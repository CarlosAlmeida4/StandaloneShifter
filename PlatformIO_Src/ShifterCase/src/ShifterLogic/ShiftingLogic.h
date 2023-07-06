//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ShiftingLogic.h
//
// Code generated for Simulink model 'ShiftingLogic'.
//
// Model version                  : 2.0
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Fri Jul  7 00:09:03 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Atmel->AVR
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ShiftingLogic_h_
#define RTW_HEADER_ShiftingLogic_h_
#include "rtwtypes.h"

#include "ShiftingLogic_types.h"

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
    real_T Switch;                     // '<S4>/Switch'
    real_T Switch1;                    // '<S4>/Switch1'
    real_T Switch1_c;                  // '<S8>/Switch1'
    real_T Switch_n;                   // '<S8>/Switch'
    real_T RequestedGear;              // '<S3>/Add'
    real_T Saturation;                 // '<S10>/Saturation'
    real_T Switch_h;                   // '<S14>/Switch'
    uint8_T Cast;                      // '<S2>/Cast'
    uint8_T Cast1;                     // '<S2>/Cast1'
    uint8_T MaxGearMemory;             // '<S2>/Max Gear Memory'
    uint8_T MaxGear;                   // '<S2>/Add'
    uint8_T Saturation_m;              // '<S2>/Saturation'
    uint8_T Cast_i;                    // '<S9>/Cast'
    uint8_T Cast1_f;                   // '<S9>/Cast1'
    uint8_T Cast_k;                    // '<S5>/Cast'
    uint8_T Cast1_b;                   // '<S5>/Cast1'
    int8_T Switch_i;                   // '<S11>/Switch'
    boolean_T LogicalOperator;         // '<S4>/Logical Operator'
    boolean_T CastToBoolean;           // '<S5>/Cast To Boolean'
    boolean_T Delay;                   // '<S6>/Delay'
    boolean_T CastToBoolean1;          // '<S5>/Cast To Boolean1'
    boolean_T Delay_a;                 // '<S7>/Delay'
    boolean_T CastToBoolean_f;         // '<S9>/Cast To Boolean'
    boolean_T Delay_g;                 // '<S12>/Delay'
    boolean_T CastToBoolean1_p;        // '<S9>/Cast To Boolean1'
    boolean_T Delay_n;                 // '<S13>/Delay'
    boolean_T LogicalOperator_m;       // '<S8>/Logical Operator'
    boolean_T RelationalOperator;      // '<S14>/Relational Operator'
    boolean_T LogicalOperator_o;       // '<S12>/Logical Operator'
    boolean_T LogicalOperator1;        // '<S12>/Logical Operator1'
    boolean_T LogicalOperator_i;       // '<S13>/Logical Operator'
    boolean_T LogicalOperator1_o;      // '<S13>/Logical Operator1'
    boolean_T LogicalOperator_e;       // '<S6>/Logical Operator'
    boolean_T LogicalOperator1_k;      // '<S6>/Logical Operator1'
    boolean_T LogicalOperator_op;      // '<S7>/Logical Operator'
    boolean_T LogicalOperator1_d;      // '<S7>/Logical Operator1'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_ShiftingLogic_T {
    real_T Add_DWORK1;                 // '<S3>/Add'
    int8_T CurrentGearMemory_DSTATE;   // '<S3>/Current Gear Memory'
    uint8_T MaxGearMemory_DSTATE;      // '<S2>/Max Gear Memory'
    boolean_T Delay_DSTATE;            // '<S6>/Delay'
    boolean_T Delay_DSTATE_d;          // '<S7>/Delay'
    boolean_T Delay_DSTATE_m;          // '<S12>/Delay'
    boolean_T Delay_DSTATE_l;          // '<S13>/Delay'
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_ShiftingLogic_T {
    uint8_T ShiftUprequest;            // '<Root>/Shift Up request'
    uint8_T ShiftDownrequest;          // '<Root>/Shift Down request'
    uint8_T ResetCount;                // '<Root>/Reset Count'
    uint8_T MaxGearUP;                 // '<Root>/Max Gear UP'
    uint8_T MaxGearDown;               // '<Root>/Max Gear Down'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_ShiftingLogic_T {
    int8_T CurrentGear;                // '<Root>/Current Gear'
  };

  // Parameters (default storage)
  struct P_ShiftingLogic_T {
    real_T AbsoluteMaxGear;            // Variable: AbsoluteMaxGear
                                          //  Referenced by: '<S10>/Saturation'

    real_T Constant2_Value;            // Expression: 0
                                          //  Referenced by: '<S4>/Constant2'

    real_T Constant1_Value;            // Expression: 0
                                          //  Referenced by: '<S4>/Constant1'

    real_T Constant_Value;             // Expression: 0
                                          //  Referenced by: '<S11>/Constant'

    real_T Constant2_Value_n;          // Expression: 0
                                          //  Referenced by: '<S8>/Constant2'

    real_T Constant1_Value_b;          // Expression: 0
                                          //  Referenced by: '<S8>/Constant1'

    real_T Saturation_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S10>/Saturation'

    boolean_T Delay_InitialCondition;
                                   // Computed Parameter: Delay_InitialCondition
                                      //  Referenced by: '<S12>/Delay'

    boolean_T Delay_InitialCondition_i;
                                 // Computed Parameter: Delay_InitialCondition_i
                                    //  Referenced by: '<S13>/Delay'

    boolean_T Delay_InitialCondition_c;
                                 // Computed Parameter: Delay_InitialCondition_c
                                    //  Referenced by: '<S6>/Delay'

    boolean_T Delay_InitialCondition_h;
                                 // Computed Parameter: Delay_InitialCondition_h
                                    //  Referenced by: '<S7>/Delay'

    int8_T CurrentGearMemory_InitialCondit;
                          // Computed Parameter: CurrentGearMemory_InitialCondit
                             //  Referenced by: '<S3>/Current Gear Memory'

    uint8_T Switch_Threshold;          // Computed Parameter: Switch_Threshold
                                          //  Referenced by: '<S11>/Switch'

    uint8_T MaxGearMemory_InitialCondition;
                           // Computed Parameter: MaxGearMemory_InitialCondition
                              //  Referenced by: '<S2>/Max Gear Memory'

    uint8_T Saturation_UpperSat;      // Computed Parameter: Saturation_UpperSat
                                         //  Referenced by: '<S2>/Saturation'

    uint8_T Saturation_LowerSat_o;  // Computed Parameter: Saturation_LowerSat_o
                                       //  Referenced by: '<S2>/Saturation'

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

  // Root inport: '<Root>/Shift Up request' set method
  void setShift_Up_request(uint8_T localArgInput);

  // Root inport: '<Root>/Shift Down request' set method
  void setShift_Down_request(uint8_T localArgInput);

  // Root inport: '<Root>/Reset Count' set method
  void setReset_Count(uint8_T localArgInput);

  // Root inport: '<Root>/Max Gear UP' set method
  void setMax_Gear_UP(uint8_T localArgInput);

  // Root inport: '<Root>/Max Gear Down' set method
  void setMax_Gear_Down(uint8_T localArgInput);

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
  // External outputs
  ExtY_ShiftingLogic_T ShiftingLogic_Y;

  // Block signals
  B_ShiftingLogic_T ShiftingLogic_B;
  public:
  // Block states
  DW_ShiftingLogic_T ShiftingLogic_DW;
  private:
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
//  hilite_system('ShifterLogic/ShiftingLogic/ShiftingLogic')    - opens subsystem ShifterLogic/ShiftingLogic/ShiftingLogic
//  hilite_system('ShifterLogic/ShiftingLogic/ShiftingLogic/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'ShifterLogic/ShiftingLogic'
//  '<S1>'   : 'ShifterLogic/ShiftingLogic/ShiftingLogic'
//  '<S2>'   : 'ShifterLogic/ShiftingLogic/ShiftingLogic/Max Gear Logic'
//  '<S3>'   : 'ShifterLogic/ShiftingLogic/ShiftingLogic/ShiftingLogic'
//  '<S4>'   : 'ShifterLogic/ShiftingLogic/ShiftingLogic/Max Gear Logic/Double Input Prevention'
//  '<S5>'   : 'ShifterLogic/ShiftingLogic/ShiftingLogic/Max Gear Logic/Edge Detection'
//  '<S6>'   : 'ShifterLogic/ShiftingLogic/ShiftingLogic/Max Gear Logic/Edge Detection/Edge Detection'
//  '<S7>'   : 'ShifterLogic/ShiftingLogic/ShiftingLogic/Max Gear Logic/Edge Detection/Edge Detection1'
//  '<S8>'   : 'ShifterLogic/ShiftingLogic/ShiftingLogic/ShiftingLogic/Double Input Prevention'
//  '<S9>'   : 'ShifterLogic/ShiftingLogic/ShiftingLogic/ShiftingLogic/Edge Detection'
//  '<S10>'  : 'ShifterLogic/ShiftingLogic/ShiftingLogic/ShiftingLogic/Gear Limit Check Logic'
//  '<S11>'  : 'ShifterLogic/ShiftingLogic/ShiftingLogic/ShiftingLogic/Reset'
//  '<S12>'  : 'ShifterLogic/ShiftingLogic/ShiftingLogic/ShiftingLogic/Edge Detection/Edge Detection'
//  '<S13>'  : 'ShifterLogic/ShiftingLogic/ShiftingLogic/ShiftingLogic/Edge Detection/Edge Detection1'
//  '<S14>'  : 'ShifterLogic/ShiftingLogic/ShiftingLogic/ShiftingLogic/Gear Limit Check Logic/Max Gear Limit Logic'

#endif                                 // RTW_HEADER_ShiftingLogic_h_

//
// File trailer for generated code.
//
// [EOF]
//
