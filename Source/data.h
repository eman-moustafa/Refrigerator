#ifndef DATA_H
#define DATA_H


#include "QString"
#include <QtMath>

class Data
{
public:
    Data();

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

    QString Time=NULL;




    void setRefrigeratorStateMachine(const QString &newrefrigeratorStateMachine);

    void setRefrigeratorPreCoolingStateMachine(const QString &newRefrigeratorPreCoolingStateMachine);

    void setRefrigeratorMode(const QString &newRefrigeratorMode);

    void setOverloadPullDownModeStatesOR(const QString &newOverloadPullDownModeStatesOR);

    void setOverTemperatureModeActionsOnStatesOR(const QString &newOverTemperatureModeActionsOnStatesOR);

    void setMode0(const QString &newMode0);

    void setCorrectedAmbientTemperature(const QString &newCorrectedAmbientTemperature);

    void setAmbientThermistorTemperature(const QString &newAmbientThermistorTemperature);

    void setFreezerThermistorTemperature(const QString &newFreezerThermistorTemperature);

    void setRefrigeratorThermistorTemperature(const QString &newRefrigeratorThermistorTemperature);

    void setDefrostThermistorTemperature(const QString &newDefrostThermistorTemperature);

    void setCompressorState(const QString &newCompressorState);

    void setCompressorSetSpeed(const QString &newCompressorSetSpeed);

    void setCompressorActualRunningSpeed(const QString &newCompressorActualRunningSpeed);

    void setCompressorStep(const QString &newCompressorStep);

    void setStartingSpeedCondition(const QString &newStartingSpeedCondition);

    void setCompressorCutonPoint(const QString &newCompressorCutonPoint);

    void setCompressorCutOffPoint(const QString &newCompressorCutOffPoint);

    void setDamperState(const QString &newDamperState);

    void setDamperCutonPoint (const QString &newDamperCutonPoint);

    void setDamperCutOffPoint (const QString &newDamperCutOffPoint);

    void setCompressorTimer(const QString &newCompressorTimer);

    void setCompressorOnTimein(const QString &newCompressorOnTimein);

    void setCompressorCycleAccumulativeOnTime(const QString &newCompressorCycleAccumulativeOnTime);

    void setCompressorAccumulativeOnTime(const QString &newCompressorAccumulativeOnTime);

    void setCompressorPreviousDuty (const QString &newCompressorPreviousDuty);

    void setCompressorOldDuty (const QString &newCompressorOldDuty);

    void setRefrigeratorUserSelectionTemperature(const QString &newRefrigeratorUserSelectionTemperature);

    void setRefPreCoolingStateMachine(const QString &newRefPreCoolingStateMachine);

    void setFreezerUserSelectionTemperature(const QString &newFreezerUserSelectionTemperature);

    void setHeaterState(const QString &newHeaterState);

    void setHeaterOnTime(const QString &newHeaterOnTime);

    void setFreezerDoorState(const QString &newFreezerDoorState);

    void setRefrigeratorDoorState (const QString &newRefrigeratorDoorState);

    void setFreezerDoorCummulativeOpenTime (const QString &newFreezerDoorCummulativeOpenTime);

    void setRefrigeratorDoorCummulativeOpenTime(const QString &newRefrigeratorDoorCummulativeOpenTime);

    void setTimesOfRefrigeratorDoorOpen(const QString &newTimesOfRefrigeratorDoorOpen);

    void setTimesOfFreezerDoorOpen(const QString &newTimesOfFreezerDoorOpen);

    void setFanTargetSpeed(const QString &newFanTargetSpeed);

    void setFanMeasuredSpeed (const QString &newFanMeasuredSpeed);

    void setFanSpeedError (const QString &newFanSpeedError);

    void setFanDACValue(const QString &newFanDACValue);

    void setRefrigeratorDefrostFactor(const QString &newRefrigeratorDefrostFactor);

    void setTimeToDefrostConditions(const QString &newTimeToDefrostConditions);

    void setTime(const QString &newTime);





};

#endif // DATA_H
