//Programa de aplicação da função OU Exclusivo e NOT
#include <SanUSB.h>

short int ledXOR, ledpisca;

void main(void){
clock_int_4MHz();

while(1)
{
if(!entrada_pin_e3){Reset();}
ledXOR = entrada_pin_a0^entrada_pin_a1;  //OU exclusivo entre os pinos b1 e b2 ->input

saida_pino(pin_b6,ledXOR); 		   //O LedXOR mostra o resultado do OU exclusivo

ledpisca=!ledpisca;  		   // ledpisca é igual ao inverso de ledpisca
saida_pino(pin_b7,ledpisca);		   // b0 recebe o valor de ledpisca
tempo_ms(500);
}
}