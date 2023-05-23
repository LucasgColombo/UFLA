#include <iostream>

using namespace std;
class noh {
    friend class listaDupla;
    private:
        int dado;
        noh *proximo;
        noh *antecessor;

    public:
        noh(int d);

};

noh :: noh(int d){
    dado = d;
    proximo = NULL;
    antecessor = NULL;
}

class listaDupla{
    private:
        noh *primeiro;
        noh *ultimo;
        int tamanho;
    public:
        listaDupla();
        ~listaDupla();
        void insereNoFim(int dado);
        void imprimeIni();
        void imprimeReverso();
        void removeNoInicio();
        void removeNaPosicao(int posicao);
        void removeNoFim();
        void removeRepetidos();
};

listaDupla :: listaDupla(){
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

listaDupla :: ~listaDupla(){
    noh *aux = primeiro;
    noh *temp;

    while(aux != NULL){
        temp = aux;
        aux = aux->proximo;
        delete temp;
    }
    tamanho = 0;
}

void listaDupla :: insereNoFim(int dado){
    noh* novo = new noh(dado);

    if(tamanho == 0){
        primeiro = novo;
        ultimo = novo;
    }
    else{
        ultimo->proximo = novo;
        novo->antecessor = ultimo;
        ultimo = novo;
    }
    tamanho++;

}

void listaDupla :: imprimeIni(){
    noh * aux = primeiro;

    while(aux != NULL){
        cout << aux->dado << ' ';
        aux = aux->proximo;
    }
    cout << endl;
}

void listaDupla :: imprimeReverso(){
    noh *aux = ultimo;
    while (aux != NULL){
        cout << aux->dado << ' ';
        aux = aux->antecessor;
    }
    cout << endl;
}

void listaDupla :: removeNoInicio(){
    if(tamanho == 0)
        cout << "ERRO" << endl;
    noh *aux =primeiro;
    noh *temp = NULL;
    int val = aux->dado;
    temp = aux->antecessor;
    primeiro = aux->proximo;
    primeiro->antecessor = temp;
    delete aux;
    delete temp;
    tamanho --;
    
    if(tamanho == 0)
        ultimo = NULL;
    
}

void listaDupla :: removeNoFim(){
    if(tamanho == 0)
        cout << "ERRO";

    noh *aux = ultimo;
    noh *temp = NULL;   
    
    temp = aux->proximo;
    ultimo = aux->antecessor;
    ultimo->proximo = temp;
    delete aux;
    delete temp;
    tamanho --;
} 

void listaDupla :: removeNaPosicao(int valor){
    noh *aux = primeiro;
    noh *anterior = NULL;

    while((aux != NULL) and (aux->dado == valor)){
        anterior = aux;
        aux = aux->proximo;
    }
    if(aux != NULL){
        if(aux == primeiro)
            removeNoInicio();
        else if(aux == ultimo)
            removeNoFim();
        else{
            anterior->proximo = aux->proximo;
            anterior->antecessor = aux->antecessor;
            tamanho--;
            delete aux;
        }
    }
}

void listaDupla :: removeRepetidos(){
    noh *aux = primeiro;
    noh *temp = primeiro;

    while(aux != NULL){

    }

}

int main(){

    int dado,tam;
    listaDupla minhaLista;
    
    cin >> tam;
    for(int i = 0; i < tam; i++){
        cin >> dado;
        minhaLista.insereNoFim(dado);
    }
    minhaLista.removeRepetidos();

    minhaLista.imprimeIni();
    minhaLista.imprimeReverso();

    return 0;
}