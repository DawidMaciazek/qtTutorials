#ifndef OVERLOADS_H
#define OVERLOADS_H

#include "person.h"
#include <QtCore>

QDataStream &operator<<(QDataStream &out, const Person &person);
QDataStream &operator>>(QDataStream &in, Person &person);

QDataStream &operator<<(QDataStream &out, const Person &person)
{
    out << person.age << person.name;
    return out;
}

QDataStream &operator>>(QDataStream &in, Person &person)
{
    person = Person();
    in >> person.age >> person.name;
    return in;
}


#endif // OVERLOADS_H
