#include <iostream>

using namespace std;

typedef int Dado;

class noh {
    friend class lista;
    private:
        const Dado dado;
        noh* proximo;
    public:
        noh(Dado d = 0);
};

noh::noh(Dado d) : dado(d) {
    proximo = NULL;
}

class lista {
    private:
        noh* primeiro;
        noh* ultimo;
        int tamanho;
    public:
        lista();
        ~lista();
        void insereVazia(Dado dado);
        void insereInicio(Dado dado);
        void insere(Dado dado);
        void insere(Dado dado, int pos);
        void removeInicio();
        void removeFim();
        void remove(int posicao);
        int procura(Dado valor);
        void imprime();
        bool vazia();
};

// constrói uma lista inicialmente vazia
lista::lista() {
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

lista::~lista() {
    noh* iter = primeiro;
    noh* proximo = NULL;
    while (iter != NULL) {
        proximo = iter->proximo;
        delete iter;
        iter = proximo;
    }
}

// método básico que *percorre* a lista, imprimindo seus elementos
void lista::imprime() {
    noh* aux = primeiro;
    while (aux != NULL) {
        cout << aux->dado << " ";
        aux = aux->proximo;
    }
    cout << endl;
}

//Metodo pra inserir em lista vazia
void lista :: insereVazia(Dado dado){
    noh* novo = new noh(dado);
    primeiro = novo;
    ultimo = novo;
    tamanho =1;
}

//Metodo pra inserir no inicio

void lista :: insereInicio(Dado dado){
    if(tamanho == 0){
        insereVazia(dado);
    }
    else{
        noh *novo = new noh(dado);
        novo->proximo = primeiro;
        primeiro = novo;
        tamanho++;
    }
}

// insere por padrão no final da lista
void lista::insere(Dado dado) {
    if(tamanho == 0)
        insereVazia(dado);
    else{
        noh *novo = new noh(dado);
        ultimo->proximo = novo;
        ultimo = novo;
        tamanho++;
    }
}

// insere um dado em uma determinada posição da lista
void lista::insere(Dado dado, int posicao) {
    if(tamanho == 0){
        insereVazia(dado);
    }
    else if(posicao == 0){
        insereInicio(dado);
    }
    else if(posicao == tamanho){
        insere(dado);
    }
    else{
        noh *novo = new noh(dado);
        noh *aux = primeiro;
        int posAux = 0;
        while(posAux < posicao -1){
            aux = aux->proximo;
            posAux++;
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;
        tamanho++;
    }
}

// remove o item da posição passada por parâmetro
// Atenção - o código deve tratar de posição inválidas
void lista :: removeInicio(){
    if(vazia())
        cout << "ERRO";
    
    noh *aux = primeiro;
    primeiro = aux->proximo;
    delete aux;
    tamanho --;
    if(vazia())
        ultimo = NULL;
}

void lista :: removeFim(){
    if(vazia())
        cout << "ERRO";
    
    noh *aux = primeiro;
    noh *anterior = NULL;
    while (aux->proximo != NULL){
        anterior = aux;
        aux = aux->proximo; 
    }
    if(anterior == NULL)
        primeiro = NULL;
    else
        anterior->proximo = NULL;
    
    delete ultimo;
    ultimo = anterior;
    tamanho--;
    
}

void lista::remove(int posicao) {
    int posNoh = 0;
    if(vazia()){
        cout << "ERRO";
    }

    noh *aux = primeiro;
    noh *anterior = NULL;
    while ((aux != NULL) and (posNoh != posicao)){
        anterior = aux;
        aux = aux->proximo;
        posNoh++;
    }
    if(aux != NULL){
        if(aux == primeiro){
            removeInicio();
        }
        else if(aux == ultimo){
            removeFim();
        }
        else{
            anterior->proximo = aux->proximo;
            tamanho--;
            delete aux;
        }
    }
    else{
        cout << "ERRO";
    }
}

// procura por um elemento e retorna a posição ou -1 se não encontrado
int lista::procura(Dado valor) {
    noh *aux = primeiro;
    int procurado = 0;
    while(aux != NULL){
        if(aux->dado == valor){
            aux = NULL;
        }
        else{
            aux = aux->proximo;
            procurado++;
        }
    }
    if(procurado == tamanho)
        procurado = -1;

    return procurado;
}

// verifica se a lista está vazia
bool lista::vazia() {
    bool vazia;
    if(tamanho == 0)
        vazia = true;
    else
        vazia = false;
    
    return vazia;
}

int main() { // NÃO MODIFIQUE!
    lista minhaLista;
    char opcao;
    int valor, pos;
    cin >> opcao;
    while (opcao != 'Q') {
        switch(opcao) {
            case 'I':
                cin >> valor;
                minhaLista.insere(valor);
                break;
            case 'W':
                cin >> valor;
                cin >> pos;
                minhaLista.insere(valor, pos);
                break;
            case 'P':
                cin >> valor;
                cout << minhaLista.procura(valor) << endl;
                break;
            case 'R':
                cin >> pos;
                minhaLista.remove(pos);
                break;
            case 'V':
                cout << minhaLista.vazia() << endl;
                break;
        }
        cin >> opcao;
    }
    minhaLista.imprime();
    return 0;
}