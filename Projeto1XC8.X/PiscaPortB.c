#include "SanUSB1X.h"

//#pragma interrupt interrupcao
void interrupt interrupcao(){}

long int i;

void delay (void)
{
  for (i = 0; i <10000; i++)
    ;
}

void main (void)
{
clock_int_4MHz();

  TRISB = 0;
  TRISD = 0;

  while (1)
    {
if(!entrada_pin_e3){Reset();}//pressionar o botão para gravação
      /* Zera a porta B */
      PORTB = 0; PORTD = 0;

      /* Delay para ver o Led */
      tempo_ms(300);

      /* Liga os LEDs */
      PORTB = 0xff; PORTD = 0xff;

     /* Delay para ver o Led */
      delay ();
    }
}

