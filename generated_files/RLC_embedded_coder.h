/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: RLC_embedded_coder.h
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

#ifndef RTW_HEADER_RLC_embedded_coder_h_
#define RTW_HEADER_RLC_embedded_coder_h_
#ifndef RLC_embedded_coder_COMMON_INCLUDES_
#define RLC_embedded_coder_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "F2806x_Device.h"
#include "DSP28xx_SciUtil.h"
#include "F2806x_Examples.h"
#include "IQmathLib.h"
#include "F2806x_Gpio.h"
#endif                                 /* RLC_embedded_coder_COMMON_INCLUDES_ */

#include <string.h>
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define RLC_embedded_coder_M           (rtM)

extern void init_SCI(void);
extern void init_SCI_GPIO(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_XBAR(void);
extern void config_ePWM_TBSync(void);

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T duty;                         /* '<S4>/Normalize voltage' */
  real_T OutportBufferForPID;          /* '<S8>/Constant' */
  real_T OutportBufferForADC_calib;    /* '<S9>/Constant' */
  real_T Delay1_DSTATE;                /* '<S17>/Delay1' */
  real_T Delay_DSTATE;                 /* '<S17>/Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S17>/Discrete-Time Integrator' */
  real_T Delay1_DSTATE_g;              /* '<S16>/Delay1' */
  real_T Delay_DSTATE_p;               /* '<S16>/Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_a;/* '<S16>/Discrete-Time Integrator' */
  uint32_T Output_DSTATE;              /* '<S11>/Output' */
  int16_T VOLTAGE;                     /* '<S1>/VOLTAGE' */
  int16_T CURRENT;                     /* '<S1>/CURRENT' */
  int16_T DataTypeConversion1;         /* '<S2>/Data Type Conversion1' */
  int16_T DataTypeConversion;          /* '<S2>/Data Type Conversion' */
  int16_T IndexVector;                 /* '<S33>/Index Vector' */
  int16_T Delay1_DSTATE_d;             /* '<S2>/Delay1' */
  int16_T Delay_DSTATE_k;              /* '<S2>/Delay' */
  int16_T If1_ActiveSubsystem;         /* '<S3>/If1' */
  uint16_T Compare;                    /* '<S10>/Compare' */
  uint16_T Output_DSTATE_j;            /* '<S30>/Output' */
  uint16_T Output_DSTATE_m;            /* '<S20>/Output' */
  uint16_T Output_DSTATE_d;            /* '<S26>/Output' */
  boolean_T Initialvalue_FirstOutputTime;/* '<S2>/Initial value' */
  boolean_T Initialvalue1_FirstOutputTime;/* '<S2>/Initial value1' */
} DW;

/* Invariant block signals (default storage) */
typedef struct {
  const int16_T Width;                 /* '<S6>/Width' */
} ConstB;

