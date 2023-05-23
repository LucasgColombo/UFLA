#include <iostream>
#include <cstring>

using namespace std;

int main (){
	int tam=0;
	string frase, frase2, concatenacao;
	
	getline(cin, frase);
	getline(cin, frase2);
	
	frase = frase + frase2;
	
	tam = frase.length();
	
	char *v = new char [tam];
	
	strcpy(v,frase.c_str());
	
	for (int i=0; i < tam; i++){
		cout << v[i];
	}
	
	
	return 0;
}

