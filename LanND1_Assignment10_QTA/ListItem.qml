import QtQuick 2.15
import QtQuick.Controls 2.15

Item{
    id: root
    signal open()
    onOpen: {
        popup.open()
    }

    Popup {
        id: popup
        width: parent.width
        height: parent.height
        modal: true
        padding: 1

        onClosed: {
            listFunction.close()
        }

        Rectangle{
            id: rightMenuBar
            width: parent.width
            height: 50
            anchors{
                top: parent.top
            }
            color: "transparent"

            Image {
                id: searchIcon
                source: "qrc:/image/search.png"
                width: height = rightMenuBar.height / 2
                anchors {
                    left: parent.left
                    leftMargin: 10
                    verticalCenter: parent.verticalCenter
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        console.log("Search icon pressed")
                    }
                }
            }

            Image{
                id: closeIcon
                source: "qrc:/image/menu_close.png"
                width: height = rightMenuBar.height / 2
                anchors {
                    right: parent.right
                    rightMargin: 10
                    verticalCenter: parent.verticalCenter
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        listFunction.close()
                        popup.close()
                    }
                }
            }

            Rectangle{
                width: parent.width
                height: 2
                color: "#666666"
                anchors.bottom: parent.bottom
            }
        }

        ListView{
            id: listFunction
            width: parent.width
            height: parent.height - rightMenuBar.height
            anchors.top: rightMenuBar.bottom
            clip: true
            model: HomeModel
            currentIndex: -1
            signal close()
            delegate: ItemFunc{
                id: childItem
                width: listFunction.width
                textShow: theName
                height: 60
                modelSub: theSubList
                Connections{
                    target: listFunction
                    function onClose() {
                        childItem.outChoosing()
                        // childItem.expanded = false
                    }
                }
                onCloseAll: {
                    listFunction.close()
                }
            }
        }
    }
}
