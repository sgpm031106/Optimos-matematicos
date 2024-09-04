/*
Universidad Autonoma de Aguascalientes
Centro de ciencias basicas
Departamento de ciencias de la computacion
Ingenieria en computacion inteligente
Programacion cientifica
Alumnos:
	- Perez Moreno Sergio Gabriel
	- Rovelo Gonzalez Miguel Adrian
	- Nava Salazar Marcos Fernando
Profesor: Luis Fernando Gutierrez Marfileño
MAYO DEL 2022

*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double EPSILON = 1e-10;  // Tolerancia para considerar un número como cero

double Gauss()
{
	cout<<"El programa resuelve un sistema de ecuaciones lineales por medio del metodo de Gauss. "<<endl;
	cout<<"Matriz de ejemplo solicitada en la practica: "<<endl<<endl;
	cout<<"-x1 + x2 - x3 = -1"<<endl;
	cout<<"4x1 - 2x2 + 2x3 =  0"<<endl;
	cout<<"-3x1 - 2x2   = -4"<<endl<<endl;
    int n;
    cout<<"Cuantos sistemas se van a resolver? ";
    cin>>n;
    
    double **a = new double *[n];
    
    for (int i=0; i<n; i++) 
	{
        a[i] = new double[n+1];
    }
    
    cout << "Ingrese los coeficientes de la matriz aumentada:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n+1; j++) {
        	cout<<"-> ";
            cin >> a[i][j];
        }
    }
    cout<<"\n";

    // Eliminación gaussiana
    for (int k = 0; k < n; k++) {
        // Pivoteo parcial
        int p = k;
        for (int i = k+1; i < n; i++) {
            if (abs(a[i][k]) > abs(a[p][k])) {
                p = i;
            }
        }
        if (abs(a[p][k]) < EPSILON) {
            cout << "La matriz es singular" << endl;
            return 1;
        }
        if (p != k) {
            for (int j = k; j < n+1; j++) {
                double temp = a[k][j];
                a[k][j] = a[p][j];
                a[p][j] = temp;
            }
        }
        // Eliminación hacia adelante
        for (int i = k+1; i < n; i++) {
            double f = a[i][k] / a[k][k];
            for (int j = k+1; j < n+1; j++) {
                a[i][j] -= f * a[k][j];
            }
            a[i][k] = 0.0;
        }
    }

    // Sustitución hacia atrás
    double x[n];
    for (int i = n-1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i+1; j < n; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n] - sum) / a[i][i];
    }

    // Mostrar solución
    cout << "Las soluciones del sistema son:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i+1 << " = " << x[i] << endl;
    }
    
    //liberar memoria
    for (int i = 0; i < n; i++) {
    	delete[] a[i];
	}
	delete[] a;
}


int main() 
{
	int op;
	do
	{
		cout<<"---MENU---"<<endl;
		cout<<"1. Metodo de Gauss. "<<endl;
		cout<<"2. Salir del programa. "<<endl;
		cout<<"Que desea hacer? ";
		cin>>op;
		switch(op)
		{
			case 1:
				Gauss();
				cout<<"\n";
				break;
				
			case 2:
				cout<<"Saliendo del programa. "<<endl;
				cout<<"\n";
				break;
				
			default:
				cout<<"Opcion invalida, ingrese otra respuesta:. "<<endl;
				cout<<"\n";
				break;
		}
		system("pause");
		system("cls");
	}while(op != 2);
	
    return 0;
}

