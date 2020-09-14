# include "Lib.h"

int main() {
    carga_c config;
    estados_c estado = espera; 
    config = f_inicio();
    
    while (1) {
    	config = f_lectura();
        switch (estado) {
        case espera: 
		estado = f_espera(config);
        break;
        case avisomaximo: 
		estado = f_cargamax(config);
        break;
        case avisosobrecarga: 
		estado = f_sobrecarga(config);
        break;
        }
    }
    return 0;
}


