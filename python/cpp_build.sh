g++ -g -DSTATS -DHOMEGROWN -pthread -mcx16 -O1 -std=c++17 -march=native -DNDEBUG -I . -fPIC test_hnsw.cpp -o test_hnsw -ldl -L/usr/local/lib
