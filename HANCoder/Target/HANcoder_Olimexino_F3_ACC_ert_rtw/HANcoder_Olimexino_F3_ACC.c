/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HANcoder_Olimexino_F3_ACC.c
 *
 * Code generated for Simulink model 'HANcoder_Olimexino_F3_ACC'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Thu Jun  8 16:32:35 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HANcoder_Olimexino_F3_ACC.h"
#include "HANcoder_Olimexino_F3_ACC_types.h"
#include <math.h>
#include "rtwtypes.h"
#include "HANcoder_Olimexino_F3_ACC_private.h"
#include "zero_crossing_types.h"

/* map ByteSwap function */
#define ByteSwap(x)                    (ByteSwap_x((uint8_t *) &x, sizeof(x)))

void PwmoutIRQ_PWMOUT_MODULE_TIM2(void);

/* Exported block signals */
real_T Sim_dist;                       /* '<S12>/Discrete-Time Integrator' */
real_T own_dist;                       /* '<S12>/Discrete-Time Integrator1' */
real_T Sim_GAP;                        /* '<S12>/Subtract' */
real_T E;                              /* '<S15>/Sum1' */
real_T switcher;                       /* '<S14>/Switch1' */
real_T Speed_setpoint;                 /* '<S14>/Saturation' */
real_T speed_Right;                    /* '<S12>/Moving Average' */
uint32_T SI_FreeHeap;                  /* '<S132>/Level-2 M-file S-Function' */
uint32_T SI_FreeStack;                 /* '<S133>/Level-2 M-file S-Function' */
uint16_T control_effort;               /* '<S16>/600 - 0 N1' */
int16_T camera_gap;                    /* '<S128>/In1' */
int16_T speed_setpoint;                /* '<S128>/In2' */
int16_T Distance_setpoint;             /* '<S128>/In3' */
int16_T gap_valid;                     /* '<S128>/In4' */
uint8_T SI_CPUload;                    /* '<S131>/Level-2 M-file S-Function' */
boolean_T ON_OFF;                      /* '<S1>/Signal Conversion' */
boolean_T cc_acc_switcher;             /* '<S17>/AND' */

/* Block signals (default storage) */
BlockIO rtB;

/* Block states (default storage) */
D_Work rtDWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates rtPrevZCSigState;

/* Forward declaration for local functions */
static void SystemCore_setup(dsp_simulink_MovingAverage *obj);
static tCanDataTypes canRxData_0_291U;
static tCanDataTypes canRxData_0_1U;

/*
 * Swaps the values of two bytes.
 * a, b pointers to data values that need swapping
 */
static void swap(unsigned char *a, unsigned char *b)
{
  register char i = *a;
  *a = *b;
  *b = i;
}                                      /*** end of swap ***/

/*
 * Swaps all bytes in b. Typically used to fix endianes.
 * b pointer to data with bytes to swap
 * n number of bytes to swap
 */
void ByteSwap_x(uint8_t *b, size_t n)
{
  int i = 0;
  int j = n-1;
  while (i<j) {
    swap(&b[i], &b[j]);
    i++, j--;
  }
}

void PwmoutIRQ_PWMOUT_MODULE_TIM2(void)
{
}

