#include "esp_log.h"


#include "mqtt_client.h"

#define BROKER_URL "mqtt://10.230.24.108:1883"

void log_error_if_nonzero(const char *message, int error_code);

void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data);

void mqtt_app_start(void);