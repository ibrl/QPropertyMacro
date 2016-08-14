#ifndef TESTOBJECT_H
#define TESTOBJECT_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include "../q_property_full.h"

class TestObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY_FULL_VAL(integerValue, int)
    Q_PROPERTY_FULL_REF(stringValue, QString)
    Q_PROPERTY_READONLY(dateTimeValue, QDateTime)

public:
    TestObject(QObject *parent = 0);

    void alterDateTime(const QDateTime& dateTime);

};

#endif // TESTOBJECT_H