static void SystemCore_setup(dsp_simulink_MovingAverage *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj->NumChannels = 1;
  obj->FrameLength = 1;
  obj->_pobj0.isInitialized = 0;
  obj->_pobj0.isInitialized = 0;
  obj->pStatistic = &obj->_pobj0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

/* Model step function */
void HANcoder_Olimexino_F3_ACC_step(void)
{
  /* local block i/o variables */
  uint16_T rtb_SFunction_o2;
  uint16_T rtb_SFunction_o3;
  uint16_T rtb_SFunction_o4;
  uint16_T rtb_SFunction_o5;
  int16_T rtb_SFunction_o2_m;
  int16_T rtb_SFunction_o3_d;
  int16_T rtb_SFunction_o4_k;
  int16_T rtb_SFunction_o5_l;
  int8_T rtb_SFunction_o1;
  int8_T rtb_SFunction_o1_l;
  boolean_T rtb_Level2MfileSFunction;
  g_dsp_internal_SlidingWindowAve *obj;
  real_T csumrev[9];
  real_T modValueRev;
  real_T rtb_DeadZone;
  real_T rtb_Gain_k;
  real_T rtb_IntegralGain_f;
  real_T rtb_Integrator_n;
  real_T rtb_Sum;
  real_T u2;
  real_T z;
  int32_T i;
  int8_T tmp;
  int8_T tmp_0;
  boolean_T rtb_RelationalOperator;
  boolean_T rtb_fixforDTpropagationissue;

  /* M-S-Function: '<S5>/Level-2 M-file S-Function' */
  /* read from digital input */
  rtb_Level2MfileSFunction = DiginGet(DIGIN_PORTC_PIN9);

  /* Outputs for Triggered SubSystem: '<S6>/J-K Flip-Flop' incorporates:
   *  TriggerPort: '<S10>/Trigger'
   */
  if ((!rtb_Level2MfileSFunction) && (rtPrevZCSigState.JKFlipFlop_Trig_ZCE !=
       ZERO_ZCSIG)) {
    /* CombinatorialLogic: '<S10>/Logic' incorporates:
     *  Memory: '<S10>/Memory'
     *  Memory generated from: '<S6>/J-K Flip-Flop'
     */
    i = (int32_T)(((((uint32_T)rtDWork.Memory_PreviousInput_b << 1) +
                    rtDWork.TmpLatchAtJKFlipFlopInport1_Pre) << 1) +
                  rtDWork.TmpLatchAtJKFlipFlopInport2_Pre);
    rtB.Logic[0U] = rtConstP.Logic_table[(uint32_T)i];
    rtB.Logic[1U] = rtConstP.Logic_table[(uint32_T)i + 8U];

    /* Update for Memory: '<S10>/Memory' */
    rtDWork.Memory_PreviousInput_b = rtB.Logic[0];
  }

  rtPrevZCSigState.JKFlipFlop_Trig_ZCE = rtb_Level2MfileSFunction;

  /* End of Outputs for SubSystem: '<S6>/J-K Flip-Flop' */

  /* SignalConversion: '<S1>/Signal Conversion' */
  ON_OFF = rtB.Logic[0];

  /* Outputs for Enabled SubSystem: '<S1>/Subsystem' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (ON_OFF) {
    rtDWork.Subsystem_MODE = true;

    /* M-S-Function: '<S126>/S-Function' incorporates:
     *  Constant: '<S12>/Constant1'
     */

    /* read the message data and store the new parameter */
    rtb_SFunction_o1 = CanIoGetMessage(0, 291U, NULL,
      &canRxData_0_291U.uint8_T_info[0], NULL);

    /* process the message data */
    if (rtb_SFunction_o1 > 0) {
      /* read the data */
      rtb_SFunction_o2_m = canRxData_0_291U.int16_T_info[0];
      rtb_SFunction_o3_d = canRxData_0_291U.int16_T_info[1];
      rtb_SFunction_o4_k = canRxData_0_291U.int16_T_info[2];
      rtb_SFunction_o5_l = canRxData_0_291U.int16_T_info[3];
    }

    /* Outputs for Enabled SubSystem: '<S126>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S128>/Enable'
     */
    if (rtb_SFunction_o1 > 0) {
      /* SignalConversion generated from: '<S128>/In1' */
      camera_gap = rtb_SFunction_o2_m;

      /* SignalConversion generated from: '<S128>/In2' */
      speed_setpoint = rtb_SFunction_o3_d;

      /* SignalConversion generated from: '<S128>/In3' */
      Distance_setpoint = rtb_SFunction_o4_k;

      /* SignalConversion generated from: '<S128>/In4' */
      gap_valid = rtb_SFunction_o5_l;
    }

    /* End of Outputs for SubSystem: '<S126>/Enabled Subsystem' */

    /* Gain: '<S12>/Gain1' */
    rtb_DeadZone = (real_T)16777 * 5.9604644775390625E-8 * (real_T)
      speed_setpoint;

    /* Gain: '<S15>/Gain' */
    rtb_Integrator_n = 1.0 * rtb_DeadZone;

    /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
    Sim_dist = rtDWork.DiscreteTimeIntegrator_DSTATE;

    /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' */
    own_dist = rtDWork.DiscreteTimeIntegrator1_DSTATE;

    /* Sum: '<S12>/Subtract' */
    Sim_GAP = Sim_dist - own_dist;

    /* Sum: '<S15>/Sum1' */
    E = Sim_GAP - (real_T)Distance_setpoint;

    /* Sum: '<S63>/Sum' incorporates:
     *  DiscreteIntegrator: '<S53>/Integrator'
     *  Gain: '<S58>/Proportional Gain'
     */
    rtb_Sum = 1.0 * E + rtDWork.Integrator_DSTATE;

    /* Switch: '<S46>/Switch' incorporates:
     *  Constant: '<S15>/Constant'
     *  RelationalOperator: '<S46>/u_GTE_up'
     *  RelationalOperator: '<S46>/u_GT_lo'
     *  Switch: '<S46>/Switch1'
     */
    if (rtb_Sum >= rtb_Integrator_n) {
      modValueRev = rtb_Integrator_n;
    } else if (rtb_Sum > 0.0) {
      /* Switch: '<S46>/Switch1' */
      modValueRev = rtb_Sum;
    } else {
      modValueRev = 0.0;
    }

    /* Sum: '<S46>/Diff' incorporates:
     *  Switch: '<S46>/Switch'
     */
    rtb_IntegralGain_f = rtb_Sum - modValueRev;

    /* RelationalOperator: '<S43>/Relational Operator' incorporates:
     *  Constant: '<S43>/Clamping_zero'
     */
    rtb_RelationalOperator = (0.0 != rtb_IntegralGain_f);

    /* RelationalOperator: '<S43>/fix for DT propagation issue' incorporates:
     *  Constant: '<S43>/Clamping_zero'
     */
    rtb_fixforDTpropagationissue = (rtb_IntegralGain_f > 0.0);

    /* Switch: '<S61>/Switch2' incorporates:
     *  RelationalOperator: '<S61>/LowerRelop1'
     */
    if (rtb_Sum <= rtb_Integrator_n) {
      /* Switch: '<S61>/Switch' incorporates:
       *  Constant: '<S15>/Constant'
       *  RelationalOperator: '<S61>/UpperRelop'
       */
      if (rtb_Sum < 0.0) {
        rtb_Integrator_n = 0.0;
      } else {
        rtb_Integrator_n = rtb_Sum;
      }

      /* End of Switch: '<S61>/Switch' */
    }

    /* End of Switch: '<S61>/Switch2' */

    /* Logic: '<S17>/AND' incorporates:
     *  Constant: '<S124>/Constant'
     *  Gain: '<S17>/Enter margin'
     *  Gain: '<S17>/Exit margin'
     *  Logic: '<S17>/NAND'
     *  Memory: '<S17>/Memory'
     *  RelationalOperator: '<S124>/Compare'
     *  RelationalOperator: '<S17>/Relational Operator'
     *  RelationalOperator: '<S17>/Relational Operator1'
     */
    cc_acc_switcher = ((Sim_GAP >= (real_T)(24576 * Distance_setpoint) *
                        0.0001220703125) && ((Sim_GAP > (real_T)(16384 *
      Distance_setpoint) * 0.000244140625) || (rtDWork.Memory_PreviousInput !=
      false)));

    /* Switch: '<S14>/Switch1' */
    if (gap_valid > 0) {
      /* Switch: '<S14>/Switch1' */
      switcher = cc_acc_switcher;
    } else {
      /* Switch: '<S14>/Switch1' incorporates:
       *  Constant: '<S14>/Constant'
       */
      switcher = 1.0;
    }

    /* End of Switch: '<S14>/Switch1' */

    /* Switch: '<S14>/Switch' */
    if (switcher <= 0.0) {
      rtb_DeadZone = rtb_Integrator_n;
    }

    /* End of Switch: '<S14>/Switch' */

    /* Sum: '<S66>/SumI1' incorporates:
     *  Gain: '<S50>/Integral Gain'
     *  Gain: '<S65>/Kt'
     *  Sum: '<S65>/SumI3'
     */
    rtb_IntegralGain_f = (rtb_DeadZone - rtb_Integrator_n) * 1.0 + 0.1 * E;

    /* Switch: '<S43>/Switch1' incorporates:
     *  Constant: '<S43>/Constant'
     *  Constant: '<S43>/Constant2'
     */
    if (rtb_fixforDTpropagationissue) {
      tmp = 1;
    } else {
      tmp = (-1);
    }

    /* Switch: '<S43>/Switch2' incorporates:
     *  Constant: '<S43>/Clamping_zero'
     *  Constant: '<S43>/Constant3'
     *  Constant: '<S43>/Constant4'
     *  RelationalOperator: '<S43>/fix for DT propagation issue1'
     */
    if (rtb_IntegralGain_f > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = (-1);
    }

    /* Switch: '<S43>/Switch' incorporates:
     *  Constant: '<S43>/Constant1'
     *  Logic: '<S43>/AND3'
     *  RelationalOperator: '<S43>/Equal1'
     *  Switch: '<S43>/Switch1'
     *  Switch: '<S43>/Switch2'
     */
    if (rtb_RelationalOperator && (tmp == tmp_0)) {
      rtb_Integrator_n = 0.0;
    } else {
      rtb_Integrator_n = rtb_IntegralGain_f;
    }

    /* End of Switch: '<S43>/Switch' */

    /* Saturate: '<S14>/Saturation' */
    if (rtb_DeadZone > 3.0) {
      /* Saturate: '<S14>/Saturation' */
      Speed_setpoint = 3.0;
    } else if (rtb_DeadZone < 0.0) {
      /* Saturate: '<S14>/Saturation' */
      Speed_setpoint = 0.0;
    } else {
      /* Saturate: '<S14>/Saturation' */
      Speed_setpoint = rtb_DeadZone;
    }

    /* End of Saturate: '<S14>/Saturation' */

    /* SampleTimeMath: '<S73>/TSamp'
     *
     * About '<S73>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_Sum = Speed_setpoint * 100.0;

    /* M-S-Function: '<S125>/S-Function' incorporates:
     *  Constant: '<S12>/Constant2'
     */

    /* read the message data and store the new parameter */
    rtb_SFunction_o1_l = CanIoGetMessage(0, 1U, NULL,
      &canRxData_0_1U.uint8_T_info[0], NULL);

    /* process the message data */
    if (rtb_SFunction_o1_l > 0) {
      /* read the data */
      rtb_SFunction_o2 = canRxData_0_1U.uint16_T_info[0];
      rtb_SFunction_o3 = canRxData_0_1U.uint16_T_info[1];
      rtb_SFunction_o4 = canRxData_0_1U.uint16_T_info[2];
      rtb_SFunction_o5 = canRxData_0_1U.uint16_T_info[3];
    }

    /* Outputs for Enabled SubSystem: '<S125>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S127>/Enable'
     */
    if (rtb_SFunction_o1_l > 0) {
      /* SignalConversion generated from: '<S127>/In1' */
      rtB.In1 = rtb_SFunction_o2;
    }

    /* End of Outputs for SubSystem: '<S125>/Enabled Subsystem' */

    /* Gain: '<S12>/Gain' */
    rtb_Gain_k = (real_T)((uint16_T)53687U) * 1.862645149230957E-9 * (real_T)
      rtB.In1;

    /* MATLABSystem: '<S12>/Moving Average' */
    if (rtDWork.obj.TunablePropsChanged) {
      rtDWork.obj.TunablePropsChanged = false;
    }

    obj = rtDWork.obj.pStatistic;
    if (obj->isInitialized != 1) {
      obj->isSetupComplete = false;
      obj->isInitialized = 1;
      obj->pCumSum = 0.0;
      for (i = 0; i < 9; i++) {
        obj->pCumSumRev[i] = 0.0;
      }

      obj->pCumRevIndex = 1.0;
      obj->pModValueRev = 0.0;
      obj->isSetupComplete = true;
      obj->pCumSum = 0.0;
      for (i = 0; i < 9; i++) {
        obj->pCumSumRev[i] = 0.0;
      }

      obj->pCumRevIndex = 1.0;
      obj->pModValueRev = 0.0;
    }

    rtb_DeadZone = obj->pCumRevIndex;
    rtb_IntegralGain_f = obj->pCumSum;
    for (i = 0; i < 9; i++) {
      csumrev[i] = obj->pCumSumRev[i];
    }

    modValueRev = obj->pModValueRev;
    z = 0.0;

    /* MATLABSystem: '<S12>/Moving Average' */
    speed_Right = 0.0;

    /* MATLABSystem: '<S12>/Moving Average' */
    rtb_IntegralGain_f += rtb_Gain_k;
    if (modValueRev == 0.0) {
      z = csumrev[(int32_T)rtb_DeadZone - 1] + rtb_IntegralGain_f;
    }

    csumrev[(int32_T)rtb_DeadZone - 1] = rtb_Gain_k;
    if (rtb_DeadZone != 9.0) {
      rtb_DeadZone++;
    } else {
      rtb_DeadZone = 1.0;
      rtb_IntegralGain_f = 0.0;
      for (i = 7; i >= 0; i--) {
        csumrev[i] += csumrev[i + 1];
      }
    }

    if (modValueRev == 0.0) {
      /* MATLABSystem: '<S12>/Moving Average' */
      speed_Right = z / 10.0;
    }

    obj->pCumSum = rtb_IntegralGain_f;
    for (i = 0; i < 9; i++) {
      obj->pCumSumRev[i] = csumrev[i];
    }

    obj->pCumRevIndex = rtb_DeadZone;
    if (modValueRev > 0.0) {
      obj->pModValueRev = modValueRev - 1.0;
    } else {
      obj->pModValueRev = 0.0;
    }

    /* Sum: '<S16>/Sum1' incorporates:
     *  Gain: '<S16>/Gain'
     *  Gain: '<S16>/Gain1'
     */
    rtb_IntegralGain_f = 100.0 * Speed_setpoint - 100.0 * speed_Right;

    /* Sum: '<S116>/Sum' incorporates:
     *  DiscreteIntegrator: '<S107>/Integrator'
     *  Gain: '<S112>/Proportional Gain'
     */
    rtb_DeadZone = 1.0 * rtb_IntegralGain_f + rtDWork.Integrator_DSTATE_a;

    /* Saturate: '<S114>/Saturation' */
    if (rtb_DeadZone > 600.0) {
      modValueRev = 600.0;
    } else if (rtb_DeadZone < 0.0) {
      modValueRev = 0.0;
    } else {
      modValueRev = rtb_DeadZone;
    }

    /* Sum: '<S16>/Add' incorporates:
     *  Gain: '<S16>/Force to PWM'
     *  Gain: '<S71>/Gain'
     *  Gain: '<S71>/Gain1'
     *  SampleTimeMath: '<S73>/TSamp'
     *  Saturate: '<S114>/Saturation'
     *  Sum: '<S71>/Add'
     *  Sum: '<S73>/Diff'
     *  UnitDelay: '<S73>/UD'
     *
     * About '<S73>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     *
     * Block description for '<S73>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S73>/UD':
     *
     *  Store in Global RAM
     */
    modValueRev += (real_T)(int16_T)floor(((rtb_Sum - rtDWork.UD_DSTATE) *
      1000.0 + 50.0 * Speed_setpoint) * 2.046);

    /* Saturate: '<S16>/600 - 0 N1' */
    z = ((uint16_T)0U);
    u2 = ((uint16_T)600U);
    if (modValueRev > u2) {
      /* Saturate: '<S16>/600 - 0 N1' */
      control_effort = (uint16_T)u2;
    } else if (modValueRev < z) {
      /* Saturate: '<S16>/600 - 0 N1' */
      control_effort = (uint16_T)z;
    } else {
      /* Saturate: '<S16>/600 - 0 N1' */
      control_effort = (uint16_T)modValueRev;
    }

    /* End of Saturate: '<S16>/600 - 0 N1' */
    /* DeadZone: '<S100>/DeadZone' */
    if (rtb_DeadZone > 600.0) {
      rtb_DeadZone -= 600.0;
    } else if (rtb_DeadZone >= 0.0) {
      rtb_DeadZone = 0.0;
    } else {
      rtb_DeadZone -= 0.0;
    }

    /* End of DeadZone: '<S100>/DeadZone' */

    /* Gain: '<S104>/Integral Gain' */
    rtb_IntegralGain_f *= 0.7;

    /* Update for M-S-Function: '<S129>/Level-2 M-file S-Function' */
    /* set the new duty cycle */
    PwmoutSet(PWMOUT_TIM2_PIN_PA1, control_effort);

    /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S12>/Constant'
     */
    rtDWork.DiscreteTimeIntegrator_DSTATE += 0.01 * 1.0;

    /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' */
    rtDWork.DiscreteTimeIntegrator1_DSTATE += 0.01 * rtb_Gain_k;

    /* Update for DiscreteIntegrator: '<S53>/Integrator' */
    rtDWork.Integrator_DSTATE += 1.0 * rtb_Integrator_n;

    /* Update for Memory: '<S17>/Memory' */
    rtDWork.Memory_PreviousInput = cc_acc_switcher;

    /* Update for UnitDelay: '<S73>/UD' incorporates:
     *  SampleTimeMath: '<S73>/TSamp'
     *
     * About '<S73>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     *
     * Block description for '<S73>/UD':
     *
     *  Store in Global RAM
     */
    rtDWork.UD_DSTATE = rtb_Sum;

    /* Switch: '<S98>/Switch1' incorporates:
     *  Constant: '<S98>/Clamping_zero'
     *  Constant: '<S98>/Constant'
     *  Constant: '<S98>/Constant2'
     *  RelationalOperator: '<S98>/fix for DT propagation issue'
     */
    if (rtb_DeadZone > 0.0) {
      tmp = 1;
    } else {
      tmp = (-1);
    }

    /* Switch: '<S98>/Switch2' incorporates:
     *  Constant: '<S98>/Clamping_zero'
     *  Constant: '<S98>/Constant3'
     *  Constant: '<S98>/Constant4'
     *  RelationalOperator: '<S98>/fix for DT propagation issue1'
     */
    if (rtb_IntegralGain_f > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = (-1);
    }

    /* Switch: '<S98>/Switch' incorporates:
     *  Constant: '<S98>/Clamping_zero'
     *  Constant: '<S98>/Constant1'
     *  Logic: '<S98>/AND3'
     *  RelationalOperator: '<S98>/Equal1'
     *  RelationalOperator: '<S98>/Relational Operator'
     *  Switch: '<S98>/Switch1'
     *  Switch: '<S98>/Switch2'
     */
    if ((0.0 != rtb_DeadZone) && (tmp == tmp_0)) {
      rtb_IntegralGain_f = 0.0;
    }

    /* Update for DiscreteIntegrator: '<S107>/Integrator' incorporates:
     *  Switch: '<S98>/Switch'
     */
    rtDWork.Integrator_DSTATE_a += 0.01 * rtb_IntegralGain_f;
  } else if (rtDWork.Subsystem_MODE) {
    rtDWork.Subsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S1>/Subsystem' */
  /* M-S-Function: '<S131>/Level-2 M-file S-Function' */
  /* read the current CPU load */
  SI_CPUload = OsGetCpuLoad();

  /* M-S-Function: '<S132>/Level-2 M-file S-Function' */
  /* read the free heap size */
  SI_FreeHeap = OsGetFreeHeapSize();

  /* M-S-Function: '<S133>/Level-2 M-file S-Function' */
  /* read the task's free stack size */
  SI_FreeStack = OsGetTaskFreeStackSize("AppCtrlTask");

  /* Update for Memory generated from: '<S6>/J-K Flip-Flop' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtDWork.TmpLatchAtJKFlipFlopInport1_Pre = true;

  /* Update for Memory generated from: '<S6>/J-K Flip-Flop' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtDWork.TmpLatchAtJKFlipFlopInport2_Pre = true;
}

/* Model initialize function */
void HANcoder_Olimexino_F3_ACC_initialize(void)
{
  {
    g_dsp_internal_SlidingWindowAve *obj;
    int32_T i;

    {
      /* user code (Start function Header) */
      uint8_t canResult1;
      tCanFilter canFilter1;

      /* user code (Start function Body) */

      /* initialize the CAN driver. */
      CanInit(32, 8);

      /* initialize the CAN I/O module for channel 1 */
      CanIoInit(0);

      /* Start for M-S-Function: '<S5>/Level-2 M-file S-Function' */

      /* configure the digital input */
      DiginConfigure(DIGIN_PORTC_PIN9, DIGIN_CFG_PULLDOWN);

      /* Start for S-Function (sfcn_pwmout_init): '<S130>/S-Function' */

      /* initialize the PWM module and register the callback handler */
      PwmoutInit(PWMOUT_MODULE_TIM2, 20, PWMOUT_EDGE_ALIGNMENT);
      PwmoutRegisterPeriodCompleteCallback(PWMOUT_MODULE_TIM2,
        PwmoutIRQ_PWMOUT_MODULE_TIM2);

      /* configures channel 2 */
      PwmoutConfigure(PWMOUT_TIM2_PIN_PA1, PWMOUT_ACTIVE_HIGH,
                      PWMOUT_INVERTED_OUTPUT_OFF);

      /* Start for M-S-Function: '<S126>/S-Function' incorporates:
       *  Constant: '<S12>/Constant1'
       */

      /* register a CAN storage buffer for the message with this ID */
      CanIoCreateMessageReceivedStorage(0, 291U);

      /* Start for M-S-Function: '<S125>/S-Function' incorporates:
       *  Constant: '<S12>/Constant2'
       */

      /* register a CAN storage buffer for the message with this ID */
      CanIoCreateMessageReceivedStorage(0, 1U);

      /* Start for MATLABSystem: '<S12>/Moving Average' */
      rtDWork.obj.isInitialized = 0;
      rtDWork.obj.NumChannels = -1;
      rtDWork.obj.FrameLength = -1;
      rtDWork.obj.matlabCodegenIsDeleted = false;
      SystemCore_setup(&rtDWork.obj);

      /* End of Start for SubSystem: '<S1>/Subsystem' */

      /* Start for M-S-Function: '<S2>/Level-2 M-file S-Function' */

      /* configure the stack size for the task that executes the model */
      AppCtrlTaskSetStackSize((configMINIMAL_STACK_SIZE*sizeof(portBASE_TYPE)) +
        25);

      /* configure the sample time of the model in microseconds */
      AppCtrlTaskSetPeriod(10000);

      /* Run the ADC conversions ten times faster than the Simulink model */
      ADCconversionTaskSetPeriod(10000/10);

      /* Start for M-S-Function: '<S3>/Level-2 M-file S-Function' */

      /* store the CAN controller's filter configuration */
      canFilter1.mask = 0x00000000;
      canFilter1.code = 0x00000000;
      canFilter1.mode = CAN_FILTER_MODE_STDID_ONLY;

      /* connect and synchronize the CAN bus */
      canResult1 = CanConnect(0, 500000, &canFilter1);
      configASSERT(canResult1 == TRUE);

      /* Start for M-S-Function: '<S9>/Level-2 M-file S-Function' */

      /* initialize the measurement and calibration interface */
      MacUsbComInit();
      MacInit();
    }

    /* SystemInitialize for Triggered SubSystem: '<S6>/J-K Flip-Flop' */
    /* SystemInitialize for Outport: '<S10>/!Q' incorporates:
     *  CombinatorialLogic: '<S10>/Logic'
     */
    rtB.Logic[1] = true;

    /* End of SystemInitialize for SubSystem: '<S6>/J-K Flip-Flop' */

    /* SystemInitialize for Enabled SubSystem: '<S1>/Subsystem' */
    /* InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
    rtDWork.DiscreteTimeIntegrator_DSTATE = 20.0;

    /* InitializeConditions for MATLABSystem: '<S12>/Moving Average' */
    obj = rtDWork.obj.pStatistic;
    if (obj->isInitialized == 1) {
      obj->pCumSum = 0.0;
      for (i = 0; i < 9; i++) {
        obj->pCumSumRev[i] = 0.0;
      }

      obj->pCumRevIndex = 1.0;
      obj->pModValueRev = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S12>/Moving Average' */
    /* End of SystemInitialize for SubSystem: '<S1>/Subsystem' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
