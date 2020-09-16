# include "Lib.h"

estados_c f_espera(carga_c config)
{
    estados_c estado;
    if (config.carga < config.carga_max)
    {
      system ("color 02");
	  printf("\n\nSISTEMA EN ESPERA");
	  Sleep (3000);
      estado = espera;
      return (estado);
    }
    estado = avisomaximo;
    return (estado);
}

estados_c f_cargamax(carga_c config)
{
    estados_c estado;
    if (config.carga >= config.carga_max && config.carga < config.carga_max + config.tolerancia)
    {
        system ("color 06");
		printf("\n\nCARGA COMPLETA!");
		Sleep (3000);
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

estados_c f_sobrecarga(carga_c config)
{
    estados_c estado;
    if (config.carga >= config.carga_max + config.tolerancia)
    {
        system ("color 04");
		printf("\n\nSOBRECARGA!! \a");
		Sleep (3000);
        estado = avisosobrecarga;
        return (estado);
    }
    estado = avisomaximo;
    return (estado);
}
