/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HANcoder_Olimexino_SV_MP.c
 *
 * Code generated for Simulink model 'HANcoder_Olimexino_SV_MP'.
 *
 * Model version                  : 16.8
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed May 10 10:24:49 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HANcoder_Olimexino_SV_MP.h"
#include <math.h>
#include "rtwtypes.h"
#include "HANcoder_Olimexino_SV_MP_private.h"

/* map ByteSwap function */
#define ByteSwap(x)                    (ByteSwap_x((uint8_t *) &x, sizeof(x)))

/* Exported block signals */
real_T E;                              /* '<S11>/Sum1' */
uint32_T SI_FreeStack;                 /* '<S125>/Level-2 M-file S-Function' */
uint32_T SI_FreeHeap;                  /* '<S126>/Level-2 M-file S-Function' */
int16_T control_effort;                /* '<S12>/-5000 -5000 N1' */
int16_T speed;                         /* '<S122>/In1' */
int16_T gap;                           /* '<S122>/In2' */
uint8_T SI_CPUload;                    /* '<S124>/Level-2 M-file S-Function' */

/* Block signals (default storage) */
BlockIO rtB;

/* Block states (default storage) */
D_Work rtDWork;
static tCanDataTypes canTxData;
static tCanDataTypes canRxData_0_256U;

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

