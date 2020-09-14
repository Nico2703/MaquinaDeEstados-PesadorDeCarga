# include "Lib.h"

int main() {
    carga_c config;
    estados_c estado = espera; 
    config = f_inicio();
    
    while (1) {
        switch (estado) {
        case espera: 
        config = f_lectura();
		estado = f_espera(config);
        break;
        case avisomaximo: 
        config = f_lectura();
		estado = f_cargamax(config);
        break;
        case avisosobrecarga: 
        config = f_lectura();
		estado = f_sobrecarga(config);
        break;
        }
    }
    return 0;
}


