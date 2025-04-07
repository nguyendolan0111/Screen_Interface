#ifndef TRANSLATION_H
#define TRANSLATION_H

#include <QObject>
#include <QTranslator>

class Translation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentLanguage READ currentLanguage WRITE setCurrentLanguage NOTIFY currentLanguageChanged FINAL)
    Q_PROPERTY(QString empty READ empty WRITE setEmpty NOTIFY emptyChanged FINAL)

public:
    enum Language{
        English,
        France,
        Spanish,
        Korean
    };
    Translation(QObject* parent = nullptr);
    int currentLanguage() const;
    void setCurrentLanguage(int newCurrentLanguage);


    Q_INVOKABLE QString convertToString(int langOrder);

    QString empty() const;
    void setEmpty(const QString &newEmpty);

signals:
    void currentLanguageChanged();

    void emptyChanged();

private:
    int m_currentLanguage;
    QTranslator* trans;

    QString m_empty;
};

#endif // TRANSLATION_H
