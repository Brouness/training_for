#include <iostream>
#include <string>

int ft_strlen(std::string& str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}

int main()
{
    std::cout << "hello world" << std::endl;
    std::string h = "hello";
    std::cout << h.length() << std::endl;
    return 0;
}
