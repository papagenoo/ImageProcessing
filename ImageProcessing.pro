TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

INCLUDEPATH += /usr/local/include/Eigen

HEADERS += CImg.h \
    CImg.h
INCLUDEPATH += /opt/X11/include

LIBS += -L/opt/X11/lib -lX11
#LIBS += -L/usr/X11R6/lib -lm -lpthread -lX11

#OTHER_FILES += \
#    lena.jpg


#RESOURCES += lena.jpg #resources.qrc

OTHER_FILES += \
    logo.gif \
    lena.jpg \
    1.png
