import QtQuick 2.0
import Qt.labs.folderlistmodel 1.0
import Effects 1.0

//import Label 1.0


Rectangle {
    id:root
    width: 800
    height: 480
    color: "white"
    //    Image
    //    {
    //        anchors.fill: parent
    //        source:"Images/welcome_DS111.png"
    //    }

    property bool shiftedPlus:false

    //    Panel1Image{
    //    id:container
    //        folder:"Images100"
    //    }

    /* Panel10Images{
        id:container0
        folder1:"Images100"
    }
    Panel20Images{
        id:container1
        folder:"Images100"
    }
    */
    //    Panel50Images{
    //        id:container
    //        folder5:"Images"
    //    }

    //    Panel1Image{
    //        id:container
    //        folder:"Images"
    //    }


    ColorOverlay{
        //    anchors.fill: parent
        //    source: "Images/0027_Guidance.png"
        source:"Images/meditate.png"
        color:"blue"
        strength: 0.5
        width: 500
//        height: 600
        x:300
    }

    DropShadow{
        //    anchors.fill: parent
        //    source: "Images/0027_Guidance.png"
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
        //    anchors.fill: parent
        //    source: "Images/0027_Guidance.png"
        source:"Images/meditate.png"
        radius: 0
        width:100
        x:100
        //    y:100
    }

    //Effect{
    ////    anchors.fill: parent
    //    width:100
    //    height: 100
    ////    source: "Images/0027_Guidance.png"
    //    source:"Images/meditate.png"
    //    strength: 0.5
    //    color:"red"
    //    x:200
    //}
    Button {
        id: buttonONOFF
        label.text:"Show Graph"
        x:10
        y:20
        height: 40
        width: 167
    }

    Connections
    {
        target: buttonONOFF
        onSgnCMDValidateSingle:
        {

        }
    }


    //    Timer{
    //        id:timer1
    //        interval:250
    //        repeat :true
    //        running: true
    //        onTriggered: {

    //            if(shiftedPlus)
    //                container.x = container.x-1
    //            else
    //                container.x = container.x+1

    //            shiftedPlus = !shiftedPlus


    //        }
    //    }

    Component.onCompleted: {


        //viewer.startUpdateViewer(1000)
    }

}
