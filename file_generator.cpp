//#include <iostream>
//#include <fstream>
//#include <string>
//#include <sstream>
//#include <cstdlib>
//#include <ctime>
//
//// Функция для генерации случайного числа в диапазоне от -100 до 100
//double generateRandomNumber() {
//    return (std::rand() % 20001 - 10000) / 100.0;
//}
//
//// Функция для генерации файла с матрицей A и вектором b
//void generateTestFile(const std::string &path, const std::string &mName, const std::string &vName, int n) {
//    // Формируем полные пути к файлам
//    std::string fullMatrixFileName = path + "/" + mName;
//    std::string fullVectorFileName = path + "/" + vName;
//
//    // Открытие файлов для записи матрицы A и вектора b
//    std::ofstream matrixFile(fullMatrixFileName);
//    std::ofstream vectorFile(fullVectorFileName);
//
//    if (!matrixFile || !vectorFile) {
//        std::cerr << "Ошибка открытия файлов для записи!" << std::endl;
//        return;
//    }
//
//    // Записываем размер матрицы и вектора в файлы
//    matrixFile << n << std::endl;
//    vectorFile << n << std::endl;
//
//    // Строковый поток для буферизации данных
//    std::stringstream matrixBuffer;
//
//    // Заполнение буфера данными для матрицы A
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            matrixBuffer << generateRandomNumber() << " ";
//        }
//        matrixBuffer << "\n";
//    }
//
//    // Запись буфера в файл
//    matrixFile << matrixBuffer.str();
//
//    // Заполнение и запись вектора b
//    for (int i = 0; i < n; ++i) {
//        vectorFile << generateRandomNumber() << std::endl;
//    }
//
//    // Закрытие файлов
//    matrixFile.close();
//    vectorFile.close();
//
//    std::cout << "Сгенерированы файлы: " << fullMatrixFileName << " и " << fullVectorFileName << std::endl;
//}
//
//int file_generator() {
//    std::srand(std::time(0));
//
//    int sizes[] = {10, 100, 1000, 5000};  // Размеры матриц и векторов для генерации
//
//    // Путь для сохранения файлов (например, "./test_data/")
//    std::string path = R"(C:\Files\Programing\C++\Parallel_Labs)";
//
//    // Генерация тестовых файлов для каждого размера
//    for (int n: sizes) {
//        std::string matrixFileName = "finA_" + std::to_string(n) + ".txt";
//        std::string vectorFileName = "finB_" + std::to_string(n) + ".txt";
//        generateTestFile(path, matrixFileName, vectorFileName, n);
//        std::cout << "End with " << n << std::endl;
//    }
//
//    return 0;
//}
//
//int main() {
//    return file_generator();
//}
