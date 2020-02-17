#include <iostream>
#include <vector>

int main()
{
    std::vector<char> str;
    std::vector<int> result;
    char tempChar = std::cin.get();
    str.push_back(tempChar); result.push_back(0);
    for(int i = 1; (tempChar = std::cin.get()) != '\n'; ++i)
    {
        str.push_back(tempChar); result.push_back(0);
        int tempNumber = result[i - 1];
        while(tempNumber != 0 && str[i] != str[tempNumber])
        {
            tempNumber = result[tempNumber - 1];
        }

        if(str[i] == str[tempNumber])
        {
            tempNumber++;
        }
        result[i] = tempNumber;
    }

    int p = str.size() - result[str.size() - 1];
    std::cout << ((str.size() % p) ? str.size() : p);
}
