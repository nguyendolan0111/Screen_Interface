#ifndef MYHOMEITEM_H
#define MYHOMEITEM_H

#include <QObject>
#include <QStringList>

class HomeItemObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged FINAL)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QStringList icons READ icons WRITE setIcons NOTIFY iconsChanged FINAL)
    Q_PROPERTY(QStringList subList READ subList WRITE setSubList NOTIFY subListChanged FINAL)

public:
    explicit HomeItemObject(int id, const QString& name, QString normal,
                        QString press, QString horver, QString disable,
                        const QStringList& sublist, QObject *parent = nullptr);

    HomeItemObject(QObject *parent = nullptr);

    int id() const;
    void setId(int newId);

    QString name() const;
    void setName(const QString &newName);

    QStringList icons() const;
    void setIcons(const QStringList &newIcons);

    QStringList subList() const;
    void setSubList(const QStringList &newSubList);

    void updateTranslation();

signals:
    void idChanged();
    void nameChanged();

    void iconsChanged();

    void subListChanged();

private:
    int m_id;
    QString m_name;
    QStringList m_icons;
    QStringList m_subList;

    QString keyName;
    QStringList keySublist;
};

#endif // MYHOMEITEM_H
