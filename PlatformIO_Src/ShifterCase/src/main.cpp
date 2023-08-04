#include <Arduino.h>
#include <stdio.h>              // This example main program uses printf/fflush
#include "ShifterLogic\ShiftingLogic.h"             // Model header file
#include "IO_inputs\IO_inputs.h"
#include "TaskScheduler.h"
#include "ScreenControl\ScreenControl.h"
#include "IO_output\IO_output.h"

#include "HID-Project.h"

#define TASK1MS_PERIOD 1
#define TASK10MS_PERIOD 10

Scheduler runner;
static ShiftingLogic ShiftingLogic_Obj;
static IOinput IOinput_obj;
static ScreenControl ScreenControl_Obj;
static IOoutput IOoutput_obj;

int8_T Old_Gear = 0 ;

struct Result_ShiftingLogic_T {
  int8_T CurrentGear;                // '<Root>/Current Gear'
};

// Callback methods prototypes
void Task1MS();
Task t1(TASK10MS_PERIOD, TASK_FOREVER, &Task1MS, &runner, true);  //adding task to the chain on creation

void setup() {
  // put your setup code here, to run once:
  ShiftingLogic_Obj.initialize();
  IOinput_obj.InitInputs();
  runner.startNow();
  Serial.begin(9600);

  Gamepad.begin();
}

void loop() {
  runner.execute();
}


void Task1MS()
{

  static uint8_t count5 = 0;

  IOinput_obj.FastCyclic();
  //ShiftingLogic_Obj.setMax_Gear_Limit(MAXGEARDEFAULT_VALUE);
  ShiftingLogic_Obj.setMax_Gear_UP(IOinput_obj.IOInputs_MaxGearLimit.MaxGearLimitUp);
  ShiftingLogic_Obj.setMax_Gear_Down(IOinput_obj.IOInputs_MaxGearLimit.MaxGearLimitDown);
  ShiftingLogic_Obj.setReset_Count(IOinput_obj.IOInputs_ResetCount.ResetCount);
  ShiftingLogic_Obj.setShift_Down_request(IOinput_obj.IOInputs_ShiftDownRequest.ShiftDownRequest);
  ShiftingLogic_Obj.setShift_Up_request(IOinput_obj.IOInputs_ShiftUpRequest.ShiftUpRequest);
  ShiftingLogic_Obj.step();
  ScreenControl_Obj.setInport(ShiftingLogic_Obj.getCurrent_Gear());
  ScreenControl_Obj.step();
  IOoutput_obj.FastCyclic(ScreenControl_Obj.ScreenControl_Y.Outport);
  //Serial.print("Current Gear: ");
  //Serial.println(ShiftingLogic_Obj.getCurrent_Gear());
  //Serial.print("Max Gear: ");
  //Serial.println(ShiftingLogic_Obj.ShiftingLogic_DW.MaxGearMemory_DSTATE);
  if(ShiftingLogic_Obj.getCurrent_Gear()>Old_Gear && IOinput_obj.IOInputs_ShiftUpRequest.ShiftUpRequest == 1)
  {
    Gamepad.releaseAll();
    Gamepad.press(1);
    
    Old_Gear = ShiftingLogic_Obj.getCurrent_Gear();
    Gamepad.write();
    
  }
  else if(ShiftingLogic_Obj.getCurrent_Gear()<Old_Gear && IOinput_obj.IOInputs_ShiftDownRequest.ShiftDownRequest == 1)
  {
    Gamepad.releaseAll();
    Gamepad.press(2);
    Old_Gear = ShiftingLogic_Obj.getCurrent_Gear();
    Gamepad.write();
    
  }
  else if(IOinput_obj.IOInputs_ShiftDownRequest.ShiftDownRequest == 0 && IOinput_obj.IOInputs_ShiftUpRequest.ShiftUpRequest == 0)
  {
    Gamepad.releaseAll();
    Gamepad.write();
  }

}