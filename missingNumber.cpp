#include <iostream>
#include <stdio.h>
#include <array>
using namespace std;


bool divisible(int num){
    if(num % 2 ==0 ) return true;
    else return false;
}

/*void recorre(int lista[], int size){
    for(int i = 0; i<size; i++){
        if(divisible(lista[i])) cout<<"Es divisible de 2: "<< lista[i]<<"\n";
        else cout <<"no es el: "<< lista[i]<<"\n";
    }
}*/
void muestraLista(int lista[], int size){
    for(int i = 0; i<size; i++){
        cout<<lista[i]<<" ";
    }
    cout<<endl;
}
int partition(int arrayL[], int p, int r){
    int temp = 0;
    int x = arrayL[r];
    int i = (p-1);
    for (int j = p; j <= r-1 ;j++){
        if(arrayL[j] <= x){
            i++;
            temp = arrayL[i];
            arrayL[i] = arrayL[j];
            arrayL[j] = temp;
        }
    }
    temp = arrayL[i+1];
    arrayL[i+1] = arrayL[r];
    arrayL[r] = temp;
    return (i+1);
}
void quicksort(int array[], int p, int r){
    if(p < r){
        int q = partition(array, p, r);
        quicksort(array, p, q - 1);
        quicksort(array, q + 1, r);
    }
}

int main(){
    int size = 0, test = 0;
    cin>>test;
    if(test > 10) return 0;
    while(test > 0){
        
        cin>>size;
        
        if (size<1 || size > 105) return 0;
        
        int lista[size];
        for(int i=0; i<size;i++){
            cin>>lista[i];
        }
        //muestraLista(lista, size);
        quicksort(lista, 0, size - 1);
        //cout<<"ORDENADO"<<endl;
        //muestraLista(lista, size);
        if(divisible(lista[size-1])){
            cout<<lista[size-1] + 2<<endl;
        }else{
            lista[size - 1] -= 1;
            cout<< lista[size-1] + 2<<endl;
        }
        test--;
    }
    return 0;
}