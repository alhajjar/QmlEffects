#ifndef DROPSHADOW_H
#define DROPSHADOW_H

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
 * \brief The DropShadow class, it load an Image and apply to it a DropShadow effect
 */
class DropShadow :  public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString source READ getImageSource WRITE setImageSource)
    Q_PROPERTY(QColor color READ getColor WRITE setColor)
    Q_PROPERTY(int width READ getWidth WRITE setCustomWidth)
    Q_PROPERTY(int height READ getHeight WRITE setCustomHeight)
    Q_PROPERTY(double radius READ getBlurRadius WRITE setBlurRadius)
    Q_PROPERTY(double horizontalOffset READ getXOffset WRITE setXOffset)
    Q_PROPERTY(double verticalOffset READ getYOffset WRITE setYOffset)
public:
    /*!
     * \brief DropShadow constructor
     * \param parent
     */
    DropShadow(QQuickItem *parent = 0);
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
     * \brief getColor, function to get the color of the DropShadow effect
     * \return color, QColor
     */
    QColor getColor() const;
    /*!
     * \brief setColor, function to set the color of the DropShadow effect
     * \param &color, QColor
     */
    void setColor(const QColor &color);
    /*!
     * \brief getBlurRadius, function to get the radius of the Dropshadow effect
     * \return radius, double
     */
    double getBlurRadius() const;
    /*!
     * \brief setBlurRadius, function to set the radius of the Dropshadow effect
     * \param radius, double
     */
    void setBlurRadius(const double blurRadius);
    /*!
     * \brief getXOffset, function to get the X offset of the Dropshadow effect
     * \return horizontalOffset, double
     */
    double getXOffset() const;
    /*!
     * \brief getYOffset, function to get the Y offset of the Dropshadow effect
     * \return verticalOffset, double
     */
    double getYOffset() const;
    /*!
     * \brief setXOffset, function to set the X offset of the Dropshadow effect
     * \param value, double
     */
    void setXOffset(double value);
    /*!
     * \brief setYOffset, function to get the Y offset of the Dropshadow effect
     * \param value, double
     */
    void setYOffset(double value);
    void paint(QPainter *painter);
    /*!
     *\brief Destructor of this class
     */
    ~DropShadow();


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
    QColor m_color;
    double radius;
    QGraphicsDropShadowEffect* pShadow;
    QGraphicsOpacityEffect* pOpacity;
    QGraphicsView view;
    QGraphicsScene *scene;
    int width;
    int height;
    QPixmap pixmap;
    QPainter * m_painter;
    double horizontalOffset;
    double verticalOffset;

};

#endif // DROPSHADOW_H
