#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Класс листа дерева, хранит в себе значение и указатели на левый и правый лист
struct leaf
{
    int value;
    leaf* left;
    leaf* right;
};

class BinaryTree
{
public:

    BinaryTree()
    {
        root = NULL;
    }
    ~BinaryTree()
    {
        destroy_tree();
    }

    // Функция вставки элемента
    void destroy_tree()
    {
        destroy_tree(root);
    }

    // Функция вызывающая рекурсивную функцию записи в дерево
    void readAndInsert(int &i, string &plant)
    {
        readAndInsert(i, plant, NULL);
    }

    //функция вызывающаю рекурсивную функцию прямого обхода
    void direct_traversal()
    {
        direct_traversal(root);
    }

    //функция вызывающаю рекурсивную функцию центрированного обхода
    void symmetric_traversal()
    {
        symmetric_traversal(root);
    }

    //функция вызывающаю рекурсивную функцию концевого обхода
    void reverse_traversal()
    {
        reverse_traversal(root);
    }

private:
    // Рекурсивно удаляет дерево
    void destroy_tree(leaf* leaf)
    {
        if (leaf != NULL)
        {
            destroy_tree(leaf->left);
            destroy_tree(leaf->right);
            delete leaf;
        }
    }

    // Рекурсивную функцию записи в дерево
    bool readAndInsert(int& i, string& plant, leaf* currentLeaf) // Выводит true если создался лист, если false то происходит удаление
    {
        string str = "";
        while (i < plant.size() && plant[i] != '(' && plant[i] != ')' && plant[i] != ',') // Считываю символы
        {
            if (plant[i]!=' ')
            {
                str += plant[i];
            }
            i++;
        }
        i++;

        if (str != "") // Проверка на пустоту значения
        {
            int newValue = stoi(str);

            if (currentLeaf == NULL)// Проверка на существование корня
            {
                root = new leaf;
                root->value = newValue;
                currentLeaf = root;
            }
            else
            {
                currentLeaf->value = newValue;
            }
            currentLeaf->left = NULL;
            currentLeaf->right = NULL;

            if (plant[i-1] != ',' && plant[i-1] != ')') // Очередная проверка
            {
                currentLeaf->left = new leaf;
                if (!readAndInsert(i, plant, currentLeaf->left))
                {
                    delete currentLeaf->left;
                    currentLeaf->left = NULL;
                }

                currentLeaf->right = new leaf;
                if (!readAndInsert(i, plant, currentLeaf->right))
                {
                    delete currentLeaf->right;
                    currentLeaf->right = NULL;
                }

            }

            while (i < plant.size() && (plant[i] == ')' || plant[i] == ','))// Пропускаю символы
            {
                i++;
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    // Рекурсивная функция прямого обхода
    void direct_traversal(leaf* currentLeaf)
    {
        if (currentLeaf != NULL)
        {
            cout << currentLeaf->value << " ";
            direct_traversal(currentLeaf->left);
            direct_traversal(currentLeaf->right);
        }
    }

    // Рекурсивная функция центрированного обхода
    void symmetric_traversal(leaf* currentLeaf)
    {
        if (currentLeaf != NULL)
        {
            symmetric_traversal(currentLeaf->left);
            cout << currentLeaf->value << " ";
            symmetric_traversal(currentLeaf->right);
        }
    }

    // Рекурсивная функция концевого обхода 
    void reverse_traversal(leaf* currentLeaf)
    {
        if (currentLeaf != NULL)
        {
            reverse_traversal(currentLeaf->left);
            reverse_traversal(currentLeaf->right);
            cout << currentLeaf->value << " ";
        }
    }

    leaf* root;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    BinaryTree NewTree;

    cout << "Введите дерево" << endl;

    string plant;
    getline(cin, plant);
    cout << endl;

    int i = 0;
    NewTree.readAndInsert(i, plant);

    cout << "Прямого обход:" << endl;
    NewTree.direct_traversal();
    cout << endl;

    cout << "Центрированный обход:" << endl;
    NewTree.symmetric_traversal();
    cout << endl;

    cout << "Концевого обхода:" << endl;
    NewTree.reverse_traversal();
    cout << endl;

    return 0;
}