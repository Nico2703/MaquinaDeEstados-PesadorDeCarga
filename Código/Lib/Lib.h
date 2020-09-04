#ifndef LIB
#define LIB
#include <stdio.h>

typedef enum {
	espera = 1,
    avisomaximo = 0,
    avisosobrecarga = 0,
}estados_c;

typedef struct {
	char carga;         // Carga actual
	char carga_max;     // Carga seteada
	char tolerancia;    // Delta de carga
}carga_c;

carga_c f_inicio(void); // Lee el archivo de configuración y carga las variables.
estados_c f_espera(carga_c);
estados_c f_cargamax(carga_c);
estados_c f_sobrecarga(carga_c);

#endif
