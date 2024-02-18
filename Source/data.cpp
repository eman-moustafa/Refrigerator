#include "data.h"

Data::Data()
{

}

void Data::setRefrigeratorStateMachine(const QString &newrefrigeratorStateMachine)
{
    if(newrefrigeratorStateMachine=="0")RefrigeratorStateMachine="REFRIGERATOR_STATE_POWER_ON";
    else if(newrefrigeratorStateMachine=="1")RefrigeratorStateMachine="REFRIGERATOR_STATE_START";
    else if(newrefrigeratorStateMachine=="2")RefrigeratorStateMachine="REFRIGERATOR_STATE_PRECOOLING";
    else if(newrefrigeratorStateMachine=="3")RefrigeratorStateMachine="REFRIGERATOR_STATE_COOLING";
    else if(newrefrigeratorStateMachine=="4")RefrigeratorStateMachine="REFRIGERATOR_STATE_PRE_DEFROST";
    else if(newrefrigeratorStateMachine=="5")RefrigeratorStateMachine="REFRIGERATOR_STATE_DEFROST";
    else if(newrefrigeratorStateMachine=="6")RefrigeratorStateMachine="REFRIGERATOR_STATE_POST_DEFROST";
    else RefrigeratorStateMachine="undefined";
}

void Data:: setRefrigeratorPreCoolingStateMachine(const QString &newRefrigeratorPreCoolingStateMachine)
{
    if(newRefrigeratorPreCoolingStateMachine=="0") RefrigeratorPreCoolingStateMachine="REFRIGERATOR_COOLING_START";
    else if(newRefrigeratorPreCoolingStateMachine=="1")RefrigeratorPreCoolingStateMachine="REFRIGERATOR_ONE_MINUTE_AFTER_COOLING_START";
    else if(newRefrigeratorPreCoolingStateMachine=="2")RefrigeratorPreCoolingStateMachine="REFRIGERATOR_FIVE_MINUTES_AFTER_COOLING_START";
    else if(newRefrigeratorPreCoolingStateMachine=="3")RefrigeratorPreCoolingStateMachine="REFRIGERATOR_SEVENTEEN_MINUTES_AFTER_COOLING_START";
    else RefrigeratorPreCoolingStateMachine="undefined";

}

void Data:: setRefrigeratorMode(const QString &newRefrigeratorMode)
{
    if(newRefrigeratorMode=="0")RefrigeratorMode="NORMAL_MODE";
    else if(newRefrigeratorMode=="1")RefrigeratorMode="EXPRESSFREEZING_MODE";
    else if(newRefrigeratorMode=="2")RefrigeratorMode="OVERLOAD_PULLDOWN_MODE";
    else if(newRefrigeratorMode=="3")RefrigeratorMode="REFRIGERATOR_OVER_TEMP_MODE";
    else if(newRefrigeratorMode=="4")RefrigeratorMode="ECO_MODE";
    else if(newRefrigeratorMode=="5")RefrigeratorMode="EXPRESS_FREEZING_WAIT_UNTIL_READY";
    else if(newRefrigeratorMode=="6")RefrigeratorMode="PWB_CHECK_MODE";
    else if(newRefrigeratorMode=="7")RefrigeratorMode="LINE_CHECK_A_TEST_MODE";
    else if(newRefrigeratorMode=="8")RefrigeratorMode="LINE_CHECK_B_TEST_MODE";
    else if(newRefrigeratorMode=="9")RefrigeratorMode="SELF_DIAGNOSIS_MODE";
    else if(newRefrigeratorMode=="10")RefrigeratorMode="INPUT_MEASUREMENT_MODE";
    else if(newRefrigeratorMode=="11")RefrigeratorMode="DEMO_TEST_MODE";
    else if(newRefrigeratorMode=="12")RefrigeratorMode="OPERATION_MONITORING_TEST_MODE";
    else if(newRefrigeratorMode=="13")RefrigeratorMode="ERROR_MODE";
    else RefrigeratorMode="undefined";
}

