#include <iostream>

using namespace std;

class noh{
	
	friend class deque;
	
	private:
		string comando;
		noh* proximo;
		noh* anterior;
		
	public:
		noh(string c = 0);
};

noh::noh(string c){
	
	comando = c;
	proximo = NULL;
	anterior = NULL;
}

class deque{
	
	private:
		noh* esq;
		noh* dir;
		int tamanho;
		int capacidade;
		void removerTodos();
		
	public:
		deque(int tam);
		~deque();
		void inserirNaEsquerda(string comando);
		void inserirNaDireita(string comando);
		string removerNaEsquerda();
		string removerNaDireita();
		void undo();
};

deque::deque(int cap){
	
	tamanho = 0;
	capacidade = cap;
	esq = NULL;
	dir = NULL;
}

deque::~deque(){
	
	removerTodos();
}

void deque::removerTodos(){
	
	noh* aux = esq;
	noh* temp;
	
	while(aux != NULL){
		
		temp = aux;
		aux = aux->proximo;
		delete temp;
	}
	
	tamanho = 0;
	capacidade = 0;
	esq = NULL;
	dir = NULL;
}

void deque::inserirNaDireita(string comando){
	
	if(tamanho != capacidade){
		
		noh* novo = new noh(comando);
		
		if(tamanho == 0){
			
			esq = novo;
			dir = novo;
		}
		
		else{
			
			dir->proximo = novo;
			novo->anterior = dir;
			dir = novo;
		}
		
		tamanho++;
	}
	
	else{
		
		string removido = removerNaEsquerda();
		
		cout << "esqueci: comando " << removido << endl;
		
		noh* novo = new noh(comando);
		
		dir->proximo = novo;
		novo->anterior = dir;
		dir = novo;
	}
}

void deque::inserirNaEsquerda(string comando){
	
	noh* novo = new noh(comando);
	
	if(tamanho == 0){
		
		esq = novo;
		dir = novo;
	}
	
	else{
		
		novo->proximo = esq;
		esq->anterior = novo;
		esq = novo;
	}
	
	tamanho++;
}

string deque::removerNaDireita(){
	
	if(tamanho == 0){
		
		cerr << "Remoção em lista vazia!" << endl;
		exit(EXIT_FAILURE);
	}
	
	noh* aux = dir;
	string dado = aux->comando;
	dir = dir->anterior;
	
	if(dir != NULL)
		dir->proximo = NULL;
		
		
	delete aux;
	
	tamanho--;
	
	if(tamanho == 0)
		esq = NULL;
		
	return dado;
}

string deque::removerNaEsquerda(){
	
	if(tamanho == 0){
		
		cerr << "Remoção em lista vazia!" << endl;
		exit(EXIT_FAILURE);
	}
	
	noh* aux = esq;
	string dado = aux->comando;
	esq = esq->proximo;
	
	if(esq != NULL)
		esq->anterior = NULL;
		
	delete aux;
	
	tamanho--;
	
	if(tamanho == 0)
		dir = NULL;
		
	return dado;
}

void deque::undo(){
	
	if(tamanho == 0)
		cout << "ERRO" << endl;
		
	else{
		
		string result = removerNaDireita();
		
		cout << "desfazer: comando " << result << endl;
	}
}

int main(){
	
	int quant;
	cin >> quant;
	
	deque controle(quant);
	
	string escolha, comando;
	
	while(escolha != "sair") {
		cin >> escolha;
		
		if(escolha == "comando"){
			
			cin >> comando;
			controle.inserirNaDireita(comando);
		}
		
		else if(escolha == "undo")
			controle.undo();
		
	}
	
	return 0;
}
