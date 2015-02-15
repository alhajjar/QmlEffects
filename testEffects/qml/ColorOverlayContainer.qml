import QtQuick 2.0
import Qt.labs.folderlistmodel 1.0


Rectangle {
    id:root
    width: 800
    height: 480
    property alias image: image
    property alias colorOverlay: colorOverlay
    property alias prSource: image.source
    property alias target: colorOverlay.source
    property alias prVisible: colorOverlay.visible
    property alias color: colorOverlay.color
    Image{
        id:image
        anchors.fill: parent
        source:"Images/welcome_DS1.png"

    }
    ColorOverlay {
        id: colorOverlay
        source: image
        anchors.fill: image
        color: Qt.rgba(Math.random(),Math.random(),Math.random())
    }
}
