#include <iostream>
#include <algorithm>

//сложность работы алгоритма - О(n^2) в худшем случае
//алгоритм разобран в книге алгоритмы и структуры данных
//школа анализа данных

int n = 0;
int position = 0;

struct top
{
	int a;
	int b;
	int posInArray;
	int parent = -1;
	int left = -1;
	int right = -1;

};

top* arr = 0;
top* tree = 0;

struct {
	bool operator()(top& a, top& b) const
	{
	    if (a.a < b.a)
        {
            return true;
        }
        else
        {
            return false;
        }
	}
} comp;

void bild()
{
    std::cin >> n;
    arr = new top[n];
}
void scan()
{
    int a;
    int b;
    for (;position < n; position++)
	{
	    std::cin >> a >> b;
		top* tempTop = arr + position;
		tempTop->a = a;
		tempTop->b = -b;
		tempTop->posInArray = position;
	}
}
void insertt()
{
    int right = 0;
    std::sort(arr, arr + position, comp);
	for (int i = 1; i < n; i++)
	{
		if (arr[i].b < arr[i - 1].b)
		{
			arr[i - 1].right = i;
			arr[i].parent = i - 1;
			continue;
		}
        int par = arr[i - 1].parent;
        while (par != -1 && arr[i].b > arr[par].b)
        {
            par = arr[par].parent;
        }
        if (par == -1)
        {
            arr[right].parent = i;
            arr[i].left = right;
            right = i;
        }
        else
        {
            arr[i].left = arr[par].right;
            arr[arr[par].right].parent = i;
            arr[par].right = i;
            arr[i].parent = par;
        }
	}
}

void print()
{
    std::cout << "YES" << std::endl;
    int resultArray[3][position];
    for (int tempPos = 0; tempPos < position; tempPos++)
    {
        resultArray[0][arr[tempPos].posInArray] = arr[tempPos].parent != -1 ? arr[arr[tempPos].parent].posInArray + 1 : 0;
        resultArray[1][arr[tempPos].posInArray] = arr[tempPos].left   != -1 ? arr[arr[tempPos].left].posInArray + 1 : 0;
        resultArray[2][arr[tempPos].posInArray] = arr[tempPos].right  != -1 ? arr[arr[tempPos].right].posInArray + 1 : 0;
    }
    for (int i = 0; i < position; i++)
    {
        std::cout << resultArray[0][i] << " " << resultArray[1][i] << " " << resultArray[2][i] << "\n";
    }
//	for (int k = 0; k < position; k++)
//	{
//	    for (int tempPos = 0; tempPos < position; tempPos++)
//        {
//            if (arr[tempPos].posInArray == k)
//            {
//            std::cout << (arr[tempPos].parent != -1 ? arr[arr[tempPos].parent].posInArray + 1 : 0) << " " <<
//                    (arr[tempPos].left  != -1   ? arr[arr[tempPos].left].posInArray + 1 : 0) << " " <<
//                    (arr[tempPos].right != -1  ? arr[arr[tempPos].right].posInArray + 1 : 0) << "\n";
//                    break;
//            }
//        }
//	}
	delete[] arr;
}

int main()
{
	bild();
	scan();
	insertt();
	print();
	return 0;
}
