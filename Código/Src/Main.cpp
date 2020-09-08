# include "Lib.h"

using namespace std;
fstream archivo;

int main() {
    carga_c config;
    estados_c estado = espera; 
    config = f_inicio();
    
    while (1) {
        switch (estado) {
        case espera: 
        config = f_lectura();
		estado = f_espera(config);
        break;
        case avisomaximo: 
        config = f_lectura();
		estado = f_cargamax(config);
        break;
        case avisosobrecarga: 
        config = f_lectura();
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
	return (aux);
	}
	else
	{
		cout<<"\nArchivo no encontrado"<<endl;
	}
}

carga_c f_lectura(void)
{
	system ("CLS");
    carga_c aux;
    cout<<"Carga maxima: "<<aux.carga_max<<endl;
	cout<<"Tolerancia: "<<aux.tolerancia<<endl;
	aux.carga = rand() % 100;                          //Simula la señal de entrada
	return (aux);
}

estados_c f_espera(carga_c config)
{
    estados_c estado;
    while (config.carga < config.carga_max)
    {
      system ("color 02");
	  printf("\nSistema en espera");
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

estados_c f_sobrecarga(carga_c config)
{
    estados_c estado;
    while (config.carga >= config.carga_max + config.tolerancia)
    {
        system ("color 04");
		printf("\nSobrecarga");
        estado = avisosobrecarga;
        return (estado);
    }
    estado = avisomaximo;
    return (estado);
}

