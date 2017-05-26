#include <bits/stdc++.h>

struct Node
{
    int value;
    Node *next;
    Node(int _value){value = _value; next = nullptr;}
    Node(){value = 0; next = nullptr;}
};

struct begin
{
    Node *adj;
    Node *end;
    bool flag;
};

begin* create(int n)
{
    begin *head = new begin[n];
    for(int i = 0; i < n; i++)
        head[i].adj = new Node(), head[i].flag = false, head[i].end = head[i].adj;
    return head;
}

void insert(begin *head, int v, int w)
{
    head[v].end->next = new Node(w);
    head[v].end = head[v].end->next;
    head[v].adj->value++;
    return;
}

void dfs(begin *head, int v)
{
    head[v].flag = true;
    for(Node *aux = head[v].adj->next; aux != nullptr; aux = aux->next)
        if(!head[aux->value].flag)
            dfs(head, aux->value);
}

void clean(begin *head, int n)
{
    Node *aux, *k;
    for(int i = 0; i < n; i++){
        aux = head[i].adj;
        while(aux != nullptr)
            k = aux->next, delete(aux), aux = k;
    }
    delete[] head;
}

void show(begin *head, int n)
{
    for(int i = 0; i < n; i++)
    {
        std::cout << i << ": ";
        for(Node *aux = head[i].adj->next; aux != nullptr; aux = aux->next)
            std::cout << aux->value << ' ';
        std::cout << '\n';
    }
}

int main()
{
    begin *head = create(3);
    insert(head, 0, 2);
    insert(head, 2, 0);
    insert(head, 0, 1);
    insert(head, 1, 0);
    insert(head, 1, 2);
    insert(head, 2, 1);
    show(head, 3);
    int ans = 0;
    for(int i = 0; i < 3; i++)
        if(!head[i].flag)
            dfs(head, i), ans++;
    std::cout << ans << '\n';
    clean(head, 3);

    return 0;
}
