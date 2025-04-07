import QtQuick 2.15

Item{
    id: root
    signal choosing();
    signal outChoosing();
    signal closeAll();
    property alias modelSub: titleSublist.model

    onChoosing: {
        expanded = true
        closeAni.stop();
        openAni.start();
    }

    onOutChoosing: {
        expanded = false
        openAni.stop()
        closeAni.start()
    }

    property string textShow
    property string imageChoosing: "qrc:/image/menu_K_02.png"
    property string imageOutChoosing: "qrc:/image/menu_K_04.png"
    // property alias modelItem: textFunction.text
    property bool expanded: false
    Rectangle {
        id: title
        width: parent.width
        height: 60
        color: "white"
        anchors.top: root.top

        MouseArea{
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                cursorShape = Qt.PointingHandCursor
            }
            onExited: {
                cursorShape = Qt.ArrowCursor
            }
            onClicked: {
                if(!root.expanded){
                    root.closeAll();
                    root.choosing();
                }
                else {
                    root.outChoosing()
                }
            }
        }

        Text{
            id: textFunction
            text: root.textShow
            color: "#a7a7a7"
            font.pointSize: 14
            anchors {
                left: parent.left
                leftMargin: 15
                verticalCenter: parent.verticalCenter
            }
        }

        Image {
            id: functionImage
            width: height = textFunction.height
            source: imageOutChoosing
            anchors {
                right: parent.right
                rightMargin: 15
                verticalCenter: parent.verticalCenter
            }
        }

        Rectangle{
            width: parent.width
            height: 1
            color: "#a7a7a7"
            anchors.bottom: title.bottom
        }

    }

    NumberAnimation{
        id: openAni
        target: root
        property: "height"
        running: false
        to: 60 + titleSublist.height
        duration: 500
        onStarted: {
            // titleSublist.z = 3
            titleSublist.visible = true
        }
        onStopped: {
            title.color = "#05141f"
            textFunction.color = "#a5a5a5"
            functionImage.source = root.imageChoosing
        }
    }

    NumberAnimation{
        id: closeAni
        target: root
        property: "height"
        running: false
        to: 60
        duration: 500
        onStopped: {
            titleSublist.visible = false
            title.color = "white"
            textFunction.color = "#a7a7a7"
            functionImage.source = root.imageOutChoosing
        }
    }

    ListView{
        id: titleSublist
        width: parent.width
        height: title.height * titleSublist.count
        visible: false
        anchors.top: title.bottom
        interactive: false
        delegate: Rectangle{
            width: titleSublist.width
            height: title.height
            color: "#f6f3f2"
            Text {
                id: name
                text: qsTr(modelData)
                color: "#888a76"
                font.pointSize: 14
                anchors {
                    left: parent.left
                    leftMargin: 15
                    verticalCenter: parent.verticalCenter
                }
            }
            MouseArea{
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {
                    cursorShape = Qt.PointingHandCursor
                }
                onExited: {
                    cursorShape = Qt.ArrowCursor
                }
                onClicked: {
                    console.log("click to %1".arg(name.text))
                }
            }
        }
    }
}

