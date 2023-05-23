#include <iostream>

using namespace std;

struct pacientes {
	string nome;
	char sexo;
	float altura;
	float peso=0;
	float imc;
};

int main (){
	int totalPaci;
	
	cin >> totalPaci;
	
	pacientes v[totalPaci];
	
	string maisPesada;
	float pesoMaior = 0;
	
	//preenche o vetor
	for (int i = 0; i < totalPaci; i++){
		cin >> v[i].nome;
		cin >> v[i].sexo; 
		cin >> v[i].altura;
		cin >> v[i].peso;
		
		// calcula o imc
		if (v[i].sexo == 'H')
			v[i].imc = 72.7 * v[i].altura - 58;
		else
			v[i].imc = 62.1 * v[i].altura - 44.7;
		
		//acha o peso maior
		if (v[i].peso > pesoMaior){
			pesoMaior = v[i].peso;
			maisPesada = v[i].nome;
		}
			
	}
	
	cout << endl;
	cout << maisPesada << endl;
	
	for (int i = 0; i < totalPaci; i++){
		if (v[i].peso > v[i].imc){
			cout << v[i]. nome << " " << v[i].imc - v[i].peso << endl;
		}
	}
	
	for (int i = 0; i < totalPaci; i++){
		if (v[i].peso < v[i].imc){
			cout << v[i]. nome << " " << v[i].imc - v[i].peso << endl;
		}
	}
	
	return 0;
}
