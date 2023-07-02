//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ShiftingLogic_data.cpp
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

// Block parameters (default storage)
ShiftingLogic::P_ShiftingLogic_T ShiftingLogic::ShiftingLogic_P{
  // Variable: AbsoluteMaxGear
  //  Referenced by: '<S11>/Saturation'

  30.0,

  // Expression: 0
  //  Referenced by: '<S5>/Constant2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S5>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S12>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S9>/Constant2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S9>/Constant1'

  0.0,

  // Expression: -1
  //  Referenced by: '<S11>/Saturation'

  -1.0,

  // Computed Parameter: Delay_InitialCondition
  //  Referenced by: '<S13>/Delay'

  true,

  // Computed Parameter: Delay_InitialCondition_i
  //  Referenced by: '<S14>/Delay'

  true,

  // Computed Parameter: Delay_InitialCondition_c
  //  Referenced by: '<S7>/Delay'

  true,

  // Computed Parameter: Delay_InitialCondition_h
  //  Referenced by: '<S8>/Delay'

  true,

  // Computed Parameter: CurrentGearMemory_InitialCondit
  //  Referenced by: '<S4>/Current Gear Memory'

  0,

  // Computed Parameter: Switch_Threshold
  //  Referenced by: '<S12>/Switch'

  0U,

  // Computed Parameter: MaxGearMemory_InitialCondition
  //  Referenced by: '<S3>/Max Gear Memory'

  0U,

  // Computed Parameter: Saturation_UpperSat
  //  Referenced by: '<S3>/Saturation'

  20U,

  // Computed Parameter: Saturation_LowerSat_o
  //  Referenced by: '<S3>/Saturation'

  1U
};

//
// File trailer for generated code.
//
// [EOF]
//
