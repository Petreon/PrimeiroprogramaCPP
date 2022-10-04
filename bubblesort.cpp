#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int code[1000] = {111,222,333,444,555};
float arr[1000] = {220,112,324,110,300};
int indexxarr[1000];
float arrcopy[1000];
int iteracoes = 0;

void mostrarArray(float ar[1000]) {
    cout << "{";
    for (int i = 0 ; i < 1000; i++) {
        if (code[i] != 0){
        cout << ar[i] << ",";

        }
    }
    cout << "}";
}
void mostrarArray(int ar[1000]) {
    cout << "{";
    for (int i = 0 ; i < 1000; i++) {
        if (code[i] != 0){
        cout << ar[i] << ",";

        }
    }
    cout << "}";
}


void fullIndexARR() {
    for (int i = 0; i < 1000; i++) {
        indexxarr[i] = i;
    }
}

void bubbleSort() {
    float templess;
    float tempbigger;
    int temp1;
    int temp2;
    bool controle = true;

    if (iteracoes == 0) {
    copy(begin(arr), end(arr), begin(arrcopy));
    }
    while (controle) {
        for (int i = 0; i < 1000; i++){
            for(int j = i+1; j < 1000; j++) {
                if(arrcopy[j] < arrcopy[i] && (code[i] != 0 && code[j] !=0)) {
                    templess = arrcopy[j];
                    tempbigger = arrcopy[i];
                    arrcopy[i] = templess;
                    arrcopy[j] = tempbigger;

                    temp1 = indexxarr[j];
                    temp2 = indexxarr[i];
                    indexxarr[i] = temp1;
                    indexxarr[j] = temp2;
                    cout << arrcopy[j] << " , " << arrcopy[i] << endl;
                    break;
                    //cout << "iteracoes: " << i;
                }
                else if (i == 998){
                controle = false;
                }   
            }
        }
    }
    if (iteracoes < 10){
        iteracoes++;
        cout << "iter:" << iteracoes << endl;
        return bubbleSort();

    } else if (iteracoes == 10) {
        iteracoes = 0;
    }
    
    //mostrarArray(arrcopy);

     

    
}




int main() {
    mostrarArray(arr);
    fullIndexARR();
    mostrarArray(indexxarr);
    bubbleSort();
    mostrarArray(arrcopy);
    mostrarArray(indexxarr);

    return 0;
}