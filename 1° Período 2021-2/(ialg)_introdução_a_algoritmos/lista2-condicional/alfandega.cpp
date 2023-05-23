#include <iostream>

using namespace std;

int main() {
    float codigoCompra, peso, codigoPais, precoBruto, imposto, valorFinal;
		
	cin >> codigoCompra >> peso >> codigoPais;
	
	peso *= 1000;
	
	cout << peso << endl;
	
	if ((codigoCompra >= 1) and (codigoCompra <= 4)){
		precoBruto = peso * 10;
		cout << precoBruto << endl;
	}else if((codigoCompra >= 5 ) and (codigoCompra <= 7)){
		precoBruto = peso * 25;
		cout << precoBruto << endl;
	}else if((codigoCompra >= 8) and (codigoCompra <= 10)){
		precoBruto = peso * 35;
		cout << precoBruto << endl;
	}
	
	if (codigoPais == 1){
		imposto = precoBruto * 0.0;
		cout << imposto << endl;
	}else if(codigoPais == 2){
		imposto = precoBruto * 0.15;
		cout << imposto << endl;
	}else if(codigoPais == 3){
		imposto = precoBruto * 0.25;
		cout << imposto << endl;
	}
	
	valorFinal = precoBruto + imposto;
	
	cout << valorFinal << endl;
	
    return 0;
}
