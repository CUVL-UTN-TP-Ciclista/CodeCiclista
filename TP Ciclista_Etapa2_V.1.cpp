/* Trabajo Practico 
   - Ciclista - 
   1er.Cuatrimestre 2021
*/

# include<iostream>
# include<math.h>
# include<stdlib.h>
# include<string.h>
using namespace std;
# define SEPARADOR ' '
# define MAX_FIL 100
# define MAX_COL 100
# define MAX_VUELTAS 5

struct st_Vueltas {
	int nroVuelta;
	int tiempoVuelta;  //MMSS
	int largoVuelta = 47;  // en Km
};

struct st_VueltasDia {
	int fechaEntrenamiento;
	st_Vueltas Vueltas;
};

void ingresoDatos(string detalle, int &valorDetalle);
void cargoLasVueltas(st_Vueltas Vueltas[], int cantVueltas);
void muestroLasVueltas(st_Vueltas Vueltas[], int cantVueltas);
void validoSegundos(int &minseg);
//void calcularVuelta(st_Vueltas Vueltas[], int cantVueltas, int &vuelta, int &tiempo, char tipoVuelta);
void calculoVelocidadMedia(st_Vueltas Vueltas[], int cantVueltas, float &velocidadMedia);
void cargoLasVueltasDia(st_VueltasDia VueltasDia[], st_Vueltas Vueltas[]);
void ordenoLasVueltasDia(st_VueltasDia VueltasDia[], st_Vueltas Vueltas[]);
void muestroLasVueltasDia(st_VueltasDia VueltasDia[], st_Vueltas Vueltas[]);
void muestroVelocidadMayorMedia(st_VueltasDia VueltasDia[], st_Vueltas Vueltas[]);
void calculoVelocidadVuelta(st_Vueltas Vueltas, float &velocidadVuelta);
void muestroInformacionVuelta(st_VueltasDia VueltasDia[], st_Vueltas Vueltas[], int vueltaInformar);

int main(){

//  int cantVueltas=0;
//	int numeroVueltaRapida=0;
//	int tiempoRapida=0;
//	int numeroVueltaLenta=0;
//	int tiempoLenta=0;
//	float velocidadMedia=0;
//	int vuelta=0;
//	int tiempo=0;
  int vueltaInformar = 0;

// Etapa 2
// 1- Se cargan todas las vueltas (pueden no estar en orden) y fecha de entrenamiento
	st_VueltasDia VueltasDia[1];
	st_Vueltas Vueltas[MAX_VUELTAS];

	cargoLasVueltasDia(VueltasDia, Vueltas);

// 2.- Listar las vueltas ordenadas
	ordenoLasVueltasDia(VueltasDia, Vueltas);
	muestroLasVueltasDia(VueltasDia, Vueltas);

// 3.- Listado de Vueltas cuya Velocidad sea mayor a la Velocidad Media
    muestroVelocidadMayorMedia(VueltasDia, Vueltas);

// 4.- Informacion completa de una vuelta
    cout<<endl;
    ingresoDatos("Ingrese la vuelta sobre la que necesita informacion (0=Fin): ",vueltaInformar);
    while (vueltaInformar !=0){
		muestroInformacionVuelta(VueltasDia, Vueltas, vueltaInformar);
		cout<<endl;
		ingresoDatos("Ingrese la vuelta sobre la que necesita informacion (0=Fin): ",vueltaInformar);
	}


	cout<< endl;
	system("pause");
	return 0;
}

void ingresoDatos(string detalle, int &valorDetalle){
	cout<<detalle;
	cin>>valorDetalle;
	return;
}

void cargoLasVueltas(st_Vueltas Vueltas[], int cantVueltas){
    for (int i=0; i<cantVueltas; i++){
        ingresoDatos("Ingrese Nro.de Vuelta: ", Vueltas[i].nroVuelta);
		ingresoDatos("Ingrese Tiempo.de Vuelta mmss: ", Vueltas[i].tiempoVuelta);
		validoSegundos(Vueltas[i].tiempoVuelta);
//		ingresoDatos("Ingrese Largo de Vuelta: ", Vueltas[i].largoVuelta);
  		Vueltas[i].largoVuelta = 20;
    }
	return;
}

void validoSegundos(int &minseg){
		while (minseg%100 > 59){
			cout<< "         Supero la cantidad de segundos valido, verifique..!!!"<<endl;
			cout<< "         los segundos deben ser entre 00 y 59"<<endl;
			ingresoDatos("Ingrese Tiempo.de Vuelta mmss: ", minseg);
		}
		return;
}

