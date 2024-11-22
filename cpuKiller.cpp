#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void heavyLoad(int id) {
    while (true) {
        volatile double x = 0;
        for (int i = 0; i < 100000000; i++) {
            x += 1.0 / (i + 1);
        }
        cout << id << endl;
    }
}


int main()
{

    unsigned int numThreads = thread::hardware_concurrency();
    cout << "Anzahl der verfügbar Threads: " << numThreads << endl;

    vector<thread> threads;

    for (unsigned int i = 0; i < numThreads; i++) {
        threads.emplace_back(heavyLoad, i + 1);
    }

    for (auto& t: threads) {
        t.join();
    }

    return 0;
}
