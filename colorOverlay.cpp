#include "colorOverlay.h"


ColorOverlay::ColorOverlay(QQuickItem *parent) :
    QQuickPaintedItem(parent)
{

    connect(this,SIGNAL(sgnSourceImageChanged()),this,SLOT(sltOnsourceChanged()));
    myImage = new QImage;
    pColorize = new QGraphicsColorizeEffect;
    m_color = Qt::blue;
    width = 0;
    height = 0;
    strength = 1.0;
    scene = new QGraphicsScene;
    view.setScene(scene);
}

int ColorOverlay::getWidth()
{
    return width;
}

int ColorOverlay::getHeight()
{
    return height;
}

void ColorOverlay::setCustomWidth(int value)
{
    width = value;
    qDebug()<<"ColorOverlay::setCustomWidth("<<value<<")";
}

void ColorOverlay::setCustomHeight(int value)
{
    height = value;
    qDebug()<<"ColorOverlay::setCustomHeight("<<value<<")";
}


QColor ColorOverlay::getColor() const
{
    return m_color;
}

void ColorOverlay::setColor(const QColor &color)
{
    m_color = color;
}

double ColorOverlay::getStrength() const
{
    return strength;
}

void ColorOverlay::setStrength(const double strength)
{
    this->strength = strength;
}

void ColorOverlay::setImageSource(QString image)
{
    sourceImage = image;
    sgnSourceImageChanged();
}

QString ColorOverlay::getImageSource() const
{
    return sourceImage;
}

void ColorOverlay::sltOnsourceChanged()
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

void ColorOverlay::paint(QPainter *painter)
{
    view.setScene(scene);
    scene->setSceneRect(QRect(0,0,800,480));
    pColorize->setColor(QColor(m_color));
    pColorize->setStrength(strength);
    QGraphicsPixmapItem *p = view.scene()->addPixmap(pixmap);
    p->setGraphicsEffect(pColorize);
    view.render(painter,QRect(0,0,800,480),QRect(0,0,800,480));
}

ColorOverlay::~ColorOverlay()
{
    delete myImage;
    delete pColorize;
    delete scene;
}
