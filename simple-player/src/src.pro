#
# VLC-Qt Simple Player
# Copyright (C) 2015 Tadej Novak <tadej@tano.si>
#

TARGET      = simple-player
TEMPLATE    = app
CONFIG 	   += c++11

QT         += widgets

SOURCES    += main.cpp \
   SimplePlayer.cpp \
    EqualizerDialog.cpp
	
HEADERS    += SimplePlayer.h \
    EqualizerDialog.h


HEADERS    += SimplePlayer.h \
    EqualizerDialog.h


LIBS       += -lVLCQtCore -lVLCQtWidgets


QML_IMPORT_PATH       +=  C:/Qt/Qt5.12.0/5.12.0/msvc2017/qml

QML_IMPORT_PATH       +=  C:/VLC-Qt/qml


# Edit below for custom library location
LIBS       += -Lc:/vlc-qt/lib -lVLCQtCore -lVLCQtWidgets
INCLUDEPATH += c:/vlc-qt/include
