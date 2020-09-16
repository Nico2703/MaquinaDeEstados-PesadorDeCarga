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
    estados_c estado2;
    if (config.carga >= config.carga_max && config.carga < config.carga_max + config.tolerancia)
    {
        system ("color 06");
		printf("\n\nCARGA COMPLETA!");
		Sleep (3000);
        estado2 = avisomaximo;
        return (estado2);
    }
    if (config.carga < config.carga_max)
    {
        estado2 = espera;
        return (estado2);
    }
    if (config.carga >= config.carga_max + config.tolerancia)
    {
        estado2 = avisosobrecarga;
        return (estado2);
    }  
}

estados_c f_sobrecarga(carga_c config)
{
    estados_c estado3;
    if (config.carga >= config.carga_max + config.tolerancia)
    {
        system ("color 04");
		printf("\n\nSOBRECARGA!! \a");
		Sleep (3000);
        estado3 = avisosobrecarga;
        return (estado3);
    }
    estado3 = avisomaximo;
    return (estado3);
}