void Data::setOverloadPullDownModeStatesOR(const QString &newOverloadPullDownModeStatesOR)
{
    if (RefrigeratorMode=="OVERLOAD_PULLDOWN_MODE")
    {
    if(newOverloadPullDownModeStatesOR=="0")OverloadPullDownModeStatesOR="OVERLOAD_PLD_START_STATE";
    else if(newOverloadPullDownModeStatesOR=="1")OverloadPullDownModeStatesOR="OVERLOAD_PLD_MODE_ACTION_1_STATE";
    else if(newOverloadPullDownModeStatesOR=="2")OverloadPullDownModeStatesOR="OVERLOAD_PLD_MODE_ACTION_2_STATE";
    else if(newOverloadPullDownModeStatesOR=="3")OverloadPullDownModeStatesOR="OVERLOAD_PLD_MODE_ACTION_3_STATE";
    else if(newOverloadPullDownModeStatesOR=="4")OverloadPullDownModeStatesOR="OVERLOAD_PLD_MODE_ACTION_4_STATE";
    else if(newOverloadPullDownModeStatesOR=="5")OverloadPullDownModeStatesOR="OVERLOAD_PLD_END_STATE";
    else if(newOverloadPullDownModeStatesOR=="6")OverloadPullDownModeStatesOR="OVERLOAD_PLD_STATES_NUM";
    else OverloadPullDownModeStatesOR ="undefined";
    }
    else  OverloadPullDownModeStatesOR ="Not in OverloadPullDownMode";
}

void Data:: setOverTemperatureModeActionsOnStatesOR(const QString &newOverTemperatureModeActionsOnStatesOR)
{
     if (RefrigeratorMode=="REFRIGERATOR_OVER_TEMP_MODE")
     {
    if(newOverTemperatureModeActionsOnStatesOR=="0") OverTemperatureModeActions_OnStatesOR="REFRIGERTOR_OVER_TEMP_ACTION_0_STATE";
    else if(newOverTemperatureModeActionsOnStatesOR=="1")OverTemperatureModeActions_OnStatesOR="REFRIGERTOR_OVER_TEMP_ACTION_1_STATE";
    else if(newOverTemperatureModeActionsOnStatesOR=="2")OverTemperatureModeActions_OnStatesOR="REFRIGERTOR_OVER_TEMP_ACTION_2_STATE";
    else OverTemperatureModeActions_OnStatesOR="undefined";
     }
     else OverTemperatureModeActions_OnStatesOR="Not in Over Temperature Mode";
}

void Data::setMode0(const QString &newMode0)
{
    if (RefrigeratorMode=="REFRIGERATOR_OVER_TEMP_MODE"||RefrigeratorMode=="OVERLOAD_PULLDOWN_MODE")
    {
        if(newMode0=="0")  Mode0=" Not Overload Pulldown Mode, Not Over Temperature Mode";
        else Mode0="undefined";
    }
    else Mode0="0";
}

void Data::setCorrectedAmbientTemperature(const QString &newCorrectedAmbientTemperature)
{
     CorrectedAmbientTemperature =newCorrectedAmbientTemperature;
}

void Data::setAmbientThermistorTemperature(const QString &newAmbientThermistorTemperature)
{

    if (newAmbientThermistorTemperature =="30000") AmbientThermistorTemperature="OPEN_CIRCUIT_THERMISTOR_ERROR";
    else if (newAmbientThermistorTemperature =="20000") AmbientThermistorTemperature="SHORT_CIRCUIT_THERMISTOR_ERROR";
    else if (newAmbientThermistorTemperature!="30000" ||newAmbientThermistorTemperature !="20000")
        AmbientThermistorTemperature = std::to_string(newAmbientThermistorTemperature.toUInt()/100).c_str();
    else AmbientThermistorTemperature="undefined";

}

void Data::setFreezerThermistorTemperature(const QString &newFreezerThermistorTemperature)
{
    if (newFreezerThermistorTemperature =="30000") FreezerThermistorTemperature="OPEN_CIRCUIT_THERMISTOR_ERROR";
    else if (newFreezerThermistorTemperature =="20000") FreezerThermistorTemperature="SHORT_CIRCUIT_THERMISTOR_ERROR";
    else if (newFreezerThermistorTemperature!="30000" ||newFreezerThermistorTemperature !="20000")
        FreezerThermistorTemperature = std::to_string(newFreezerThermistorTemperature.toUInt()/100).c_str();
    else FreezerThermistorTemperature="undefined";
}

