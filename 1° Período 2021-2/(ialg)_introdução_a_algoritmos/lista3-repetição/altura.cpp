#include <iostream>
#include <string>

using namespace std;

int main(){
	float alt, maiorAlt=0, menorAlt=100, altF=0, altM=0, altT=0; 
    int n, c=0, f=0, m=0;
    string sexo;
    
    
    cin >> n;
    
    while(n > c){
		cin >> alt;
		cin >> sexo;
		
		if (alt > maiorAlt){
			maiorAlt = alt;
		}
		if (alt < menorAlt){
			menorAlt = alt;
		}
		
		if (sexo == "m"){
			altM += alt; 
			m++;
		}else if(sexo == "f"){
			altF += alt;
			f++;
		}
		altT += alt;
		c++;
	}
    
    cout << maiorAlt << endl;
    cout << menorAlt << endl;
    
    if (altF == 0){
		cout << "erro" << endl;
	}else{
		altF = altF/f;
		cout << altF << endl;
	}
    
    
    if (altM == 0){
        cout << "erro" << endl;
    }else {
        altM = altM/ m;
        cout << altM << endl;
    }
    
    altT = altT/n;
    cout << altT << endl;
    
    return 0;
}
