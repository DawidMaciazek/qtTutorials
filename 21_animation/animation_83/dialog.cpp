#include "dialog.h"
#include "ui_dialog.h"
#include "myitem.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(-200, -200, 300, 300);

    QPen mypen = QPen(Qt::red);

    QLineF topLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    QLineF bottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());
    QLineF leftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    QLineF rightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());

    scene->addLine(topLine, mypen);
    scene->addLine(bottomLine, mypen);
    scene->addLine(leftLine, mypen);
    scene->addLine(rightLine, mypen);


    int itemCount = 1;
    for(int i = 0; i < itemCount; i++)
    {
        MyItem *item = new MyItem(i); //mem leak?
        scene->addItem(item);
    }


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),
            scene, SLOT(advance()));
    timer->start(200);
}

Dialog::~Dialog()
{
    delete ui;
}
