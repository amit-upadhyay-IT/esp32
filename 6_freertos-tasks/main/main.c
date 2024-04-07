#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void task1(void *params) {
    while(1) {
        printf("Task 1: Param %s\n", (char *)params);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void task2(void *params) {
    while(1) {
        printf("Task 2: Param %s\n", (char *)params);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}


void app_main(void)
{
    xTaskCreate(&task1, "task1", 2048, "parameter 1", 1, NULL);
    xTaskCreate(&task2, "task2", 2048, "parameter 2", 1, NULL);
}
