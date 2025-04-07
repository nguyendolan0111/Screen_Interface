#include "HomeItemListModel.h"
#include <QDir>
#include <QStringList>
#include <QDebug>
#include <QList>
#include <QFile>

HomeItemListModel::HomeItemListModel(QObject* parent)
    : QAbstractListModel(parent)
{}

int HomeItemListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_data.size();
}

QVariant HomeItemListModel::data(const QModelIndex &index, int role) const
{
    if(index.row() > m_data.size() - 1 || index.row() < 0){
        return QVariant();
    }

    HomeItemObject* item = m_data[index.row()];
    if(role == ID){
        return item->id();
    }
    else if(role == Name){
        return item->name();
    }
    else if(role == Normal){
        return item->icons().at(0);
    }
    else if(role == Pressed){
        return item->icons().at(1);
    }
    else if(role == Hovered){
        return item->icons().at(2);
    }
    else if(role == Disable){
        return item->icons().at(3);
    }
    else if(role == SubList){
        return item->subList();
    }
    else
        return QVariant();
}

void HomeItemListModel::addItem(HomeItemObject *item)
{
    beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
    m_data.append(item);
    endInsertRows();
}

void HomeItemListModel::loadItem()
{
    QDir dir(QDir::currentPath());
    dir.cdUp();
    dir.cdUp();
    if(dir.cd("image") && dir.cd("imageItem")){
        loadSubList();
        keyName.append(QT_TR_NOOP("Start"));
        keyName.append(QT_TR_NOOP("Navigation"));
        keyName.append(QT_TR_NOOP("UVO"));
        keyName.append(QT_TR_NOOP("Driver Assistance"));
        keyName.append(QT_TR_NOOP("Data Services"));
        keyName.append(QT_TR_NOOP("Media"));
        keyName.append(QT_TR_NOOP("Radio"));
        keyName.append(QT_TR_NOOP("Phone"));
        keyName.append(QT_TR_NOOP("Setting"));
        keyName.append(QT_TR_NOOP("Other"));
        keyName.append(QT_TR_NOOP("Reference"));
        for(int i = 0; i < keyName.size(); i++){
            addItem(new HomeItemObject(i + 1, keyName[i],
                                   dir.absolutePath() + "/" + convertToString(i + 1) + "_" + keyName[i] + "_K.png",
                                   dir.absolutePath() + "/" + convertToString(i + 1) + "_" + keyName[i] + ".png",
                                   dir.absolutePath() + "/" + convertToString(i + 1) + "_" + keyName[i] + ".png",
                                   dir.absolutePath() + "/" + convertToString(i + 1) + "_" + keyName[i] + "_K.png",
                                   keySublist.at(i)));
        }

    }
    else{
        qDebug() << "Cannot find folder name image or name imageItem";
    }
}

