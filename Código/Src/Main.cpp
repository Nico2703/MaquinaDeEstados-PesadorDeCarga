# include "Lib.h"

using namespace std;
fstream archivo;

int main() {
    carga_c config;
    estados_c estado = espera; 
    
    while (1) {
    	config = f_inicio();
        switch (estado) {
        case espera: 
		estado = f_espera(config);
        break;
        case avisomaximo: 
		estado = f_cargamax(config);
        break;
        case avisosobrecarga: 
		estado = f_sobrecarga(config);
        break;
        }
    }
    return 0;
}

carga_c f_inicio(void)
    {
    system ("CLS");
    carga_c aux;
    string comentarios;
	archivo.open("Config.txt",ios::in);
	if (archivo.is_open())
	{	
	while ( !archivo.eof() ){
		archivo>>comentarios>>aux.carga_max>>comentarios>>aux.tolerancia;
		cout<<"Carga maxima: "<<aux.carga_max<<endl;
		cout<<"Tolerancia: "<<aux.tolerancia<<endl;
    }
	archivo.close(); 
	printf ("\nCarga: ");
	cin>>aux.carga;
	return (aux);
	}
	else
	{
		cout<<"\nArchivo no encontrado"<<endl;
	}
}

estados_c f_espera(carga_c config)
{
    estados_c estado;
    while (config.carga < config.carga_max)
    {
	  printf("Sistema en espera\n\n");
      system("PAUSE");
      estado = espera;
      return (estado);
    }
    estado = avisomaximo;
    return (estado);
}

estados_c f_cargamax(carga_c config)
{
    estados_c estado;
    while (config.carga >= config.carga_max && config.carga < config.carga_max + config.tolerancia)
    {
        printf("Carga completa\n\n");
        system ("PAUSE");
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
    while (config.carga >= config.carga_max + config.tolerancia)
    {
        printf("Sobrecarga\n\n");
        system ("PAUSE");
        estado = avisosobrecarga;
        return (estado);
    }
    estado = avisomaximo;
    return (estado);
}

