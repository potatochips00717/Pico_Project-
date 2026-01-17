#include "pico/stdlib.h"
#include "tusb.h"
//#include "tusb_hid.h"
#include "device/usbd.h"
#include "class/hid/hid_device.h"
#include <stdio.h>
#include <hardware/gpio.h>




#define kbr 0x01
const uint faceButtons[]={0,1,2,3,4,5,6,7};
//if the orgional keys wante to be used, mostly u,j,i,k,o,l,p, and ; (yes, the semi-colin key)
const uint8_t faceKeys[]=
{
    HID_KEY_U,
    HID_KEY_J,
    HID_KEY_I,
    HID_KEY_K,
    HID_KEY_O,
    HID_KEY_L,
    HID_KEY_P,
    HID_KEY_SEMICOLON
};



const uint directions[]={8,9,10,11};
const uint8_t directionKeys[]=
{
    HID_KEY_W,
    HID_KEY_A,
    HID_KEY_S,
    HID_KEY_D
};
//basic up down left and right 
const uint extraButtons[]={12,13,14,15,16};
const uint8_t extraKeys[]=
{
    HID_KEY_TAB,
    HID_KEY_ENTER,
    HID_KEY_ESCAPE,
    HID_KEY_BACKSPACE,
    HID_KEY_SPACE
};
//should be stuff like enter, tab, escape, backspace and maybe space 





int main()
{
    stdio_init_all();
    set_buttons();
    while(true)
    {
        for (int i=0;i<8;i++)
        {
            if (faceButtons[i]==0)
            {
                key_sendy(faceKeys[i]);
            }
        }
        for (int i=0;i<4;i++)
        {
            if (directions[i]==0)
            {
                key_sendy(directionKeys[i]);
            }
        }

        for (int i=0;i<5;i++)
        {
            if (extraButtons[i]==0)
            {
                key_sendy(extraKeys[i]);
            }
        }
        sleep_ms(10);
    }

    return 0;
}


// creates the buttons to be used later 
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

void key_sendy(uint8_t keyP)
{
    if (tud_hid_ready())
    {
        uint8_t keyReader[]={keyP,0,0,0,0,0};
        tud_hid_keyboard_report(kbr, 0, keyReader);
    }
}
