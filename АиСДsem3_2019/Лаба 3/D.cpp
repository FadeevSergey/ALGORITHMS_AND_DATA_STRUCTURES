#include <iostream>

int main()
{
    std::string firstString;
    std::string secondString;
    std::cin >> firstString;
    std::cin >> secondString;
    int kmpSize = firstString.size() + secondString.size() + 1;
    int result[kmpSize];
    std::string KMP = firstString + '\0' + secondString;
    int left = 0, right = 0;

    for(int i = 1; i < kmpSize; ++i)
    {
        result[i] = std::max(0, std::min(right - i, result[i - left]));
        while(i + result[i] < kmpSize && KMP[result[i]] == KMP[i + result[i]])
        {
            result[i]++;
        }

        if(i + result[i] > right)
        {
            left = i;
            right = i + result[i];
        }
    }

    int resultNumber = 0;
    for(int i = firstString.size(); i < kmpSize; ++i)
    {
        if(result[i] == firstString.size())
        {
            resultNumber++;
        }
    }

    std::cout << resultNumber << '\n';
    for(int i = firstString.size() + 1; i < kmpSize; ++i)
    {
        if(result[i] == firstString.size())
        {
            std::cout << i - firstString.size() << ' ';
        }
    }
}
