| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C6 | ESP32-H2 | ESP32-P4 | ESP32-S2 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- | -------- | -------- | -------- | -------- | -------- |

# FreeRTOS tasks

To create a task: 
```
xTaskCreate(&task1, "task1", 2048, "parameter 1", 1, NULL);
```


we typically have 2 cores in esp32 dev.
- first is usually used for the application, i.e. the one that runs the main method
- second is usually used to handle background things like, communication, various other bg tasks like connection to bluetooth.

we can designate the task on any of the two cores via this method:
```
xTaskCreatePinnedToCore(&task2, "humidity reading", 2048, "task 2", 2, NULL,0); // last argument 0 is for first core, 1 is for second core.
```