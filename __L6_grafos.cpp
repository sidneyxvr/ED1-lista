#include <iostream>
using namespace std;

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
    cout << "LISTA DE ADJACENCIA:" << '\n';
    for(int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for(Node *aux = head[i].adj->next; aux != nullptr; aux = aux->next)
            cout << aux->value << ' ';
        cout << '\n';
    }
}

int main()
{
    int n, m, v, w;

    cin >> n >> m;
    begin *head = create(n);

    while(m--)
    {
        cin >> v >> w;
        insert(head, v, w);
        insert(head, w, v);
    }

    show(head, n);

    cout << '\n';

    for(int i = 0; i < n; i++)
        if(!head[i].flag)
        int ans = 0;
            dfs(head, i), ans++;

    cout << "a quantidade de componentes conexas do grafo eh " << ans <<'\n';

    clean(head, n);

    return 0;
}
