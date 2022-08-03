#include <iostream>
#include <Windows.h>

class Counter {
private:
    int counts;
public:
    Counter() {
        counts = 1;
    };

    Counter(int initialValue) {
        counts = initialValue;
    }

    void decrease() {
        counts--;
    }

    void increase() {
        counts++;
    }

    int getCounts() {
        return counts;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string answer;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> answer;

    Counter counter{};

    if (answer == "да") {
        int initValue;
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> initValue;
        counter = Counter(initValue);
    }
    else {
        if (answer == "нет") {
            counter = Counter();
        }
        else {
            std::cout << "Ответ непонятен. Начальное значение счётчика установлено по умолчанию.\n";
            counter = Counter();
        }
    }
    
    bool stop = false;
    do {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> answer;
        if (answer == "+") {
            counter.increase();
        }
        else if (answer == "-") {
            counter.decrease();
        }
        else if (answer == "=") {
            std::cout << counter.getCounts() << "\n";
        }
        else if ((answer == "x") || (answer == "х")) {
            stop = true;
        }
        else {
            std::cout << "Команда не распознана\n";
        }
    } while (!stop);
    std::cout << "До свидания!" << "\n";
}