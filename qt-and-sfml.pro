######################################################################
# Automatically generated by qmake (3.1) Mon May 11 14:21:40 2020
######################################################################

# Output
CONFIG += debug
CONFIG += c++17
TARGET = qt-and-sfml
DESTDIR = dist/bin
OBJECTS_DIR = dist/obj
MOC_DIR = dist/.moc
RCC_DIR = dist/.rcc

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Standard lib
LIBS += -lstdc++fs

# Qt modules
QT += gui
QT += widgets

# Input
INCLUDEPATH += include
SOURCES += src/*.cpp

# SFML
INCLUDEPATH += C:/lib/SFML-2.5.1/include
LIBS += -LC:/lib/SFML-2.5.1/lib
LIBS += -lsfml-system-d
LIBS += -lsfml-window-d
LIBS += -lsfml-graphics-d