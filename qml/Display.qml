import QtQuick
import QtQuick.Shapes

Rectangle {
    anchors.fill: parent
    color: "#222"
    Shape {
        anchors.centerIn: parent
        width: 200; height: 200
        ShapePath {
            strokeColor: "yellow"
            strokeWidth: 4
            fillColor: "#44aaff"
            startX: 20; startY: 20
            PathLine { x: 180; y: 20 }
            PathLine { x: 180; y: 180 }
            PathLine { x: 20; y: 180 }
            PathLine { x: 20; y: 20 }
        }
        ShapePath {
            strokeColor: "red"
            strokeWidth: 3
            fillColor: "transparent"
            startX: 100; startY: 40
            PathArc { x: 100; y: 160; radiusX: 60; radiusY: 60 }
        }
    }
}
