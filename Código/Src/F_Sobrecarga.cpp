# include "Lib.h"

estados_c f_sobrecarga(carga_c config)
{
    estados_c estado;
    if (config.carga >= config.carga_max + config.tolerancia)
    {
        system ("color 04");
		printf("\nSobrecarga");
        estado = avisosobrecarga;
        return (estado);
    }
    estado = avisomaximo;
    return (estado);
}

