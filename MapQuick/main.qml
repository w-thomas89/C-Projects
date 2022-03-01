import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtLocation 5.6
import QtPositioning 5.6


Item {
    visible: true
    width: 640
    height: 480

    Map {
        id: map
        x: 0
        y: 0
        width: 480
        height: 480
        plugin: mapPlugin

        center: QtPositioning.coordinate(59.91, 10.75) // Oslo
        zoomLevel: 14

        onZoomLevelChanged: {
            inZoomLevel.text = zoomLevel
        }
    }

    Plugin {
        id: mapPlugin
        name: "osm"
    }
    Text {
        id: text3
        x: 488
        y: 38
        width: 144
        height: 14
        text: qsTr("City Search")
        font.pixelSize: 11
        horizontalAlignment: Text.AlignHCenter
    }
    //text field to input from user for search against applicationdata()
    TextField {
        id: inCitySearch
        x: 487
        y: 55
        width: 145
        height: 40
        text: qsTr("")
        horizontalAlignment: Text.AlignHCenter
        placeholderText: "City Name"
    }
    Text {
        id: text4
        x: 488
        y: 97
        width: 144
        height: 14
        text: qsTr("Zoom Amount (1-30)")
        font.pixelSize: 11
        horizontalAlignment: Text.AlignHCenter
    }
    //text field that issues the zoom level upon button press
    TextField {
        id: inZoomLevel
        x: 487
        y: 116
        width: 145
        height: 40
        text: qsTr("")
        horizontalAlignment: Text.AlignHCenter
        placeholderText: "Zoom Level"
    }
    //button that calls for changes to map center and zoom level based on input textField data
    Button {
        id: inCityZoom
        x: 511
        y: 161
        text: qsTr("Update")
        onClicked: {
            map.center = applicationData.getCoordinates(inCitySearch.text)
            map.zoomLevel = parseFloat(inZoomLevel.text)
        }
    }
    Text {
        id: text1
        x: 488
        y: 321
        width: 144
        height: 14
        text: qsTr("Latitude")
        font.pixelSize: 11
        horizontalAlignment: Text.AlignHCenter
    }
    //input latitude coordinates - will accept as a float
    TextField {
        id: inLat
        x: 487
        y: 337
        width: 146
        height: 40
        text: qsTr("")
        horizontalAlignment: Text.AlignHCenter
        placeholderTextColor: "#7f353637"
        placeholderText: "Lat Coords"
    }
    Text {
        id: text2
        x: 488
        y: 377
        width: 144
        height: 14
        text: qsTr("Longitude")
        font.pixelSize: 10
        horizontalAlignment: Text.AlignHCenter
    }
    //input longitude coordinates - will accept as a float
    TextField {
        id: inLong
        x: 487
        y: 392
        width: 146
        height: 40
        text: qsTr("")
        horizontalAlignment: Text.AlignHCenter
        placeholderText: "Long Coords"
        placeholderTextColor: "#7f353637"
    }
    //update map.center based on input lat/long coordinates
    Button {
        id: updateInputValues
        x: 511
        y: 436
        text: qsTr("Update")

        onClicked: {
            map.center = applicationData.setCoordinates(inLat, inLong)
        }
    }
}
