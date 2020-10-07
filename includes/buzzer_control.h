/******************************************************************************
 * @author Makers For Life
 * @copyright Copyright (c) 2020 Makers For Life
 * @file buzzer_control.h
 * @brief Abstraction to switch buzzer ON or OFF
 *****************************************************************************/
#pragma once
#include "Arduino.h"
/// Initialization of HardwareTimer for buzzer
void BuzzerControl_Init(void);

/// Switch buzzer ON
void BuzzerControl_On(void);

/// Switch buzzer OFF
void BuzzerControl_Off(void);

/// Change freq
void BuzzerIncrementFreq(void);
void BuzzerDecrementFreq(void);
extern uint32_t buzzerCurrentFreq;
