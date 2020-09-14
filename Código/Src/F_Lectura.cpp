# include "Lib.h"

using namespace std;

carga_c f_lectura(void)
{
	system ("CLS");
    carga_c aux;
    cout<<"Carga maxima: "<<aux.carga_max<<endl;
	cout<<"Tolerancia: "<<aux.tolerancia<<endl;
	aux.carga = rand() % 100;                          //Simula la señal de entrada
	return (aux);
}

