// Using Dynamic Programming for the Balo problem
// Input :
// + Backpack Weight, Name Items, Value, Weight
// n iput from keyboard
// Read File
#include "array"
#include "cassert"
#include "iostream"
#include "vector"
#define _CRT_SECURE_NO_WARNINGS

namespace dynamic_programming {

    namespace knapsack {
        template <size_t n>
        int maxKnapsackValue(const int capacity, const std::array<int, n>& weight,
            const std::array<int, n>& value) {
            std::vector<std::vector<int> > maxValue(n + 1,
                std::vector<int>(capacity + 1, 0));
            int items = sizeof(weight) / sizeof(weight[0]);
            for (size_t i = 0; i < items + 1; ++i) {
                for (size_t j = 0; j < capacity + 1; ++j) {
                    if (i == 0 || j == 0) {
                        maxValue[i][j] = 0;
                    }
                    else if (weight[i - 1] <= j) {
                        int profit1 = value[i - 1] + maxValue[i - 1][j - weight[i - 1]];
                        int profit2 = maxValue[i - 1][j];

                        maxValue[i][j] = std::max(profit1, profit2);
                    }
                    else {
                        maxValue[i][j] = maxValue[i - 1][j];
                    }
                }
            }
            return maxValue[items][capacity];
        }
    }
}

static void test() {
    const int n1 = 3;                             // number of items
    std::array<int, n1> weight1 = { 10, 20, 30 };   // weight of each item
    std::array<int, n1> value1 = { 60, 100, 120 };  // value of each item
    const int capacity1 = 50;                     // capacity of carrying bag
    const int max_value1 = dynamic_programming::knapsack::maxKnapsackValue(
        capacity1, weight1, value1);
    const int expected_max_value1 = 220;
    assert(max_value1 == expected_max_value1);
    std::cout << "Maximum Knapsack value with " << n1 << " items is "
        << max_value1 << std::endl;

}


int main() {
    // Testing
    test();
    return 0;
}