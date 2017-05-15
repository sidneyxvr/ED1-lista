#include <bits/stdc++.h>

using namespace std;

int tam;

struct cliente
{
    string nome, cpf;
};

cliente* criar(const int max = 1 << 20)
{
    cliente *lista;
    lista = (cliente*)(malloc(max*sizeof(cliente*)));
    return lista;
}

void inserir(cliente *lista, cliente c)
{   
    lista[tam] = c;
    tam++;
}

cliente remover(cliente *lista)
{
    cliente aux = lista[0];
    for(int i = 0; i < tam - 1; i++)
        lista[i] = lista[i + 1];
    return aux;
}

void deletar(cliente *lista)
{
    free(lista);
}

int main()
{
    cliente *lista = criar();
    cliente c1, c2, c3, c4;
    c1.nome = "alguem", c1.cpf = "123456789";
    inserir(lista, c1);
    c2.nome = "mais alguem", c2.cpf = "912345678";
    inserir(lista, c2);
    c3 = remover(lista);
    cout << c3.nome << '\n';
    c4.nome = "loucura", c4.cpf = "0000000000";
    inserir(lista, c4);
    c3 = remover(lista);
    cout << c3.nome << '\n';
    deletar(lista);
    
    return 0;
}
