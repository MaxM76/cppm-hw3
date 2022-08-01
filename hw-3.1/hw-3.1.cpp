#include <iostream>
#include <Windows.h>

class Calculator {
public:
    double num1;
    double num2;

    double add() {
        return num1 + num2;
    }

    double multiply() {
        return num1 * num2;
    }

    double subtract_1_2() {
        return num1 - num2;
    }

    double subtract_2_1() {
        return num2 - num1;
    }

    double divide_1_2() {
        return num1 / num2;
    }

    double divide_2_1() {
        return num2 / num1;
    }

    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        }
        else {
            return false;
        }
    }

    bool set_num2(double num2) {
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        }
        else {
            return false;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Calculator calculator;
    double num;
    boolean error = false;

    while (true) {
        do {
            if (error) {
                std::cout << "Неверный ввод!\n";
            }
            std::cout << "Введите num1: ";
            std::cin >> num;
            error = !calculator.set_num1(num);
        } while (error);
        error = false;

        do {
            if (error) {
                std::cout << "Неверный ввод!\n";
            }
            std::cout << "Введите num2: ";
            std::cin >> num;
            error = !calculator.set_num2(num);
        } while (error);
        error = false;

        std::cout << "num1 + num2 = " << calculator.add() << "\n";
        std::cout << "num1 - num2 = " << calculator.subtract_1_2() << "\n";
        std::cout << "num2 - num1 = " << calculator.subtract_2_1() << "\n";
        std::cout << "num1 * num2 = " << calculator.multiply() << "\n";
        std::cout << "num1 / num2 = " << calculator.divide_1_2() << "\n";
        std::cout << "num2 / num1 = " << calculator.divide_2_1() << "\n";
    }
}