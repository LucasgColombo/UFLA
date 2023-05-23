#include <iostream>

using namespace std;

struct passageiro{
    string cpf;
    string nome;
    int telefone;
};

class nohFila{
    friend class fila;
    private:
        passageiro dado;
        nohFila *proximo;
    public:
        nohFila(passageiro adicionado);
};

nohFila :: nohFila(passageiro adicionado){
    dado = adicionado;
    proximo = NULL;
}

class fila{
    private:
        nohFila *inicio;
        nohFila * fim;
        int tamanho;
    public:
         fila();
		~fila();
        void enfilera(passageiro dado);
        passageiro desenfilera();
        int numero_de_elementos();

};

fila :: fila(){
    inicio = NULL;
    fim = NULL;
    tamanho = 0;
}

fila :: ~fila(){
    while(tamanho > 0){
        desenfilera();
    }
}

void fila :: enfilera(passageiro dado){
    nohFila *novo = new nohFila (dado);
    if(tamanho == 0){
        inicio = novo;
    }
    else{
        fim->proximo = novo;
    }
    fim = novo;
    tamanho++;
}

passageiro fila :: desenfilera(){
    nohFila *aux;
    passageiro desenfilerado = inicio ->dado;
    aux = inicio;
    inicio = inicio ->proximo;
    if(tamanho == 0){
        fim = NULL;
    }

    delete aux;
    tamanho --;
    return desenfilerado;

}

int fila :: numero_de_elementos(){
    return tamanho;
}

class assento{
    friend class lista;
    private:
        bool disponivel;
        int numb_assento;
        passageiro donoAssento;
        fila espera;
        assento *proximo;

    public:
        assento(int d);

};

assento :: assento(int d){
    disponivel = true;
    numb_assento = d;
    donoAssento.cpf = "VAZIO";
    donoAssento.nome = "VAZIO";
    donoAssento.telefone = 0;
}

class lista{
    private:
        assento *primeiro;
        assento *ultimo;
        int tamanho;
    public:
        lista();
        ~lista();
        void insereNoFim(int numbAssento);
        void imprimeIni();
        void adquireAssento(int posicao, passageiro novo);
        void cancelaPassagem(string cpf);
        void consultaDisponibilidade(int posicao);
        passageiro removeNoInicio();
        passageiro removeNaPosicao(int posicao);
        passageiro removeNoFim();
        int tamanhoLista();
};

lista :: lista(){
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

lista :: ~lista(){
    assento *aux = primeiro;
    assento *temp = NULL;

    while(aux != NULL){
        temp = aux;
        aux = aux->proximo;
        delete temp;
    }
    tamanho = 0;
}

void lista :: insereNoFim(int numbAssento){
    assento *novo = new assento(numbAssento);

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

void lista :: adquireAssento(int posicao,passageiro novo ){
    if(posicao < 1 or posicao > tamanho)
        cout << "ERRO";
    

    assento *aux = primeiro;
    int localizacao = 1;
    while(posicao > localizacao){
        aux = aux->proximo;
        localizacao++;
    }
    if(aux->disponivel){
        aux->donoAssento = novo;
        aux->disponivel = false;
    }
    else
        aux->espera.enfilera(novo);

}

void lista :: cancelaPassagem(string cpf){
    assento *aux = primeiro;

    while(cpf != aux->donoAssento.cpf){
        aux = aux->proximo;
    }
    if(aux->espera.numero_de_elementos() > 0)
        aux->donoAssento = aux->espera.desenfilera();
    else{
        aux->disponivel = true;
        aux->donoAssento.cpf = "VAZIO";
        aux->donoAssento.nome = "VAZIO";
        aux->donoAssento.telefone = 0;
    }

}

void lista ::consultaDisponibilidade(int posicao){
    assento *aux = primeiro;
    int localizacao = 1;
    while(posicao > localizacao){
        aux = aux->proximo;
        localizacao++;
    }
    if(aux->disponivel)
        cout << "Disponivel" << endl;
    
    else
        cout << "Ocupado - Espera:" << aux->espera.numero_de_elementos() <<endl;
}

void lista :: imprimeIni(){
    assento *aux = primeiro;
    while(aux != NULL){
        cout << aux->numb_assento << ' ' << aux->donoAssento.cpf << ' ' << aux->donoAssento.nome << ' ' << aux->donoAssento.telefone << endl;
        aux = aux->proximo;
    }
    cout << endl;

}


int main(){

    bool t = true;
    int opcao, assentoEscolhido;
    string cpf;

    lista passageiros;
    passageiro novo;


    for(int i = 1; i <= 200;i++)
        passageiros.insereNoFim(i);

    
    while(t){
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            cin >> assentoEscolhido;

            cin >> novo.cpf;
            cin.ignore();
            getline(cin,novo.nome);
            cin >> novo.telefone;
            passageiros.adquireAssento(assentoEscolhido,novo);
            break;
        case 2:
            cin >> cpf;
            passageiros.cancelaPassagem(cpf);
            break;

        case 3:
            cin >> assentoEscolhido;
            passageiros.consultaDisponibilidade(assentoEscolhido);

            break;
        default:
            t = false;
            break;
        }
    }
    
    passageiros.imprimeIni();

    return 0;
}
