#include <iostream>
#include <stdio.h>
#include <array>
using namespace std;


bool divisible(int num){
    if(num % 2 ==0 ) return true;
    else return false;
}

void recorre(int lista[], int size){
    for(int i = 0; i<size; i++){
        if(divisible(lista[i])) cout<<"Es divisible de 2: "<< lista[i]<<"\n";
    }
}
int partition(int array[], int p, int r){
    int x = 0, i=0, temp = 0;
    x = array[r];
    i = p-1;
    for (int j = p; i <= r-1 ;i++){
        if(array[j] <= x){
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[i+1];
    array[i+1] = array[r];
    array[r] = temp;
    return i+1;
}
void quicksort(int array[], int p, int r){
    int q = 0;
    if(p<r){
        q = partition(array, p, r);
        quicksort(array, p, q);
        quicksort(array, q + 1, r);
    }
}

int main(){
    int size = 0, test = 0;
    cin>>test;
    cin>>size;
    int lista[size];
    for(int i=0; i<size;i++){
        cin>>lista[i];
    }
    recorre(lista, size);
    return 0;
}