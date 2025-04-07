#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include "Translation.h"
#include "HomeItemListModel.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    Translation* trans = new Translation();
    QObject::connect(trans,&Translation::currentLanguageChanged,
                     &engine, &QQmlApplicationEngine::retranslate);

    HomeItemListModel* model = new HomeItemListModel();
    model->loadItem();

    QObject::connect(trans,&Translation::currentLanguageChanged,
                     model, &HomeItemListModel::updateTranslation);

    engine.rootContext()->setContextProperty("Translation", trans);
    engine.rootContext()->setContextProperty("HomeModel", model);

    engine.load(url);

    return app.exec();
}
