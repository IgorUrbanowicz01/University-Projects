#include <iostream>
#include <vector>
#include <cmath>

class PrimeNumbers {
private:
    std::vector<int> primes;

public:
    PrimeNumbers(int n) {
        std::vector<bool> is_prime(n + 1, true);
        is_prime[0] = false;
        is_prime[1] = false;

        for (int i = 2; i <= std::sqrt(n); i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (is_prime[i]) {
                primes.push_back(i);
            }
        }
    }

    int liczba(int m) {
        if (m < 0 || m >= primes.size()) {
            std::cout << m << " - liczba spoza zakresu\n";
            return -1;
        }

        return primes[m];
    }

    ~PrimeNumbers() {
        std::cout << "Object destroyed\n";
    }
};

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Brak argumentu\n";
        return 1;
    }

    int n = std::stoi(argv[1]);

    if (n < 2) {
        std::cerr << "Nieprawidłowy zakres\n";
        return 1;
    }

    PrimeNumbers prime_numbers(n);

    for (int i = 2; i < argc; i++) {
        int m = std::stoi(argv[i]);
        std::cout << m << " - " << prime_numbers.liczba(m) << "\n";
    }

    return 0;
}
