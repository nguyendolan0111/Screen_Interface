#include "Translation.h"
#include <QGuiApplication>
#include <QDebug>

Translation::Translation(QObject* parent)
    : QObject{parent}, m_empty("")
{
    trans = new QTranslator();
    setCurrentLanguage(English);
}

int Translation::currentLanguage() const
{
    return m_currentLanguage;
}

void Translation::setCurrentLanguage(int newCurrentLanguage)
{
    if (m_currentLanguage == newCurrentLanguage)
        return;
    m_currentLanguage = newCurrentLanguage;

    switch (newCurrentLanguage) {
    case English:{

        if(!trans->load(":/myapp_en.qm")){
            qDebug() << "Cannot load english file";
        }
        break;
    }
    case France:{

        if(!trans->load(":/myapp_fr.qm")){
            qDebug() << "Cannot load france file";
        }
        break;
    }
    case Spanish:{

        if(!trans->load(":/myapp_es.qm")){
            qDebug() << "Cannot load spanish file";
        }
        break;
    }
    case Korean:{
        if(!trans->load(":/myapp_kr.qm")){
            qDebug() << "Cannot load korean file";
        }
        break;
    }
    default:
        break;
    }
    qApp->installTranslator(trans);
    qDebug() << "Successfully load new language";
    emit currentLanguageChanged();
    emit emptyChanged();
}

QString Translation::convertToString(int langOrder)
{
    switch (langOrder) {
    case English:
        return "English";
    case France:
        return "France";
    case Spanish:
        return "ESPAÑOL";
    case Korean:
        return "한국어";
    default:
        break;
    }
}


QString Translation::empty() const
{
    return m_empty;
}

void Translation::setEmpty(const QString &newEmpty)
{
    if (m_empty == newEmpty)
        return;
    m_empty = newEmpty;
    emit emptyChanged();
}
