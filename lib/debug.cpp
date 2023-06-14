#include "debug.h"



/*void initialisationUART() {
    
    // 2400 bauds. Nous vous donnons la valeur des deux
    // premier registres pour vous éviter des complications
    UBRR0H = 0;
    UBRR0L = 0xCF;
    
    // permettre la reception et la transmission par le UART0
    UCSR0A = 0;
    UCSR0B |= (1 << RXEN0 | 1 << TXEN0);  // active la transmission et la reception
    
    // Format des trames: 8 bits, 1 stop bits, none parity
    UCSR0C = 1 << UCSZ01 | 1 << UCSZ00;
}*/

//methode qui envoie les donnees par le port serie de RS232
void transmissionUART(unsigned char data) {
    
    /* Wait for empty transmit buffer */
    while (!( UCSR0A & (1 << UDRE0))){
    }
    /* Put data into buffer, sends the data */
    UDR0 = data;
}
