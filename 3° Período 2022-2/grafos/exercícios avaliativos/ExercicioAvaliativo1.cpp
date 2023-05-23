/*
A lógica do algoritmo consiste em aplicar uma busca por profundidade ao grafo
e armazenar o pai de cada vértice, caso o vértice não possua pai ele não é
possível alcança-lo a partir de outro vértice logo para cada um que não possui
pai é necessario um novo interruptor

Lucas Gomes Colombo 202120795
Rafael Brunini Pereira 202120488
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

#define n_visitado 0

typedef vector<int>vi;

void dfsVisita(int u,int *d, int *pai,vi *LA,int &cont_dfs){   

    for(auto it = LA[u].begin(); it != LA[u].end(); it++)
    {   
        d[u] = cont_dfs++;
        int v = *it;
        if(find(LA[u].begin(), LA[u].end(), v) != LA[u].end() and !(find(LA[v].begin(), LA[v].end(), u) != LA[v].end())){
                pai[v] = u;
        }
        if(d[v] == n_visitado){
                pai[v] = u;
                dfsVisita(v,d,pai,LA,cont_dfs);
        }
    }
    
}

int main(){
    int n,m; // n -> vertices, m -> arestas
    int u,v; // direção da incidencia da aresta 
    int count = 0,qtd_testes; // count -> interruptores necessários, qtd_testes -> numero de execuções do algoritmo

    cin >> qtd_testes;
    int *resultados = new int[qtd_testes];
    for(int j = 0; j < qtd_testes;j++){
        cin >> n >> m;
        int* pai = new int[n+1]; // armazena o pai de cada vertice
        int* d = new int[n+1]; // armazena se foi ou não visitado
        vi *LA = new vi[n+1];
        int cont_dfs = 1;

        for(int i = 1; i <= n ;i++){
            d[i] = n_visitado;
            pai[i] = -1;
        }

        for(int i = 0; i < m; i++){
            cin >> u >> v;
            if(find(LA[u].begin(), LA[u].end(), v) != LA[u].end()){
                continue;
            }           
            LA[u].push_back(v);
        }
        
        for(int i = 1; i <= n ;i++){
            if(d[i] == n_visitado){
                dfsVisita(i,d,pai,LA,cont_dfs);
            } 
        }
        for(int i = 1; i <= n; i++){
            if(pai[i] == -1)
                count++;
         }
        if(count == 0) // Se count é zero significa q a necessidade de ao menos um interruptor
            count = 1;
        resultados[j] = count;
        count = 0;

        delete []d;
        delete []pai;
        delete []LA;
    }

    for(int i = 0; i < qtd_testes;i++)
        cout << resultados[i] << endl;

    return 0;
}

