#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QDebug"
#include<QMessageBox>
#include <QDateTime>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_status(new QLabel),
      m_settings(new SettingDialog),
      m_serial(new QSerialPort(this)),
      m_Data(new Data)
{
    ui->setupUi(this);

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionExits->setEnabled(true);
    ui->actionConfigure->setEnabled(true);
    initConnection();

    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);

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
    connect(ui->actionConfigure, &QAction::triggered, m_settings, &SettingDialog::showSettings);
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
            qDebug()<<"Read";
            ui->actionConnect->setEnabled(false);
            ui->actionDisconnect->setEnabled(true);
            ui->actionConfigure->setEnabled(false);
            ui->newpushButton_15->setEnabled(true);

    } else {

            qDebug()<<"eror";


}
}

void MainWindow::closeSerialPort()
{
    if (m_serial->isOpen())
        m_serial->close();
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
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

         qDebug()<<m_Data->DamperState;
         parseData();
         updateData();
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


void MainWindow::updateData()
{
    if(m_Data->RefrigeratorStateMachine!=NULL) ui->eRefStateMachine->setText(m_Data->RefrigeratorStateMachine);

    if(m_Data->RefrigeratorPreCoolingStateMachine !=NULL) ui->eRefPreCooling->setText(m_Data->RefrigeratorPreCoolingStateMachine);

    if(m_Data->RefrigeratorMode !=NULL) ui->eRefMod->setText(m_Data->RefrigeratorMode );

    if(m_Data->OverloadPullDownModeStatesOR !=NULL) ui->eOverloadPullDownMode->setText(m_Data->OverloadPullDownModeStatesOR);

    if(m_Data->OverTemperatureModeActions_OnStatesOR !=NULL) ui->eOverTempMode->setText(m_Data->OverTemperatureModeActions_OnStatesOR );

    if(m_Data->Mode0!=NULL) ui->eMode0->setText(m_Data->Mode0);

    if(m_Data->CorrectedAmbientTemperature!=NULL) ui->eCorrectedAmbientTemp->setText(m_Data->CorrectedAmbientTemperature);

    if(m_Data->AmbientThermistorTemperature!=NULL) ui->eAmbientThermistorTemp->setText(m_Data->AmbientThermistorTemperature);

    if(m_Data->FreezerThermistorTemperature!=NULL) ui->eFreezerThermistorTemp->setText(m_Data->FreezerThermistorTemperature);

    if(m_Data->RefrigeratorThermistorTemperature!=NULL) ui->eRefThermistorTemp->setText(m_Data->RefrigeratorThermistorTemperature);

    if(m_Data->DefrostThermistorTemperature!=NULL) ui->eDefrostThermistorTemp->setText(m_Data->DefrostThermistorTemperature);

    if(m_Data->CompressorState!=NULL) ui->etComState->setText(m_Data->CompressorState);

    if(m_Data->CompressorSetSpeed!=NULL)ui->eComSpeedSetVal->setText(m_Data->CompressorState);

    if(m_Data->CompressorActualRunningSpeed!=NULL)ui->eCompressorActualRunningSpeed->setText(m_Data->CompressorActualRunningSpeed);

    if(m_Data->CompressorStep!=NULL)        ui->eComStep->setText(m_Data->CompressorStep);

    if(m_Data->StartingSpeedCondition!=NULL)ui->eStartingSpeedCondition->setText(m_Data->StartingSpeedCondition);

    if(m_Data->CompressorCutonPoint!=NULL)  ui->eComCutOnPoint->setText(m_Data->CompressorCutonPoint);

    if(m_Data->CompressorCutOffPoint!=NULL) ui->eComCutOffPoint->setText(m_Data->CompressorCutOffPoint);

    if(m_Data->DamperState!=NULL)           ui->eDamperState->setText(m_Data->DamperState);

    if(m_Data->DamperCutOnPoint!=NULL)      ui->eDamperCutOnPoint->setText(m_Data->DamperCutOnPoint);

    if(m_Data->DamperCutOffPoint!=NULL)     ui->eDamperCutOffPoint->setText(m_Data->DamperCutOffPoint);

    if(m_Data->RefrigeratorUserSelectionTemperature!=NULL)       ui->eRefrigeratorUserSelectionTemp->setText(m_Data->RefrigeratorUserSelectionTemperature);

    if(m_Data->FreezerUserSelectionTemperature!=NULL)            ui->eFreezerrUserSelectionTemp->setText(m_Data->FreezerUserSelectionTemperature);

    if(m_Data->HeaterState!=NULL)            ui->eHeaterState->setText(m_Data->HeaterState);

    if(m_Data->HeaterOnTime!=NULL)            ui->eHeaterOnTime->setText(m_Data->HeaterOnTime);

    if(m_Data->FreezerDoorState!=NULL)            ui->elFreezerDoorState->setText(m_Data->FreezerDoorState);

    if(m_Data->RefrigeratorDoorState!=NULL)            ui->eRefrigeratorDoorState->setText(m_Data->RefrigeratorDoorState);

    if(m_Data->FreezerDoorCummulativeOpenTime!=NULL)            ui->eFreezerDoorCommulativeOpenTime->setText(m_Data->FreezerDoorCummulativeOpenTime);

    if(m_Data->RefrigeratorDoorCummulativeOpenTime!=NULL)            ui->eRefigeratorDoorCommulativeOpenTime->setText(m_Data->RefrigeratorDoorCummulativeOpenTime);

    if(m_Data->TimesOfFreezerDoorOpen!=NULL)            ui->eTimesOfFreezerDoorOpen->setText(m_Data->TimesOfFreezerDoorOpen);

    if(m_Data->TimesOfRefrigeratorDoorOpen!=NULL)            ui->eTimesOfRefDoorOpen->setText(m_Data->TimesOfRefrigeratorDoorOpen);

    if(m_Data->FanTargetSpeed!=NULL)            ui->eFanTargetSpeed->setText(m_Data->FanTargetSpeed);

    if(m_Data->FanMeasuredSpeed!=NULL)            ui->eFanMeasuredSpeed->setText(m_Data->FanMeasuredSpeed);

    if(m_Data->FanSpeedError!=NULL)            ui->eFanSpeedError->setText(m_Data->FanSpeedError);

    if(m_Data->FanDACValue!=NULL)            ui->eFanDACValue->setText(m_Data->FanDACValue);

    if (m_Data->CompressorTimer!=NULL) ui->eComTimerInMin->setText(m_Data->CompressorTimer);

    if (m_Data->CompressorOnTimein!=NULL) ui->eComOnTimeInMin->setText(m_Data->CompressorOnTimein);

    if (m_Data->CompressorPreviousDuty!=NULL) ui->eComPreviousDuty->setText(m_Data->CompressorPreviousDuty);

    if (m_Data->CompressorOldDuty!=NULL) ui->eComOldDuty->setText(m_Data->CompressorOldDuty);

    if (m_Data->CompressorCycleAccumulativeOnTime!=NULL) ui->eComCycleAccuOnTime->setText(m_Data->CompressorCycleAccumulativeOnTime);

    if (m_Data->CompressorAccumulativeOnTime!=NULL) ui->eComAccuOnTime->setText(m_Data->CompressorAccumulativeOnTime);

    if(m_Data->Time!=NULL)
        ui->RealTime->setText(m_Data->Time);

    ui->RealTime->setText(QDateTime::currentDateTime().toString("dd.MM.yyyy.h:m:s ap"));

}

void MainWindow::showStatusMessage(const QString &message)
{
    m_status->setText(message);
}

void MainWindow::on_newpushButton_15_clicked()
{

}

