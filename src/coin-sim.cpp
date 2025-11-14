#include "coin-sim.hpp"
#include <chrono>

CoinSimulator::CoinSimulator(double p)
    : p_(p), rng_(std::random_device{}()), dist_(p) {}

int CoinSimulator::run(int n) {
    int heads = 0;
    for (int i = 0; i < n; i++) {
        if (dist_(rng_)) heads++;
    }
    return heads;
}