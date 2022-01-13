# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = qml

HEADERS = \
   $$PWD/src/process.h \
   $$PWD/windows/Project.rc.in

SOURCES = \
   $$PWD/src/main.cpp

INCLUDEPATH = \
    $$PWD/src

#DEFINES = 


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../VLC-Qt/qml/VLCQt/ -lVLCQt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../VLC-Qt/qml/VLCQt/ -lVLCQtd
else:unix: LIBS += -L$$PWD/../../../VLC-Qt/qml/VLCQt/ -lVLCQt

INCLUDEPATH += $$PWD/../../../VLC-Qt/qml/VLCQt
DEPENDPATH += $$PWD/../../../VLC-Qt/qml/VLCQt

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../VLC-Qt/lib/ -lVLCQtQml
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../VLC-Qt/lib/ -lVLCQtQmld
else:unix: LIBS += -L$$PWD/../../../VLC-Qt/lib/ -lVLCQtQml

INCLUDEPATH += $$PWD/../../../VLC-Qt/include
DEPENDPATH += $$PWD/../../../VLC-Qt/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../VLC-Qt/lib/ -lVLCQtQml
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../VLC-Qt/lib/ -lVLCQtQmld
else:unix: LIBS += -L$$PWD/../../../VLC-Qt/lib/ -lVLCQtQml

INCLUDEPATH += $$PWD/../../../VLC-Qt/include
DEPENDPATH += $$PWD/../../../VLC-Qt/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../VLC-Qt/qml/VLCQt/ -lVLCQt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../VLC-Qt/qml/VLCQt/ -lVLCQtd
else:unix: LIBS += -L$$PWD/../../../VLC-Qt/qml/VLCQt/ -lVLCQt

INCLUDEPATH += $$PWD/../../../VLC-Qt/include
DEPENDPATH += $$PWD/../../../VLC-Qt/include
