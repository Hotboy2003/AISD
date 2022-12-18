#include <iostream>
#include <conio.h>
#include <stack>

using namespace std;

// структура
struct node
{
    int info;
    node* l, * r; // левая правая ветка
};

node* tree = NULL; // корень NULL

//функция ввода дерева
void push(int a, node** t)
{
    if ((*t) == NULL)
    {
        //создаем новую структуру
        (*t) = new node;
        //записываем корень
        (*t)->info = a;
        //зануляем левую и правую ветки
        (*t)->l = (*t)->r = NULL;
        return;
    }
    //сортируем введеные элементы, перенаправляя их в зависиморсти от того больше они или меньше корня
    if (a > (*t)->info) push(a, &(*t)->r);
    else push(a, &(*t)->l);
}

// функция нерекурсивного обхода и вывода чисел
void print(node* root, int u)
{
    // если дерева не существует, то return
    if (root == nullptr)
        return;

    //реализация вывода через стек
    stack<node*> nodeStack;
    nodeStack.push(root);

    while (nodeStack.empty() == false)
    {
        struct node* node = nodeStack.top();
        cout << node->info;
        nodeStack.pop();

        if (node->r)
            nodeStack.push(node->r);
        if (node->l)
            nodeStack.push(node->l);
    }
}

void main()
{
    //устанавливаем русский язык
    setlocale(LC_ALL, "Russian");
    int n;
    int s;
    cout << "Количество элементов: ";
    //принимаем на вход количество элементов 
    cin >> n;

    // записываем все элементы в дерево
    for (int i = 0; i < n; ++i)
    {
        cout << "Вершина: ";
        cin >> s;

        push(s, &tree);
    }
    //нерекурсивно выводим элементы дерева
    print(tree, 0);
    _getch();
}