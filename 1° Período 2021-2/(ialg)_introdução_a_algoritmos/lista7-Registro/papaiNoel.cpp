#include <iostream>

using namespace std;

struct carta{
	string nome;
	string pedido;
};

struct brinquedo{
	string nome;
	int quantidadeDisponivel;
	int quantidadeNecessaria;
};

int main(){
	int totalCartas, totalBrinquedos;
	
	cin >> totalCartas;
	
	carta listaPedidos[totalCartas];
	
	for (int i=0; i < totalCartas; i++){
		cin >> listaPedidos[i].nome >> listaPedidos[i].pedido;
	}
	
	cin >> totalBrinquedos;
	
	brinquedo estoquePresentes[totalBrinquedos];
	
	for (int i=0; i < totalBrinquedos; i++){
		cin >> estoquePresentes[i].nome; 
		cin >> estoquePresentes[i].quantidadeDisponivel; 
		estoquePresentes[i].quantidadeNecessaria=0;
	}
	
	for (int i=0; i < totalCartas; i++){
		int j=0; 
		while ((j < totalBrinquedos) and (estoquePresentes[j].nome != listaPedidos[i].pedido)){
			j++;
		}
		
		if (estoquePresentes[j].nome == listaPedidos[i].pedido){
			estoquePresentes[j].quantidadeNecessaria++;
		}
	}
	
	for (int i=0; i < totalBrinquedos; i++){
		if (estoquePresentes[i].quantidadeDisponivel < estoquePresentes[i].quantidadeNecessaria){
			cout << estoquePresentes[i].nome << " ";
		}
	}
	
	
	
	return 0;
}