/* Parameters (default storage) */
struct P_ {
  real_T Kd_u;                         /* Variable: Kd_u
                                        * Referenced by: '<S17>/Gain2'
                                        */
  real_T Ki_i;                         /* Variable: Ki_i
                                        * Referenced by: '<S16>/Gain1'
                                        */
  real_T Ki_u;                         /* Variable: Ki_u
                                        * Referenced by: '<S17>/Gain1'
                                        */
  real_T Kp_i;                         /* Variable: Kp_i
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T Kp_u;                         /* Variable: Kp_u
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T PWM_PERIOD;                   /* Variable: PWM_PERIOD
                                        * Referenced by:
                                        *   '<S5>/Constant'
                                        *   '<S29>/Constant'
                                        */
  real_T SAMPLE_TIME;                  /* Variable: SAMPLE_TIME
                                        * Referenced by:
                                        *   '<S16>/T sample'
                                        *   '<S16>/T_sample'
                                        *   '<S17>/T sample'
                                        *   '<S17>/T_sample'
                                        */
  real_T current_offset;               /* Variable: current_offset
                                        * Referenced by: '<S2>/Initial value1'
                                        */
  real_T i_max;                        /* Variable: i_max
                                        * Referenced by: '<S17>/Saturation'
                                        */
  real_T offset_filter;                /* Variable: offset_filter
                                        * Referenced by:
                                        *   '<S2>/Constant3'
                                        *   '<S2>/Constant4'
                                        */
  real_T ref_value_high;               /* Variable: ref_value_high
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T ref_value_low;                /* Variable: ref_value_low
                                        * Referenced by: '<S15>/Constant1'
                                        */
  real_T tau;                          /* Variable: tau
                                        * Referenced by:
                                        *   '<S17>/Constant'
                                        *   '<S17>/Constant1'
                                        */
  real_T u_max;                        /* Variable: u_max
                                        * Referenced by:
                                        *   '<S4>/Normalize voltage'
                                        *   '<S16>/Saturation'
                                        */
  real_T voltage_offset;               /* Variable: voltage_offset
                                        * Referenced by: '<S2>/Initial value'
                                        */
  real32_T ADC_gain;                   /* Variable: ADC_gain
                                        * Referenced by:
                                        *   '<S14>/adc gain'
                                        *   '<S14>/adc gain2'
                                        */
  real32_T current_gain;               /* Variable: current_gain
                                        * Referenced by: '<S14>/current gain'
                                        */
  real32_T voltage_gain;               /* Variable: voltage_gain
                                        * Referenced by: '<S14>/voltage gain'
                                        */
  uint16_T ref_counter_cmpr;           /* Variable: ref_counter_cmpr
                                        * Referenced by: '<S19>/Constant'
                                        */
  uint16_T ref_counter_prd;            /* Variable: ref_counter_prd
                                        * Referenced by:
                                        *   '<S22>/FixPt Switch'
                                        *   '<S28>/FixPt Switch'
                                        */
  real_T PID_current_Kd;               /* Mask Parameter: PID_current_Kd
                                        * Referenced by: '<S16>/Gain2'
                                        */
  real_T PID_current_tau;              /* Mask Parameter: PID_current_tau
                                        * Referenced by:
                                        *   '<S16>/Constant'
                                        *   '<S16>/Constant1'
                                        */
  uint32_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S13>/FixPt Switch'
                                        */
  uint32_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S10>/Constant'
                                       */
  uint16_T CompareToConstant_const_b;
                                    /* Mask Parameter: CompareToConstant_const_b
                                     * Referenced by: '<S25>/Constant'
                                     */
  uint16_T CounterLimited_uplimit;     /* Mask Parameter: CounterLimited_uplimit
                                        * Referenced by: '<S35>/FixPt Switch'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T ADC_calib_Y0;                 /* Expression: [0]
                                        * Referenced by: '<S9>/ADC_calib'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T PID_Y0;                       /* Expression: [0]
                                        * Referenced by: '<S8>/PID'
                                        */
  real_T Constant_Value_b;             /* Expression: 1
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Constant1_Value_k;            /* Expression: 4
                                        * Referenced by: '<S18>/Constant1'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T duty_Y0;                      /* Computed Parameter: duty_Y0
                                        * Referenced by: '<S4>/duty'
                                        */
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S17>/Delay1'
                                        */
  real_T Gain3_Gain;                   /* Expression: 2
                                        * Referenced by: '<S17>/Gain3'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S17>/Delay'
                                        */
  real_T Gain4_Gain;                   /* Expression: 2
                                        * Referenced by: '<S17>/Gain4'
                                        */
  real_T Gain5_Gain;                   /* Expression: 2
                                        * Referenced by: '<S17>/Gain5'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S17>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S17>/Discrete-Time Integrator'
                                        */
  real_T Delay1_InitialCondition_p;    /* Expression: 0.0
                                        * Referenced by: '<S16>/Delay1'
                                        */
  real_T Gain3_Gain_e;                 /* Expression: 2
                                        * Referenced by: '<S16>/Gain3'
                                        */
  real_T Delay_InitialCondition_c;     /* Expression: 0.0
                                        * Referenced by: '<S16>/Delay'
                                        */
  real_T Gain4_Gain_g;                 /* Expression: 2
                                        * Referenced by: '<S16>/Gain4'
                                        */
  real_T Gain5_Gain_e;                 /* Expression: 2
                                        * Referenced by: '<S16>/Gain5'
                                        */
  real_T DiscreteTimeIntegrator_gainva_j;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                           * Referenced by: '<S16>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_g;  /* Expression: 0
                                        * Referenced by: '<S16>/Discrete-Time Integrator'
                                        */
  real_T u1_UpperSat;                  /* Expression: 1
                                        * Referenced by: '<S29>/[-1,1]'
                                        */
  real_T u1_LowerSat;                  /* Expression: -1
                                        * Referenced by: '<S29>/[-1,1]'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S5>/Switch1'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S14>/Gain'
                                        */
  real32_T Gain3_Gain_g;               /* Computed Parameter: Gain3_Gain_g
                                        * Referenced by: '<S14>/Gain3'
                                        */
  uint32_T Constant_Value_o3;          /* Computed Parameter: Constant_Value_o3
                                        * Referenced by: '<S13>/Constant'
                                        */
  uint32_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S11>/Output'
                                   */
  uint32_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S12>/FixPt Constant'
                                       */
  int16_T voltage_offset_Y0;           /* Computed Parameter: voltage_offset_Y0
                                        * Referenced by: '<S2>/voltage_offset'
                                        */
  int16_T current_offset_Y0;           /* Computed Parameter: current_offset_Y0
                                        * Referenced by: '<S2>/current_offset'
                                        */
  int16_T Delay1_InitialCondition_f;
                                /* Computed Parameter: Delay1_InitialCondition_f
                                 * Referenced by: '<S2>/Delay1'
                                 */
  int16_T Delay_InitialCondition_o;
                                 /* Computed Parameter: Delay_InitialCondition_o
                                  * Referenced by: '<S2>/Delay'
                                  */
  int16_T End_Value;                   /* Computed Parameter: End_Value
                                        * Referenced by: '<S32>/End'
                                        */
  int16_T Start_Value;                 /* Computed Parameter: Start_Value
                                        * Referenced by: '<S32>/Start'
                                        */
  int16_T Bias_Bias;                   /* Computed Parameter: Bias_Bias
                                        * Referenced by: '<S32>/Bias'
                                        */
  int16_T Start_Value_e;               /* Computed Parameter: Start_Value_e
                                        * Referenced by: '<S31>/Start'
                                        */
  int16_T Start1_Value;                /* Computed Parameter: Start1_Value
                                        * Referenced by: '<S31>/Start1'
                                        */
  uint16_T Constant_Value_g;           /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S22>/Constant'
                                        */
  uint16_T Constant_Value_k0;          /* Computed Parameter: Constant_Value_k0
                                        * Referenced by: '<S28>/Constant'
                                        */
  uint16_T Output_InitialCondition_b;
                                /* Computed Parameter: Output_InitialCondition_b
                                 * Referenced by: '<S20>/Output'
                                 */
  uint16_T Output_InitialCondition_k;
                                /* Computed Parameter: Output_InitialCondition_k
                                 * Referenced by: '<S26>/Output'
                                 */
  uint16_T FixPtConstant_Value_a;   /* Computed Parameter: FixPtConstant_Value_a
                                     * Referenced by: '<S27>/FixPt Constant'
                                     */
  uint16_T FixPtConstant_Value_p;   /* Computed Parameter: FixPtConstant_Value_p
                                     * Referenced by: '<S21>/FixPt Constant'
                                     */
  uint16_T u1000_UpperSat;             /* Computed Parameter: u1000_UpperSat
                                        * Referenced by: '<S29>/[0, 1000]'
                                        */
  uint16_T u1000_LowerSat;             /* Computed Parameter: u1000_LowerSat
                                        * Referenced by: '<S29>/[0, 1000]'
                                        */
  uint16_T Constant_Value_i;           /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S35>/Constant'
                                        */
  uint16_T Output_InitialCondition_a;
                                /* Computed Parameter: Output_InitialCondition_a
                                 * Referenced by: '<S30>/Output'
                                 */
  uint16_T FixPtConstant_Value_c;   /* Computed Parameter: FixPtConstant_Value_c
                                     * Referenced by: '<S34>/FixPt Constant'
                                     */
  uint16_T Out1_Y0;                    /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S7>/Out1'
                                        */
  uint16_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<S4>/Manual Switch'
                               */
};

