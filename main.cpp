#include <iostream>

/***
 *
 * @param Target Limit for Fib values
 * @return Sum of even numbers below target in fib sequence
 */

int fib (int a, int b, int sum, int limit) {
    int next_val = a + b;

    // should stop when range exceeds target limit
    if (next_val > limit) {
        return sum;
    }
    // want sum of only even number
    if (next_val % 2 == 0) {
        sum +=  next_val;
    }

    return fib(b, next_val, sum, limit);
}

int main(int argc, char** argv) {
    if (argc == 2) {
        const int limit = atoi(argv[1]);
        std::cout << fib(0,1,0, limit);
        return 0;
    }
    else {
        return 1;
    }

}
