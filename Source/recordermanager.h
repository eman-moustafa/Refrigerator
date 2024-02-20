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
