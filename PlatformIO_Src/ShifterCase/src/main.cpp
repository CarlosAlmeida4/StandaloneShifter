#include <Arduino.h>
#include <stdio.h>              // This example main program uses printf/fflush
#include "ShifterLogic\ShiftingLogic.h"             // Model header file
#include "IO_inputs\IO_inputs.h"
#include "TaskScheduler.h"

#define TASK1MS_PERIOD 1

Scheduler runner;
static ShiftingLogic ShiftingLogic_Obj;// Instance of model class
static IOinput IOinput_obj;

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
  ShiftingLogic_Obj.setMax_Gear_Limit(/*IOinput_obj.IOInputs_MaxGearLimit.MaxGearLimit*/MAXGEARDEFAULT_VALUE);
  ShiftingLogic_Obj.setReset_Count(0);
  ShiftingLogic_Obj.setShift_down_request(IOinput_obj.IOInputs_ShiftDownRequest.ShiftDownRequest);
  ShiftingLogic_Obj.setShift_UP_request(IOinput_obj.IOInputs_ShiftUpRequest.ShiftUpRequest);
  ShiftingLogic_Obj.step();
  Serial.println(ShiftingLogic_Obj.getCurrent_Gear());
}