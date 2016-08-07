#include "SanUSBino.h"

int soma = 0;
int qtdIn = 0;

void setup(){
  
            }

void loop()
{
    int i;
    if(!entrada_pin_e3){
        tempo_ms(500);
        if(!entrada_pin_e3){
            qtdIn++;
            if (qtdIn < 3){
                nivel_baixo(pin_b7);
                tempo_ms(300);
                nivel_alto(pin_b7);
            }else{
                nivel_baixo(pin_b7);
                tempo_ms(500);
                for(i = 0; i < soma; i++){
                    nivel_alto(pin_b7);
                    tempo_ms(500);
                    nivel_baixo(pin_b7);
                    tempo_ms(500);
                }
                soma = 0;
                qtdIn = 0;
            }
            tempo_ms(500);
        }else{
            soma++;
            tempo_ms(500);
            nivel_alto(pin_b6);
            tempo_ms(200);
            nivel_baixo(pin_b6);
            tempo_ms(200);
        }
    }
}
