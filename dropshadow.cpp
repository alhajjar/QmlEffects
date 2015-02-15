#include "dropshadow.h"

DropShadow::DropShadow(QQuickItem *parent) :
    QQuickPaintedItem(parent)
{

    connect(this,SIGNAL(sgnSourceImageChanged()),this,SLOT(sltOnsourceChanged()));
    myImage = new QImage;
    pShadow = new QGraphicsDropShadowEffect;
    m_color = Qt::blue;
    width = 0;
    height = 0;
    radius = 1.0;
    horizontalOffset = 8.0;
    verticalOffset = 8.0;
    scene = new QGraphicsScene;
    view.setScene(scene);
}

int DropShadow::getWidth()
{
    return width;
}

int DropShadow::getHeight()
{
    return height;
}

void DropShadow::setCustomWidth(int value)
{
    width = value;
    qDebug()<<"DropShadow::setCustomWidth("<<value<<")";
}

void DropShadow::setCustomHeight(int value)
{
    height = value;
    qDebug()<<"DropShadow::setCustomHeight("<<value<<")";
}



QColor DropShadow::getColor() const
{
    return m_color;
}

void DropShadow::setColor(const QColor &color)
{
    m_color = color;
}

double DropShadow::getBlurRadius() const
{
    return radius;
}

double DropShadow::getXOffset() const
{
    return horizontalOffset;
}

double DropShadow::getYOffset() const
{
    return verticalOffset;
}

void DropShadow::setXOffset(double value)
{
    horizontalOffset = value;
}

void DropShadow::setYOffset(double value)
{
    verticalOffset = value;
}

void DropShadow::setBlurRadius(const double blurRadius)
{
    radius = blurRadius;
}

void DropShadow::setImageSource(QString image)
{

    sourceImage = image;
    sgnSourceImageChanged();
}

QString DropShadow::getImageSource() const
{
    return sourceImage;
}

void DropShadow::sltOnsourceChanged()
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

void DropShadow::paint(QPainter *painter)
{
    view.setScene(scene);
    scene->setSceneRect(QRect(0,0,800,480));
    pShadow->setColor(QColor(m_color));
    pShadow->setBlurRadius(radius);
    pShadow->setXOffset(horizontalOffset);
    pShadow->setYOffset(verticalOffset);
    //    pixmap = QPixmap::fromImage( *myImage);
    QGraphicsPixmapItem *p = view.scene()->addPixmap(pixmap);
    p->setGraphicsEffect(pShadow);
    view.render(painter,QRect(0,0,800,480),QRect(0,0,800,480));
}

DropShadow::~DropShadow()
{
    delete myImage;
    delete pShadow;
    delete scene;
}
