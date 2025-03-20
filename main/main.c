#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"


#define redLED 16
#define yellowLED 17
#define greenLED 18
#define sensor 5

void app_main(void)
{
    
    gpio_set_direction(redLED,GPIO_MODE_OUTPUT);

    gpio_set_direction(yellowLED,GPIO_MODE_OUTPUT);

    gpio_set_direction(greenLED,GPIO_MODE_OUTPUT);

    gpio_set_direction(sensor,GPIO_MODE_INPUT);
    gpio_set_pull_mode(sensor,GPIO_PULLUP_ONLY);
    
    ESP_LOGI("LED","Red LED ON");
    gpio_set_level(redLED,1);
    gpio_set_level(yellowLED,0);
    gpio_set_level(greenLED,0);

    while(1){
        int button = gpio_get_level(sensor);
        if(button == 0){
            ESP_LOGI("SENSOR","Car Detected");
            vTaskDelay(pdMS_TO_TICKS(1500));
            
            ESP_LOGI("LED","Yellow LED ON");
            gpio_set_level(redLED,0);
            gpio_set_level(yellowLED,1);
            gpio_set_level(greenLED,0);
            vTaskDelay(pdMS_TO_TICKS(1000));

            ESP_LOGI("LED","Green LED ON");
            gpio_set_level(redLED,0);
            gpio_set_level(yellowLED,0);
            gpio_set_level(greenLED,1);
            vTaskDelay(pdMS_TO_TICKS(1500));

            ESP_LOGI("LED","Red LED ON");
            gpio_set_level(redLED,1);
            gpio_set_level(yellowLED,0);
            gpio_set_level(greenLED,0);
        }else {
            vTaskDelay(pdMS_TO_TICKS(100));
        }
    }

}
