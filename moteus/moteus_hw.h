// Copyright 2018-2019 Josh Pieper, jjp@pobox.com.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

namespace moteus {

// r1 silk
// #define MOTEUS_HW_REV 0

// r2 silk
// #define MOTEUS_HW_REV 1

// r3 silk
// #define MOTEUS_HW_REV 2

// r4.1 silk
// #define MOTEUS_HW_REV 3

// The most recent version of the HW.
#ifndef MOTEUS_HW_REV
// r4.2 silk
#define MOTEUS_HW_REV 4
#endif

// The mapping between MOTEUS_HW_REV and the version pins on the
// board.
#if defined(TARGET_STM32G4)
constexpr int kHardwareInterlock[] = {
  -1,  // r1 (never printed for g4)
  -1,  // r2 (never printed for g4)
  -1,  // r3 (never printed for g4)
  0,   // r4.1
  0,   // r4.2 (unfortunately, indistinguishable from the interlock)
};
#else
constexpr int kHardwareInterlock[] = {
  0,   // r1
  1,   // r2
  2,   // r3 & r3.1
  -1,  // never printed for f4
  -1,  // never printed for f4
};
#endif

#define DRV8323_ENABLE PA_3

#if MOTEUS_HW_REV <= 2
#define DRV8323_HIZ PC_3
#else
#define DRV8323_HIZ PB_7
#endif

#if MOTEUS_HW_REV == 0
#define DRV8323_CS PA_4
#elif MOTEUS_HW_REV <= 2
#define DRV8323_CS PC_8
#elif MOTEUS_HW_REV >= 3
#define DRV8323_CS PC_4
#endif

#define DRV8323_MOSI PA_7
#define DRV8323_MISO PA_6
#define DRV8323_SCK PA_5

#if MOTEUS_HW_REV <= 2
#define DRV8323_FAULT PC_4
#elif MOTEUS_HW_REV >= 3
#define DRV8323_FAULT PB_6
#endif

#if MOTEUS_HW_REV <= 2
#define DEBUG_LED1 PA_11
#define POWER_LED PA_12
#elif MOTEUS_HW_REV >= 3
#define DEBUG_LED1 PF_0
#define POWER_LED PF_1
#endif

#if MOTEUS_HW_REV <= 2
#define MOTEUS_DEBUG_UART_OUT PC_10
#elif MOTEUS_HW_REV >= 3
#define MOTEUS_DEBUG_UART_OUT PB_3
#endif

#if MOTEUS_HW_REV <= 2
#define HWREV_PIN0 PC_13
#define HWREV_PIN1 PC_14
#define HWREV_PIN2 PC_15
#elif MOTEUS_HW_REV >= 3
#define HWREV_PIN0 PC_13
#define HWREV_PIN1 PC_6
#define HWREV_PIN2 PA_15
#endif

#if MOTEUS_HW_REV <= 2
#define MOTEUS_CURRENT1 PC_5
#define MOTEUS_CURRENT2 PB_0_ALT0
#elif MOTEUS_HW_REV >= 3
// ADC1
#define MOTEUS_CURRENT1 PB_0
// ADC3
#define MOTEUS_CURRENT2 PB_1_ALT0
#endif

#if MOTEUS_HW_REV <= 2
#define MOTEUS_VSENSE PC_1_ALT1
#elif MOTEUS_HW_REV >=3
#define MOTEUS_VSENSE PA_8
#endif

#if MOTEUS_HW_REV == 0
#define MOTEUS_TSENSE PC_0_ALT1
#elif MOTEUS_HW_REV <= 2
#define MOTEUS_TSENSE PC_2_ALT1
#elif MOTEUS_HW_REV >= 3
#define MOTEUS_TSENSE PA_9
#endif

#if MOTEUS_HW_REV <= 1
#define MOTEUS_CURRENT_SENSE_OHM 0.001f
#elif MOTEUS_HW_REV >= 2
#define MOTEUS_CURRENT_SENSE_OHM 0.0005f
#endif

#if MOTEUS_HW_REV <= 2
#define MOTEUS_UART_TX PA_9
#define MOTEUS_UART_RX PA_10
#define MOTEUS_UART_DIR PA_8
#else
#define MOTEUS_UART_TX PC_10
#define MOTEUS_UART_RX PC_11
#define MOTEUS_UART_DIR NC
#endif

#define MOTEUS_AS5047_MOSI PB_15
#define MOTEUS_AS5047_MISO PB_14
#define MOTEUS_AS5047_SCK PB_13

#if MOTEUS_HW_REV <= 2
#define MOTEUS_AS5047_CS PB_12
#elif MOTEUS_HW_REV >= 3
#define MOTEUS_AS5047_CS PB_11
#endif

#if MOTEUS_HW_REV >= 3
#define MOTEUS_CAN_TD PA_12
#define MOTEUS_CAN_RD PA_11
#endif

#if MOTEUS_HW_REV <= 2
#define MOTEUS_DEBUG1 PB_8
#define MOTEUS_DEBUG2 PB_9
#elif MOTEUS_HW_REV >= 3
#define MOTEUS_DEBUG1 PC_14
#define MOTEUS_DEBUG2 PC_15
#endif

#define MOTEUS_DEBUG_DAC PA_4

#if defined(TARGET_STM32G4)
#define MOTEUS_CCM_ATTRIBUTE __attribute__ ((section (".ccmram")))
#elif defined(TARGET_STM32F4)
#define MOTEUS_CCM_ATTRIBUTE
#else
#error "Unknown target"
#endif



#define MOTEUS_MODEL_NUMBER ((MOTEUS_HW_REV) << 8 | 0x00)
#define MOTEUS_FIRMWARE_VERSION 0x000100

}
