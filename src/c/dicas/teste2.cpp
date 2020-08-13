#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int vetor[N];
    int numero = 0;
    for(int i=0; i<N; i++){
        cin>>vetor[i];
    }
    for(int i=0; i<N; i++){
        if(vetor[i]==1){
            if(vetor[i+1]==0 and vetor[i+2]==0){
                numero = numero + 1;
            }
        }
    }
    cout<<numero;

}

