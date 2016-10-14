#include "dialog.h"
#include "ui_dialog.h"

#include "dragitem.h"
#include <QDebug>
#include <QDragEnterEvent>
#include <QDataStream>
#include <QMimeData>
#include <QVector>

#include <QScrollBar>

#include <QGraphicsColorizeEffect>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    cnt = 0;
    dragSource = -1;

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
    /*
    int dragPos = event->pos().x();

    int cnt = ui->horizontalLayout->count();

    for(int i=0; i<cnt; i++)
    {
        int x = ui->horizontalLayout->itemAt(i)->widget()->pos().x();
        int w = ui->horizontalLayout->itemAt(i)->widget()->width();

        if (dragPos > x && dragPos < x+w)
        {
            //ui->horizontalLayout->itemAt(i)->widget()->setGraphicsEffect(clearEffect);
            //ui->horizontalLayout->takeAt(i);
        }
        else
        {
            //ui->horizontalLayout->itemAt(i)->widget()->setGraphicsEffect(shadowEffect);
        }
    }
    */
}

void Dialog::dragEnterEvent(QDragEnterEvent *event)
{
    event->setAccepted(true);
}

void Dialog::dropEvent(QDropEvent *event)
{
    int dragPos = event->pos().y();
    int cnt = ui->verticalLayout->count();

    QVector<DragItem *> widgets;

    int sourceIndex = -1;
    int swapIndex = -1;

    qDebug() << "dro event";
    for(int i=0; i<cnt; i++)
    {
        qDebug() << i;
        DragItem *currentWidget =
                qobject_cast<DragItem *>(ui->verticalLayout->itemAt(i)->widget());

        if(currentWidget)
        {
            widgets.append(currentWidget);
        }

        int y = currentWidget->pos().y();
        int h = currentWidget->height();

        if (dragPos > y && dragPos < y+h)
        {
            swapIndex = i;
        }

        if (currentWidget == event->source())
        {
            sourceIndex = i;
        }
    }

    for(int i=0; i<widgets.length(); i++)
    {
        qDebug() << "removing:"<<i;
        ui->verticalLayout->removeWidget(widgets[i]);
        //ui->gridLayout->removeWidget(widgets[i]);
    }

    //for(int i=widgets.length()-1; i>=0; i--)
    for(int i=0; i<widgets.length(); i++)
    {
        //if(i == 2)
        //    continue;
        ui->verticalLayout->addWidget(widgets[i]);
    }
    ui->verticalLayout->addWidget(widgets[2]);

    qDebug() << ui->scrollArea->size();
    qDebug() << ui->scrollArea->verticalScrollBar()->value();

    /*
    DragItem *sourceWidget = qobject_cast<DragItem *>(ui->gridLayout->itemAtPosition(sourceIndex,0)->widget());
    DragItem *swapWidget = qobject_cast<DragItem *>(ui->gridLayout->itemAtPosition(swapIndex,0)->widget());

    ui->gridLayout->removeWidget(sourceWidget);
    ui->gridLayout->removeWidget(swapWidget);

    ui->gridLayout->addWidget(sourceWidget, swapIndex, 0);
    ui->gridLayout->addWidget(swapWidget, sourceIndex, 0);

    ui->gridLayout->update();

    qDebug() << ui->scrollArea->visibleRegion();



    qDebug() << "----";
    dragSource = -1;
    */
}

void Dialog::on_pushButton_clicked()
{

    //DragItem *drag = new DragItem(cnt, this);

    //QGraphicsColorizeEffect *effect = new QGraphicsColorizeEffect(this);
    //effect->setColor(QColor(124,124,124,124));


    //ui->horizontalLayout->addWidget(drag);


}

void Dialog::on_pushButton_2_clicked()
{
    DragItem *drag = new DragItem(cnt, this);
    //ui->gridLayout->addWidget(drag,cnt,0);//,Qt::AlignTop);
    //ui->gridLayout->addWidget(drag,cnt,0);
    ui->verticalLayout->addWidget(drag);
    cnt++;
}
