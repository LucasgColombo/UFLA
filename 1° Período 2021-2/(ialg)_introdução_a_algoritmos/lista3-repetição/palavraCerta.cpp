#include <iostream>
#include <string>

using namespace std;

int main(){
	
	int contA = 0;
	int contB = 0;
	
	int numLetras = 0;
	
	char L;
	
	while (numLetras < 10){
		cin >> L;
		if (L == char(98)){
			contB++;
		}else{
			contA++;
		}
		numLetras++;
	}
	
	if (contB > contA){
		cout << 1 << endl;
	}else{
		cout << 0 << endl;
	}
	
	return 0;
}

