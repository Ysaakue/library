import QtQuick 2.12
import QtQuick.Layouts 1.12

ColumnLayout {
    id: root
    z: 1

    property alias imageSource: image.source
    property alias image: image
    property bool fillImage: false

    property alias label: textWidget.text
    property alias innerText: containerText.text
    property alias innerTextColor: containerText.color
    property alias font: textWidget.font

    property alias border: container.border
    property alias radius: container.radius
    property alias color: container.color

    property alias rectangle: container
    property alias buttonWidth: container.width
    property alias buttonHeight: container.height
    property int buttonWidthOffset: 0
    property int buttonHeightOffset: 0

    property alias button: button
    property alias innerTextItem: containerText

    property bool has_border: false

    signal pressed
    signal clicked

    Rectangle {
        id: container

        visible: (image.source) ? true : false
        color: "transparent"
        border.width: 2.2
        radius: 6
        border.color: root.has_border? "333" : "transparent"
        Layout.alignment: Qt.AlignHCenter
        width: childrenRect.width + buttonWidthOffset
        height: childrenRect.height + buttonHeightOffset

        Image {
            id: image
            anchors.centerIn: container
        }

        Text {
            id: containerText
            color: "white"
            font.pointSize: 10
        }
    }

    Text {
        id: textWidget
        visible: textWidget.text ? true : false
        color: "white"
        font.pointSize: 11.5
        horizontalAlignment: Text.AlignHCenter
        Layout.alignment: Qt.AlignHCenter
    }

    Rectangle {
        id: highlightRectangle
        color: button.pressed ? Qt.rgba(25, 25, 25, 0.25) : "transparent"
        width: parent.width; height: parent.height
        radius: container.radius

        MouseArea {
            id: button
            anchors.fill: parent
            onPressed: root.pressed()
            onClicked: root.clicked()
        }
    }
}
