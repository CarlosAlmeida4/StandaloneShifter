#include <Arduino.h>
#include <stdio.h>              // This example main program uses printf/fflush
#include "ShifterLogic\ShiftingLogic.h"             // Model header file

static ShiftingLogic ShiftingLogic_Obj;// Instance of model class

void setup() {
  // put your setup code here, to run once:
  ShiftingLogic_Obj.initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
  //udpate inputs
  
  //ShiftingLogic_Obj.setMax_Gear_Limit();
  //ShiftingLogic_Obj.setShift_UP_request();
  //ShiftingLogic_Obj.setShift_down_request();
  //ShiftingLogic_Obj.setReset_Count();
  ShiftingLogic_Obj.step();
}