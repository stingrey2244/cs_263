#include <iostream>
#include <vector>
#include <random>
#include <chrono>

constexpr size_t SIZE = 10'000'000;

// multiplies every element in the vector by a user-inputted scalar 
void scalar_multiply(float* a, int scalar) {
    for (size_t i = 0; i < SIZE; i++) {
        a[i] *= scalar;
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
    // take user input for scalar to multiply by
    int scalar;
    std::cout << "Enter the scalar value to multiply a vector by: \n";
    std::cin >> scalar;
    std::cin.ignore();
    
    std::vector<float> a(SIZE);

    // fills vector a with random integers
    std::mt19937 gen(1871);
    std::uniform_int_distribution<int> dist(-100, 100);
    fill_random(a, gen, dist);

    // time the execution of scalar_multiply function on vector a and print it to the command line
    auto start = std::chrono::high_resolution_clock::now();
    scalar_multiply(a.data(), scalar);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Time:\n" << duration.count() << " ms\n";

    return 0;
}
