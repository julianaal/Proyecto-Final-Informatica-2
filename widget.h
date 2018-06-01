#include <QTimer>
#include <QMessageBox>
#include "nave.h"
#include "bala.h"
#include "alien.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QWidget *Game;
    QGraphicsScene *scene;
    QTimer *timer;
    QTimer *timershot;
    QMessageBox *msg;

    Nave *Ship;
    Alien *Spaceship[50];
    Bala *Shot[20];

    int Inicio;
    int round;
    bool righting,lefting;
    bool uping,downing;
    bool shotting;
    void dibujar_alien(int,int,int);

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private slots:
    void mover();
    void reload();
};

#endif // WIDGET_H
