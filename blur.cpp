#include "blur.h"

Blur::Blur(QQuickItem *parent) :
    QQuickPaintedItem(parent)
{
    connect(this,SIGNAL(sgnSourceImageChanged()),this,SLOT(sltOnsourceChanged()));
    myImage = new QImage;
    pBlur = new QGraphicsBlurEffect;
    width = 0;
    height = 0;
    radius = 5.0;
    scene = new QGraphicsScene;
    view.setScene(scene);
}

int Blur::getWidth()
{
    return width;
}

int Blur::getHeight()
{
    return height;
}

void Blur::setCustomWidth(int value)
{
    width = value;
    qDebug()<<"Blur::setCustomWidth("<<value<<")";
}

void Blur::setCustomHeight(int value)
{
    height = value;
    qDebug()<<"Blur::setCustomHeight("<<value<<")";
}

double Blur::getRadius() const
{
    return radius;
}

void Blur::setRadius(const double radius)
{
    this->radius = radius;
}

void Blur::setImageSource(QString image)
{
    sourceImage = image;
    sgnSourceImageChanged();
}

QString Blur::getImageSource() const
{
    return sourceImage;
}

void Blur::sltOnsourceChanged()
{
    myImage->load(sourceImage);
    if(width == 0)
    {
        width = myImage->width();
    }

    if(height == 0)
    {
        height = myImage->height();
    }
    this->setWidth(width);
    this->setHeight(height);

    pixmap = QPixmap::fromImage( myImage->scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}

void Blur::paint(QPainter *painter)
{
    view.setScene(scene);
    scene->setSceneRect(QRect(0,0,800,480));
    pBlur->setBlurRadius(radius);
   // pixmap = QPixmap::fromImage( *myImage);
    QGraphicsPixmapItem *p = view.scene()->addPixmap(pixmap);
    p->setGraphicsEffect(pBlur);
    view.render(painter,QRect(0,0,800,480),QRect(0,0,800,480));
}

Blur::~Blur()
{
    delete myImage;
    delete pBlur;
    delete scene;
}
