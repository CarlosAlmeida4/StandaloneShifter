#include <Arduino.h>
#include <stdio.h>              // This example main program uses printf/fflush
#include "ShifterLogic\ShiftingLogic.h"             // Model header file
#include "IO_inputs\IO_inputs.h"
#include "TaskScheduler.h"

#define TASK1MS_PERIOD 1

Scheduler runner;
static ShiftingLogic ShiftingLogic_Obj;// Instance of model class
static IOinput IOinput_obj;

struct Result_ShiftingLogic_T {
  int8_T CurrentGear;                // '<Root>/Current Gear'
};

// Callback methods prototypes
void Task1MS();
Task t1(TASK1MS_PERIOD, TASK_FOREVER, &Task1MS, &runner, true);  //adding task to the chain on creation

void setup() {
  // put your setup code here, to run once:
  ShiftingLogic_Obj.initialize();
  IOinput_obj.InitInputs();
  runner.startNow();
  Serial.begin(9600);
}

void loop() {
  runner.execute();
}


void Task1MS()
{
  IOinput_obj.FastCyclic();
  //ShiftingLogic_Obj.setMax_Gear_Limit(MAXGEARDEFAULT_VALUE);
  ShiftingLogic_Obj.setMax_Gear_UP(IOinput_obj.IOInputs_MaxGearLimit.MaxGearUpPin);
  ShiftingLogic_Obj.setMax_Gear_Down(IOinput_obj.IOInputs_MaxGearLimit.MaxGearDownPin);
  ShiftingLogic_Obj.setReset_Count(IOinput_obj.IOInputs_ResetCount.ResetCount);
  ShiftingLogic_Obj.setShift_Down_request(IOinput_obj.IOInputs_ShiftDownRequest.ShiftDownRequest);
  ShiftingLogic_Obj.setShift_Up_request(IOinput_obj.IOInputs_ShiftUpRequest.ShiftUpRequest);
  ShiftingLogic_Obj.step();
  Serial.println(ShiftingLogic_Obj.ShiftingLogic_DW.MaxGearMemory_DSTATE);
  //Serial.println(ShiftingLogic_Obj.getCurrent_Gear());
}