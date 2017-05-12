#include <bits/stdc++.h>

using namespace std;

const int MAX = 1 << 20;
int tam;

struct cliente
{
    string nome, cpf;
};

cliente* criar()
{
    cliente *lista;
    lista = (cliente*)(malloc(MAX));
    return lista;
}

void inserir(cliente *lista, cliente c, int pos)
{   
    cliente aux;
    while(pos != tam)
    {
        aux = lista[pos];
        lista[pos] = c;
        c = aux;
        pos++;
    }
    lista[pos] = c;
    tam++;
}

cliente remover(cliente *lista, int pos)
{
    cliente aux = lista[pos];
    for(int i = pos; i < tam; i++)
        lista[pos] = lista[pos + 1];
    tam--;
    return aux;
}

int buscar(cliente *lista, cliente c)
{
    for(int i = 0; i < tam; i++)
        if(lista[i].cpf == c.cpf)
            return i;
    return -1;
}

void deletar(cliente *lista)
{
    free(lista);
}

int main()
{
    cliente *lista = criar();
    cliente c1, c2, c3;
    c1.nome = "alguem", c1.cpf = "123456789";
    inserir(lista, c1, 0);
    c2.nome = "mais alguem", c2.cpf = "912345678";
    inserir(lista, c2, 0);
    c1.nome = "alem de mais alguem", c1.cpf = "891234567";
    inserir(lista, c3, 0);
    cout << lista[0].nome << '\n';
    cout << buscar(lista, c2) << '\n';
    cliente r = remover(lista, 0);
    cout << lista[0].nome << '\n';
    deletar(lista);
    return 0;
}
