#include <iostream>

using namespace std;

int main() {
	
	int n, cont=0, maior=0, segundoMaior=0, media=0;
	
	while(cont < 7){
		cin >> n;
		if (n > maior){
			segundoMaior = maior;
			maior = n;
		}else if (n > segundoMaior ) {
			segundoMaior = n;
		}
		media += n;
		cont++;
	}
	media = ((media - maior) - segundoMaior)/5;
	
	cout << maior << endl;
	cout << segundoMaior << endl;
	cout << media << endl;
	
	return 0;
}
