#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define OUTPUT_GPIO 15

void app_main(void)
{
    printf("Hello world!\n");
    esp_rom_gpio_pad_select_gpio(OUTPUT_GPIO);
    gpio_set_direction(OUTPUT_GPIO, GPIO_MODE_OUTPUT);

    while (1) {
        gpio_set_level(OUTPUT_GPIO, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
