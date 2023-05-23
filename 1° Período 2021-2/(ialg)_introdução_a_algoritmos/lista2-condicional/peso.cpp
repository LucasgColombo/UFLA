#include <iostream>

using namespace std;

int main (){
	float h, pesoM, pesoF;
	char  sexo;
	
	cin >> sexo >> h;
	
	switch (sexo){
		case 'M':
			pesoM = (72.7 * h) - 58;
			cout << pesoM;
			break;
		case 'F':
			pesoF = (62.1 * h) - 44.7;
			cout << pesoF;
			break;
	}
		
	return 0;
}
