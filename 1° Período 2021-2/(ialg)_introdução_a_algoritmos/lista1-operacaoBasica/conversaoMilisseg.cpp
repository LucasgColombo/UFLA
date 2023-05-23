#include <iostream>

using namespace std;

int main() {
	int milisseg, min, hora;
	double seg;
	
    cin >> milisseg;
    
    hora = milisseg / 3600000;
    min = (milisseg%3600000)/60000;
    seg = (milisseg%3600000%6000)/1000.0;
    
    cout << hora << " : " << min << " : " << seg << endl;
    
    return 0;
}
