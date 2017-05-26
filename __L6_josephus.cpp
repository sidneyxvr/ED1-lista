#include <bits/stdc++.h>

struct Node
{
    std::string name;
    Node *next;
    Node(Node *head, std::string _name){name = _name, next = head;}
    Node(){next = nullptr;}
};

Node* create()
{
    Node *head = new Node();
    head->next = head;
    return head;
}

void insert(Node *head, std::string name, int pos)
{
    Node *aux;
    int i = 0;
    for(aux = head; aux->next != head and i < pos; aux = aux->next)
        i++;
    if(aux->next == head)
        aux->next = new Node(head, name);
    else
    {
        Node *k = new Node(head, name);
        k->next = aux->next;
        aux->next = k;
    }
}

Node remove(Node *head, int pos)
{
    Node *aux;
    int i = 0;
    for(aux = head; aux->next != head and i < pos; aux = aux->next)
        i++;
    Node *k = aux->next, r = *k;
    aux->next = aux->next->next;
    delete(k);
    return r;
}

void clean(Node *head){
    Node *aux1 = head->next, *aux2 = head->next;
    while(aux1 != head)
        aux1 = aux1->next, delete(aux2), aux2 = aux1;
    delete(aux2);
}

std::string josephus(Node *head, int n, int m)
{
    int c = 0, i;
    Node *aux = head;
    while(n != 1)
    {
        if(aux == head)
            i = -1, aux = aux->next;
        else
        {
            i++, c++;
            if(c == m)
            {
                Node r = remove(head, i);
                n--, i--, c = 0;
                aux = r.next;
            }else
                aux = aux->next;
        }
    }
    return head->next->name;
}

int main()
{
    Node *head = create();
    insert(head, "Poisson", 0);
    insert(head, "Bernoulli", 1);
    insert(head, "Newton", 2);
    insert(head, "Einsten", 3);
    insert(head, "Morgado", 4);
    std::cout << josephus(head, 5, 2) << '\n';
    clean(head);

    return 0;
}
