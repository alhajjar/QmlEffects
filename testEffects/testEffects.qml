import QtQuick 2.1
import Effects 1.0

Rectangle {
    width: 800
    height: 380

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

	SimpleApp{
	id:simpleApp
	}

}