void Data::setRefrigeratorThermistorTemperature(const QString &newRefrigeratorThermistorTemperature)
{
    if (newRefrigeratorThermistorTemperature =="30000") RefrigeratorThermistorTemperature="OPEN_CIRCUIT_THERMISTOR_ERROR";
    else if (newRefrigeratorThermistorTemperature =="20000") RefrigeratorThermistorTemperature="SHORT_CIRCUIT_THERMISTOR_ERROR";
    else if (newRefrigeratorThermistorTemperature!="30000" ||newRefrigeratorThermistorTemperature !="20000")
        RefrigeratorThermistorTemperature = std::to_string(newRefrigeratorThermistorTemperature.toUInt()/100).c_str();
    else RefrigeratorThermistorTemperature="undefined";
}

void Data:: setDefrostThermistorTemperature(const QString &newDefrostThermistorTemperature)
{
    if (newDefrostThermistorTemperature =="30000") DefrostThermistorTemperature="OPEN_CIRCUIT_THERMISTOR_ERROR";
    else if (newDefrostThermistorTemperature =="20000") DefrostThermistorTemperature="SHORT_CIRCUIT_THERMISTOR_ERROR";
    else if (newDefrostThermistorTemperature!="30000" ||newDefrostThermistorTemperature !="20000")
        DefrostThermistorTemperature = std::to_string(newDefrostThermistorTemperature.toUInt()/100).c_str();
    else DefrostThermistorTemperature="undefined";
}

void Data:: setCompressorState(const QString &newCompressorState)
{
    if(newCompressorState=="0") CompressorState="COMPRESSOR_OFF_STATE";
    else if(newCompressorState=="1")CompressorState="COMPRESSOR_ON_STATE";
    else CompressorState="undefined";

}

void Data::setCompressorSetSpeed(const QString &newCompressorSetSpeed)
{
     CompressorSetSpeed = std::to_string(newCompressorSetSpeed.toUInt()*100).c_str();
}

void Data::setCompressorActualRunningSpeed(const QString &newCompressorActualRunningSpeed)
{
    CompressorActualRunningSpeed = std::to_string(newCompressorActualRunningSpeed.toUInt()*100).c_str();

}

void Data:: setCompressorStep(const QString &newCompressorStep)
{
    CompressorStep=newCompressorStep;
}

void Data::setStartingSpeedCondition(const QString &newStartingSpeedCondition)
{
    StartingSpeedCondition=newStartingSpeedCondition;
}

void Data::setCompressorCutonPoint(const QString &newCompressorCutonPoint)
{
    CompressorCutonPoint = std::to_string(newCompressorCutonPoint.toUInt()/100).c_str();

}

void Data::setCompressorCutOffPoint(const QString &newCompressorCutOffPoint)
{
    CompressorCutOffPoint = std::to_string(newCompressorCutOffPoint.toUInt()/100).c_str();

}

void Data::setDamperState(const QString &newDamperState)
{

    if(newDamperState=="0") DamperState="DAMPER_CLOSE";
    else if(newDamperState=="1")DamperState="DAMPER_OPEN";
    else DamperState="undefined";
}

void Data::setDamperCutonPoint (const QString &newDamperCutonPoint)
{
    DamperCutOnPoint = std::to_string(newDamperCutonPoint.toUInt()/100).c_str();

}

void Data::setDamperCutOffPoint (const QString &newDamperCutOffPoint)
{
    DamperCutOffPoint = std::to_string(newDamperCutOffPoint.toUInt()/100).c_str();

}

void Data::setCompressorTimer(const QString &newCompressorTimer)
{
    CompressorTimer=newCompressorTimer;
}

void Data::setCompressorOnTimein(const QString &newCompressorOnTimein)
{
    CompressorOnTimein=newCompressorOnTimein;
}

void Data::setCompressorCycleAccumulativeOnTime(const QString &newCompressorCycleAccumulativeOnTime)
{
    CompressorCycleAccumulativeOnTime=newCompressorCycleAccumulativeOnTime;
}

void Data::setCompressorAccumulativeOnTime(const QString &newCompressorAccumulativeOnTime)
{
    CompressorAccumulativeOnTime=newCompressorAccumulativeOnTime;
}

void Data::setCompressorPreviousDuty (const QString &newCompressorPreviousDuty)
{
    CompressorPreviousDuty=newCompressorPreviousDuty;
}

