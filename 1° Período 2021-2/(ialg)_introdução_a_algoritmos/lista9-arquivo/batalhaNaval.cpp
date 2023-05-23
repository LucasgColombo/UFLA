#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct registro{
    int numero;
    int quant = 0;
};

void batalhaN(int **m1, int **m2, int n){
    vector <registro> num;
    bool y = false;
    int afundados =0;

    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            if(m1[i][j] > 0){
                for(int k=0; k < (int)num.size(); k++){ 
                    if(num[k].numero == m1[i][j]){
                        y = true;
                        num[k].quant++;
                    }
                }
                if(y == false){
                    num.resize((int)num.size() + 1);
                    num[(int)num.size() -1].numero = m1[i][j];
                    num[(int)num.size() -1].quant++;
                }
                y = false;
            }
            if(m2[i][j]==1){
                if(m1[i][j]>0){
                    for(int x=0; x < (int)num.size();x++){
                        if(num[x].numero == m1[i][j]){
                            num[x].quant--;
                        }
                    }
                }
            }
        }
    }

    for(int i=0; i < (int)num.size(); i++){
        if(num[i].quant == 0){
            afundados++;
        }
    }

    cout << afundados << endl;
}

int main(){
    string nome = "BatalhaNaval.txt";
    int n;

    ifstream arquivo(nome);
    arquivo >> n;

    int **m1 = new int*[n];
    int **m2 = new int*[n];

    for(int i=0; i < n; i++){
        m1[i] = new int[n];
        m2[i] = new int[n];
    }

    for(int i=0; i < n; i++){
        for(int k=0; k < n; k++){
            arquivo >> m1[i][k];
        }
    }
    for(int i=0; i < n; i++){
        for(int k=0; k < n; k++){
            arquivo >> m2[i][k];
        }
    }

    batalhaN(m1,m2,n);

    for(int i=0; i < n; i++){
        delete[]m1[i];
        delete[]m2[i];
    }
    delete[]m1;
    delete[]m2;

    return 0;
}
