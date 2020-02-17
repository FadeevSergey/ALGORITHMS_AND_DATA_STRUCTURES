//https://neerc.ifmo.ru/wiki/index.php?title=%D0%94%D0%B5%D0%BA%D0%B0%D1%80%D1%82%D0%BE%D0%B2%D0%BE_%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE
//http://neerc.ifmo.ru/~sta/2012-2013/1-discrete-math/11-lab-trees.pdf problem C
//vk.com/privetha
#include <iostream>
#include <cstdlib>

using namespace std;

int counter = 0;

long long firstLong=123456789, secondLong=362436069, thirdLond=521288629;

int randomInt()
{
    long long tempLong;
    firstLong ^= firstLong << 16;
    firstLong ^= firstLong >> 5;
    firstLong ^= firstLong << 1;

    tempLong = firstLong;
    firstLong = secondLong;
    secondLong = thirdLond;
    thirdLond = tempLong ^ firstLong ^ secondLong;

    return thirdLond % INT_MAX;
}

struct TOP
{
    int value;
    int number;
    int SizeOfTree;
    TOP *left, *right;
};

TOP* tree = nullptr;
TOP* topPointer = 0;
TOP* newTop(int number)
{
    TOP* top = topPointer + counter++;
    top->value = randomInt();
    top->SizeOfTree = 1;
    top->number = number;
    return top;
}

int getSizeOfTree(TOP *tree)
{
    if (tree == nullptr)
    {
        return 0;
    }
    return tree->SizeOfTree;
}

void newSizeOfTree(TOP *tree)
{
    if (tree == nullptr)
    {
        return;
    }
    tree->SizeOfTree = getSizeOfTree(tree->left) + getSizeOfTree(tree->right) + 1;
}

TOP* merge(TOP* treeFirst, TOP *treeSecond)
{
    if (treeFirst == nullptr)
    {
        return treeSecond;
    }
    if (treeSecond == nullptr)
    {
        return treeFirst;
    }
    if (treeFirst->value > treeSecond->value)
    {
        treeFirst->right = merge(treeFirst->right, treeSecond);
        newSizeOfTree(treeFirst);
        return treeFirst;
    }
    else
    {
        treeSecond->left = merge(treeFirst, treeSecond->left);
        newSizeOfTree(treeSecond);
        return treeSecond;
    }
}

void split(TOP *tree, int x, TOP *&treeFirst, TOP *&treeSecond)
{
    if (tree == nullptr)
    {
        treeFirst = nullptr;
        treeSecond = nullptr;
        return;
    }
    if (getSizeOfTree(tree->left) < x)
    {
        split(tree->right, x - getSizeOfTree(tree->left) - 1, tree->right, treeSecond);
        treeFirst = tree;
    }
    else
    {
        split(tree->left, x, treeFirst, tree->left);
        treeSecond = tree;
    }
    newSizeOfTree(tree);
}

TOP* move(TOP *tree, int left, int r)
{
    TOP *tree1, *tree2, *tree3, *tree4;
    split(tree, r + 1, tree1, tree2);
    split(tree1, left, tree3, tree4);
    return merge(merge(tree4, tree3), tree2);
}

void printTree(TOP *tree)
{
    if (tree == nullptr)
    {
        return;
    }
    printTree(tree->left);
    cout << tree->number << " ";
    printTree(tree->right);
}

int main()
{
    topPointer = new TOP[100001 * sizeof(TOP)];
    int n;
    int m;
    int left;
    int right;
    TOP* tree = nullptr;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        tree = merge(tree, newTop(i));
    }
    for (int i = 0; i < m; i++)
    {
        cin >> left >> right;
        move(tree, left - 1, right - 1);
    }
    printTree(tree);
    delete[] topPointer;
    return 0;
}