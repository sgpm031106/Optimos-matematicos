/*
Universidad Autonoma de Aguascalientes
Centro de Ciencias Básicas
Departamento de Ciencias de la Computacion
Programacion Cientifica
Profesor: Fernando Gutierrez Marfileño
	Alumnos: 
	-Pérez Moreno Sergio Gabriel
	-Nava Salazar Marcos Fernando
	-Rovelo Gonzalez Miguel Adrian
Marzo del 2023
Practica método de la regla falsa para evaluar la funcion f(x) = e^-x - ln(x)
*/


#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x)
{
	return exp(-x) - log(x);
}

void regla_falsa()
{
	double Xi, Xs, Xm, error;
	double fxi, fxs, fxm;
	int iteraciones, i=1;
	
	cout<<"Programa que calcula para la funcion: f(x) = e^-x - ln(x). "<<endl<<endl; 
	
	cout<<"Ingrese el valor del limite inferior: ";
	cin>>Xi;
	cout<<"\n";
	cout<<"Ingrese el valor del limite superior: ";
	cin>>Xs;
	cout<<"\n";
	cout<<"Teclea el valor inicial de x: ";
	cin>>Xm;
	cout<<"\n";
	cout<<"Ingrese el margen de error: ";
	cin>>error;
	cout<<"\n";
	cout<<"Ingrese el numero de iteraciones: ";
	cin>>iteraciones;
	cout<<"\n";
	
	cout<<"Total de iteraciones: "<<endl;
	do
	{
		fxi = f(Xi);
		fxs = f(Xs);
		Xm = Xs - fxs*(Xs - Xi)/(fxs - fxi);
		fxm = f(Xm);

		if((fxi * fxm) > 0)
		{
			Xi = Xm;
		}
		else
		{
			Xs = Xm;
		}
		i++;
		cout<<"Iteracion"<<i<<": "<<setprecision(9)<<Xm<<endl;
	}while(i < iteraciones && abs(fxm) > error);
	
	cout<<"\n";
	
	if(i == iteraciones)
	{
		cout<<"¡Error! Se excede el numero de iteraciones. "<<endl;
	}
	
	cout<<"El valor aproximado de la raiz dentro del margen de error es: "<<setprecision(9)<<Xm<<endl;
}

int main()
{
	int op;
	do
	{
		cout<<"---MENU---"<<endl;
		cout<<"1. Resolver por metodo de regla falsa. "<<endl;
		cout<<"2. Salir del programa. "<<endl;
		cout<<"Que desea hacer? ";
		cin>>op;
		cout<<"\n";
		switch(op)
		{
			case 1:
				regla_falsa();
				break;
				
			case 2:
				cout<<"Saliendo del programa. "<<endl;
				break;
				
			default:
				cout<<"Opcion invalida, ingrese otra respuesta. "<<endl;
				break;
		}
		system("pause");
		system("cls");
	}while(op != 2);
}
