QT += testlib
QT += gui
QT += multimedia
CONFIG += qt warn_on depend_includepath testcase

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TEMPLATE = app

SOURCES +=  tst_testbomb.cpp
