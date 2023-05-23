#include <iostream>

using namespace std;

class noh {
    friend class lista;
    private:
        int dado;
        noh *proximo;

    public:
        noh(int d);

};

noh :: noh(int d){
    dado = d;
    proximo = NULL;
}

class lista{
    private:
        noh *primeiro;
        noh *ultimo;
        int tamanho;
    public:
        lista();
        ~lista();
        lista& operator=(const lista& umaLista);    
        void insereNoFim(int dado);
        void imprimeIni();
        int removeNoInicio();
        int removeNaPosicao(int posicao);
        int removeNoFim();
        int tamanhoLista();
        lista novaLista(int divisor,lista &minhaLista);
};

lista :: lista(){
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

lista :: ~lista(){
    noh *aux = primeiro;
    noh *temp;

    while(aux != NULL){
        temp = aux;
        aux = aux->proximo;
        delete temp;
    }
    tamanho = 0;
}

lista& lista ::operator=(const lista& umaLista){
    noh *aux = umaLista.primeiro;

    while (aux !=NULL){
        insereNoFim(aux->dado);
        aux = aux->proximo;
    }
    return *this;
}

void lista :: insereNoFim(int dado){
    noh* novo = new noh(dado);

    if(tamanho == 0){
        primeiro = novo;
        ultimo = novo;
    }
    else{
        ultimo->proximo = novo;
        ultimo = novo;
    }
    tamanho++;
}

void lista :: imprimeIni(){
    noh * aux = primeiro;

    while(aux != NULL){
        cout << aux->dado << ' ';
        aux = aux->proximo;
    }
    cout << endl;
}

int lista :: removeNoInicio(){
    if(tamanho == 0)
        cout << "ERRO" << endl;
    noh *aux =primeiro;
    int val = aux->dado;
    primeiro = aux->proximo;
    delete aux;
    tamanho --;
    
    if(tamanho == 0)
        ultimo = NULL;
    
    return val;
}

int lista :: removeNoFim(){
    if(tamanho == 0)
        cout << "ERRO";

    noh *aux = primeiro;
    noh *anterior = NULL;   
    
    while(aux->proximo != NULL){
        anterior = aux;
        aux = aux->proximo;
    }
    int val = aux ->dado;   
    
    if(anterior == NULL)
        primeiro = NULL;
    else
        anterior->proximo = NULL;
    delete aux;
    ultimo = anterior;
    tamanho --;
    return val;
} 

int lista :: removeNaPosicao(int posicao){
    noh *aux = primeiro;
    noh *anterior = NULL;
    int valor = 0 ,percorrido = 0;

    
    while((aux != NULL) and (percorrido != posicao)){
        anterior = aux;
        aux = aux->proximo;
        percorrido++;
    }
    if(aux != NULL){
        if(aux == primeiro)
           valor = removeNoInicio();
        else if(aux == ultimo)
           valor =  removeNoFim();
        else{
            valor = aux->dado;
            anterior->proximo = aux->proximo;
            tamanho--;
            delete aux;
        }
    }
    return valor;
}

int lista :: tamanhoLista(){
    return tamanho;
}


lista lista :: novaLista(int divide, lista &minhaLista){
    lista auxiliar;
    for(int i = 0; i < minhaLista.tamanhoLista() - divide + 1 ;i++){
        auxiliar.insereNoFim(minhaLista.removeNaPosicao(divide + 1));
    }
    return auxiliar;
}

int main(){

    int dado, tam, divide;
    lista minhaLista;
    lista lista2;
    cin >> tam;
    for(int i = 0; i < tam;i++ ){
        cin >> dado;
        minhaLista.insereNoFim(dado);        
    }
    cin >> divide;
    if(divide > minhaLista.tamanhoLista()-1){
        minhaLista.imprimeIni();
        cout << -1;
    }
    else if(divide == minhaLista.tamanhoLista()-1){
        minhaLista.imprimeIni();
        cout << endl;
    }
    else{
        lista2 = minhaLista.novaLista(divide,minhaLista);
        minhaLista.imprimeIni();
        lista2.imprimeIni();
    }
    return 0;
}
