/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: RLC_embedded_coder.c
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
#include "rtwtypes.h"
#include <math.h>
#include <string.h>

void InitAdc (void);
void config_ADC_SOC1 (void);
void config_ADC_SOC2 (void);

/* Block signals and states (default storage) */
DW rtDW;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern uint16_T MW_adcInitFlag;
void isr_int1pie4_task_fcn(void);
extern void configureGPIOExtInterrupt(void);
void isr_int1pie4_task_fcn(void);
static void rate_scheduler(void);

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcInitFlag = 0;

#endif

/* Hardware Interrupt Block: '<S3>/C28x Hardware Interrupt1' */
void isr_int1pie4_task_fcn(void)
{
  if (1 == runModel) {
    /* Call the system: <S3>/Counter, Initial output value 0 */
    {
      /* S-Function (c28xisr_c2000): '<S3>/C28x Hardware Interrupt1' */

      /* Output and update for function-call system: '<S3>/Counter, Initial output value 0' */
      {
        uint32_T rtb_FixPtSum1;

        /* RelationalOperator: '<S10>/Compare' incorporates:
         *  Constant: '<S10>/Constant'
         *  UnitDelay: '<S11>/Output'
         */
        rtDW.Compare = (uint16_T)(rtDW.Output_DSTATE >=
          rtP.CompareToConstant_const);

        /* Sum: '<S12>/FixPt Sum1' incorporates:
         *  Constant: '<S12>/FixPt Constant'
         *  UnitDelay: '<S11>/Output'
         */
        rtb_FixPtSum1 = rtDW.Output_DSTATE + rtP.FixPtConstant_Value;

        /* Switch: '<S13>/FixPt Switch' */
        if (rtb_FixPtSum1 > rtP.WrapToZero_Threshold) {
          /* Update for UnitDelay: '<S11>/Output' incorporates:
           *  Constant: '<S13>/Constant'
           */
          rtDW.Output_DSTATE = rtP.Constant_Value_o3;
        } else {
          /* Update for UnitDelay: '<S11>/Output' */
          rtDW.Output_DSTATE = rtb_FixPtSum1;
        }

        /* End of Switch: '<S13>/FixPt Switch' */
      }

      /* End of Outputs for S-Function (c28xisr_c2000): '<S3>/C28x Hardware Interrupt1' */
    }
  }
}

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 27999) {/* Sample time: [0.7s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function */
void RLC_embedded_coder_step(void)
{
  real_T rtb_Saturation;
  real_T rtb_Switch1;
  real_T rtb_differentiator;
  real_T rtb_differentiator_g;
  real_T rtb_e;
  real_T rtb_integral;
  int16_T rtb_Merge[4];
  int16_T rtAction;
  int16_T rtPrevAction;
  int16_T rtb_Add_b;
  uint16_T rtb_TmpRTBAtCounterInitialoutpu;
  boolean_T rtb_Compare_k;

  /* RateTransition generated from: '<S3>/Counter, Initial output value 0' incorporates:
   *  RelationalOperator: '<S10>/Compare'
   */
  rtb_TmpRTBAtCounterInitialoutpu = rtDW.Compare;

  /* If: '<S3>/If1' incorporates:
   *  RateTransition generated from: '<S3>/Counter, Initial output value 0'
   */
  rtPrevAction = rtDW.If1_ActiveSubsystem;
  rtAction = (rtb_TmpRTBAtCounterInitialoutpu != 0U);
  rtDW.If1_ActiveSubsystem = rtAction;
  if (rtPrevAction != rtAction) {
    switch (rtPrevAction) {
     case 0:
      /* Disable for SignalConversion generated from: '<S9>/ADC_calib' incorporates:
       *  Outport: '<S9>/ADC_calib'
       * */
      rtDW.OutportBufferForADC_calib = rtP.ADC_calib_Y0;
      break;

     case 1:
      /* Disable for SignalConversion generated from: '<S8>/PID' incorporates:
       *  Outport: '<S8>/PID'
       * */
      rtDW.OutportBufferForPID = rtP.PID_Y0;
      break;
    }
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S3>/Enable calibration' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* S-Function (c28xswtrigint): '<S9>/Software Interrupt Trigger' incorporates:
     *  Constant: '<S9>/Constant'
     */

    /* Software Interrupt Trigger: INT1.4 */
    if (rtP.Constant_Value > 0.0) {
      PieCtrlRegs.PIEIFR1.bit.INTx4 = 1;
      asm(" RPT #1 || NOP");           /*wait 1 cycles        */
    }

    /* SignalConversion generated from: '<S9>/ADC_calib' incorporates:
     *  Constant: '<S9>/Constant'
     */
    rtDW.OutportBufferForADC_calib = rtP.Constant_Value;

    /* End of Outputs for SubSystem: '<S3>/Enable calibration' */
  } else {
    /* Outputs for IfAction SubSystem: '<S3>/Enable algorithm' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* SignalConversion generated from: '<S8>/PID' incorporates:
     *  Constant: '<S8>/Constant'
     */
    rtDW.OutportBufferForPID = rtP.Constant_Value_b;

    /* End of Outputs for SubSystem: '<S3>/Enable algorithm' */
  }

  /* End of If: '<S3>/If1' */

  /* S-Function (c2802xadc): '<S1>/VOLTAGE' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    rtDW.VOLTAGE = (AdcResult.ADCRESULT1);
  }

  /* S-Function (c2802xadc): '<S1>/CURRENT' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    rtDW.CURRENT = (AdcResult.ADCRESULT2);
  }

  /* Outputs for Enabled SubSystem: '<Root>/ADC calibration' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (rtDW.OutportBufferForADC_calib > 0.0) {
    /* Sum: '<S2>/Subtract3' incorporates:
     *  Constant: '<S2>/Constant2'
     *  Constant: '<S2>/Constant4'
     *  Delay: '<S2>/Delay1'
     *  Product: '<S2>/Divide2'
     *  Product: '<S2>/Divide3'
     *  Sum: '<S2>/Subtract2'
     */
    rtb_integral = (rtP.Constant2_Value - rtP.offset_filter) * (real_T)
      rtDW.Delay1_DSTATE_d + rtP.offset_filter * (real_T)rtDW.VOLTAGE;

    /* InitialCondition: '<S2>/Initial value' */
    if (rtDW.Initialvalue_FirstOutputTime) {
      rtDW.Initialvalue_FirstOutputTime = false;
      rtb_integral = rtP.voltage_offset;
    }

    /* End of InitialCondition: '<S2>/Initial value' */

    /* DataTypeConversion: '<S2>/Data Type Conversion1' */
    rtDW.DataTypeConversion1 = (int16_T)floor(rtb_integral);

    /* Sum: '<S2>/Subtract1' incorporates:
     *  Constant: '<S2>/Constant1'
     *  Constant: '<S2>/Constant3'
     *  Delay: '<S2>/Delay'
     *  Product: '<S2>/Divide'
     *  Product: '<S2>/Divide1'
     *  Sum: '<S2>/Subtract'
     */
    rtb_integral = (rtP.Constant1_Value - rtP.offset_filter) * (real_T)
      rtDW.Delay_DSTATE_k + rtP.offset_filter * (real_T)rtDW.CURRENT;

    /* InitialCondition: '<S2>/Initial value1' */
    if (rtDW.Initialvalue1_FirstOutputTime) {
      rtDW.Initialvalue1_FirstOutputTime = false;
      rtb_integral = rtP.current_offset;
    }

    /* End of InitialCondition: '<S2>/Initial value1' */

    /* DataTypeConversion: '<S2>/Data Type Conversion' */
    rtDW.DataTypeConversion = (int16_T)floor(rtb_integral);

    /* Update for Delay: '<S2>/Delay1' */
    rtDW.Delay1_DSTATE_d = rtDW.DataTypeConversion1;

    /* Update for Delay: '<S2>/Delay' */
    rtDW.Delay_DSTATE_k = rtDW.DataTypeConversion;
  }

  /* End of Outputs for SubSystem: '<Root>/ADC calibration' */

  /* Sum: '<Root>/Sum' */
  rtPrevAction = rtDW.VOLTAGE - rtDW.DataTypeConversion1;

  /* Sum: '<Root>/Sum1' */
  rtAction = rtDW.CURRENT - rtDW.DataTypeConversion;

  /* Outputs for Enabled SubSystem: '<Root>/PID algorithm' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (rtDW.OutportBufferForPID > 0.0) {
    /* Switch: '<S15>/Switch' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S15>/Constant1'
     *  Constant: '<S19>/Constant'
     *  RelationalOperator: '<S19>/Compare'
     *  UnitDelay: '<S20>/Output'
     */
    if (rtDW.Output_DSTATE_m >= rtP.ref_counter_cmpr) {
      rtb_Switch1 = rtP.ref_value_low;
    } else {
      rtb_Switch1 = rtP.ref_value_high;
    }

    /* End of Switch: '<S15>/Switch' */

    /* Sum: '<S17>/Sum1' incorporates:
     *  DataTypeConversion: '<S14>/Data Type Conversion'
     *  Gain: '<S14>/Gain'
     *  Gain: '<S14>/adc gain'
     *  Gain: '<S14>/voltage gain'
     */
    rtb_e = rtb_Switch1 - rtP.Gain_Gain * (real32_T)rtPrevAction * rtP.ADC_gain *
      rtP.voltage_gain;

    /* Sum: '<S17>/Sum' incorporates:
     *  Constant: '<S17>/Constant'
     *  Constant: '<S17>/Constant1'
     *  Constant: '<S17>/T sample'
     *  Constant: '<S17>/T_sample'
     *  Delay: '<S17>/Delay'
     *  Delay: '<S17>/Delay1'
     *  Gain: '<S17>/Gain2'
     *  Gain: '<S17>/Gain3'
     *  Gain: '<S17>/Gain4'
     *  Gain: '<S17>/Gain5'
     *  Product: '<S17>/Divide'
     *  Product: '<S17>/Divide1'
     *  Sum: '<S17>/Subtract'
     *  Sum: '<S17>/Subtract1'
     *  Sum: '<S17>/Sum2'
     */
    rtb_differentiator = (rtP.Gain4_Gain * rtP.tau - rtP.SAMPLE_TIME) *
      rtDW.Delay_DSTATE / (rtP.Gain5_Gain * rtP.tau + rtP.SAMPLE_TIME) + (rtb_e
      - rtDW.Delay1_DSTATE) * rtP.Kd_u * rtP.Gain3_Gain;

    /* DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
    rtb_Switch1 = rtDW.DiscreteTimeIntegrator_DSTATE;

    /* Sum: '<S17>/Plus' incorporates:
     *  Gain: '<S17>/Gain'
     */
    rtb_Switch1 += rtP.Kp_u * rtb_e + rtb_differentiator;

    /* Saturate: '<S17>/Saturation' */
    if (rtb_Switch1 > rtP.i_max) {
      rtb_integral = rtP.i_max;
    } else if (rtb_Switch1 < -rtP.i_max) {
      rtb_integral = -rtP.i_max;
    } else {
      rtb_integral = rtb_Switch1;
    }

    /* End of Saturate: '<S17>/Saturation' */

    /* RelationalOperator: '<S24>/Compare' incorporates:
     *  Constant: '<S24>/Constant'
     *  Sum: '<S17>/Add'
     */
    rtb_Compare_k = (rtb_Switch1 - rtb_integral == rtP.Constant_Value_d);

    /* ManualSwitch: '<S4>/Manual Switch' */
    if (rtP.ManualSwitch_CurrentSetting == 1U) {
      /* Switch: '<S18>/Switch' incorporates:
       *  Constant: '<S18>/Constant'
       *  Constant: '<S18>/Constant1'
       *  Constant: '<S25>/Constant'
       *  RelationalOperator: '<S25>/Compare'
       *  UnitDelay: '<S26>/Output'
       */
      if (rtDW.Output_DSTATE_d >= rtP.CompareToConstant_const_b) {
        rtb_integral = rtP.Constant1_Value_k;
      } else {
        rtb_integral = rtP.Constant_Value_k;
      }

      /* End of Switch: '<S18>/Switch' */
    }

    /* End of ManualSwitch: '<S4>/Manual Switch' */

    /* Sum: '<S16>/Sum1' incorporates:
     *  DataTypeConversion: '<S14>/Data Type Conversion1'
     *  Gain: '<S14>/Gain3'
     *  Gain: '<S14>/adc gain2'
     *  Gain: '<S14>/current gain'
     */
    rtb_integral -= rtP.Gain3_Gain_g * (real32_T)rtAction * rtP.ADC_gain *
      rtP.current_gain;

    /* Sum: '<S16>/Sum' incorporates:
     *  Constant: '<S16>/Constant'
     *  Constant: '<S16>/Constant1'
     *  Constant: '<S16>/T sample'
     *  Constant: '<S16>/T_sample'
     *  Delay: '<S16>/Delay'
     *  Delay: '<S16>/Delay1'
     *  Gain: '<S16>/Gain2'
     *  Gain: '<S16>/Gain3'
     *  Gain: '<S16>/Gain4'
     *  Gain: '<S16>/Gain5'
     *  Product: '<S16>/Divide'
     *  Product: '<S16>/Divide1'
     *  Sum: '<S16>/Subtract'
     *  Sum: '<S16>/Subtract1'
     *  Sum: '<S16>/Sum2'
     */
    rtb_differentiator_g = (rtP.Gain4_Gain_g * rtP.PID_current_tau -
      rtP.SAMPLE_TIME) * rtDW.Delay_DSTATE_p / (rtP.Gain5_Gain_e *
      rtP.PID_current_tau + rtP.SAMPLE_TIME) + (rtb_integral -
      rtDW.Delay1_DSTATE_g) * rtP.PID_current_Kd * rtP.Gain3_Gain_e;

    /* Sum: '<S16>/Plus' incorporates:
     *  DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
     *  Gain: '<S16>/Gain'
     */
    rtb_Switch1 = (rtP.Kp_i * rtb_integral + rtb_differentiator_g) +
      rtDW.DiscreteTimeIntegrator_DSTATE_a;

    /* Saturate: '<S16>/Saturation' */
    if (rtb_Switch1 > rtP.u_max) {
      rtb_Saturation = rtP.u_max;
    } else if (rtb_Switch1 < -rtP.u_max) {
      rtb_Saturation = -rtP.u_max;
    } else {
      rtb_Saturation = rtb_Switch1;
    }

    /* End of Saturate: '<S16>/Saturation' */

    /* Gain: '<S4>/Normalize voltage' */
    rtDW.duty = 1.0 / rtP.u_max * rtb_Saturation;

    /* Sum: '<S27>/FixPt Sum1' incorporates:
     *  Constant: '<S27>/FixPt Constant'
     *  UnitDelay: '<S26>/Output'
     */
    rtb_TmpRTBAtCounterInitialoutpu = rtDW.Output_DSTATE_d +
      rtP.FixPtConstant_Value_a;

    /* Switch: '<S28>/FixPt Switch' */
    if (rtb_TmpRTBAtCounterInitialoutpu > rtP.ref_counter_prd) {
      /* Update for UnitDelay: '<S26>/Output' incorporates:
       *  Constant: '<S28>/Constant'
       */
      rtDW.Output_DSTATE_d = rtP.Constant_Value_k0;
    } else {
      /* Update for UnitDelay: '<S26>/Output' */
      rtDW.Output_DSTATE_d = rtb_TmpRTBAtCounterInitialoutpu;
    }

    /* End of Switch: '<S28>/FixPt Switch' */

    /* Sum: '<S21>/FixPt Sum1' incorporates:
     *  Constant: '<S21>/FixPt Constant'
     *  UnitDelay: '<S20>/Output'
     */
    rtb_TmpRTBAtCounterInitialoutpu = rtDW.Output_DSTATE_m +
      rtP.FixPtConstant_Value_p;

    /* Switch: '<S22>/FixPt Switch' */
    if (rtb_TmpRTBAtCounterInitialoutpu > rtP.ref_counter_prd) {
      /* Update for UnitDelay: '<S20>/Output' incorporates:
       *  Constant: '<S22>/Constant'
       */
      rtDW.Output_DSTATE_m = rtP.Constant_Value_g;
    } else {
      /* Update for UnitDelay: '<S20>/Output' */
      rtDW.Output_DSTATE_m = rtb_TmpRTBAtCounterInitialoutpu;
    }

    /* End of Switch: '<S22>/FixPt Switch' */

    /* Update for Delay: '<S17>/Delay1' */
    rtDW.Delay1_DSTATE = rtb_e;

    /* Update for Delay: '<S17>/Delay' */
    rtDW.Delay_DSTATE = rtb_differentiator;

    /* Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S17>/Gain1'
     *  Product: '<S17>/Product'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE += rtb_e * (real_T)rtb_Compare_k *
      rtP.Ki_u * rtP.DiscreteTimeIntegrator_gainval;

    /* Update for Delay: '<S16>/Delay1' */
    rtDW.Delay1_DSTATE_g = rtb_integral;

    /* Update for Delay: '<S16>/Delay' */
    rtDW.Delay_DSTATE_p = rtb_differentiator_g;

    /* Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S23>/Constant'
     *  Gain: '<S16>/Gain1'
     *  Product: '<S16>/Product'
     *  RelationalOperator: '<S23>/Compare'
     *  Sum: '<S16>/Add'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE_a += (real_T)(rtb_Switch1 -
      rtb_Saturation == rtP.Constant_Value_l) * rtb_integral * rtP.Ki_i *
      rtP.DiscreteTimeIntegrator_gainva_j;
  }

  /* End of Outputs for SubSystem: '<Root>/PID algorithm' */

  /* Switch: '<S5>/Switch1' incorporates:
   *  Constant: '<S5>/Constant'
   *  Saturate: '<S29>/[-1,1]'
   */
  if (rtDW.OutportBufferForADC_calib > rtP.Switch1_Threshold) {
    rtb_Switch1 = rtP.PWM_PERIOD / 4.0;
  } else {
    if (rtDW.duty > rtP.u1_UpperSat) {
      /* Saturate: '<S29>/[-1,1]' */
      rtb_integral = rtP.u1_UpperSat;
    } else if (rtDW.duty < rtP.u1_LowerSat) {
      /* Saturate: '<S29>/[-1,1]' */
      rtb_integral = rtP.u1_LowerSat;
    } else {
      /* Saturate: '<S29>/[-1,1]' */
      rtb_integral = rtDW.duty;
    }

    /* DataTypeConversion: '<S29>/Data Type Conversion' incorporates:
     *  Constant: '<S29>/Constant'
     *  Product: '<S29>/Divide'
     *  Saturate: '<S29>/[-1,1]'
     *  Sum: '<S29>/Subtract'
     */
    rtb_TmpRTBAtCounterInitialoutpu = (uint16_T)(rtP.PWM_PERIOD / 4.0 *
      rtb_integral + rtP.PWM_PERIOD / 4.0);

    /* Saturate: '<S29>/[0, 1000]' */
    if (rtb_TmpRTBAtCounterInitialoutpu > rtP.u1000_UpperSat) {
      rtb_Switch1 = rtP.u1000_UpperSat;
    } else if (rtb_TmpRTBAtCounterInitialoutpu < rtP.u1000_LowerSat) {
      rtb_Switch1 = rtP.u1000_LowerSat;
    } else {
      rtb_Switch1 = rtb_TmpRTBAtCounterInitialoutpu;
    }

    /* End of Saturate: '<S29>/[0, 1000]' */
  }

  /* End of Switch: '<S5>/Switch1' */

  /* S-Function (c2802xpwm): '<S5>/Symmetrical PWM' */

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.half.CMPA = (uint16_T)(rtb_Switch1);
  }

  /* If: '<S6>/If' incorporates:
   *  UnitDelay: '<S30>/Output'
   */
  if (rtDW.Output_DSTATE_j == 0U) {
    /* Outputs for IfAction SubSystem: '<S6>/Start' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    /* SignalConversion generated from: '<S32>/Data_out' incorporates:
     *  Constant: '<S32>/End'
     *  Constant: '<S32>/Start'
     *  SignalConversion generated from: '<S32>/Data'
     */
    rtb_Merge[0] = rtP.Start_Value;
    rtb_Merge[1] = rtP.End_Value;
    rtb_Merge[2] = rtPrevAction;
    rtb_Merge[3] = rtAction;

    /* Bias: '<S32>/Bias' */
    rtPrevAction = rtConstB.Width + rtP.Bias_Bias;

    /* End of Outputs for SubSystem: '<S6>/Start' */
  } else {
    /* Outputs for IfAction SubSystem: '<S6>/Data' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    /* SignalConversion generated from: '<S31>/Data_out' incorporates:
     *  Constant: '<S31>/Start'
     *  Constant: '<S31>/Start1'
     *  SignalConversion generated from: '<S31>/Data'
     */
    rtb_Merge[0] = rtPrevAction;
    rtb_Merge[1] = rtAction;
    rtb_Merge[2] = rtP.Start_Value_e;
    rtb_Merge[3] = rtP.Start1_Value;

    /* SignalConversion generated from: '<S31>/Data_width' */
    rtPrevAction = rtConstB.Width;

    /* End of Outputs for SubSystem: '<S6>/Data' */
  }

  /* End of If: '<S6>/If' */

  /* Outputs for Iterator SubSystem: '<S6>/While Iterator Subsystem' incorporates:
   *  WhileIterator: '<S33>/While Iterator'
   */
  /* MultiPortSwitch: '<S33>/Index Vector' */
  rtAction = 0;
  do {
    rtDW.IndexVector = rtb_Merge[rtAction];

    {
      if (checkSCITransmitInprogress != 1) {
        checkSCITransmitInprogress = 1;
        int16_T errFlgHeader = NOERROR;
        int16_T errFlgData = NOERROR;
        int16_T errFlgTail = NOERROR;
        errFlgData = scia_xmit((unsigned char*)&rtDW.IndexVector, 2, 2);
        checkSCITransmitInprogress = 0;
      }
    }

    rtb_Add_b = (rtPrevAction - rtAction) - 1;
    rtAction++;
  } while (rtb_Add_b != 0);

  /* End of Outputs for SubSystem: '<S6>/While Iterator Subsystem' */

  /* Sum: '<S34>/FixPt Sum1' incorporates:
   *  Constant: '<S34>/FixPt Constant'
   *  UnitDelay: '<S30>/Output'
   */
  rtb_TmpRTBAtCounterInitialoutpu = rtDW.Output_DSTATE_j +
    rtP.FixPtConstant_Value_c;
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (c280xgpio_do): '<Root>/Toggle pin 34' incorporates:
     *  Constant: '<Root>/Constant'
     */
    {
      GpioDataRegs.GPBTOGGLE.bit.GPIO34 = (uint16_T)(rtP.Constant_Value_o != 0);
    }
  }

  /* Switch: '<S35>/FixPt Switch' */
  if (rtb_TmpRTBAtCounterInitialoutpu > rtP.CounterLimited_uplimit) {
    /* Update for UnitDelay: '<S30>/Output' incorporates:
     *  Constant: '<S35>/Constant'
     */
    rtDW.Output_DSTATE_j = rtP.Constant_Value_i;
  } else {
    /* Update for UnitDelay: '<S30>/Output' */
    rtDW.Output_DSTATE_j = rtb_TmpRTBAtCounterInitialoutpu;
  }

  /* End of Switch: '<S35>/FixPt Switch' */
  rate_scheduler();
}

