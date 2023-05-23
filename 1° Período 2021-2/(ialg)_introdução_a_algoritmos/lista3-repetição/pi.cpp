#include <iostream>
#include <cmath>

using namespace std;

int main (){
	int c=1, p;
	double x, raiz, pi;
	
	x = sqrt(2);
	raiz = x;
	
	cin >> p;
	
	while (c < p){
		x = sqrt (2 + x);
		raiz *= x;
		c++;
	}
	
	pi = (pow(2, p+1))/ raiz;
	
	
	cout << pi << endl;
	
	
	return 0;
}

