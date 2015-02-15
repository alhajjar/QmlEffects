#ifndef COLOROVERLAY_H
#define COLOROVERLAY_H

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
 * \brief The ColorOverlay class, it load an Image and apply to it a ColorOverlay effect
 */
class ColorOverlay :  public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString source READ getImageSource WRITE setImageSource)
    Q_PROPERTY(QColor color READ getColor WRITE setColor)
    Q_PROPERTY(int width READ getWidth WRITE setCustomWidth)
    Q_PROPERTY(int height READ getHeight WRITE setCustomHeight)
    Q_PROPERTY(double strength READ getStrength WRITE setStrength)
public:
    /*!
     * \brief ColorOverlay constructor
     * \param parent
     */
    ColorOverlay(QQuickItem *parent = 0);
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
     * \brief getColor, function to get the color of the ColorOverlay effect
     * \return color, QColor
     */
    QColor getColor() const;
    /*!
     * \brief setColor, function to set the color of the ColorOverlay effect
     * \param &color, QColor
     */
    void setColor(const QColor &color);
    /*!
     * \brief getStrength, function to get the strenght of the ColorOverlay effect
     * \return strength, double
     */
    double getStrength() const;
    /*!
     * \brief setStrength, function to set the strenght of the ColorOverlay effect
     * \param strength, double
     */
    void setStrength(const double strength);
    /*!
     * \brief paint, overload of the function paint of QQuickPaintedItem it paint the ColorOverlayed image
     * \param painter, QPainter
     */
    void paint(QPainter *painter);
    /*!
     *\brief Destructor of this class
     */
    ~ColorOverlay();

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
    double strength;
    QGraphicsColorizeEffect* pColorize;
    QGraphicsOpacityEffect* pOpacity;
    QGraphicsView view;
    QGraphicsScene *scene;
    int width;
    int height;
    QPixmap pixmap;
    QPainter * m_painter;

};

#endif // COLOROVERLAY_H
