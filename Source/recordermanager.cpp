#include "recordermanager.h"
#include <QRegularExpression>


RecorderManager::RecorderManager()
{
    m_db=QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("Records.db");

    if(m_db.open()){
         query=new QSqlQuery (m_db);
    }
    else {
        emit DataBaseError("Cannot connect To database !!!!"+m_db.lastError().text());

    }
}


QStringList RecorderManager::getRecords()
{
    if(m_db.isOpen()){
        return m_db.tables();
    }
    else
        {
                emit DataBaseError("Cannot connect To database !!!!"+m_db.lastError().text());
                return {};
    };

}

int RecorderManager::getRecordlength(QString RecordName)
{
    if(m_db.isOpen()){
        query->exec(QString("SELECT COUNT(*) FROM %1").arg(RecordName));
        if (!query->isActive()) {
            emit RecordRetrieveError("Failed to get rows length :" +query->lastError().text());
            qDebug()<<"Failed to get rows length  :" <<query->lastError().text();
         }
        if(query->next()) return query->value(0).toInt();
        return 0;
    }
    else
        {
                emit DataBaseError("Cannot connect To database !!!!"+m_db.lastError().text());
                return 0;
    };
}

QString RecorderManager::createRecord(QString RecordName)
{
    if(m_db.isOpen()){
        QString colums="[indx] INTEGER PRIMARY KEY AUTOINCREMENT"
                       ",";
        QVector<QString>::iterator itt;
                for (itt = FrameData.begin(); itt != FrameData.end(); ++itt) {
                    if((*itt)=="Time")colums+=(*itt)+" varchar(20),";
                    else colums+=(*itt)+" varchar(4),";
                }
                if (!colums.isEmpty()) {
                       colums.truncate(colums.size()-1);
                   }
        query->exec(QString("CREATE TABLE %1  (%2)").arg(RecordName,colums));

        // check if the query was executed successfully
        if (!query->isActive()) {
            emit RecordcreateError("Failed to create Record:"+query->lastError().text());
            return NULL;
         }
        return QString("%1").arg(RecordName) ;
    }
    else
        {
                emit DataBaseError("Cannot connect To database !!!!"+m_db.lastError().text());
                return NULL;
        };
}

