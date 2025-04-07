import QtQuick 2.15

Rectangle {
    id: root
    // width: 200
    // height: 150
    color: "#3C3D37"
    clip: true

    property string sourceImage
    property string sourceImageHover
    property string textShow
    property string colorHover: "black"
    property string colorNormal: "white"
    // signal comeHere();

    Image{
        id: iconShow
        width: root.width / 3
        height: width
        source: root.sourceImage
        fillMode: Image.PreserveAspectFit
        anchors.bottom: root.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }
    Text{
        id: textDisplay
        text: root.textShow
        font.pointSize: 10
        elide: Text.ElideRight
        color: root.colorNormal
        anchors.top: parent.verticalCenter
        anchors.topMargin: 5
        anchors.horizontalCenter: parent.horizontalCenter
    }

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            console.log("Click to %1 button".arg(root.textShow))
            // comeHere();
        }
        onEntered: {
            iconShow.source = root.sourceImageHover
            root.color = "#E9EFEC"
            textDisplay.color = colorHover
        }
        onExited: {
            iconShow.source = root.sourceImage
            root.color = "#3C3D37"
            textDisplay.color = colorNormal
        }
    }
}
