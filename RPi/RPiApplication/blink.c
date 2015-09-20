#include <bcm2835.h>
#include "blink.h"

#define PIN RPI_GPIO_P1_11

void blink_setup(void){
     if (!bcm2835_init())
        return 1;
    // Set the pin to be an output
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);

}

void blink_toggle(void){

    // Blink
    // Turn it on
    bcm2835_gpio_write(PIN, HIGH);
        
    // wait a bit
    bcm2835_delay(500);
        
    // turn it off
    bcm2835_gpio_write(PIN, LOW);
        
    // wait a bit
    bcm2835_delay(500);
}
void blink_set_high(void){
    bcm2835_gpio_write(PIN, HIGH);
}
void blink_set_low(void){
     bcm2835_gpio_write(PIN, LOW);
}
void blink_close(void){
    bcm2835_close();
}