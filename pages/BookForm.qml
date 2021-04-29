import QtQuick 2.0
import QtQuick.Controls 2.15

import "utilities"

Rectangle {
    id: page

    property string action: "save"
    property var databaseInstance: global_database_controller

    property string isbn: ""
    property string name: ""
    property string author: ""
    property string category_description: ""

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
                text: page.isbn
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
                text: page.name
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
                text: page.author
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

            Component.onCompleted: {
                if(category_description != "")
                    category.currentIndex = category.find(category_description)
            }
        }
    }

    Dialog {
        id: dialog
        anchors.centerIn: parent.Center
        title: ""
        modal: true

        closePolicy: Popup.NoAutoClose

        onOpened: dialog_timer.running = true
        property bool pop: false
        Timer{
            id: dialog_timer
            interval: 3000
            onTriggered: {
                dialog.close()
                if(dialog.pop) pageRoute.pop()
            }
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
            if(isbn.text != "" && name.text != "" && author.text!= "")
                if(action === "save")
                    if(databaseInstance.saveBook(isbn.text,name.text,author.text,category.currentText)){
                        dialog.title = "Livro salvo com sucesso"
                        dialog.pop = true
                    }else
                        dialog.title = "Ocorreu um erro ao tentar salvar o livro"
                else
                    if(databaseInstance.updateBook(isbn.text,name.text,author.text,category.currentText)){
                        dialog.title = "Livro editado com sucesso"
                        dialog.pop = true
                    }else
                        dialog.title = "Ocorreu um erro ao tentar editar o livro"
            else
                dialog.title = "preencha todos os campos"
            dialog.open()
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
