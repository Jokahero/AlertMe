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

unix {
    QMAKE_CXXFLAGS += -Werror
}

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CLEAN = gen/* ui/include/* bin/*

SOURCES += src/Main.cpp \
    src/core/AAlert.cpp \
	src/core/AlertManager.cpp \
        src/core/features/Sound.cpp \
	src/core/TickTimer.cpp \
    src/core/features/Notification.cpp \

HEADERS  += \ 
    inc/core/AAlert.hpp \
	inc/core/AlertManager.hpp \
        inc/core/features/Sound.hpp \
	inc/core/TickTimer.hpp \
        inc/core/features/AFeature.hpp \
    inc/core/features/Notification.hpp \

FORMS    +=

RESOURCES += res/default_sounds.qrc \
    res/images.qrc
