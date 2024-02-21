#ifndef RECORDERMANAGER_H
#define RECORDERMANAGER_H
#include<QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QDateTime>
#include <sstream>
#include <QObject>
#include <QFileInfo>



class RecorderManager
{

public:
    RecorderManager();

    QStringList getRecords();
    int getRecordlength(QString RecordName);
    QString createRecord(QString RecordName);
    bool createRecordFrame(QString RecName,QVector<QString> Data);
    QMap<QString,QString> RetrieveFramedata(QString RecName,int index);
    void ExtractRecord(QString RecName,QString cols,int offset,QString Path);
    void importRecord(QString Path);
    QVector<QString>FrameData={"Time","RefrigeratorStateMachine","RefrigeratorPre_coolingStateMachine",
                               "RefrigeratorMode","OverloadPullDownModeStatesOR","OverTemperatureModeActions_OnStatesOR",
                               "Mode0","CorrectedAmbientTemperature","AmbientThermistorTemperature",
                               "FreezerThermistorTemperature","RefrigeratorThermistorTemperature","DefrostThermistorTemperature",
                               "CompressorState","CompressorSetSpeed","CompressorActualRunningSpeed","CompressorStep",
                               "StartingSpeedCondition","CompressorCutonPoint","CompressorCutOffPoint","DamperState",
                               "DamperCutOnPoint","DamperCutOffPoint","CompressorTimer","CompressorOnTimein","CompressorCycleAccumulativeOnTime",
                               "CompressorAccumulativeOnTime","CompressorPreviousDuty","CompressorOldDuty","RefrigeratorUserSelectionTemperature",
                               "RefPreCoolingStateMachine","FreezerUserSelectionTemperature","HeaterState","HeaterOnTime",
                               "FreezerDoorState","RefrigeratorDoorState","FreezerDoorCummulativeOpenTime",
                               "RefrigeratorDoorCummulativeOpenTime","TimesOfRefrigeratorDoorOpen",
                               "TimesOfFreezerDoorOpen","FanTargetSpeed","FanMeasuredSpeed",
                               "FanSpeedError","FanDACValue","RefrigeratorDefrostFactor","RecorderManager",
                               };






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
private:
    QSqlDatabase m_db;
    QSqlQuery *query;
signals:
    void DataBaseError(QString Result);
    void RecordcreateError(QString Result);
    void RecordcreateFrameError(QString Result);
    void RecordRetrieveError(QString Result);
    void RecordImportError(QString Result);
    void RecordExportError(QString Result);
    void RecordimportSucc(QString Result);
    void RecordExportSucc(QString Result);

};

#endif // RECORDERMANAGER_H
