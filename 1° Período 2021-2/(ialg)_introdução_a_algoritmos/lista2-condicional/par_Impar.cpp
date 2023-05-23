#include <iostream>

using namespace std;

int main() {
    int num, numPar=0, numImpar=0, digito;
		
	cin >> num;
	
	digito = num%10; 
	num = num/10;
	if (digito%2 == 0){
		numPar++;
	}else{
		numImpar++;
	}
	
	digito = num%10; 
	num = num/10;
	if (digito%2 == 0){
		numPar++;
	}else{
		numImpar++;
	}
	
	digito = num%10; 
	num = num/10;
	if (digito%2 == 0){
		numPar++;
	}else{
		numImpar++;
	}
	
	digito = num%10; 
	num = num/10;
	if (digito%2 == 0){
		numPar++;
	}else{
		numImpar++;
	}
	
	digito = num%10; 
	num = num/10;
	if (digito%2 == 0){
		numPar++;
	}else{
		numImpar++;
	}
	
	cout << numPar << endl;	
	cout << numImpar << endl;
    return 0;
}

