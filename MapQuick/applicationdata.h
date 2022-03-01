#ifndef APPLICATION_DATA_H
#define APPLICATION_DATA_H

#include <QObject>
#include <QGeoCoordinate>
class ApplicationData: public QObject {
    Q_OBJECT
public:
public slots:
    QGeoCoordinate getCoordinates(QString name) {
        QGeoCoordinate coordinate;
        if (name == "London") {
            coordinate.setLatitude(51.5074);
            coordinate.setLongitude(0.1278);
        } else if (name == "Shanghai") {
            coordinate.setLatitude(31.2304);
            coordinate.setLongitude(121.4737);
        } else if (name == "Lagos") {
            coordinate.setLatitude(6.5244);
            coordinate.setLongitude(3.3792);
        } else if (name == "New York") {
            coordinate.setLatitude(40.7128);
            coordinate.setLongitude(-74.0060);
        }
        return coordinate;
    }
    //overloaded the function to work with specific input
    QGeoCoordinate setCoordinates(QString lat, QString lon) {
        float latitude = lat.toFloat();
        float longitude = lon.toFloat();
        QGeoCoordinate coordinate;
        coordinate.setLatitude(latitude);
        coordinate.setLongitude(longitude);
        return coordinate;
    }
};

#endif // APPLICATION_DATA_H
