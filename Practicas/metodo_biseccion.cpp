/*
Universidad Autónoma de Aguascalientes
Centro de Ciencias Básicas
Departamento de cienicas de la computacion
Ingenieria en Computacion Inteligente
- Pérez Moreno Sergio Gabriel
Profesor: Fernando Gutiérrez Marfileño
Mayo del 2022
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>

using namespace std;

//Funcion de tipo double que retorna la evaluacion de la funcion con el valor que tomará cuando se mande a llamar en la funcion principal.
double f(double x)
{
	return pow(x,3) - 1.412*pow(x,2) + 0.098;
}

int main()
{
	setlocale(LC_ALL, "spanish");
	//Declaración de variables
	double a, b, c, fc, error, tolerancia;
	int cont = 0;
	
	cout<<"El programa encuentra la raíz de la función f(x) = x^3 - 1.412*x^2 + 0.098 en el intervalo [0, 1]\ncon una tolerancia de error de 0.000001.\n"<<endl;
	
	cout<<"Digite el valor del intervalo inferior: ";
	cin>>a;
	cout<<"\n";
	
	cout<<"Digite el valor del intervalo superior: ";
	cin>>b;
	cout<<"\n";
	
	cout<<"Digite la tolerancia de error: ";
	cin>>error;
	cout<<"\n";
	
	//Dentro de un ciclo while se lleva a cabo el proceso
	while(true)
	{
		//c es el valor de la formula para el punto medio entre los dos valores del intervalo.
		c = (a+b)/2;
		
		//fc es el valor de la funcion declarada previamente que se evalua en el punto medio (c).
		fc = f(c);
		
		//Si el valor absoluto de la funcion evaluada en c es menor que la tolerancia de error, da el resultado.
		if(abs(fc) < error)
		{
			cout<<"El valor de la raíz es: "<<setprecision(9)<<c<<endl<<endl;
			break; 
		}
		/*Si la funcion evaluada en el intervalo inferior multiplicada por la funcion evaluada en el punto medio da un valor negativo,
		el valor del intervalo superior toma el lugar del punto medio*/
		else if(f(a)*fc < 0)
		{
			b = c;
		}
		//Si es un valor positivo, el intervalo inferior toma el valor del punto medio.
		else
		{
			a = c;
		}
		cont++;
	}
	cout<<"Se hicieron un total de "<<cont<<" iteraciones. "<<endl;
	return 0;
}
