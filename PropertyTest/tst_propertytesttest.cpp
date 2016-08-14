#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include "testobject.h"

class PropertyTestTest : public QObject
{
    Q_OBJECT

public:
    PropertyTestTest();

public Q_SLOTS:
    void onIntegerValueChanged();
    void onStringValueChanged();
    void onDateTimeValueChanged();

private Q_SLOTS:
    void testInteger();
    void testString();
    void testDateTime();

private:
    TestObject m_testObject;
    bool m_slotCalled;
};

PropertyTestTest::PropertyTestTest()
{
}

void PropertyTestTest::onIntegerValueChanged()
{
    QVERIFY2(m_testObject.integerValue() == 49, "IntegerValue");
    m_slotCalled = true;
}

void PropertyTestTest::onStringValueChanged()
{
    QVERIFY2(m_testObject.stringValue() == QString("HelloWorld!"), "StringValue");
    m_slotCalled = true;
}

void PropertyTestTest::onDateTimeValueChanged()
{
    QVERIFY2(m_testObject.dateTimeValue() <= QDateTime::currentDateTime(), "DateTimeValue");
    m_slotCalled = true;
}

void PropertyTestTest::testInteger()
{
    bool ok = connect(&m_testObject, SIGNAL(integerValueChanged()), this, SLOT(onIntegerValueChanged()));
    m_slotCalled = false;
    QVERIFY2(ok, "Connection");
    m_testObject.setintegerValue(49);
    QVERIFY2(m_slotCalled, "Slot Called");
}

void PropertyTestTest::testString()
{
    bool ok = connect(&m_testObject, SIGNAL(stringValueChanged()), this, SLOT(onStringValueChanged()));
    m_slotCalled = false;
    QVERIFY2(ok, "Connection");
    m_testObject.setstringValue("HelloWorld!");
    QVERIFY2(m_slotCalled, "Slot Called");
}

void PropertyTestTest::testDateTime()
{
    bool ok = connect(&m_testObject, SIGNAL(dateTimeValueChanged()), this, SLOT(onDateTimeValueChanged()));
    m_slotCalled = false;
    QVERIFY2(ok, "Connection");
    m_testObject.alterDateTime(QDateTime::currentDateTime());
    QVERIFY2(m_slotCalled, "Slot Called");
}

QTEST_MAIN(PropertyTestTest)

#include "tst_propertytesttest.moc"
