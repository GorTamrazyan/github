#include <iostream>

int lcm(int a, int b) {
    int c = a, d = b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }     
    return c * d / a;
}

int main() {
    int num1, num2;
    
    std::cout << "input 2 number: ";
    std::cin >> num1 >> num2;
    
    int result = lcm(num1, num2);
    
    std::cout << "Result: " << result << std::endl;
    
    return 0;
}
