#include <iostream>
#include <string>

using namespace std;

int removedor (string v[], int quant){
	int aux=0;
	
	for (int i=0; i < quant; i++){
		if (v[i] == v[i+1])
			v[i] = "";
	}
	
	for (int i=0; i < quant; i++){
		if (v[i] != ""){
			swap(v[i], v[aux]);
			aux++;
		}
	}

	return 0;
}

int main (){
	int quant, i=0, c=0;
	
	cin >> quant;
	
	string v[quant] = {};
	
	for (i=0; i < quant; i++){
		cin >> v[i];
	}
	
	for (i=0; i < quant; i++){
		if (v[i] != v[i-1]){
			c++;
		}
	}
	
	cout << c << endl;
	
	removedor (v, quant); 
	
	for (i=0; i < c; i++){
		cout << v[i] << endl;; 
	}
	
	return 0;
}

