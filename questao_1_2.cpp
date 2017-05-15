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
    cliente c;
    c.nome = "sidney", c.cpf = "123456789";
    inserir(lista, c, 0);
    cout << lista[0].nome << '\n';
    cliente r = remover(lista, 0);
    cout << lista[0].nome << '\n';
    deletar(lista);
    return 0;
}
