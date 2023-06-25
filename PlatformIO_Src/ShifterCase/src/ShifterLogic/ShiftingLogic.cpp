//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ShiftingLogic.cpp
//
// Code generated for Simulink model 'ShiftingLogic'.
//
// Model version                  : 1.16
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Sun Jun 25 23:04:35 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Atmel->AVR
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ShifterLogic\ShiftingLogic.h"
#include <cmath>
#include "ShifterLogic\rtwtypes.h"

// Model step function
void ShiftingLogic::step()
{
  // Outputs for Atomic SubSystem: '<Root>/ShiftingLogic'
  // DataTypeConversion: '<S3>/Cast To Boolean' incorporates:
  //   Inport: '<Root>/Shift UP request'

  ShiftingLogic_B.CastToBoolean = (ShiftingLogic_U.ShiftUPrequest != 0);

  // Delay: '<S6>/Delay'
  ShiftingLogic_B.Delay = ShiftingLogic_DW.Delay_DSTATE;

  // DataTypeConversion: '<S3>/Cast To Boolean1' incorporates:
  //   Inport: '<Root>/Shift down request'

  ShiftingLogic_B.CastToBoolean1 = (ShiftingLogic_U.Shiftdownrequest != 0);

  // Delay: '<S7>/Delay'
  ShiftingLogic_B.Delay_n = ShiftingLogic_DW.Delay_DSTATE_l;

  // Outport: '<Root>/Current Gear' incorporates:
  //   Delay: '<S1>/Current Gear Memory'

  ShiftingLogic_Y.CurrentGear = ShiftingLogic_DW.CurrentGearMemory_DSTATE;

  // Switch: '<S5>/Switch' incorporates:
  //   Constant: '<S5>/Constant'
  //   Inport: '<Root>/Reset Count'

  if (ShiftingLogic_U.ResetCount > ShiftingLogic_P.Switch_Threshold) {
    real_T u0;
    u0 = std::floor(ShiftingLogic_P.Constant_Value);
    if (std::isnan(u0) || std::isinf(u0)) {
      u0 = 0.0;
    } else {
      u0 = std::fmod(u0, 256.0);
    }

    // Switch: '<S5>/Switch' incorporates:
    //   Constant: '<S5>/Constant'

    ShiftingLogic_B.Switch_i = static_cast<int8_T>(u0 < 0.0 ?
      static_cast<int16_T>(static_cast<int8_T>(-static_cast<int8_T>(static_cast<
      uint8_T>(-u0)))) : static_cast<int16_T>(static_cast<int8_T>
      (static_cast<uint8_T>(u0))));
  } else {
    real_T u0;
    real_T u1;
    real_T u2;

    // Logic: '<S2>/Logical Operator' incorporates:
    //   Inport: '<Root>/Shift UP request'
    //   Inport: '<Root>/Shift down request'

    ShiftingLogic_B.LogicalOperator = ((ShiftingLogic_U.ShiftUPrequest != 0) &&
      (ShiftingLogic_U.Shiftdownrequest != 0));

    // Switch: '<S2>/Switch1' incorporates:
    //   Switch: '<S2>/Switch'

    if (ShiftingLogic_B.LogicalOperator) {
      // Switch: '<S2>/Switch1' incorporates:
      //   Constant: '<S2>/Constant2'

      ShiftingLogic_B.Switch1 = ShiftingLogic_P.Constant2_Value;

      // Switch: '<S2>/Switch' incorporates:
      //   Constant: '<S2>/Constant1'

      ShiftingLogic_B.Switch = ShiftingLogic_P.Constant1_Value;
    } else {
      // Logic: '<S7>/Logical Operator'
      ShiftingLogic_B.LogicalOperator_i = !ShiftingLogic_B.Delay_n;

      // Logic: '<S7>/Logical Operator1'
      ShiftingLogic_B.LogicalOperator1_o = (ShiftingLogic_B.CastToBoolean1 &&
        ShiftingLogic_B.LogicalOperator_i);

      // DataTypeConversion: '<S3>/Cast1'
      ShiftingLogic_B.Cast1 = ShiftingLogic_B.LogicalOperator1_o;

      // Switch: '<S2>/Switch1'
      ShiftingLogic_B.Switch1 = ShiftingLogic_B.Cast1;

      // Logic: '<S6>/Logical Operator'
      ShiftingLogic_B.LogicalOperator_o = !ShiftingLogic_B.Delay;

      // Logic: '<S6>/Logical Operator1'
      ShiftingLogic_B.LogicalOperator1 = (ShiftingLogic_B.CastToBoolean &&
        ShiftingLogic_B.LogicalOperator_o);

      // DataTypeConversion: '<S3>/Cast'
      ShiftingLogic_B.Cast = ShiftingLogic_B.LogicalOperator1;

      // Switch: '<S2>/Switch'
      ShiftingLogic_B.Switch = ShiftingLogic_B.Cast;
    }

    // End of Switch: '<S2>/Switch1'

    // Sum: '<S1>/Add' incorporates:
    //   Outport: '<Root>/Current Gear'

    ShiftingLogic_B.RequestedGear = (ShiftingLogic_B.Switch -
      ShiftingLogic_B.Switch1) + static_cast<real_T>(ShiftingLogic_Y.CurrentGear);

    // Saturate: '<S4>/Saturation'
    u0 = ShiftingLogic_B.RequestedGear;
    u1 = ShiftingLogic_P.Saturation_LowerSat;
    u2 = ShiftingLogic_P.AbsoluteMaxGear;
    if (u0 > u2) {
      // Saturate: '<S4>/Saturation'
      ShiftingLogic_B.Saturation = u2;
    } else if (u0 < u1) {
      // Saturate: '<S4>/Saturation'
      ShiftingLogic_B.Saturation = u1;
    } else {
      // Saturate: '<S4>/Saturation'
      ShiftingLogic_B.Saturation = u0;
    }

    // End of Saturate: '<S4>/Saturation'

    // RelationalOperator: '<S8>/Relational Operator' incorporates:
    //   Inport: '<Root>/Max Gear Limit'

    ShiftingLogic_B.RelationalOperator = (ShiftingLogic_U.MaxGearLimit <
      ShiftingLogic_B.Saturation);

    // Switch: '<S8>/Switch'
    if (ShiftingLogic_B.RelationalOperator) {
      // Switch: '<S8>/Switch' incorporates:
      //   Inport: '<Root>/Max Gear Limit'

      ShiftingLogic_B.Switch_h = ShiftingLogic_U.MaxGearLimit;
    } else {
      // Switch: '<S8>/Switch'
      ShiftingLogic_B.Switch_h = ShiftingLogic_B.Saturation;
    }

    // End of Switch: '<S8>/Switch'
    u0 = std::floor(ShiftingLogic_B.Switch_h);
    if (std::isnan(u0) || std::isinf(u0)) {
      u0 = 0.0;
    } else {
      u0 = std::fmod(u0, 256.0);
    }

    // Switch: '<S5>/Switch'
    ShiftingLogic_B.Switch_i = static_cast<int8_T>(u0 < 0.0 ?
      static_cast<int16_T>(static_cast<int8_T>(-static_cast<int8_T>(static_cast<
      uint8_T>(-u0)))) : static_cast<int16_T>(static_cast<int8_T>
      (static_cast<uint8_T>(u0))));
  }

  // End of Switch: '<S5>/Switch'

  // Update for Delay: '<S6>/Delay'
  ShiftingLogic_DW.Delay_DSTATE = ShiftingLogic_B.CastToBoolean;

  // Update for Delay: '<S7>/Delay'
  ShiftingLogic_DW.Delay_DSTATE_l = ShiftingLogic_B.CastToBoolean1;

  // Update for Delay: '<S1>/Current Gear Memory'
  ShiftingLogic_DW.CurrentGearMemory_DSTATE = ShiftingLogic_B.Switch_i;

  // End of Outputs for SubSystem: '<Root>/ShiftingLogic'
}

