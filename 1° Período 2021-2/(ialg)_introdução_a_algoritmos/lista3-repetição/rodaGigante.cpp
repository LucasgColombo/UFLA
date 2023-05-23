#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	const double pi = 3.14159265358;
	int cadeiras;
	float raio, x, y, angulo, cont=0;
	
	cin >> raio >> cadeiras;
	
	angulo = 360/cadeiras;
	
	while(cadeiras > cont){
	x = raio * cos(pi * angulo*cont/180);
	y = raio * sin(pi * angulo*cont/180);
	
	cout << fixed << setprecision(2) << x << " " << y << endl;
	
	cont++;
	}
	
	return 0;
}

