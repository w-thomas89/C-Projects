#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include "applicationdata.h"
#include <QSslSocket>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQuickView view;
    ApplicationData data;
    view.rootContext()->setContextProperty("applicationData", &data);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    view.setSource(url);
    view.show();

    return app.exec();
}


//#include <QCoreApplication>
//#include <QDebug>
//#include <QSslSocket> //To use QSslSocket Class
//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);
//    qDebug()<<QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
//    return a.exec();
//}
