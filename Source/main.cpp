#include "mainwindow.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QInputDialog>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStringList Languages;
    QTranslator Trans;
    Languages<<"English"<<"Arabic";
    QString Lang=QInputDialog::getItem(NULL,"Select Language","Language",Languages);
    if(Lang=="English"){
        Trans.load(":/English.qm");
        a.installTranslator(&Trans);
    }
    else if(Lang=="Arabic"){
        Trans.load(":/arabic.qm");
        a.installTranslator(&Trans);


    }

    MainWindow w;
    w.changeLayout(Lang);
    w.showMaximized();

    return a.exec();
}
