#include <iostream>
#include <fstream>

using namespace std;

string codifica(string conteudo){
	int tam = conteudo.length(), letraId;
	char letra;
	
	for(int i=0; i < tam; i++){
		if(conteudo[i] != ' '){
			if (conteudo[i] == 'X'){
				conteudo[i] = 'A';
			}else if (conteudo[i] == 'Y'){
				conteudo[i] = 'B';
			}else if (conteudo[i] == 'Z'){
				conteudo[i] = 'C';
			}else{
				letraId = conteudo[i];
				letraId += 3;
				letra = letraId;
				conteudo[i] = letra;
			}
		}
	}
	return conteudo;
	
}

int main(){
	string nome, conteudo;
	
	cin >> nome;
	
	ifstream arquivo(nome);
	
	ofstream saida("cifrado");
	
	while (getline(arquivo, conteudo)){
		saida << codifica(conteudo) << endl;
	}
	
	arquivo.close();
	saida.close();

	return 0;
}

