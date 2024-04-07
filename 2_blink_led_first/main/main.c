#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


#define PIN 2

void app_main(void) {
    gpio_set_direction(PIN, GPIO_MODE_OUTPUT);
    uint32_t isOn = 0;

    while (true) {
        isOn = !isOn;
        gpio_set_level(PIN, isOn);
        vTaskDelay(pdMS_TO_TICKS(10000));
    }
}
