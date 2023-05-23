#include <iostream>

using namespace std;

int main(){
    int n, i, j;
    
    cin >> n;

    int m[n][n];

    for (i=0; i < n; i++)
        for (j=0; j < n; j++)
        cin >> m[i][j];  

    int soma = 0;

    for (i=0; i < n; i++){
        for (j = 0; j < n; j++){
            if(i+j >= n){
                cout << m[i][j] << " ";
                soma += m[i][j];
            }
        }
    }


    cout << endl << soma << endl;

    return 0;
}
