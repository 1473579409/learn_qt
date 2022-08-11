#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
#include <QSound>//音效头文件

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //配置主场景

    //设置固定大小
    setFixedSize(320,588);

    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    setWindowTitle("翻金币主场景");

    //退出按钮实现
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });

    //准备开始按钮的音效
    QSound * startSound = new QSound(":/res/TapButtonSound.wav",this);
//    startSound->setLoops(-1); //设置循环  -1表示无限循环
    startSound->play();

    //开始按钮
    MyPushButton * startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5 - startBtn->width()*0.5, this->height()*0.7);

    //实例化选择关卡场景
    chooseScene = new ChooseLevelScene;

    //监听选择关卡的返回按钮的信号
    connect(chooseScene, &ChooseLevelScene::chooseSceneBack,this,[=](){
        this->setGeometry(chooseScene->geometry());
        chooseScene->hide();
        this->show();
    });

    connect(startBtn,&MyPushButton::clicked,[=](){
//         qDebug() << "点击了开始";
        //播放开始音效资源
        startSound->play();

         //弹起特效
         startBtn->zoom1();
         startBtn->zoom2();

         //延时进入选择
         QTimer::singleShot(500,this,[=](){
             //设置chooseScene场景的位置
             chooseScene->setGeometry(this->geometry());

             //自身隐藏
             this->hide();
             //显示选择关卡场景
             chooseScene->show();
         });

    });

}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画背景图上图标
    pix.load(":/res/Title.png");

    pix = pix.scaled( pix.width()*0.5,pix.height()*0.5 );

    painter.drawPixmap(10,30,pix);
}



MainWindow::~MainWindow()
{
    delete ui;
}

