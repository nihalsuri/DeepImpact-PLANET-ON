#include "npt_stack.h"

static const char *TAG = "ntp stack";


void ntp_start_time(void){

    ESP_LOGI(TAG, "getting ntp time");
    sntp_setoperatingmode(SNTP_OPMODE_POLL);
    sntp_setservername(0, "pool.ntp.org");
    sntp_set_time_sync_notification_cb(time_sync_notification);
    sntp_init();
}

void time_sync_notification(struct timeval *tv){

    char strTime[50];
    sprintf(strTime,"%ld",tv->tv_sec);

    ESP_LOGI(TAG, "time synchronization event %s", strTime);

    
}