/* Parameters (default storage) */
typedef struct P_ P;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P rtP;

/* Block signals and states (default storage) */
extern DW rtDW;
extern const ConstB rtConstB;          /* constant block i/o */

/* Model entry point functions */
extern void RLC_embedded_coder_initialize(void);
extern void RLC_embedded_coder_step(void);
extern volatile boolean_T runModel;

/* Real-time Model object */
extern RT_MODEL *const rtM;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S11>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S12>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S20>/Data Type Propagation' : Unused code path elimination
 * Block '<S21>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S26>/Data Type Propagation' : Unused code path elimination
 * Block '<S27>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S30>/Data Type Propagation' : Unused code path elimination
 * Block '<S34>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/FixPt Data Type Duplicate1' : Unused code path elimination
 */

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
 * '<Root>' : 'RLC_embedded_coder'
 * '<S1>'   : 'RLC_embedded_coder/ADC'
 * '<S2>'   : 'RLC_embedded_coder/ADC calibration'
 * '<S3>'   : 'RLC_embedded_coder/ADC calibration selector'
 * '<S4>'   : 'RLC_embedded_coder/PID algorithm'
 * '<S5>'   : 'RLC_embedded_coder/PWM'
 * '<S6>'   : 'RLC_embedded_coder/Serial Send'
 * '<S7>'   : 'RLC_embedded_coder/ADC calibration selector/Counter, Initial output value 0'
 * '<S8>'   : 'RLC_embedded_coder/ADC calibration selector/Enable algorithm'
 * '<S9>'   : 'RLC_embedded_coder/ADC calibration selector/Enable calibration'
 * '<S10>'  : 'RLC_embedded_coder/ADC calibration selector/Counter, Initial output value 0/Compare To Constant'
 * '<S11>'  : 'RLC_embedded_coder/ADC calibration selector/Counter, Initial output value 0/Counter Free-Running'
 * '<S12>'  : 'RLC_embedded_coder/ADC calibration selector/Counter, Initial output value 0/Counter Free-Running/Increment Real World'
 * '<S13>'  : 'RLC_embedded_coder/ADC calibration selector/Counter, Initial output value 0/Counter Free-Running/Wrap To Zero'
 * '<S14>'  : 'RLC_embedded_coder/PID algorithm/Convert to float'
 * '<S15>'  : 'RLC_embedded_coder/PID algorithm/Generate reference'
 * '<S16>'  : 'RLC_embedded_coder/PID algorithm/PID_current'
 * '<S17>'  : 'RLC_embedded_coder/PID algorithm/PID_voltage'
 * '<S18>'  : 'RLC_embedded_coder/PID algorithm/Reference current'
 * '<S19>'  : 'RLC_embedded_coder/PID algorithm/Generate reference/Compare To Constant'
 * '<S20>'  : 'RLC_embedded_coder/PID algorithm/Generate reference/ref_period'
 * '<S21>'  : 'RLC_embedded_coder/PID algorithm/Generate reference/ref_period/Increment Real World'
 * '<S22>'  : 'RLC_embedded_coder/PID algorithm/Generate reference/ref_period/Wrap To Zero'
 * '<S23>'  : 'RLC_embedded_coder/PID algorithm/PID_current/Compare To Zero'
 * '<S24>'  : 'RLC_embedded_coder/PID algorithm/PID_voltage/Compare To Zero'
 * '<S25>'  : 'RLC_embedded_coder/PID algorithm/Reference current/Compare To Constant'
 * '<S26>'  : 'RLC_embedded_coder/PID algorithm/Reference current/Counter'
 * '<S27>'  : 'RLC_embedded_coder/PID algorithm/Reference current/Counter/Increment Real World'
 * '<S28>'  : 'RLC_embedded_coder/PID algorithm/Reference current/Counter/Wrap To Zero'
 * '<S29>'  : 'RLC_embedded_coder/PWM/Calculate CMPA register'
 * '<S30>'  : 'RLC_embedded_coder/Serial Send/Counter Limited'
 * '<S31>'  : 'RLC_embedded_coder/Serial Send/Data'
 * '<S32>'  : 'RLC_embedded_coder/Serial Send/Start'
 * '<S33>'  : 'RLC_embedded_coder/Serial Send/While Iterator Subsystem'
 * '<S34>'  : 'RLC_embedded_coder/Serial Send/Counter Limited/Increment Real World'
 * '<S35>'  : 'RLC_embedded_coder/Serial Send/Counter Limited/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_RLC_embedded_coder_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
