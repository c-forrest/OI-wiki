#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
#include <tuple>

// Find the maximum of unimodel function F.
// The domain of F must be consecutive integer values of type T.
template <typename T, typename F>
std::pair<T, decltype(std::declval<F>()(std::declval<T>()))>
golden_section_search(T ll, T rr, F func) {
    constexpr long double phi = (sqrtl(5.0l) - 1) / 2;
    T ml = ll + (rr - ll) * (1 - phi);
    T mr = ll + (rr - ll) * phi;
    auto fl = func(ml), fr = func(mr);
    while (ml < mr) {
        if (fl > fr) {
            rr = mr;
            mr = ml;
            fr = fl;
            ml = ll + (rr - ll) * (1 - phi);
            fl = func(ml);
        } else {
            ll = ml;
            ml = mr;
            fl = fr;
            mr = ll + (rr - ll) * phi;
            fr = func(mr);
        }
    }
    for (auto i = ll; i <= rr; ++i) {
        auto fi = func(i);
        if (fi > fr) {
            fr = fi;
            mr = i;
        }
    }
    return std::make_pair(mr, fr);
};

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    // Calculate h(k) = max_x f(x) - k * g(x).
    auto calc = [&](int k) -> long long {
        long long dp[2] = { 0, -0x3f3f3f3f };
        for (int i = 1; i <= n; ++i) {
            std::tie(dp[0], dp[1]) = std::make_pair(
                std::max(dp[0], dp[1]),
                dp[0] + a[i] + k
            );
        }
        return std::max(dp[0], dp[1]);
    };
    // Solve the dual problem to find v(m).
    // Implemented as a minimization problem by adding negative signs.
    // Only consider tangent lines of negative slopes to ignore the part 
    //     of the curve after the peak.
    auto res = -golden_section_search(-1000000, 0, [&](int k) -> long long {
        return -calc(k) + (long long)k * m;
    }).second;
    std::cout << res << std::endl;
    return 0;
}
