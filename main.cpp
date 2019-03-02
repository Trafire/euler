#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    int sum = 0;
    int square = 0;
    for (int i = 1; i <= 100; ++i) {
        sum += i * i;
        square += i;
    }
    square = square * square;
    cout << square - sum;
    return 0;
}