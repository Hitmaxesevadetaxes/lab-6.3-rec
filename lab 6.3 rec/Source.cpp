#include <iostream>
#include <vector>
#include <limits>

// ������� ��� ��������� �� ���������� ������ (�������)
std::vector<int> createArray(int size) {
    std::vector<int> arr(size);
    std::cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
    return arr;
}

// ������� ��� ��������� ������ � ������ �����
template <typename T>
void displayArray(const std::vector<T>& arr) {
    std::cout << "Array: ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// ���������� ������� ��� ����������� ������������� ������� �����
int findMaxEvenRecursive(const std::vector<int>& arr, int index, int maxEven) {
    // ������� �������: ���� �� ������� ���� ������, ��������� �������� maxEven
    if (index == arr.size()) {
        return maxEven;
    }

    // ����������, �� � �������� ������� ������ � ������ �� �������� maxEven
    if (arr[index] % 2 == 0 && arr[index] > maxEven) {
        maxEven = arr[index];
    }

    // ���������� ���������� ��������� ������� ������
    return findMaxEvenRecursive(arr, index + 1, maxEven);
}

int main() {
    using namespace::std;
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    // �������� �� ���������� ��������� ������
    if (size <= 0) {
        std::cout << "Size must be a positive integer.\n";
        return 1;
    }

    // ��������� �� �������� �����
    std::vector<int> arr = createArray(size);
    displayArray(arr);

    // ��������� ����������� ����� ����� �� ��������� ������
    int initialMax = std::numeric_limits<int>::min();
    int maxEven = findMaxEvenRecursive(arr, 0, initialMax);

    // �������� ���������
    if (maxEven == std::numeric_limits<int>::min()) {
        std::cout << "There are no even numbers in the array.\n";
    }
    else {
        std::cout << "The largest even number: " << maxEven << std::endl;
    }

    return 0;
}
