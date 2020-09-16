# include "Lib.h"

using namespace std;
fstream archivo;

carga_c f_inicio(void)
    {
    system ("CLS");
    carga_c aux;
    string comentarios;
	archivo.open("Config.txt",ios::in);
	if (archivo.is_open())
	{	
	while ( !archivo.eof() ){
		archivo>>comentarios>>comentarios>>aux.carga_max>>comentarios>>comentarios>>aux.tolerancia;
		if ( !archivo.eof() )
		{
		cout<<"PESADOR DESACTIVADO"<<endl;
        cout<<"DATOS DE AJUSTE"<<endl;
		cout<<"Carga maxima: "<<aux.carga_max<<endl;
		cout<<"Tolerancia: "<<aux.tolerancia<<endl;
	    }
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
    cout<<"PESADOR ACTIVADO"<<endl;
    cout<<"DATOS DE AJUSTE"<<endl;
    cout<<"Carga maxima: "<<aux.carga_max<<endl;
	cout<<"Tolerancia: "<<aux.tolerancia<<endl; 
	aux.carga = rand() % 100;                         //Simula la señal de entrada                        
	return (aux);
}
