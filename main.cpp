#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
/***
 * @param Target Limit for Fib values
 * @return Sum of even numbers below target in fib sequence
 */

std::vector<unsigned long long> generate_next_prime(std::vector<unsigned long long> primes) {
    unsigned long long  start = primes[primes.size() - 1];
    unsigned long long i = start;
    while (true) {
        i += 2;
        bool prime = true;
        std::vector<unsigned long long>::iterator v = primes.begin();
        while (v != primes.end()) {
            if (i % *v == 0) {
                prime = false;
                break;
            }
            v++;
        }
        if (prime) {
            primes.push_back(i);
            return primes;
        }
    }
}

std::vector<unsigned long long> get_primes(unsigned long long target) {
    std::ofstream myfile;
    std::string filename = "../prime_numbers.txt";
    std::ifstream file(filename);
    std::vector<unsigned long long> primes;
    if (file.is_open()) {
        unsigned long long number;
        while (file >> number)
            primes.push_back(number);
    }
    file.close();
    if (primes[primes.size() - 1] < target) {
        while (primes[primes.size() - 1] < target) {
            primes = generate_next_prime(primes);
        }
        std::ofstream outfile(filename);
        for (std::vector<unsigned long long>::const_iterator i = primes.begin(); i != primes.end(); ++i) {
            outfile << "\n" << *i;
        }
    }
    return primes;
}

unsigned long long get_largest_prime(unsigned long long number) {
    unsigned long long limit;
    limit = std::sqrt(number);
    std::vector<unsigned long long> primes = get_primes(limit);
    unsigned long long largest_prime = 0;
    for (std::vector<unsigned long long>::const_iterator i = primes.begin(); *i <= limit; ++i) {
        if (number % *i == 0) {
            largest_prime = *i;
        }
    }
    return largest_prime;
}

int main(int argc, char **argv) {
    unsigned long long value = 600851475143;
    std::cout << get_largest_prime(value) << std::endl;
    return 0;
}