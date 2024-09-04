/*
Universidad Autonoma de Aguascalientes
Centro de Ciencias Basicas
Ingenieria en Computacion Inteligente
Departamento de Ciencias de la Computacion
Programacion Cientifica
Junio del 2023
Proyecto Final
*/

/*
El proyecto consiste en implementar los métodos de integración numérica de Simpson 1/3 y Simpson 3/8 
para obtener el área bajo la curva de la función: x * exp(2x) en los intervalos [0, 3] 
*/

//Librerias
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Funcion que retorna la integral principal que se va a evaluar.
double f(double x)
{
	return x * exp(2*x);
}

//Funcion que retorna la cuarta derivada de la funcion para obtener el error.
double f4(double x)
{
	return (16*x + 32)*exp(2*x);
}

//Funcion que realiza la regla de integracion de Simpson 3/8.
void simpson38()
{
	double a = 0, b = 3;
	int n = 6;
	
	
	double h = (b-a)/n;
	double suma = f(a) + f(b);
	double z = (b-a)/2;
	double f4z = f4(z);
	

	double x = a+h;
	
	for(int i=1; i<n; i++)
	{
		if(i%3 == 0)
		{
			suma = suma + 2*f(x);
		}
		else
		{
			suma = suma + 3*f(x);
		}
		x += h;
	}
	double resultado = (3*h/8.0) * suma;
	double error = (-3.0/80.0)*pow(h,5)*f4z;
	
	cout<<"El resultado de la integracion es: "<<resultado<<endl<<endl;
	cout<<"Con un error de: "<<error<<endl<<endl;
}

//Funcion que realiza la regla de integracion de Simpson 1/3.
void simpson13()
{
	double a = 0, b = 3;
	int n = 6;
	
	double h = (b-a)/n;
	double z = (a+b)/2.0;
	double f4z = f4(z);
	double suma = f(a) + f(b);
	
	for(int i=1; i<n; i++)
	{
		double x = a+i*h;
		if(i%2 == 0)
		{
			suma = suma + 2*f(x);
		}
		else
		{
			suma = suma + 4*f(x);
		}
	}
	double resultado = (h/3.0) * suma;
	double error = (-1.0/180.0)*pow(h,4)*f4z;
	
	cout<<"El resultado de la integracion es: "<<resultado<<endl<<endl;
	cout<<"Con un error de: "<<error<<endl<<endl;
}

//Funcion principal.
int main()
{
	int op;
	do
	{
		cout<<"El proyecto consiste en implementar los metodos de integracion numerica de \nSimpson 1/3 y Simpson 3/8 para obtener el area bajo la curva de la funcion: x * exp(2x)\nen el intervalo [0, 3]. "<<endl<<endl;
	
		cout<<"La funcion viene declarada en una funcion que retorna los valores evaluados,\nel limite inferior es 0, el superior 3\nel margen de error sera de 0.0001 y el maximo de iteraciones de 100. "<<endl<<endl;
		
		cout<<"---MENU---"<<endl;
		cout<<"1- Regla de Simpson 1/3. "<<endl;
		cout<<"2- Regla de Simpson 3/8. "<<endl;
		cout<<"3- Salir del programa. "<<endl;
		cout<<"->> Que desea realizar? ";
		cin>>op;
		cout<<"\n";
		switch(op)
		{
			case 1:
				simpson13();
				break;
				
			case 2:
				simpson38();
				break;
				
			case 3:
				cout<<"Saliendo del programa. "<<endl;
				cout<<"\n";
				break;
				
			default:
				cout<<"Opcion invalida, ingrese otra respuesta. "<<endl;
				cout<<"\n";
				break;
		}
		system("pause");
		system("cls");
	}while(op != 3);
	return 0;
}

/*
---CONCLUSIONES---
El programa funciona de manera efectiva y rápida ya que los valores vienen definidos
a la hora de declarar las vairables asi que el proceso es directo a lo que piden las 
instrucciones de la practica.
Viendo los resultados dados podemos observar que el metodo de integreaciond de Simpson 1/3
tiene un margen de error menor al de Simpson 3/8.
*/
