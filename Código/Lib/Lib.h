#ifndef LIB
#define LIB
#include <stdio.h>
#include <stdlib.h>

typedef enum {
	 espera = 0,
     avisomaximo = 1,
     avisosobrecarga = 2
}estados_c;

typedef struct {
	int carga;         // Carga actual
	int carga_max;     // Carga seteada
	int tolerancia;    // Delta de carga
}carga_c;

carga_c f_inicio(void); // Lee el archivo de configuracion y carga las variables.
estados_c f_espera(carga_c);
estados_c f_cargamax(carga_c);
estados_c f_sobrecarga(carga_c);

#endif
