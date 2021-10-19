#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

	long double un = 0 ;
	long double vn = 0 ;

long double CalculU(long double n)
{
	un = 99.0/100.0;
	long double u1 = 99.0/100.0;
	long double u2 = 4801.0/5000.0;
	
		for(int i=2; i<2*n-1; i++)
		{   
			un = (99.0/50.0*u2)-u1;
			u1 = u2;
			u2 = un;
			
		}
		cout << un << endl;
		return un;
	
}

long double CalculV(long double n)
{
	vn = 99.0/4780.0;
	long double v1 = 99.0/4780.0;
	long double v2 = -11414399.0/11424200.0;
	
		for(int i=2; i<2*n-1; i++)
		{   
			vn = (99.0/2390.0)*v2-v1;
			v1 = v2;
			v2 = vn;
			
		}
		cout << std::setprecision(20) << vn << "e" << endl;
		return vn;
	
}

int main()
{   
	long double n=0;
	cout << "Entrez un nombre de répétitions : ";
	cin >> n;
	long double pi=0.0;
	
	for(long double i=1; i<n+1; i++)
	{
		un = CalculU(i);
		vn = CalculV(i);
		pi = pi+(pow((-1.0),(i-1.0))/pow(10.0,((2.0*i)-1.0))*((2.0*i)-1.0))*((4.0*un)-vn);
	}
	pi = 8*pi;
	cout << std::setprecision(20) << pi << endl;
}


