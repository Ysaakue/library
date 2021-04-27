import QtQuick 2.15
import QtQuick.Controls 2.0
import QtQuick.Window 2.15
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12
import DatabaseController 1.0

import "utilities"

Rectangle {
    property string current_model: "book"

    function getName(modelData){
        if(current_model == "book" && modelData["name"])
            return modelData["name"];
        else if(current_model == "category" && modelData["description"])
            return modelData["description"];
        return "";
    }

    DatabaseController{
        id: global_database_controller
    }

    Background{id: background}

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
            text: "search"
            height: 25
            width: 25
            onClicked: console.log(search_text.text)
            Image{
                z:1
                anchors.fill: parent
                source: "qrc:/pages/images/search_black_24dp.svg"
            }
        }

        Button{
            text: current_model == "book"? "Adicionar Livro" : "Adicionar Categoria"
            font.pointSize: 14
            height: 25
            onClicked: {
                if(current_model == "book"){
                    //
                }
                else{

                }
            }
        }

        Button{
            text: current_model == "book"? "Lista de Categorias" : "Lista de Livros"
            font.pointSize: 14
            height: 25
            onClicked: {
                if(current_model == "book"){
                    current_model = "category"
                    list.model = global_database_controller.getAllCategories()
                }
                else{
                    current_model = "book"
                    list.model = global_database_controller.getAllBooks()
                }
            }
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
        model: global_database_controller.getAllBooks()
        interactive: true
        clip: true
        delegate: Rectangle{
            height: 30
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            color: "white"

            Text{
                text: getName(modelData)
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
