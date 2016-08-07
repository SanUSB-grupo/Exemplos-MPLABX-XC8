//Utiliza interrupcao serial para receber comandos enviados via bluetooth ou zigbee
#include "SanUSB48X.h"
short int pisca=0;
unsigned char comando;

//#pragma interrupt interrupcao
void interrupt interrupcao()
{
 if (serial_interrompeu)  {
     serial_interrompeu=0;
     comando = le_serial();

         switch (comando){
             case 'L':
             pisca=0; nivel_alto(pin_b7); //Não imprime (printf) dentro da interrupcao
             break;

             case 'D':
             pisca=0; nivel_baixo(pin_b7);
             break;

             case 'P':
             pisca=1;nivel_alto(pin_b7);
             break;
         }
   }
}

void main(){
    clock_int_48MHz();
    habilita_interrupcao(recep_serial);
    taxa_serial(19200);

    while(1){
   if (entrada_pin_e3==0){Reset();} //com interrupcao evitar no while, pois pode dar conflito com a gravacao
   while (pisca==1){
                    inverte_saida(pin_b7);tempo_ms(300);
                   }//pisca rapido

     sendsw((char *)"SanUSB\r\n");
     tempo_ms(1000);
     inverte_saida(pin_b7);

    }
}
