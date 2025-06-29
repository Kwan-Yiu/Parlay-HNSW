#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>

#include "builder.cpp"

int main() {
    std::string metric = "Euclidian";
    std::string data_path = "../data/sift/sift_base.fbin";
    std::string output_path = "../data/sift/outputs/sift_32";
    uint32_t graph_degree = 32;
    uint32_t efc = 200;
    float m_l = 1.15f;
    float alpha = 1.15f;

    setenv("PARLAY_NUM_THREADS", std::to_string(48).c_str(), 1);

    auto build_start = std::chrono::high_resolution_clock::now();
    build_hnsw_index<float, Euclidian_Point<float>>(
        metric, data_path, output_path, graph_degree, efc, m_l, alpha);
    auto build_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> build_diff = build_end - build_start;
    std::cout << "build_hnsw_index (build phase) finished in "
              << build_diff.count() << " s" << std::endl;

    return 0;
}