#include <bits/stdc++.h>

using namespace std;

struct cliente
{
    string nome, cpf;
    cliente *next;
    cliente(string _nome, string _cpf){nome = _nome, cpf = _cpf, next = nullptr;}
    cliente(){next = nullptr;}
};

cliente* criar()
{
    cliente *head = new cliente();
    return head;
}

void inserir(cliente *head, string nome, string cpf, int pos)
{
    cliente *aux = head, *c = new cliente(nome, cpf);
    int i = 1;
    while(i < pos and aux->next != nullptr)
        aux = aux->next, i++;
    if(!aux->next)
        aux->next = c;
    else
        c->next = aux->next, aux->next = c;

}

cliente remover(cliente *head, int pos)
{
    cliente *aux = head, r;
    int i = 1;
    while(i < pos - 1 and aux->next)
        aux = aux->next, i++;
    if(!aux->next->next)
        r = *(aux->next), free(aux->next), aux->next = nullptr;
    return r;
}

int buscar(cliente *head, string cpf)
{
    cliente *aux = head;
    int i = 1;
    while(aux->cpf != cpf)
        aux = aux->next, i++;
    return i;
}


void imprimir(cliente *head)
{
    cliente aux = *head;
    while(aux.next != nullptr)
        cout << aux.nome << ' ' << aux.cpf << '\n';
}

void deletar(cliente *head)
{
    cliente *aux = head;
    while(aux->next != nullptr)
        aux = aux->next, free(head), head = aux->next;
}

int main()
{

    return 0;
}
