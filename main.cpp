#include <iostream>

int euler1 (int target){
    int sum = 0;
    for (int i = 0; i < target; i++) {
        if (i % 5 == 0 | i % 3 == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    std::cout << euler1(1000);
    return 0;
}
