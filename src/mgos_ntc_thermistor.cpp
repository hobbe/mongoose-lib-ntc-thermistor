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

#include "mgos_ntc_thermistor.h"

NTC_Thermistor *mgos_ntc_thermistor_create() {
  return new NTC_Thermistor();
}

void mgos_ntc_thermistor_close(NTC_Thermistor *sensor) {
  if (sensor != nullptr) {
    delete sensor;
    sensor = nullptr;
  }
}

bool mgos_ntc_thermistor_begin(NTC_Thermistor *sensor,
                               const unsigned char pin,
                               const double referenceResistance,
                               const double nominalResistance,
                               const double nominalTemperatureCelsius,
                               const double bValue,
                               const int adcResolution) {
  if (sensor == nullptr) return false;

  sensor->initialize(pin, referenceResistance, nominalResistance, nominalTemperatureCelsius, bValue, adcResolution);
  return true;
}

double mgos_ntc_thermistor_read_celsius(NTC_Thermistor *sensor) {
  if (sensor == nullptr) return 0;
  return sensor->readCelsius();
}

double mgos_ntc_thermistor_read_fahrenheit(NTC_Thermistor *sensor) {
  if (sensor == nullptr) return 0;
  return sensor->readFahrenheit();
}

double mgos_ntc_thermistor_read_kelvin(NTC_Thermistor *sensor) {
  if (sensor == nullptr) return 0;
  return sensor->readKelvin();
}
