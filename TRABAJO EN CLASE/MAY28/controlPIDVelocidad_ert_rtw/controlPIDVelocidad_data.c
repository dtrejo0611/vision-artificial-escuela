/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controlPIDVelocidad_data.c
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

/* Block parameters (default storage) */
P_controlPIDVelocidad_T controlPIDVelocidad_P = {
  /* Mask Parameter: LowPassFilterDiscreteorContinuo
   * Referenced by: '<S1>/K'
   */
  1.0,

  /* Mask Parameter: LowPassFilterDiscreteorContin_f
   * Referenced by: '<S4>/Time constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S7>/Constant'
   */
  2.0,

  /* Mask Parameter: LowPassFilterDiscreteorContin_c
   * Referenced by: '<S4>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S8>/Constant'
   */
  0.0,

  /* Expression: 1/44
   * Referenced by: '<Root>/Gain'
   */
  0.022727272727272728,

  /* Expression: 60/20.4
   * Referenced by: '<Root>/Gain4'
   */
  2.9411764705882355,

  /* Expression: pi/30
   * Referenced by: '<Root>/Gain5'
   */
  0.10471975511965977,

  /* Expression: 150
   * Referenced by: '<Root>/Velocidad en RPM'
   */
  150.0,

  /* Expression: pi/30
   * Referenced by: '<Root>/Gain1'
   */
  0.10471975511965977,

  /* Expression: 2.45
   * Referenced by: '<Root>/Constant2'
   */
  2.45,

  /* Expression: 2.6
   * Referenced by: '<Root>/Gain3'
   */
  2.6,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S10>/Integrator'
   */
  0.001,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S10>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S10>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S10>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S10>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<Root>/Gain2'
   */
  40960U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
