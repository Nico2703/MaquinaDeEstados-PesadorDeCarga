# include "Lib.h"

int main() {
	estados_c (*fsm[])(carga_c)={f_espera,f_cargamax,f_sobrecarga};
    carga_c config;
    estados_c estado = espera; 
    config = f_inicio(); 
    Sleep(3000);
    while (1) {
    	config = f_lectura();
    	estado = (*fsm[estado])(config);
    }
    return 0;
}


