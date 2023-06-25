//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ShiftingLogic.h
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
#ifndef RTW_HEADER_ShiftingLogic_h_
#define RTW_HEADER_ShiftingLogic_h_
#include "ShifterLogic\rtwtypes.h"
//#include "rtw_continuous.h"
//#include "rtw_solver.h"
#include "ShifterLogic\ShiftingLogic_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model ShiftingLogic
class ShiftingLogic final
{
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_ShiftingLogic_T {
    real_T Switch1;                    // '<S2>/Switch1'
    real_T Switch;                     // '<S2>/Switch'
    real_T RequestedGear;              // '<S1>/Add'
    real_T Saturation;                 // '<S4>/Saturation'
    real_T Switch_h;                   // '<S8>/Switch'
    uint8_T Cast;                      // '<S3>/Cast'
    uint8_T Cast1;                     // '<S3>/Cast1'
    int8_T Switch_i;                   // '<S5>/Switch'
    boolean_T CastToBoolean;           // '<S3>/Cast To Boolean'
    boolean_T Delay;                   // '<S6>/Delay'
    boolean_T CastToBoolean1;          // '<S3>/Cast To Boolean1'
    boolean_T Delay_n;                 // '<S7>/Delay'
    boolean_T LogicalOperator;         // '<S2>/Logical Operator'
    boolean_T RelationalOperator;      // '<S8>/Relational Operator'
    boolean_T LogicalOperator_o;       // '<S6>/Logical Operator'
    boolean_T LogicalOperator1;        // '<S6>/Logical Operator1'
    boolean_T LogicalOperator_i;       // '<S7>/Logical Operator'
    boolean_T LogicalOperator1_o;      // '<S7>/Logical Operator1'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_ShiftingLogic_T {
    real_T Add_DWORK1;                 // '<S1>/Add'
    int8_T CurrentGearMemory_DSTATE;   // '<S1>/Current Gear Memory'
    boolean_T Delay_DSTATE;            // '<S6>/Delay'
    boolean_T Delay_DSTATE_l;          // '<S7>/Delay'
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_ShiftingLogic_T {
    uint8_T MaxGearLimit;              // '<Root>/Max Gear Limit'
    uint8_T ShiftUPrequest;            // '<Root>/Shift UP request'
    uint8_T Shiftdownrequest;          // '<Root>/Shift down request'
    uint8_T ResetCount;                // '<Root>/Reset Count'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_ShiftingLogic_T {
    int8_T CurrentGear;                // '<Root>/Current Gear'
  };

  // Parameters (default storage)
  struct P_ShiftingLogic_T {
    real_T AbsoluteMaxGear;            // Variable: AbsoluteMaxGear
                                          //  Referenced by: '<S4>/Saturation'

    real_T Constant_Value;             // Expression: 0
                                          //  Referenced by: '<S5>/Constant'

    real_T Constant2_Value;            // Expression: 0
                                          //  Referenced by: '<S2>/Constant2'

    real_T Constant1_Value;            // Expression: 0
                                          //  Referenced by: '<S2>/Constant1'

    real_T Saturation_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S4>/Saturation'

    boolean_T Delay_InitialCondition;
                                   // Computed Parameter: Delay_InitialCondition
                                      //  Referenced by: '<S6>/Delay'

    boolean_T Delay_InitialCondition_i;
                                 // Computed Parameter: Delay_InitialCondition_i
                                    //  Referenced by: '<S7>/Delay'

    int8_T CurrentGearMemory_InitialCondit;
                          // Computed Parameter: CurrentGearMemory_InitialCondit
                             //  Referenced by: '<S1>/Current Gear Memory'

    uint8_T Switch_Threshold;          // Computed Parameter: Switch_Threshold
                                          //  Referenced by: '<S5>/Switch'

  };

  // Real-time Model Data Structure
  struct RT_MODEL_ShiftingLogic_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  ShiftingLogic(ShiftingLogic const&) = delete;

  // Assignment Operator
  ShiftingLogic& operator= (ShiftingLogic const&) & = delete;

  // Move Constructor
  ShiftingLogic(ShiftingLogic &&) = delete;

  // Move Assignment Operator
  ShiftingLogic& operator= (ShiftingLogic &&) = delete;

  // Real-Time Model get method
  ShiftingLogic::RT_MODEL_ShiftingLogic_T * getRTM();

  // External inputs
  ExtU_ShiftingLogic_T ShiftingLogic_U;

  // External outputs
  ExtY_ShiftingLogic_T ShiftingLogic_Y;

  // Root inport: '<Root>/Max Gear Limit' set method
  void setMax_Gear_Limit(uint8_T localArgInput);

  // Root inport: '<Root>/Shift UP request' set method
  void setShift_UP_request(uint8_T localArgInput);

  // Root inport: '<Root>/Shift down request' set method
  void setShift_down_request(uint8_T localArgInput);

  // Root inport: '<Root>/Reset Count' set method
  void setReset_Count(uint8_T localArgInput);

  // Root outport: '<Root>/Current Gear' get method
  int8_T getCurrent_Gear() const;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  ShiftingLogic();

  // Destructor
  ~ShiftingLogic();

  // private data and function members
 private:
  // Block signals
  B_ShiftingLogic_T ShiftingLogic_B;

  // Block states
  DW_ShiftingLogic_T ShiftingLogic_DW;

  // Tunable parameters
  static P_ShiftingLogic_T ShiftingLogic_P;

  // Real-Time Model
  RT_MODEL_ShiftingLogic_T ShiftingLogic_M;
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Note that this particular code originates from a subsystem build,
//  and has its own system numbers different from the parent model.
//  Refer to the system hierarchy for this subsystem below, and use the
//  MATLAB hilite_system command to trace the generated code back
//  to the parent model.  For example,
//
//  hilite_system('ShifterLogic/ShiftingLogic')    - opens subsystem ShifterLogic/ShiftingLogic
//  hilite_system('ShifterLogic/ShiftingLogic/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'ShifterLogic'
//  '<S1>'   : 'ShifterLogic/ShiftingLogic'
//  '<S2>'   : 'ShifterLogic/ShiftingLogic/Double Input Prevention'
//  '<S3>'   : 'ShifterLogic/ShiftingLogic/Edge Detection'
//  '<S4>'   : 'ShifterLogic/ShiftingLogic/Gear Limit Check Logic'
//  '<S5>'   : 'ShifterLogic/ShiftingLogic/Reset'
//  '<S6>'   : 'ShifterLogic/ShiftingLogic/Edge Detection/Edge Detection'
//  '<S7>'   : 'ShifterLogic/ShiftingLogic/Edge Detection/Edge Detection1'
//  '<S8>'   : 'ShifterLogic/ShiftingLogic/Gear Limit Check Logic/Max Gear Limit Logic'

#endif                                 // RTW_HEADER_ShiftingLogic_h_

//
// File trailer for generated code.
//
// [EOF]
//
