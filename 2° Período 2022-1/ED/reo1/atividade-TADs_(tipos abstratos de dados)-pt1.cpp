/*
-
-
- renato não consegui fazer a expansão dinâmica do vetor no tempo da aula.
- tentarei terminar em casa, e caso tenha alguma duvida te aviso 
-
-
*/
#include <iostream>
#include <cstdlib>

using namespace std;

struct papeis {
    string nomeMusicas;
    string nomeCompositores;
    string estilosMusicais;
    string tiposDocumentos;
};

struct colegas {
    string nomeArtistas;
    string tipoInstrumentos;
    string estiloArtistas;

};

class euterpe { //é o nome da mulher do enunciado

    private:
        papeis *partituras;
        colegas * amigos;
        int totalPartituras;
        int totalColegas;

    public:
        euterpe(int quantidadePartituras, int quantidadeColegas);
        ~euterpe();

        void cadastroPartitura();
        void cadastroColegas();
        int busca(string busca, bool x);
        //void imprime(int posi);

};

euterpe::euterpe(int quantidadePartituras, int quantidadeColegas){
    totalPartituras = quantidadePartituras;
    totalColegas = quantidadeColegas;
    partituras = new papeis [totalPartituras];
    amigos = new colegas [totalColegas];

};

euterpe::~euterpe(){
    delete[] partituras;
    delete[] amigos;
    totalPartituras = 0;
    totalColegas = 0;
};

void euterpe::cadastroPartitura(){

    for(int i=0; i < totalPartituras; i++){
        cout << "------CADASTRO DAS PARTITURAS------" << endl;

        cout << "Insira o nome da musica" << endl;
        getline(cin, partituras[i].nomeMusicas);
        cin.ignore(0, '\n');

        cout << "Insira o nome dos compositores" << endl;
        getline(cin, partituras[i].nomeCompositores);
        cin.ignore(0, '\n');

        cout << "Insira o estilo musical" << endl;
        getline(cin, partituras[i].estilosMusicais);
        cin.ignore(0, '\n');

        cout << "Insira o tipo de partitura(partitura, tablatura, cifra)" << endl;
        getline(cin, partituras[i].tiposDocumentos);
        cin.ignore(0, '\n');

        cout << endl;

    }
};

void euterpe::cadastroColegas(){

    for(int i=0; i < totalColegas; i++){       
        cout << "------CADASTRO DOS COLEGAS------" << endl;

        cout << "Insira o nome do artista" << endl;
        getline(cin, amigos[i].nomeArtistas);
        cin.ignore(0, '\n');

        cout << "Insira o nome dos instrumentoss" << endl;
        getline(cin, amigos[i].tipoInstrumentos);
        cin.ignore(0, '\n');

        cout << "Insira o estilo musical do artista/banda" << endl;
        getline(cin, amigos[i].estiloArtistas);
        cin.ignore(0, '\n');

    }
};

int euterpe::busca(string busca, bool x){
    for(int i=0; i < totalPartituras; i++){
        if(busca == partituras[i].estilosMusicais){
            x = true;
            cout << "Aqui estao as musicas com esse estilo" << endl;
            cout << "Nome: " << partituras[i].nomeMusicas << endl;
            cout << "Compositores: " << partituras[i].nomeCompositores << endl;
            cout << "Tipo de documento: " << partituras[i].tiposDocumentos << endl;
        }
    }

    if (x = false){
        cout << "estilo não encontrado" << endl;
    }
}


int main(){

    int quantidadePartituras, quantidadeColegas;

    cout <<"Quantas partituras voce deseja cadastrar inicialmente?"<< endl;
    cin >> quantidadePartituras;
    cout <<"Quantos colegas voce deseja registrar inicialmente?"<< endl;
    cin >> quantidadeColegas;
    cin.ignore(1,'\n');

    euterpe *ptr = new euterpe(quantidadePartituras, quantidadeColegas);
    ptr->cadastroPartitura();
    ptr->cadastroColegas();


    string busca;
    bool x = false;

    if (quantidadePartituras > 0){
        cout << "Qual o estilo de musica voce deseja buscar?" << endl;
        getline(cin, busca);
        x = ptr->busca(busca, x);
        //ptr->imprime(posi);
        
    }

    ptr->~euterpe();

    return 0;
}