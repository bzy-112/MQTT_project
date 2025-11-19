QT       += core gui
QT       += network
QT       += multimedia multimediawidgets
QT       += charts
QT       += mqtt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    TempHum.cpp \
    ledui.cpp \
    lightui.cpp \
    main.cpp \
    mqttclient.cpp \
    temphumtiyui.cpp \
    widget.cpp

HEADERS += \
    TempHum.h \
    ledui.h \
    lightui.h \
    temphumtiyui.h \
    widget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    TempHum.ui \
    ledui.ui \
    lightui.ui \
    temphumtiyui.ui

RESOURCES += \
    main.qrc






