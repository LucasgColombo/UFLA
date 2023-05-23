#include <iostream>

using namespace std;

int binaria(int v[], int inicio, int fim, int procurado) {     
	if (inicio <= fim){
		int meio = (inicio+fim)/2;
		
		if (v[meio] > procurado){
			return binaria(v,meio+1,fim,procurado);
		}else if (procurado > v[meio]){
			return binaria(v,inicio,meio-1,procurado);
		}else
			return meio;
	}
	return -1;
}


int main (){
	int quant, busca;
	
	cin >> quant;
	
	int v[quant];
	
	for (int i=0; i < quant; i++){
		cin >> v[i];
	}
	
	cin >> busca;
	
	cout << binaria (v, 0, quant-1, busca) << endl;
	
	return 0;
}
