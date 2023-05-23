#include <iostream>
#include <string>

using namespace std;

struct lista {
	int matri;
	string nome;
};

int main (){
	int quant, busca;
	
	cin >> quant;
	
	int inicio=0, meio, fim = quant - 1;
	
	lista v[quant];
	
	for (int i = 0; i < quant; i++){
		cin >> v[i].matri;
		cin >> v[i].nome;
	}
	
	 cin >> busca;
	
	while (inicio <= fim) {
		meio = (inicio + fim)/2;
		cout << v[meio].matri << endl;
		
		if (busca == v[meio].matri){
			cout << v[meio].nome << endl;
			
			inicio = fim + 1;
		}else{
			if (busca > v[meio].matri)
				inicio = meio+1;
			else
				fim = meio-1;
		}
	}
	
	return 0;
}
