#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTranslator>
#include <QLocale>
#include <QDir>
const int N = 300;
const QString PathForTranslations = "./";


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSettings *LocalSettings = new QSettings(QString("%1%2").arg(QDir::homePath(), "/.WiFiHostapdAP/WiFi_Hostapd_AP.conf"), QSettings::NativeFormat);
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForCStrings(codec);
    QString bb = QApplication::applicationFilePath();
    QStringList argument = QCoreApplication::arguments();
    QString com;
    char command[N];
    char *tmp1;
    char buf[BUFSIZ];


	FILE *ptr;
    int test=0;
    if ((ptr = popen("id | grep uid=0", "r")) != NULL) 
		while (fgets(buf, BUFSIZ, ptr) != NULL) test++;
			pclose(ptr);


  if(test==0) {
        qDebug() << "USER: get ROOT ... ";
        if(LocalSettings->value("Programm/suCommand", true).toBool() || argument.last() == "-su") {
            LocalSettings->setValue("Programm/suCommand", false);
            GetRoot ppp; ppp.exec(); }
            
        com.clear();
        com = LocalSettings->value("Programm/rootCommand", "gksu ").toString();

        qDebug() << "Get root with " << com << ".";

        com.toLocal8Bit();
        tmp1 = com.toAscii().data();
        strcpy(command, tmp1);
        strcpy(tmp1, "");

        bb.toLocal8Bit();
        tmp1 = bb.toAscii().data();
        strcat(command, tmp1);
        bb.clear();

        system(command);
        a.exit();
    } else {
QSettings *GlobalSettings = new QSettings("/root/.WiFiHostapdAP/WiFi_Hostapd_AP.conf",QSettings::NativeFormat);
qDebug() << "ROOT: ok. Begin ... ";
// НАстройки перевода:
int Translate = GlobalSettings->value("Programm/Language", 0).toInt(); // 0 - автоматически 1 - английский 2 - русский
QString Trans;
if(Translate==0) Trans = "app_" + QLocale::system().name();
else if(Translate==1) Trans = "app_en";
else if(Translate==2) Trans = "app_ru";
else Trans = "app_en";

// Устанавливаем перевод
        QTranslator appTranslator;
        appTranslator.load(QString("%1%2").arg(PathForTranslations, Trans), qApp->applicationDirPath());
        a.installTranslator(&appTranslator);
        GlobalSettings->setValue("Programm/suCommand", false);

        MainWindow w;
        w.show();
delete GlobalSettings;
delete LocalSettings;
    return a.exec();
    }
}

