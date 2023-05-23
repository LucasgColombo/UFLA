#include <iostream>

using namespace std;

struct carga{
	string tipoC;
	int Disparos;
};

struct armas{
	string nome;
	string Tipo;
};

int main(){
	int quantCargas, quantArmas;
	
	cin >> quantCargas;
	
	carga cDisponivel[quantCargas];
	
	for (int i=0; i < quantCargas; i++){
		cin >> cDisponivel[i].tipoC;
		cin >> cDisponivel[i].Disparos;
	}
	
	cin >> quantArmas;
	
	armas arsenal[quantArmas];
	
	for(int i=0; i < quantArmas; i++){
		cin >> arsenal[i].nome;
		cin >> arsenal[i].Tipo;
	}
	
	int municao=0;
	
	for(int i=0; i< quantArmas; i++){
		for (int j=0; j < quantCargas; j++){
			if (arsenal[i].Tipo == cDisponivel[j].tipoC)
				municao += cDisponivel[j].Disparos;
		}
	}
	
	cout << municao;
	
	return 0;
}
