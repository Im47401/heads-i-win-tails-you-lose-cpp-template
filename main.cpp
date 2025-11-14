#include <iostream>
#include <vector>
#include <chrono>
#include "src/coin-sim.hpp"

int main() {

    std::vector<int> n_values = {10, 100};
    std::vector<int> m_values = {1, 2, 3, 4};
    std::vector<double> p_values = {0.5, 0.75};

    std::cout << "Number of Flips (n) | Trial Number (m) | Probability (p) | Heads\n";
    std::cout << "---------------------------------------------------------------\n";

    for (double p : p_values) {
        CoinSimulator sim(p);

        for (int n : n_values) {
            for (int m : m_values) {

                auto start = std::chrono::high_resolution_clock::now();

                int heads = sim.run(n);

                auto end = std::chrono::high_resolution_clock::now();
                double ms = std::chrono::duration<double, std::milli>(end - start).count();

                std::cout << n << " \t\t\t"
                          << m << "\t\t\t"
                          << p << "\t\t"
                          << heads << "\t ("
                          << ms << " ms)"
                          << "\n";
            }
        }
    }

    return 0;
}