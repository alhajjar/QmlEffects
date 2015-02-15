TEMPLATE = lib
TARGET = effectsPlugin
QT += qml quick widgets
CONFIG += qt plugin

TARGET = $$qtLibraryTarget($$TARGET)
uri = Effects

# Input
SOURCES += \
    effectsplugin_plugin.cpp \
    blur.cpp \
    colorOverlay.cpp \
    dropshadow.cpp

HEADERS += \
    effectsplugin_plugin.h \
    blur.h \
    colorOverlay.h \
    dropshadow.h

OTHER_FILES = qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}

