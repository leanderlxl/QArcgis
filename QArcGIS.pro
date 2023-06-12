QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ThreadPool/baseMapTasks/wmts_map.cpp \
    core/AbstractShapeType.cpp \
    core/ShapeState/EditShapeState.cpp \
    core/ShapeState/shapeeditor.cpp \
    core/layer.cpp \
    core/layermanager.cpp \
    core/shapes.cpp \
    main.cpp \
    widget/Client.cpp \
    widget/Edit/createfeatures.cpp \
    widget/Edit/makelayer.cpp \
    widget/contentBar/contentbar.cpp \
    widget/contentBar/mytreewidget.cpp \
    widget/mapViewer/graphicsView/Editor_bar/decorator.cpp \
    widget/mapViewer/graphicsView/Editor_bar/editor.cpp \
    widget/mapViewer/graphicsView/Editor_bar/editorpixmapitem.cpp \
    widget/mapViewer/graphicsView/ViewState/selectstate.cpp \
    widget/mapViewer/graphicsView/ViewState/statemanager.cpp \
    widget/mapViewer/graphicsView/mapView.cpp \
    widget/mapViewer/graphicsView/mapscene.cpp \
    widget/mapViewer/mapviewwidget.cpp \
    widget/mapViewer/projector/projector.cpp \
    widget/menuBar/TabWidget/pixmapitem.cpp \
    widget/menuBar/TabWidget/tabwidget.cpp \
    widget/menuBar/buildmenu.cpp \
    widget/menuBar/menubar.cpp


HEADERS += \
    ThreadPool/baseMapTasks/wmts_map.h \
    core/AbstractShapeType.h \
    core/ShapeState/EditShapeState.h \
    core/ShapeState/shapeeditor.h \
    core/layer.h \
    core/layermanager.h \
    core/shapes.h \
    widget/Client.h \
    widget/Edit/createfeatures.h \
    widget/Edit/makelayer.h \
    widget/contentBar/contentbar.h \
    widget/contentBar/mytreewidget.h \
    widget/mapViewer/graphicsView/Editor_bar/decorator.h \
    widget/mapViewer/graphicsView/Editor_bar/editor.h \
    widget/mapViewer/graphicsView/Editor_bar/editorpixmapitem.h \
    widget/mapViewer/graphicsView/ViewState/selectstate.h \
    widget/mapViewer/graphicsView/ViewState/statemanager.h \
    widget/mapViewer/graphicsView/mapView.h \
    widget/mapViewer/graphicsView/mapscene.h \
    widget/mapViewer/mapviewwidget.h \
    widget/mapViewer/projector/projector.h \
    widget/menuBar/TabWidget/pixmapitem.h \
    widget/menuBar/TabWidget/tabwidget.h \
    widget/menuBar/buildmenu.h \
    widget/menuBar/menubar.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += D:/QtProject/QArcGIS/lib/gdal/include
LIBS += -LD:/QtProject/QArcGIS/lib/gdal/lib -lgdal_i

RESOURCES += \
    widget/mapViewer/View.qrc \
    widget/menuBar/TabWidget/menuBar.qrc

FORMS += \
    ui/Layer/createFeatures.ui \
    ui/Layer/form.ui



