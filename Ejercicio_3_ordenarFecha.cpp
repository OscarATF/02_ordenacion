#include <iostream> 
using namespace std;

struct Fecha{
	int dia;
	int mes;
	int anio;
};

struct Personal{
	string dni;
	string nombres;
	Fecha nacim;
};

void ordenaPos(int,Personal[]);
bool comparar(Personal,Personal);

int main() {
	const int tam=100;
	Personal per[tam];
	int n;
	cout<<"3. Ordenar personal por fecha de nacimiento"<<endl;
	cout<<"Ingrese la cantidad de personal: "; cin>>n;
	
	for (int i=0;i<n;i++) {
		cout<<endl;
		cin.ignore();
		cout<<"Ingrese nombre completo: "; getline(cin,per[i].nombres);
		cout<<"Ingrese DNI: "; cin>>per[i].dni;
		cout<<"Ingrese Fecha de nacimiento\nDia: "; cin>>per[i].nacim.dia;
		cout<<"Mes: "; cin>>per[i].nacim.mes;
		cout<<"Anio: "; cin>>per[i].nacim.anio;
	}
	
	ordenaPos(n,per);
	cout<<"------------------------------------"<<endl;
	cout<<"Personal ordenado por fecha de nacimiento"<<endl;
	for (int i=0;i<n;i++) {
		cout<<endl;
		cout<<"nombre completo: "<<per[i].nombres<<endl;
		cout<<"DNI: "<<per[i].dni<<endl;
		cout<<"Fecha de nacimiento\nDia: "<<per[i].nacim.dia<<endl;
		cout<<"Mes: "<<per[i].nacim.mes<<endl;
		cout<<"Anio: "<<per[i].nacim.anio<<endl;
	}
}

void ordenaPos(int n,Personal p[]) {
	Personal aux;
	int k;
	for (int i=0;i<n;i++) {
		aux=p[i];
		k=i-1;
		while (k>=0 && comparar(aux,p[k]))  {
			p[k+1]=p[k];
			k--;
		}
		p[k+1]=aux;
	}
}

bool comparar(Personal aux,Personal p) {
	if (aux.nacim.anio<p.nacim.anio ||
    	(aux.nacim.anio==p.nacim.anio && aux.nacim.mes<p.nacim.mes) ||
        (aux.nacim.anio==p.nacim.anio && aux.nacim.mes==p.nacim.mes && aux.nacim.dia<p.nacim.dia)){
        	return true;
		} else {
			return false;
		}
}