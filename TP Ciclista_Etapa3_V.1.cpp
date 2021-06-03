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
# define MAX_VUELTAS 20
# define AWO 2021

struct st_Vueltas {
	int nroVuelta;
	int tiempoVuelta;  //MMSS
	int largoVuelta;  // en Km
};

struct st_VueltasDia {
	st_Vueltas Vueltas[MAX_VUELTAS] ;
};

void ingresoDatos(string detalle, int &valorDetalle);
void cargoLasVueltas(st_Vueltas Vueltas[]);
void validoSegundos(int &minseg);
void validoFecha(int mesAwoEntrenamiento, char tipo);
void obtengoDiasMes(int mes, int awo, int& dias);
bool esBisiesto(int awo);
void cargoLasVueltasMes(st_VueltasDia VueltasDia[], st_Vueltas Vueltas[], int diasEntrenamiento);
void muestroLasVueltasMes(st_VueltasDia VueltasDia[], st_Vueltas Vueltas[], int diasEntrenamiento);
void calcularVueltaMes(st_VueltasDia VueltasDia[], st_Vueltas Vueltas[], char tipoVuelta, int diasEntrenamiento,
                       int &dia, int &vuelta);
void calculoVelocidadVueltaMes(int tiempoVuelta, int largo, float &velocidadVuelta);

int main(){

	int mesEntrenamiento = 0;
	int awoEntrenamiento = 0;
	int diasEntrenamiento = 0;
	int vuelta=0;
	int tiempo=0;
	int diaEnt=0;
	int largo=0;
	int numeroVueltaRapida=0;
	int tiempoRapida=0;
	int numeroVueltaLenta=0;
	int tiempoLenta=0;
	float velocidadVuelta = 0;

// Etapa 3
// Registrar los entrenamientos realizados en todo 1 mes
	ingresoDatos("Ingrese el Mes de carga del Entrenamiento: ", mesEntrenamiento);
    validoFecha(mesEntrenamiento, 'M');
	ingresoDatos("Ingrese el Año de carga del Entrenamiento: ", awoEntrenamiento);
    validoFecha(awoEntrenamiento, 'A');
	obtengoDiasMes(mesEntrenamiento, awoEntrenamiento, diasEntrenamiento);

	st_VueltasDia VueltasDia[diasEntrenamiento];
	st_Vueltas Vueltas[MAX_VUELTAS];

	cout<<endl<<"Ingreso de Datos --- Mes Entrenamiento: "<<mesEntrenamiento<<"/"<<awoEntrenamiento<<endl;
	cargoLasVueltasMes(VueltasDia, Vueltas, diasEntrenamiento);
	cout<<endl<<"Detalle de Vueltas realizadas --- Mes Entrenamiento: "<<mesEntrenamiento<<"/"<<awoEntrenamiento<<endl;
	muestroLasVueltasMes(VueltasDia, Vueltas, diasEntrenamiento);


// A.- Cúal fue el entrenamiento con la vuelta más rápida y su tiempo. 
//     Debe mostrar también los datos de la vuelta correspondiente
	calcularVueltaMes(VueltasDia, Vueltas, 'R', diasEntrenamiento, diaEnt, vuelta);
	numeroVueltaRapida = VueltasDia[diaEnt].Vueltas[vuelta].nroVuelta;
	tiempoRapida = VueltasDia[diaEnt].Vueltas[vuelta].tiempoVuelta;
	largo = VueltasDia[diaEnt].Vueltas[vuelta].largoVuelta;
	cout<<endl;
	cout<< "La vuelta mas rapida fue realizada el dia "<< diaEnt+1 << "/"<<mesEntrenamiento<<"/"<<awoEntrenamiento<<endl;
	cout<< "Es la numero "<< numeroVueltaRapida << " con un tiempo de ";
	cout<< tiempoRapida/100 << " min. "<< tiempoRapida%100 << " seg. "<< endl;
    calculoVelocidadVueltaMes(tiempoRapida, largo, velocidadVuelta);
    cout<<"y a una Velocidad de: "<<velocidadVuelta<< " m/s. "<<endl;

// B.- Cúal fue el entrenamiento con la vuelta más lenta y su tiempo.
	calcularVueltaMes(VueltasDia, Vueltas, 'L', diasEntrenamiento, diaEnt, vuelta);
	numeroVueltaLenta = VueltasDia[diaEnt].Vueltas[vuelta].nroVuelta;
	tiempoLenta = VueltasDia[diaEnt].Vueltas[vuelta].tiempoVuelta;
	largo = VueltasDia[diaEnt].Vueltas[vuelta].largoVuelta;
	cout<<endl;
	cout<< "La vuelta mas lenta fue realizada el dia "<< diaEnt+1 << "/"<<mesEntrenamiento<<"/"<<awoEntrenamiento<<endl;
	cout<< "Es la numero "<< numeroVueltaLenta << " con un tiempo de ";
	cout<< tiempoLenta/100 << " min. "<< tiempoLenta%100 << " seg. "<< endl;
    calculoVelocidadVueltaMes(tiempoLenta, largo, velocidadVuelta);
    cout<<"y a una Velocidad de: "<<velocidadVuelta<< " m/s. "<<endl;


	cout<< endl;
	system("pause");
	return 0;
}

