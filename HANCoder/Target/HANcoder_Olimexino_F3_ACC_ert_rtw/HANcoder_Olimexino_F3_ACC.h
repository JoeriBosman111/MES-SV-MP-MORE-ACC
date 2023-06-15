/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HANcoder_Olimexino_F3_ACC.h
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

#ifndef RTW_HEADER_HANcoder_Olimexino_F3_ACC_h_
#define RTW_HEADER_HANcoder_Olimexino_F3_ACC_h_
#ifndef HANcoder_Olimexino_F3_ACC_COMMON_INCLUDES_
#define HANcoder_Olimexino_F3_ACC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "pwmout.h"
#include "canio.h"
#include "digin.h"
#include "app.h"
#include "SYS_config.h"
#include "os.h"
#include "anin.h"
#include "can.h"
#include "mac.h"
#endif                          /* HANcoder_Olimexino_F3_ACC_COMMON_INCLUDES_ */

#include "HANcoder_Olimexino_F3_ACC_types.h"
#include "zero_crossing_types.h"

/* Block signals (default storage) */
typedef struct {
  uint16_T In1;                        /* '<S127>/In1' */
  boolean_T Logic[2];                  /* '<S10>/Logic' */
} BlockIO;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage obj;      /* '<S12>/Moving Average' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S12>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S12>/Discrete-Time Integrator1' */
  real_T Integrator_DSTATE;            /* '<S53>/Integrator' */
  real_T UD_DSTATE;                    /* '<S73>/UD' */
  real_T Integrator_DSTATE_a;          /* '<S107>/Integrator' */
  boolean_T TmpLatchAtJKFlipFlopInport1_Pre;/* synthesized block */
  boolean_T TmpLatchAtJKFlipFlopInport2_Pre;/* synthesized block */
  boolean_T Memory_PreviousInput;      /* '<S17>/Memory' */
  boolean_T Memory_PreviousInput_b;    /* '<S10>/Memory' */
  boolean_T Subsystem_MODE;            /* '<S1>/Subsystem' */
} D_Work;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState JKFlipFlop_Trig_ZCE;      /* '<S6>/J-K Flip-Flop' */
} PrevZCSigStates;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Logic_table
   * Referenced by: '<S10>/Logic'
   */
  boolean_T Logic_table[16];
} ConstParam;

/* Block signals (default storage) */
extern BlockIO rtB;

/* Block states (default storage) */
extern D_Work rtDWork;

/* Zero-crossing (trigger) state */
extern PrevZCSigStates rtPrevZCSigState;

/* Constant parameters (default storage) */
extern const ConstParam rtConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Sim_dist;                /* '<S12>/Discrete-Time Integrator' */
extern real_T own_dist;                /* '<S12>/Discrete-Time Integrator1' */
extern real_T Sim_GAP;                 /* '<S12>/Subtract' */
extern real_T E;                       /* '<S15>/Sum1' */
extern real_T switcher;                /* '<S14>/Switch1' */
extern real_T Speed_setpoint;          /* '<S14>/Saturation' */
extern real_T speed_Right;             /* '<S12>/Moving Average' */
extern uint32_T SI_FreeHeap;           /* '<S132>/Level-2 M-file S-Function' */
extern uint32_T SI_FreeStack;          /* '<S133>/Level-2 M-file S-Function' */
extern uint16_T control_effort;        /* '<S16>/600 - 0 N1' */
extern int16_T camera_gap;             /* '<S128>/In1' */
extern int16_T speed_setpoint;         /* '<S128>/In2' */
extern int16_T Distance_setpoint;      /* '<S128>/In3' */
extern int16_T gap_valid;              /* '<S128>/In4' */
extern uint8_T SI_CPUload;             /* '<S131>/Level-2 M-file S-Function' */
extern boolean_T ON_OFF;               /* '<S1>/Signal Conversion' */
extern boolean_T cc_acc_switcher;      /* '<S17>/AND' */

