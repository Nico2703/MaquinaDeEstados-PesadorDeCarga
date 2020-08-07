## TP- Máquina de estados
## Pesador de carga
Balanza electrónica con indicador de "carga completa" y "sobrecarga". Configurable con datos de "carga máxima" y "tolerancia"
### Memoria descriptiva
Este sistema representa un control de cargas, por ejemplo, de un ascensor. El mismo, se inicializa con los parámetros de carga máxima y tolerancia, indicados por el usuario. 
Existen varias maneras de sensar la carga, celdas de carga, transformadores diferenciales, entre otros. Con el agregado de controles electrónicos, se traduce la información de estos transductores en señales para su interpretación y manejo.
El pesador, permanecerá sin cambios mientras la carga sensada sea menor a la carga máxima indicada.
Una vez alcanzada la carga máxima y mientras se encuentre dentro de la tolerancia admitida, emitirá un mensaje de carga completa.
Luego de superado este valor, emitirá un mensaje de sobrecarga.
Estos mensajes serán visuales y sonoros.
### Diagrama de estados y transiciones
 ![./Recursos/Diagrama.png](https://github.com/Nico2703/TP-MaquinaDeEstados-PesadorDeCarga/blob/master/Recursos/Diagrama.png)
 - __SET__:  Bandera de fin de inicialización
 - __Carga__:  Carga sensada en tiempo real
 - __Carga_máx__:  Carga máxima seteada
 - __Tolerancia__:  Tolerancia admisible
