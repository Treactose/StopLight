#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


#define redLED 16
#define yellowLED 17
#define greenLED 18

void app_main(void)
{
    esp_rom_gpio_pad_select_gpio(redLED);
    gpio_set_direction(redLED,GPIO_MODE_OUTPUT);

    esp_rom_gpio_pad_select_gpio(yellowLED);
    gpio_set_direction(yellowLED,GPIO_MODE_OUTPUT);

    esp_rom_gpio_pad_select_gpio(greenLED);
    gpio_set_direction(greenLED,GPIO_MODE_OUTPUT);

    while(1){
        gpio_set_level(redLED,1);
        gpio_set_level(yellowLED,0);
        gpio_set_level(greenLED,0);
        vTaskDelay(15000);
        
        gpio_set_level(redLED,0);
        gpio_set_level(yellowLED,1);
        gpio_set_level(greenLED,0);
        vTaskDelay(5000);

        gpio_set_level(redLED,0);
        gpio_set_level(yellowLED,0);
        gpio_set_level(greenLED,1);
        vTaskDelay(15000);
    }

}
