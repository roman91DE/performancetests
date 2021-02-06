#include <thread>
#include <functional>
#include <vector>
#include <stdio.h>
#include <iostream>

typedef unsigned long long ull;

void nthFib(int n) {
    int ind = 0;
    ull n_1 = 1;
    ull n_2 = 1;
    while (ind++ < n-1) {
        //printf("%d.th Fib = %d\n%d.th Fib = %d\n", ind, n_1, (ind+1), n_2);
        ind++;
        n_1 = n_1 + n_2;
        n_2 = n_1 + n_2;
    }
    printf("Done\n");
}

int main() {
    unsigned concurent_threads_supported = std::thread::hardware_concurrency();
    std::cout << "Parallel Threads = " << concurent_threads_supported << std::endl;
    std::vector <std::thread> worker;
    auto t0 = std::chrono::high_resolution_clock::now();
    for (int k = 1; k < 72; k++)
        worker.emplace_back(nthFib, 10000000000);
    for (auto &it: worker) {
        if (it.joinable())
            {it.join();}
    }
    auto t1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast <std::chrono::seconds> (t1 - t0).count();
    std::cout << "Duration = " << duration1 << " seconds\n";
    return 0;
}