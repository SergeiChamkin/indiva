#ifndef SET_H
#define SET_H

#include <iostream>
#include "list.h"
#include <fstream>
#include <sstream>
#include <cassert>
#include <QString>
#include <string.h>

using namespace std;
class Set {
private:
    tlist ls;
    int size;
public:
    Set() {
        size = 0;
    }

    Set(const Set  &s) {
        size = s.getSize();
        for (int i = 0; i < size; i++) {
            ls.add(s[i]);
        }
    }

    ~Set(){
        ls.remove_all();
        size = 0;
    }
    QString &operator[](int index) const {
        return ls[index];
    }

    int getSize() const {
        return size;
    }

    int findPos(QString which)  {
        for (int i = 0; i < size; i++) {
            if (ls[i] == which) return i;
        }
        return -1;
    }

    void add(QString what) {
        if (findPos(what) == -1) {
            ls.add(what);
            size++;
        }
    }

    bool isIncluding(QString w)  {
        if (findPos(w) != -1) return 1;
        else return 0;
    }

    bool isEmpty() const{
        return size == 0;
    }

    Set operator=(Set s) {
        size = s.getSize();
        for (int i = 0; i < size; i++) {
            ls[i] = s[i];
        }
        return *this;
    }

    QString toString(){
        QString answ="[";
        for (int i = 0; i < this->getSize(); i++) {
            answ+=(ls[i]);
            answ+=", ";
        }
        answ+="]";
        return answ;
    }
};

ostream  &operator<<(ostream&os, Set &set) {
    os << "[";
    for (int i = 0; i < set.getSize(); i++) {
        std::string current_locale_text = set[i].toLocal8Bit().constData();
        os << current_locale_text << ", ";
    }
    os << "]" << endl;
    return os;
}

istream &operator>>(istream &is, Set &set) {
    cout << "Введите размер: ";
    int size;
    string tmp;
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "Введите " << i+1 << " элемент множества:";
        cin >> tmp;
        set.add(QString::fromUtf8(tmp.c_str()));
    }
    cout << endl;
    return is;
}

Set operator+=(Set &set,QString what) {
    set.add(what);
    return set;
}

Set operator+=(Set &set1, Set &set2) {
    for (int i = 0; i < set2.getSize(); i++) {
        set1.add(set2[i]);
    }
    return set1;
}

Set operator-(Set &set1, Set &set2) {
    Set answ;
    for (int i = 0; i < set1.getSize(); i++) {
        if (!set2.isIncluding(set1[i])) {
            answ.add(set1[i]);
        }
    }
    return answ;
}

Set operator-=(Set &set, QString what) {
    Set answ;
    for (int i = 0; i < set.getSize(); i++) {
        if (set[i]!=what) {
            answ.add(set[i]);
        }
    }
    set = answ;
    return answ;
}


Set operator&&(Set &set1, Set &set2) {
    Set answ;
    for (int i = 0; i < set1.getSize(); i++) {
        if (set2.isIncluding(set1[i])) answ.add(set1[i]);
    }
    return answ;
}

void getFromFile(Set &set,string filename) {
    ifstream infile(filename);
    string line;
    while (getline(infile, line))
    {
        istringstream iss(line);
        string token;
        while (getline(iss, token, ' '))
        {
            set.add((token.c_str()));
        }
    }
}

bool operator==(Set &set1, Set &set2){
    if(set1.getSize()!=set2.getSize()){
        return false;
    } else{
        for(int i=0;i<set1.getSize();i++){
            if(!set1.isIncluding(set2.operator[](i))){
                return false;
            }
        }
    }
    return true;
}

bool operator!=(Set &set1, Set &set2){
    return !(set1==set2);
}
#endif // SET_H
