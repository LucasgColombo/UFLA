#include <iostream>

using namespace std;

bool existe(string palavra, string frase, int &posi){
	int tamf = (int)frase.size(), tamp = (int) palavra.size();
	int teste[tamp];
	int c;
	bool x;

	if( tamp > tamf ){
		return false;
	}
	
	for(int i=0; i <= tamf - tamp; i++){
		if(frase[i]==palavra[0]){
			posi=i;
			for(int j=0; j < tamp; j++){
				teste[j]=0;
			}

			c=i;
			for(int k=0; k < tamp ;k++){
				if(palavra[k]==frase[c]){
					teste[k]=1;
					c++;
				}
			}

			x=true;
			for(int z=0 ; z < tamp; z++){
				if(teste[z]==0){
					x=false;
				}
			}

			if(x){
				return true;
			}
        }
    }
    return false;
}

int main(){
	string frase;
	string palavra;
	int posi=0;

	cin >> frase >> palavra;
	
	if(existe(palavra,frase,posi)){
		cout<<posi;
	}else{
		cout<<-1;
	}
	return 0;
}