void HomeItemListModel::loadSubList()
{
    // append the start
    QStringList listStart;
    listStart.append(QT_TR_NOOP("Name of each Component"));
    listStart.append(QT_TR_NOOP("Basic operation"));
    listStart.append(QT_TR_NOOP("HOME Screen"));
    listStart.append(QT_TR_NOOP("Favorites"));
    keySublist.append(listStart);

    // append the navigation
    QStringList listNavi;
    listNavi.append(QT_TR_NOOP("Getting Started with Navigation"));
    listNavi.append(QT_TR_NOOP("Map Screen"));
    listNavi.append(QT_TR_NOOP("Operating Navigation"));
    listNavi.append(QT_TR_NOOP("Searching For Destination of Navigation"));
    listNavi.append(QT_TR_NOOP("Using the Route Menu"));
    keySublist.append(listStart);

    // append Uvo
    QStringList listUvo;
    listUvo.append(QT_TR_NOOP("UVO"));
    keySublist.append(listUvo);

    // append driver assis
    QStringList listDriver;
    listDriver.append(QT_TR_NOOP("Driver Assistance"));
    keySublist.append(listDriver);

    // append Data services
    QStringList listData;
    listData.append(QT_TR_NOOP("About HD Data Services"));
    listData.append(QT_TR_NOOP("Traffic"));
    listData.append(QT_TR_NOOP("Weather"));
    listData.append(QT_TR_NOOP("Doppler Radar"));
    listData.append(QT_TR_NOOP("Fuel Prices"));
    keySublist.append(listData);

    // append Media
    QStringList listMedia;
    listMedia.append(QT_TR_NOOP("Playing USB"));
    listMedia.append(QT_TR_NOOP("Playing IPod"));
    listMedia.append(QT_TR_NOOP("Playing Bluetooth Audio"));
    listMedia.append(QT_TR_NOOP("Playing Sounds Of Nature"));
    keySublist.append(listMedia);

    // append Radio
    QStringList listRadio;
    listRadio.append(QT_TR_NOOP("List To FM/AM Radio"));
    listRadio.append(QT_TR_NOOP("List To HD Radio"));
    listRadio.append(QT_TR_NOOP("List To SiriusXM Radio"));
    keySublist.append(listRadio);

    // append Phone
    QStringList listPhone;
    listPhone.append(QT_TR_NOOP("Bluetooth"));
    listPhone.append(QT_TR_NOOP("Making A Call"));
    listPhone.append(QT_TR_NOOP("Call history"));
    listPhone.append(QT_TR_NOOP("Contacts"));
    listPhone.append(QT_TR_NOOP("Favorites Contacts"));
    listPhone.append(QT_TR_NOOP("Dial Screen"));
    listPhone.append(QT_TR_NOOP("Messages"));
    keySublist.append(listPhone);

    // append System
    QStringList listSys;
    listSys.append(QT_TR_NOOP("Vehicle Settings"));
    listSys.append(QT_TR_NOOP("Navigation Settings"));
    listSys.append(QT_TR_NOOP("Device Connections Settings"));
    listSys.append(QT_TR_NOOP("UVO Settings"));
    listSys.append(QT_TR_NOOP("Screen Theme/Layout"));
    listSys.append(QT_TR_NOOP("Advanced Settings"));
    listSys.append(QT_TR_NOOP("Date/Time Settings"));
    listSys.append(QT_TR_NOOP("General Settings"));
    listSys.append(QT_TR_NOOP("Sound Settings"));
    listSys.append(QT_TR_NOOP("Display Settings"));
    listSys.append(QT_TR_NOOP("Voice Recognition Settings"));
    listSys.append(QT_TR_NOOP("System Infomation Check And Update Guide"));
    keySublist.append(listSys);

    // append other
    QStringList listOthers;
    listOthers.append(QT_TR_NOOP("About Phone Projection"));
    listOthers.append(QT_TR_NOOP("Voice Memo"));
    listOthers.append(QT_TR_NOOP("Voice Regconition System"));
    listOthers.append(QT_TR_NOOP("Siri"));
    listOthers.append(QT_TR_NOOP("Using Rear Camera"));
    listOthers.append(QT_TR_NOOP("SVM (Surround View Monitor)"));
    listOthers.append(QT_TR_NOOP("Driving Info"));
    listOthers.append(QT_TR_NOOP("Climate"));
    keySublist.append(listOthers);

    // append ref
    QStringList listRef;
    listRef.append(QT_TR_NOOP("Precautions For Safety"));
    listRef.append(QT_TR_NOOP("General Infomation"));
    listRef.append(QT_TR_NOOP("Before Thinking the Product Has Malfunctioned"));
    listRef.append(QT_TR_NOOP("Before Thinking There is A Product Defect"));
    listRef.append(QT_TR_NOOP("Troubleshooting"));
    listRef.append(QT_TR_NOOP("Trademarks and Licenses"));
    listRef.append(QT_TR_NOOP("Specification"));
    listRef.append(QT_TR_NOOP("Open Souce Software Notice"));
    keySublist.append(listRef);

}

void HomeItemListModel::updateTranslation()
{
    for (HomeItemObject *item : m_data) {

        item->updateTranslation();
    }
    emit dataChanged(index(0, 0), index(this->rowCount(QModelIndex()) - 1, 0));
}

QString HomeItemListModel::convertToString(int i)
{
    if(i < 10){
        return "0" + QString::number(i);
    }
    else return QString::number(i);
}

QHash<int, QByteArray> HomeItemListModel::roleNames() const
{

    QHash<int, QByteArray> roles;
    roles[ID] = "theID";
    roles[Name] = "theName";
    roles[Normal] = "theNormal";
    roles[Pressed] = "thePressed";
    roles[Hovered] = "theHorvered";
    roles[Disable] = "theDisable";
    roles[SubList]= "theSubList";

    return roles;
}

