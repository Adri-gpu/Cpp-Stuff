#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	const int haut = 50;
	const int lon = 50; 
	double ci;
	double cj;
	double r; 
	double d;
	cout << "Entrez les coordonnées du centrer (ci,cj) et le rayon" << endl;
	cin >> ci;
	cin >> cj;
	cin >> r;
	for (int i=0 ; i<haut ; ++i)
	{
		for (int j=0; j<lon ; ++j)
		{
			d=(cj-j)*(cj-j)+(ci-i)*(ci-i);
			if (d <= r*r)
				cout << "*" ;
			else 
				cout << " " ;
		}
	cout << endl;
	}
	
}
		
