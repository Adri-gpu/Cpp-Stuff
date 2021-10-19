#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	cout << "Entrez le nombre d'iterations: ";
	int n;
	cin >> n;
	//long double pi = 0.0;
	long double a = 0.0;//
	
	for(long double i=0.0; i<n; i++)
	{
		a = ( 1/pow(16,i) )*( ( 4/(8*i+1) )-( 2/(8*i+4) )-( 1/(8*i+5) )-( 1/(8*i+6) ) );//
		cout << i << " : " << setprecision(20) << a << endl;//
		
		
		//pi += ( 1/pow(16,i) )*( ( 4/(8*i+1) )-( 2/(8*i+4) )-( 1/(8*i+5) )-( 1/(8*i+6) ) );
		//cout << i << " : " << setprecision(20) << pi << endl;
	}
	//cout << setprecision(20) << pi << endl;
	
	return 0;
}
