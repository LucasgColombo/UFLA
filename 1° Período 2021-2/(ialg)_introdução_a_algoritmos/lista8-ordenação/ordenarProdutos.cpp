#include <iostream>
#include <cmath>

using namespace std;

struct produtos {
	int id;
	string nome;
	float preco;
};

void ordenacao (produtos lista[], int totalC){
	
	produtos pivo;
	int j;
	
	for(int i=1; i < totalC; i++){
		pivo.id = lista[i].id;
		pivo.nome = lista[i].nome;
		pivo.preco = lista[i].preco;
		
		j = i-1;
		
		while(j >= 0 and pivo.preco < lista[j].preco){
			lista[j+1].id = lista[j].id;
			lista[j+1].nome = lista[j].nome;
			lista[j+1].preco = lista[j].preco;
			
			j = j - 1;
		}
		lista[j+1].id = pivo.id;
		lista[j+1].nome = pivo.nome;
		lista[j+1].preco = pivo.preco;
	}
}

int main(){
    int quant;
    bool x=false;
    
    cin >> quant;
    
    produtos lista[quant];
    
    for (int i=0; i < quant; i++){
		cin >> lista[i].id;
		cin.ignore();
		getline(cin , lista[i].nome);
		cin >> lista[i].preco;
	}
	
	ordenacao(lista, quant);
	
	float min, max;
	cin >> min >> max;
	
	for (int i=0; i < quant; i++){
		if (lista[i].preco >= min and lista[i].preco <= max){
			cout << lista[i].id << " ";
			cout << "\"" << lista[i].nome << "\" ";
			cout << lista[i].preco << endl;
			
			x = true;
		}
	}
	
	if(x == false){
		cout << "inexistente" << endl;
	}

    return 0;
}

