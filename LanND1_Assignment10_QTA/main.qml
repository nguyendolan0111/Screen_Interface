import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    id: root
    width: 1000
    height: 600
    visible: true
    title: qsTr("Kia Owner manuals")

    Rectangle {
        anchors.fill: parent
        color: "#1c1c1b"
    }

    Flickable {
        id: flickable
        anchors.fill: parent
        contentWidth: parent.width
        contentHeight: 1200
        // property int gridHeight: root.height - 100

        Image{
            id: greetingImage
            width: parent.width - 100
            height: flickable.contentHeight - grid.height - 20
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            source: "qrc:/image/carImagePc.jpg"
        }
        Image{
            id: logo
            width: 100
            fillMode: Image.PreserveAspectFit
            source: "qrc:image/Logo_K.png"
            anchors {
                left: greetingImage.left
                top: parent.top
                leftMargin: 20
            }
        }

        Text{
            text: qsTr("Gen5 Premium Class Navigation")
            color: "white"
            font.pointSize: 25
            anchors {
                right: greetingImage.right
                rightMargin: 20
                bottom: greetingImage.bottom
                bottomMargin: 20
            }
        }

        Language{
            id: choosingLang
            width: 150
            anchors{
                right: greetingImage.right
                top: greetingImage.top
                topMargin: 20
                rightMargin: 80
            }
        }

        ListItem{
            id: sublist
            height: root.height
            width: parent.width * 2 / 5
            anchors.right: parent.right
        }

        Image{
            id: popUpImage
            width: height = choosingLang.height + 10
            source: "qrc:/image/menu.png"
            anchors.left: choosingLang.right
            anchors.leftMargin: 30
            anchors.top: greetingImage.top
            anchors.topMargin: 15
            MouseArea{
                id: mouseArea
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {
                    mouseArea.cursorShape = Qt.PointingHandCursor
                }
                onExited: {
                    mouseArea.cursorShape = Qt.ArrowCursor
                }
                onClicked: {
                    sublist.open()
                }
            }
        }

        GridView {
            id: grid
            width: parent.width - 200
            height: 600
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            cellWidth: parent.width > 500 ? grid.width / 5 : grid.width / 3
            cellHeight: parent.width > 500 ? grid.height / 3 : grid.height / 4
            interactive: false
            model: HomeModel
            delegate: Item{
                width: grid.cellWidth
                height: grid.cellHeight
                HomeItem{
                    width: parent.width - 10
                    height: parent.height - 10
                    anchors.centerIn: parent
                    sourceImage: "file://"
                                 + theNormal
                    sourceImageHover: "file://"
                                      + theHorvered
                    textShow: HomeModel.getData(theName) + Translation.empty
                }
            }
        }

        ScrollBar.vertical: ScrollBar {
            policy: ScrollBar.AlwaysOn
        }
    }







}
