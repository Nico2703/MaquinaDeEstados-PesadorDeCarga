# include "Lib.h"

estados_c f_espera(carga_c config)
{
    estados_c estado;
    if (config.carga < config.carga_max)
    {
      system ("color 02");
	  printf("\nSistema en espera");
      estado = espera;
      return (estado);
    }
    estado = avisomaximo;
    return (estado);
}
