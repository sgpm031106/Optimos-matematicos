/*
Universidad Autónoma de Aguascalientes
Centro de Ciencias Básicas
Ingeniería en Computacion Inteligente
    -Perez Moreno Sergio Gabriel
    -Nava Salazar Marcos Fernando
    -Rovelo Gonzales Miguel Adrian

    Tan(x) en terminos de series de Taylor

    Febrero del 2022
*/
#include <iostream>
#include <math.h>
#include <cmath>
#include <conio.h>

using namespace std;

//Funciones para calcular las series de taylor de seno y coseno
double seno(double x, int n);
double coseno(double x, int n);

//Tan(x) = Sen(x)/Cos(x)

//ENTRE MAS GRANDE EL ANGULO, MAS TERMINOS NECESITA PARA SER MAS EXACTO

int main()
{
    //Variable para resultado de tangente variables que servirán como parametros
    double angulo, tangente;
    int cant_terminos;

    cout<<"Ingrese el angulo: ";
    cin>>angulo;
    cout<<"\n";

    cout<<"Ingrese la cantidad de terminos: ";
    cin>>cant_terminos;

    //Formula para obtener Tan(x)
    tangente = seno(angulo, cant_terminos) / coseno(angulo, cant_terminos);
    cout<<"La tangente de "<<angulo<<" es: "<<tangente<<endl;

    return 0;
}

//Funcion Seno
double seno(double x, int n)
{
    int exponente = 1;
    float y;
    double resultado = 0, factorial;

    //Formula para convertir los grados (x) a radianes.
    y = (x * 3.14159265359)/180;

    //Ciclo for que itera cada termino de la serie
    for(int i=1; i<=n; i++)
    {
        factorial = 1;
        //Ciclo for para calcular el factorial
        for(int j=1; j<=exponente; j++)
        {
            factorial = factorial * j;
        }
        //Condicionales para cambiar el signo ya que este cambia cada termino +-+-+
        if(i%2 == 0)
        {
            resultado = resultado - pow(y, exponente)/factorial;
        }
        else
        {
            resultado = resultado + pow(y, exponente)/factorial;
        }
        //El exponente aumenta de 2 en 2 cada termino empezando con 1 (1, 3, 5, 7...)
        exponente = exponente + 2;
    }
    //Retornar resultado de la serie de taylor de Seno
    return resultado;
}

//Funcion Coseno
double coseno(double x, int n)
{
    int exponente = 0, signo = -1;
    float y;
    double resultado1 = 0, factorial = 1; 

    y = (x * 3.14159265359)/180;

    //Ciclo for para iterar termino por termino
    for(int i=0; i<=n; i++)
    {
        factorial = 1;
        //Ciclo for para calcular factorial
        for(int j=1; j<=exponente; j++)
        {
            factorial = factorial * j;  
        }
        //Cada termino el signo cambiara +-+-+
        signo = signo * -1;
        resultado1 = resultado1 + signo*pow(y, exponente)/factorial;
        //El exponente aumenta de 2 en 2 empezando por cero (0, 2, 4, 6...)
        exponente = exponente + 2;
    }
    //Retornar resultado de la serie de taylor de coseno
    return resultado1;
}