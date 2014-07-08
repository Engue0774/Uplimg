#include "selectareaband.h"
#include "screenmanager.h"


SelectAreaBand::SelectAreaBand(ScreenManager *manager, QWidget * parent) : QLabel(parent)
{
    this->setCursor(Qt::CrossCursor);
    rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
    this->manager = manager;
    QObject::connect(this, SIGNAL(areaTaken(QRect)), manager, SLOT(areaPictureTaken(QRect)));
}

void SelectAreaBand::selectArea()
{
    showFullScreen();
}

void SelectAreaBand::mousePressEvent(QMouseEvent * event)
{
    if(event->button() != Qt::LeftButton)
        return;

    origin = event->pos();
    rubberBand->setGeometry(QRect(origin, QSize(0,0)));
    rubberBand->show();
}

void SelectAreaBand::mouseMoveEvent(QMouseEvent * event)
{
    rubberBand->setGeometry(QRect(origin, event->pos()).normalized());
}

void SelectAreaBand::mouseReleaseEvent(QMouseEvent * event)
{
    if(event->button() != Qt::LeftButton)
        return;

    rubberBand->hide();
    this->hide();
    emit areaTaken(QRect(origin, event->pos()).normalized());
}

void SelectAreaBand::keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_Escape)
        {
            this->close();
        }
}

SelectAreaBand::~SelectAreaBand() {}
