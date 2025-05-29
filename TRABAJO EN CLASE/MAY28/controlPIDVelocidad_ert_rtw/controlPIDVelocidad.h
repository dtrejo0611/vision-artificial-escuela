/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controlPIDVelocidad.h
 *
 * Code generated for Simulink model 'controlPIDVelocidad'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu May 29 13:55:34 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef controlPIDVelocidad_h_
#define controlPIDVelocidad_h_
#ifndef controlPIDVelocidad_COMMON_INCLUDES_
#define controlPIDVelocidad_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#endif                                /* controlPIDVelocidad_COMMON_INCLUDES_ */

#include "controlPIDVelocidad_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
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

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Probe[2];                     /* '<S4>/Probe' */
  real_T Velocidadmedida;              /* '<Root>/Gain5' */
  real_T Referencia;                   /* '<Root>/Gain1' */
  real_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1' */
  real_T Saturation;                   /* '<S10>/Saturation' */
  real_T u;                            /* '<Root>/MATLAB Function1' */
  real_T gip;                          /* '<Root>/MATLAB Function1' */
  real_T Gain;                         /* '<Root>/Gain' */
} B_controlPIDVelocidad_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_j;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_block_T obj_jn;/* '<Root>/Digital Output' */
  codertarget_arduinobase_int_o_T obj_l;/* '<Root>/Encoder' */
  codertarget_arduinobase_in_ob_T obj_b;/* '<Root>/PWM' */
  real_T Integrator_DSTATE;            /* '<S10>/Integrator' */
  real_T TimeStampA;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative' */
  real_T TimeStampB;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative' */
  struct {
    void *LoggedData;
  } Velocidad_PWORK;                   /* '<Root>/Velocidad' */

  struct {
    void *LoggedData;
  } Voltaje_PWORK;                     /* '<Root>/Voltaje' */

  struct {
    void *LoggedData;
  } Corriente_PWORK;                   /* '<Root>/Corriente' */

  int8_T Integrator_PrevResetState;    /* '<S10>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S10>/Integrator' */
} DW_controlPIDVelocidad_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
} X_controlPIDVelocidad_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
} XDot_controlPIDVelocidad_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
} XDis_controlPIDVelocidad_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_controlPIDVelocidad_T_ {
  real_T LowPassFilterDiscreteorContinuo;
                              /* Mask Parameter: LowPassFilterDiscreteorContinuo
                               * Referenced by: '<S1>/K'
                               */
  real_T LowPassFilterDiscreteorContin_f;
                              /* Mask Parameter: LowPassFilterDiscreteorContin_f
                               * Referenced by: '<S4>/Time constant'
                               */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S7>/Constant'
                                       */
  real_T LowPassFilterDiscreteorContin_c;
                              /* Mask Parameter: LowPassFilterDiscreteorContin_c
                               * Referenced by: '<S4>/Constant'
                               */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/44
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain4_Gain;                   /* Expression: 60/20.4
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T Gain5_Gain;                   /* Expression: pi/30
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T VelocidadenRPM_Value;         /* Expression: 150
                                        * Referenced by: '<Root>/Velocidad en RPM'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/30
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Constant2_Value;              /* Expression: 2.45
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 2.6
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S10>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S10>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S10>/Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: windupUpperLimit
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: windupLowerLimit
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  uint16_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<Root>/Gain2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_controlPIDVelocidad_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_controlPIDVelocidad_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_controlPIDVelocidad_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[1];
  real_T odeF[3][1];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
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
    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_controlPIDVelocidad_T controlPIDVelocidad_P;

/* Block signals (default storage) */
extern B_controlPIDVelocidad_T controlPIDVelocidad_B;

/* Continuous states (default storage) */
extern X_controlPIDVelocidad_T controlPIDVelocidad_X;

/* Disabled states (default storage) */
extern XDis_controlPIDVelocidad_T controlPIDVelocidad_XDis;

/* Block states (default storage) */
extern DW_controlPIDVelocidad_T controlPIDVelocidad_DW;

/* Model entry point functions */
extern void controlPIDVelocidad_initialize(void);
extern void controlPIDVelocidad_step(void);
extern void controlPIDVelocidad_terminate(void);

/* Real-time Model object */
extern RT_MODEL_controlPIDVelocidad_T *const controlPIDVelocidad_M;
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
 * '<Root>' : 'controlPIDVelocidad'
 * '<S1>'   : 'controlPIDVelocidad/Low-Pass Filter (Discrete or Continuous)'
 * '<S2>'   : 'controlPIDVelocidad/MATLAB Function1'
 * '<S3>'   : 'controlPIDVelocidad/MATLAB Function2'
 * '<S4>'   : 'controlPIDVelocidad/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S5>'   : 'controlPIDVelocidad/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S6>'   : 'controlPIDVelocidad/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S7>'   : 'controlPIDVelocidad/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Constant'
 * '<S8>'   : 'controlPIDVelocidad/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S9>'   : 'controlPIDVelocidad/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S10>'  : 'controlPIDVelocidad/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 */
#endif                                 /* controlPIDVelocidad_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
