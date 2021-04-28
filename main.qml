import QtQuick.Controls 2.0
import DatabaseController 1.0

import "pages"

ApplicationWindow {
    id: page
    title: qsTr("Master Library")
    width: 700
    height: 480
    visible: true

    DatabaseController{
        id: global_database_controller
    }

    StackView{
        id: pageRoute
        initialItem: ListPage{id: home}
        anchors.fill: parent
    }
}
