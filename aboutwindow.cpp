#include "aboutwindow.h"
#include "ui_aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutWindow)
{
    QSettings *GlobalSettings = new QSettings("/root/.WiFiHostapdAP/WiFi_Hostapd_AP.conf",QSettings::NativeFormat);
    int Translate = GlobalSettings->value("Programm/Language", 0).toInt(); // 0 - автоматически 1 - английский 2 - русский
   QUrl Trans;

   ui->setupUi(this);
   ui->version->setText(tr("Version of programm: ") + GlobalSettings->value("Programm/version", "1.0").toString());

   if(Translate==0) Trans = "file:///usr/share/wifi-hostapd-ap/translations/about_" + QLocale::system().name() + ".html";
   else if(Translate==1) Trans =  "file:///usr/share/wifi-hostapd-ap/translations/about_en.html";
   else if(Translate==2) Trans = "file:///usr/share/wifi-hostapd-ap/translations/about_ru.html";
   else Trans = "file:///usr/share/wifi-hostapd-ap/translations/about_en.html";

if(Trans.isValid())
    ui->AboutView->setSource(Trans);
else
    ui->AboutView->setSource(QUrl( "file:///usr/share/wifi-hostapd-ap/translations/about_en.html"));

    delete GlobalSettings;
}

AboutWindow::~AboutWindow()
{
    delete ui;
}
