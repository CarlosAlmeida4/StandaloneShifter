//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ScreenControl.cpp
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
#include "ScreenControl.h"
#include <cmath>
#include "rtwtypes.h"

// Model step function
void ScreenControl::step()
{
  real_T tmp;
  int16_T i;

  // Outputs for Atomic SubSystem: '<Root>/ScreenControl'
  // MultiPortSwitch: '<S1>/Index Vector' incorporates:
  //   Inport: '<Root>/Inport'

  switch (ScreenControl_U.Inport) {
   case 0L:
    // Outport: '<Root>/Outport' incorporates:
    //   Constant: '<S1>/Constant10'

    for (i = 0; i < 8; i++) {
      tmp = std::floor(ScreenControl_ConstP.pooled1[i]);
      if (std::isnan(tmp) || std::isinf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = std::fmod(tmp, 256.0);
      }

      ScreenControl_Y.Outport[i] = static_cast<uint8_T>(tmp < 0.0 ? static_cast<
        int16_T>(static_cast<uint8_T>(-static_cast<int8_T>(static_cast<uint8_T>(
        -tmp)))) : static_cast<int16_T>(static_cast<uint8_T>(tmp)));
    }
    break;

   case 1L:
    // Outport: '<Root>/Outport' incorporates:
    //   Constant: '<S1>/Constant1'

    for (i = 0; i < 8; i++) {
      tmp = std::floor(ScreenControl_ConstP.Constant1_Value[i]);
      if (std::isnan(tmp) || std::isinf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = std::fmod(tmp, 256.0);
      }

      ScreenControl_Y.Outport[i] = static_cast<uint8_T>(tmp < 0.0 ?
        static_cast<int16_T>(static_cast<uint8_T>(-static_cast<int8_T>(
        static_cast<uint8_T>(-tmp)))) : static_cast<int16_T>(static_cast<uint8_T>
        (tmp)));
    }
    break;

   case 2L:
    // Outport: '<Root>/Outport' incorporates:
    //   Constant: '<S1>/Constant'

    for (i = 0; i < 8; i++) {
      tmp = std::floor(ScreenControl_ConstP.Constant_Value[i]);
      if (std::isnan(tmp) || std::isinf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = std::fmod(tmp, 256.0);
      }

      ScreenControl_Y.Outport[i] = static_cast<uint8_T>(tmp < 0.0 ? static_cast<
        int16_T>(static_cast<uint8_T>(-static_cast<int8_T>(static_cast<uint8_T>(
        -tmp)))) : static_cast<int16_T>(static_cast<uint8_T>(tmp)));
    }
    break;

   case 3L:
    // Outport: '<Root>/Outport' incorporates:
    //   Constant: '<S1>/Constant2'

    for (i = 0; i < 8; i++) {
      tmp = std::floor(ScreenControl_ConstP.Constant2_Value[i]);
      if (std::isnan(tmp) || std::isinf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = std::fmod(tmp, 256.0);
      }

      ScreenControl_Y.Outport[i] = static_cast<uint8_T>(tmp < 0.0 ?
        static_cast<int16_T>(static_cast<uint8_T>(-static_cast<int8_T>(
        static_cast<uint8_T>(-tmp)))) : static_cast<int16_T>(static_cast<uint8_T>
        (tmp)));
    }
    break;

   case 4L:
    // Outport: '<Root>/Outport' incorporates:
    //   Constant: '<S1>/Constant3'

    for (i = 0; i < 8; i++) {
      tmp = std::floor(ScreenControl_ConstP.Constant3_Value[i]);
      if (std::isnan(tmp) || std::isinf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = std::fmod(tmp, 256.0);
      }

      ScreenControl_Y.Outport[i] = static_cast<uint8_T>(tmp < 0.0 ? static_cast<
        int16_T>(static_cast<uint8_T>(-static_cast<int8_T>(static_cast<uint8_T>(
        -tmp)))) : static_cast<int16_T>(static_cast<uint8_T>(tmp)));
    }
    break;

   case 5L:
    // Outport: '<Root>/Outport' incorporates:
    //   Constant: '<S1>/Constant4'

    for (i = 0; i < 8; i++) {
      tmp = std::floor(ScreenControl_ConstP.Constant4_Value[i]);
      if (std::isnan(tmp) || std::isinf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = std::fmod(tmp, 256.0);
      }

      ScreenControl_Y.Outport[i] = static_cast<uint8_T>(tmp < 0.0 ?
        static_cast<int16_T>(static_cast<uint8_T>(-static_cast<int8_T>(
        static_cast<uint8_T>(-tmp)))) : static_cast<int16_T>(static_cast<uint8_T>
        (tmp)));
    }
    break;

   case 6L:
    // Outport: '<Root>/Outport' incorporates:
    //   Constant: '<S1>/Constant5'

    for (i = 0; i < 8; i++) {
      tmp = std::floor(ScreenControl_ConstP.Constant5_Value[i]);
      if (std::isnan(tmp) || std::isinf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = std::fmod(tmp, 256.0);
      }

      ScreenControl_Y.Outport[i] = static_cast<uint8_T>(tmp < 0.0 ? static_cast<
        int16_T>(static_cast<uint8_T>(-static_cast<int8_T>(static_cast<uint8_T>(
        -tmp)))) : static_cast<int16_T>(static_cast<uint8_T>(tmp)));
    }
    break;

   case 7L:
    // Outport: '<Root>/Outport' incorporates:
    //   Constant: '<S1>/Constant6'

    for (i = 0; i < 8; i++) {
      tmp = std::floor(ScreenControl_ConstP.Constant6_Value[i]);
      if (std::isnan(tmp) || std::isinf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = std::fmod(tmp, 256.0);
      }

      ScreenControl_Y.Outport[i] = static_cast<uint8_T>(tmp < 0.0 ?
        static_cast<int16_T>(static_cast<uint8_T>(-static_cast<int8_T>(
        static_cast<uint8_T>(-tmp)))) : static_cast<int16_T>(static_cast<uint8_T>
        (tmp)));
    }
    break;

   case 8L:
    // Outport: '<Root>/Outport' incorporates:
    //   Constant: '<S1>/Constant7'

    for (i = 0; i < 8; i++) {
      tmp = std::floor(ScreenControl_ConstP.Constant7_Value[i]);
      if (std::isnan(tmp) || std::isinf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = std::fmod(tmp, 256.0);
      }

      ScreenControl_Y.Outport[i] = static_cast<uint8_T>(tmp < 0.0 ? static_cast<
        int16_T>(static_cast<uint8_T>(-static_cast<int8_T>(static_cast<uint8_T>(
        -tmp)))) : static_cast<int16_T>(static_cast<uint8_T>(tmp)));
    }
    break;

   case 9L:
    // Outport: '<Root>/Outport' incorporates:
    //   Constant: '<S1>/Constant8'

    for (i = 0; i < 8; i++) {
      tmp = std::floor(ScreenControl_ConstP.Constant8_Value[i]);
      if (std::isnan(tmp) || std::isinf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = std::fmod(tmp, 256.0);
      }

      ScreenControl_Y.Outport[i] = static_cast<uint8_T>(tmp < 0.0 ?
        static_cast<int16_T>(static_cast<uint8_T>(-static_cast<int8_T>(
        static_cast<uint8_T>(-tmp)))) : static_cast<int16_T>(static_cast<uint8_T>
        (tmp)));
    }
    break;

   case -1L:
    // Outport: '<Root>/Outport' incorporates:
    //   Constant: '<S1>/Constant9'

    for (i = 0; i < 8; i++) {
      tmp = std::floor(ScreenControl_ConstP.Constant9_Value[i]);
      if (std::isnan(tmp) || std::isinf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = std::fmod(tmp, 256.0);
      }

      ScreenControl_Y.Outport[i] = static_cast<uint8_T>(tmp < 0.0 ? static_cast<
        int16_T>(static_cast<uint8_T>(-static_cast<int8_T>(static_cast<uint8_T>(
        -tmp)))) : static_cast<int16_T>(static_cast<uint8_T>(tmp)));
    }
    break;

   default:
    // Outport: '<Root>/Outport' incorporates:
    //   Constant: '<S1>/Constant11'

    for (i = 0; i < 8; i++) {
      tmp = std::floor(ScreenControl_ConstP.pooled1[i]);
      if (std::isnan(tmp) || std::isinf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = std::fmod(tmp, 256.0);
      }

      ScreenControl_Y.Outport[i] = static_cast<uint8_T>(tmp < 0.0 ?
        static_cast<int16_T>(static_cast<uint8_T>(-static_cast<int8_T>(
        static_cast<uint8_T>(-tmp)))) : static_cast<int16_T>(static_cast<uint8_T>
        (tmp)));
    }
    break;
  }

  // End of MultiPortSwitch: '<S1>/Index Vector'
  // End of Outputs for SubSystem: '<Root>/ScreenControl'
}

// Model initialize function
void ScreenControl::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void ScreenControl::terminate()
{
  // (no terminate code required)
}

// Root inport: '<Root>/Inport' set method
void ScreenControl::setInport(int8_T localArgInput)
{
  ScreenControl_U.Inport = localArgInput;
}

// Constructor
ScreenControl::ScreenControl() :
  ScreenControl_U(),
  ScreenControl_Y(),
  ScreenControl_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
ScreenControl::~ScreenControl() = default;

// Real-Time Model get method
ScreenControl::RT_MODEL_ScreenControl_T * ScreenControl::getRTM()
{
  return (&ScreenControl_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
