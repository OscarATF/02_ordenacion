#include <iostream>
using namespace std;

void SeleccionDir(int[],int);
void imprimirArreglo(int[],int);

int main() {
	int n;
	cout<<"\tSELECCION DIRECTA\n"<<endl;
	cout<<"Ingrese la capacidad del arreglo: "; cin>>n;
	int arreglo[n];
	for (int i=0;i<n;i++) {
		cout<<"Ingrese el elemento "<<i+1<<" : "; cin>>arreglo[i];
	}
	cout<<endl;
	SeleccionDir(arreglo,n);
	imprimirArreglo(arreglo,n);
}
//Metodo de seleccion directa
void SeleccionDir(int A[],int n) {
	for (int i=0;i<n-1;i++) {
		int menor=A[i];
		int k=i;
		for (int j=i+1;j<n;j++) {
			if (A[j]<menor) {
				menor=A[j];
				k=j;
			}
		}
		A[k]=A[i];
		A[i]=menor;
	}
}
//imprimir arreglo
void imprimirArreglo(int arr[],int n) {
	cout<<"Elementos ordenados: ";
	for (int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
