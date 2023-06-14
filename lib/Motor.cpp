#include "Motor.h"


Motor::Motor()
{
}

Motor::~Motor()
{
}

void Motor::forward(uint8_t ocr1a, uint8_t ocr1b)
{
    Motor::fwd = true;
    PORTD |= _BV(PD6);
    PORTD |= _BV(PD3);
    PWM::adjustPWM(ocr1a, ocr1b);
}

void Motor::backward(uint8_t ocr1a, uint8_t ocr1b)
{
    Motor::fwd = false;
    PORTD &= ~_BV(PD6);
    PORTD &= ~_BV(PD3);
    PWM::adjustPWM(ocr1a, ocr1b);

}

void Motor::turnLeft()
{
    if(Motor::fwd) 
    {
        PORTD = _BV(PD6);
    }
    else {
        PORTD &= ~_BV(PD6);
    }
    PWM::adjustPWM(254, 0);
}

void Motor::turnRight()
{
    if(Motor::fwd) 
    {
        PORTD = _BV(PD3);
    }
    else {
        PORTD &= ~_BV(PD3);
    }
    PWM::adjustPWM(0, 254);
}   

void Motor::stop()
{
    PWM::adjustPWM(0, 0);
}