void muestroLasVueltas(st_Vueltas Vueltas[], int cantVueltas){
	for (int i=0; i<cantVueltas;i++){
		cout<<endl<<"vuelta: "<<Vueltas[i].nroVuelta;
		cout<<endl<<"tiempo: "<<Vueltas[i].tiempoVuelta<< "    Distancia: "<<Vueltas[i].largoVuelta<<endl;
	}
	return;
}
/*
void calcularVuelta(st_Vueltas Vueltas[],int cantVueltas,int &vuelta,int &tiempo,char tipoVuelta){
	vuelta=Vueltas[0].nroVuelta;
	tiempo=Vueltas[0].tiempoVuelta;
	
	for(int i=0; i<cantVueltas; i++){
		if ((tipoVuelta == 'R' &&  Vueltas[i].tiempoVuelta < tiempo) || 
		    (tipoVuelta == 'L' &&  Vueltas[i].tiempoVuelta > tiempo)){
				tiempo=Vueltas[i].tiempoVuelta;
				vuelta=Vueltas[i].nroVuelta;
		}
	}
	return;
}
*/
void calculoVelocidadMedia(st_Vueltas Vueltas[], int cantVueltas, float &velocidadMedia){
	float sumaDistancia = 0;
	int tiempoInicial = 0;
	float tiempoFinal = 0;
	for (int i=0; i<cantVueltas;i++){
		tiempoFinal += ((Vueltas[i].tiempoVuelta/100*60)+(Vueltas[i].tiempoVuelta%100)) ; 
		sumaDistancia += (Vueltas[i].largoVuelta*1000); // Distancia en Mts.
	}
	velocidadMedia=(sumaDistancia/(tiempoFinal-tiempoInicial));
	return;
}

void cargoLasVueltasDia(st_VueltasDia VueltasDia[], st_Vueltas Vueltas[]){
	cout<<endl<<"Ingrese la fecha del Entrenamiento: ";
	cin>>VueltasDia[0].fechaEntrenamiento;
	cargoLasVueltas(Vueltas, MAX_VUELTAS);
/*    for (int i=0; i<MAX_VUELTAS; i++){
        ingresoDatos("Ingrese Nro.de Vuelta: ", Vueltas[i].nroVuelta);
		ingresoDatos("Ingrese Tiempo.de Vuelta mmss: ", Vueltas[i].tiempoVuelta);
		validoSegundos(Vueltas[i].tiempoVuelta);
//		ingresoDatos("Ingrese Largo de Vuelta: ", Vueltas[i].largoVuelta);
  		Vueltas[i].largoVuelta = 20;
    }*/
	return;
}

void ordenoLasVueltasDia(st_VueltasDia VueltasDia[], st_Vueltas Vueltas[]){
	int i = 0;
	st_Vueltas auxiliar;
	bool ordenado = false;
	while (i < MAX_VUELTAS && !ordenado) {
	ordenado = true; 
	for (int j = 0; j < MAX_VUELTAS-i-1; j++) {
		if (Vueltas[j].nroVuelta >Vueltas[j+1].nroVuelta) {
		auxiliar = Vueltas[j];
		Vueltas[j]= Vueltas[j+1];
		Vueltas[j+1] = auxiliar;
		ordenado = false; 
		}
	}
	i++;
	}
	return;	
}

void muestroLasVueltasDia(st_VueltasDia VueltasDia[], st_Vueltas Vueltas[]){
	cout<<endl<<"Listado de vueltas correspondiente al: "<<VueltasDia[0].fechaEntrenamiento<<endl;
	muestroLasVueltas(Vueltas, MAX_VUELTAS);
/*	for (int i=0; i<MAX_VUELTAS;i++){
		cout<<endl<<"vuelta: "<<Vueltas[i].nroVuelta;
		cout<<endl<<"tiempo: "<<Vueltas[i].tiempoVuelta;
		cout<<endl<<"largo: "<<Vueltas[i].largoVuelta<<endl;
	}*/
	return;
}

void muestroVelocidadMayorMedia(st_VueltasDia VueltasDia[], st_Vueltas Vueltas[]){
	float velocidadMediaDia = 0;
	float velocidadVuelta = 0;
	calculoVelocidadMedia(Vueltas, MAX_VUELTAS, velocidadMediaDia);
	cout<<endl<<"Fecha del Entrenamiento: "<<VueltasDia[0].fechaEntrenamiento<<endl;
	cout<<"Velocidad Media: "<< velocidadMediaDia << " m/s. "<< endl;
	cout<<"    Vueltas con velocidad superior a la Media"<<endl;
	for (int i=0; i<MAX_VUELTAS;i++){
		calculoVelocidadVuelta(Vueltas[i], velocidadVuelta);
		if (velocidadVuelta > velocidadMediaDia){
			cout<<endl<<"Vuelta: "<<Vueltas[i].nroVuelta;
			cout<<"       Velocidad: "<<velocidadVuelta<< " m/s. ";
		}
	}
	cout<<endl;
	return;
}

void calculoVelocidadVuelta(st_Vueltas Vueltas, float &velocidadVuelta){
	float espacio = 0;
	float tiemposs = 0;
	espacio = Vueltas.largoVuelta*1000;
	tiemposs = (Vueltas.tiempoVuelta/100*60+Vueltas.tiempoVuelta%100);
	velocidadVuelta = espacio /tiemposs;
	return;
}

void muestroInformacionVuelta(st_VueltasDia VueltasDia[], st_Vueltas Vueltas[], int vueltaInformar){
    cout<<"Vuelta numero: "<<vueltaInformar<<endl;
    cout<<"       Tiempo: "<<Vueltas[vueltaInformar-1].tiempoVuelta/100<< " min. "
                           <<Vueltas[vueltaInformar-1].tiempoVuelta%100<< " seg. "<<endl;
    cout<<"        Fecha: "<<VueltasDia[0].fechaEntrenamiento<<endl;
    float velocidadVuelta = 0;
    calculoVelocidadVuelta(Vueltas[vueltaInformar-1], velocidadVuelta);
    cout<<"    Velocidad: "<<velocidadVuelta<< " m/s. "<<endl;
    return;
}

