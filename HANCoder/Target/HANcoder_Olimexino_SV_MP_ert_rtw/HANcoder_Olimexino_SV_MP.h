/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HANcoder_Olimexino_SV_MP.h
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

#ifndef RTW_HEADER_HANcoder_Olimexino_SV_MP_h_
#define RTW_HEADER_HANcoder_Olimexino_SV_MP_h_
#ifndef HANcoder_Olimexino_SV_MP_COMMON_INCLUDES_
#define HANcoder_Olimexino_SV_MP_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "can.h"
#include "canio.h"
#include "app.h"
#include "SYS_config.h"
#include "os.h"
#include "anin.h"
#include "mac.h"
#endif                           /* HANcoder_Olimexino_SV_MP_COMMON_INCLUDES_ */

#include "HANcoder_Olimexino_SV_MP_types.h"

/* Block signals (default storage) */
typedef struct {
  int16_T Gain;                        /* '<S7>/Gain' */
  int16_T Gain3;                       /* '<S7>/Gain3' */
} BlockIO;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S49>/Integrator' */
  real_T Filter_DSTATE;                /* '<S44>/Filter' */
  real_T UD_DSTATE;                    /* '<S69>/UD' */
  real_T Integrator_DSTATE_g;          /* '<S103>/Integrator' */
  real_T Filter_DSTATE_i;              /* '<S98>/Filter' */
  boolean_T Memory_PreviousInput;      /* '<S13>/Memory' */
} D_Work;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Entermargin;            /* '<S13>/Enter margin' */
  const real_T Exitmargin;             /* '<S13>/Exit margin' */
  const int16_T Gain1;                 /* '<S7>/Gain1' */
  const int16_T Gain2;                 /* '<S7>/Gain2' */
} ConstBlockIO;

/* Block signals (default storage) */
extern BlockIO rtB;

/* Block states (default storage) */
extern D_Work rtDWork;
extern const ConstBlockIO rtConstB;    /* constant block i/o */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T E;                       /* '<S11>/Sum1' */
extern uint32_T SI_FreeStack;          /* '<S125>/Level-2 M-file S-Function' */
extern uint32_T SI_FreeHeap;           /* '<S126>/Level-2 M-file S-Function' */
extern int16_T control_effort;         /* '<S12>/-5000 -5000 N1' */
extern int16_T speed;                  /* '<S122>/In1' */
extern int16_T gap;                    /* '<S122>/In2' */
extern uint8_T SI_CPUload;             /* '<S124>/Level-2 M-file S-Function' */

