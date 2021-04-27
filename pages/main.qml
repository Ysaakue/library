import QtQuick 2.15
import QtQuick.Controls 2.0
import QtQuick.Window 2.15
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

import "utilities"

ApplicationWindow {
    id: page
    width: 700
    height: 480
    visible: true
    title: qsTr("Master Library")

    Rectangle {
        id: background
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0; color: "#929292" }
            GradientStop { position: 1; color: "#151515" }
        }
    }

    Grid{
        id: search_box
        anchors.top: parent.top
        anchors.topMargin: 5
        layoutDirection: "LeftToRight"
        spacing: 5
        anchors.horizontalCenter: parent.horizontalCenter

        Rectangle{
            id: text_box
            width: 300
            height: 25
            TextInput{
                id: search_text
                anchors.fill: parent
                anchors.verticalCenter: parent.verticalCenter
                color: "black"
                font.pointSize: 14
            }
        }

        Button{
            text: "teste1"
            height: search_text.height
            width: 25
            onClicked: console.log(search_text.text)
        }

        Button{
            text: "adicionar categoria"
            font.pointSize: 14
            height: 25
        }

        Button{
            text: "adicionar livro"
            font.pointSize: 14
            height: 25
        }
    }

    ListView{
        id: list
        anchors.top: search_box.bottom
        anchors.topMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        width: search_box.width
        anchors.horizontalCenter: parent.horizontalCenter
        model: ["Harry Porter","Percy Jackson","Guia Suno Dividendos"]
        interactive: true
        delegate: Rectangle{
            height: 30
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            color: "white"

            Text{
                text: modelData
                color: "black"
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 5
            }
            Divider{
                width: parent.width
            }
            MyButton {
                id: edit_
                anchors.right: delete_.left
                anchors.rightMargin: 2.5
                buttonWidth: 24; buttonHeight: 24
                anchors.verticalCenter: parent.verticalCenter
                imageSource: "qrc:/pages/images/edit_black_24dp.svg"
            }
            MyButton {
                id: delete_
                anchors.right: parent.right
                anchors.rightMargin: 5
                buttonWidth: 24; buttonHeight: 24
                anchors.verticalCenter: parent.verticalCenter
                imageSource: "qrc:/pages/images/delete_black_24dp.svg"
            }
        }
    }
}
