/*
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef mgos_ntc_thermistor_h
#define mgos_ntc_thermistor_h

#include "NTC_Thermistor.h"

#include "mgos.h"
#include "mgos_adc.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

NTC_Thermistor *mgos_ntc_thermistor_create();

bool mgos_ntc_thermistor_begin(NTC_Thermistor *sensor,
                               unsigned char pin,
                               double referenceResistance,
                               double nominalResistance,
                               double nominalTemperatureCelsius,
                               double bValue,
                               int adcResolution);

void mgos_ntc_thermistor_close(NTC_Thermistor *sensor);

/**
 * Reads a temperature in Celsius from the thermistor.
 * @return temperature in degree Celsius
 */
double mgos_ntc_thermistor_read_celsius(NTC_Thermistor *sensor);

/**
 * Reads a temperature in Fahrenheit from the thermistor.
 * @return temperature in degree Fahrenheit
 */
double mgos_ntc_thermistor_read_fahrenheit(NTC_Thermistor *sensor);

/**
 * Reads a temperature in Kelvin from the thermistor.
 * @return temperature in degree Kelvin
 */
double mgos_ntc_thermistor_read_kelvin(NTC_Thermistor *sensor);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* mgos_ntc_thermistor_h */
