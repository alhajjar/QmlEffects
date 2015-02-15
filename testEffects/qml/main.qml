import QtQuick 2.0
import QtGraphicalEffects 1.0
//import "TestCases/MediaPixel"
import Qt.labs.folderlistmodel 1.0



Item {
    id: idRoot
    width: 800
    height: 480

    property int compilationTimeStart:0
    property int compilationTimeStop:0
    property int creationTimeStart:0
    property int creationTimeStop:0

    property int minutes:0
    property int seconds:0
    property int milliseconds:0

//    Style {
//        id: idStyle
//        objectName: "idStyle"
//        prIsTarget: false
//        prInterPanelAnimation: true
//        prIntraPanelAnimation: true
//        prHmiResourcesRepository: "../../Applis/HMIResources/Universes"
//    }

    function fnReturnTime()
    {
        var date = new Date();
        minutes = date.getMinutes()
        seconds = date.getSeconds()
        milliseconds = minutes*60*1000 + seconds*1000 + date.getMilliseconds()
        print("fnReturnTime : milliseconds --------------------------->"+milliseconds)
        return milliseconds
    }


    Timer {
        id: idCompilationTimer
        running: false
        onRunningChanged: {
            if (running == true)
            {
                compilationTimeStart = fnReturnTime()
                print("Compilation Time started")
            }
            else {
                compilationTimeStop = fnReturnTime()
                print("Compilation Time :"+(compilationTimeStop-compilationTimeStart))
            }
        }


    }


    Timer {
        id: idCreationTimer
        onRunningChanged: {
            if (running == true)
            {

                creationTimeStart = fnReturnTime()
                print("creation Time started")
            }
            else {

                creationTimeStop = fnReturnTime()
                print("creation Time :"+(creationTimeStop-creationTimeStart))
            }
        }
    }
    SimpleApp{
        anchors.fill: parent
    }

    Component.onCompleted: {
        idCompilationTimer.running = true
//    var component = Qt.createComponent("../qml/SimpleApp.qml")
	//var component = Qt.createComponent("SimpleLoaderApp.qml")
       
        //var component = Qt.createComponent("TestCases/MediaHypnose/MEDIA_0001Skin.qml")
      //  var component = Qt.createComponent("TestCases/MediaPixel/MEDIA_0001Skin.qml")
//        if (component.status === Component.Ready)
//        {
//            idCompilationTimer.running = false
//            idCreationTimer.running = true
//            var obj = component.createObject(idRoot)
//            idCreationTimer.running = false
//        }
//        viewer.startUpdateViewer(1000)
    }


}

