import QtQuick 2.15

Item{
    id: root
    property int currentIndex: -1
    height: languageImage.height

    property url imageNormal: "qrc:/image/lang.png"
    property url imagePressed: "qrc:/image/lang_active.png"
    signal closeLang();

    onCloseLang: {
        if(dynamicLoader.sourceComponent !== null){
            languageImage.source = root.imageNormal
            dynamicLoader.sourceComponent = null
        }
    }

    Image{
        id: languageImage
        width: parent.width
        source: root.imageNormal
        fillMode: Image.PreserveAspectFit
    }

    Loader{
        id: dynamicLoader
        anchors.top: languageImage.bottom
        anchors.topMargin: 3
        anchors.left: parent.left
    }

    Component{
        id: listLanguage
        ListView{
            id: listView
            width: languageImage.width * 2 / 3
            height: listView.count * 20
            model: ["ENGLISH", "FRANCE", "ESPAÑOL", "한국어"]
            currentIndex: root.currentIndex
            delegate: Rectangle{
                width: parent.width
                height: 20
                clip: true
                color: listView.currentIndex === index ? "#05141f" : "white"
                Text {
                    id: textLanguage
                    text: modelData
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    font.pointSize: 10
                    color: listView.currentIndex === index ? "white" : "#05141f"
                    elide: Text.ElideRight
                }

                MouseArea{
                    id: chooseLang
                    anchors.fill: parent
                    onClicked: {
                        listView.currentIndex = index
                        Translation.currentLanguage = index
                        root.currentIndex = index
                        closeLang();
                    }
                    hoverEnabled: true
                    onEntered: {
                        chooseLang.cursorShape = Qt.PointingHandCursor
                    }
                    onExited: {
                        chooseLang.cursorShape = Qt.ArrowCursor
                    }
                }
            }
        }
    }

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
            languageImage.source = root.imagePressed
            if(dynamicLoader.sourceComponent == null){
                dynamicLoader.sourceComponent = listLanguage
            }
            else{
                closeLang();
            }
        }
    }
}
