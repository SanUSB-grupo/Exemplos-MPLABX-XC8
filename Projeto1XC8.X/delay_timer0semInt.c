#include "SanUSB1X.h" // Prática de interrupção do temporizador 0

 unsigned int i;

//#pragma interrupt interrupcao
void interrupt interrupcao(){}

void main() {
clock_int_4MHz();
 //T0CON BITS = TMR0ON , T08BIT(0=16bits OR 1=8bits), T0CS , T0SE , PSA , T0PS2 T0PS1 T0PS0.
 //Defaull 1 in all bits.
T0CON =0B11000001; //TMR0ON, 8 bits, Prescaler 1:4 (001 - see datasheet)
TMR0L = 6; //conta 250us antes de estourar x 4 = 1ms

while (1){
    if(!entrada_pin_e3){Reset();}//pressionar o botão para gravação
		
    inverte_saida(pin_b7);
    timer0_ms(1000);
    }
}
