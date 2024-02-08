#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QDebug"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_status(new QLabel),
      m_settings(new SettingDialog)
{
    ui->setupUi(this);
    initConnection();
}

void MainWindow::changeLayout(QString Lang)
{
    if(Lang=="English"){
        ui->centralwidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
    }
    else if(Lang=="Arabic"){
         ui->centralwidget->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

    }
    else
    {
         QMessageBox::about(this, tr("Choose Language"),
                            tr("You Should Choose Language ."));


         }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionExits_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionAbout_QT_triggered()
{
    QApplication::aboutQt();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("About Simple Refrigerator"),
                       tr("The <b>Simple Refrigerator</b> example demonstrates how to "
                          "use the Qt Serial Port module in modern GUI applications "
                          "using Qt, with a menu bar, toolbars, and a status bar."));
}


void MainWindow::initConnection()
{
    connect(ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
    connect(ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(ui->actionExits, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionSetting, &QAction::triggered, m_settings, &SettingDialog::showSettings);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(ui->actionAbout_QT, &QAction::triggered, qApp, &QApplication::aboutQt);
}

void MainWindow ::openSerialPort()
{

        const SettingDialog::Settings p = m_settings->settings();
        m_serial->setPortName(p.name);
        m_serial->setBaudRate(p.baudRate);
        m_serial->setDataBits(p.dataBits);
        m_serial->setParity(p.parity);
        m_serial->setStopBits(p.stopBits);
        m_serial->setFlowControl(p.flowControl);
        if (m_serial->open(QIODevice::ReadWrite)) {
            ui->actionConnect->setEnabled(false);
            ui->actionDisconnect->setEnabled(true);
            ui->actionSetting->setEnabled(false);
            ui->newpushButton_15->setEnabled(true);
           showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                              .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                              .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));

    } else {
            QMessageBox::critical(this, tr("Error"), m_serial->errorString());

            showStatusMessage(tr("Open error"));
            qDebug()<<"eror";

    }

}

void MainWindow::closeSerialPort()
{
    if (m_serial->isOpen())
        m_serial->close();
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionSetting->setEnabled(true);
    ui->newpushButton_15->setEnabled(false);
    showStatusMessage(tr("Disconnected"));
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Simple MonitorIndoor"),
                       tr("The <b>Simple MonitorIndoor</b> example demonstrates how to "
                          "use the Qt Serial Port module in modern GUI applications "
                          "using Qt, with a menu bar, toolbars, and a status bar."));
}

void MainWindow::writeData(const QByteArray &data)
{
    m_serial->write(data);
}

void MainWindow::readData()
{

    if(m_serial->canReadLine()){


        const QByteArray data = m_serial->readLine();
        qDebug()<<data<<endl;

        QString receivedData = QString::fromLatin1(data);
        QStringList values = receivedData.split(',');


         RefrigeratorStateMachine = values.at(0);
         RefrigeratorPreCoolingStateMachine  = values.at(1);
         RefrigeratorMode  = values.at(2);
         OverloadPullDownModeStatesOR  = values.at(3);
         OverTemperatureModeActions_OnStatesOR = values.at(3);
         Mode0 = values.at(3);
         CorrectedAmbientTemperature  = values.at(4);
         AmbientThermistorTemperature  = values.at(5);
         FreezerThermistorTemperature  = values.at(6);
         RefrigeratorThermistorTemperature  = values.at(7);
         DefrostThermistorTemperature  = values.at(8);
         CompressorState   = values.at(9);
         CompressorSetSpeed   = values.at(10);
         CompressorActualRunningSpeed   = values.at(11);
         CompressorStep  = values.at(12);
         StartingSpeedCondition  = values.at(13);
         CompressorCutonPoint   = values.at(14);
         CompressorCutOffPoint   = values.at(15);
         DamperState   = values.at(16);
         DamperCutOnPoint   = values.at(17);
         DamperCutOffPoint  = values.at(18);
         CompressorTimer   = values.at(19);
         CompressorOnTimein   = values.at(20);
         CompressorCycleAccumulativeOnTime   = values.at(21);
         CompressorAccumulativeOnTime  = values.at(22);
         CompressorPreviousDuty  = values.at(23);
         CompressorOldDuty   = values.at(24);
         RefrigeratorUserSelectionTemperature   = values.at(25);
         RefPreCoolingStateMachine  = values.at(26);
         FreezerUserSelectionTemperature   = values.at(27);
         HeaterState  = values.at(28);
         HeaterOnTime   = values.at(29);
         FreezerDoorState   = values.at(30);
         RefrigeratorDoorState   = values.at(31);
         FreezerDoorCummulativeOpenTime  = values.at(32);
         RefrigeratorDoorCummulativeOpenTime  = values.at(33);
         TimesOfRefrigeratorDoorOpen   = values.at(34);
         TimesOfFreezerDoorOpen   = values.at(35);
         FanTargetSpeed   = values.at(36);
         FanMeasuredSpeed   = values.at(37);
         FanSpeedError  = values.at(38);
         FanDACValue   = values.at(39);
         RefrigeratorDefrostFactor   = values.at(40);
         TimeToDefrostConditions   = values.at(41);

        // qDebug()<<strokeData(QString(data).trimmed());
       // parseData(strokeData(QString(data).trimmed()));
        //updateData();
    }
}

