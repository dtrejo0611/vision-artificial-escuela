/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PRACTICA2.h
 *
 * Code generated for Simulink model 'PRACTICA2'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Feb 27 16:44:04 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef PRACTICA2_h_
#define PRACTICA2_h_
#ifndef PRACTICA2_COMMON_INCLUDES_
#define PRACTICA2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#endif                                 /* PRACTICA2_COMMON_INCLUDES_ */

#include "PRACTICA2_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include <math.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Gain6;                        /* '<Root>/Gain6' */
  real_T Gain3;                        /* '<Root>/Gain3' */
  real_T Gain4;                        /* '<Root>/Gain4' */
  real_T Gain2;                        /* '<Root>/Gain2' */
  uint32_T Gain;                       /* '<Root>/Gain' */
  uint32_T Gain5;                      /* '<Root>/Gain5' */
  uint16_T AnalogInput1;               /* '<Root>/Analog Input1' */
} B_PRACTICA2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_f;/* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_h;/* '<Root>/Digital Input' */
  codertarget_arduinobase_blo_p_T obj_h0;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_blo_p_T obj_l;/* '<Root>/Digital Output' */
  codertarget_arduinobase_int_p_T obj_o;/* '<Root>/Encoder' */
  codertarget_arduinobase_in_p0_T obj_hn;/* '<Root>/PWM' */
  real_T TimeStampA;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative' */
  real_T TimeStampB;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */
} DW_PRACTICA2_T;

/* Parameters (default storage) */
struct P_PRACTICA2_T_ {
  real_T Constant_Value;               /* Expression: 2.471
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain6_Gain;                   /* Expression: 1/0.185
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1/44
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 60/20.4
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: pi/30
                                        * Referenced by: '<Root>/Gain4'
                                        */
  uint32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  uint16_T Gain5_Gain;                 /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<Root>/Gain5'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PRACTICA2_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_PRACTICA2_T PRACTICA2_P;

/* Block signals (default storage) */
extern B_PRACTICA2_T PRACTICA2_B;

/* Block states (default storage) */
extern DW_PRACTICA2_T PRACTICA2_DW;

/* External function called from main */
extern void PRACTICA2_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void PRACTICA2_initialize(void);
extern void PRACTICA2_step0(void);     /* Sample time: [0.0s, 0.0s] */
extern void PRACTICA2_step2(void);     /* Sample time: [0.1s, 0.0s] */
extern void PRACTICA2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PRACTICA2_T *const PRACTICA2_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PRACTICA2'
 */
#endif                                 /* PRACTICA2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
