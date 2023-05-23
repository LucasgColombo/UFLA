#include <iostream>
#include <cmath>

using namespace std;

struct alunos{
	string matri;
	string nome;
	int nota;
};

int main(){
	int quantAlu, maiorN=0;
	float mediaN=0, porcentagem=0;
	string notaMaior;
	
	cin >> quantAlu;
	
	alunos lista [quantAlu];
	
	for (int i=0; i < quantAlu; i++){ //insercao, mediaNota, nome da maior nota
		cin >> lista[i].matri;
		cin >> lista[i].nome;
		cin >> lista[i].nota;
		
		if (lista[i].nota > maiorN){
			maiorN = lista[i].nota; 
			notaMaior = lista[i].nome;
		}
		
		mediaN += lista[i].nota;
	}
	
	mediaN /= quantAlu;
	cout << mediaN << endl;
	
	for (int i=0; i < quantAlu; i++){ //alunos que zeraram
		if (lista[i].nota == 0){
			cout << lista[i].matri << endl;
		}
	}
	
	for (int i=0; i < quantAlu; i++){ // porcentagem abaixo da media
		if (lista[i].nota < mediaN){
			porcentagem++;
		}
	}
	porcentagem = (porcentagem / quantAlu)*100;
	cout << porcentagem << "%" << endl;
	
	cout << notaMaior << endl;
	
	return 0;
}
