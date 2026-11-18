#include <iostream>
#include <vector>
#include <random>
#include <chrono>

constexpr size_t SIZE = 10'000'000;

// adds each element in the vector b to vector a
void add(float* a, float* b) {
    for (size_t i = 0; i < SIZE; i++) {
        a[i] += b[i];
    }
}

// fills a given vector with random integers
void fill_random(std::vector<float>& v, std::mt19937& gen,
    std::uniform_int_distribution<int>& dist) {
    for (auto& val : v) {
        val = dist(gen);
    }
}

int main() {
    std::vector<float> a(SIZE), b(SIZE);

    // fills vectors a and b with random integers
    std::mt19937 gen(1871);
    std::uniform_int_distribution<int> dist(-100, 100);
    fill_random(a, gen, dist);
    fill_random(b, gen, dist);

    // time the execution of the add function on vector a and b and print it to the command line
    auto start = std::chrono::high_resolution_clock::now();
    add(a.data(), b.data());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Time:\n" << duration.count() << " ms\n";

    return 0;
}
