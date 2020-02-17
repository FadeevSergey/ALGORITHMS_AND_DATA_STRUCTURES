// https://www.e-olymp.com/ru/problems/687
// vk.com/privetha
#include <iostream>

class Node
{
public:
    Node *left = nullptr;
    Node *right = nullptr;
    int k;
    int height = 1;
    int weight = 1;
    Node(int k)
    {
        this->k = k;
    }
};

int weight(Node* t)
{
    if (t == nullptr) {return 0;}
    else {return t->weight;}
}

int level(Node* t)
{
    if (t == nullptr) {return 0;}
    else {return t->height;}
}

int maxK(Node* t, int k)
{
    if (weight(t->right) + 1 == k) {return t->k;}
    if (weight(t->right) + 1 < k) {return maxK(t->left, k - weight(t->right) - 1);}
    else {return maxK(t->right, k);}
}

Node* rightTurn(Node* t)
{
    Node* tempNode = t->left;
    t->left = tempNode->right;
    tempNode->right = t;
    t->height = std::max(level(t->left), level(t->right)) + 1;
    t->weight = weight(t->left) + weight(t->right) + 1;
    tempNode->height = std::max(level(tempNode->left), level(tempNode->right)) + 1;
    tempNode->weight = weight(tempNode->left) + weight(tempNode->right) + 1;
    return tempNode;
}

Node* leftTurn(Node* t)
{
    Node* tempNode = t->right;
    t->right = tempNode->left;
    tempNode->left = t;
    t->height = std::max(level(t->left), level(t->right)) + 1;
    t->weight = weight(t->left) + weight(t->right) + 1;
    tempNode->height = std::max(level(tempNode->left), level(tempNode->right)) + 1;
    tempNode->weight = weight(tempNode->left) + weight(tempNode->right) + 1;
    return tempNode;
}

Node* update(Node* t)
{
    t->height = std::max(level(t->left), level(t->right)) + 1;
    t->weight = weight(t->left) + weight(t->right) + 1;
    if ((level(t->right) - level(t->left)) == 2)
    {
        if ((level((t->right)->right) - level((t->right)->left)) < 0) {t->right = rightTurn(t->right);}
        return leftTurn(t);
    }
    if ((level(t->right) - level(t->left)) == -2)
    {
        if ((level((t->left)->right) - level((t->left)->left)) > 0) {t->left = leftTurn(t->left);}
        return rightTurn(t);
    }
    return t;
}

Node* insert(Node *t, int k)
{
    if (t == nullptr) {return new Node(k);}
    if (k < t->k) {t->left = insert(t->left, k);}
    else {t->right = insert(t->right, k);}
    return update(t);
}

Node* minNode(Node* t)
{
    while (t->left != nullptr) {t = t->left;}
    return t;
}

Node* kxm(Node* t)
{
    if (t->left == nullptr) {return t->right;}
    t->left = kxm(t->left); {return update(t);}
}

Node* remove(Node* t, int k)
{
    if (t == nullptr) {return nullptr;}
    if (k < t->k) {t->left = remove(t->left, k);}
    else if (k > t->k) {t->right = remove(t->right, k);}
    else if (k == t->k)
    {
        Node* left = t->left;
        Node* right = t->right;
        delete t;
        if (right == nullptr) {return left;}
        Node* z = minNode(right);
        z->right = kxm(right);
        z->left = left;
        return update(z);
    }
    return update(t);
}

int main()
{
    Node* tree = nullptr;
    int n;
    int c;
    int k;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> c >> k;
        switch (c)
        {
            case 1:
                tree = insert(tree, k);
                break;
            case 0:
                std::cout << maxK(tree, k) <<std::endl;
                break;
            case -1:
                tree = remove(tree, k);
        }
    }
    return 0;
}