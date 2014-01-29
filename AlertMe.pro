#-------------------------------------------------
# AlertMe
#-------------------------------------------------

CONFIG += qt
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += multimedia

TARGET = AlertMe
TEMPLATE = app

DESTDIR = bin

INCLUDEPATH = inc ui/include inc/model 
UI_DIR = ui/include
OBJECTS_DIR = gen 
MOC_DIR = gen 

QMAKE_CXXFLAGS += -Werror

QMAKE_CLEAN = gen/* ui/include/* bin/*

SOURCES += src/Main.cpp \
    src/AAlert.cpp \
	src/AlertManager.cpp \
	src/Sound.cpp \
	src/TickTimer.cpp

HEADERS  += \ 
    inc/AAlert.hpp \
	inc/AlertManager.hpp \
	inc/Sound.hpp \
	inc/TickTimer.hpp

FORMS    +=

RESOURCES += res/default_sounds.qrc
