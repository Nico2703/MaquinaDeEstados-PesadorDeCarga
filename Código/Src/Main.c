#include "Lib.h"

int main() {
    carga_c config;
    estados_c estado = espera; 

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

void f_espera(config)
{
    while (carga < carga_max)
        printf("Sistema en espera");
    return (avisomaximo = 1);
}

void f_avisomaximo(config)
{
    while (carga_max <= carga < carga_max + tolerancia)
        printf("Carga completa");
    if (carga < carga_max)
        return (espera = 1);
    if (carga = > carga_max + tolerancia)
        return (avisosobrecarga = 1);
}

void f_avisosobrecarga(config)
{
    while (carga = > carga_max + tolerancia)
        printf("Sobrecarga");
        return (avisomaximo = 1);
}
