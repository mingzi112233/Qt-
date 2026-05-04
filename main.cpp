#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    QFile qss(":/style/stylesheet.qss");
    if(qss.open(QFile::ReadOnly))
    {
        qDebug()<<"open success";
        QString style = QLatin1String(qss.readAll());

        w.setStyleSheet(style);
        qss.close();
    }
    else
    {
        qDebug()<<"qss open failed";
    }

    w.show();
    return a.exec();
}

