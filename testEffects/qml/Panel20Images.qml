import QtQuick 2.0

Rectangle {
width:800
height:480
property string folder:"Images"
property alias source1:container1.source1
property alias source2:container1.source2
property alias source3:container1.source3
property alias source4:container1.source4
property alias source5:container1.source5
property alias source6:container1.source6
property alias source7:container1.source7
property alias source8:container1.source8
property alias source9:container1.source9
property alias source10:container1.source10
property alias source11:container2.source1
property alias source12:container2.source2
property alias source13:container2.source3
property alias source14:container2.source4
property alias source15:container2.source5
property alias source16:container2.source6
property alias source17:container2.source7
property alias source18:container2.source8
property alias source19:container2.source9
property alias source20:container2.source10
Panel10Images
{
    id:container1
    anchors.fill: parent
    source1:folder+"/welcome_DS1.png"
    source2:folder+"/welcome_DS2.png"
    source3:folder+"/welcome_DS3.png"
    source4:folder+"/welcome_DS4.png"
    source5:folder+"/welcome_DS5.png"
    source6:folder+"/welcome_DS6.png"
    source7:folder+"/welcome_DS7.png"
    source8:folder+"/welcome_DS8.png"
    source9:folder+"/welcome_DS9.png"
    source10:folder+"/welcome_DS10.png"
}

Panel10Images
{
    id:container2
    anchors.fill: parent
    source1:folder+"/welcome_DS11.png"
    source2:folder+"/welcome_DS12.png"
    source3:folder+"/welcome_DS13.png"
    source4:folder+"/welcome_DS14.png"
    source5:folder+"/welcome_DS15.png"
    source6:folder+"/welcome_DS16.png"
    source7:folder+"/welcome_DS17.png"
    source8:folder+"/welcome_DS18.png"
    source9:folder+"/welcome_DS19.png"
    source10:folder+"/welcome_DS20.png"
}


}
