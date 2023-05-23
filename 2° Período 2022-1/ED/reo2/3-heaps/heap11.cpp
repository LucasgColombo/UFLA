#include <iostream>

typedef unsigned CodProcesso;
typedef int PrioriProcesso;

class Heap{
	
	private:
		CodProcesso *mCodigo;
		PrioriProcesso *mPrioridade;
		unsigned int capacidade;
		int tamanho;
		
	public:
		Heap(int cap);
		~Heap();
		bool Inserir(CodProcesso codigo, PrioriProcesso prioridade);
		bool Retirar(CodProcesso* ptCodigo, PrioriProcesso* ptPrioridade);
		bool Vazia();
		
	protected:
		void ArrumarDescendo(int i);
		void ArrumarSubindo(int i);
		inline int Direito(int i);
		inline int Esquerdo(int i);
		inline int Pai(int i);
};

using namespace std;

Heap::Heap(int cap){
	
	capacidade = cap;
	tamanho = 0;
	mCodigo = new CodProcesso[capacidade];
	mPrioridade = new PrioriProcesso[capacidade];
	
	for(unsigned int i = 0; i < capacidade; i++){
		
		mCodigo[i] = 0;
		mPrioridade[i] = 0;
	}
}

Heap::~Heap(){
	
	delete[] mCodigo;
	delete[] mPrioridade;
}

int Heap::Pai(int i){
	
	return (i - 1)/2;
}

int Heap::Esquerdo(int i){
	
	return 2 * i + 1;
}

int Heap::Direito(int i){
	
	return 2 * i + 2;
}

bool Heap::Vazia(){
	
	return (tamanho == 0);
}

void Heap::ArrumarDescendo(int i) {
	
	int esq = Esquerdo(i);
	int dir = Direito(i);
	
	int maior = i;
	
	if((esq <= tamanho - 1) and (mPrioridade[esq] > mPrioridade[i]))
		maior = esq;
		
	if((dir <= tamanho - 1) and (mPrioridade[dir] > mPrioridade[maior]))
		maior = dir;
		
	if(maior != i){
		
		swap(mPrioridade[i], mPrioridade[maior]);
		swap(mCodigo[i], mCodigo[maior]);
		
		ArrumarDescendo(maior);
	}
}

void Heap::ArrumarSubindo(int i) {
	
	int p = Pai(i);
	
	if((p >= 0) and (mPrioridade[i] > mPrioridade[p])){
		
		swap(mPrioridade[i], mPrioridade[p]);
		swap(mCodigo[i], mCodigo[p]);
		
		ArrumarSubindo(p);
	}
}

bool Heap::Retirar(CodProcesso* ptCodigo, PrioriProcesso* ptPrioridade) {
	
	if(Vazia())
		return false;
		
	else{
		
		*ptPrioridade = mPrioridade[0];
		*ptCodigo = mCodigo[0];
		
		swap(mPrioridade[0], mPrioridade[tamanho - 1]);
		swap(mCodigo[0], mCodigo[tamanho - 1]);
		
		tamanho--;
		ArrumarDescendo(0);
		
		return true;
	}
}

bool Heap::Inserir(CodProcesso codigo, PrioriProcesso prioridade) {
	
	if(unsigned(tamanho) == capacidade)
		return false;
		
	else{
		
		mCodigo[tamanho] = codigo;
		mPrioridade[tamanho] = prioridade;
		ArrumarSubindo(tamanho);
		tamanho++;
		
		return true;
	}
}

int main(){
	
	unsigned int capacidade;
	cin >> capacidade;
	
	Heap heap(capacidade);
	
	char comando;
	CodProcesso codigo;
	PrioriProcesso prioridade;
	
	do{
		
		cin >> comando;
		
		switch(comando){
			
			case 'i':
				cin >> codigo >> prioridade;
				heap.Inserir(codigo, prioridade);
				break;
				
			case 'o':
				if(heap.Retirar(&codigo, &prioridade))
					cout << codigo << ' ' << prioridade << endl;
				else
					cout << "Nao encontrado" << endl;
				break;
				
			case 's':
				break;
		}
	}while(comando != 's');
	
	return 0;
}