bool RecorderManager::createRecordFrame(QString RecName, QVector<QString> Data)
{
    QString colums="";
    QString values="";
    if(m_db.isOpen()){
        
        QSqlQuery query;
        query.prepare("INSERT INTO '"+RecName+"' (Time ,RefrigeratorStateMachine, RefrigeratorPreCoolingStateMachine, RefrigeratorMode, OverloadPullDownModeStatesOR, OverTemperatureModeActions_OnStatesOR, "
                                              "Mode0,CorrectedAmbientTemperature,AmbientThermistorTemperature,FreezerThermistorTemperature,"
                                              "RefrigeratorThermistorTemperature,DefrostThermistorTemperature,CompressorState,"
                                              "CompressorSetSpeed,CompressorActualRunningSpeed,CompressorStep,StartingSpeedCondition,"
                                              "CompressorCutonPoint,CompressorCutOffPoint,DamperState,DamperCutOnPoint,DamperCutOffPoint,"
                                              "CompressorTimer,CompressorOnTimein,CompressorCycleAccumulativeOnTime,CompressorAccumulativeOnTime,"
                                              "CompressorPreviousDuty,CompressorOldDuty,RefrigeratorUserSelectionTemperature,RefPreCoolingStateMachine,"
                                              "FreezerUserSelectionTemperature,HeaterState,HeaterOnTime,FreezerDoorState,RefrigeratorDoorState,"
                                              "FreezerDoorCummulativeOpenTime,RefrigeratorDoorCummulativeOpenTime,TimesOfRefrigeratorDoorOpen,"
                                              "TimesOfFreezerDoorOpen,FanTargetSpeed,FanMeasuredSpeed,FanSpeedError,FanDACValue,"
                                              "RefrigeratorDefrostFactor,TimeToDefrostConditions) "
           
                      "VALUES (:Time ,:RefrigeratorStateMachine, :RefrigeratorPreCoolingStateMachine, :RefrigeratorMode, "
                                              ":OverloadPullDownModeStatesOR,:OverTemperatureModeActions_OnStatesOR, "
                                              ":Mode0,:CorrectedAmbientTemperature,:AmbientThermistorTemperature,:FreezerThermistorTemperature,"
                                              ":RefrigeratorThermistorTemperature,:DefrostThermistorTemperature,:CompressorState,"
                                              ":CompressorSetSpeed,:CompressorActualRunningSpeed,:CompressorStep,:StartingSpeedCondition,"
                                              ":CompressorCutonPoint,:CompressorCutOffPoint,:DamperState,:DamperCutOnPoint,:DamperCutOffPoint,"
                                              ":CompressorTimer,:CompressorOnTimein,:CompressorCycleAccumulativeOnTime,:CompressorAccumulativeOnTime,"
                                              ":CompressorPreviousDuty,:CompressorOldDuty,:RefrigeratorUserSelectionTemperature,:RefPreCoolingStateMachine,"
                                              ":FreezerUserSelectionTemperature,:HeaterState,:HeaterOnTime,:FreezerDoorState,:RefrigeratorDoorState,"
                                              ":FreezerDoorCummulativeOpenTime,:RefrigeratorDoorCummulativeOpenTime,:TimesOfRefrigeratorDoorOpen,"
                                              ":TimesOfFreezerDoorOpen,:FanTargetSpeed,:FanMeasuredSpeed,:FanSpeedError,:FanDACValue,"
                                              ":RefrigeratorDefrostFactor,:TimeToDefrostConditions) ");
        
        query.bindValue(":RefrigeratorStateMachine", RefrigeratorStateMachine);
        query.bindValue(":RefrigeratorPreCoolingStateMachine", RefrigeratorPreCoolingStateMachine);
        query.bindValue(":RefrigeratorMode", RefrigeratorMode);
        query.bindValue(":OverloadPullDownModeStatesOR", OverloadPullDownModeStatesOR);
        query.bindValue(":OverTemperatureModeActions_OnStatesOR", OverTemperatureModeActions_OnStatesOR);
        
        query.bindValue(":RefrigeratorStateMachine", RefrigeratorStateMachine);
        query.bindValue(":RefrigeratorStateMachine", RefrigeratorStateMachine);
        query.bindValue(":RefrigeratorStateMachine", RefrigeratorStateMachine);
        query.bindValue(":RefrigeratorStateMachine", RefrigeratorStateMachine);
        query.bindValue(":RefrigeratorStateMachine", RefrigeratorStateMachine);
        query.bindValue(":RefrigeratorStateMachine", RefrigeratorStateMachine);
        query.bindValue(":RefrigeratorStateMachine", RefrigeratorStateMachine);
        query.bindValue(":RefrigeratorStateMachine", RefrigeratorStateMachine);
        query.bindValue(":RefrigeratorStateMachine", RefrigeratorStateMachine);
        query.bindValue(":RefrigeratorStateMachine", RefrigeratorStateMachine);
        query.bindValue(":RefrigeratorStateMachine", RefrigeratorStateMachine);
        query.bindValue(":RefrigeratorStateMachine", RefrigeratorStateMachine);
        query.bindValue(":RefrigeratorStateMachine", RefrigeratorStateMachine);
        query.bindValue(":RefrigeratorStateMachine", RefrigeratorStateMachine);
        query.bindValue(":RefrigeratorStateMachine", RefrigeratorStateMachine);
        query.bindValue(":RefrigeratorStateMachine", RefrigeratorStateMachine);
        
        
                return true;
    }
   else
        {
                emit DataBaseError("Cannot connect To database !!!!"+m_db.lastError().text());
                return false;
    }
}

QMap<QString,QString> RecorderManager::RetrieveFramedata(QString RecName, int index)
{

    QMap<QString,QString> result;
    if(m_db.isOpen()){
        QString colums;
        QVector<QString>::iterator itt;
                for (itt = FrameData.begin(); itt != FrameData.end(); ++itt) {
                    colums+=(*itt)+",";
                }
                if (!colums.isEmpty()) {
                       colums.truncate(colums.size()-1);
                   }

        query->exec(QString("SELECT %1 FROM %2 WHERE indx='%3'").arg(colums,RecName,std::to_string(index).c_str()));
        if (!query->isActive()) {
            emit RecordRetrieveError("Failed to retrieve elements :" +query->lastError().text());
            qDebug()<<"Failed to retrieve elements :" <<query->lastError().text();
         }
        if(query->next()) {
            int counter=0;
            for (itt = FrameData.begin(); itt != FrameData.end(); ++itt) {
                result.insert((*itt),query->value(counter).toString());
                counter++;
            }

        }
    }
    else
        {
                emit DataBaseError("Cannot connect To database !!!!"+m_db.lastError().text());
        }
     return result;

}


