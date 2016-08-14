#include "testobject.h"

TestObject::TestObject(QObject *parent)
    : QObject(parent)
    , m_integerValue(0)
{
    m_dateTimeValue = QDateTime::currentDateTime();
}

void TestObject::alterDateTime(const QDateTime &dateTime)
{
    m_dateTimeValue = dateTime;
    emit dateTimeValueChanged();
}