/* Model initialize function */
void RLC_embedded_coder_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)rtM, 0,
                sizeof(RT_MODEL));

  /* states (dwork) */
  (void) memset((void *)&rtDW, 0,
                sizeof(DW));

  /* Start for If: '<S3>/If1' */
  rtDW.If1_ActiveSubsystem = -1;

  /* Start for S-Function (c2802xadc): '<S1>/VOLTAGE' */
  if (MW_adcInitFlag == 0U) {
    InitAdc();
    MW_adcInitFlag = 1U;
  }

  config_ADC_SOC1 ();

  /* Start for S-Function (c2802xadc): '<S1>/CURRENT' */
  if (MW_adcInitFlag == 0U) {
    InitAdc();
    MW_adcInitFlag = 1U;
  }

  config_ADC_SOC2 ();

  /* Start for S-Function (c2802xpwm): '<S5>/Symmetrical PWM' */

  /*** Initialize ePWM1 modules ***/
  {
    /*  // Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 3U;          // Sync Output Select

       EPwm1Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0U;          // Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0U;          // Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
       EPwm1Regs.TBCTL.bit.SWFSYNC              = 0U;          // Software Force Sync Pulse
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFFU) | 0x32U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 1000U;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm1Regs.TBPHS.half.TBPHS               = 0U;         // Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x5FU) | 0x0U;
    EPwm1Regs.CMPA.half.CMPA = 0U;     // Counter Compare A Register
    EPwm1Regs.CMPB = 0U;               // Counter Compare B Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 96U;// Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 144U;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm1Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 0U;          // Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 0;          // Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x803FU) | 0x0U;
    EPwm1Regs.DBRED = 0U;// Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED = 0U;
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 1U;          // Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASEL              = 1U;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCAPRD               = 1U;          // EPWM1SOCA Period Select
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion B Select
       EPwm1Regs.ETPS.bit.SOCBPRD               = 1U;          // EPWM1SOCB Period Select
       EPwm1Regs.ETSEL.bit.INTEN                = 0U;          // EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          // EPWM1INTn Select
       EPwm1Regs.ETPS.bit.INTPRD                = 1U;          // EPWM1INTn Period Select
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF0FU) | 0x1901U;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x3303U) | 0x1101U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM1B
       EPwm1Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM1A action on DCAEVT1
       EPwm1Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM1A action on DCAEVT2
       EPwm1Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM1B action on DCBEVT1
       EPwm1Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM1B action on DCBEVT2
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	// Trip Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	// Digital Compare A Control Register
       EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 0U;          // DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare B Control Register
       EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
       EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
       EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
       EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
     */
    EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare Trip Select Register
       EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

       EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          // Digital Compare A Low COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          // Digital Compare B Low COMP Input Select
     */
    EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
       EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
       EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
       EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
     */
    EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	// Digital Compare Filter Control Register
       EPwm1Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
       EPwm1Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
       EPwm1Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
       EPwm1Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
     */
    EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm1Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm1Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
     */
    EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	// HRPWM Configuration Register
       EPwm1Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm1Regs.HRCNFG.bit.SELOUTB             = 1U;          // EPWMB Output Selection Bit
     */
    EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0U) | 0x20U;
    EDIS;
  }

  /* Start for S-Function (c280xgpio_do): '<Root>/Toggle pin 34' incorporates:
   *  Constant: '<Root>/Constant'
   */
  EALLOW;
  GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCFU;
  GpioCtrlRegs.GPBDIR.all |= 0x4U;
  EDIS;

  /* InitializeConditions for UnitDelay: '<S30>/Output' */
  rtDW.Output_DSTATE_j = rtP.Output_InitialCondition_a;

  /* SystemInitialize for S-Function (c28xisr_c2000): '<S3>/C28x Hardware Interrupt1' incorporates:
   *  SubSystem: '<S3>/Counter, Initial output value 0'
   */

  /* System initialize for function-call system: '<S3>/Counter, Initial output value 0' */

  /* InitializeConditions for UnitDelay: '<S11>/Output' */
  rtDW.Output_DSTATE = rtP.Output_InitialCondition;

  /* SystemInitialize for RelationalOperator: '<S10>/Compare' incorporates:
   *  Outport: '<S7>/Out1'
   */
  rtDW.Compare = rtP.Out1_Y0;
  configureGPIOExtInterrupt();

  /* End of SystemInitialize for S-Function (c28xisr_c2000): '<S3>/C28x Hardware Interrupt1' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/ADC calibration' */
  /* Start for InitialCondition: '<S2>/Initial value' */
  rtDW.Initialvalue_FirstOutputTime = true;

  /* Start for InitialCondition: '<S2>/Initial value1' */
  rtDW.Initialvalue1_FirstOutputTime = true;

  /* InitializeConditions for Delay: '<S2>/Delay1' */
  rtDW.Delay1_DSTATE_d = rtP.Delay1_InitialCondition_f;

  /* InitializeConditions for Delay: '<S2>/Delay' */
  rtDW.Delay_DSTATE_k = rtP.Delay_InitialCondition_o;

  /* SystemInitialize for DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  Outport: '<S2>/voltage_offset'
   */
  rtDW.DataTypeConversion1 = rtP.voltage_offset_Y0;

  /* SystemInitialize for DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Outport: '<S2>/current_offset'
   */
  rtDW.DataTypeConversion = rtP.current_offset_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/ADC calibration' */

  /* SystemInitialize for SignalConversion generated from: '<S9>/ADC_calib' incorporates:
   *  Outport: '<S9>/ADC_calib'
   */
  rtDW.OutportBufferForADC_calib = rtP.ADC_calib_Y0;

  /* End of SystemInitialize for SubSystem: '<S3>/Enable calibration' */

  /* SystemInitialize for IfAction SubSystem: '<S3>/Enable algorithm' */
  /* SystemInitialize for SignalConversion generated from: '<S8>/PID' incorporates:
   *  Outport: '<S8>/PID'
   */
  rtDW.OutportBufferForPID = rtP.PID_Y0;

  /* End of SystemInitialize for SubSystem: '<S3>/Enable algorithm' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/PID algorithm' */
  /* InitializeConditions for UnitDelay: '<S20>/Output' */
  rtDW.Output_DSTATE_m = rtP.Output_InitialCondition_b;

  /* InitializeConditions for Delay: '<S17>/Delay1' */
  rtDW.Delay1_DSTATE = rtP.Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<S17>/Delay' */
  rtDW.Delay_DSTATE = rtP.Delay_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE = rtP.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for UnitDelay: '<S26>/Output' */
  rtDW.Output_DSTATE_d = rtP.Output_InitialCondition_k;

  /* InitializeConditions for Delay: '<S16>/Delay1' */
  rtDW.Delay1_DSTATE_g = rtP.Delay1_InitialCondition_p;

  /* InitializeConditions for Delay: '<S16>/Delay' */
  rtDW.Delay_DSTATE_p = rtP.Delay_InitialCondition_c;

  /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE_a = rtP.DiscreteTimeIntegrator_IC_g;

  /* SystemInitialize for Gain: '<S4>/Normalize voltage' incorporates:
   *  Outport: '<S4>/duty'
   */
  rtDW.duty = rtP.duty_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/PID algorithm' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
