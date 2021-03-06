import QtQuick 2.6
import QtQuick.Controls 2.0

Rectangle {
    id: base
    color: "#f9f9f9"
    border.width:1
    border.color: "#bdc3c7"
    
    width: 600
    height: 500
    
    ListView {
        objectName: "lliurex.lnf.selector"
        id: packages
        width: parent.width-5; height: parent.height-5
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        
        visible: true
        model: lnfModel
        focus: true
        
        Component.onCompleted: {
            packages.currentIndex=lnfCurrentIndex
        }
        
        delegate:
            Rectangle {
                anchors.horizontalCenter: parent.horizontalCenter
                
                width: parent.width
                height: childrenRect.height+20
                color: (packages.currentIndex==index) ? "#bfdcf1" : "#f9f9f9"
                
                MouseArea {
                    anchors.fill: preview
                    onClicked: {
                        packages.currentIndex=index
                        lnfIndex=index
                    }
                  }
                
                Image {
                    id: preview
                    y: 10
                    anchors.horizontalCenter: parent.horizontalCenter
                    source: "file:/usr/share/plasma/look-and-feel/"+lnfModel[index].path+"/contents/previews/preview.png"
                    
                }
                
                Text {
                    anchors.top: preview.bottom
                    anchors.margins: 5
                    anchors.horizontalCenter: preview.horizontalCenter
                    
                    text: lnfModel[index].name
                }
            }
        
    }
}