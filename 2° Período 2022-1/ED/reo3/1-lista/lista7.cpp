#include <iostream>

using namespace std;

class noh {
    friend class listaDupla;

    private:
        noh *proximo;
        noh *anterior;
        int dado;

    public:
        noh(int Dado);
};

noh::noh(int Dado = 0) {
    dado = Dado;
    proximo = NULL;
    anterior = NULL;
} 

class listaDupla{
    private:
        int tamanho;
        noh *primeiro;
        noh *ultimo;

    public:
        listaDupla();
        ~listaDupla();
        void InsereNoFim(int Dado);
        void Remove(int Dado);
        bool vazia();
        void Imprime();
        void ImprimeReverso();
};

listaDupla::listaDupla() {
    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
}

listaDupla::~listaDupla() {
    noh *atual = primeiro;
    noh *temp = NULL;

    while (atual->proximo != NULL)
    {
        temp = atual;
        atual = atual->proximo;
        delete temp;
    }
}

void listaDupla::InsereNoFim(int Dado) {
    noh *novoNoh = new noh(Dado);
    
    if(primeiro == NULL) {
        primeiro = novoNoh;
        ultimo = novoNoh;
    }
    else {
        ultimo -> proximo = novoNoh;
        novoNoh -> anterior = ultimo;
        ultimo = novoNoh;
    }
    tamanho++;
}

void listaDupla::Remove(int Dado) {
    noh *compara = primeiro;
    noh *aux, *aux2, *aux3;

    while (compara->proximo != NULL) {
        aux = compara->proximo;

        if (aux->proximo == NULL) {
            if (Dado == aux->dado) {
                aux2 = aux->anterior;
                aux2->proximo = NULL;
                ultimo = aux2;
                tamanho--;
            }
        }

        while (aux->proximo != NULL) {
            if (Dado == aux->dado) {
                aux2 = aux->anterior;
                aux3 = aux->proximo;
                aux2->proximo = aux3;
                aux3->anterior = aux2;
                tamanho--;
                aux = aux2;
            }

            aux = aux->proximo;

            if (aux->proximo == NULL) {
                if (Dado == aux->dado) {
                    aux2 = aux->anterior;
                    aux2->proximo = NULL;
                    ultimo = aux2;
                    tamanho--;
                }
            }
        }
        if (compara->proximo != NULL) {
            compara = compara->proximo;
        }
    }
}

bool listaDupla::vazia() {
    return (tamanho == 0);
}

void listaDupla::Imprime() {
    noh *elemento = primeiro;
    
    while(elemento != NULL){
        cout << elemento->dado << " ";
        elemento = elemento->proximo;
    }
    cout << endl;
}

void listaDupla::ImprimeReverso() {
    noh *elemento = ultimo;
    
    while(elemento != NULL){
        cout << elemento->dado << " ";
        elemento = elemento->anterior;
    }
}

int main()
{
    listaDupla lista;
    int tamLista;
    int valor;

    cin >> tamLista;

    for (int i = 0; i < tamLista; i++) {
        cin >> valor;
        lista.InsereNoFim(valor);
    }

    int quantParaRemover;
    int elementos;

    cin >> quantParaRemover;

    for (int i=0; i < quantParaRemover; i++) {
        cin >> elementos;
        lista.Remove(elementos);
    }

    lista.Imprime();
    lista.ImprimeReverso();

    return 0;
}