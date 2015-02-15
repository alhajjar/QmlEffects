import QtQuick 2.0
import QtGraphicalEffects 1.0

Rectangle {
    id:root
    width: 800
    height: 480
    property alias prSource: image.source

    Image{
        id:image
        anchors.fill: parent

    }
    Image {
        id: mask
        anchors.fill:  parent
        sourceSize: Qt.size(parent.width, parent.height)
        opacity: 0.01
        smooth: true
       // source: idStyle.prUniverseImagesSystemRepository + idStyle.prUniverseAmbiance.image_repository+"Masque_CF_Radio_gauche.png"
    }
    OpacityMask {
        id: opacitymask
        anchors.fill: image
        maskSource: mask
        source: image
        z: 100
    }
}
