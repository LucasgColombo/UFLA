#include <iostream>
#include <cmath>

using namespace std;

struct pessoas{
	float salario;
	int idade;
	int filhos;
};

int main(){
	int nPessoas;
	float mediaS=0, mediaF=0, maiorS=0, porcentagem=0;
	
	cin >> nPessoas;
	
	pessoas lista[nPessoas];
	
	for (int i=0; i < nPessoas; i++){ //preeche
		cin >> lista[i].salario;
		cin >> lista[i].idade;
		cin >> lista[i].filhos;
		
		if(lista[i].salario > maiorS){ // maior salario
			maiorS = lista[i].salario;
		}
	}

	for (int i=0; i < nPessoas; i++){ // media de salario e dilhos
		mediaS += lista[i].salario;
		mediaF += lista[i].filhos;
	}
	mediaS /= nPessoas;
	mediaF /= nPessoas;
	
	for (int i=0; i < nPessoas; i++){ // percentual 
		if (lista[i].salario > 1000){
			porcentagem++;
		}
	}
	porcentagem = (porcentagem / nPessoas)*100;
	
	cout << mediaS << endl;
	cout << mediaF << endl;
	cout << maiorS << endl;
	cout << round(porcentagem) << "%" << endl;
	
	return 0;
}
