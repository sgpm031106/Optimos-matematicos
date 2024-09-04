/*
Universidad Autonoma de Aguascalientes
Centro de Ciencias Básicas
Ingenieria en Computacion Inteligente

Integrantes:
Pérez Moreno Sergio Gabriel
Rovelo Gonzalez Miguel Adrian
Nava Salazar Marcos Fernando

Profesor:
Luis Fernando Gutierrez Marfileño

Programa:
El codigo funciona evaluando por el metodo grafico una funcion de tercer grado. 
Los datos se ingresan por el usuario y el programa suelta los puntos de la grafica y la raiz de cruce.
*/
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

void funcion();

double raiz;
int inferior, superior, error;
bool siraiz;

int main()
{    
	int op;
    do
    { 
	    cout<<"---Menu---"<<endl;
	    cout<<"1. Resolver por  metodo grafico. "<<endl;
	    cout<<"2. Salir. "<<endl;
	    cout<<"Que desea hacer: ";
		cin>>op;
		switch(op)
		{
			case 1:
				funcion();
				break;
			
			case 2:
				cout<<"Saliendo del programa. "<<endl;
				cout<<"\n";
				break;
				
			default: 
				cout<<"Opcion invalida. "<<endl;
				break;
		}
		system("pause");
		system("cls");
	}while(op != 2);
	return 0;
}

void funcion()
{
	cout<<"Resolver para x^3 + 2x^2 + 3x - 5. "<<endl<<endl;
   	cout<<"Ingresa el valor del intervalo inferior: ";
    cin>>inferior;
    cout<<"\n";

    cout<<"Ingresa el valor del intervalo superior: ";
    cin>>superior;
    cout<<"\n";
    
    cout<<"Digite tolerancia de error: ";
    cin>>error;
    cout<<"\n";
    
    double f_x[superior-inferior];

    int indice = 0;
    int absoluto = superior - inferior;

	cout<<"Valores de f(x): "<<endl;
    for(int i=inferior; i<=superior; i+=error)
    {
        f_x[indice] = pow(i,3) + 2*pow(i,2) + 3*i - 5;
        cout<<"f("<<inferior+indice<<") = "<<f_x[indice]<<endl;	
        indice++;
    }
    cout<<"\n";
    
    float valor_de_x[superior-inferior];
    
    
    for(int i=0; i<=absoluto; i++)
    {
    	valor_de_x[i] = inferior + i;
    	cout<<"Valor de x: "<<valor_de_x[i]<<endl;;
	}
	cout<<"\n";
	
    for(int i=0; i<(absoluto); i++)
    {
    	if(f_x[i]*f_x[i+1] < 0)
    	{
    		raiz = (valor_de_x[i] + valor_de_x[i+1]) / 2;
    		cout<<"La raiz que esta entre "<<inferior+i+1<<" y "<<inferior+i<<" es "<<raiz<<endl;
		}
	}
	cout<<"\n";
}
