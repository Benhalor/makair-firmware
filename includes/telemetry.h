/******************************************************************************
 * @author Makers For Life
 * @copyright Copyright (c) 2020 Makers For Life
 * @file telemetry.h
 * @brief Implementation of the telemetry protocol
 *****************************************************************************/

#pragma once

#include <stdint.h>

#include "../includes/alarm_controller.h"
#include "../includes/cycle.h"

/// Prepare Serial6 to send telemetry data
void initTelemetry(void);

/// Send a "boot" message
void sendBootMessage(void);

/// Send a "data snapshot" message
void sendDataSnapshot(uint16_t centileValue,
                      uint16_t pressureValue,
                      CyclePhases phase,
                      CycleSubPhases subPhase,
                      uint8_t blowerValvePosition,
                      uint8_t patientValvePosition,
                      uint8_t blowerRpm,
                      uint8_t batteryLevel);

/// Send a "machine state snapshot" message
void sendMachineStateSnapshot(uint32_t cycleValue,
                              uint8_t peakCommand,
                              uint8_t plateauCommand,
                              uint8_t peepCommand,
                              uint8_t cpmCommand,
                              uint8_t previousPeakPressure,
                              uint8_t previousPlateauPressure,
                              uint8_t previousPeepPressure,
                              uint8_t currentAlarmCodes[ALARMS_SIZE],
                              uint8_t previousAlarmCodes[ALARMS_SIZE]);

/// Send a "alarm trap" message
void sendAlarmTrap(uint16_t centileValue,
                   uint16_t pressureValue,
                   CyclePhases phase,
                   CycleSubPhases subPhase,
                   uint32_t cycleValue,
                   uint8_t alarmCode,
                   AlarmPriority alarmPriority,
                   bool triggered,
                   uint32_t expectedValue,
                   uint32_t measuredValue,
                   uint32_t cyclesSinceTriggerValue);
