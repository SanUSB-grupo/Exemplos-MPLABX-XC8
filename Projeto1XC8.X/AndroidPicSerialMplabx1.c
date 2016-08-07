//Utiliza interrupcao serial para receber comandos enviados via bluetooth ou zigbee para configuracao do PWM
#include "SanUSB1X.h" //
//o printf no XC8 eh resolvido inclusive para float, com string na ROM
     const char * s1 = "Hi from a RAM Pointer to a ROM \"string\""; //const leva os dados para a ROM
     const char * const s2 = "Hi from a ROM Pointer to a ROM \"string\"";
     char Teste[] = "Teste\r\n";  //string armazenada na RAM

//#pragma interrupt interrupcao
void interrupt interrupcao()
{
  unsigned char c;

 if (serial_interrompeu)  {            
     serial_interrompeu=0;
     c = le_serial();
    // if (c >= '0' && c<= '9')
     {
         switch (c){
             case 'L':
             nivel_alto(pin_b7);
                 break;
             case 'B':
           nivel_baixo(pin_b7);
                 break;
        
        }
     } 
   }
} 

//unsigned long int resultado, Vresult; //16 bits
void main(){
    clock_int_4MHz();

    habilita_interrupcao(recep_serial);
    taxa_serial(9600);

    while(1){
        if (entrada_pin_e3==0){Reset();}
        
        sendsw((char *)Teste);//envia string armazenada na RAM
        //sendsw((char *)s1);//envia string armazenada na RAM
        //printf("%s\n", Teste);
        printf("%s\n", s1);
        printf("%s\n", s2);

        inverte_saida(pin_b6);
        inverte_saida(pin_b7);
        tempo_ms(1000);
 
            }
}

