QT = core qml gui quick

SOURCES += main.cpp 
HEADERS += process.h
RESOURCES += video.qrc
RC_FILE = comment.rc
QML_IMPORT_PATH += C:/VLC-Qt/qml
target.path = $$[QT_INSTALL_EXAMPLES]/qml/attilio
INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../VLC-Qt/lib/ -lVLCQtCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../VLC-Qt/lib/ -lVLCQtCored
else:unix: LIBS += -L$$PWD/../../../../VLC-Qt/lib/ -lVLCQtCore

INCLUDEPATH += $$PWD/../../../../VLC-Qt/include
DEPENDPATH += $$PWD/../../../../VLC-Qt/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../VLC-Qt/lib/ -lVLCQtQml
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../VLC-Qt/lib/ -lVLCQtQmld
else:unix: LIBS += -L$$PWD/../../../../VLC-Qt/lib/ -lVLCQtQml

INCLUDEPATH += $$PWD/../../../../VLC-Qt/include
DEPENDPATH += $$PWD/../../../../VLC-Qt/include

