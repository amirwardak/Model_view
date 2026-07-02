#ifndef MYMODELADRESS_H
#define MYMODELADRESS_H
#include "Structs.h"
#include <QObject>
#include <QAbstractTableModel>
class MyModelAdress : public QAbstractTableModel
{
    Q_OBJECT
private:
    QVector<WithAddres>* modelDataAdr;
public:
    MyModelAdress(QVector<WithAddres>* data, QObject* parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex& index) const;

    void resetModel();
};

#endif // MYMODELADRESS_H
