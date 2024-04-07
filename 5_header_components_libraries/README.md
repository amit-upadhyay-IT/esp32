| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C6 | ESP32-H2 | ESP32-P4 | ESP32-S2 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- | -------- | -------- | -------- | -------- | -------- |

# Header, components and libraries

### Notes:

- creating header files will not need you to declare the method signature before it's usage.

- components can be made for packaing with following CMakeLists

```txt
idf_component_register(
    SRCS 
        "calc3.c"
    INCLUDE_DIRS 
        "."
    REQUIRES
        "driver"
)
```

REQUIRES specifies the packages which can be used in that componenets, to use the IntelliSense we need to build after updating the CMakeLists file

- for normal packaging, we can have a package inside main with defined .h file

- external libraries can be found here: https://components.espressif.com/components?q=