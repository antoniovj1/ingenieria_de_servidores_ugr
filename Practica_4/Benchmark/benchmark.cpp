#include <iomanip>
#include <iostream>
#include <omp.h>
#include <vector>

using namespace std;

double media( const vector<double> &v ){
	double sum=0;
	for( int i = 0 ;  i < v.size() ; i++)
		sum+=v[i];
	return sum/v.size();
}

long double pi_secuencial( int n ){
	long double h = 1.0 / n;
	long double sum = 0.0;
	int i;
	double x;
	long double pi;

	#pragma omp single //Para asegurarnos de que solo se usa una hebra.
	{
		for (i = 1; i <= n; i++) {
			x = h * ((double)i - 0.5);
			sum += (4.0 / (1.0 + x*x));
		}
	}
	pi = sum * h;
	return pi;
}

long double pi_paralelo( int n ){
	long double h = 1.0 / n;
	long double sum = 0.0;
	int i;
	double x;
	long double pi;

	#pragma omp parallel for reduction(+:sum) private(x,i) //Ejecutamos el bucle de forma paralela para usar toda la CPU
	for ( i = 1; i <= n; i++) {
		x = h * ((double)i - 0.5);
		sum += (4.0 / (1.0 + x*x));
	}

	pi = sum * h;
	return pi;
}

int main(int argc, char *argv[]) 
{ 
 	cout <<endl;
	// Calculo de PI
        long long int n,n2;
	cout << "Número de iteraciones para el cáculo de PI (n > 0): ";
	cin >> n;

	cout << "Número de repeticiones del cálculo (n > 0): ";
	cin >> n2;
	
	vector<double> vt1,vt2;
	double tiempo_i1,tiempo_i2,tiempo_f1,tiempo_f2,tiempo1,tiempo2;

	long double pip,pis;

	for(int i = 0 ; i < n2 ; i++){
 	tiempo_i1 = omp_get_wtime();
		pip = pi_paralelo(n);
	tiempo_f1=omp_get_wtime();
	vt1.push_back( tiempo_f1-tiempo_i1 );
	}

	for(int i = 0 ; i < n2 ; i++){
 	tiempo_i2 = omp_get_wtime();
		pis = pi_secuencial(n);
	tiempo_f2=omp_get_wtime();
	vt2.push_back(tiempo_f2-tiempo_i2);
	}

	tiempo1 = media(vt1);
	tiempo2 = media(vt2);


	cout.precision(20);
	cout <<endl;
  	cout << left << setw(51)<< "El valor aproximado de PI es (paralelo): " << setw(24) << pip << endl;
  	cout << left << setw(51)<< "El valor aproximado de PI es (secuencial): " << setw(24) << pis << endl;
	cout <<endl;
	cout.precision(5);
  	cout << left << setw(51)<< "Tiempo usando el procesador completo (paralelo): " << setw(24) << tiempo1 << endl;
  	cout << left << setw(51)<< "Tiempo usando una sola hebra (secuencial): " << setw(24) << tiempo2 << endl;
	cout <<endl;


	return 0;
 
}
