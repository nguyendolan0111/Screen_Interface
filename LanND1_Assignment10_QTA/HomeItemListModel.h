#ifndef HOMEITEMLISTMODEL_H
#define HOMEITEMLISTMODEL_H

#include <QAbstractListModel>
#include "HomeItemObject.h"
#include <QStringList>

class HomeItemListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ItemRoles{
        ID = Qt::UserRole + 1,
        Name,
        Normal,
        Pressed,
        Hovered,
        Disable,
        SubList
    };

    HomeItemListModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    void addItem(HomeItemObject* item);
    void loadItem();
    void loadSubList();
    Q_INVOKABLE QString getData(QString text){
        return tr(text.toUtf8());
    }

public slots:
    void updateTranslation();

private:
    QList<HomeItemObject*> m_data;

    QString convertToString(int i);

    QStringList keyName;
    QList<QStringList> keySublist;

protected:
    QHash<int, QByteArray> roleNames() const;
};

#endif // HOMEITEMLISTMODEL_H
