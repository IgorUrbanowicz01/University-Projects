#include "WierszTroikatPaskala.hpp"
#include <stdexcept>
#include <iostream>
#include <cstdlib>

WierszTrojkataPascala::WierszTrojkataPascala(int n) : n_(n), wiersz_(nullptr) {
    if (n < 0) {
        throw std::invalid_argument("n  nie może być ujemne");
    }

    wiersz_ = new int[n + 1];

    wiersz_[0] = 1;
    for (int i = 1; i <= n; i++) {
        wiersz_[i] = (wiersz_[i - 1] * (n - i + 1)) / i;
    }
}

int WierszTrojkataPascala::wspolczynnik(int m) const {
    if (m < 0 || m > n_) {
        throw std::invalid_argument("liczba spoza zakresu");
    }
    return wiersz_[m];
}

WierszTrojkataPascala::~WierszTrojkataPascala() {
    delete[] wiersz_;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Za mała ilość argumentów" << std::endl;
        return 1;
    }


    int n = std::stoi(argv[1]);

    try {
        WierszTrojkataPascala wiersz(n);

        for (int i = 2; i < argc; i++) {
            try {
                int m = std::stoi(argv[i]);
                int wsp = wiersz.wspolczynnik(m);
                std::cout << m << " - " << wsp << std::endl;
            } catch (const std::exception& ex) {
                std::cout << argv[i] << " - " << ex.what() << std::endl;
            }
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "nieprawidłowe dane" << std::endl;
        return 1;
    }

    return 0;
}