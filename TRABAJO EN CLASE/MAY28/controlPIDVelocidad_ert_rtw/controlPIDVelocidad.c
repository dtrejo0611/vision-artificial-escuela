/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controlPIDVelocidad.c
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

#include "controlPIDVelocidad.h"
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "controlPIDVelocidad_private.h"

/* Block signals (default storage) */
B_controlPIDVelocidad_T controlPIDVelocidad_B;

/* Continuous states */
X_controlPIDVelocidad_T controlPIDVelocidad_X;

/* Disabled State Vector */
XDis_controlPIDVelocidad_T controlPIDVelocidad_XDis;

/* Block states (default storage) */
DW_controlPIDVelocidad_T controlPIDVelocidad_DW;

/* Real-time model */
static RT_MODEL_controlPIDVelocidad_T controlPIDVelocidad_M_;
RT_MODEL_controlPIDVelocidad_T *const controlPIDVelocidad_M =
  &controlPIDVelocidad_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  controlPIDVelocidad_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  controlPIDVelocidad_step();
  controlPIDVelocidad_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  controlPIDVelocidad_step();
  controlPIDVelocidad_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void controlPIDVelocidad_step(void)
{
  /* local block i/o variables */
  real_T rtb_uT;
  boolean_T rtb_LogicalOperator;
  if (rtmIsMajorTimeStep(controlPIDVelocidad_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&controlPIDVelocidad_M->solverInfo,
                          ((controlPIDVelocidad_M->Timing.clockTick0+1)*
      controlPIDVelocidad_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(controlPIDVelocidad_M)) {
    controlPIDVelocidad_M->Timing.t[0] = rtsiGetT
      (&controlPIDVelocidad_M->solverInfo);
  }

  {
    real_T lastTime;
    real_T rtb_Derivative;
    real_T rtb_K;
    real_T *lastU;
    int32_T rtb_Encoder_0;
    int16_T tmp_0;
    uint16_T b_varargout_1;
    boolean_T tmp;

    /* MATLABSystem: '<Root>/Encoder' */
    if (controlPIDVelocidad_DW.obj_l.TunablePropsChanged) {
      controlPIDVelocidad_DW.obj_l.TunablePropsChanged = false;
    }

    MW_EncoderRead(controlPIDVelocidad_DW.obj_l.Index, &rtb_Encoder_0);

    /* Gain: '<Root>/Gain' incorporates:
     *  DataTypeConversion: '<Root>/Cast To Double'
     *  MATLABSystem: '<Root>/Encoder'
     */
    controlPIDVelocidad_B.Gain = rtb_Encoder_0;
    controlPIDVelocidad_B.Gain *= controlPIDVelocidad_P.Gain_Gain;

    /* Derivative: '<Root>/Derivative' */
    rtb_Derivative = controlPIDVelocidad_M->Timing.t[0];
    if ((controlPIDVelocidad_DW.TimeStampA >= rtb_Derivative) &&
        (controlPIDVelocidad_DW.TimeStampB >= rtb_Derivative)) {
      rtb_Derivative = 0.0;
    } else {
      lastTime = controlPIDVelocidad_DW.TimeStampA;
      lastU = &controlPIDVelocidad_DW.LastUAtTimeA;
      if (controlPIDVelocidad_DW.TimeStampA < controlPIDVelocidad_DW.TimeStampB)
      {
        if (controlPIDVelocidad_DW.TimeStampB < rtb_Derivative) {
          lastTime = controlPIDVelocidad_DW.TimeStampB;
          lastU = &controlPIDVelocidad_DW.LastUAtTimeB;
        }
      } else if (controlPIDVelocidad_DW.TimeStampA >= rtb_Derivative) {
        lastTime = controlPIDVelocidad_DW.TimeStampB;
        lastU = &controlPIDVelocidad_DW.LastUAtTimeB;
      }

      rtb_Derivative = (controlPIDVelocidad_B.Gain - *lastU) / (rtb_Derivative -
        lastTime);
    }

    /* End of Derivative: '<Root>/Derivative' */

    /* Gain: '<Root>/Gain5' incorporates:
     *  Gain: '<Root>/Gain4'
     */
    controlPIDVelocidad_B.Velocidadmedida = controlPIDVelocidad_P.Gain4_Gain *
      rtb_Derivative * controlPIDVelocidad_P.Gain5_Gain;
    tmp = rtmIsMajorTimeStep(controlPIDVelocidad_M);
    if (tmp) {
      /* Gain: '<Root>/Gain1' incorporates:
       *  Constant: '<Root>/Velocidad en RPM'
       */
      controlPIDVelocidad_B.Referencia = controlPIDVelocidad_P.Gain1_Gain *
        controlPIDVelocidad_P.VelocidadenRPM_Value;

      /* SignalConversion generated from: '<Root>/Mux1' */
      controlPIDVelocidad_B.TmpSignalConversionAtTAQSigLogg[0] =
        controlPIDVelocidad_B.Velocidadmedida;
      controlPIDVelocidad_B.TmpSignalConversionAtTAQSigLogg[1] =
        controlPIDVelocidad_B.Referencia;

      /* Logic: '<S4>/Logical Operator' incorporates:
       *  Constant: '<S4>/Constant'
       *  Constant: '<S4>/Time constant'
       *  Constant: '<S7>/Constant'
       *  Constant: '<S8>/Constant'
       *  RelationalOperator: '<S7>/Compare'
       *  RelationalOperator: '<S8>/Compare'
       *  Sum: '<S4>/Sum1'
       */
      rtb_LogicalOperator =
        ((controlPIDVelocidad_P.LowPassFilterDiscreteorContin_f -
          controlPIDVelocidad_B.Probe[0] <= controlPIDVelocidad_P.Constant_Value)
         && (controlPIDVelocidad_P.LowPassFilterDiscreteorContin_c <
             controlPIDVelocidad_P.CompareToConstant_const));

      /* MATLABSystem: '<Root>/Analog Input' */
      controlPIDVelocidad_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(14UL);
      MW_AnalogInSingle_ReadResult
        (controlPIDVelocidad_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
         &b_varargout_1, MW_ANALOGIN_UINT16);

      /* Gain: '<S1>/K' incorporates:
       *  Constant: '<Root>/Constant2'
       *  Gain: '<Root>/Gain2'
       *  Gain: '<Root>/Gain3'
       *  MATLABSystem: '<Root>/Analog Input'
       *  Sum: '<Root>/Sum'
       * */
      rtb_K = ((real_T)((uint32_T)controlPIDVelocidad_P.Gain2_Gain *
                        b_varargout_1) * 1.1920928955078125E-7 -
               controlPIDVelocidad_P.Constant2_Value) *
        controlPIDVelocidad_P.Gain3_Gain *
        controlPIDVelocidad_P.LowPassFilterDiscreteorContinuo;

      /* DiscreteIntegrator: '<S10>/Integrator' */
      if (controlPIDVelocidad_DW.Integrator_IC_LOADING != 0) {
        controlPIDVelocidad_DW.Integrator_DSTATE = rtb_K;
        if (controlPIDVelocidad_DW.Integrator_DSTATE >
            controlPIDVelocidad_P.Integrator_UpperSat) {
          controlPIDVelocidad_DW.Integrator_DSTATE =
            controlPIDVelocidad_P.Integrator_UpperSat;
        } else if (controlPIDVelocidad_DW.Integrator_DSTATE <
                   controlPIDVelocidad_P.Integrator_LowerSat) {
          controlPIDVelocidad_DW.Integrator_DSTATE =
            controlPIDVelocidad_P.Integrator_LowerSat;
        }
      }

      if (rtb_LogicalOperator ||
          (controlPIDVelocidad_DW.Integrator_PrevResetState != 0)) {
        controlPIDVelocidad_DW.Integrator_DSTATE = rtb_K;
        if (controlPIDVelocidad_DW.Integrator_DSTATE >
            controlPIDVelocidad_P.Integrator_UpperSat) {
          controlPIDVelocidad_DW.Integrator_DSTATE =
            controlPIDVelocidad_P.Integrator_UpperSat;
        } else if (controlPIDVelocidad_DW.Integrator_DSTATE <
                   controlPIDVelocidad_P.Integrator_LowerSat) {
          controlPIDVelocidad_DW.Integrator_DSTATE =
            controlPIDVelocidad_P.Integrator_LowerSat;
        }
      }

      /* Saturate: '<S10>/Saturation' incorporates:
       *  DiscreteIntegrator: '<S10>/Integrator'
       */
      if (controlPIDVelocidad_DW.Integrator_DSTATE >
          controlPIDVelocidad_P.Saturation_UpperSat) {
        /* Saturate: '<S10>/Saturation' */
        controlPIDVelocidad_B.Saturation =
          controlPIDVelocidad_P.Saturation_UpperSat;
      } else if (controlPIDVelocidad_DW.Integrator_DSTATE <
                 controlPIDVelocidad_P.Saturation_LowerSat) {
        /* Saturate: '<S10>/Saturation' */
        controlPIDVelocidad_B.Saturation =
          controlPIDVelocidad_P.Saturation_LowerSat;
      } else {
        /* Saturate: '<S10>/Saturation' */
        controlPIDVelocidad_B.Saturation =
          controlPIDVelocidad_DW.Integrator_DSTATE;
      }

      /* End of Saturate: '<S10>/Saturation' */
    }

    /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
     *  Integrator: '<Root>/Integrator'
     */
    controlPIDVelocidad_B.gip = controlPIDVelocidad_B.Referencia -
      controlPIDVelocidad_B.Velocidadmedida;
    controlPIDVelocidad_B.u = (0.222 * controlPIDVelocidad_B.Velocidadmedida +
      10.1787 * controlPIDVelocidad_B.Saturation) + 0.0167 *
      controlPIDVelocidad_X.Integrator_CSTATE;
    if (!(controlPIDVelocidad_B.u >= 0.0)) {
      controlPIDVelocidad_B.u = 0.0;
    }

    if (!(controlPIDVelocidad_B.u <= 12.0)) {
      controlPIDVelocidad_B.u = 12.0;
    }

    /* End of MATLAB Function: '<Root>/MATLAB Function1' */

    /* MATLAB Function: '<Root>/MATLAB Function2' */
    if (controlPIDVelocidad_B.u > 12.0) {
      rtb_Derivative = 0.0;
    } else {
      rtb_Derivative = controlPIDVelocidad_B.u;
    }

    if (rtb_Derivative > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = 0;
    }

    /* MATLABSystem: '<Root>/Digital Output' incorporates:
     *  MATLAB Function: '<Root>/MATLAB Function2'
     */
    writeDigitalPin(5, (uint8_T)tmp_0);

    /* MATLABSystem: '<Root>/Digital Output1' */
    writeDigitalPin(6, 0);

    /* MATLABSystem: '<Root>/PWM' */
    controlPIDVelocidad_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
      (11UL);

    /* MATLAB Function: '<Root>/MATLAB Function2' */
    rtb_Derivative *= 21.25;

    /* Start for MATLABSystem: '<Root>/PWM' */
    if (!(rtb_Derivative <= 255.0)) {
      rtb_Derivative = 255.0;
    }

    if (!(rtb_Derivative >= 0.0)) {
      rtb_Derivative = 0.0;
    }

    /* MATLABSystem: '<Root>/PWM' */
    MW_PWM_SetDutyCycle(controlPIDVelocidad_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                        rtb_Derivative);
    if (tmp) {
      /* MinMax: '<S4>/Max' incorporates:
       *  Constant: '<S4>/Time constant'
       */
      if ((controlPIDVelocidad_B.Probe[0] >=
           controlPIDVelocidad_P.LowPassFilterDiscreteorContin_f) || rtIsNaN
          (controlPIDVelocidad_P.LowPassFilterDiscreteorContin_f)) {
        rtb_Derivative = controlPIDVelocidad_B.Probe[0];
      } else {
        rtb_Derivative = controlPIDVelocidad_P.LowPassFilterDiscreteorContin_f;
      }

      /* End of MinMax: '<S4>/Max' */

      /* Product: '<S1>/1//T' incorporates:
       *  Fcn: '<S4>/Avoid Divide by Zero'
       *  Sum: '<S1>/Sum1'
       */
      rtb_uT = 1.0 / ((real_T)(rtb_Derivative == 0.0) * 2.2204460492503131e-16 +
                      rtb_Derivative) * (rtb_K -
        controlPIDVelocidad_B.Saturation);
    }
  }

  if (rtmIsMajorTimeStep(controlPIDVelocidad_M)) {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative' */
    if (controlPIDVelocidad_DW.TimeStampA == (rtInf)) {
      controlPIDVelocidad_DW.TimeStampA = controlPIDVelocidad_M->Timing.t[0];
      lastU = &controlPIDVelocidad_DW.LastUAtTimeA;
    } else if (controlPIDVelocidad_DW.TimeStampB == (rtInf)) {
      controlPIDVelocidad_DW.TimeStampB = controlPIDVelocidad_M->Timing.t[0];
      lastU = &controlPIDVelocidad_DW.LastUAtTimeB;
    } else if (controlPIDVelocidad_DW.TimeStampA <
               controlPIDVelocidad_DW.TimeStampB) {
      controlPIDVelocidad_DW.TimeStampA = controlPIDVelocidad_M->Timing.t[0];
      lastU = &controlPIDVelocidad_DW.LastUAtTimeA;
    } else {
      controlPIDVelocidad_DW.TimeStampB = controlPIDVelocidad_M->Timing.t[0];
      lastU = &controlPIDVelocidad_DW.LastUAtTimeB;
    }

    *lastU = controlPIDVelocidad_B.Gain;

    /* End of Update for Derivative: '<Root>/Derivative' */
    if (rtmIsMajorTimeStep(controlPIDVelocidad_M)) {
      /* Update for DiscreteIntegrator: '<S10>/Integrator' */
      controlPIDVelocidad_DW.Integrator_IC_LOADING = 0U;
      controlPIDVelocidad_DW.Integrator_DSTATE +=
        controlPIDVelocidad_P.Integrator_gainval * rtb_uT;
      if (controlPIDVelocidad_DW.Integrator_DSTATE >
          controlPIDVelocidad_P.Integrator_UpperSat) {
        controlPIDVelocidad_DW.Integrator_DSTATE =
          controlPIDVelocidad_P.Integrator_UpperSat;
      } else if (controlPIDVelocidad_DW.Integrator_DSTATE <
                 controlPIDVelocidad_P.Integrator_LowerSat) {
        controlPIDVelocidad_DW.Integrator_DSTATE =
          controlPIDVelocidad_P.Integrator_LowerSat;
      }

      controlPIDVelocidad_DW.Integrator_PrevResetState = (int8_T)
        rtb_LogicalOperator;

      /* End of Update for DiscreteIntegrator: '<S10>/Integrator' */
    }

    if (rtmIsMajorTimeStep(controlPIDVelocidad_M)) {/* Sample time: [0.001s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
        ((controlPIDVelocidad_M->Timing.clockTick1 * 1) + 0);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1, extmodeTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(controlPIDVelocidad_M)) {
    rt_ertODEUpdateContinuousStates(&controlPIDVelocidad_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++controlPIDVelocidad_M->Timing.clockTick0;
    controlPIDVelocidad_M->Timing.t[0] = rtsiGetSolverStopTime
      (&controlPIDVelocidad_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      controlPIDVelocidad_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void controlPIDVelocidad_derivatives(void)
{
  XDot_controlPIDVelocidad_T *_rtXdot;
  _rtXdot = ((XDot_controlPIDVelocidad_T *) controlPIDVelocidad_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = controlPIDVelocidad_B.gip;
}

/* Model initialize function */
void controlPIDVelocidad_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  controlPIDVelocidad_P.Integrator_UpperSat = rtInf;
  controlPIDVelocidad_P.Integrator_LowerSat = rtMinusInf;
  controlPIDVelocidad_P.Saturation_UpperSat = rtInf;
  controlPIDVelocidad_P.Saturation_LowerSat = rtMinusInf;

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&controlPIDVelocidad_M->solverInfo,
                          &controlPIDVelocidad_M->Timing.simTimeStep);
    rtsiSetTPtr(&controlPIDVelocidad_M->solverInfo, &rtmGetTPtr
                (controlPIDVelocidad_M));
    rtsiSetStepSizePtr(&controlPIDVelocidad_M->solverInfo,
                       &controlPIDVelocidad_M->Timing.stepSize0);
    rtsiSetdXPtr(&controlPIDVelocidad_M->solverInfo,
                 &controlPIDVelocidad_M->derivs);
    rtsiSetContStatesPtr(&controlPIDVelocidad_M->solverInfo, (real_T **)
                         &controlPIDVelocidad_M->contStates);
    rtsiSetNumContStatesPtr(&controlPIDVelocidad_M->solverInfo,
      &controlPIDVelocidad_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&controlPIDVelocidad_M->solverInfo,
      &controlPIDVelocidad_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&controlPIDVelocidad_M->solverInfo,
      &controlPIDVelocidad_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&controlPIDVelocidad_M->solverInfo,
      &controlPIDVelocidad_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&controlPIDVelocidad_M->solverInfo, (boolean_T**)
      &controlPIDVelocidad_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&controlPIDVelocidad_M->solverInfo,
                          (&rtmGetErrorStatus(controlPIDVelocidad_M)));
    rtsiSetRTModelPtr(&controlPIDVelocidad_M->solverInfo, controlPIDVelocidad_M);
  }

  rtsiSetSimTimeStep(&controlPIDVelocidad_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&controlPIDVelocidad_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&controlPIDVelocidad_M->solverInfo, false);
  controlPIDVelocidad_M->intgData.y = controlPIDVelocidad_M->odeY;
  controlPIDVelocidad_M->intgData.f[0] = controlPIDVelocidad_M->odeF[0];
  controlPIDVelocidad_M->intgData.f[1] = controlPIDVelocidad_M->odeF[1];
  controlPIDVelocidad_M->intgData.f[2] = controlPIDVelocidad_M->odeF[2];
  controlPIDVelocidad_M->contStates = ((X_controlPIDVelocidad_T *)
    &controlPIDVelocidad_X);
  controlPIDVelocidad_M->contStateDisabled = ((XDis_controlPIDVelocidad_T *)
    &controlPIDVelocidad_XDis);
  controlPIDVelocidad_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&controlPIDVelocidad_M->solverInfo, (void *)
                    &controlPIDVelocidad_M->intgData);
  rtsiSetSolverName(&controlPIDVelocidad_M->solverInfo,"ode3");
  rtmSetTPtr(controlPIDVelocidad_M, &controlPIDVelocidad_M->Timing.tArray[0]);
  rtmSetTFinal(controlPIDVelocidad_M, -1);
  controlPIDVelocidad_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  controlPIDVelocidad_M->Sizes.checksums[0] = (3041527569U);
  controlPIDVelocidad_M->Sizes.checksums[1] = (652054190U);
  controlPIDVelocidad_M->Sizes.checksums[2] = (2608580590U);
  controlPIDVelocidad_M->Sizes.checksums[3] = (875508688U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    controlPIDVelocidad_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(controlPIDVelocidad_M->extModeInfo,
      &controlPIDVelocidad_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(controlPIDVelocidad_M->extModeInfo,
                        controlPIDVelocidad_M->Sizes.checksums);
    rteiSetTFinalTicks(controlPIDVelocidad_M->extModeInfo, -1);
  }

  /* Start for Probe: '<S4>/Probe' */
  controlPIDVelocidad_B.Probe[0] = 0.001;
  controlPIDVelocidad_B.Probe[1] = 0.0;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  controlPIDVelocidad_DW.TimeStampA = (rtInf);
  controlPIDVelocidad_DW.TimeStampB = (rtInf);

  /* InitializeConditions for DiscreteIntegrator: '<S10>/Integrator' */
  controlPIDVelocidad_DW.Integrator_IC_LOADING = 1U;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  controlPIDVelocidad_X.Integrator_CSTATE = controlPIDVelocidad_P.Integrator_IC;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  controlPIDVelocidad_DW.obj_l.Index = 0U;
  controlPIDVelocidad_DW.obj_l.matlabCodegenIsDeleted = false;
  controlPIDVelocidad_DW.obj_l.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &controlPIDVelocidad_DW.obj_l.Index);
  controlPIDVelocidad_DW.obj_l.isSetupComplete = true;
  controlPIDVelocidad_DW.obj_l.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<Root>/Encoder' */
  MW_EncoderReset(controlPIDVelocidad_DW.obj_l.Index);

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  controlPIDVelocidad_DW.obj.matlabCodegenIsDeleted = false;
  controlPIDVelocidad_DW.obj.isInitialized = 1L;
  controlPIDVelocidad_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(14UL);
  controlPIDVelocidad_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  controlPIDVelocidad_DW.obj_jn.matlabCodegenIsDeleted = false;
  controlPIDVelocidad_DW.obj_jn.isInitialized = 1L;
  digitalIOSetup(5, 1);
  controlPIDVelocidad_DW.obj_jn.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  controlPIDVelocidad_DW.obj_j.matlabCodegenIsDeleted = false;
  controlPIDVelocidad_DW.obj_j.isInitialized = 1L;
  digitalIOSetup(6, 1);
  controlPIDVelocidad_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM' */
  controlPIDVelocidad_DW.obj_b.matlabCodegenIsDeleted = false;
  controlPIDVelocidad_DW.obj_b.isInitialized = 1L;
  controlPIDVelocidad_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL,
    0.0, 0.0);
  controlPIDVelocidad_DW.obj_b.isSetupComplete = true;
}

