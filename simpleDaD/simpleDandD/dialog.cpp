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
    if(! event->mimeData()->hasFormat(DragItem::dragItemMimeType()))
    {
        event->ignore();
        return;
    }

    int scrollShift = 0;

    if(ui->scrollArea->verticalScrollBar())
        scrollShift = ui->scrollArea->verticalScrollBar()->value();

    int dropPos = event->pos().y() + scrollShift;
    int cnt = ui->verticalLayout->count();

    QVector<DragItem *> widgets;
    DragItem * dropWidget = NULL;

    qDebug() << "dro event: " << dropPos;

    qDebug() << scrollShift;

    int dropIndex = 0;
    int localWidget = 0;
    bool continueSearch = true;
    for(int i=0; i<cnt; i++)
    {
        DragItem *currentWidget =
                qobject_cast<DragItem *>(ui->verticalLayout->itemAt(i)->widget());
        int currentCenter = currentWidget->pos().y() + currentWidget->height()/2;

        if(dropPos < currentCenter && continueSearch)
        {
            dropIndex = i - localWidget;
            continueSearch = false;
        }

        if(currentWidget == event->source())
        {
            localWidget = 1;
            dropWidget = currentWidget;
        }
        else
        {
            widgets.append(currentWidget);
        }
    }

    if(continueSearch)
    {
        dropIndex = cnt - 1;
    }

    if(dropWidget == NULL)
    {
        qDebug() << "widget is from outside !!";
        QByteArray itemData = event->mimeData()->data(DragItem::dragItemMimeType());
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        int itemIndex;
        dataStream >> itemIndex;

        widgets.insert(dropIndex,new DragItem(itemIndex,this));
    }
    else
    {
        widgets.insert(dropIndex, dropWidget);
    }

    for(int i=0; i<widgets.length(); i++)
    {
        ui->verticalLayout->removeWidget(widgets[i]);
    }

    for(int i=0; i<widgets.length(); i++)
    {
        ui->verticalLayout->addWidget(widgets[i]);
    }

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
    DragItem *drag = new DragItem(cnt, this);
    ui->verticalLayout_2->addWidget(drag);
    cnt++;
}

void Dialog::on_pushButton_2_clicked()
{
    DragItem *drag = new DragItem(cnt, this);
    //ui->gridLayout->addWidget(drag,cnt,0);//,Qt::AlignTop);
    //ui->gridLayout->addWidget(drag,cnt,0);
    ui->verticalLayout->addWidget(drag);
    cnt++;
}
