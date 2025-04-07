#include "HomeItemObject.h"

HomeItemObject::HomeItemObject(int id, const QString& name, QString normal,
                       QString press, QString horver, QString disable,
                       const QStringList& sublist, QObject *parent)
    : QObject{parent}, m_id(id), m_name(name)
{
    m_icons.append(normal);
    m_icons.append(press);
    m_icons.append(horver);
    m_icons.append(disable);

    keyName = name;
    keySublist = sublist;
}

HomeItemObject::HomeItemObject(QObject *parent)
    : QObject{parent}
{
}

int HomeItemObject::id() const
{
    return m_id;
}

void HomeItemObject::setId(int newId)
{
    if (m_id == newId)
        return;
    m_id = newId;
    emit idChanged();
}

QString HomeItemObject::name() const
{
    return m_name;
}

void HomeItemObject::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

QStringList HomeItemObject::icons() const
{
    return m_icons;
}

void HomeItemObject::setIcons(const QStringList &newIcons)
{
    if (m_icons == newIcons)
        return;
    m_icons = newIcons;
    emit iconsChanged();
}

QStringList HomeItemObject::subList() const
{
    return m_subList;
}

void HomeItemObject::setSubList(const QStringList &newSubList)
{
    if (m_subList == newSubList)
        return;
    m_subList = newSubList;
    emit subListChanged();
}

void HomeItemObject::updateTranslation()
{
    m_name = QObject::tr(keyName.toUtf8().constData());
    QStringList translatedFeatures;
    for (const QString &feature : keySublist) {
        translatedFeatures.append(QObject::tr(feature.toUtf8().constData()));
    }
    setSubList(translatedFeatures);
}