/* Model terminate function */
void controlPIDVelocidad_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!controlPIDVelocidad_DW.obj_l.matlabCodegenIsDeleted) {
    controlPIDVelocidad_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((controlPIDVelocidad_DW.obj_l.isInitialized == 1L) &&
        controlPIDVelocidad_DW.obj_l.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!controlPIDVelocidad_DW.obj.matlabCodegenIsDeleted) {
    controlPIDVelocidad_DW.obj.matlabCodegenIsDeleted = true;
    if ((controlPIDVelocidad_DW.obj.isInitialized == 1L) &&
        controlPIDVelocidad_DW.obj.isSetupComplete) {
      controlPIDVelocidad_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close
        (controlPIDVelocidad_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!controlPIDVelocidad_DW.obj_jn.matlabCodegenIsDeleted) {
    controlPIDVelocidad_DW.obj_jn.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!controlPIDVelocidad_DW.obj_j.matlabCodegenIsDeleted) {
    controlPIDVelocidad_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!controlPIDVelocidad_DW.obj_b.matlabCodegenIsDeleted) {
    controlPIDVelocidad_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((controlPIDVelocidad_DW.obj_b.isInitialized == 1L) &&
        controlPIDVelocidad_DW.obj_b.isSetupComplete) {
      controlPIDVelocidad_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_SetDutyCycle
        (controlPIDVelocidad_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      controlPIDVelocidad_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_Close(controlPIDVelocidad_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
