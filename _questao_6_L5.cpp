#include <bits/stdc++.h>

using namespace std;

struct cliente
{
    string nome, cpf;
    cliente *next, *prev;
    cliente(string _nome, string _cpf){nome = _nome, cpf = _cpf, next = nullptr, prev = nullptr;}
    cliente(){next = nullptr, prev = nullptr;}
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
    while(i < pos)
        aux = aux->next, i++;
    if(aux->next == head)
        aux->next = c, c->prev = aux, c->next = head;
    else
        c->next = aux->next, c->next->prev = c, aux->next = c, c->prev = aux;
}

cliente remover(cliente *head, int pos)
{
    cliente *aux = head->next, r;
    int i = 1;
    while(i < pos)
        aux = aux->next, i++;
    r = *aux;
    if(aux->next == head)
        aux->prev->next = head;
    else
        aux->prev->next = aux->next, aux->next->prev = aux->prev;
    return r;
}

int buscar(cliente *head, string cpf)
{
    cliente *aux = head->next;
    int i = 1;
    while(aux->cpf != cpf)
    {
        if(aux != head)
            return -1;
        aux = aux->next, i++;
    }
    return i;
}


void listar(cliente *head)
{
    cliente *aux = head->next;
    while(aux != head)
        cout << aux->nome << '\n', aux = aux->next;
}

int main()
{
    

    return 0;
}
