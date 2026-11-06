#include "Rng.h"
#include <cassert>

int Rng::range(int lo, int hi) {
    assert(lo <= hi);  // uniform_int_distribution(lo, hi) is UB otherwise
    return std::uniform_int_distribution<int>(lo, hi)(engine_);
}
