/**********************************************************************
* Filename    : Softlight.cpp
* Description : Use potentiometer to control LED
* Author      : www.freenove.com
* modification: 2020/03/07
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <softPwm.h>
// #include <ADCDevice.hpp>

#define R_Pin 23         //define 3 pins for RGBLED
#define G_Pin 24
#define B_Pin 25

void setupPinLed(void){
    softPwmCreate(R_Pin, 0, 255); //Create SoftPWM pin for red
    softPwmCreate(G_Pin, 0, 255); //Create SoftPWM pin for green
    softPwmCreate(B_Pin, 0, 255); //Create SoftPWM pin for blue
}

void setupPinColor(int r, int g, int b){
    softPwmWrite(R_Pin, 255 - r); //Set the duty cycle
    softPwmWrite(G_Pin, 255 - g); //Set the duty cycle
    softPwmWrite(B_Pin, 255 - b); //Set the duty cycle
}

// ADCDevice *adc;  // Define an ADC Device class object

int main(void){

    int r, g, b;
    wiringPiSetup();
    setupPinLed();

    for(;;){
        // srand(time(NULL));
        /* generate secret number between 1 and 255: */
        printf("R: ");
        scanf("%d", &r);
        printf("G: ");
        scanf("%d", &g);
        printf("B: ");
        scanf("%d", &b);
        // Get user input from the keyboard
        // r = 255 - rand() % 255 + 1;
        // g = 255 - rand() % 255 + 1;
        // b = 255 - rand() % 255 + 1;

        printf("R: %d\tG: %d\tB: %d\n", r, g, b);
        setupPinColor(r, g, b);
        delay(10000);
    }
    
    return 0;
}
