#-------------------------------------------------
#
# Project created by QtCreator 2012-01-08T17:07:50
#
#-------------------------------------------------

QT       += core gui

TARGET = WiFi_Hostapd_AP
TEMPLATE = app

HEADERS  += mainwindow.h \
    aboutwindow.h \
    optionswindow.h \
    activateap.h \
    disactiveap.h \
    editorconfig.h \
    dialogindicator.h \
    getroot.h \
    logsystem.h

SOURCES += main.cpp\
        mainwindow.cpp \
    aboutwindow.cpp \
    optionswindow.cpp \
    activateap.cpp \
    disactiveap.cpp \
    editorconfig.cpp \
    dialogindicator.cpp \
    getroot.cpp \
    logsystem.cpp \
    CheckProcess.cpp \
    PlatformVariable.cpp


FORMS    += mainwindow.ui \
    aboutwindow.ui \
    optionswindow.ui \
    editorconfig.ui \
    dialogindicator.ui \
    getroot.ui \
    logsystem.ui

OTHER_FILES += \
    pic/WiFi_logo_litle.png \
    app_ru.qm \
    app_en.qm

TRANSLATIONS += app_ru.ts\
app_en.ts

RC_FILE = myapp.rc

RESOURCES     = images.qrc
