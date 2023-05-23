#include <iostream>

using namespace std;

class Fila{
	private:
		int ini;
		int fim;
		int tam;
		int cap;
		int *vetor;
	public:
		Fila(int capacidade);
		~Fila();
		void enfileirar();
		void desenfileirar();
		void imprimir();
		void vazia();
};

Fila::Fila(int capacidade){
	cap = capacidade;
	tam = 0;
	ini = 0;
	fim = 0;
	vetor = new int[cap];
}

Fila::~Fila(){
	delete [] vetor;
}

void Fila::vazia(){
	ini = 0;
	fim = 0;
}

void Fila::enfileirar(){
	int valor;
	cin >> valor;
	
	if(tam < cap){
		if(tam == 0)
			vazia();
		else
			fim = (fim+1)%cap;
		vetor[fim] = valor;
		tam++;
	}
}

void Fila::desenfileirar(){
	if(tam > 0){
		cout << vetor[ini] << endl;
		tam--;
		ini = (ini+1)%cap;
	}
}

void Fila::imprimir(){
	cout << "tamanho=" << tam
		 << " capacidade=" << cap
		 << " inicio=" << ini
		 << " fim=" << fim << endl;
	int aux;
	if(ini > fim)
		aux = fim;
	else
		aux = ini;
	for(int i=0; i<tam; i++){
		cout << vetor[i+aux] << " ";
	}
	cout << endl;
}

int main(){
	int tam;
	cin >> tam;
	Fila fila = Fila(tam);
	char opcao;
	cin >> opcao;
	while(opcao != 't'){
		switch(opcao){
			case 'e':
				fila.enfileirar();
				break;
			case 'd':
				fila.desenfileirar();
				break;
			case 'i':
				fila.imprimir();
				break;
			case 't':
				break;
			default:
				break;
		}
		cin >> opcao;
	}
	

	return 0;
}
