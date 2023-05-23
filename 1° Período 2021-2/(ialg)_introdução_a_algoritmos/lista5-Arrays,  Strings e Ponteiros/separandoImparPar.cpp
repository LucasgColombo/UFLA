#include <iostream>

using namespace std;

int main (){
	
	int v[20], imp[20], par[20];
	int p=0, l=0;
	
	for (int i=0; i < 20; i++){
		cin >> v[i];
	}

	for (int i=0; i < 20; i++){
		if (v[i] % 2 == 0){
			par[p] = v[i];
			p++; 
		}else{
			imp[l] = v[i];
			l++;
		}
	}
	
	
	
	cout << endl;
	for (int i=0; i < p; i++)
		cout << par[i] << " ";
	
	cout << endl;
	
	for (int i=0; i < l; i++){
			cout << imp[i] << " "; 
		}	
	
	return 0;
}
