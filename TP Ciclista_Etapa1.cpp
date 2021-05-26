
/* Trabajo práctico Ciclista
Integrantes:
- Mateo, Bautista
- Recalde, Ignacio
- Salas, Rodrigo
- Signori, Horacio
*//////////////////////


/*Etapa 1
Desarrollar una aplicación que permita al ciclista:
a. Cargar los datos de las vueltas seleccionadas. Se debe poder cargar los datos de una
cantidad arbitraria de vueltas determinada por el ciclista.
b. Cuál fue, de las ingresadas, la vuelta más rápida y su tiempo.
c. Cuál fue, de las ingresadas, la vuelta más lenta y su tiempo.
d. Cuál fue la velocidad media, expresada en m/s. (Vm = distancia / Tmax - Tmin)
*/

#include<iostream>

using namespace std;

//Estructuras
struct st_Vuelta {
	int nroVuelta;
	int tiempoVuelta;
	int largoVuelta;
};

//                                              Defi. Funciones

void ingresoDeDato(string mensajeAlUsuario, int &valorDetalle);

void cargaDeVueltas(st_Vuelta Vueltas[], int cantVueltas);

st_Vuelta vueltaMasRapida(st_Vuelta Vueltas[],int cantVueltas);
st_Vuelta vueltaMasLenta(st_Vuelta Vueltas[],int cantVueltas);


//                                                  MAIN

int main(){

	//Etapa 1.a)
    int cantVueltas = 0;
    ingresoDeDato("Ingrese la cantidad de Vueltas a cargar: ", cantVueltas);

	st_Vuelta Vueltas[cantVueltas];
   	cargaDeVueltas(Vueltas, cantVueltas);

    cout<<endl;

	//Etapa 1.b)
	st_Vuelta vMasRapida = vueltaMasRapida(Vueltas,cantVueltas);
	cout<<"Vuelta mas rapida, vuelta Nro "<<vMasRapida.nroVuelta<<", en "<<"MM: "<<vMasRapida.tiempoVuelta/100<<" ss: "<<vMasRapida.tiempoVuelta%100 <<endl;;

	//Etapa 1.c)
	st_Vuelta vMasLenta = vueltaMasLenta(Vueltas,cantVueltas);
	cout<<"Vuelta mas lenta, vuelta Nro "<<vMasLenta.nroVuelta<<", en "<<"MM: "<<vMasLenta.tiempoVuelta/100<<" ss: "<<vMasLenta.tiempoVuelta%100 <<endl;

	//Etapa 1.d)
	float porReducTiempo = ((vMasRapida.tiempoVuelta /(float)vMasLenta.tiempoVuelta)) -1;
    cout<<"Porcentaje de reduccion de tiempo entre el peor y mejor tiempo: "<< porReducTiempo <<endl;

	return 0;
}


//                                                  Funciones

void ingresoDeDato(string mensajeAlUsuario, int &valorDetalle){
	cout<<mensajeAlUsuario;
	cin>>valorDetalle;
}

void cargaDeVueltas(st_Vuelta Vueltas[], int cantVueltas){
    int largoVuelta;
    ingresoDeDato("\nIngrese largo de Vuelta (en Km): ", largoVuelta);

    for (int i=0; i<cantVueltas; i++){
        ingresoDeDato("\nIngrese Nro.de Vuelta: ", Vueltas[i].nroVuelta);
		ingresoDeDato("Ingrese Tiempo de la vuelta (MMss): ", Vueltas[i].tiempoVuelta);
		Vueltas[i].largoVuelta = largoVuelta;
    }
}

st_Vuelta vueltaMasRapida(st_Vuelta Vueltas[],int cantVueltas){
	st_Vuelta vMasRapida = Vueltas[0];

	for(int i=1;i<cantVueltas;i++){
		 if(Vueltas[i].tiempoVuelta <= vMasRapida.tiempoVuelta){
		 vMasRapida = Vueltas[i];
		 }
	}

	return vMasRapida;
}
st_Vuelta vueltaMasLenta(st_Vuelta Vueltas[],int cantVueltas){
	st_Vuelta vMasLenta = Vueltas[0];

	for(int i=1;i<cantVueltas;i++){
		 if(Vueltas[i].tiempoVuelta >= vMasLenta.tiempoVuelta){
		 vMasLenta = Vueltas[i];
		 }
	}

	return vMasLenta;
}
