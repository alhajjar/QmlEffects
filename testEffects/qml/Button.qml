

import QtQuick 2.0 
import QtGraphicalEffects 1.0


Rectangle {
    id: root
    height: 74
    width: 148
    color:"grey"
    opacity: 0.6
    radius: 10

    signal sgnCMDValidateSingle()

    property alias label: label
    property alias label_name: label
    property alias text_alignement: label.horizontalAlignment
    property alias touchArea: touchArea

        Item{
            id: c_Button_UTIL_LEFT_0
            anchors.fill: parent

            Text {
                id: label
                color:"white"
                objectName: "label"
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 9
                anchors.left: parent.left
                anchors.leftMargin: 46
                anchors.right: parent.right
                anchors.rightMargin: 0
                horizontalAlignment: Text.AlignLeft
                maximumLineCount: 2
            }


        }


        MouseArea  {
            id: touchArea
            objectName: "touchArea"
            anchors.bottomMargin: 0
            anchors.fill: parent
            onClicked: sgnCMDValidateSingle()
            hoverEnabled: true
            onEntered:root.opacity = 1
            onExited:  root.opacity = 0.6
        }



}

