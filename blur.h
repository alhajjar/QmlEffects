#ifndef BLUR_H
#define BLUR_H

#include <QtGui>
#include <QtCore>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEffect>
#include <QtQuick/QQuickPaintedItem>
#include <QLabel>
#include <QPainter>
#include <QGraphicsProxyWidget>

/*!
 * \brief The Blur class, it load an Image and apply to it a Blur effect
 */
class Blur :  public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString source READ getImageSource WRITE setImageSource)
    Q_PROPERTY(int width READ getWidth WRITE setCustomWidth)
    Q_PROPERTY(int height READ getHeight WRITE setCustomHeight)
    Q_PROPERTY(double radius READ getRadius WRITE setRadius)
public:
    /*!
     * \brief Blur constructor
     * \param parent
     */
    Blur(QQuickItem *parent = 0);

    /*!
     * \brief getWidth, function to get the width of the image
     * \return width, int
     */
    int getWidth();
    /*!
     * \brief getHeight, function to get the height of the image
     * \return height, int
     */
    int getHeight();
    /*!
     * \brief setCustomWidth, function to set the width of the image
     * \param width, int
     */
    void setCustomWidth(int width);
    /*!
     * \brief setCustomHeight, function to set the height of the image
     * \param height, int
     */
    void setCustomHeight(int height);
    /*!
     * \brief getRadius, function to get the radius of the Blur effect
     * \return radius, double
     */
    double getRadius() const;
    /*!
     * \brief setRadius, function to set the radius of the Blur effect
     * \param radius, double
     */
    void setRadius(const double radius);
    /*!
     * \brief setImageSource, function to set the name of the image
     * \param myImage, QString
     */
    void setImageSource(QString myImage);
    /*!
     * \brief getImageSource, function to get the name of the image
     * \return sourceImageName, QString
     */
    QString getImageSource() const;
    /*!
     * \brief paint, overload of the function paint of QQuickPaintedItem it paint the Blured image
     * \param painter, QPainter
     */
    void paint(QPainter *painter);
    /*!
     *\brief Destructor of this class
     */
    ~Blur();


signals:
    /*!
     * \brief sgnSourceImageChanged, signal emited when the sourceName of image is changed
     */
    void sgnSourceImageChanged();

public slots:
    /*!
     * \brief sltOnsourceChanged, slot that detect the signal sgnSourceImageChanged, it load the wanted image
     */
    void sltOnsourceChanged();
private:
    QImage *myImage;
    QString sourceImage;
    double radius;
    QGraphicsBlurEffect* pBlur;
    QGraphicsOpacityEffect* pOpacity;
    QGraphicsView view;
    QGraphicsScene *scene;
    int width;
    int height;
    QPixmap pixmap;
    QPainter * m_painter;

};

#endif // BLUR_H