/* Model entry point functions */
extern void HANcoder_Olimexino_F3_ACC_initialize(void);
extern void HANcoder_Olimexino_F3_ACC_step(void);

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
 * '<Root>' : 'HANcoder_Olimexino_F3_ACC'
 * '<S1>'   : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm'
 * '<S2>'   : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Base Sample Time config'
 * '<S3>'   : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/CAN config'
 * '<S4>'   : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Custom ID config1'
 * '<S5>'   : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Digital Input'
 * '<S6>'   : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/J-K Flip-Flop'
 * '<S7>'   : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem'
 * '<S8>'   : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Sytem information'
 * '<S9>'   : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/XCP on USB config1'
 * '<S10>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/J-K Flip-Flop/J-K Flip-Flop'
 * '<S11>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm'
 * '<S12>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Inputs'
 * '<S13>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Outputs'
 * '<S14>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control'
 * '<S15>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control'
 * '<S16>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control'
 * '<S17>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Switcher'
 * '<S18>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller'
 * '<S19>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Anti-windup'
 * '<S20>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/D Gain'
 * '<S21>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Filter'
 * '<S22>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Filter ICs'
 * '<S23>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/I Gain'
 * '<S24>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Ideal P Gain'
 * '<S25>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Ideal P Gain Fdbk'
 * '<S26>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Integrator'
 * '<S27>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Integrator ICs'
 * '<S28>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/N Copy'
 * '<S29>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/N Gain'
 * '<S30>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/P Copy'
 * '<S31>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Parallel P Gain'
 * '<S32>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Reset Signal'
 * '<S33>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Saturation'
 * '<S34>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Saturation Fdbk'
 * '<S35>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Sum'
 * '<S36>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Sum Fdbk'
 * '<S37>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Tracking Mode'
 * '<S38>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Tracking Mode Sum'
 * '<S39>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Tsamp - Integral'
 * '<S40>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Tsamp - Ngain'
 * '<S41>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/postSat Signal'
 * '<S42>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/preSat Signal'
 * '<S43>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S44>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S45>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
 * '<S46>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
 * '<S47>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/D Gain/Disabled'
 * '<S48>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Filter/Disabled'
 * '<S49>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Filter ICs/Disabled'
 * '<S50>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/I Gain/Internal Parameters'
 * '<S51>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Ideal P Gain/Passthrough'
 * '<S52>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S53>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Integrator/Discrete'
 * '<S54>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Integrator ICs/Internal IC'
 * '<S55>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S56>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/N Gain/Disabled'
 * '<S57>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/P Copy/Disabled'
 * '<S58>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S59>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Reset Signal/Disabled'
 * '<S60>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Saturation/External'
 * '<S61>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Saturation/External/Saturation Dynamic'
 * '<S62>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Saturation Fdbk/Disabled'
 * '<S63>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Sum/Sum_PI'
 * '<S64>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Sum Fdbk/Disabled'
 * '<S65>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Tracking Mode/Enabled'
 * '<S66>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S67>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S68>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S69>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/postSat Signal/Forward_Path'
 * '<S70>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Distance control/PID Controller/preSat Signal/Forward_Path'
 * '<S71>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/Feed Forward'
 * '<S72>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller'
 * '<S73>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/Feed Forward/Discrete Derivative'
 * '<S74>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Anti-windup'
 * '<S75>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/D Gain'
 * '<S76>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Filter'
 * '<S77>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Filter ICs'
 * '<S78>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/I Gain'
 * '<S79>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Ideal P Gain'
 * '<S80>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Ideal P Gain Fdbk'
 * '<S81>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Integrator'
 * '<S82>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Integrator ICs'
 * '<S83>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/N Copy'
 * '<S84>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/N Gain'
 * '<S85>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/P Copy'
 * '<S86>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Parallel P Gain'
 * '<S87>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Reset Signal'
 * '<S88>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Saturation'
 * '<S89>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Saturation Fdbk'
 * '<S90>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Sum'
 * '<S91>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Sum Fdbk'
 * '<S92>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Tracking Mode'
 * '<S93>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Tracking Mode Sum'
 * '<S94>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Tsamp - Integral'
 * '<S95>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Tsamp - Ngain'
 * '<S96>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/postSat Signal'
 * '<S97>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/preSat Signal'
 * '<S98>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S99>'  : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S100>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S101>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/D Gain/Disabled'
 * '<S102>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Filter/Disabled'
 * '<S103>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Filter ICs/Disabled'
 * '<S104>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/I Gain/Internal Parameters'
 * '<S105>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Ideal P Gain/Passthrough'
 * '<S106>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S107>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Integrator/Discrete'
 * '<S108>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Integrator ICs/Internal IC'
 * '<S109>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S110>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/N Gain/Disabled'
 * '<S111>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/P Copy/Disabled'
 * '<S112>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S113>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Reset Signal/Disabled'
 * '<S114>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Saturation/Enabled'
 * '<S115>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Saturation Fdbk/Disabled'
 * '<S116>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Sum/Sum_PI'
 * '<S117>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Sum Fdbk/Disabled'
 * '<S118>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Tracking Mode/Disabled'
 * '<S119>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S120>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S121>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S122>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/postSat Signal/Forward_Path'
 * '<S123>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Speed Feedback Control/PID Controller/preSat Signal/Forward_Path'
 * '<S124>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Algorithm/Model And Control/Switcher/IsZero'
 * '<S125>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Inputs/CAN receive ABS'
 * '<S126>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Inputs/CAN receive LAPTOP'
 * '<S127>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Inputs/CAN receive ABS/Enabled Subsystem'
 * '<S128>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Inputs/CAN receive LAPTOP/Enabled Subsystem'
 * '<S129>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Outputs/PWM Duty Cycle'
 * '<S130>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Subsystem/Outputs/PWM Init'
 * '<S131>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Sytem information/Get CPU load1'
 * '<S132>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Sytem information/Get free Heap1'
 * '<S133>' : 'HANcoder_Olimexino_F3_ACC/HANcoder STM32 Target - Olimexino-STM32 F3 algorithm/Sytem information/Get free Stack1'
 */
#endif                             /* RTW_HEADER_HANcoder_Olimexino_F3_ACC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
