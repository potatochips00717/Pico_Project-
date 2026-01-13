#include "pico/stdlib.h"
#include <stdio.h>


int main() {
    // Initialize USB serial output
    stdio_init_all();
    
    // Give time for serial to connect
    sleep_ms(2000);
    
    printf("\n=== Pico Program Started ===\n");
    
    // Configure onboard LED (GPIO 25)
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    
    printf("Board LED on GPIO %d\n", LED_PIN);
    // printf("System clock: %d Hz\n", clock_get_hz(clk_sys));
    
    uint32_t counter = 0;
    
    while (true) {
        // Toggle LED
        gpio_put(LED_PIN, !gpio_get(LED_PIN));
        
        // Print status
        printf("Counter: %d, LED: %s\n", 
               counter++,
               gpio_get(LED_PIN) ? "ON" : "OFF");
        
        // Wait
        sleep_ms(500);
    }
    
    return 0;
}
