#include <iostream>  
#include <string>  
  
int main() 
{  
    std::string line;  
    std::getline(std::cin, line);  
    std::cout << "You entered: " << line << std::endl;  
    return 0;  
}
