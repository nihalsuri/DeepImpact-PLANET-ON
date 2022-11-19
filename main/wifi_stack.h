#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"

#include "mqtt_stack.h"
#include "npt_stack.h"

#define WIFI_SSID "CoworkingLab"
#define WIFI_PASSWORD "67VCj@I#rc"
#define MAX_RETRIES 7


#define BIT_WIFI_CONNECTED BIT0
#define BIT_WIFI_FAIL BIT2

static EventGroupHandle_t s_wifi_event_group;

void wifi_init_sta(void);