#include <iostream>
using namespace std;

void imprimirArreglo(int[],int);
void interDirDer(int[],int);
void interDirIzq(int[],int);

int main() {
	int n,op;
	cout<<"Ingrese la capacidad del arreglo: "; cin>>n;
	int arreglo[n];
	for (int i=0;i<n;i++) {
		cout<<"Ingrese el elemento "<<i+1<<" : "; cin>>arreglo[i];
	}
	imprimirArreglo(arreglo,n);
	do {
		cout<<"\nMetodos de Ordenacion"<<endl
			<<"1. Intercambio Directo Derecha"<<endl
			<<"2. Intercambio Directo Izquierda"<<endl
			<<"3. Salir del programa"<<endl;
		cout<<"Ingrese una opcion: "; cin>>op;
		switch (op) {
			case 1:
				interDirDer(arreglo,n-1);
				imprimirArreglo(arreglo,n);
				return 0;
				break;
			case 2:
				interDirIzq(arreglo,n-1);
				imprimirArreglo(arreglo,n);
				return 0;
		}
	} while (op!=3);
	cout<<endl;
}

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
	
void imprimirArreglo(int arr[],int n) {
	for (int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}