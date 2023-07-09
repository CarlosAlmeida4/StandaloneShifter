//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ScreenControl.h
//
// Code generated for Simulink model 'ScreenControl'.
//
// Model version                  : 1.10
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Sun Jul  9 17:49:39 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Atmel->AVR
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ScreenControl_h_
#define RTW_HEADER_ScreenControl_h_
#include "rtwtypes.h"
#include "ScreenControl_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model ScreenControl
class ScreenControl final
{
  // public data and function members
 public:
  // Constant parameters (default storage)
  struct ConstP_ScreenControl_T {
    // Expression: Display2ndGear
    //  Referenced by: '<S1>/Constant'

    real_T Constant_Value[8];

    // Expression: Display1stGear
    //  Referenced by: '<S1>/Constant1'

    real_T Constant1_Value[8];

    // Pooled Parameter (Expression: DisplayNGear)
    //  Referenced by:
    //    '<S1>/Constant10'
    //    '<S1>/Constant11'

    real_T pooled1[8];

    // Expression: Display3rdGear
    //  Referenced by: '<S1>/Constant2'

    real_T Constant2_Value[8];

    // Expression: Display4thGear
    //  Referenced by: '<S1>/Constant3'

    real_T Constant3_Value[8];

    // Expression: Display5thGear
    //  Referenced by: '<S1>/Constant4'

    real_T Constant4_Value[8];

    // Expression: Display6thGear
    //  Referenced by: '<S1>/Constant5'

    real_T Constant5_Value[8];

    // Expression: Display7thGear
    //  Referenced by: '<S1>/Constant6'

    real_T Constant6_Value[8];

    // Expression: Display8thGear
    //  Referenced by: '<S1>/Constant7'

    real_T Constant7_Value[8];

    // Expression: Display9thGear
    //  Referenced by: '<S1>/Constant8'

    real_T Constant8_Value[8];

    // Expression: DisplayRGear
    //  Referenced by: '<S1>/Constant9'

    real_T Constant9_Value[8];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_ScreenControl_T {
    int8_T Inport;                     // '<Root>/Inport'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_ScreenControl_T {
    uint8_T Outport[8];                // '<Root>/Outport'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_ScreenControl_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  ScreenControl(ScreenControl const&) = delete;

  // Assignment Operator
  ScreenControl& operator= (ScreenControl const&) & = delete;

  // Move Constructor
  ScreenControl(ScreenControl &&) = delete;

  // Move Assignment Operator
  ScreenControl& operator= (ScreenControl &&) = delete;

  // Real-Time Model get method
  ScreenControl::RT_MODEL_ScreenControl_T * getRTM();

  // External inputs
  ExtU_ScreenControl_T ScreenControl_U;

  // External outputs
  ExtY_ScreenControl_T ScreenControl_Y;

  // Root inport: '<Root>/Inport' set method
  void setInport(int8_T localArgInput);

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  ScreenControl();

  // Destructor
  ~ScreenControl();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL_ScreenControl_T ScreenControl_M;
};

// Constant parameters (default storage)
extern const ScreenControl::ConstP_ScreenControl_T ScreenControl_ConstP;

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'ScreenControl'
//  '<S1>'   : 'ScreenControl/ScreenControl'

#endif                                 // RTW_HEADER_ScreenControl_h_

//
// File trailer for generated code.
//
// [EOF]
//
