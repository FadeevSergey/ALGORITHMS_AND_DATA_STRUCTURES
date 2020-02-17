#include <iostream>
#include <string>

using namespace std;

struct top
{
    int key;
    top *left = nullptr;
    top *right = nullptr;
    top *parent = nullptr;
};
int num = 0;
top* tree;
extern void deletee(int, top*&);
extern top* next(int, top*);
void insertt(int x, top* &v)
{
    if (v == nullptr)
    {
        top* tempTop = new top;
        v = tempTop;
        v->key = x;
        v->parent = nullptr;
        return;
    }
    if (v->key == x)
    {
        return;
    }
    if (v->key > x)
    {
        if (v->left == nullptr)
        {
            top* tempT = new top;
            tempT->key = x;
            v->left = tempT;
            tempT->parent = v;
            return;
        }
        else
        {
            if (v->left->key < x)
            {
                top* t = new top;
                t->key = x;
                t->left = v->left;
                v->left = t;
                t->parent = v;
                return;
            }
            if (v->left->key > x)
            {
                insertt(x, v->left);
                return;
            }
        }
    }
    if (v->key < x)
    {

        if (v->right == nullptr)
        {
            top* tempT = new top;
            tempT->key = x;
            v->right = tempT;
            tempT->parent = v;
            return;
        }
        else
        {
            if (v->right->key > x)
            {
                top* t = new top;
                t->key = x;
                t->right = v->right;
                v->right = t;
                t->parent = v;
                return;
            }
            if (v->right->key < x)
            {
                insertt(x, v->right);
                return;
            }
        }
    }
}


top* exists(int x, top* v)
{
    if (v == nullptr)
    {
        return nullptr;
    }
    if (v->key == x)
    {
        return v;
    }
    if (v->left == nullptr && v->right == nullptr)
    {
        if (v->key == x)
        {
            return v;
        }
        else
        {
            return nullptr;
        }
    }

    if (v->left == nullptr)
    {
        return exists(x, v->right);
    }
    if (v->right == nullptr)
    {
        return exists(x, v->left);
    }
    if (v->key > x)
    {
        return exists(x, v->left);
    }
    if (v->key < x)
    {
        return exists(x, v->right);
    }
}
top* maxT(top* v)
{
    if(v->right == nullptr)
    {
        return v;
    }
    while(v->right != nullptr)
    {
        v = v->right;
    }
    return v;
}
top* minT(top* v)
{
    if(v->left == nullptr)
    {
        return v;
    }
    while(v->left != nullptr)
    {
        v = v->left;
    }
    return v;
}

top* next(int x, top* v)
{
    bool fl = false;
    top* tempTop = exists(x, v);
    if (tempTop == nullptr)
    {
        insertt(x, tree);
        fl = true;
        v = exists(x, v);
    }
    else
    {
        v = tempTop;
    }
    top* neXuy = exists(x, v);
    if (v->right != nullptr)
    {
        top* tempTop2 = minT(v->right);
        if (tempTop2->key == x)
        {
            if (fl)
            {
                deletee(x, neXuy);
            }
            return nullptr;
        }
        else
        {
            if (fl)
            {
                deletee(x, neXuy);
            }
            return tempTop2;
        }
    }
    top* parent = v->parent;
    while(parent != nullptr && v == parent->right)
    {
        v = parent;
        parent = parent->parent;
    }
    if (parent->key == x)
    {
        if (fl)
        {
            deletee(x, neXuy);
        }
        return nullptr;
    }
    else
    {
        if (fl)
        {
            deletee(x, neXuy);
        }
        return parent;
    }

}

top* prev(int x, top* v)
{
    insertt(x, tree);
    v = exists(x, v);
    if (v->left != nullptr)
    {
        top* tempTop2 = minT(v->right);
        if (tempTop2->key == x)
        {
            return nullptr;
        }
        else
        {
            return tempTop2;
        }
    }
    top* parent = v->parent;
    while(parent != nullptr && v == parent->left)
    {
        v = parent;
        parent = parent->parent;
    }
    if (parent->key == x)
    {
        return nullptr;
    }
    else
    {
        return parent;
    }
}
void deletee(int x, top* &v)
{
    if(v->left == nullptr && v->right == nullptr)
    {
            if (v->parent != nullptr)
            {
            if (v->parent->right->key == x)
            {
                v->parent->right = nullptr;
            }
            else
            {
                v->parent->left = nullptr;
            }
            }
            delete v;
            cout << "*";
            return;

    }
    if (v->left == nullptr)
    {
        top* tempTop = new top;
        tempTop = v->right;
        tempTop->parent = v->parent;
        if (v->parent != nullptr)
        {
        if (v->parent->right->key == x)
        {
            v->parent->right = nullptr;
        }
        else
        {
            v->parent->left = nullptr;
        }
        }
        delete v;
        v = tempTop;
        return;
    }
    if ( v->right == nullptr)
    {
        top* tempTop = new top;
        tempTop = v->left;
        tempTop->parent = v->parent;
        if (v->parent != nullptr)
        {
        if (v->parent->right->key == x)
        {
            v->parent->right = nullptr;
        }
        else
        {
            v->parent->left = nullptr;
        }
        }
        delete v;
        v = tempTop;
        return;
    }
    if(v->left != nullptr && v->right != nullptr)
    {
        top* tempTop = new top;
        tempTop = next(v->key, v);
        deletee(tempTop->key, tempTop);
        v->key = tempTop->key;
        return;
    }
}
void out(top* v)
{
    cout << " " << "*" << " ";
    cout << " " << v->key << " ";
    if (v->left != nullptr)
    {
        out(v->left);
    }
    if (v->right != nullptr)
    {
        out(v->right);
    }
}

int main()
{
    tree = nullptr;
    int tempInt;
    string tempStr;
    while (cin >> tempStr && cin >> tempInt)
    {
        if (tempStr == "insert")
        {
            insertt(tempInt, tree);
        }
        if (tempStr == "out")
        {
            out(tree);
        }
        if (tempStr == "delete")
        {
            top* vTemp = exists(tempInt, tree);
            if (vTemp == nullptr)
            {
                continue;
            }
            deletee(tempInt, vTemp);
        }
        if (tempStr == "exists")
        {

            if (exists(tempInt, tree) == nullptr)
            {
                cout << "false" << "\n";
            }
            else
            {
                cout << "true" << "\n";
            }
        }
        if (tempStr == "next")
        {
            cout << next(tempInt, tree)->key << "\n";
        }
        if (tempStr == "prev")
        {
            cout << prev(tempInt, tree) << "\n";
        }
    }
    return 0;
}

