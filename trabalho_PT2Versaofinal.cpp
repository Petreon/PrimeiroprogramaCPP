#include <iostream>
#include <string>
#include <algorithm>
using namespace std; // bad-practice, tirar no proximo programa

int codigo[1000] = {0};
string descricao[1000] = {""};
float preco[1000] = {0};
int quantidadeVendida[1000] = {0};
float percentualLucro[1000] = {0};
float lucroObtido[1000] = {0};
int indexxarr[1000];
float arrcopy[1000];
int iteracoes = 0;

bool control = true;


int verificar_ultimoIndex() {  // pega o index do codigo para sincronizar com os outros arrays
     int index = 0;
    for (int i = 0; i <= 1000000; i++) {
        if (codigo[i] == 0) {
            index = i;
            break;
        }
    }

    return index;
}

int iterarDados(int indexx = 0, int inpUser = 0) { //função para poder procurar um dado especifico do programa baseado no codigo do produto
    int salvarIndex;
    for(int i=0; i <= indexx; i++ ) {
        if (inpUser == codigo[i]){
            /*    cout << endl << "---------------------------------" << endl
            << "Codigo: " << codigo[i] << endl
            << "Descricao: " << descricao[i] << endl
            << "Preco: R$" << preco[i] << endl
            << "Quantidade Vendida: " << quantidadeVendida[i] << endl 
            << "---------------------------------" << endl; */
            salvarIndex = i; 
            break;
            }
        else {
            salvarIndex = -1;            
        }
    
    }
    if (salvarIndex == -1) { // somente uma mensagenzinha de erro para dizer que o produto não foi encontrado
        cout << "Produto nao encontrado tente novamente " << endl; 
    }
    return salvarIndex;
}

void adicionar(){ // adiciona um produto ao array
    int index = verificar_ultimoIndex();
    cout << "digite o codigo do produto(somente numeros)" << endl;
    cin >> codigo[index];
    codigo[index+1] = 0; // serve para adicionar o 0 no proximo indice do array, para que a funcao verificar_ultimoIndex ainda funcione

    cout << "digite a descricao do produto" << endl;

    getline(cin >> ws, descricao[index]); // "ws" serve para limpar a linha anterior e conseguir adicionar a string
    
    cout << "digite o preco do produto \n";
    cin >> preco[index];

    cout << "digite a quantidade vendida do produto(numeros inteiros)" << endl;
    cin >> quantidadeVendida[index];

    cout << "digite o percentual do lucro desse produto" << endl;
    cin >> percentualLucro[index];
    
    cout << "produto adicionado com sucesso \n ";
}


void visualisar(){ // visualiza os produtos
    int index = verificar_ultimoIndex();
    for (int i = 0; i < index; i++) {
        cout << endl << "---------------------------------" << endl
        << "Codigo: " << codigo[i] << endl
        << "Descricao: " << descricao[i] << endl
        << "Preco: R$" << preco[i] << endl
        << "Quantidade Vendida: " << quantidadeVendida[i] << endl 
        << "Percentual de Lucro: " << percentualLucro[i] << endl
        << "Lucro Obtido: " << lucroObtido[i] << endl
        << "---------------------------------" << endl;
    }
}

void registrarVenda() {
    int code;
    int quantidadevend;
    cout << "Digite o codigo do produto da qual deseja realizar venda" << endl;
    cin >> code;
    cout << "Digite a quantide vendida do produto" << endl;
    cin >> quantidadevend;


    int index = iterarDados(verificar_ultimoIndex(), code);
    if (index != -1) {
        quantidadeVendida[index] += quantidadevend;
    } else {
        cout << "não foi possivel adicionar a venda ao produto";
    }
}

void mostrarArray(float ar[1000]) { //mostrar away in python away pra debbug
    cout << "{";
    for (int i = 0 ; i < 1000; i++) {
        if (codigo[i] != 0){
        cout << ar[i] << ",";

        }
    }
    cout << "}";
}
void mostrarArray(int ar[1000]) { // function overloading for int
    cout << "{";
    for (int i = 0 ; i < 1000; i++) {
        if (codigo[i] != 0){
        cout << ar[i] << ",";

        }
    }
    cout << "}";
}


void fullIndexARR() { // encher o array de indexxs para sincronizar com array de codigos
    for (int i = 0; i < 1000; i++) {
        indexxarr[i] = i;
    }
}

void bubbleSort() { // ordenar o array de forma crescente
    float templess;
    float tempbigger;
    int temp1;
    int temp2;
    bool controle = true;

    if (iteracoes == 0) {
    copy(begin(lucroObtido), end(lucroObtido), begin(arrcopy));
    }
    while (controle) {
        for (int i = 0; i < 1000; i++){
            for(int j = i+1; j < 1000; j++) {
                if(arrcopy[j] < arrcopy[i] && (codigo[i] != 0 && codigo[j] !=0)) {
                    templess = arrcopy[j];
                    tempbigger = arrcopy[i];
                    arrcopy[i] = templess;
                    arrcopy[j] = tempbigger;

                    temp1 = indexxarr[j];
                    temp2 = indexxarr[i];
                    indexxarr[i] = temp1;
                    indexxarr[j] = temp2;
                    //cout << arrcopy[j] << " , " << arrcopy[i] << endl;
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
        //cout << "iter:" << iteracoes << endl;
        return bubbleSort();

    } else if (iteracoes == 10) {
        iteracoes = 0;
    }
    
    //mostrarArray(arrcopy);
    
}






void visualizarLucroDrec() { // tentativa de reordenar os dados
    fullIndexARR();
    bubbleSort();

    for (int k = 998; k >=0; k--) {
        if(codigo[k] != 0) {
            cout << endl << "----------------------" << endl 
            << "descricao do produto: " << descricao[indexxarr[k]] << endl
            << "Lucro Obtido: R$" << lucroObtido[indexxarr[k]] << endl
            << "---------------------" << endl; 
        }
    }

}










void emitirLucro(int indice = 0) {
    
    if (verificar_ultimoIndex() != indice) {
        lucroObtido[indice] = preco[indice] * quantidadeVendida[indice] * percentualLucro[indice];
        //cout << "feita" << indice << "iteracao" << endl;
    return emitirLucro(indice+1);
    }
    else {
        visualizarLucroDrec();
    }
}


void userInput() {
    //cin.clear();
    //cin.ignore(100, '\n');       
    try {
        int escolha;
        cin >> escolha;
        if (escolha == 1){
            adicionar();
        }
        else if(escolha == 2){
            registrarVenda();
        }
        else if(escolha == 3) {
            emitirLucro();
        }
        else if(escolha == 4) {
            visualisar();
        }
        else if(escolha == 5){
            
        }
        else if (escolha == 9) {
            control = false;
        }
        else {
            throw (escolha);
        }
    }
    catch(...){
        cout << "comando nao reconhecido tente novamente" << endl;
        // os dois comandos abaixo servem para limpar o input caso tenha sido colocado uma string no "cin"
        cin.clear(); 
        cin.ignore(100, '\n');
        userInput();
    }
}



int main(){
    cout << "Bem vindo ao Programa" << endl;
    cout << "digite a opcao a ser escolhida" << endl
        << "1 - Incluir Dados" << endl 
        << "2 - Registrar Venda" << endl
        << "3 - Emitir lucratividade" << endl
        << "4 - Visualizar Dados, (so deixei pra facilitar o debbug do programa)" << endl
        << "9 - Encerrar Programa" << endl;

    while(control) {
        cout << "digite a opcao a ser escolhida " << endl;
        userInput();
    }
   
    return 0;
}