#include "builder.cpp"
#include <string>
#include <iostream>
#include <chrono>

int main() {
    std::string metric = "Euclidian";
    std::string data_path = "../data/sift/sift_base.fbin";
    std::string output_path = "../data/sift/outputs/sift_32";
    uint32_t graph_degree = 32;
    uint32_t efc = 64;
    float m_l = 1.15f;
    float alpha = 1.15f;

    auto start = std::chrono::high_resolution_clock::now();

    build_hnsw_index<float, Euclidian_Point<float>>(
        metric, data_path, output_path, graph_degree, efc, m_l, alpha
    );

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "build_hnsw_index finished in " << diff.count() << " s" << std::endl;

    return 0;
} 