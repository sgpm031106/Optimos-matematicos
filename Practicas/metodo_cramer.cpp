/*
Universidad Autónoma de Aguascalientes
Centro de Ciencias Básicas
Departamento de cienicas de la computacion
Ingenieria en Computacion Inteligente
- Pérez Moreno Sergio Gabriel
- Rovelo González Miguel Adrián
- Nava Salazar Marcos Fernando
Profesor: Fernando Gutiérrez Marfileño
Materia: Programacion Cientifica
Abril del 2022 
*/



#include <iostream>
using namespace std;

int main()
{
    //double a[3][3] = {{2, -1, 6}, {-3, 4, -5}, {8, -7, -9}};  // coeficientes del sistema
    //double b[3] = {77, -30, -133};  // tÃ©rminos independientes del sistema
    double a[100][100];
    double b[100];
    int n;
    
    //Variable para guardar el tamaño que tendra la matriz, ya que debe de ser cuadrada (nxn).
    cout<<"Ingrese la cantidad de sistemas a resolver: ";
    cin>>n;
    cout<<"\n";
    
    //La matriz se llenara con los valores que tienen incognitas
    cout<<"inserte la matriz"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }       
    
    cout<<"\n";
    
    //El vector b se llenara con los valores de los terminos independientes
    cout<<"inserte b"<<endl;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    
    /*
    
    MATRIZ
	(Incognitas) VECTOR (terminos independientes)
    ---------	-------
    1	2	3  =  10
    4	5	6  =  20
    7	8	9  =  30
    */
    
    
    cout<<"\n";

    double detA = a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[0][2] * a[1][0] * a[2][1]
               - a[0][2] * a[1][1] * a[2][0] - a[0][0] * a[1][2] * a[2][1] - a[0][1] * a[1][0] * a[2][2];
    // determinante de la matriz de coeficientes

    double detA1 = b[0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * b[2] + a[0][2] * b[1] * a[2][1]
                - a[0][2] * a[1][1] * b[2] - b[0] * a[1][2] * a[2][1] - a[0][1] * b[1] * a[2][2];
    // determinante de la matriz de coeficientes con la primera columna reemplazada por los tÃ©rminos independientes

    double detA2 = a[0][0] * b[1] * a[2][2] + b[0] * a[1][2] * a[2][0] + a[0][2] * a[1][0] * b[2]
                - a[0][2] * b[1] * a[2][0] - a[0][0] * a[1][2] * b[2] - b[0] * a[1][0] * a[2][2];
    // determinante de la matriz de coeficientes con la segunda columna reemplazada por los tÃ©rminos independientes

    double detA3 = a[0][0] * a[1][1] * b[2] + a[0][1] * b[1] * a[2][0] + b[0] * a[1][0] * a[2][1]
                - b[0] * a[1][1] * a[2][0] - a[0][0] * b[1] * a[2][1] - a[0][1] * a[1][0] * b[2];
    // determinante de la matriz de coeficientes con la tercera columna reemplazada por los tÃ©rminos independientes

    double x1 = detA1 / detA;  // solucion para x1
    double x2 = detA2 / detA;  // solucion para x2
    double x3 = detA3 / detA;  // solucion para x3

    cout << "Solucion del sistema de ecuaciones lineales:" << endl;
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;

    return 0;

}
