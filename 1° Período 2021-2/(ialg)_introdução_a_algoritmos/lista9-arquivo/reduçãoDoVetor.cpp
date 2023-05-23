#include <fstream>
#include <iostream>


using namespace std;

float *expande(float *v, int &tam){
    float *novo = new float[tam+1];

    for(int i=0;i<tam;i++) novo[i] = v[i];

    tam++;

    delete[]v;

    return novo;

}

float *preencher(string nome,float *v, int &tam){
    float aux;
    int i=0;

    ifstream arquivo(nome);

    while(arquivo >> aux){ 
        v = expande(v,tam);
        
        v[i]=aux;
        i++;
    }

    arquivo.close();

    return v;

}

int main(){
    string nome;
    float *v = NULL;
    int tam =0;

    cin >> nome;

    v = preencher(nome,v,tam);

    if(tam %2 == 0){
        for(int i=tam-1, j=tam-2;j>-1;i-=2,j-=2){
            cout << (v[i]+v[j])/2 << " ";
        }
    }else{
        cout << v[tam-1] << " ";
        for(int i=tam-2, j=tam-3;j>-1;i-=2,j-=2){
            cout << (v[i]+v[j])/2 << " ";
        }
    }

    return 0;
}
