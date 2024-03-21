#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include "settingdialog.h"
#include"data.h"

QT_BEGIN_NAMESPACE

class QLabel;

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void changeLayout(QString Lang);
    ~MainWindow();

private slots:
    void on_actionExits_triggered();

    void on_actionAbout_QT_triggered();

    void on_actionAbout_triggered();


    void initConnection();

    void openSerialPort();
    void closeSerialPort();
    void about();
    void writeData(const QByteArray &data);
    void readData();
    QVector<QString>  strokeData(QString Data);
    void parseData();
    void updateData();



    void showStatusMessage(const QString &message);

    void on_newpushButton_15_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QString> LastFrame;
    QLabel *m_status = nullptr;
    SettingDialog *m_settings = nullptr;
    QSerialPort *m_serial = nullptr;
    Data *m_Data;



    QString RefrigeratorStateMachine=NULL;

    QString RefrigeratorPreCoolingStateMachine=NULL;

    QString RefrigeratorMode=NULL;

    QString OverloadPullDownModeStatesOR=NULL;

    QString OverTemperatureModeActions_OnStatesOR=NULL;

    QString Mode0=NULL;

    QString CorrectedAmbientTemperature=NULL;

    QString AmbientThermistorTemperature=NULL;

    QString FreezerThermistorTemperature=NULL;

    QString RefrigeratorThermistorTemperature=NULL;

    QString DefrostThermistorTemperature=NULL;

    QString CompressorState=NULL;

    QString CompressorSetSpeed=NULL;

    QString CompressorActualRunningSpeed=NULL;

    QString CompressorStep=NULL;

    QString StartingSpeedCondition=NULL;

    QString CompressorCutonPoint=NULL;

    QString CompressorCutOffPoint=NULL;

    QString DamperState=NULL;

    QString DamperCutOnPoint =NULL;

    QString DamperCutOffPoint =NULL;

    QString CompressorTimer=NULL;

    QString CompressorOnTimein=NULL;

    QString CompressorCycleAccumulativeOnTime=NULL;

    QString CompressorAccumulativeOnTime=NULL;

    QString CompressorPreviousDuty=NULL;

    QString CompressorOldDuty=NULL;

    QString RefrigeratorUserSelectionTemperature=NULL;

    QString RefPreCoolingStateMachine=NULL;

    QString FreezerUserSelectionTemperature=NULL;

    QString HeaterState=NULL;

    QString HeaterOnTime=NULL;

    QString FreezerDoorState=NULL;

    QString RefrigeratorDoorState=NULL;

    QString FreezerDoorCummulativeOpenTime=NULL;

    QString RefrigeratorDoorCummulativeOpenTime=NULL;

    QString TimesOfRefrigeratorDoorOpen=NULL;

    QString TimesOfFreezerDoorOpen=NULL;

    QString FanTargetSpeed=NULL;

    QString FanMeasuredSpeed=NULL;

    QString FanSpeedError=NULL;

    QString FanDACValue=NULL;

    QString RefrigeratorDefrostFactor=NULL;

    QString TimeToDefrostConditions=NULL;




};
#endif // MAINWINDOW_H
