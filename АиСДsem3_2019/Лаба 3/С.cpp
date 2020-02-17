#include <iostream>

int main()
{
    std::string str;
    std::cin >> str;
    int result[str.size()];
    int left = 0, right = 0;

    for(int i = 1; i < str.size(); ++i)
    {
        result[i] = std::max(0, std::min(right - i, result[i - left]));
        while(i + result[i] < str.size() && str[result[i]] == str[i + result[i]])
        {
            result[i]++;
        }

        if(i + result[i] > right)
        {
            left = i;
            right = i + result[i];
        }
    }

    for(int i = 1; i < str.size(); ++i)
    {
        std::cout << result[i] << ' ';
    }
}
