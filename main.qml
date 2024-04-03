import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 300
    height: 300
    title: "Movie Night"
    color: "#f5f5f5"

    // Close button
    Button {
        text: "X"
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.topMargin: 5
        anchors.rightMargin: 5
        width: 20
        height: 40

        background: Rectangle {
            color: button.pressed ? "lightgray" : "transparent"
            radius: 20
        }

        onClicked: {
            close()
        }

        contentItem: Text {
            text: parent.text
            color: "black"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.fill: parent
            font: button.font
        }
    }

    Column {
        anchors.centerIn: parent
        width: parent.width
        spacing: 20

        // Title label
        Label {
            text: qsTr("Movie Night")
            font.pixelSize: 24
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // Input instructions label
        Label {
            text: qsTr("Enter any number")
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // Number input field
        TextField {
            id: numberInput
            width: parent.width * 0.8
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter

            cursorDelegate: Rectangle {
                color: "grey"
                width: 2
                visible: parent.cursorVisible
            }

            background: Rectangle {
                color: "white"
                border.width: 1
                border.color: numberInput.activeFocus ? "#0078d7" : "#cccccc"
                radius: 2
            }
        }

        // Order button
        Button {
            id: orderButton
            text: qsTr("Order now")
            width: parent.width * 0.5
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                let num = parseInt(numberInput.text);
                if (!isNaN(num)) {
                    fantasyMovies.selectMovie(num);
                } else {
                    movieOutput.text = "Please enter a valid number."
                }
            }
        }

        // Output label for movie selection
        Label {
            id: movieOutput
            width: parent.width * 0.8
            wrapMode: Text.WordWrap
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    // Connect to CFantasyMovies to update movieOutput label
    Connections {
        target: fantasyMovies
        onMovieSelected: function(movieTitle) {
            movieOutput.text = movieTitle
        }
    }
}
