#include <iostream>

using namespace std;

bool is_palindrome(int num) {
    std::string s_num = std::to_string(num);
    int len = s_num.size();
    for (int i = 0; i < len; i++) {
        if (s_num[i] != s_num[len - 1 - i]) {

            return false;
        }
    }
    return true;
}

bool is_three_digit(int num) {
    return num > 99 & num < 1000;
}

bool three_digit_factors(int num) {
    for (int i =100; i < 1000; ++i) {
        if (num % i == 0) {
            if (is_three_digit(num / i)) {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char **argv) {
    for (int i = 999999; i > 99999; --i) {
        if (is_palindrome(i) & three_digit_factors(i)) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}