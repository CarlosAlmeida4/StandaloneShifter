#include "Arduino.h"
#include "IO_inputs\IO_inputs.h"



void IOinput::InitInputs()
{
    IOInputs_MaxGearLimit.MaxGearDownPin = MAXGEARUP_PIN;
    IOInputs_ShiftUpRequest.ShiftUpRequestPin = SHIFTUPREQUEST_PIN;
    IOInputs_ShiftDownRequest.ShiftDownRequestPin = SHIFTDOWNREQUEST_PIN;
    IOInputs_ResetCount.ResetCountPin = RESETCOUNT_PIN;

    pinMode(IOInputs_MaxGearLimit.MaxGearDownPin,INPUT);
    pinMode(IOInputs_MaxGearLimit.MaxGearUpPin,INPUT);
    pinMode(IOInputs_ShiftUpRequest.ShiftUpRequestPin,INPUT);
    pinMode(IOInputs_ShiftDownRequest.ShiftDownRequestPin,INPUT);
    pinMode(IOInputs_ResetCount.ResetCountPin,INPUT);

    IOInputs_MaxGearLimit.MaxGearLimit = MAXGEARDEFAULT_VALUE;
    IOInputs_ShiftUpRequest.ShiftUpRequest = 0;
    IOInputs_ShiftDownRequest.ShiftDownRequest = 0;
    IOInputs_ResetCount.ResetCount = 0;
}

void IOinput::FastCyclic()
{
    IOInputs_ShiftUpRequest.ShiftUpRequest = digitalRead(IOInputs_ShiftUpRequest.ShiftUpRequestPin);
    IOInputs_ShiftDownRequest.ShiftDownRequest = digitalRead(IOInputs_ShiftDownRequest.ShiftDownRequestPin);
    IOInputs_ResetCount.ResetCount = digitalRead(IOInputs_ResetCount.ResetCountPin);
    
    if(digitalRead(IOInputs_MaxGearLimit.MaxGearDownPin))
    {
        IOInputs_MaxGearLimit.MaxGearLimit--;
    }
    else if(digitalRead(IOInputs_MaxGearLimit.MaxGearUpPin))
    {
        IOInputs_MaxGearLimit.MaxGearLimit++;
    }
    //Serial.print("Shit Up Request : ");
    //Serial.println(IOInputs_ShiftUpRequest.ShiftUpRequest);
    //Serial.print("Shit Down Request : ");
    //Serial.println(IOInputs_ShiftDownRequest.ShiftDownRequest);
}