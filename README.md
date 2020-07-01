# mongoose-lib-ntc-thermistor

## Description

A Mongoose OS library to use Arduino NTC thermistor.

## Demo app

See the [demo project](https://github.com/hobbe/mongoose-lib-ntc-thermistor-demo)
for use with a Shelly 1PM.

## Sample

```cpp
#include "mgos.h"
#include "mgos_ntc_thermistor.h"

static struct NTC_Thermistor *ntc = NULL;

static void timer_cb(void *arg) {
  if (ntc != NULL) {
    double temperature = mgos_ntc_thermistor_read_celsius(ntc);
    LOG(LL_INFO, ("Temperature: %.1f C", temperature));
  } else {
    LOG(LL_INFO, ("No temperature reading"));
  }

  (void) arg;
}

enum mgos_app_init_result mgos_app_init(void) {
  if ((ntc = mgos_ntc_thermistor_create()) == NULL) {
    LOG(LL_ERROR, ("Unable to initialize NTC Thermistor"));
  } else {
    const unsigned char pin = 0;
    const double referenceResistance = 10000;
    const double nominalResistance = 32000;
    const double nominalTemperatureCelsius = 25;
    const double bValue = 3350;
    const int adcResolution = 1024;
    mgos_ntc_thermistor_begin(ntc, pin, referenceResistance, nominalResistance,
                              nominalTemperatureCelsius, bValue, adcResolution);
    LOG(LL_INFO, ("NTC Thermistor initialized"));
  }

  mgos_set_timer(2000 /* ms */, MGOS_TIMER_REPEAT, timer_cb, NULL);

  return MGOS_APP_INIT_SUCCESS;
}
```

## Credits

Based on the library [NTC_Thermistor](https://github.com/YuriiSalimov/NTC_Thermistor)
from [YuriiSalimov](https://github.com/YuriiSalimov).

## Licensing

Apache License Version 2.0, see also [Mongoose OS](https://github.com/cesanta/mongoose-os).