void MainWindow::parseData()
{
        m_Data->setRefrigeratorStateMachine(RefrigeratorStateMachine);

        m_Data->setRefrigeratorPreCoolingStateMachine(RefrigeratorPreCoolingStateMachine);

        m_Data->setRefrigeratorMode(RefrigeratorMode);

        m_Data->setOverloadPullDownModeStatesOR(OverloadPullDownModeStatesOR);

        m_Data->setOverTemperatureModeActionsOnStatesOR(OverTemperatureModeActions_OnStatesOR);

        m_Data->setMode0(Mode0);

        m_Data->setCorrectedAmbientTemperature(CorrectedAmbientTemperature);

        m_Data->setAmbientThermistorTemperature(AmbientThermistorTemperature);

        m_Data->setFreezerThermistorTemperature(FreezerThermistorTemperature);

        m_Data->setRefrigeratorThermistorTemperature(RefrigeratorThermistorTemperature);

        m_Data->setDefrostThermistorTemperature(DefrostThermistorTemperature);

        m_Data->setCompressorState(CompressorState);

        m_Data->setCompressorSetSpeed(CompressorSetSpeed);

        m_Data->setCompressorActualRunningSpeed(CompressorActualRunningSpeed);

        m_Data->setCompressorStep(CompressorStep);

        m_Data->setStartingSpeedCondition(StartingSpeedCondition);

        m_Data->setCompressorCutonPoint(CompressorCutonPoint);

        m_Data->setCompressorCutOffPoint(CompressorCutOffPoint);

        m_Data->setDamperState(DamperState);

        m_Data->setDamperCutonPoint (DamperCutOnPoint);

        m_Data->setDamperCutOffPoint (DamperCutOffPoint);

        m_Data->setCompressorTimer(CompressorTimer);

        m_Data->setCompressorOnTimein(CompressorOnTimein);

        m_Data->setCompressorCycleAccumulativeOnTime(CompressorCycleAccumulativeOnTime);

        m_Data->setCompressorAccumulativeOnTime(CompressorAccumulativeOnTime);

        m_Data->setCompressorPreviousDuty (CompressorPreviousDuty);

        m_Data->setCompressorOldDuty(CompressorOldDuty);

        m_Data->setRefrigeratorUserSelectionTemperature(RefrigeratorUserSelectionTemperature);

        m_Data->setRefrigeratorDoorCummulativeOpenTime(RefrigeratorUserSelectionTemperature);

        m_Data->setFreezerUserSelectionTemperature(FreezerUserSelectionTemperature);

        m_Data->setHeaterState(HeaterState);

        m_Data->setRefPreCoolingStateMachine(RefPreCoolingStateMachine);

        m_Data->setHeaterOnTime(HeaterOnTime);

        m_Data->setFreezerDoorState(FreezerDoorState);

        m_Data->setRefrigeratorDoorState(RefrigeratorDoorState);

        m_Data->setFreezerDoorCummulativeOpenTime (FreezerDoorCummulativeOpenTime);

        m_Data->setRefrigeratorDoorCummulativeOpenTime(RefrigeratorDoorCummulativeOpenTime);

        m_Data->setTimesOfRefrigeratorDoorOpen(TimesOfRefrigeratorDoorOpen);

        m_Data->setTimesOfFreezerDoorOpen (TimesOfFreezerDoorOpen);

        m_Data->setFanTargetSpeed(FanTargetSpeed);

        m_Data->setFanMeasuredSpeed(FanMeasuredSpeed);

        m_Data->setFanSpeedError (FanSpeedError);

        m_Data->setFanDACValue(FanDACValue);

        m_Data->setRefrigeratorDefrostFactor(RefrigeratorDefrostFactor);

        m_Data->setTimeToDefrostConditions (TimeToDefrostConditions);

}

void MainWindow::showStatusMessage(const QString &message)
{
    m_status->setText(message);
}
