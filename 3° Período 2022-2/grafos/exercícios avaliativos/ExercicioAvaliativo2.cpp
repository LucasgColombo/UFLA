
//Lucas Gomes Colombo 202120795

#include<utility>
#include<vector>
#include<iostream>
#include <queue>
using namespace std;

typedef pair<int, int> ii; // pares de inteiros
typedef vector<int> vi; // vetor de inteiros
typedef vector<ii> vii; // vetor de pares de inteiros
/* variaveis globais */

// armazena a informacao se o vertice foi explorado ou nao
vi explorado;

// heap que armazena o vertices e suas prioridades a cada iteracao
priority_queue<ii> Q;

// lista de adjacencia
vector<vii> LA;

// numero de vertices
int n;

// numero de arestas
int m;

// funcao que atualiza a fila de prioridades
void atualizaFila(int u)
{
    explorado[u] = 1;
    for(int j = 0; j < int(LA[u].size()); j++)
    {
        ii v = LA[u][j];
        if(!explorado[v.first])
          /* valor: peso; chave: id do vertice
           * o valor negativo se deve ao fato de
           * que a heap do C++ eh implementada como
           * uma heap-max, e para desempate, prioriza-se
           * aqui o id de menor indice
           */
          Q.push(ii(v.second, v.first)); 
    }
}

int prim()
{
    explorado.assign(n, 0);
    atualizaFila(1);
    
    // custo da AGM
    int resultado = 200000;
 
 
    while(!Q.empty())
    {
        ii u = Q.top(); // O(1)
        Q.pop(); // O(logm)

        int w = u.first; // retirando o negativo cadastrado na heap
        int v = u.second;
     
        if(!explorado[v])
        {
          if(resultado >= w)
            resultado = w;         
          atualizaFila(v); // O(logm)
        }
    }
 
    return resultado;
}

int main()
{
  int maximo;
  cin >> maximo;
  for(int j = 0; j < maximo;j++){
    cin >> n >> m;
 
    for(int i = 0; i <= n; i++)
    {
        vii lista;
        LA.push_back(lista);
    }
        
    int u, v, w; // extremos das arestas, e peso de cada aresta
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        int contador = 0, continua = 0;
        for(vector<vii>::iterator it = LA.begin(); it != LA.end() && continua < 2; ++it)
        {
          if(contador == u) 
          {
            ii par1(v, w);
            (*it).push_back(par1);    
            continua++;
          }
       
          else if(contador == v)
          {
            ii par2(u, w);
            (*it).push_back(par2);    
            continua++;
          }
          contador++;
      }
    }
    cout << prim() << endl;
    LA.clear();
  }
    return 0;
}