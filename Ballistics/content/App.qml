import Ballistics
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    title: "Ballistics Calculator"
    width: 800
    height: 600
    visible: true

    ColumnLayout {
        anchors.fill: parent
        spacing: 10

        // Ballistic Coefficient
        TextField {
            id: bcField
            placeholderText: "Ballistic Coefficient"
            Layout.fillWidth: true
        }

        // Initial Velocity
        TextField {
            id: velocityField
            placeholderText: "Initial Velocity (ft/s)"
            Layout.fillWidth: true
        }

        // Sight Height
        TextField {
            id: sightHeightField
            placeholderText: "Sight Height (inches)"
            Layout.fillWidth: true
        }

        // Shooting Angle
        TextField {
            id: angleField
            placeholderText: "Shooting Angle (degrees)"
            Layout.fillWidth: true
        }

        // Zero Range
        TextField {
            id: zeroRangeField
            placeholderText: "Zero Range (yards)"
            Layout.fillWidth: true
        }

        // Wind Speed
        TextField {
            id: windSpeedField
            placeholderText: "Wind Speed (mph)"
            Layout.fillWidth: true
        }

        // Wind Angle
        TextField {
            id: windAngleField
            placeholderText: "Wind Angle (degrees)"
            Layout.fillWidth: true
        }

        // Temperature
        TextField {
            id: tempField
            placeholderText: "Temperature (°F)"
            Layout.fillWidth: true
        }

        // Atmospheric Pressure
        TextField {
            id: pressureField
            placeholderText: "Atmospheric Pressure (inHg)"
            Layout.fillWidth: true
        }

        // Caliber
        TextField {
            id: caliberField
            placeholderText: "Caliber (inches)"
            Layout.fillWidth: true
        }

        // Bullet Weight
        TextField {
            id: bulletWeightField
            placeholderText: "Bullet Weight (grains)"
            Layout.fillWidth: true
        }

        // Bullet Length
        TextField {
            id: bulletLengthField
            placeholderText: "Bullet Length (inches)"
            Layout.fillWidth: true
        }

        // Twist Rate
        TextField {
            id: twistRateField
            placeholderText: "Twist Rate (1 in X inches)"
            Layout.fillWidth: true
        }

        // Calculate Button
        Button {
            id: calculateButton
            text: "Calculate"
            Layout.fillWidth: true
            // onClicked: { /* Add your logic here */ }
        }
    }
}
