#include <stdio.h>
#include "nvs_flash.h"  // non-volatile storage to store some nimble configuration
#include "esp_log.h"
#include "nimble/nimble_port.h"
#include "nimble/nimble_port_freertos.h"
#include "host/ble_hs.h"  // the host stack for nimble
#include "esp_nimble_hci.h"  // the host control interface for nimble
#include "services/gap/ble_svc_gap.h"  // to access GAP profile, i.e. how do we advertise our device

void ble_app_on_sync(void)
{
    ble_addr_t addr;
    ble_hs_id_gen_rnd(1, &addr);
    ble_hs_id_set_rnd(addr.val);

    uint8_t uuid128[16];
    memset(uuid128, 0x11, sizeof(uuid128));
    ble_ibeacon_set_adv_data(uuid128, 2, 10, -50);

    struct ble_gap_adv_params adv_params = (struct ble_gap_adv_params){0};
    ble_gap_adv_start(BLE_OWN_ADDR_RANDOM, NULL, BLE_HS_FOREVER, &adv_params, NULL, NULL);
}

void app_main(void)
{
    nvs_flash_init();  // initialize the non-volatile storage

    // there will be some initialization of the nimble stack, pretty much like a boilerplate code for nimble

    esp_nimble_hci_and_controller_init();  // initialize the host control interface and the controller
    nimble_port_init();  // initialize the nimble port

}
