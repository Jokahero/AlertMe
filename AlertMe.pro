#-------------------------------------------------
# AlertMe
#-------------------------------------------------

CONFIG += qt
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    src/core/AAlert.cpp \
	src/core/AlertManager.cpp \
	src/core/TickTimer.cpp

HEADERS  += \ 
    inc/core/AAlert.hpp \
	inc/core/AlertManager.hpp \
	inc/core/TickTimer.hpp

FORMS    +=
