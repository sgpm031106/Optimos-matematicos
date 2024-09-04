/*
    Universidad Autonoma de Aguascalientes
    Centro de Ciencias Basicas
    Departamente de Ciencias de la Computacion
    Programacion Cientifica
    - Perez Moreno Sergio Gabriel
    - Nava Salazar Marcos Fernando
    - Rovelo Gonzales Miguel Adrian
    Profesor Fernando Gutierrez Marfileño
    El programa calcula el punto fijo de una expresion exponencial, mediante datos ingresados por el usuario
*/


#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    /*Para resolver  e^-x - x
        tolerancia de 0.0001
        valor de x0 = 0
    */

   //Declaracion de variables
    double aprox, error, x;
    int cont;

    //Datos de entrada: aproximacion (x = 0) y tolerancia de error (0.0001)
    cout<<"Ingrese el valor de la aproximacion: ";
    cin>>aprox;
    cout<<"\n";

    cout<<"Ingrese valor de la tolerancia: ";
    cin>>error;
    cout<<"\n";

    //Formula con x despejada
    x = exp(-aprox);

    //Bucle para iterar la resta de la formula hasta que el valor absoluto de la aproximacion - x sea menor que la tolerancia de error
    while (abs(aprox-x) > error)
    {
        aprox = x;
        x = exp(-aprox);
        cont++;
    }

    cout<<"El valor es: "<<fixed<<setprecision(9)<<x<<endl;
    cout<<"Con un total de "<<cont<<" iteraciones. "<<endl;

    return 0;
}