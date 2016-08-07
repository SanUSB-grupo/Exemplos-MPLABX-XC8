#include "SanUSB48.h" 


short int pisca=0;
unsigned char comando;

 unsigned long int data=0;
 char msg[32];
 char str[10]; 

#define TC_CLK pin_c0 
#define TC_CS pin_c1
#define TC_DATA entrada_pin_c2 //PORTCbits.RC2 -Default entrada -> TRISC=1

void FloattoAscSerial(float value, char *string)
 {
long ParteInt=0; // Stores digits left of decimal
unsigned long ParteDec=0; // Stores digits right of decimal

     if (value < 0) {// se valor for negativo
         *string++ = '-';
         value = -value;
     }
//ParteInt=(long)(value);
//ParteDec=(int)(value*100)-ParteInt*100; 
//sprintf(string, (const far rom char *) "%lu.%02u",ParteInt,ParteDec);
 sprintf(string, (const far rom char *) "%lu.%02u",
                     (long) value,//int Decimal = diferenca do float e a parte inteira (long)
                     (int) ((value - (long) value) * 100));

    sendsw((char *)str);
  }

unsigned long int TempSPI(void)//pode ser mais de um termopar
    {
    unsigned long int valor = 0;
    float temp = 0;
    char i;

     nivel_baixo(TC_CS); ////pára a conversão AD para transmitir
    for (i=0;i<32;i++) //pega os 32 bits from the MAX31855
        {
        nivel_alto(TC_CLK); //tempo_ms(1);
        if (TC_DATA==1){valor = valor | 1;} // 
        nivel_baixo(TC_CLK); //tempo_ms(1);
        if (i != 31) valor = valor << 1;
        }
    nivel_alto(TC_CS);
    valor = 0x1FFF & (valor >> 18); //shift 18 e retorna ate 13 bits válidos do AD
    temp = valor * 0.25; //Converte para graus
    FloattoAscSerial(temp,str); 
    }


#pragma interrupt interrupcao
void interrupcao()
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
    nivel_alto(TC_CS);             //AD interno convertendo
    

    while(1){
   if (entrada_pin_e3==0){Reset();} //com interrupcao evitar no while, pois pode dar conflito com a gravacao
   while (pisca==1){
                    inverte_saida(pin_b7);tempo_ms (300);
                   }

     inverte_saida(pin_b7);
     TempSPI();sendrw((rom char *)"\r\n");
     tempo_ms (3000);

    }
}

