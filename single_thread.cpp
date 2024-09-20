#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

std::vector<std::vector<double>> A;
std::vector<double> b;
std::vector<double> c;
int n;

void calculate_single_thread() {
    for (int i = 0; i < n; ++i) {
        c[i] = 0;
        for (int j = 0; j < n; ++j) {
            c[i] += A[i][j] * b[j];
        }
    }
}

int lab1_single_thread() {
    std::string path = R"(C:\Files\Programing\C++\Parallel_Labs)";

    std::string fileA = path + R"(\finA_5000.txt)";
    std::string fileB = path + R"(\finB_5000.txt)";
    std::string fileC = path + R"(\finC_5000_single_thread.txt)";

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

    // Засекаем время начала вычислений
    auto start_time = std::chrono::high_resolution_clock::now();

    // Выполняем вычисления в одном потоке
    calculate_single_thread();

    // Засекаем время окончания вычислений
    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end_time - start_time;
    std::cout << "Time: " << duration.count() << " sec." << std::endl;

    // Запись результата в файл
    std::cout << "Writing result to the file" << std::endl;
    std::ofstream fout(fileC);
    for (int i = 0; i < n; ++i) {
        fout << c[i] << std::endl;
    }
    fout.close();

    return 0;
}

int main() {
    return lab1_single_thread();
}
