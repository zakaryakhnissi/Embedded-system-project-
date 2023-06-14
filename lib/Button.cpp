#include "Button.h"

// constructeur : met la broche sur laquelle le bouton est connecté en entrée
Button::Button(volatile uint8_t &DDRx, uint8_t pin)
{
    DDRx &= ~(1 << pin); 
} 

Button::Button(volatile uint8_t *btnDDR[], uint8_t pins[], uint8_t nbButtons){

    for (uint8_t i = 0; i < nbButtons; i++)
    {
        Button(*btnDDR[i], pins[i]); 
    }
}


void Button::setSenseControl(PseudoPin pseudoPin, InterruptSenseControl ics)
{
    cli();
    
    switch (pseudoPin) 
    {
        case pseudoPD2:
            EIMSK |= (1 << INT0);
            switch (ics)
            {
                case InterruptSenseControl::LOW_LEVEL:
                    // Nothing to do
                    break;
                case InterruptSenseControl::ANY_EDGE:
                    EICRA |= (0 << ISC01) | (1 << ISC00);
                    break;
                case InterruptSenseControl::FALLING_EDGE:
                    EICRA |= (1 << ISC01) | (0 << ISC00);
                    break;
                case InterruptSenseControl::RISING_EDGE:
                    EICRA |= (1 << ISC01) | (1 << ISC00);
                    break;    
            }
            break;

        case pseudoPD3:
            EIMSK |= (1 << INT1);
            switch (ics)
            {
                case InterruptSenseControl::LOW_LEVEL:
                    // Nothing to do
                    break;
                case InterruptSenseControl::ANY_EDGE:
                    EICRA |= (0 << ISC11) | (1 << ISC10);
                    break;
                case InterruptSenseControl::FALLING_EDGE:
                    EICRA |= (1 << ISC11) | (0 << ISC10);
                    break;
                case InterruptSenseControl::RISING_EDGE:
                    EICRA |= (1 << ISC11) | (1 << ISC10);
                    break;    
            }
            break;

        case pseudoPB2:
            EIMSK |= (1 << INT2);
            switch (ics)
            {
                case InterruptSenseControl::LOW_LEVEL:
                    // Nothing to do
                    break;
                case InterruptSenseControl::ANY_EDGE:
                    EICRA |= (0 << ISC21) | (1 << ISC20);
                    break;
                case InterruptSenseControl::FALLING_EDGE:
                    EICRA |= (1 << ISC21) | (0 << ISC20);
                    break;
                case InterruptSenseControl::RISING_EDGE:
                    EICRA |= (1 << ISC21) | (1 << ISC20);
                    break;    
            }
            break; 
    }
    sei();
}

uint8_t mask(uint8_t &port, uint8_t pin)
{
    return port & (1 << pin);
}

bool Button::debounce(uint8_t &port, uint8_t pin) {
    
    bool isPressed = false; 

    if (mask(port, pin)) {
        _delay_ms(30);
        if (mask(port, pin))
            isPressed = true;
    }
    return isPressed;
}