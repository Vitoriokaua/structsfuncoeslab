#include <iostream>
#include <string>
using namespace std;

struct pessoas
{
    string nome;
    string sexo;
    pessoas* prox;
};

pessoas* Criar_lista() {
    return NULL;
}

void Inserir_inicio(pessoas*& l, string nome, string sexo) {
    pessoas* novo = new pessoas;
    novo->nome = nome;
    novo->sexo = sexo;
    novo->prox = NULL;
    if (l == NULL)
        l = novo;
    else
    {
        novo->prox = l;
        l = novo;
    }
}

void imprimir(pessoas* l) {
    pessoas* p = l;
    while (p != NULL)
    {
        cout << "Nome: " << p->nome << " - Sexo: " << p->sexo << endl;
        p = p->prox;
    }
}

int main() {
    pessoas* homens = Criar_lista();
    pessoas* mulheres = Criar_lista();
    string nome;
    string sexo;

    cout << "Digite o nome das pessoas: (digite 'fim' para terminar)" << endl;
    cin >> nome;

    while (nome != "fim")
    {
        cout << "Informe o sexo (M/F): ";
        cin >> sexo;

        if (sexo == "M")
            Inserir_inicio(homens, nome, sexo);
        else if (sexo == "F")
            Inserir_inicio(mulheres, nome, sexo);
        else
            cout << "Sexo inválido" << endl;

        cout << "Digite o nome das pessoas: (digite 'fim' para terminar)" << endl;
        cin >> nome;
    }

    cout << "Homens:" << endl;
    imprimir(homens);
    cout << "Mulheres:" << endl;
    imprimir(mulheres);

    return 0;
}
//fazer com que o usuario fornessa dados de pessoas (nome e sexo), 
//e inserir a pessoa na lista adequada o usuario ira parar quando digitar o nome "fim",imprimira entao as duas listas