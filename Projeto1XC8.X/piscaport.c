#include "SanUSB1X.h"

//#pragma interrupt interrupcao
void interrupt interrupcao(){}

void main (void)
{
clock_int_4MHz();

while (1)
{
   nivel_alto(pin_b6); 
   tempo_ms(500);
   nivel_baixo(pin_b6);
   tempo_ms(500);
   nivel_alto(pin_b7); 
   tempo_ms(500);
   nivel_baixo(pin_b7);
   tempo_ms(500);
}
}
