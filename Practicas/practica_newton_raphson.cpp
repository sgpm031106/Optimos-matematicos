/*
Universidad Aut�noma de Aguasalientes
Centro de Ciencias B�sicas
Departamento de Ciencias de la Computaci�n
Materia: Programacion Cientifica
Profesor: Fernando Gutierrez Marfile�o
Alumnos:
	-P�rez Moreno Sergio Gabriel
	-Nava Salazar Marcos Fernando
	-Rovelo Gonzalez Miguel Adrian
	
Marzo del 2023

El programa evalua la funci�n f(x) = cos(x) - x con el m�todo de Newton Raphson
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>
#define pi 3.14159265

using namespace std;

double f(double x)
{
	return cos(x) - x;
}

double f_derivada(double x)
{
	return -sin(x) - 1;
}

void Newton_Raphson()
{
	double x0, tolerancia, x, x_anterior, error, x2;
	int max_iteraciones, iteraciones = 0;
	
	cout<<"Ingrese valor inicial en grados: ";
	cin>>x0;
	cout<<"\n";
	
	cout<<"Ingrese la tolerancia de error: ";
	cin>>tolerancia;
	cout<<"\n";
	
	cout<<"Ingrese el n�mero m�ximo de iteraciones: ";
	cin>>max_iteraciones;
	cout<<"\n";
	
	x0 = x0*(pi/180);
	
	do
	{
		x_anterior = x0;
		x = x0 - f(x0) / f_derivada(x0);
		error = abs((x - x_anterior)/x);
		iteraciones++;
		x0 = x;
		x2 = x * (180/pi);
	}while(error > tolerancia && iteraciones < max_iteraciones);
	
	if(iteraciones == max_iteraciones)
	{
		cout<<"La cantidad de iteraciones alcanz� su m�ximo. "<<endl;
	}
	else
	{
		cout<<"Ra�z de la funcion en radianes: "<<setprecision(9)<<x<<endl;
		cout<<"Ra�z de la funcion en grados: "<<setprecision(9)<<x2<<endl;
		cout<<"Se hicieron un total de "<<iteraciones<<" iteraciones. "<<endl;
	}
}

int main()
{
	setlocale(LC_ALL, "spanish");
	int op;
	do
	{
		cout<<"---MEN�---"<<endl;
		cout<<"1. Resolver por el m�todo de Newton Raphson. "<<endl;
		cout<<"2. Salir del programa. "<<endl;
		cout<<"�Qu� desea hacer? ";
		cin>>op;
		cout<<"\n";
		switch(op)
		{
			case 1:
				Newton_Raphson();
				break;
				
			case 2:
				cout<<"Saliendo del programa... "<<endl;
				break;
				
			default: 
				cout<<"Opci�n inv�lida, ingrese otra respuesta. "<<endl;
				break;
		}
		system("pause");
		system("cls");
	}while(op != 2);
}
