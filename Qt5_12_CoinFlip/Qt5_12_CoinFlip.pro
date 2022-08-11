QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chooselevelscene.cpp \
    dataconfig.cpp \
    main.cpp \
    mainwindow.cpp \
    mycoin.cpp \
    mypushbutton.cpp \
    playscene.cpp

HEADERS += \
    chooselevelscene.h \
    dataconfig.h \
    mainwindow.h \
    mycoin.h \
    mypushbutton.h \
    playscene.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Qt5_12_CoinFlip.pro.user \
    res/BackButton.png \
    res/BackButtonSelected.png \
    res/BackButtonSound.wav \
    res/BoardNode.png \
    res/Coin0001.png \
    res/Coin0002.png \
    res/Coin0003.png \
    res/Coin0004.png \
    res/Coin0005.png \
    res/Coin0006.png \
    res/Coin0007.png \
    res/Coin0008.png \
    res/ConFlipSound.wav \
    res/LevelCompletedDialogBg.png \
    res/LevelIcon.png \
    res/LevelWinSound.wav \
    res/MenuSceneBg.png \
    res/MenuSceneStartButton.png \
    res/OtherSceneBg.png \
    res/PlayLevelSceneBg.png \
    res/TapButtonSound.wav \
    res/Title.png

RESOURCES += \
    res.qrc
