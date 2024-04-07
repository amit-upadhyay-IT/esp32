| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C6 | ESP32-H2 | ESP32-P4 | ESP32-S2 | ESP32-S3 | Linux |
| ----------------- | ----- | -------- | -------- | -------- | -------- | -------- | -------- | -------- | ----- |

# Hello World Example

Starts a FreeRTOS task to print "Hello World".

## output of program:

> Hello world!
> This is esp32 chip with 2 CPU core(s), WiFi/BTBLE, silicon revision v3.1, 2MB external flash
> Minimum free heap size: 300876 bytes


we load the chip info like this:
```
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
```

we can get the esp details like this:
```
    chip_info.cores,
    (chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "WiFi/" : "",
    (chip_info.features & CHIP_FEATURE_BT) ? "BT" : "",
    (chip_info.features & CHIP_FEATURE_BLE) ? "BLE" : "",
    (chip_info.features & CHIP_FEATURE_IEEE802154) ? ", 802.15.4 (Zigbee/Thread)" : "")
```

We can get the flash shize using:
```
uint32_t flash_size;
esp_flash_get_size(NULL, &flash_size);
```

Free heap space could also be a useful metric:
```
esp_get_minimum_free_heap_size();
```

## Example folder contents

The project **hello_world** contains one source file in C language [hello_world_main.c](main/hello_world_main.c). The file is located in folder [main](main).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt` files that provide set of directives and instructions describing the project's source files and targets (executable, library, or both).

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt
├── pytest_hello_world.py      Python script used for automated testing
├── main
│   ├── CMakeLists.txt
│   └── hello_world_main.c
└── README.md                  This is the file you are currently reading
```

For more information on structure and contents of ESP-IDF projects, please refer to Section [Build System](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html) of the ESP-IDF Programming Guide.

## Troubleshooting

* Program upload failure

    * Hardware connection is not correct: run `idf.py -p PORT monitor`, and reboot your board to see if there are any output logs.
    * The baud rate for downloading is too high: lower your baud rate in the `menuconfig` menu, and try again.