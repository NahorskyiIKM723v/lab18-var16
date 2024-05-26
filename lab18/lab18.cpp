#include <iostream>
#include <Windows.h>
using namespace std;

class Matrix {
private:
    int data[3][5];
 public:
    Matrix() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 5; ++j)
                data[i][j] = 0;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 5; ++j)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 5; ++j)
                result.data[i][j] = data[i][j] * other.data[i][j];
        return result;
    }

    bool operator==(const Matrix& other) const {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 5; ++j)
                if (data[i][j] != other.data[i][j])
                    return false;
        return true;
    }

    void print() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    void input() {
        cout << "Введіть значення для матриці 3x5:" << endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                cin >> data[i][j];
            }
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Matrix matrix1, matrix2;

    cout << "Введення для Матриці 1:" << endl;
    matrix1.input();
    cout << "Введення для Матриці 2:" << endl;
    matrix2.input();
    cout << "Матриця 1:" << endl;
    matrix1.print();
    cout << "Матриця 2:" << endl;
    matrix2.print();

    Matrix resultSubtraction = matrix1 - matrix2;
    cout << "Результат віднімання (Матриця 1 - Матриця 2):" << endl;
    resultSubtraction.print();

    Matrix resultMultiplication = matrix1 * matrix2;
    cout << "Результат множення (Матриця 1 * Матриця 2):" << endl;
    resultMultiplication.print();

    bool isEqual = (matrix1 == matrix2);
    cout << "Матриця 1 та Матриця 2 " << (isEqual ? "однакові" : "різні") << "." << endl;

    return 0;
}
