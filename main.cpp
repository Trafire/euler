#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <fstream>

/***
 * @param Target Limit for Fib values
 * @return Sum of even numbers below target in fib sequence
 */

std::vector<unsigned long long> generate_next_prime(std::vector<unsigned long long> primes) {
    unsigned long long start = primes[primes.size() - 1];
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

std::vector<unsigned long long> get_prime_factors(unsigned long long num, std::vector<unsigned long long> factors) {
    std::vector<unsigned long long> primes = get_primes(num);


    if (std::find(primes.begin(), primes.end(), num) != primes.end()) {
        factors.push_back(num);
        return factors;
    }

    for (std::vector<unsigned long long>::const_iterator i = primes.begin(); *i <= num; ++i) {
        if (num % *i == 0) {
            num = num / *i;
            factors.push_back(*i);
            return get_prime_factors(num, factors);
        }
    }
    return factors;
}

void find_common_factors(std::vector<unsigned long long> factors, unsigned long long *common_factors) {
    int mycount;
    for (int i = 1; i < 21; ++i) {
        mycount = std::count(factors.begin(), factors.end(), i);
        if (*(common_factors + i) < mycount) {
            *(common_factors + i) = mycount;
        }

    }

}

int main(int argc, char **argv) {
    unsigned long long common_factors[21] = {0};

    std::vector<unsigned long long> factors;
    find_common_factors(factors, common_factors);



    for (int num = 2; num < 21; ++num) {
        std::vector<unsigned long long> factors;
        factors = get_prime_factors(num, factors);
        find_common_factors(factors, common_factors);

    }
    unsigned long long product = 1;
    for (int i = 1; i < 21; i++){
        for (int power = 0; power < common_factors[i]; ++power) {
            product = product * i;
        }
    }
    std::cout << product;
    return 0;
}