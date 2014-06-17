import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1

Rectangle {
    width: 300
    height: 300

    ListView {
        id: alertList
        width: 300
        height: 300
        anchors.rightMargin: 0
        anchors.bottomMargin: 0

        model: alerts

        delegate: Item {
            x: 5
            height: 25
            width: parent.width

            Text {
                text: name
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }

            Text {
                text: description
                font.italic: true
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }

            Switch {
                checked: active
                anchors.right: parent.right
                anchors.rightMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                onCheckedChanged: {
                    if (active != checked)
                        active = checked;
                }
            }
        }
    }
}
