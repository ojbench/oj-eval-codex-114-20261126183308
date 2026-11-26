#include "../src.hpp"
#include <cassert>
#include <climits>
#include <random>
#include <vector>

int main() {
    int **p = nullptr;
    Init(p, 0);
    Clear(p, 0);
    assert(p == nullptr);

    const int n = 101;
    Init(p, n);
    std::vector<std::vector<int>> reference(n + 1);
    std::mt19937 random(1728);
    for (int i = 0; i < 1000000; ++i) {
        int x = 1 + random() % n;
        int value = (i % 2 == 0) ? INT_MIN + i : INT_MAX - i;
        Add_element(p, x, value);
        reference[x].push_back(value);
        int k = 1 + random() % reference[x].size();
        assert(Get_element(p, x, k) == reference[x][k - 1]);
    }
    for (int x = 1; x <= n; ++x) {
        for (int k = 1; k <= static_cast<int>(reference[x].size()); ++k) {
            assert(Get_element(p, x, k) == reference[x][k - 1]);
        }
    }
    Clear(p, n);

    Init(p, 1000000);
    for (int i = 1; i <= 1000000; ++i) Add_element(p, 1000000, i);
    for (int i = 1; i <= 1000000; ++i) assert(Get_element(p, 1000000, i) == i);
    Clear(p, 1000000);

    Init(p, 1000000);
    for (int i = 1; i <= 1000000; ++i) Add_element(p, i, -i);
    for (int i = 1; i <= 1000000; ++i) assert(Get_element(p, i, 1) == -i);
    Clear(p, 1000000);
    assert(p == nullptr);
}
