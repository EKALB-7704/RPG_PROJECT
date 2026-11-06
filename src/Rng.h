#pragma once

#include <cstdint>
#include <random>

// The game's one source of randomness. Construct a single instance in main()
// and pass it by reference; tests construct their own with a fixed seed.
class Rng {
public:
    explicit Rng(std::uint32_t seed) : engine_(seed) {}

    int range(int lo, int hi);  // inclusive at both ends

private:
    std::mt19937 engine_;
};
