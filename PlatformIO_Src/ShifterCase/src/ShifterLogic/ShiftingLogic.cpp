//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ShiftingLogic.cpp
//
// Code generated for Simulink model 'ShiftingLogic'.
//
// Model version                  : 1.18
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Sat Jul  1 18:20:37 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Atmel->AVR
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ShiftingLogic.h"
#include <cmath>
#include "rtwtypes.h"

// Model step function
void ShiftingLogic::step()
{
  real_T u0_0;
  uint8_T u0;
  uint8_T u1;
  uint8_T u2;

  // Outputs for Atomic SubSystem: '<Root>/ShiftingLogic'
  // Logic: '<S5>/Logical Operator' incorporates:
  //   Inport: '<Root>/Max Gear Down'
  //   Inport: '<Root>/Max Gear UP'

  ShiftingLogic_B.LogicalOperator = ((ShiftingLogic_U.MaxGearUP != 0) &&
    (ShiftingLogic_U.MaxGearDown != 0));

  // DataTypeConversion: '<S6>/Cast To Boolean' incorporates:
  //   Inport: '<Root>/Max Gear UP'

  ShiftingLogic_B.CastToBoolean = (ShiftingLogic_U.MaxGearUP != 0);

  // Delay: '<S7>/Delay'
  ShiftingLogic_B.Delay = ShiftingLogic_DW.Delay_DSTATE;

  // Switch: '<S5>/Switch'
  if (ShiftingLogic_B.LogicalOperator) {
    // Switch: '<S5>/Switch' incorporates:
    //   Constant: '<S5>/Constant1'

    ShiftingLogic_B.Switch = ShiftingLogic_P.Constant1_Value;
  } else {
    // Logic: '<S7>/Logical Operator'
    ShiftingLogic_B.LogicalOperator_e = !ShiftingLogic_B.Delay;

    // Logic: '<S7>/Logical Operator1'
    ShiftingLogic_B.LogicalOperator1_k = (ShiftingLogic_B.CastToBoolean &&
      ShiftingLogic_B.LogicalOperator_e);

    // DataTypeConversion: '<S6>/Cast'
    ShiftingLogic_B.Cast_k = ShiftingLogic_B.LogicalOperator1_k;

    // Switch: '<S5>/Switch'
    ShiftingLogic_B.Switch = ShiftingLogic_B.Cast_k;
  }

  // End of Switch: '<S5>/Switch'

  // DataTypeConversion: '<S3>/Cast'
  u0_0 = std::floor(ShiftingLogic_B.Switch);
  if (std::isnan(u0_0) || std::isinf(u0_0)) {
    u0_0 = 0.0;
  } else {
    u0_0 = std::fmod(u0_0, 256.0);
  }

  // DataTypeConversion: '<S3>/Cast'
  ShiftingLogic_B.Cast = static_cast<uint8_T>(u0_0 < 0.0 ? static_cast<int16_T>(
    static_cast<uint8_T>(-static_cast<int8_T>(static_cast<uint8_T>(-u0_0)))) :
    static_cast<int16_T>(static_cast<uint8_T>(u0_0)));

  // DataTypeConversion: '<S6>/Cast To Boolean1' incorporates:
  //   Inport: '<Root>/Max Gear Down'

  ShiftingLogic_B.CastToBoolean1 = (ShiftingLogic_U.MaxGearDown != 0);

  // Delay: '<S8>/Delay'
  ShiftingLogic_B.Delay_a = ShiftingLogic_DW.Delay_DSTATE_d;

  // Switch: '<S5>/Switch1'
  if (ShiftingLogic_B.LogicalOperator) {
    // Switch: '<S5>/Switch1' incorporates:
    //   Constant: '<S5>/Constant2'

    ShiftingLogic_B.Switch1 = ShiftingLogic_P.Constant2_Value;
  } else {
    // Logic: '<S8>/Logical Operator'
    ShiftingLogic_B.LogicalOperator_op = !ShiftingLogic_B.Delay_a;

    // Logic: '<S8>/Logical Operator1'
    ShiftingLogic_B.LogicalOperator1_d = (ShiftingLogic_B.CastToBoolean1 &&
      ShiftingLogic_B.LogicalOperator_op);

    // DataTypeConversion: '<S6>/Cast1'
    ShiftingLogic_B.Cast1_b = ShiftingLogic_B.LogicalOperator1_d;

    // Switch: '<S5>/Switch1'
    ShiftingLogic_B.Switch1 = ShiftingLogic_B.Cast1_b;
  }

  // End of Switch: '<S5>/Switch1'

  // DataTypeConversion: '<S3>/Cast1'
  u0_0 = std::floor(ShiftingLogic_B.Switch1);
  if (std::isnan(u0_0) || std::isinf(u0_0)) {
    u0_0 = 0.0;
  } else {
    u0_0 = std::fmod(u0_0, 256.0);
  }

  // DataTypeConversion: '<S3>/Cast1'
  ShiftingLogic_B.Cast1 = static_cast<uint8_T>(u0_0 < 0.0 ? static_cast<int16_T>
    (static_cast<uint8_T>(-static_cast<int8_T>(static_cast<uint8_T>(-u0_0)))) :
    static_cast<int16_T>(static_cast<uint8_T>(u0_0)));

  // Delay: '<S3>/Max Gear Memory'
  ShiftingLogic_B.MaxGearMemory = ShiftingLogic_DW.MaxGearMemory_DSTATE;

  // Sum: '<S3>/Add'
  ShiftingLogic_B.MaxGear = static_cast<uint8_T>((ShiftingLogic_B.Cast -
    ShiftingLogic_B.Cast1) + ShiftingLogic_B.MaxGearMemory);

  // Saturate: '<S3>/Saturation'
  u0 = ShiftingLogic_B.MaxGear;
  u1 = ShiftingLogic_P.Saturation_LowerSat_o;
  u2 = ShiftingLogic_P.Saturation_UpperSat;
  if (u0 > u2) {
    // Saturate: '<S3>/Saturation'
    ShiftingLogic_B.Saturation_m = u2;
  } else if (u0 < u1) {
    // Saturate: '<S3>/Saturation'
    ShiftingLogic_B.Saturation_m = u1;
  } else {
    // Saturate: '<S3>/Saturation'
    ShiftingLogic_B.Saturation_m = u0;
  }

  // End of Saturate: '<S3>/Saturation'

  // Outputs for Atomic SubSystem: '<S2>/ShiftingLogic'
  // DataTypeConversion: '<S10>/Cast To Boolean' incorporates:
  //   Inport: '<Root>/Shift Up request'

  ShiftingLogic_B.CastToBoolean_f = (ShiftingLogic_U.ShiftUprequest != 0);

  // Delay: '<S13>/Delay'
  ShiftingLogic_B.Delay_g = ShiftingLogic_DW.Delay_DSTATE_m;

  // DataTypeConversion: '<S10>/Cast To Boolean1' incorporates:
  //   Inport: '<Root>/Shift Down request'

  ShiftingLogic_B.CastToBoolean1_p = (ShiftingLogic_U.ShiftDownrequest != 0);

  // Delay: '<S14>/Delay'
  ShiftingLogic_B.Delay_n = ShiftingLogic_DW.Delay_DSTATE_l;

  // Outport: '<Root>/Current Gear' incorporates:
  //   Delay: '<S4>/Current Gear Memory'

  ShiftingLogic_Y.CurrentGear = ShiftingLogic_DW.CurrentGearMemory_DSTATE;

  // Switch: '<S12>/Switch' incorporates:
  //   Constant: '<S12>/Constant'
  //   Inport: '<Root>/Reset Count'

  if (ShiftingLogic_U.ResetCount > ShiftingLogic_P.Switch_Threshold) {
    u0_0 = std::floor(ShiftingLogic_P.Constant_Value);
    if (std::isnan(u0_0) || std::isinf(u0_0)) {
      u0_0 = 0.0;
    } else {
      u0_0 = std::fmod(u0_0, 256.0);
    }

    // Switch: '<S12>/Switch' incorporates:
    //   Constant: '<S12>/Constant'

    ShiftingLogic_B.Switch_i = static_cast<int8_T>(u0_0 < 0.0 ?
      static_cast<int16_T>(static_cast<int8_T>(-static_cast<int8_T>(static_cast<
      uint8_T>(-u0_0)))) : static_cast<int16_T>(static_cast<int8_T>
      (static_cast<uint8_T>(u0_0))));
  } else {
    real_T u1_0;
    real_T u2_0;

    // Logic: '<S9>/Logical Operator' incorporates:
    //   Inport: '<Root>/Shift Down request'
    //   Inport: '<Root>/Shift Up request'

    ShiftingLogic_B.LogicalOperator_m = ((ShiftingLogic_U.ShiftUprequest != 0) &&
      (ShiftingLogic_U.ShiftDownrequest != 0));

    // Switch: '<S9>/Switch1' incorporates:
    //   Switch: '<S9>/Switch'

    if (ShiftingLogic_B.LogicalOperator_m) {
      // Switch: '<S9>/Switch1' incorporates:
      //   Constant: '<S9>/Constant2'

      ShiftingLogic_B.Switch1_c = ShiftingLogic_P.Constant2_Value_n;

      // Switch: '<S9>/Switch' incorporates:
      //   Constant: '<S9>/Constant1'

      ShiftingLogic_B.Switch_n = ShiftingLogic_P.Constant1_Value_b;
    } else {
      // Logic: '<S14>/Logical Operator'
      ShiftingLogic_B.LogicalOperator_i = !ShiftingLogic_B.Delay_n;

      // Logic: '<S14>/Logical Operator1'
      ShiftingLogic_B.LogicalOperator1_o = (ShiftingLogic_B.CastToBoolean1_p &&
        ShiftingLogic_B.LogicalOperator_i);

      // DataTypeConversion: '<S10>/Cast1'
      ShiftingLogic_B.Cast1_f = ShiftingLogic_B.LogicalOperator1_o;

      // Switch: '<S9>/Switch1'
      ShiftingLogic_B.Switch1_c = ShiftingLogic_B.Cast1_f;

      // Logic: '<S13>/Logical Operator'
      ShiftingLogic_B.LogicalOperator_o = !ShiftingLogic_B.Delay_g;

      // Logic: '<S13>/Logical Operator1'
      ShiftingLogic_B.LogicalOperator1 = (ShiftingLogic_B.CastToBoolean_f &&
        ShiftingLogic_B.LogicalOperator_o);

      // DataTypeConversion: '<S10>/Cast'
      ShiftingLogic_B.Cast_i = ShiftingLogic_B.LogicalOperator1;

      // Switch: '<S9>/Switch'
      ShiftingLogic_B.Switch_n = ShiftingLogic_B.Cast_i;
    }

    // End of Switch: '<S9>/Switch1'

    // Sum: '<S4>/Add' incorporates:
    //   Outport: '<Root>/Current Gear'

    ShiftingLogic_B.RequestedGear = (ShiftingLogic_B.Switch_n -
      ShiftingLogic_B.Switch1_c) + static_cast<real_T>
      (ShiftingLogic_Y.CurrentGear);

    // Saturate: '<S11>/Saturation'
    u0_0 = ShiftingLogic_B.RequestedGear;
    u1_0 = ShiftingLogic_P.Saturation_LowerSat;
    u2_0 = ShiftingLogic_P.AbsoluteMaxGear;
    if (u0_0 > u2_0) {
      // Saturate: '<S11>/Saturation'
      ShiftingLogic_B.Saturation = u2_0;
    } else if (u0_0 < u1_0) {
      // Saturate: '<S11>/Saturation'
      ShiftingLogic_B.Saturation = u1_0;
    } else {
      // Saturate: '<S11>/Saturation'
      ShiftingLogic_B.Saturation = u0_0;
    }

    // End of Saturate: '<S11>/Saturation'

    // RelationalOperator: '<S15>/Relational Operator'
    ShiftingLogic_B.RelationalOperator = (ShiftingLogic_B.MaxGearMemory <
      ShiftingLogic_B.Saturation);

    // Switch: '<S15>/Switch'
    if (ShiftingLogic_B.RelationalOperator) {
      // Switch: '<S15>/Switch'
      ShiftingLogic_B.Switch_h = ShiftingLogic_B.MaxGearMemory;
    } else {
      // Switch: '<S15>/Switch'
      ShiftingLogic_B.Switch_h = ShiftingLogic_B.Saturation;
    }

    // End of Switch: '<S15>/Switch'
    u0_0 = std::floor(ShiftingLogic_B.Switch_h);
    if (std::isnan(u0_0) || std::isinf(u0_0)) {
      u0_0 = 0.0;
    } else {
      u0_0 = std::fmod(u0_0, 256.0);
    }

    // Switch: '<S12>/Switch'
    ShiftingLogic_B.Switch_i = static_cast<int8_T>(u0_0 < 0.0 ?
      static_cast<int16_T>(static_cast<int8_T>(-static_cast<int8_T>(static_cast<
      uint8_T>(-u0_0)))) : static_cast<int16_T>(static_cast<int8_T>
      (static_cast<uint8_T>(u0_0))));
  }

  // End of Switch: '<S12>/Switch'

  // Update for Delay: '<S13>/Delay'
  ShiftingLogic_DW.Delay_DSTATE_m = ShiftingLogic_B.CastToBoolean_f;

  // Update for Delay: '<S14>/Delay'
  ShiftingLogic_DW.Delay_DSTATE_l = ShiftingLogic_B.CastToBoolean1_p;

  // Update for Delay: '<S4>/Current Gear Memory'
  ShiftingLogic_DW.CurrentGearMemory_DSTATE = ShiftingLogic_B.Switch_i;

  // End of Outputs for SubSystem: '<S2>/ShiftingLogic'

  // Update for Delay: '<S7>/Delay'
  ShiftingLogic_DW.Delay_DSTATE = ShiftingLogic_B.CastToBoolean;

  // Update for Delay: '<S8>/Delay'
  ShiftingLogic_DW.Delay_DSTATE_d = ShiftingLogic_B.CastToBoolean1;

  // Update for Delay: '<S3>/Max Gear Memory'
  ShiftingLogic_DW.MaxGearMemory_DSTATE = ShiftingLogic_B.Saturation_m;

  // End of Outputs for SubSystem: '<Root>/ShiftingLogic'
}

