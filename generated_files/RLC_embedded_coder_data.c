/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: RLC_embedded_coder_data.c
 *
 * Code generated for Simulink model 'RLC_embedded_coder'.
 *
 * Model version                  : 1.301
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Dec 21 15:43:26 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "RLC_embedded_coder.h"

/* Invariant block signals (default storage) */
const ConstB rtConstB = {
  2                                    /* '<S6>/Width' */
};

/* Block parameters (default storage) */
P rtP = {
  /* Variable: Kd_u
   * Referenced by: '<S17>/Gain2'
   */
  0.00015,

  /* Variable: Ki_i
   * Referenced by: '<S16>/Gain1'
   */
  50.0,

  /* Variable: Ki_u
   * Referenced by: '<S17>/Gain1'
   */
  17000.0,

  /* Variable: Kp_i
   * Referenced by: '<S16>/Gain'
   */
  1.0,

  /* Variable: Kp_u
   * Referenced by: '<S17>/Gain'
   */
  5.5,

  /* Variable: PWM_PERIOD
   * Referenced by:
   *   '<S5>/Constant'
   *   '<S29>/Constant'
   */
  2000.0,

  /* Variable: SAMPLE_TIME
   * Referenced by:
   *   '<S16>/T sample'
   *   '<S16>/T_sample'
   *   '<S17>/T sample'
   *   '<S17>/T_sample'
   */
  2.5E-5,

  /* Variable: current_offset
   * Referenced by: '<S2>/Initial value1'
   */
  1940.0,

  /* Variable: i_max
   * Referenced by: '<S17>/Saturation'
   */
  5.0,

  /* Variable: offset_filter
   * Referenced by:
   *   '<S2>/Constant3'
   *   '<S2>/Constant4'
   */
  0.05,

  /* Variable: ref_value_high
   * Referenced by: '<S15>/Constant'
   */
  2.5,

  /* Variable: ref_value_low
   * Referenced by: '<S15>/Constant1'
   */
  0.0,

  /* Variable: tau
   * Referenced by:
   *   '<S17>/Constant'
   *   '<S17>/Constant1'
   */
  2.0E-5,

  /* Variable: u_max
   * Referenced by:
   *   '<S4>/Normalize voltage'
   *   '<S16>/Saturation'
   */
  3.3,

  /* Variable: voltage_offset
   * Referenced by: '<S2>/Initial value'
   */
  1971.0,

  /* Variable: ADC_gain
   * Referenced by:
   *   '<S14>/adc gain'
   *   '<S14>/adc gain2'
   */
  0.000805860793F,

  /* Variable: current_gain
   * Referenced by: '<S14>/current gain'
   */
  3.92156863F,

  /* Variable: voltage_gain
   * Referenced by: '<S14>/voltage gain'
   */
  2.4F,

  /* Variable: ref_counter_cmpr
   * Referenced by: '<S19>/Constant'
   */
  500U,

  /* Variable: ref_counter_prd
   * Referenced by:
   *   '<S22>/FixPt Switch'
   *   '<S28>/FixPt Switch'
   */
  40000U,

  /* Mask Parameter: PID_current_Kd
   * Referenced by: '<S16>/Gain2'
   */
  0.0,

  /* Mask Parameter: PID_current_tau
   * Referenced by:
   *   '<S16>/Constant'
   *   '<S16>/Constant1'
   */
  0.0,

  /* Mask Parameter: WrapToZero_Threshold
   * Referenced by: '<S13>/FixPt Switch'
   */
  4294967295U,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S10>/Constant'
   */
  200000U,

  /* Mask Parameter: CompareToConstant_const_b
   * Referenced by: '<S25>/Constant'
   */
  20000U,

  /* Mask Parameter: CounterLimited_uplimit
   * Referenced by: '<S35>/FixPt Switch'
   */
  11999U,

  /* Expression: 1
   * Referenced by: '<S2>/Constant2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S2>/Constant1'
   */
  1.0,

  /* Expression: [0]
   * Referenced by: '<S9>/ADC_calib'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S9>/Constant'
   */
  1.0,

  /* Expression: [0]
   * Referenced by: '<S8>/PID'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant'
   */
  1.0,

  /* Expression: 4
   * Referenced by: '<S18>/Constant1'
   */
  4.0,

  /* Expression: 0
   * Referenced by: '<S18>/Constant'
   */
  0.0,

  /* Computed Parameter: duty_Y0
   * Referenced by: '<S4>/duty'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S23>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S24>/Constant'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S17>/Delay1'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S17>/Gain3'
   */
  2.0,

  /* Expression: 0.0
   * Referenced by: '<S17>/Delay'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S17>/Gain4'
   */
  2.0,

  /* Expression: 2
   * Referenced by: '<S17>/Gain5'
   */
  2.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S17>/Discrete-Time Integrator'
   */
  2.5E-5,

  /* Expression: 0
   * Referenced by: '<S17>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S16>/Delay1'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S16>/Gain3'
   */
  2.0,

  /* Expression: 0.0
   * Referenced by: '<S16>/Delay'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S16>/Gain4'
   */
  2.0,

  /* Expression: 2
   * Referenced by: '<S16>/Gain5'
   */
  2.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_j
   * Referenced by: '<S16>/Discrete-Time Integrator'
   */
  2.5E-5,

  /* Expression: 0
   * Referenced by: '<S16>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S29>/[-1,1]'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S29>/[-1,1]'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S5>/Switch1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S14>/Gain'
   */
  -1.0F,

  /* Computed Parameter: Gain3_Gain_g
   * Referenced by: '<S14>/Gain3'
   */
  -1.0F,

  /* Computed Parameter: Constant_Value_o3
   * Referenced by: '<S13>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S11>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S12>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: voltage_offset_Y0
   * Referenced by: '<S2>/voltage_offset'
   */
  0,

  /* Computed Parameter: current_offset_Y0
   * Referenced by: '<S2>/current_offset'
   */
  0,

  /* Computed Parameter: Delay1_InitialCondition_f
   * Referenced by: '<S2>/Delay1'
   */
  0,

  /* Computed Parameter: Delay_InitialCondition_o
   * Referenced by: '<S2>/Delay'
   */
  0,

  /* Computed Parameter: End_Value
   * Referenced by: '<S32>/End'
   */
  21331,

  /* Computed Parameter: Start_Value
   * Referenced by: '<S32>/Start'
   */
  17733,

  /* Computed Parameter: Bias_Bias
   * Referenced by: '<S32>/Bias'
   */
  2,

  /* Computed Parameter: Start_Value_e
   * Referenced by: '<S31>/Start'
   */
  0,

  /* Computed Parameter: Start1_Value
   * Referenced by: '<S31>/Start1'
   */
  0,

  /* Computed Parameter: Constant_Value_g
   * Referenced by: '<S22>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_k0
   * Referenced by: '<S28>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition_b
   * Referenced by: '<S20>/Output'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition_k
   * Referenced by: '<S26>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value_a
   * Referenced by: '<S27>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: FixPtConstant_Value_p
   * Referenced by: '<S21>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: u1000_UpperSat
   * Referenced by: '<S29>/[0, 1000]'
   */
  1000U,

  /* Computed Parameter: u1000_LowerSat
   * Referenced by: '<S29>/[0, 1000]'
   */
  0U,

  /* Computed Parameter: Constant_Value_i
   * Referenced by: '<S35>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition_a
   * Referenced by: '<S30>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value_c
   * Referenced by: '<S34>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S7>/Out1'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<S4>/Manual Switch'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
