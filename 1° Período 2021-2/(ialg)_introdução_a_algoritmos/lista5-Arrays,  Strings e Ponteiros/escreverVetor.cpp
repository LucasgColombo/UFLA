#include <iostream>

using namespace std;

void imprime (int vetor[], int tamanho){
	
	cout << "[";
	
	for (int i=0; i < tamanho; i++)
		cout << vetor[i] << ", ";
		
	cout << "]" << endl;
}

int main (){
	int tam;
	
	cin >> tam;
	
	int v[tam];
	
	for (int i=0; i < tam; i++)
		cin >> v[i];
		
	imprime(v, tam);
	
	return 0;
}
