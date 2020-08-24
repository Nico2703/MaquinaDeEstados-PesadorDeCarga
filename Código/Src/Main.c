#include "Lib.h"

int main() {
    carga_c config;
    estados_t estado = espera; 

    config = inicio();
    while (1) {
        switch (estado) {
        case espera: estado = f_espera(config);
            break;
        case avisomaximo: estado = f_cargamax(config);
            break;
        case avisosobrecarga: estado = f_sobrecarga(config);
            break;
        }
    }
    return 0;
}