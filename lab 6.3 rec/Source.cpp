#include <iostream>
#include <vector>
#include <limits>

// Функція для створення та заповнення масиву (вектора)
std::vector<int> createArray(int size) {
    std::vector<int> arr(size);
    std::cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
    return arr;
}

// Функція для виведення масиву у вигляді рядка
template <typename T>
void displayArray(const std::vector<T>& arr) {
    std::cout << "Array: ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Рекурсивна функція для знаходження максимального парного числа
int findMaxEvenRecursive(const std::vector<int>& arr, int index, int maxEven) {
    // Базовий випадок: якщо ми досягли кінця масиву, повертаємо поточний maxEven
    if (index == arr.size()) {
        return maxEven;
    }

    // Перевіряємо, чи є поточний елемент парним і більшим за поточний maxEven
    if (arr[index] % 2 == 0 && arr[index] > maxEven) {
        maxEven = arr[index];
    }

    // Рекурсивно перевіряємо наступний елемент масиву
    return findMaxEvenRecursive(arr, index + 1, maxEven);
}

int main() {
    using namespace::std;
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    // Перевірка на коректність введеного розміру
    if (size <= 0) {
        std::cout << "Size must be a positive integer.\n";
        return 1;
    }

    // Створюємо та виводимо масив
    std::vector<int> arr = createArray(size);
    displayArray(arr);

    // Знаходимо максимальне парне число за допомогою рекурсії
    int initialMax = std::numeric_limits<int>::min();
    int maxEven = findMaxEvenRecursive(arr, 0, initialMax);

    // Виводимо результат
    if (maxEven == std::numeric_limits<int>::min()) {
        std::cout << "There are no even numbers in the array.\n";
    }
    else {
        std::cout << "The largest even number: " << maxEven << std::endl;
    }

    return 0;
}