/* Model entry point functions */
extern void HANcoder_Olimexino_SV_MP_initialize(void);
extern void HANcoder_Olimexino_SV_MP_step(void);

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
 * '<Root>' : 'HANcoder_Olimexino_SV_MP'
 * '<S1>'   : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm'
 * '<S2>'   : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm'
 * '<S3>'   : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Base Sample Time config'
 * '<S4>'   : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/CAN config'
 * '<S5>'   : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Custom ID config'
 * '<S6>'   : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Inputs'
 * '<S7>'   : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Outputs'
 * '<S8>'   : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Sytem information'
 * '<S9>'   : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/XCP on USB config'
 * '<S10>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control'
 * '<S11>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control'
 * '<S12>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control'
 * '<S13>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Switcher'
 * '<S14>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller'
 * '<S15>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Anti-windup'
 * '<S16>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/D Gain'
 * '<S17>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Filter'
 * '<S18>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Filter ICs'
 * '<S19>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/I Gain'
 * '<S20>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Ideal P Gain'
 * '<S21>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Ideal P Gain Fdbk'
 * '<S22>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Integrator'
 * '<S23>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Integrator ICs'
 * '<S24>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/N Copy'
 * '<S25>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/N Gain'
 * '<S26>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/P Copy'
 * '<S27>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Parallel P Gain'
 * '<S28>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Reset Signal'
 * '<S29>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Saturation'
 * '<S30>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Saturation Fdbk'
 * '<S31>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Sum'
 * '<S32>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Sum Fdbk'
 * '<S33>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Tracking Mode'
 * '<S34>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Tracking Mode Sum'
 * '<S35>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Tsamp - Integral'
 * '<S36>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Tsamp - Ngain'
 * '<S37>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/postSat Signal'
 * '<S38>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/preSat Signal'
 * '<S39>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S40>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S41>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
 * '<S42>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
 * '<S43>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/D Gain/Internal Parameters'
 * '<S44>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S45>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S46>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/I Gain/Internal Parameters'
 * '<S47>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Ideal P Gain/Passthrough'
 * '<S48>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S49>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Integrator/Discrete'
 * '<S50>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Integrator ICs/Internal IC'
 * '<S51>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/N Copy/Disabled'
 * '<S52>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/N Gain/Internal Parameters'
 * '<S53>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/P Copy/Disabled'
 * '<S54>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S55>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Reset Signal/Disabled'
 * '<S56>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Saturation/External'
 * '<S57>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Saturation/External/Saturation Dynamic'
 * '<S58>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Saturation Fdbk/Disabled'
 * '<S59>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Sum/Sum_PID'
 * '<S60>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Sum Fdbk/Disabled'
 * '<S61>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Tracking Mode/Enabled'
 * '<S62>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S63>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Tsamp - Integral/Passthrough'
 * '<S64>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S65>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/postSat Signal/Forward_Path'
 * '<S66>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Distance control/PID Controller/preSat Signal/Forward_Path'
 * '<S67>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/Feed Forward'
 * '<S68>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller'
 * '<S69>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/Feed Forward/Discrete Derivative'
 * '<S70>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Anti-windup'
 * '<S71>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/D Gain'
 * '<S72>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Filter'
 * '<S73>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Filter ICs'
 * '<S74>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/I Gain'
 * '<S75>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Ideal P Gain'
 * '<S76>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Ideal P Gain Fdbk'
 * '<S77>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Integrator'
 * '<S78>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Integrator ICs'
 * '<S79>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/N Copy'
 * '<S80>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/N Gain'
 * '<S81>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/P Copy'
 * '<S82>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Parallel P Gain'
 * '<S83>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Reset Signal'
 * '<S84>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Saturation'
 * '<S85>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Saturation Fdbk'
 * '<S86>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Sum'
 * '<S87>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Sum Fdbk'
 * '<S88>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Tracking Mode'
 * '<S89>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Tracking Mode Sum'
 * '<S90>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Tsamp - Integral'
 * '<S91>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Tsamp - Ngain'
 * '<S92>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/postSat Signal'
 * '<S93>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/preSat Signal'
 * '<S94>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S95>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S96>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S97>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/D Gain/Internal Parameters'
 * '<S98>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S99>'  : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S100>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/I Gain/Internal Parameters'
 * '<S101>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Ideal P Gain/Passthrough'
 * '<S102>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S103>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Integrator/Discrete'
 * '<S104>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Integrator ICs/Internal IC'
 * '<S105>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/N Copy/Disabled'
 * '<S106>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/N Gain/Internal Parameters'
 * '<S107>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/P Copy/Disabled'
 * '<S108>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S109>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Reset Signal/Disabled'
 * '<S110>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Saturation/Enabled'
 * '<S111>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Saturation Fdbk/Disabled'
 * '<S112>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Sum/Sum_PID'
 * '<S113>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Sum Fdbk/Disabled'
 * '<S114>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Tracking Mode/Disabled'
 * '<S115>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S116>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Tsamp - Integral/Passthrough'
 * '<S117>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S118>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/postSat Signal/Forward_Path'
 * '<S119>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Speed Feedback Control/PID Controller/preSat Signal/Forward_Path'
 * '<S120>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Algorithm/Model And Control/Switcher/IsZero'
 * '<S121>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Inputs/CAN receive'
 * '<S122>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Inputs/CAN receive/Enabled Subsystem'
 * '<S123>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Outputs/CAN send'
 * '<S124>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Sytem information/Get CPU load'
 * '<S125>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Sytem information/Get free Heap'
 * '<S126>' : 'HANcoder_Olimexino_SV_MP/HANcoder STM32 Target - Olimexino-STM32 algorithm/Sytem information/Get free Stack'
 */
#endif                              /* RTW_HEADER_HANcoder_Olimexino_SV_MP_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
