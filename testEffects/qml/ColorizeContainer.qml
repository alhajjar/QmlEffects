import QtQuick 2.0
import Qt.labs.folderlistmodel 1.0
import Effects 1.0
Item {
    id:root

    property alias image: image
    property alias prSource: image.source

    ColorOverlay{
        id: image
        color:"blue"
        strength: 28
    }

}
