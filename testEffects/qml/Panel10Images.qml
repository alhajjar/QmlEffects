import QtQuick 2.0

Rectangle {
width:800
height:480
property string folder1:"Images"
property alias source1:container1.source
property alias source2:container2.source
property alias source3:container3.source
property alias source4:container4.source
property alias source5:container5.source
property alias source6:container6.source
property alias source7:container7.source
property alias source8:container8.source
property alias source9:container9.source
property alias source10:container10.source
Panel1Image
{
    id:container1
    anchors.fill: parent
    source:folder1+"/welcome_DS10.png"
}

Panel1Image
{
    id:container2
    anchors.fill: parent
    source:folder1+"/welcome_DS1.png"
}

Panel1Image
{
    id:container3
    anchors.fill: parent
    source:folder1+"/welcome_DS2.png"
}

Panel1Image
{
    id:container4
    anchors.fill: parent
    source:folder1+"/welcome_DS3.png"
}

Panel1Image
{
    id:container5
    anchors.fill: parent
    source:folder1+"/welcome_DS4.png"
}

Panel1Image
{
    id:container6
    anchors.fill: parent
    source:folder1+"/welcome_DS5.png"
}

Panel1Image
{
    id:container7
    anchors.fill: parent
    source:folder1+"/welcome_DS6.png"
}

Panel1Image
{
    id:container8
    anchors.fill: parent
    source:folder1+"/welcome_DS7.png"
}

Panel1Image
{
    id:container9
    anchors.fill: parent
    source:folder1+"/welcome_DS8.png"
}

Panel1Image
{
    id:container10
    anchors.fill: parent
    source:folder1+"/welcome_DS9.png"
}

}
