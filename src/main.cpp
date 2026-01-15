#include "pico/stdlib.h"
#include "tusb.h"
#include "device/usbd.h"
#include "class/hid/hid_device.h"
#include <stdio.h>
#include <hardware/gpio.h>

// #define faceButton1 0
// #define faceButton2 1
// #define faceButton3 2
// #define faceButton4 3
// #define faceButton5 4
// #define faceButton6 5
// #define faceButton7 6
// #define faceButton8 7

const uint faceButtons[]={0,1,2,3,4,5,6,7};
//if the orgional keys wante to be used, mostly u,j,i,k,o,l,p, and ; (yes, the semi-colin key)


// #define up 8
// #define down 9
// #define left 10
// #define right 11

const uint directions[]={8,9,10,11};
//basic up down left and right 

// #define extraButton1 12
// #define extraButton2 13
// #define extraButton3 14
// #define extraButton4 15
// #define extraButton5 16

const uint extraButtons[]={12,13,14,15,16};
//should be stuff like enter, tab, escape, backspace and maybe shift 

int main()
{
    stdio_init_all();
    set_buttons();

    if (gpio_get(faceButtons[0]==0))
    {
       //attack 1  
    }



    return 0;
}

void set_buttons()
{
    for(int i=0;i<(sizeof(faceButtons)/faceButtons[0]);i++) 
    {
        gpio_init(faceButtons[i]);
        gpio_set_dir(faceButtons[i], GPIO_IN);
    }
    for(int i=0;i<(sizeof(directions)/directions[0]);i++) 
    {
        gpio_init(directions[i]);
        gpio_set_dir(directions[i], GPIO_IN);
    }
    for(int i=0;i<(sizeof(extraButtons)/extraButtons[0]);i++) 
    {
        gpio_init(extraButtons[i]);
        gpio_set_dir(extraButtons[i], GPIO_IN);
    }
}