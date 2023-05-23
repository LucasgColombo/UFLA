#include <iostream>

using namespace std;

int main(){
	int n, maior=0;
	string justify ="";
	
	cin >> n;
	
	string p[n];
	
	for(int i=0; i < n; i++){
		cin >> p[i];
		
		if(int(p[i].length()) > maior){
			maior = int(p[i].length());
		}
	}
	
	for(int i = 0; i < n; i++){
		if(int(p[i].length()) < maior){
			justify ="";
      
			while(int(justify.length()) < maior - int(p[i].length())){
				justify += "*";
			}
			
			p[i] = justify + p[i];
		}
	}	

	for(int i = 0; i < n; i++){
		cout << p[i] << endl;
	}

	return 0;

}
