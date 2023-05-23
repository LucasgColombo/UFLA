#include <iostream>
#include <cmath>

using namespace std;

struct memes {
	int num;
	string nome;
	string assunto;
	string site;
};

void imprime ( memes lista[], int quant, string busca){
	bool x=false;

	for (int i = 0; i < quant; i++){
		if (lista[i].site == busca){
			cout << lista[i].num << " ";
			cout << lista[i].nome << " ";
			cout << lista[i].assunto << " ";
			cout << lista[i].site << endl;

			x = true;
			}
	}

	if (x == false){
		cout << "Inexistente" << endl;
	}
}

void ordenacao (memes lista[], int quant){
	int menor;
	
    for (int i = 0; i < quant-1; i++) {
   	 menor = i;
   	 
   	 for (int j = i + 1; j < quant; j++) {
   		 if (lista[j].num < lista[menor].num){
   			 menor = j;
   		 }
   	 }
   	 swap (lista[i], lista[menor]);
   	 
    }
}

void leitura (memes lista[], int quant){
	for (int i=0; i< quant; i++){
		cin >> lista[i].num;
		cin >> lista[i].nome;
		cin >> lista[i].assunto;
		cin >> lista[i].site;
	}
}

int main(){
    int quant;
    string busca;
    
    cin >> quant;
    
    memes lista[quant];
    
    leitura(lista, quant);
    
    ordenacao(lista, quant);
    
    cin >> busca;
    
    imprime(lista,quant, busca);
	
    return 0;
}
