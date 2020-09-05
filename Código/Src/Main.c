#include "Lib.h"

int main() {
    carga_c config;
    estados_c estado = espera; 
    
    config = f_inicio();
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

carga_c f_inicio(void)
{
    carga_c aux;
    aux.carga = 1;
    aux.carga_max = 750;
    aux.tolerancia = 75;
    return aux;
}

estados_c f_espera(carga_c config)
{
    while (config.carga < config.carga_max)
        printf("Sistema en espera");
    estados_c estado = avisomaximo;
    return (estado);
}

estados_c f_cargamax(carga_c config)
{
    while (config.carga_max <= config.carga < config.carga_max + config.tolerancia)
        printf("Carga completa");
    if (config.carga < config.carga_max)
        estados_c estado = espera;
        return (estado);
    if (config.carga >= config.carga_max + config.tolerancia)
        estados_c estado = avisosobrecarga;
        return (estado);
}

estados_c f_sobrecarga(carga_c config)
{
    while (config.carga >= config.carga_max + config.tolerancia)
        printf("Sobrecarga");
    estados_c estado = avisomaximo;
    return (estado);
}
