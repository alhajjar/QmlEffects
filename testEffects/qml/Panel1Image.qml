import QtQuick 2.0

Rectangle {
width:800
height:480
property alias source:container.prSource
property string folder:"Images"
ColorizeContainer
{
    id:container
    anchors.fill: parent
    prSource:folder+"/welcome_DS111.png"
}
Component.onCompleted:{
//print("prSource = "+ container.prSource)
}
}
