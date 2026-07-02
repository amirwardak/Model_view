#include "mymodel.h"


MyModel::MyModel(QVector<WithTelephon>* dataPtr, QObject *parent) :  QAbstractTableModel(parent), modelData(dataPtr)
{
}

int MyModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) return 0;
    return modelData->size();
}

int MyModel::columnCount(const QModelIndex &parent) const {
    if (parent.isValid()) return 0;
    return 3;
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role!=Qt::DisplayRole)
        return QVariant();
    if(orientation==Qt::Horizontal)
    {
        switch(section)
        {
        case 0: return QVariant(tr("Name"));
        case 1: return QVariant(tr("Telephon1"));
        case 2: return QVariant(tr("Telephon2"));
        default: return QVariant();
        }
    }
    else
        return QVariant(tr("%1").arg(section+1));
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if(role!=Qt::DisplayRole)
        return QVariant();
    switch(index.column())
    {
        case 0: return modelData->at(index.row()).name;
        case 1: return modelData->at(index.row()).tel1;
        case 2: return modelData->at(index.row()).tel2;
        default: return QVariant();
    }
}

void MyModel::resetModel(){
    this->beginResetModel();
    this->endResetModel();
}

Qt::ItemFlags MyModel::flags(const QModelIndex& index) const {
    if(!index.isValid()){
        return Qt::NoItemFlags;
    }
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

bool MyModel::setData(const QModelIndex& index, const QVariant& value, int role){
    if (index.row() >= modelData->size() || index.column() >= 3) return false;
    if(index.isValid() && role == Qt::EditRole){
        switch(index.column()){
        case 0:
            (*modelData)[index.row()].name = value.toString();
            break;
        case 1:{
            bool ok = true;
            long long tel =  value.toLongLong(&ok);
            if(!ok) return false;
            (*modelData)[index.row()].tel1 = tel;
            break;
        }
        case 2:{
            bool ok = true;
            long long tel =  value.toLongLong(&ok);
            if(!ok) return false;
            (*modelData)[index.row()].tel2 = tel;
            break;
        }
        default:
            return false;
        }
        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}
