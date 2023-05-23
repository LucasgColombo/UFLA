#include <iostream>
#include <cmath>

using namespace std;

int main() {
	float alturaDesejada, alturaDegrau;
	int  quantDegrau;
	
	cin >> alturaDegrau;
	cin >> alturaDesejada;
	
	quantDegrau = round((alturaDesejada*100.0)/alturaDegrau);
	
	cout << quantDegrau;
	
    return 0;
}


