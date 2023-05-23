#include <iostream>
#include <iomanip>

using namespace std;

double parcelas (double n){
	double aux=0, resp=0, i=0;
	 
	while (n != i-1){
		resp = i*(i+1)/(i+3);
		i++;
		aux = aux + resp;
	}
	
	return aux;
}

int main (){
	double n;
	
	cin >> n;
	
	cout << parcelas(n);
	
	return 0;
}
