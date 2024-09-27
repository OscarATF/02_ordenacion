#include <iostream>
using namespace std;

struct monomio{
	float exp;
	float coef;
};

void ordenaPos(int,monomio[]);

int main() {
	
	int n;
	const int tam=50;
	monomio ter[tam];
	cout<<"1. Ordenar polinomio segun el grado de sus terminos"<<endl;
	cout<<"Ingrese la cantidad de terminos del polinomio: "; cin>>n;
	
	for (int i=0;i<n;i++) {
		cout<<endl;
		cout<<"Ingrese el coeficiente "<<i+1<<" : "; cin>>ter[i].coef;
		cout<<"Ingrese el exponente "<<i+1<<" : "; cin>>ter[i].exp;
	}
	
	ordenaPos(n,ter);
	
	cout<<endl;
	
	for (int i=0;i<n;i++) {
		cout<<ter[i].coef<<"x^"<<ter[i].exp;
		if (i!=n-1) {
			cout<<" + ";
		}
	}
}

void ordenaPos(int n,monomio t[]) {
	monomio aux;
	for (int i=1;i<n;i++) {
		for (int j=n-1;j>=i;j--) {
			if (t[j].exp<t[j-1].exp) {
				aux=t[j];
				t[j]=t[j-1];
				t[j-1]=aux;
			}
		}
	}
}
