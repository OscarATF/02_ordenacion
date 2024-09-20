#include <iostream>
using namespace std;

void ShellSort(int[],int);
void imprimirArreglo(int[],int);

int main() {
	int n;
	cout<<"\tMETODO SHELL\n"<<endl;
	cout<<"Ingrese la capacidad del arreglo: "; cin>>n;
	int arreglo[n];
	for (int i=0;i<n;i++) {
		cout<<"Ingrese el elemento "<<i+1<<" : "; cin>>arreglo[i];
	}
	cout<<endl;
	ShellSort(arreglo,n-1);
	imprimirArreglo(arreglo,n);
}
//Metodo shell
void ShellSort(int A[],int n) {
	int k=n+1;
	while (k>1) {
		k/=2;
		int cen=1;
		while (cen==1) {
			cen=0;        
			int i=0;
			while (i+k<=n) {
				if (A[i+k]<A[i]) {
					int aux=A[i];
					A[i]=A[i+k];
					A[i+k]=aux;
					cen=1;
				}
				i++;
			}
		}
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
