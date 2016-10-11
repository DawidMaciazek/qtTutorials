#include "dialog.h"
#include "ui_dialog.h"

#include "dragitem.h"
#include <QDebug>
#include <QDragEnterEvent>

#include <QGraphicsColorizeEffect>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //QLabel *lab = new QLabel(this);
    //lab->setPixmap(QPixmap::fromImage(QImage(":/resource/plot_img.png")));
    //ui->horizontalLayout->addWidget(lab);

    setAcceptDrops(true);

    shadowEffect = new QGraphicsColorizeEffect(this);
    shadowEffect->setColor(QColor(255, 0, 0, 128));

    clearEffect = new QGraphicsColorizeEffect(this);
    clearEffect->setColor(QColor(0, 0, 0, 0));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::dragMoveEvent(QDragMoveEvent *event)
{
    int dragPos = event->pos().x();

    int cnt = ui->horizontalLayout->count();

    for(int i=0; i<cnt; i++)
    {
        int x = ui->horizontalLayout->itemAt(i)->widget()->pos().x();
        int w = ui->horizontalLayout->itemAt(i)->widget()->width();

        if (dragPos > x && dragPos < x+w)
        {
            //ui->horizontalLayout->itemAt(i)->widget()->setGraphicsEffect(clearEffect);
            ui->horizontalLayout->takeAt(i)
        }
        else
        {
            //ui->horizontalLayout->itemAt(i)->widget()->setGraphicsEffect(shadowEffect);
        }
    }
}

void Dialog::dragEnterEvent(QDragEnterEvent *event)
{
    event->setAccepted(true);
}

void Dialog::on_pushButton_clicked()
{

    DragItem *drag = new DragItem(this);

    QGraphicsColorizeEffect *effect = new QGraphicsColorizeEffect(this);
    effect->setColor(QColor(124,124,124,124));


    ui->horizontalLayout->addWidget(drag);


}

void Dialog::on_pushButton_2_clicked()
{
    DragItem *drag = new DragItem(this);
    ui->horizontalLayout->addWidget(drag);
}
