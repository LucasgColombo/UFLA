#include <iostream>
#include <cmath>

using namespace std;

struct clientes {
	string nome;
	float x;
	float y;
	float valor;
	float dist;
};

void ordenacao (clientes lista[], int totalC){
	
	clientes pivo;
	int j;
	
	for(int i=1; i < totalC; i++){
		pivo = lista[i];
		j = i-1;
		
		while(j >= 0 and pivo.dist < lista[j].dist){
			lista[j+1] = lista[j];
			j--;
		}
		lista[j+1] = pivo;
	}
}

int main(){
    int atendidos, totalC;
    float xP, yP, soma=0;
    
    cin >> atendidos >> xP >> yP >> totalC;
    
    clientes lista[totalC];
    
    for (int i=0; i < totalC; i++){
		cin >> lista[i].nome;
		cin >> lista[i].x;
		cin >> lista[i].y;
		cin >> lista[i].valor;
	}
	
	for (int i=0; i < totalC; i++){
		lista[i].dist = sqrt(pow((xP - lista[i].x),2) + pow((yP - lista[i].y),2));
	}

	ordenacao(lista, totalC);
	
	 for (int i=0; i < atendidos; i++){
		soma += lista[i].valor;
	}
	
	cout << soma << endl;

    return 0;
}
