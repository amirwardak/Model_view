#include "mymodeladress.h"

MyModelAdress::MyModelAdress(QVector<WithAddres>* data, QObject* parrent) : QAbstractTableModel(parrent), modelDataAdr(data){}

int MyModelAdress::rowCount(const QModelIndex &parent) const{
    if(parent.isValid()) return 0;
    return modelDataAdr->size();
}
int MyModelAdress::columnCount(const QModelIndex &parent) const{
    if(parent.isValid()) return 0;
    return 3;
}

QVariant MyModelAdress::data(const QModelIndex &index, int role) const{
    qDebug() << "data() called: row=" << index.row()
    << "column=" << index.column()
    << "role=" << role
    << "dataSize=" << modelDataAdr->size();

    if(!index.isValid()) return QVariant();
    if(role == Qt::DisplayRole){
        if(index.row() >= modelDataAdr->size() || index.row() < 0) return QVariant();
        switch(index.column()){
            case 0: return QString(modelDataAdr->at(index.row()).name);
            case 1: return QString(modelDataAdr->at(index.row()).addr);
            case 2: return QString::number(modelDataAdr->at(index.row()).tel1);
            default: return QVariant();
        }
    }
    else return QVariant();
}
bool MyModelAdress::setData(const QModelIndex &index, const QVariant &value, int role){
    if(!index.isValid()) return false;

    if(role == Qt::EditRole){
        switch(index.column()){
        case 0: (*modelDataAdr)[index.row()].name = value.toString();
            break;
        case 1: (*modelDataAdr)[index.row()].addr = value.toString();
            break;
        case 2: (*modelDataAdr)[index.row()].tel1 = value.toLongLong();
            break;
        }
        emit dataChanged(index, index, {role});
        return true;
    }
    return false;

}
QVariant MyModelAdress::headerData(int section, Qt::Orientation orientation, int role) const{
    qDebug() << "headerData() called: section=" << section
             << "orientation=" << orientation
             << "role=" << role;

    if(role != Qt::DisplayRole) return QVariant();
    if(orientation == Qt::Horizontal){
        switch(section){
        case 0: return QVariant(tr("Name"));
        case 1: return QVariant(tr("Adress"));
        case 2: return QVariant(tr("Telephon"));
        default: return QVariant();
        }
    }
    else{
        return QString("%1").arg(section + 1);
    }
}
Qt::ItemFlags MyModelAdress::flags(const QModelIndex& index) const{
    if(!index.isValid()) return Qt::NoItemFlags;
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

void MyModelAdress::resetModel(){
    beginResetModel();
    endResetModel();
}
