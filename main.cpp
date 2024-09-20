#include <iostream>
#include <fstream>
#include <pthread.h>
#include <vector>
#include <chrono>

const int MAX_THREADS = 2;

std::vector<std::vector<double>> A;
std::vector<double> b;
std::vector<double> c;
int n;
int num_threads = MAX_THREADS;

struct ThreadData {
    int start_row;
    int end_row;
};

void *calculate(void *arg) {
    auto *data = (ThreadData *) arg;

    for (int i = data->start_row; i < data->end_row; ++i) {
        c[i] = 0;
        for (int j = 0; j < n; ++j) {
            c[i] += A[i][j] * b[j];
        }
    }

    return nullptr;
}

int lab1() {
    std::string path = R"(C:\Files\Programing\C++\Parallel_Labs)";

    std::string fileA = path + R"(\finA_5000.txt)";
    std::string fileB = path + R"(\finB_5000.txt)";
    std::string fileC = path + R"(\finC_5000.txt)";

    std::cout << "Reading data from files" << std::endl;
    std::ifstream finA(fileA);
    std::ifstream finB(fileB);

    if (!finA || !finB) {
        std::cerr << "Error opening files!" << std::endl;
        return 1;
    }

    finA >> n;
    A.resize(n, std::vector<double>(n));
    b.resize(n);
    c.resize(n);

    std::cout << "Reading matrix A" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            finA >> A[i][j];
        }
    }

    std::cout << "Reading vector b" << std::endl;
    for (int i = 0; i < n; ++i) {
        finB >> b[i];
    }

    finA.close();
    finB.close();

    if (num_threads > n) {
        num_threads = n;
    }

    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];

    std::cout << "Preparing data for threads" << std::endl;
    int rows_per_thread = n / num_threads;
    int extra_rows = n % num_threads;
    int start_row = 0;

    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num_threads; ++i) {
        thread_data[i].start_row = start_row;
        thread_data[i].end_row = start_row + rows_per_thread;
        if (i < extra_rows) {
            thread_data[i].end_row++;
        }
        start_row = thread_data[i].end_row;

        pthread_create(&threads[i], nullptr, calculate, &thread_data[i]);
    }

    std::cout << "Waiting for threads to finish" << std::endl;
    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], nullptr);
    }

    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end_time - start_time;
    std::cout << "Time: " << duration.count() << " sec." << std::endl;

    std::cout << "Writing result to the file" << std::endl;
    std::ofstream fout(fileC);
    for (int i = 0; i < n; ++i) {
        fout << c[i] << std::endl;
    }
    fout.close();

    return 0;
}

int main() {
    return lab1();
}
