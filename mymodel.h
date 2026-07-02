#ifndef MYMODEL_H
#define MYMODEL_H
#include <QAbstractTableModel>
#include <QModelIndex>
#include <QObject>
#include <QVariant>
#include <QVector>
#include "Structs.h"
class MyModel : public QAbstractTableModel
{
    Q_OBJECT
private:

    QVector<WithTelephon>* modelData;
public:
    MyModel(QVector<WithTelephon>* dataPtr, QObject* parent = nullptr);
    int rowCount(const QModelIndex& parent =  QModelIndex()) const;
    int columnCount(const QModelIndex& parent =  QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex& index) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
    void resetModel();
};

#endif // MYMODEL_H
