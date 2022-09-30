#include <iostream>
#include <string>
using namespace std; // bad-practice, tirar no proximo programa

int codigo[1000] = {0};
string descricao[1000] = {""};
float preco[1000] = {0};
int quantidade[1000] = {0};
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
                cout << endl << "---------------------------------" << endl
            << "Codigo: " << codigo[i] << endl
            << "Descricao: " << descricao[i] << endl
            << "Preco: R$" << preco[i] << endl
            << "Quantidade: " << quantidade[i] << endl 
            << "---------------------------------" << endl;
            salvarIndex = i;
            break;
            }
        else {
            salvarIndex = -1;            
        }
    
    }
    if (salvarIndex == -1) { // somente uma mensagenzinha de erro para dizer que o produto nçao foie ncontrado
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

    //cin.clear();
    //cin.ignore(0, '\n');
    getline(cin >> ws, descricao[index]); // "ws" serve para limpar a linha anterior e conseguir adicionar a string
    //cin.clear();
    //cin.ignore(0, '\n');


    cout << "digite o preco do produto \n";
    cin >> preco[index];

    cout << "digite a quantidade do produto(numeros inteiros)" << endl;
    cin >> quantidade[index];    
    
    cout << "produto adicionado com sucesso \n ";
}


void visualisar(){ // visualiza os produtos
    int index = verificar_ultimoIndex();
    for (int i = 0; i < index; i++) {
        cout << endl << "---------------------------------" << endl
        << "Codigo: " << codigo[i] << endl
        << "Descricao: " << descricao[i] << endl
        << "Preco: R$" << preco[i] << endl
        << "Quantidade: " << quantidade[i] << endl 
        << "---------------------------------" << endl;
    }
}


void consultar(int inpUser = 0 ) { // funcao unicamente feita para consultar os dado colocando um codigo especifico
    if (inpUser == 0) {
        cout << "digite o codigo do Produto que deseja visualizar os dados: ";
        cin >> inpUser;
        iterarDados(verificar_ultimoIndex(), inpUser); // aqui usa a função de iterar dados junto com a funcao de index
    }
    else {
        iterarDados(verificar_ultimoIndex(), inpUser); // essa parte da funcao serve para não ter q escrever o codigo de alterar dados novamente
        }
    }
    
    
void alterar() {
    int codigodoProd = 0;
    int alterarProduto = 0;
    int indexAtual = 0;
    int novoInt = 0;
    string novaString = "";
    float novoFloat = 0;

    cout << "Digite o codigo do produto que voce quer alterar" << endl;
    cin >> codigodoProd;
    indexAtual = iterarDados(verificar_ultimoIndex(), codigodoProd);
    cout << "Qual dado deseja alterar? " << endl
    << " 1 - Codigo" << endl
    << " 2 - Descricao" << endl
    << " 3 - Preco" << endl
    << " 4 - Quantidade" << endl;

    if (indexAtual == -1) { // caso a funcao de iterar dados retorne -1 ela vai sair do alterar e ir para o user Input novamente
    }
    else {
        cin >> alterarProduto;

        if(alterarProduto == 1) {
            cout << "Digite o novo codigo" << endl;
            cin >> novoInt;
            codigo[indexAtual] = novoInt; // DESCOBRIR O PQ DO INDEX ATUAL PRECISAR DE UM POINTER
            cout << "codigo alterado com sucesso" << endl;
        }
        else if (alterarProduto == 2) {
            cout << "Digite a nova descricao" << endl;
            cin.clear();
            cin.ignore(100, '\n');
            getline(cin >> ws, novaString);
            descricao[indexAtual] = novaString;
            cout << "descricao alterado com sucesso" << endl;

        }
        else if (alterarProduto == 3) {
            cout << "Digite o novo preco" << endl;
            cin >> novoFloat;
            preco[indexAtual] = novoFloat;
            cout << "Preco alterado com sucesso" << endl;

        }
        else if (alterarProduto == 4) {
            cout << "digite a nova quantidade do produto" << endl;
            cin >> novoInt;
            quantidade[indexAtual] = novoInt;
            cout << "Quantidade alterada com sucesso" << endl;
        }
        else {
            cout << "Opção não encontrada tente novamente" << endl;
        }

    }
    

}

void excluir() { // nesse caso de exclusão foi só necessario colocar a quatidade do produto pra zero, e não excluir todos os dados do array
    int codigoProd;
    bool boolexcluir;
    cout << "Digite o codigo do produto que deseja excluir os dados" << endl;
    cin >> codigoProd;
    int indexAtual = iterarDados(verificar_ultimoIndex(), codigoProd);
    cout << "Deseja excluir esse produto?" << endl
    << "1 - Sim" << endl << "0 - Nao" << endl;
    cin >> boolexcluir;
    if (boolexcluir) {
        quantidade[indexAtual] = 0;
        cout << "Produto excluido com sucesso" << endl;
    }
    else {
        cout << "Produto nao excluido" << endl;
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
            alterar();
        }
        else if(escolha == 3) {
            excluir();
        }
        else if(escolha == 4) {
            consultar();
        }
        else if(escolha == 5){
            visualisar();
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
        << "2 - Alterar Dados" << endl
        << "3 - Excluir Dados" << endl
        << "4 - Consultar Dados de um produto especifico" << endl
        << "5 - Listar todos os dados" << endl 
        << "9 - Encerrar Programa" << endl;

    while(control) {
        cout << "digite a opcao a ser escolhida (incluir, alterar, excluir, consultar, listar, encerrar)" << endl;
        userInput();
    }
   
    return 0;
}