import QtQuick 2.0
import Qt.labs.folderlistmodel 1.0
import Effects 1.0


Rectangle {
    id:root
    width: 800
    height: 480
    color: "white"
       ColorOverlay{
        source:"Images/meditate.png"
        color:"blue"
        strength: 0.5
        width: 500
        x:300
    }

    DropShadow{
  
        source:"Images/meditate.png"
        enabled:            true
        radius:             21.0
        color:              Qt.rgba(63, 63, 63, 180)
        horizontalOffset:   8
        verticalOffset:     8
        opacity: 1
        x:500
        y:200
    }

    Blur{
        source:"Images/meditate.png"
        radius: 0
        width:100
        x:100
    }
}