/* Model step function */
void HANcoder_Olimexino_SV_MP_step(void)
{
  /* local block i/o variables */
  int16_T rtb_SFunction_o2;
  int16_T rtb_SFunction_o3;
  int16_T rtb_SFunction_o4;
  int16_T rtb_SFunction_o5;
  int8_T rtb_SFunction_o1;
  real_T rtb_DeadZone;
  real_T rtb_DeadZone_0;
  real_T rtb_FilterCoefficient;
  real_T rtb_FilterCoefficient_i;
  real_T rtb_IntegralGain_b;
  real_T rtb_SumI1;
  real_T rtb_Switch2;
  real_T rtb_Switch_g;
  real_T rtb_TSamp;
  real_T u1;
  real_T u2;
  int8_T rtb_SumI1_0;
  int8_T rtb_fixforDTpropagationissue_0;
  boolean_T rtb_AND;
  boolean_T rtb_RelationalOperator;
  boolean_T rtb_fixforDTpropagationissue;

  /* M-S-Function: '<S121>/S-Function' incorporates:
   *  Constant: '<S6>/Constant2'
   */

  /* read the message data and store the new parameter */
  rtb_SFunction_o1 = CanIoGetMessage(0, 256U, NULL,
    &canRxData_0_256U.uint8_T_info[0], NULL);

  /* process the message data */
  if (rtb_SFunction_o1 > 0) {
    /* read the data */
    rtb_SFunction_o2 = canRxData_0_256U.int16_T_info[0];
    rtb_SFunction_o3 = canRxData_0_256U.int16_T_info[1];
    rtb_SFunction_o4 = canRxData_0_256U.int16_T_info[2];
    rtb_SFunction_o5 = canRxData_0_256U.int16_T_info[3];
  }

  /* Outputs for Enabled SubSystem: '<S121>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S122>/Enable'
   */
  if (rtb_SFunction_o1 > 0) {
    /* SignalConversion generated from: '<S122>/In1' */
    speed = rtb_SFunction_o2;

    /* SignalConversion generated from: '<S122>/In2' */
    gap = rtb_SFunction_o3;
  }

  /* End of Outputs for SubSystem: '<S121>/Enabled Subsystem' */

  /* Logic: '<S13>/AND' incorporates:
   *  Constant: '<S120>/Constant'
   *  Logic: '<S13>/NAND'
   *  Memory: '<S13>/Memory'
   *  RelationalOperator: '<S120>/Compare'
   *  RelationalOperator: '<S13>/Relational Operator'
   *  RelationalOperator: '<S13>/Relational Operator1'
   */
  rtb_AND = ((gap >= rtConstB.Entermargin) && ((gap > rtConstB.Exitmargin) ||
              (rtDWork.Memory_PreviousInput != false)));

  /* Sum: '<S11>/Sum1' incorporates:
   *  Constant: '<S10>/d_d'
   */
  E = (real_T)gap - 20.0;

  /* Gain: '<S52>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S44>/Filter'
   *  Gain: '<S43>/Derivative Gain'
   *  Sum: '<S44>/SumD'
   */
  rtb_FilterCoefficient = (2.0 * E - rtDWork.Filter_DSTATE) * 100.0;

  /* Sum: '<S59>/Sum' incorporates:
   *  DiscreteIntegrator: '<S49>/Integrator'
   *  Gain: '<S54>/Proportional Gain'
   */
  rtb_SumI1 = (1.5 * E + rtDWork.Integrator_DSTATE) + rtb_FilterCoefficient;

  /* Switch: '<S57>/Switch2' incorporates:
   *  Constant: '<S10>/v_d'
   *  Constant: '<S11>/Constant'
   *  RelationalOperator: '<S57>/LowerRelop1'
   *  RelationalOperator: '<S57>/UpperRelop'
   *  Switch: '<S57>/Switch'
   */
  if (rtb_SumI1 > 8.3333333333333339) {
    rtb_Switch2 = 8.3333333333333339;
  } else if (rtb_SumI1 < 0.0) {
    /* Switch: '<S57>/Switch' incorporates:
     *  Constant: '<S11>/Constant'
     */
    rtb_Switch2 = 0.0;
  } else {
    rtb_Switch2 = rtb_SumI1;
  }

  /* End of Switch: '<S57>/Switch2' */

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/v_d'
   */
  if (rtb_AND) {
    rtb_Switch_g = 8.3333333333333339;
  } else {
    rtb_Switch_g = rtb_Switch2;
  }

  /* End of Switch: '<S10>/Switch' */

  /* SampleTimeMath: '<S69>/TSamp'
   *
   * About '<S69>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = rtb_Switch_g * 100.0;

  /* Sum: '<S12>/Sum1' */
  rtb_IntegralGain_b = rtb_Switch_g - (real_T)speed;

  /* Gain: '<S106>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S98>/Filter'
   *  Gain: '<S97>/Derivative Gain'
   *  Sum: '<S98>/SumD'
   */
  rtb_FilterCoefficient_i = (10.0 * rtb_IntegralGain_b - rtDWork.Filter_DSTATE_i)
    * 100.0;

  /* Sum: '<S112>/Sum' incorporates:
   *  DiscreteIntegrator: '<S103>/Integrator'
   *  Gain: '<S108>/Proportional Gain'
   */
  rtb_DeadZone = (2000.0 * rtb_IntegralGain_b + rtDWork.Integrator_DSTATE_g) +
    rtb_FilterCoefficient_i;

  /* Saturate: '<S110>/Saturation' */
  if (rtb_DeadZone > 5000.0) {
    rtb_DeadZone_0 = 5000.0;
  } else if (rtb_DeadZone < (-5000.0)) {
    rtb_DeadZone_0 = (-5000.0);
  } else {
    rtb_DeadZone_0 = rtb_DeadZone;
  }

  /* End of Saturate: '<S110>/Saturation' */

  /* Sum: '<S12>/Add' incorporates:
   *  Gain: '<S67>/Gain'
   *  Gain: '<S67>/Gain1'
   *  Sum: '<S67>/Add'
   *  Sum: '<S69>/Diff'
   *  UnitDelay: '<S69>/UD'
   *
   * Block description for '<S69>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S69>/UD':
   *
   *  Store in Global RAM
   */
  rtb_DeadZone_0 += (rtb_TSamp - rtDWork.UD_DSTATE) * 1000.0 + 50.0 *
    rtb_Switch_g;

  /* Saturate: '<S12>/-5000 -5000 N1' */
  u1 = (-5000);
  u2 = 5000;
  if (rtb_DeadZone_0 > u2) {
    rtb_DeadZone_0 = u2;
  } else if (rtb_DeadZone_0 < u1) {
    rtb_DeadZone_0 = u1;
  }

  /* Saturate: '<S12>/-5000 -5000 N1' */
  control_effort = (int16_T)floor(rtb_DeadZone_0);

  /* Gain: '<S7>/Gain' */
  rtB.Gain = (int16_T)((16384 * control_effort) >> 14);

  /* Gain: '<S7>/Gain3' */
  rtB.Gain3 = (int16_T)floor(1.0 * rtb_Switch_g);

  /* Switch: '<S42>/Switch' incorporates:
   *  Constant: '<S10>/v_d'
   *  Constant: '<S11>/Constant'
   *  RelationalOperator: '<S42>/u_GTE_up'
   *  RelationalOperator: '<S42>/u_GT_lo'
   *  Switch: '<S42>/Switch1'
   */
  if (rtb_SumI1 >= 8.3333333333333339) {
    rtb_DeadZone_0 = 8.3333333333333339;
  } else if (rtb_SumI1 > 0.0) {
    /* Switch: '<S42>/Switch1' */
    rtb_DeadZone_0 = rtb_SumI1;
  } else {
    rtb_DeadZone_0 = 0.0;
  }

  /* End of Switch: '<S42>/Switch' */

  /* Sum: '<S42>/Diff' */
  rtb_SumI1 -= rtb_DeadZone_0;

  /* RelationalOperator: '<S39>/Relational Operator' incorporates:
   *  Constant: '<S39>/Constant5'
   */
  rtb_RelationalOperator = (0.0 != rtb_SumI1);

  /* RelationalOperator: '<S39>/fix for DT propagation issue' incorporates:
   *  Constant: '<S39>/Constant5'
   */
  rtb_fixforDTpropagationissue = (rtb_SumI1 > 0.0);

  /* Sum: '<S62>/SumI1' incorporates:
   *  Gain: '<S46>/Integral Gain'
   *  Gain: '<S61>/Kt'
   *  Sum: '<S61>/SumI3'
   */
  rtb_SumI1 = (rtb_Switch_g - rtb_Switch2) * 1.0 + 0.1 * E;

  /* Switch: '<S39>/Switch1' incorporates:
   *  Constant: '<S39>/Constant'
   *  Constant: '<S39>/Constant2'
   */
  if (rtb_fixforDTpropagationissue) {
    rtb_fixforDTpropagationissue_0 = 1;
  } else {
    rtb_fixforDTpropagationissue_0 = (-1);
  }

  /* End of Switch: '<S39>/Switch1' */

  /* Switch: '<S39>/Switch2' incorporates:
   *  Constant: '<S39>/Constant3'
   *  Constant: '<S39>/Constant4'
   *  Constant: '<S39>/Constant5'
   *  RelationalOperator: '<S39>/fix for DT propagation issue1'
   */
  if (rtb_SumI1 > 0.0) {
    rtb_SumI1_0 = 1;
  } else {
    rtb_SumI1_0 = (-1);
  }

  /* End of Switch: '<S39>/Switch2' */

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S39>/Constant1'
   *  Logic: '<S39>/AND3'
   *  RelationalOperator: '<S39>/Equal1'
   */
  if (rtb_RelationalOperator && (rtb_fixforDTpropagationissue_0 == rtb_SumI1_0))
  {
    rtb_SumI1 = 0.0;
  }

  /* End of Switch: '<S39>/Switch' */

  /* DeadZone: '<S96>/DeadZone' */
  if (rtb_DeadZone > 5000.0) {
    rtb_DeadZone -= 5000.0;
  } else if (rtb_DeadZone >= (-5000.0)) {
    rtb_DeadZone = 0.0;
  } else {
    rtb_DeadZone -= (-5000.0);
  }

  /* End of DeadZone: '<S96>/DeadZone' */

  /* Gain: '<S100>/Integral Gain' */
  rtb_IntegralGain_b *= 50.0;

  /* Switch: '<S94>/Switch1' incorporates:
   *  Constant: '<S94>/Constant'
   *  Constant: '<S94>/Constant2'
   *  Constant: '<S94>/Constant5'
   *  RelationalOperator: '<S94>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > 0.0) {
    rtb_fixforDTpropagationissue_0 = 1;
  } else {
    rtb_fixforDTpropagationissue_0 = (-1);
  }

  /* End of Switch: '<S94>/Switch1' */

  /* Switch: '<S94>/Switch2' incorporates:
   *  Constant: '<S94>/Constant3'
   *  Constant: '<S94>/Constant4'
   *  Constant: '<S94>/Constant5'
   *  RelationalOperator: '<S94>/fix for DT propagation issue1'
   */
  if (rtb_IntegralGain_b > 0.0) {
    rtb_SumI1_0 = 1;
  } else {
    rtb_SumI1_0 = (-1);
  }

  /* End of Switch: '<S94>/Switch2' */

  /* Switch: '<S94>/Switch' incorporates:
   *  Constant: '<S94>/Constant1'
   *  Constant: '<S94>/Constant5'
   *  Logic: '<S94>/AND3'
   *  RelationalOperator: '<S94>/Equal1'
   *  RelationalOperator: '<S94>/Relational Operator'
   */
  if ((0.0 != rtb_DeadZone) && (rtb_fixforDTpropagationissue_0 == rtb_SumI1_0))
  {
    rtb_IntegralGain_b = 0.0;
  }

  /* End of Switch: '<S94>/Switch' */
  /* M-S-Function: '<S124>/Level-2 M-file S-Function' */
  /* read the current CPU load */
  SI_CPUload = OsGetCpuLoad();

  /* M-S-Function: '<S125>/Level-2 M-file S-Function' */
  /* read the free heap size */
  SI_FreeStack = OsGetFreeHeapSize();

  /* M-S-Function: '<S126>/Level-2 M-file S-Function' */
  /* read the task's free stack size */
  SI_FreeHeap = OsGetTaskFreeStackSize("AppCtrlTask");

  /* Update for M-S-Function: '<S123>/S-Function' incorporates:
   *  Constant: '<S7>/Constant'
   */
  {
    /* prepare the data */
    canTxData.int16_T_info[0] = rtB.Gain;
    canTxData.int16_T_info[1] = rtConstB.Gain1;
    canTxData.int16_T_info[2] = rtConstB.Gain2;
    canTxData.int16_T_info[3] = rtB.Gain3;

    /* send the data */
    CanTransmit(0, 50U, 8, &canTxData.uint8_T_info[0]);
  }

  /* Update for Memory: '<S13>/Memory' */
  rtDWork.Memory_PreviousInput = rtb_AND;

  /* Update for DiscreteIntegrator: '<S49>/Integrator' */
  rtDWork.Integrator_DSTATE += 0.01 * rtb_SumI1;

  /* Update for DiscreteIntegrator: '<S44>/Filter' */
  rtDWork.Filter_DSTATE += 0.01 * rtb_FilterCoefficient;

  /* Update for UnitDelay: '<S69>/UD'
   *
   * Block description for '<S69>/UD':
   *
   *  Store in Global RAM
   */
  rtDWork.UD_DSTATE = rtb_TSamp;

  /* Update for DiscreteIntegrator: '<S103>/Integrator' */
  rtDWork.Integrator_DSTATE_g += 0.01 * rtb_IntegralGain_b;

  /* Update for DiscreteIntegrator: '<S98>/Filter' */
  rtDWork.Filter_DSTATE_i += 0.01 * rtb_FilterCoefficient_i;
}

/* Model initialize function */
void HANcoder_Olimexino_SV_MP_initialize(void)
{
  {
    /* user code (Start function Header) */
    uint8_t canResult1;
    tCanFilter canFilter1;

    /* user code (Start function Body) */

    /* initialize the CAN driver. */
    CanInit(32, 8);

    /* initialize the CAN I/O module for channel 1 */
    CanIoInit(0);

    /* Start for M-S-Function: '<S121>/S-Function' incorporates:
     *  Constant: '<S6>/Constant2'
     */

    /* register a CAN storage buffer for the message with this ID */
    CanIoCreateMessageReceivedStorage(0, 256U);

    /* Start for M-S-Function: '<S3>/Level-2 M-file S-Function' */

    /* configure the stack size for the task that executes the model */
    AppCtrlTaskSetStackSize((configMINIMAL_STACK_SIZE*sizeof(portBASE_TYPE)) + 0);

    /* configure the sample time of the model in microseconds */
    AppCtrlTaskSetPeriod(10000);

    /* Run the ADC conversions ten times faster than the Simulink model */
    ADCconversionTaskSetPeriod(10000/10);

    /* Start for M-S-Function: '<S4>/Level-2 M-file S-Function' */

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
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
