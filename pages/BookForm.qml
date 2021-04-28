import QtQuick 2.0
import QtQuick.Controls 1.4

import "utilities"

Rectangle {
    property var databaseInstance: global_database_controller

    Background{id:background}

    Grid{
        id: grid
        anchors.top: parent.top
        anchors.topMargin: 15
        anchors.right: parent.right
        anchors.rightMargin: 15
        anchors.left: parent.left
        anchors.leftMargin: 15
        columns: 2
        spacing: 5
        height: 150

        Text{
            text: "ISBN: "
            height: 25
        }
        Rectangle{
            color: "white"
            width: 300
            height: 25
            z: 1
            TextInput{
                id: isbn
                width: parent.width
                height: 22
                anchors.left: parent.left
                anchors.leftMargin: 5
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Text{
            text: "Nome: "
            height: 25
        }
        Rectangle{
            color: "white"
            width: 300
            height: 25
            TextInput{
                id: name
                width: parent.width
                anchors.left: parent.left
                anchors.leftMargin: 5
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Text{
            text: "Autor: "
            height: 25
        }
        Rectangle{
            color: "white"
            width: 300
            height: 25
            TextInput{
                id: author
                width: parent.width
                anchors.left: parent.left
                anchors.leftMargin: 5
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Text{
            text: "Categoria: "
            height: 25
        }
        ComboBox {
            id: category
            width: 300
            height: 25
            model: databaseInstance.getAllCategoriesDescriptions()
        }
    }

    Button{
        id: save
        anchors.top: grid.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 15
        text: "Salvar"
        onClicked: {
            if(databaseInstance.saveBook(isbn.text,name.text,author.text,category.currentText)){
                console.log("ok")
            } else {
                console.log("fail")
            }
        }
    }

    Button{
        anchors.top: grid.bottom
        anchors.topMargin: 5
        anchors.left: save.right
        anchors.leftMargin: 5
        text: "Cancelar"
        onClicked: pageRoute.pop()
    }
}
