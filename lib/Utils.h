#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define OFF   0
#define GREEN 1
#define RED   2
#define AMBRE 3

#define THRESHOLD 4
#define JUMP      10
#define DELAY    50

enum PinState {
    LOW, 
    HIGH 
};

namespace Utils
{
    void setPinState(volatile uint8_t *port, uint8_t pins[], PinState pinState[], uint8_t nbPins);
    void setPinState(volatile uint8_t *port, uint8_t pin, PinState pinState);
    void setAllDDR(bool output);
    void dynamic_delay_ms(uint16_t delay);
    void turnOnMatrix(uint8_t operand);
    void turnOffMatrix();
    void turnOffDirection();
    void directionNorth();
    void directionSouth();
    void directionEast();
    void directionWest();
    void turnOffDisplay();
    };   