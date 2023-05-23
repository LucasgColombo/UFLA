#include <iostream>

using namespace std;

int main(){
	string v[8];
	string m[10][8];
	float c=0, notaF=0, k=0;
	
	for (int i=0; i < 8; i++){
		cin >> v[i];
	}
	
	for (int i=0; i < 10; i++){
		for (int j=0; j < 8; j++){
			cin >> m[i][j];
		}
	}

	for (int i=0; i < 10; i++){
		for (int j=0; j < 8; j++){
			if (v[j] == m[i][j]){
				c++;
			}
		}
		c = (c/8)*100.0;
		
		notaF += c;
		
		cout << c << endl;
		
		c=0;
	}
	notaF /= 8;
	
	for (int i=0; i < 10; i++){
		for (int j=0; j < 8; j++){
			if (v[j] == m[i][j]){
				c++;
			}
		}
		c = (c/8)*100.0;
		
		if(c > notaF){
			k++;
		}
		
		c=0;
	}
	
	k = (k/10) * 100;
	
	cout << endl << k << endl;

	return 0;
}