// Model initialize function
void ShiftingLogic::initialize()
{
  // SystemInitialize for Atomic SubSystem: '<Root>/ShiftingLogic'
  // InitializeConditions for Delay: '<S7>/Delay'
  ShiftingLogic_DW.Delay_DSTATE = ShiftingLogic_P.Delay_InitialCondition_c;

  // InitializeConditions for Delay: '<S8>/Delay'
  ShiftingLogic_DW.Delay_DSTATE_d = ShiftingLogic_P.Delay_InitialCondition_h;

  // InitializeConditions for Delay: '<S3>/Max Gear Memory'
  ShiftingLogic_DW.MaxGearMemory_DSTATE =
    ShiftingLogic_P.MaxGearMemory_InitialCondition;

  // SystemInitialize for Atomic SubSystem: '<S2>/ShiftingLogic'
  // InitializeConditions for Delay: '<S13>/Delay'
  ShiftingLogic_DW.Delay_DSTATE_m = ShiftingLogic_P.Delay_InitialCondition;

  // InitializeConditions for Delay: '<S14>/Delay'
  ShiftingLogic_DW.Delay_DSTATE_l = ShiftingLogic_P.Delay_InitialCondition_i;

  // InitializeConditions for Delay: '<S4>/Current Gear Memory'
  ShiftingLogic_DW.CurrentGearMemory_DSTATE =
    ShiftingLogic_P.CurrentGearMemory_InitialCondit;

  // End of SystemInitialize for SubSystem: '<S2>/ShiftingLogic'
  // End of SystemInitialize for SubSystem: '<Root>/ShiftingLogic'
}

// Model terminate function
void ShiftingLogic::terminate()
{
  // (no terminate code required)
}

// Root inport: '<Root>/Shift Up request' set method
void ShiftingLogic::setShift_Up_request(uint8_T localArgInput)
{
  ShiftingLogic_U.ShiftUprequest = localArgInput;
}

// Root inport: '<Root>/Shift Down request' set method
void ShiftingLogic::setShift_Down_request(uint8_T localArgInput)
{
  ShiftingLogic_U.ShiftDownrequest = localArgInput;
}

// Root inport: '<Root>/Reset Count' set method
void ShiftingLogic::setReset_Count(uint8_T localArgInput)
{
  ShiftingLogic_U.ResetCount = localArgInput;
}

// Root inport: '<Root>/Max Gear UP' set method
void ShiftingLogic::setMax_Gear_UP(uint8_T localArgInput)
{
  ShiftingLogic_U.MaxGearUP = localArgInput;
}

// Root inport: '<Root>/Max Gear Down' set method
void ShiftingLogic::setMax_Gear_Down(uint8_T localArgInput)
{
  ShiftingLogic_U.MaxGearDown = localArgInput;
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
