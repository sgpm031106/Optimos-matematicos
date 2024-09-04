/*
Universidad Autonoma de Aguascalientes
Centro de Ciencias Basicas
Departamento de Ciencias de la Computacion
Programacion Cientifica
Profesor: Fernando Gutierrez Marfileño
Alumnos: 
 - Perez Moreno Sergioo Gabriel
 - Rovelo Gonzalez Miguel Adrian
 - Nava Salazar Marcos Fernando
 
Mayo del 2023
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>

using namespace std;

void Regresion_lineal()
{
	cout<<"Calcular la función de regresión lineal para el siguiente conjunto de datos:"
	"\nCinco niños de 2, 3, 5, 7 y 8 años de edad pesan, respectivamente, 14, 20, 32, 42 y 44 kilos."
	"\nHallar la ecuación de la recta de regresión de la edad sobre el peso. "<<endl<<endl;
	int n;
	double y[100], x[100], xy[100], x2[100], sumaY, sumaX, sumaXY, sumaX2;
	double a0, a1;
	
	cout<<"Ingrese la cantidad de coordenadas: ";
	cin>>n;
	cout<<"\n";
	
	for(int i=0; i<n; i++)
	{
		cout<<"Ingrese Y"<<i+1<<": ";
		cin>>y[i];
	}
	cout<<"\n";
	
	for(int i=0; i<n; i++)
	{
		cout<<"Ingrese X"<<i+1<<": ";
		cin>>x[i];
	}
	cout<<"\n";
	
	for(int i=0; i<n; i++)
	{
		xy[i] = y[i]*x[i];
		x2[i] = x[i]*x[i]; 
		sumaY = sumaY + y[i];
		sumaX = sumaX + x[i];
		sumaXY = sumaXY + xy[i];
		sumaX2 = sumaX2 + x2[i];
	}
	
	cout<<"Y\t"<<"X\t"<<"x2\t"<<"XY"<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<y[i]<<"\t"<<x[i]<<"\t"<<x2[i]<<"\t"<<xy[i]<<endl;
	}
	cout<<sumaY<<"\t"<<sumaX<<"\t"<<sumaX2<<"\t"<<sumaXY<<endl;
	
	cout<<"\n";
	
	a1 = (n*sumaXY - sumaX*sumaY)/(n*sumaX2-pow(sumaX,2));
	a0 = (sumaY - a1*sumaX)/n;
		
	cout<<"El resultado del modelo es y = "<<setprecision(9)<<a0<<" + "<<setprecision(9)<<a1<<endl;	
}


double interpolacion(int x, double* valoresX, double* valoresY)
{
	double resultado = 0.0;
	
	for(int i=0; i<3; i++)
	{
		double terminos = valoresY[i];
		for(int j=0; j<3; j++)
		{
			if(j != i)
			{
				terminos *= (x - valoresX[j] / (valoresX[j]) - valoresX[j]);
			}
		}
		resultado += terminos;
	}
	return resultado;	
}

void Polinomio_Unico()
{
	cout<<"Encontrar el polinomio de interpolación único para los valores:  (10, 0.1763),(20, 0.3640),(30, 0.5774) \n"
	"e interpolar el valor para x=21 "<<endl<<endl;
	
	double valoresX[3];
	double valoresY[3];
	int x;
	
	cout<<"Ingrese el valor de x: ";
	cin>>x;
	
	for(int i=0; i<3; i++)
	{
		cout<<"Ingrese los valores de x"<<i+1<<": ";
		cin>>valoresX[i];
	}
	cout<<"\n";
	
	for(int i=0; i<3; i++)
	{
		cout<<"Ingrese los valores de y"<<i+1<<": ";
		cin>>valoresY[i];
	}
	cout<<"\n";
	
	double valor_interpolado = interpolacion(x, valoresX, valoresY);
	
	cout<<"El valor interpolado para x = "<<x<<" es: "<<valor_interpolado<<endl;
}


void LaGrange()
{
	cout<<"Obtener el polinomio de interpolación usando la fórmula de interpolación de Lagrange con la siguiente tabla de valores, \n"
	"e interpolar en el punto x = -4. xk = {-6, 6, -1}      yk= { 8, -16, -2} "<<endl<<endl;
	int n=3;
	double x[n],y[n],aux,inter=0,interpolacion=0;
	
	//Valores de esfuerzo
	x[0]=-6;
	x[1]=6;
	x[2]=-1;
	//Valores de deformacion
	y[0]=8;
	y[1]=-16;
	y[2]=-2;
	
	cout<<"-----------Tabla de datos-----------"<<endl;
	cout<<"\t x \t\t y "<<endl;
	for(int i=0;i<n;i++){
		cout<<"\t"<<x[i]<<"\t\t"<<y[i]<<endl;
	}
	cout<<"------------------------------------"<<endl<<endl;
	
	cout<<"Ingresa el valor de interpolacion: ";	
	cin>>inter;
	
	for(int i=0; i<n ;i++){
	    aux=y[i];
	    for(int j=0; j<n; j++){
	        if(i!=j){
	            aux=(aux*(inter-x[j]))/(x[i]-x[j]);
	        }
	    }
	    interpolacion=interpolacion+aux;
	}
	cout<<"El polinomio de interpolacion cuando x = "<<inter<<", es : "<<interpolacion<<endl;
}

double interpolacion2(int n)
{
	double* xValues = new double[n];
    double* yValues = new double[n];

    // Ingresar los valores (x, y) desde la entrada estándar
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el valor x para el punto " << (i + 1) << ": ";
        cin >> xValues[i];
        cout << "Ingrese el valor y para el punto " << (i + 1) << ": ";
        cin >> yValues[i];
    }

    double x;
    cout << "Ingrese el valor de x para interpolar: ";
    cin >> x;

    double result = yValues[0]; // Término inicial

    double** dividedDifferences = new double*[n];
    for (int i = 0; i < n; i++) {
        dividedDifferences[i] = new double[n];
    }

    // Calcular las diferencias divididas
    for (int i = 0; i < n; i++) {
        dividedDifferences[i][0] = yValues[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            dividedDifferences[i][j] = (dividedDifferences[i + 1][j - 1] - dividedDifferences[i][j - 1]) / (xValues[i + j] - xValues[i]);
        }
    }

    // Calcular el polinomio de interpolación de Newton
    double term = 1.0;
    for (int i = 1; i < n; i++) {
        term *= (x - xValues[i - 1]);
        result += term * dividedDifferences[0][i];
    }
    return result;
}

void Newton()
{
	cout<<"Calcular el polinomio de interpolacion de Newton para los siguientes datos: "<<endl;
	cout<<"x = (-2, -1, 2, 3) y = (4, 1, 4, 9) y el valor a interpolar es 5. "<<endl<<endl;
	int n;
    cout << "Ingrese la cantidad de datos para la interpolación: ";
    cin >> n;

    double interpolatedValue = interpolacion2(n);

    cout << "El valor interpolado es: " << interpolatedValue << endl;
}

int main()
{
	setlocale(LC_ALL, "spanish");
	int op;
	do
	{
		cout<<"---MENÚ---"<<endl;
		cout<<"1. Método de Regresion Lineal. "<<endl;
		cout<<"2. Método de Polinomio de Interpolación. "<<endl;
		cout<<"3. Método de Interpolación de LaGrange. "<<endl;
		cout<<"4. Método de Interpolacion de Newton. "<<endl;
		cout<<"5. Salir del programa. "<<endl;
		cout<<"Que desea realizar? ";
		cin>>op;
		cout<<"\n";
		switch(op)
		{
			case 1:
				Regresion_lineal();
				cout<<"\n";
				break;
				
			case 2:
				Polinomio_Unico();
				cout<<"\n";
				break;
				
			case 3:
				LaGrange();
				cout<<"\n";
				break;
			
			case 4:
				Newton();
				cout<<"\n";
				break;
				
			case 5:
				cout<<"Saliendo del programa. "<<endl<<endl;
				break;
				
			default:
				cout<<"Opción inválida, ingrese otra respuesta. "<<endl<<endl;
				break;
		}
		system("pause");
		system("cls");
	}while(op != 5);
	
	return 0;
}
