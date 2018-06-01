#include "widget.h"
#include "ui_widget.h"

#include <QGraphicsView>
#include <QKeyEvent>
#include <qdebug.h>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(810,610);
    round=0;
    msg=new QMessageBox(this);
    timer=new QTimer(this);
    timershot=new QTimer(this);

    Game=new QWidget(this);
    Game->move(5,5);
    Game->resize(800,600);

    scene=new QGraphicsScene (Game);
    scene->setSceneRect(0, 0, 800,600);

    Ship=new Nave(400,500);
    scene->addItem(Ship);

    QGraphicsView *view=new QGraphicsView(scene,Game);
    view->setBackgroundBrush(QPixmap(":/Image/giphy.gif"));
    view->setFrameShape(QFrame::NoFrame);
    view->resize(802, 602);
    view->setEnabled(true);

    Inicio=1;
    righting=lefting=uping=downing=false;
    shotting=false;

    timer->start(15);
    timershot->start(200);
    connect(timer,SIGNAL(timeout()),this,SLOT(mover()));
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    connect(timershot,SIGNAL(timeout()),this,SLOT(reload()));

    for(int flag=0;flag<20;flag++){
        Shot[flag]=new Bala(10000,10000);
    }


    for(int flag=0;flag<20;flag++){
        dibujar_alien(flag,flag*50+25,150);
    }


}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event){

    if (event->key()==Qt::Key_Right||event->key()==Qt::Key_D){      // activa el movimiento de la nave hacia la derecha
        righting=true;
    }
    if (event->key()==Qt::Key_Left||event->key()==Qt::Key_A){       // activa el movimiento de la nave hacia la izquierda
        lefting=true;
    }
    if (event->key()==Qt::Key_Up||event->key()==Qt::Key_W){         // activa el movimiento de la nave hacia la arriba
        uping=true;
    }
    if (event->key()==Qt::Key_Down||event->key()==Qt::Key_S){       // activa el movimiento de la nave hacia la abajo
        downing=true;
    }
    if (event->key()==Qt::Key_Control){                             // activa el disparo de nave
        shotting=true;
    }
    if (event->key()==Qt::Key_Escape){
        this->close();
    }

}

void Widget::keyReleaseEvent(QKeyEvent *event){
    if (event->key()==Qt::Key_Right||event->key()==Qt::Key_D){      // desactiva el movimiento de la nave hacia la derecha
        righting=false;
    }
    if (event->key()==Qt::Key_Left||event->key()==Qt::Key_A){       // desactiva el movimiento de la nave hacia la izquierda
        lefting=false;
    }
    if (event->key()==Qt::Key_Up||event->key()==Qt::Key_W){         // desactiva el movimiento de la nave hacia la arriba
        uping=false;
    }
    if (event->key()==Qt::Key_Down||event->key()==Qt::Key_S){       // desactiva el movimiento de la nave hacia la abajo
        downing=false;
    }
    if (event->key()==Qt::Key_Control){                             // desactiva el disparo de nave
        shotting=false;
    }
}

void Widget::mover(){

    if (righting==true && Ship->getI()<800){
        Ship->setI(Ship->getI()+5);
    }
    if (lefting==true && Ship->getI()>0){
        Ship->setI(Ship->getI()-5);
    }
    if (uping==true && Ship->getJ()>0){
        Ship->setJ(Ship->getJ()-5);
    }
    if (downing==true && Ship->getJ()<600){
        Ship->setJ(Ship->getJ()+5);
    }
    if (shotting==true && Inicio==1){
        Shot[round]=new Bala(Ship->getI(),Ship->getJ()-28);
        scene->addItem(Shot[round]);
        round++;
        Inicio=0;
    }

    if(round>20){
        round=0;
    }
    for(int flag=0;flag<20;flag++){
        for(int N_A=0;N_A<20;N_A++){
            if(Shot[flag]->collidesWithItem(Spaceship[N_A])&&Spaceship[N_A]->isActive()==true){
                scene->removeItem(Spaceship[N_A]);
                scene->removeItem(Shot[flag]);
            }
        }
    }
    for(int N_A=0;N_A<20;N_A++){
        if(Ship->collidesWithItem(Spaceship[N_A])&&Spaceship[N_A]->isActive()==true){
            msg->setWindowTitle("*Purgarotio*");
            msg->setText("\nPerdio el turno");
            msg->show();
        }
    }
}

void Widget::reload(){
    Inicio=1;
    for(int flag=0;flag<20;flag++){
        if(Shot[flag]->getJ()<0){
            scene->removeItem(Shot[flag]);
        }
    }
}

void Widget::dibujar_alien(int num,int x,int y){
    int intRand = (qrand()%2);
    Spaceship[num]=new Alien(x,y,intRand);
    scene->addItem(Spaceship[num]);
}
