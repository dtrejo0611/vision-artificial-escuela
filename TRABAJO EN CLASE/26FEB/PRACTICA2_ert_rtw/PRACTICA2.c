/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PRACTICA2.c
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

#include "PRACTICA2.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "PRACTICA2_private.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_PRACTICA2_T PRACTICA2_B;

/* Block states (default storage) */
DW_PRACTICA2_T PRACTICA2_DW;

/* Real-time model */
static RT_MODEL_PRACTICA2_T PRACTICA2_M_;
RT_MODEL_PRACTICA2_T *const PRACTICA2_M = &PRACTICA2_M_;
static void rate_monotonic_scheduler(void);
real_T uMultiWord2Double(const uint32_T u1[], int16_T n1, int16_T e1)
{
  real_T y;
  int16_T exp_0;
  int16_T i;
  y = 0.0;
  exp_0 = e1;
  for (i = 0; i < n1; i++) {
    y += ldexp(u1[i], exp_0);
    exp_0 += 32;
  }

  return y;
}

void uMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T ni;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      b1 = u1i >> 16U;
      u1i &= 65535UL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void PRACTICA2_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(PRACTICA2_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (PRACTICA2_M->Timing.TaskCounters.TID[2])++;
  if ((PRACTICA2_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.1s, 0.0s] */
    PRACTICA2_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model step function for TID0 */
void PRACTICA2_step0(void)             /* Sample time: [0.0s, 0.0s] */
{
  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  {
    uint64m_T tmp;
    real_T lastTime;
    real_T rtb_Derivative;
    real_T *lastU;
    int32_T rtb_Encoder_0;
    uint16_T b_varargout_1;

    /* MATLABSystem: '<Root>/Analog Input' */
    PRACTICA2_DW.obj_f.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
      MW_AnalogIn_GetHandle(15UL);
    MW_AnalogInSingle_ReadResult
      (PRACTICA2_DW.obj_f.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
       MW_ANALOGIN_UINT16);

    /* Gain: '<Root>/Gain' incorporates:
     *  MATLABSystem: '<Root>/Analog Input'
     * */
    PRACTICA2_B.Gain = (uint32_T)PRACTICA2_P.Gain_Gain * b_varargout_1;

    /* MATLABSystem: '<Root>/PWM' */
    PRACTICA2_DW.obj_hn.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

    /* Gain: '<Root>/Gain1' incorporates:
     *  Gain: '<Root>/Gain'
     */
    uMultiWordMul(&PRACTICA2_P.Gain1_Gain, 1, &PRACTICA2_B.Gain, 1, &tmp.chunks
                  [0U], 2);

    /* Start for MATLABSystem: '<Root>/PWM' */
    rtb_Derivative = uMultiWord2Double(&tmp.chunks[0U], 2, 0) *
      1.7763568394002505E-15;
    if (!(rtb_Derivative <= 255.0)) {
      rtb_Derivative = 255.0;
    }

    if (!(rtb_Derivative >= 0.0)) {
      rtb_Derivative = 0.0;
    }

    /* MATLABSystem: '<Root>/PWM' */
    MW_PWM_SetDutyCycle(PRACTICA2_DW.obj_hn.PWMDriverObj.MW_PWM_HANDLE,
                        rtb_Derivative);

    /* MATLABSystem: '<Root>/Analog Input1' */
    PRACTICA2_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
      MW_AnalogIn_GetHandle(18UL);

    /* MATLABSystem: '<Root>/Analog Input1' */
    MW_AnalogInSingle_ReadResult
      (PRACTICA2_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
       &PRACTICA2_B.AnalogInput1, MW_ANALOGIN_UINT16);

    /* Gain: '<Root>/Gain5' */
    PRACTICA2_B.Gain5 = (uint32_T)PRACTICA2_P.Gain5_Gain *
      PRACTICA2_B.AnalogInput1;

    /* Gain: '<Root>/Gain6' incorporates:
     *  Constant: '<Root>/Constant'
     *  Gain: '<Root>/Gain5'
     *  Sum: '<Root>/Sum'
     */
    PRACTICA2_B.Gain6 = ((real_T)PRACTICA2_B.Gain5 * 1.1920928955078125E-7 -
                         PRACTICA2_P.Constant_Value) * PRACTICA2_P.Gain6_Gain;

    /* MATLABSystem: '<Root>/Encoder' */
    if (PRACTICA2_DW.obj_o.TunablePropsChanged) {
      PRACTICA2_DW.obj_o.TunablePropsChanged = false;
    }

    MW_EncoderRead(PRACTICA2_DW.obj_o.Index, &rtb_Encoder_0);

    /* Gain: '<Root>/Gain2' incorporates:
     *  DataTypeConversion: '<Root>/Cast To Double'
     *  MATLABSystem: '<Root>/Encoder'
     */
    PRACTICA2_B.Gain2 = rtb_Encoder_0;
    PRACTICA2_B.Gain2 *= PRACTICA2_P.Gain2_Gain;

    /* Derivative: '<Root>/Derivative' */
    rtb_Derivative = PRACTICA2_M->Timing.t[0];
    if ((PRACTICA2_DW.TimeStampA >= rtb_Derivative) && (PRACTICA2_DW.TimeStampB >=
         rtb_Derivative)) {
      rtb_Derivative = 0.0;
    } else {
      lastTime = PRACTICA2_DW.TimeStampA;
      lastU = &PRACTICA2_DW.LastUAtTimeA;
      if (PRACTICA2_DW.TimeStampA < PRACTICA2_DW.TimeStampB) {
        if (PRACTICA2_DW.TimeStampB < rtb_Derivative) {
          lastTime = PRACTICA2_DW.TimeStampB;
          lastU = &PRACTICA2_DW.LastUAtTimeB;
        }
      } else if (PRACTICA2_DW.TimeStampA >= rtb_Derivative) {
        lastTime = PRACTICA2_DW.TimeStampB;
        lastU = &PRACTICA2_DW.LastUAtTimeB;
      }

      rtb_Derivative = (PRACTICA2_B.Gain2 - *lastU) / (rtb_Derivative - lastTime);
    }

    /* End of Derivative: '<Root>/Derivative' */

    /* Gain: '<Root>/Gain3' */
    PRACTICA2_B.Gain3 = PRACTICA2_P.Gain3_Gain * rtb_Derivative;

    /* Gain: '<Root>/Gain4' */
    PRACTICA2_B.Gain4 = PRACTICA2_P.Gain4_Gain * PRACTICA2_B.Gain3;
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative' */
    if (PRACTICA2_DW.TimeStampA == (rtInf)) {
      PRACTICA2_DW.TimeStampA = PRACTICA2_M->Timing.t[0];
      lastU = &PRACTICA2_DW.LastUAtTimeA;
    } else if (PRACTICA2_DW.TimeStampB == (rtInf)) {
      PRACTICA2_DW.TimeStampB = PRACTICA2_M->Timing.t[0];
      lastU = &PRACTICA2_DW.LastUAtTimeB;
    } else if (PRACTICA2_DW.TimeStampA < PRACTICA2_DW.TimeStampB) {
      PRACTICA2_DW.TimeStampA = PRACTICA2_M->Timing.t[0];
      lastU = &PRACTICA2_DW.LastUAtTimeA;
    } else {
      PRACTICA2_DW.TimeStampB = PRACTICA2_M->Timing.t[0];
      lastU = &PRACTICA2_DW.LastUAtTimeB;
    }

    *lastU = PRACTICA2_B.Gain2;

    /* End of Update for Derivative: '<Root>/Derivative' */
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  PRACTICA2_M->Timing.t[0] =
    ((time_T)(++PRACTICA2_M->Timing.clockTick0)) * PRACTICA2_M->Timing.stepSize0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  PRACTICA2_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void PRACTICA2_step2(void)             /* Sample time: [0.1s, 0.0s] */
{
  boolean_T c_value;

  /* MATLABSystem: '<Root>/Digital Input' */
  c_value = readDigitalPin(6);

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  Logic: '<Root>/NOT'
   *  MATLABSystem: '<Root>/Digital Input'
   * */
  writeDigitalPin(10, (uint8_T)!c_value);

  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
   *  MATLABSystem: '<Root>/Digital Input'
   * */
  writeDigitalPin(9, (uint8_T)c_value);

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  PRACTICA2_M->Timing.clockTick2++;
}

/* Model initialize function */
void PRACTICA2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PRACTICA2_M->solverInfo,
                          &PRACTICA2_M->Timing.simTimeStep);
    rtsiSetTPtr(&PRACTICA2_M->solverInfo, &rtmGetTPtr(PRACTICA2_M));
    rtsiSetStepSizePtr(&PRACTICA2_M->solverInfo, &PRACTICA2_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&PRACTICA2_M->solverInfo, (&rtmGetErrorStatus
      (PRACTICA2_M)));
    rtsiSetRTModelPtr(&PRACTICA2_M->solverInfo, PRACTICA2_M);
  }

  rtsiSetSimTimeStep(&PRACTICA2_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&PRACTICA2_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&PRACTICA2_M->solverInfo, false);
  rtsiSetSolverName(&PRACTICA2_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(PRACTICA2_M, &PRACTICA2_M->Timing.tArray[0]);
  rtmSetTFinal(PRACTICA2_M, -1);
  PRACTICA2_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  PRACTICA2_M->Sizes.checksums[0] = (174782507U);
  PRACTICA2_M->Sizes.checksums[1] = (250389396U);
  PRACTICA2_M->Sizes.checksums[2] = (2012388626U);
  PRACTICA2_M->Sizes.checksums[3] = (306683172U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    PRACTICA2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PRACTICA2_M->extModeInfo,
      &PRACTICA2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PRACTICA2_M->extModeInfo, PRACTICA2_M->Sizes.checksums);
    rteiSetTFinalTicks(PRACTICA2_M->extModeInfo, -1);
  }

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  PRACTICA2_DW.TimeStampA = (rtInf);
  PRACTICA2_DW.TimeStampB = (rtInf);

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  PRACTICA2_DW.obj_f.matlabCodegenIsDeleted = false;
  PRACTICA2_DW.obj_f.isInitialized = 1L;
  PRACTICA2_DW.obj_f.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(15UL);
  PRACTICA2_DW.obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM' */
  PRACTICA2_DW.obj_hn.matlabCodegenIsDeleted = false;
  PRACTICA2_DW.obj_hn.isInitialized = 1L;
  PRACTICA2_DW.obj_hn.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0, 0.0);
  PRACTICA2_DW.obj_hn.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input1' */
  PRACTICA2_DW.obj.matlabCodegenIsDeleted = false;
  PRACTICA2_DW.obj.isInitialized = 1L;
  PRACTICA2_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open
    (18UL);
  PRACTICA2_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  PRACTICA2_DW.obj_o.Index = 0U;
  PRACTICA2_DW.obj_o.matlabCodegenIsDeleted = false;
  PRACTICA2_DW.obj_o.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &PRACTICA2_DW.obj_o.Index);
  PRACTICA2_DW.obj_o.isSetupComplete = true;
  PRACTICA2_DW.obj_o.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<Root>/Encoder' */
  MW_EncoderReset(PRACTICA2_DW.obj_o.Index);

  /* Start for MATLABSystem: '<Root>/Digital Input' */
  PRACTICA2_DW.obj_h.matlabCodegenIsDeleted = false;
  PRACTICA2_DW.obj_h.isInitialized = 1L;
  digitalIOSetup(6, 0);
  PRACTICA2_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  PRACTICA2_DW.obj_l.matlabCodegenIsDeleted = false;
  PRACTICA2_DW.obj_l.isInitialized = 1L;
  digitalIOSetup(10, 1);
  PRACTICA2_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  PRACTICA2_DW.obj_h0.matlabCodegenIsDeleted = false;
  PRACTICA2_DW.obj_h0.isInitialized = 1L;
  digitalIOSetup(9, 1);
  PRACTICA2_DW.obj_h0.isSetupComplete = true;
}

