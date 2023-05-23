#include <iostream>

using namespace std;

int binaria (int v[], int inicio, int fim, int busca){
	if(inicio <= fim){
		int meio = (inicio+fim)/2;
		cout << v[meio] << " ";
			if(v[meio]<busca){
				return binaria(v,meio+1, fim, busca);
			}else if(v[meio]>busca){
				return binaria(v, inicio, meio-1, busca);
			}else
				return meio;
	}
	return -1;
}

int  main (){
	int quant, busca;
	
	cin >> quant;

	int v[quant];

	for(int i=0; i < quant; i++){
		cin >> v[i];
	}

	cin >> busca;

	binaria(v, 0, quant-1, busca);

	return 0;
}
