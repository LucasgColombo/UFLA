#include <iostream>
#include <fstream>

using namespace std;

int main(){
	string nome = "numeros";
	ifstream arquivo(nome); 
	
	ofstream par("pares");
	ofstream impar("impares");
	
	int conteudo;
	while (arquivo >> conteudo){
		if (conteudo % 2 == 0){
			par << conteudo << " ";
		}else{
			impar << conteudo << " ";
		}
	}
	arquivo.close();
	par.close();
	impar.close();

	return 0;
}
