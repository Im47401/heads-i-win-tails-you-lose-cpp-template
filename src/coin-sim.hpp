#pragma once
#include <random>

class CoinSimulator {
public:
    CoinSimulator(double p);

    
    int run(int n);

private:
    double p_;
    std::mt19937 rng_;
    std::bernoulli_distribution dist_;
};