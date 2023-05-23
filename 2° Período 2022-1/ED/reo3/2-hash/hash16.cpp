#include <iostream>
#include <exception>
#include <cstring>

using namespace std;

struct dado {
    string chave;
    int valor;
};

bool operator==(const dado& d1, const dado& d2) {
    return (d1.chave == d2.chave and d1.valor == d2.valor);
}

bool operator!=(const dado& d1, const dado& d2) {
    return (d1.chave != d2.chave or d1.valor != d2.valor);
}

const int UMPRIMO = 13;
const dado INVALIDO = {"",-1};
const dado REMOVIDO = {"",-2};
const int POSINVALIDA = -1;

class hashEA {
    private:
        // Retorna a posição em que uma chave deveria ficar na estrutura
        // Usa função de hash para calcular a posição
        unsigned posicao(const string& chave);
        // Retorna a posicao em que uma chave está armazenada na estrutura
        // (retorna -1 caso chave não esteja presente)
        int buscarChave(const string& chave);
        // Vetor de dados
        dado* vetDados;
        unsigned capacidade;
        unsigned tamanho;
    public:
        hashEA(unsigned cap = 50); // usa valor default se não informado
        ~hashEA();
        // Mostra todos as posições de armazenamento da hash
        void depurar();
        // Insere uma cópia do valor. Não permite inserção de chave repetida
        void inserir(const string& chave, const int& valor);
        // Remove um item da hash associado com a chave dada
        void remover(const string& chave);
        // Retorna o valor associado a uma chave
        int consultar(const string& chave);
};


hashEA::hashEA(unsigned cap) {
// ** implementar! **
// => não se esqueça de marcar os dados em cada posição da tabela como inválidos
    capacidade = cap;
    tamanho = 0;
    vetDados = new dado[cap];

    for(unsigned i=0; i<capacidade; i++){
        vetDados[i] = INVALIDO;
        
    }

}

hashEA::~hashEA() {
    delete[] vetDados;
}

unsigned hashEA::posicao(const string& chave) {
    // ** não altere este método! **
    // Retorna a posição de armazenamento de uma chave, sem colisão
    unsigned pos = 1;
    for (unsigned i = 0; i < chave.size(); i++)
        pos = UMPRIMO * pos + chave[i];
    return pos % capacidade;
}

int hashEA::buscarChave(const string& chave) {
// ** implementar! **
    // Retorna a posicao em que uma chave está armazenada na estrutura
    // Retorna POSINVALIDA quando chave não está na tabela hash
    unsigned Posicao = posicao(chave);
    unsigned posFinal = Posicao;

    do{
        dado umDado = vetDados[Posicao];
        if(umDado == INVALIDO)
            return POSINVALIDA;
        if(umDado.chave == chave)
            return Posicao;
        Posicao = (Posicao + 1) % capacidade;    
    }while(Posicao != posFinal);

    return POSINVALIDA;
}



void hashEA::inserir(const string& chave, const int& valor) {
// ** implementar! **
    // Insere uma cópia do valor. Não permite inserção de chave repetida.
    if(chave.size() == 0){
        cout<<"Chave inválida"<<endl;
    }else if(tamanho == capacidade){
        cout<<"Tabela hash cheia"<<endl;
    }else if(buscarChave(chave) != POSINVALIDA){
        cout<<"Inserção de chave que já existe"<<endl;
    }else{
        unsigned Posicao = posicao(chave);

        while((vetDados[Posicao] != INVALIDO) and (vetDados[Posicao] != REMOVIDO))
            Posicao =  (Posicao + 1) % capacidade;

        vetDados[Posicao].chave = chave;
        vetDados[Posicao].valor = valor;

        tamanho++; 
    }
    
}

void hashEA::depurar() {
    // ** não altere este método! **
    // Mostra todos as posições de armazenamento da hash.
    for (unsigned i = 0; i < capacidade; ++i) {
        cout << '[' << i << ":";
        if (vetDados[i] != INVALIDO) {
            if (vetDados[i] == REMOVIDO)
                cout << "REMOVIDO";
            else
                cout << vetDados[i].chave << '/' << vetDados[i].valor;
        }
        cout << "] ";
    }
}

void hashEA::remover(const string& chave) {
// ** implementar! **
    // Remove um dado com determinada chave da tabela hash
    if(tamanho == 0){
        cout<<"Impossível remover de hash vazia"<<endl;
    }else{
        int posicao = buscarChave(chave);
        if(posicao == POSINVALIDA){
            cout<<"Chave não encontrada para remoção"<<endl;
        }else{
            vetDados[posicao] = REMOVIDO;

            tamanho--;
        }
    }
}

int hashEA::consultar(const std::string& chave) {
// ** implementar! **
    // Retorna o valor associado a uma chave.
    int posicao = buscarChave(chave);

    if(posicao == POSINVALIDA){
         throw runtime_error ("Chave não encontrada para consulta");
    }else{
        int valorEncontrado = vetDados[posicao].valor;

        return valorEncontrado;
    }

}

int main() {
/* não altere a função principal */
    unsigned capacidade;
    cin >> capacidade;
    hashEA tabela(capacidade);
    char operacao;

    string chave;
    int valor;
    do {
        try {
            cin >> operacao;
            switch (operacao) {
                case 'i': // inserir
                    cin >> chave >> valor;
                    tabela.inserir(chave, valor);
                    break;
                case 'r': // remover
                    cin >> chave;
                    tabela.remover(chave);
                    break;
                case 'c': // consultar
                    cin >> chave;
                    valor = tabela.consultar(chave);
                    cout << valor << endl;
                    break;
                case 'd': // debug (mostrar estrutura)
                    tabela.depurar();
                    cout << endl;
                    break;
                case 'f': // finalizar
                    // vai testar depois
                    break;
                default:
                    cerr << "operação inválida" << endl;
            }
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
    } while (operacao != 'f');

    return 0;
}