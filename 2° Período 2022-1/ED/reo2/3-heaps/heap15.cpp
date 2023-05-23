#include <iostream>   
#include <cstring>
using namespace std;

const int INVALIDO=0;

struct info {
	int original;
	int residuo;
};

class torneio{
private:
    info *heap;
    int capacidade;
    int tamanho;
    int inicioDados;
    inline int pai(int i);
    inline int esquerdo(int i);
    inline int direito(int i);
    void arruma();
    void copiaMaior(int i);
    void copiaSubindo(int i);
public: 
    torneio(info vet[],int tam);
    torneio(int numFolhas);
    ~torneio();
    void insere(info d);
    void imprime();
    info retiraRaiz();
};
torneio :: torneio (info vet[],int tam){
   capacidade = 1;
   while(capacidade < tam)
        capacidade *= 2;
        
    capacidade = capacidade-1 + tam;
    heap = new info[capacidade];
    inicioDados = capacidade - tam;
    
    memcpy(&heap[inicioDados], vet, tam*sizeof(info));
	
	tamanho = tam;
	arruma();
}

torneio :: torneio(int numFolhas){
   capacidade = 1;
   while(capacidade < numFolhas)
        capacidade *= 2;

   capacidade = capacidade - 1 + numFolhas;
   heap = new info[capacidade];
   inicioDados = capacidade - numFolhas;
   
    for(int i = 0; i < capacidade;i++){
        heap[i].residuo = INVALIDO;
   }
}

torneio ::~torneio(){
    delete[]heap;
}

void torneio :: arruma(){
    for(int i = inicioDados - 1 ; i >= 0 ; i--){
        copiaMaior(i);
    }
}
int torneio :: pai(int i){
    return (i-1)/2;
}
int torneio :: esquerdo(int i){
    return 2*i+1;
}

int torneio :: direito (int i){
	return 2*i+2;
}

void torneio :: copiaMaior(int i){
	//andar com o original
	//residuo no final
    int esq = esquerdo(i);
    int dir = direito(i);      
    int maior = -1;
	if(esq < capacidade){
		if((dir < capacidade) and (heap[dir].residuo > heap[esq].residuo)){
			maior = dir;
			heap[maior].residuo = heap[maior].residuo - heap[esq].residuo;
		}else{
			maior = esq;
			heap[maior].residuo = heap[maior].residuo - heap[dir].residuo;
		}
		heap[i].residuo = heap[maior].residuo;
		heap[i].original = heap[maior].original;
	} else {
		heap[i].residuo = INVALIDO;
	}
}

void torneio :: copiaSubindo(int i){
	int p = pai(i);
	if (heap[i].residuo > heap[p].residuo){
		heap [p] = heap [i];
		copiaSubindo(p);
	}
}

void torneio :: insere (info d){
	if (tamanho == capacidade){
		cerr << "Erro ao inserir" << endl;
		exit(EXIT_FAILURE);
	}
	heap[tamanho+inicioDados] = d;
	copiaSubindo (tamanho+inicioDados);
	tamanho++;
}

void torneio :: imprime(){
	cout << heap[0].original;
}

int main(){
	int tam;
	cin >> tam;
	info vet[tam];
	for (int i = 0; i < tam; i++){
		cin >> vet[i].original;
		vet[i].residuo = vet[i].original;
	}
	torneio *h = new torneio (vet, tam);
	
	h->imprime(); 
	
	delete h;
	
	return 0;
}