void ingresoDatos(string detalle, int &valorDetalle){
	cout<<detalle;
	cin>>valorDetalle;
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

void validoFecha(int dato, char tipo){
	if (tipo == 'D'){
	}
	if (tipo == 'M' && dato < 1 && dato > 12){
		cout<<"Mes ingresado es erroneo... Favor reingrese"<<endl;
		ingresoDatos("Ingrese el Mes de carga del Entrenamiento: ", dato);
	}
	if (tipo == 'A' && dato > AWO){
		cout<<"Año ingresado es mayor al actual... Favor reingrese"<<endl;
		ingresoDatos("Ingrese el Año de carga del Entrenamiento: ", dato);
	}
}

void obtengoDiasMes(int mes, int awo, int &dias){
	if (mes == 1 || mes == 3 || mes == 5 || mes == 8 || mes == 10 || mes == 12){
		dias = 31;
	}
	else {
		dias = 30;
	}
	if (mes==2){
		if (esBisiesto(awo)){
		dias = 29;
		}
		else {
			dias = 28;
		}
	}
}

bool esBisiesto(int awo){
    if ((awo%4 == 0) || (awo%400 == 0) && (awo%100 != 0)){
		return true;
	}
    return false;
}

void cargoLasVueltasMes(st_VueltasDia VueltasDia[], st_Vueltas Vueltas[], int diasEntrenamiento){
	for (int i = 0; i < diasEntrenamiento; i++){
		cout<<endl<<"Entrenamiento de dia "<< i+1<<endl;
		for (int j = 0; j < MAX_VUELTAS ; j++) {
			ingresoDatos("Ingrese Nro.de Vuelta: ", VueltasDia[i].Vueltas[j].nroVuelta);
			ingresoDatos("Ingrese Tiempo de Vuelta mmss: ", VueltasDia[i].Vueltas[j].tiempoVuelta);
			validoSegundos(VueltasDia[i].Vueltas[j].tiempoVuelta);
//			ingresoDatos("Ingrese Largo de Vuelta: ", Vueltas[i].largoVuelta);
  			VueltasDia[i].Vueltas[j].largoVuelta = 20;
    	}
	}
	return;
}

void muestroLasVueltasMes(st_VueltasDia VueltasDia[], st_Vueltas Vueltas[], int diasEntrenamiento){
	for (int i = 0; i < diasEntrenamiento; i++){
		cout<<endl<<"Entrenamiento de dia "<< i+1<<endl;
		for (int j = 0; j < MAX_VUELTAS ; j++) {
			cout<<"Nro.de Vuelta: "<<VueltasDia[i].Vueltas[j].nroVuelta<<endl;
    		cout<<"       Tiempo: "<<VueltasDia[i].Vueltas[j].tiempoVuelta/100<< " min. "
                         		   <<VueltasDia[i].Vueltas[j].tiempoVuelta%100<< " seg. "<<endl;
			cout<<"    Distancia: "<<VueltasDia[i].Vueltas[j].largoVuelta<<endl;
    	}
	}
	return;
}

void calcularVueltaMes(st_VueltasDia VueltasDia[], st_Vueltas Vueltas[], char tipoVuelta, int diasEntrenamiento,
                       int &dia, int &vuelta){
	cout<<endl<<endl<<endl;
	int diaTiempo = 0;
	dia = 0;
	vuelta = 0;
	diaTiempo = VueltasDia[0].Vueltas[0].tiempoVuelta;
	for (int i = 0; i < diasEntrenamiento; i++){
		for (int j = 0; j < MAX_VUELTAS; j++) {
			if ((tipoVuelta == 'R' &&  VueltasDia[i].Vueltas[j].tiempoVuelta < diaTiempo) || 
			    (tipoVuelta == 'L' &&  VueltasDia[i].Vueltas[j].tiempoVuelta > diaTiempo)){
				diaTiempo=VueltasDia[i].Vueltas[j].tiempoVuelta;
				vuelta=j;
				dia=i;
			}
		}
	}
	return;
}

void calculoVelocidadVueltaMes(int tiempoVuelta, int largo, float &velocidadVuelta){
	float espacio = 0;
	float tiemposs = 0;
	espacio = largo*1000;
	tiemposs = (tiempoVuelta/100*60+tiempoVuelta%100);
	velocidadVuelta = espacio /tiemposs;
	return;
}
