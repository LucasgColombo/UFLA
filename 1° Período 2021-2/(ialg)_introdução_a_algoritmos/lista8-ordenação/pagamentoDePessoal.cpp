#include <iostream>

using namespace std;

struct funcionarios {
	int id;
	float horaT;
	float valorH;
	float salario;
};

void ordenacao (funcionarios lista[], int quant){
	
	for (int i=0; i < quant-1; i++) {
		for (int j=0; j < quant-1-i; j++) {
			if (lista[j].salario > lista[j+1].salario){
				swap(lista[j], lista[j+1]);
			}
		}
	}
}

void leitura (funcionarios lista[], int quant){
	for (int i=0; i< quant; i++){
		cin >> lista[i].id;
		cin >> lista[i].horaT;
		cin >> lista[i].valorH;
		
		lista[i].salario = lista[i].horaT * lista[i].valorH;
	}
}

int main(){
    int quant;
    string busca;
    
    cin >> quant;
    
    funcionarios lista[quant];
    
    leitura(lista, quant);
    
    ordenacao(lista, quant);
    
    for (int i = 0; i < quant; i++){
			cout << lista[i].id << " ";
			cout << lista[i].salario << endl;
	}
	
    return 0;
}
