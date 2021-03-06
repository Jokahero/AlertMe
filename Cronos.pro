#-------------------------------------------------
# Cronos
#-------------------------------------------------

QMAKE_CXX = clang++

CONFIG += qt
CONFIG += c++14

QT += widgets
QT += multimedia
QT += qml
QT += quick

TARGET = Cronos
TEMPLATE = app

DESTDIR = bin

INCLUDEPATH = inc ui/include inc/model
UI_DIR = ui/include
OBJECTS_DIR = gen
MOC_DIR = gen

unix {
    QMAKE_CXXFLAGS += -Werror
}

DEFINES *= QT_USE_QSTRINGBUILDER

QMAKE_CLEAN = gen/* ui/include/* bin/*

SOURCES += src/Main.cpp \
    src/core/Alert.cpp \
    src/core/AlertManager.cpp \
    src/core/features/Sound.cpp \
    src/core/features/Notification.cpp \
    src/ui/ManageDialog.cpp \
    src/model/AlertModel.cpp \

HEADERS  += \
    inc/core/Alert.hpp \
    inc/core/AlertManager.hpp \
    inc/core/features/Sound.hpp \
    inc/core/features/AFeature.hpp \
    inc/core/features/Notification.hpp \
    inc/ui/ManageDialog.hpp \
    inc/model/AlertModel.hpp \

FORMS    += \
    ui/ManageDialog.ui

RESOURCES += res/default_sounds.qrc \
    res/images.qrc

target.path += /usr/local/bin

icon.files += res/images/bell.png
icon.path += /usr/share/alertme/icons/

desktop.files += alertme.desktop
desktop.path += /usr/share/alertme/

INSTALLS += target
INSTALLS += icon
INSTALLS += desktop

#-- Documentation building custom target
doc.commands = doxygen Doxyfile
QMAKE_EXTRA_TARGETS += doc
