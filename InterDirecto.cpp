#include <iostream>
using namespace std;

void imprimirArreglo(int[],int);
void interDirDer(int[],int);
void interDirIzq(int[],int);
void interDirCen(int[],int); 
void interDirBi(int[],int);

int main() {
	int n,op;
	cout<<"\tMETODOS DIRECTOS\n"<<endl;
	cout<<"Ingrese la capacidad del arreglo: "; cin>>n;
	int arreglo[n];
	for (int i=0;i<n;i++) {
		cout<<"Ingrese el elemento "<<i+1<<" : "; cin>>arreglo[i];
	}
	cout<<endl;
	imprimirArreglo(arreglo,n);
		cout<<"\nMetodos de Ordenacion"<<endl
			<<"1. Intercambio Directo Derecha"<<endl
			<<"2. Intercambio Directo Izquierda"<<endl
			<<"3. Intercambio Directo con Centinela"<<endl
			<<"4. Intercambio Directo Bidireccional"<<endl
			<<"5. Salir del programa"<<endl;
		cout<<"\nIngrese una opcion: "; cin>>op;
		cout<<endl;
		switch (op) {
			case 1:
				interDirDer(arreglo,n-1);
				imprimirArreglo(arreglo,n);
				break;
			case 2:
				interDirIzq(arreglo,n-1);
				imprimirArreglo(arreglo,n);
				break;
			case 3:
				interDirCen(arreglo,n-1);
				imprimirArreglo(arreglo,n);
				break;
			case 4:
				interDirBi(arreglo,n-1);
				imprimirArreglo(arreglo,n);
				break;
			case 5:
				return 0;
				break;
			default:
				cout<<"\nIngrese una opcion valida\n"<<endl;
		} 
}

//Intercambio Directo Derecha
void interDirDer(int arr[],int n) {
	int aux;
	for (int i=0;i<n-1;i++) {
		for (int j=0;j<n-i;j++) {
			if(arr[j]>arr[j+1]) {
				aux=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=aux;
			}	
		}
	}
}

//Intercambio Directo Izquierda
void interDirIzq(int arr[],int n) {
	int aux;
	for (int i=1;i<=n;i++) {
		for (int j=n;j>=i;j--) {         
			if (arr[j]<arr[j-1]) {
				aux=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=aux;
			}
		}
	}
}

//Intercambio Directo con Centinela
void interDirCen(int arr[],int n) {
	int cen=1; //Se continua con las iteraciones
	int i=0;
	int aux;
	while(i<n && cen==1) {
		cen=0; //No es necesario realizar mas iteraciones
		for (int j=0;j<n-i;j++) {
			if (arr[j]>arr[j+1]) {
				aux=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=aux;
				cen=1; 
			}
		}
		i++;
	}
}

//Intercambio Directo Bidireccional
void interDirBi(int arr[],int n) {
	int izq=1;
	int der=n;
	int k=n;
	int aux;
	while (izq<=der) {
		//primera etapa
		for (int i=der;i>=izq;i--) {
			if (arr[i-1]>arr[i]) {
				aux=arr[i-1];
				arr[i-1]=arr[i];
				arr[i]=aux;
				k=i;
			}
		}
		izq=k+1;
		//segunda etapa
		for (int i=izq;i<=der;i++) {
			if (arr[i-1]>arr[i]) {
				aux=arr[i-1];
				arr[i-1]=arr[i];
				arr[i]=aux;
				k=i;
			}
		}
		der=k-1;
	}
}
//Imprimir los elementos del arreglo
void imprimirArreglo(int arr[],int n) {
	cout<<"Elementos del arreglo: ";
	for (int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}