/* Model terminate function */
void PRACTICA2_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!PRACTICA2_DW.obj_f.matlabCodegenIsDeleted) {
    PRACTICA2_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((PRACTICA2_DW.obj_f.isInitialized == 1L) &&
        PRACTICA2_DW.obj_f.isSetupComplete) {
      PRACTICA2_DW.obj_f.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(15UL);
      MW_AnalogIn_Close(PRACTICA2_DW.obj_f.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!PRACTICA2_DW.obj_hn.matlabCodegenIsDeleted) {
    PRACTICA2_DW.obj_hn.matlabCodegenIsDeleted = true;
    if ((PRACTICA2_DW.obj_hn.isInitialized == 1L) &&
        PRACTICA2_DW.obj_hn.isSetupComplete) {
      PRACTICA2_DW.obj_hn.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle(PRACTICA2_DW.obj_hn.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      PRACTICA2_DW.obj_hn.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_Close(PRACTICA2_DW.obj_hn.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  if (!PRACTICA2_DW.obj.matlabCodegenIsDeleted) {
    PRACTICA2_DW.obj.matlabCodegenIsDeleted = true;
    if ((PRACTICA2_DW.obj.isInitialized == 1L) &&
        PRACTICA2_DW.obj.isSetupComplete) {
      PRACTICA2_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(18UL);
      MW_AnalogIn_Close(PRACTICA2_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */
  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!PRACTICA2_DW.obj_o.matlabCodegenIsDeleted) {
    PRACTICA2_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((PRACTICA2_DW.obj_o.isInitialized == 1L) &&
        PRACTICA2_DW.obj_o.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  if (!PRACTICA2_DW.obj_h.matlabCodegenIsDeleted) {
    PRACTICA2_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!PRACTICA2_DW.obj_l.matlabCodegenIsDeleted) {
    PRACTICA2_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!PRACTICA2_DW.obj_h0.matlabCodegenIsDeleted) {
    PRACTICA2_DW.obj_h0.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
