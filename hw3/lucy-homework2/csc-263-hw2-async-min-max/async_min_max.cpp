#include <iostream>
#include <vector>
#include <future>
#include <random>
#include <algorithm>

// find the minimum element in given range of a vector
template <typename Iterator>
auto array_min(Iterator begin, Iterator end) {
    auto length = std::distance(begin, end);

    // When vector is chunked into small enough sections, find smallest element directly
    if (length < 100'000) {
        // return the element from the iterator returned by std::min_element
        return *std::min_element(begin, end);
    }

    Iterator mid = begin + length / 2;

    // subdivide the vector and launch tasks to find the min in parallel.
    auto right_future = std::async(std::launch::async, array_min<Iterator>, mid, end);
    auto left_result = array_min(begin, mid);

    return std::min(left_result, right_future.get());
}

// find the maximum element in given range of a vector
template <typename Iterator>
auto array_max(Iterator begin, Iterator end) {
    auto length = std::distance(begin, end);

    // When vector is chunked into small enough sections, find smallest element directly
    if (length < 100'000) {
        // return the element from the iterator returned by std::max_element
        return *std::max_element(begin, end);
    }

    Iterator mid = begin + length / 2;

    // subdivide the vector and launch tasks to find the max in parallel.
    auto right_future = std::async(std::launch::async, array_max<Iterator>, mid, end);
    auto left_result = array_max(begin, mid);

    return std::max(left_result, right_future.get());
}

int main() {
    // initialize large random vector
    std::vector<float> data(10'000'000);

    unsigned int seed = 1871;
    std::mt19937 gen(seed);
    std::uniform_real_distribution<float> dist(-10'000, 10'000);

    for (float& val : data) {
        val = dist(gen);
    }

    // find the min and max values of the given vector
    auto min = array_min(data.begin(), data.end());
    auto max = array_max(data.begin(), data.end());

    std::cout << "Minimum value in array: " << min << "\n";
    std::cout << "Maximum value in array: " << max << "\n";
}