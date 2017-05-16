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

void inserir(cliente *head, string nome, string cpf)
{
    cliente *aux = head, *c = new cliente(nome, cpf);
    while(aux->next != nullptr)
        aux = aux->next;
    aux->next = c;
}

cliente remover(cliente *head)
{
    cliente *aux = head->next, r;
    if(aux->next == nullptr)
    {
        r = *aux, head->next = nullptr;
        return r;
    }
    while(aux->next->next != nullptr)
        aux = aux->next;
    r = *aux->next, aux->next = nullptr;
    return r;
}

void deletar(cliente *head)
{

}

int main()
{
    
    
    return 0;
}
