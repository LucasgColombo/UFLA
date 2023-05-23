/*
Codigo por Rafael Brunini Pereira turma 10A
Estrutura de Dados
2022
*/
#include <iostream>

using namespace std;

class noh {
    friend class listaDupla;
    private:
        string dado;
        noh *proximo;
        noh *antecessor;

    public:
        noh(string d);

};

noh :: noh(string d){
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
        void insereNoFim(string dado);
        void inverte();
        void imprimeIni();
        void imprimeReverso();
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

void listaDupla :: insereNoFim(string dado){
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

void listaDupla :: inverte(){
    noh *aux = primeiro;
    noh *temp = NULL;

    while(aux != NULL){
        temp = aux->antecessor;
        aux->antecessor = aux->proximo;
        aux->proximo = temp; 
        aux = aux->antecessor;
    }
    temp = primeiro;
    primeiro = ultimo;
    ultimo = temp;

}

int main(){

    char opcao;
    bool t = true;
    string dado;
    listaDupla minhaLista;
    while (t)
    {
        cin >> opcao;
        switch (opcao){
        case 'I':
            cin >> dado;
            minhaLista.insereNoFim(dado);
            break;
        
        case 'X':
            minhaLista.inverte();
            break;

        case 'P':
            minhaLista.imprimeIni();
            break;

        case 'R':
            minhaLista.imprimeReverso();
            break;
        
        case 'Q':
            minhaLista.imprimeIni();
            minhaLista.imprimeReverso();
            t = false;
            break;

        default:
            break;
        }
    }
    return 0;
}