// Model initialize function
void ShiftingLogic::initialize()
{
  // SystemInitialize for Atomic SubSystem: '<Root>/ShiftingLogic'
  // InitializeConditions for Delay: '<S6>/Delay'
  ShiftingLogic_DW.Delay_DSTATE = ShiftingLogic_P.Delay_InitialCondition;

  // InitializeConditions for Delay: '<S7>/Delay'
  ShiftingLogic_DW.Delay_DSTATE_l = ShiftingLogic_P.Delay_InitialCondition_i;

  // InitializeConditions for Delay: '<S1>/Current Gear Memory'
  ShiftingLogic_DW.CurrentGearMemory_DSTATE =
    ShiftingLogic_P.CurrentGearMemory_InitialCondit;

  // End of SystemInitialize for SubSystem: '<Root>/ShiftingLogic'
}

// Model terminate function
void ShiftingLogic::terminate()
{
  // (no terminate code required)
}

// Root inport: '<Root>/Max Gear Limit' set method
void ShiftingLogic::setMax_Gear_Limit(uint8_T localArgInput)
{
  ShiftingLogic_U.MaxGearLimit = localArgInput;
}

// Root inport: '<Root>/Shift UP request' set method
void ShiftingLogic::setShift_UP_request(uint8_T localArgInput)
{
  ShiftingLogic_U.ShiftUPrequest = localArgInput;
}

// Root inport: '<Root>/Shift down request' set method
void ShiftingLogic::setShift_down_request(uint8_T localArgInput)
{
  ShiftingLogic_U.Shiftdownrequest = localArgInput;
}

// Root inport: '<Root>/Reset Count' set method
void ShiftingLogic::setReset_Count(uint8_T localArgInput)
{
  ShiftingLogic_U.ResetCount = localArgInput;
}

// Root outport: '<Root>/Current Gear' get method
int8_T ShiftingLogic::getCurrent_Gear() const
{
  return ShiftingLogic_Y.CurrentGear;
}

// Constructor
ShiftingLogic::ShiftingLogic() :
  ShiftingLogic_U(),
  ShiftingLogic_Y(),
  ShiftingLogic_B(),
  ShiftingLogic_DW(),
  ShiftingLogic_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
ShiftingLogic::~ShiftingLogic()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
ShiftingLogic::RT_MODEL_ShiftingLogic_T * ShiftingLogic::getRTM()
{
  return (&ShiftingLogic_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
