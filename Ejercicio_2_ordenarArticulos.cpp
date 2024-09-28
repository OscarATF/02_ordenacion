#include <iostream> 
using namespace std;

struct Articulo{
	string cod;
	string desc;
	double prec;
	int cant;
};

void ordenaPos(int,Articulo[]);

int main() {
	int n;
	const int tam=50;
	Articulo Art[tam];
	cout<<"2. Se tienen los siguientes atributos de un articulo: \ncodigo, descripcion, precio, cantidad. Ordene"
		<<" un conjunto de articulos descendentemente segun el monto de inversion."
		<<"\nUse la ordenacion por intercambio directo\n"<<endl;
		
	cout<<"Ingresa la cantidad de articulos: "; cin>>n;
	cout<<"\nIngrese los siguientes datos\n "<<endl;
	for (int i=0;i<n;i++) {
		cout<<"Articulo "<<i+1<<endl;
		cout<<"codigo: "; cin>>Art[i].cod;
		cin.ignore();
		cout<<"descripcion: "; getline(cin,Art[i].desc);
		cout<<"precio: "; cin>>Art[i].prec;
		cout<<"cantidad: "; cin>>Art[i].cant;\
		cout<<endl;
	}
	ordenaPos(n-1,Art);
	cout<<"--------------------------------------------"<<endl;
	cout<<"Articulos ordenados por monto de inversion"<<endl;
	for (int i=0;i<n;i++) {
		cout<<"Articulo "<<i+1<<endl;
		cout<<"Monto de inversion: "<<Art[i].prec*Art[i].cant<<endl;
		cout<<"codigo: "<<Art[i].cod<<endl;
		cout<<"descripcion: "<<Art[i].desc<<endl;
		cout<<"precio: "<<Art[i].prec<<endl;
		cout<<"cantidad: "<<Art[i].cant<<endl;
		cout<<endl;
	}
}

void ordenaPos(int n,Articulo A[]) {
	Articulo aux;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n-i;j++) {
			if (A[j].prec*A[j].cant<A[j+1].prec*A[j+1].cant) {
				aux=A[j];
				A[j]=A[j+1];
				A[j+1]=aux;	
			}
		}
	}
}
