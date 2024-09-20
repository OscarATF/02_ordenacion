#include <iostream>
using namespace std;

void imprimirArreglo(int[],int);
void InsercionDir(int[],int);
void InsercionBin(int[],int);

int main() {
	int n,op;
	cout<<"\tINSERCION DIRECTA Y BINARIA\n"<<endl;
	cout<<"Ingrese la capacidad del arreglo: "; cin>>n;
	int arreglo[n];
	for (int i=0;i<n;i++) {
		cout<<"Ingrese el elemento "<<i+1<<" : "; cin>>arreglo[i];
	}
	cout<<endl;
	imprimirArreglo(arreglo,n);
		cout<<"\nMetodos de Ordenacion"<<endl
			<<"1. Insercion Directa"<<endl
			<<"2. Insercion Binaria"<<endl
			<<"3. Salir del programa"<<endl;
		cout<<"\nIngrese una opcion: "; cin>>op;
		cout<<endl;
		switch (op) {
			case 1:
				InsercionDir(arreglo,n);
				imprimirArreglo(arreglo,n);
				break;
			case 2:
				InsercionBin(arreglo,n);
				imprimirArreglo(arreglo,n);
				break;
			case 3:
				return 0;
				break;
			default:
				cout<<"\nIngrese una opcion valida\n"<<endl;
		} 
}

void InsercionDir(int A[],int n) {
	for (int i=1;i<n;i++) {
	int aux=A[i];
	int k=i-1;
		while (k>=0 && aux<A[k]) {
			A[k+1]=A[k];
			k--;
		}
		A[k+1]=aux;
	}
}

void InsercionBin(int A[],int n) {
	for (int i=1;i<n;i++) {
		int aux=A[i];
		int izq=0;
		int der=i-1;
		while (izq<=der) {
			int m=(izq+der)/2;
			if (aux<A[m]) {
				der=m-1;
			} else {
				izq=m+1;
			}
		}
		int j=i-1;
		while (j>=izq) {
			A[j+1]=A[j];
			j--;
		}
		A[izq]=aux; //insercion
	}
}

void imprimirArreglo(int arr[],int n) {
	cout<<"Elementos del arreglo: ";
	for (int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
