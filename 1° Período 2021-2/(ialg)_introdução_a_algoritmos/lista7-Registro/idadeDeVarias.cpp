#include <iostream>

using namespace std;

struct pessoa{
	string nome;
	int dia;
	int mes;
	int ano;
};

int main(){
	int PessoasT;
	
	cin >> PessoasT;
	
	pessoa lista[PessoasT];
	
	for (int i=0; i < PessoasT; i++){
		cin >> lista[i].nome; 
		cin >> lista[i].dia;
		cin >> lista[i].mes;
		cin >> lista[i].ano;
	}
	
	int diaR, mesR, anoR;
	
	cin >> diaR >> mesR >> anoR;
	
	for (int i=0; i < PessoasT; i++){
		if (lista[i].ano > anoR){
			cout << lista[i].nome << ": -1" << endl;
		}else if (lista[i].ano == anoR){
			if (lista[i].mes < mesR){
				cout << lista[i].nome << ": 0 ano" << endl;
			}else if (lista[i].mes == mesR){
				if(lista[i].dia <= diaR){
					cout << lista[i].nome << ": 0 ano" << endl;					
				}else {
					cout << lista[i].nome << ": -1" << endl;
				}
			}else {
				cout << lista[i].nome <<": -1" << endl;
			}
		}else {
			if((anoR - lista[i].ano) == 1){
				if (mesR < lista[i].mes){
					cout << lista[i].nome << ": 0 ano" << endl;
				}else {
					cout << lista[i].nome << ": 1 ano" << endl;
				}
			}else {
				if(lista[i].mes == mesR){
					if(lista[i].dia < diaR){
						cout << lista[i].nome << ": " << (anoR - lista[i].ano) << " anos" << endl;
					}else {
						cout << lista[i].nome << ": " << (anoR - lista[i].ano)+1 << " anos" << endl;
					}
				}else if (lista[i].mes < mesR){
					cout << lista[i].nome << ": " << (anoR - lista[i].ano) << " anos" << endl;
				}else {
					cout << lista[i].nome << ": " << (anoR - lista[i].ano)-1 << " anos" << endl;
				}
			}
		}
	}
	return 0;
}
