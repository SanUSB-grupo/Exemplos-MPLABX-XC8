#include "SanUSB1X.h" // https://www.youtube.com/watch?v=klucfceoTtA
//bit A, B, saida, ledpisca;

//#pragma interrupt interrupcao
void interrupt interrupcao() { //Declara��o de interrup��o no XC8
}

void main() {
    clock_int_4MHz();

    while (1) {
        if (!entrada_pin_e3) {
            Reset();
        } //pressionar o bot�o para grava��o

        inverte_saida(pin_b7);
        tempo_ms(500);
    }
}
