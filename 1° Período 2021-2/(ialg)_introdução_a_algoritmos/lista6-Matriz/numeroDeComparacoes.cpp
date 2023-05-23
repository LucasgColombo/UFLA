#include <iostream>

using namespace std;

int binaria(int v[], int tam, int busca, int &c, int troca) {   
	int inicio=0, meio, fim=tam-1;
	  
	while (inicio <= fim ) {
		meio = (inicio + fim )/2;
		c++;
		
		if (v[meio] == busca){
			v[meio] = troca;
			return meio;
		} else{ 
			if (v[meio] < busca){ 
				inicio = meio+1;
			}else{ 
				fim = meio;
			}
		}
	}
	return -1;

}


int main (){
	int tam, busca, c=0, troca;
	
	cin >> tam;
	
	int v[tam];
	
	for (int i=0; i < tam; i++){
		cin >> v[i];
	}
	
	cin >> busca;
	cin >> troca;
	
	binaria (v, tam, busca, c, troca);
	
	for (int i=0; i < tam; i++){
		cout << v[i] << " ";
	}
	cout << endl;
	cout << c << endl;
	
	return 0;
}
