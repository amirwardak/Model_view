#ifndef STRUCTS_H
#define STRUCTS_H
#include <QString>
#include <QTextStream>
#include <QDataStream>
template <typename C>
bool CompareNames(const C& a, const C& b){
    return a.name < b.name;
}

template<typename C>
bool CompareTel1(const C& a, const C& b){
    return a.name < b.name;
}

struct WithTelephon{
    QString name;
    long long tel1;
    long long tel2;
    friend QTextStream& operator<< (QTextStream& out, const WithTelephon& rhs){
        out << rhs.name << Qt::endl << rhs.tel1 << Qt::endl << rhs.tel2 << Qt::endl;
        return out;
    }

    friend QTextStream& operator>> (QTextStream& in, WithTelephon& rhs){
        rhs.name = in.readLine();
        rhs.tel1 = in.readLine().toLongLong();
        rhs.tel2 = in.readLine().toLongLong();
        return in;
    }

    friend QDataStream& operator<< (QDataStream& bout, const WithTelephon& rhs){
        bout << rhs.name << rhs.tel1 << rhs.tel2;
        return bout;
    }

    friend QDataStream& operator>> (QDataStream& bin, WithTelephon& rhs){
        bin >> rhs.name >> rhs.tel1 >> rhs.tel2;
        return bin;
    }

    static bool CompareTel2(const WithTelephon& a, const WithTelephon& b){
        return a.tel2 < b.tel2;
    }
};



struct WithAddres{
    QString name;
    QString addr;
    long long tel1;
    friend QTextStream& operator<< (QTextStream& out, const WithAddres& rhs){
        out << rhs.name << Qt::endl << rhs.tel1 << Qt::endl << rhs.addr << Qt::endl;
        return out;
    }

    friend QTextStream& operator>> (QTextStream& in, WithAddres& rhs){
        rhs.name = in.readLine();

        rhs.tel1 = in.readLine().toLongLong();
        rhs.addr = in.readLine();
        return in;
    }

    friend QDataStream& operator<< (QDataStream& bout, const WithAddres& rhs){
        bout << rhs.name << rhs.tel1 << rhs.addr;
        return bout;
    }

    friend QDataStream& operator>> (QDataStream& bin, WithAddres& rhs){
        bin >> rhs.name >> rhs.tel1 >> rhs.addr;
        return bin;
    }

    static bool CompareAddr(const WithAddres& a, const WithAddres& b){
        return a.addr < b.addr;
    }
};
#endif // STRUCTS_H
