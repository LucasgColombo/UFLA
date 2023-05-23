#include <iostream>

using namespace std;

int main (){
	int dividendo, divisor, quociente, resto;
	
	cin >> dividendo >> divisor;
	
	if(divisor != 0){
		quociente = dividendo/divisor;
		resto = dividendo%divisor;
	
		cout << quociente << endl; 
		cout << resto << endl;
	}else{
		cout << "erro" << endl;
	}
	
	return 0;
}
