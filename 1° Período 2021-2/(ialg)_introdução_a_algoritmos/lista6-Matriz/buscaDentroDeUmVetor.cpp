#include <iostream>

using namespace std;

int binaria(int v[], int tam, int busca) {   
	int inicio=0, meio, fim=tam-1;
	  
	while (inicio <= fim ) {
		meio = (inicio + fim )/2;
		
		if (v[meio] == busca){
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
	int tam, busca;
	
	cin >> tam;
	
	int v[tam];
	
	for (int i=0; i < tam; i++){
		cin >> v[i];
	}
	
	cin >> busca;
	
	cout << binaria (v, tam, busca);
	
	return 0;
}
