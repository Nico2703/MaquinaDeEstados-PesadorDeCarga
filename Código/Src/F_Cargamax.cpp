# include "Lib.h"

estados_c f_cargamax(carga_c config)
{
    estados_c estado;
    if (config.carga >= config.carga_max && config.carga < config.carga_max + config.tolerancia)
    {
        system ("color 06");
		printf("\nCarga completa");
        estado = avisomaximo;
        return (estado);
    }
    if (config.carga < config.carga_max)
    {
        estado = espera;
        return (estado);
    }
    if (config.carga >= config.carga_max + config.tolerancia)
    {
        estado = avisosobrecarga;
        return (estado);
    }  
}