void Data::setCompressorOldDuty (const QString &newCompressorOldDuty)
{
    CompressorOldDuty=newCompressorOldDuty;
}

void Data::setRefrigeratorUserSelectionTemperature(const QString &newRefrigeratorUserSelectionTemperature)
{
    RefrigeratorUserSelectionTemperature=newRefrigeratorUserSelectionTemperature;
}

void Data::setRefPreCoolingStateMachine(const QString &newRefPreCoolingStateMachine)
{
    RefPreCoolingStateMachine=newRefPreCoolingStateMachine;
}

void Data::setFreezerUserSelectionTemperature(const QString &newFreezerUserSelectionTemperature)
{
    FreezerUserSelectionTemperature=newFreezerUserSelectionTemperature;
}

void Data::setHeaterState(const QString &newHeaterState)
{

    if(newHeaterState=="0") HeaterState="HEATER_OFF";
    else if(newHeaterState=="1")HeaterState="HEATER_ON";
    else HeaterState="undefined";

}

void Data::setHeaterOnTime(const QString &newHeaterOnTime)
{
    HeaterOnTime=newHeaterOnTime;
}

void Data::setFreezerDoorState(const QString &newFreezerDoorState)
{
    if(newFreezerDoorState=="0") FreezerDoorState="FREEZER_DOOR_CLOSED";
    else if(newFreezerDoorState=="1")FreezerDoorState="FREEZER_DOOR_OPEN";
    else if(newFreezerDoorState=="2")FreezerDoorState="FREEZER_DOOR_OPEN_FOR_AN_HOUR";
    else if(newFreezerDoorState=="3")FreezerDoorState="FREEZER_DOOR_CLOSED_FOR_FIFTEEN_SECONDS";
    else FreezerDoorState="undefined";

}

void Data::setRefrigeratorDoorState (const QString &newRefrigeratorDoorState)
{
    if(newRefrigeratorDoorState=="0") RefrigeratorDoorState="REFRIGERATOR_DOOR_CLOSED";
    else if(newRefrigeratorDoorState=="1")RefrigeratorDoorState="REFRIGERATOR_DOOR_OPEN";
    else if(newRefrigeratorDoorState=="2")RefrigeratorDoorState="REFRIGERATOR_DOOR_OPEN_FOR_AN_HOUR";
    else if(newRefrigeratorDoorState=="3")RefrigeratorDoorState="REFRIGERATOR_DOOR_CLOSED_FOR_FIFTEEN_SECONDS";
    else RefrigeratorDoorState="undefined";
}

void Data::setFreezerDoorCummulativeOpenTime (const QString &newFreezerDoorCummulativeOpenTime)
{
    FreezerDoorCummulativeOpenTime=newFreezerDoorCummulativeOpenTime;
}

void Data::setRefrigeratorDoorCummulativeOpenTime(const QString &newRefrigeratorDoorCummulativeOpenTime)
{
    RefrigeratorDoorCummulativeOpenTime=newRefrigeratorDoorCummulativeOpenTime;
}

void Data::setTimesOfRefrigeratorDoorOpen(const QString &newTimesOfRefrigeratorDoorOpen)
{
    TimesOfRefrigeratorDoorOpen=newTimesOfRefrigeratorDoorOpen;
}

void Data::setTimesOfFreezerDoorOpen(const QString &newTimesOfFreezerDoorOpen)
{
    TimesOfFreezerDoorOpen=newTimesOfFreezerDoorOpen;
}

void Data::setFanTargetSpeed(const QString &newFanTargetSpeed)
{
    FanTargetSpeed=newFanTargetSpeed;
}

void Data::setFanMeasuredSpeed (const QString &newFanMeasuredSpeed)
{
    FanMeasuredSpeed=newFanMeasuredSpeed;
}

void Data::setFanSpeedError (const QString &newFanSpeedError)
{
    FanSpeedError=newFanSpeedError;
}

void Data::setFanDACValue(const QString &newFanDACValue)
{
    FanDACValue=newFanDACValue;
}

void Data::setRefrigeratorDefrostFactor(const QString &newRefrigeratorDefrostFactor)
{
    RefrigeratorDefrostFactor=newRefrigeratorDefrostFactor;
}

void Data::setTimeToDefrostConditions(const QString &newTimeToDefrostConditions)
{
    TimeToDefrostConditions=newTimeToDefrostConditions;
}
