#include <iostream>
#include <string>

class LongInteger {
private:
    int high; // Старшая часть числа
    int low; // Младшая часть числа

public:
    // Конструктор по умолчанию
    LongInteger() : high(0), low(0) {}

    // Конструктор инициализации целым числом
    LongInteger(int number) : high(number), low(0) {}

    // Конструктор инициализации строкой цифр
    LongInteger(const std::string& number) {
        // Преобразуем строку в целое число
        int value = std::stoi(number);
        high = value;
        low = 0;
    }

    // Метод сравнения на равенство
    bool operator==(const LongInteger& other) const {
        return (high == other.high) && (low == other.low);
    }

    // Метод сравнения на больше
    bool operator>(const LongInteger& other) const {
        if (high > other.high)
            return true;
        else if (high == other.high)
            return low > other.low;
        else
            return false;
    }

    // Метод сложения
    LongInteger operator+(const LongInteger& other) const {
        LongInteger result;
        result.high = high + other.high;
        result.low = low + other.low;

        if (result.low > 999999999) {
            result.high += 1;
            result.low -= 1000000000;
        }

        return result;
    }

    // Функция преобразования в строку
    std::string toString() const {
        std::string result = std::to_string(high);

        if (low != 0) {
            std::string lowStr = std::to_string(low);
            result += std::string(9 - lowStr.length(), '0') + lowStr;
        }

        return result;
    }

    // Операция вывода в поток
    friend std::ostream& operator<<(std::ostream& os, const LongInteger& num) {
        os << num.toString();
        return os;
    }

    // Операция ввода из потока
    friend std::istream& operator>>(std::istream& is, LongInteger& num) {
        std::string input;
        is >> input;
        num = LongInteger(input);
        return is;
    }
};

int main() {
    LongInteger num1(1234567890);
    LongInteger num2("9876543210");
    LongInteger num3;

    std::cout << "num1: " << num1 << std::endl;
    std::cout << "num2: " << num2 << std::endl;
    std::cout << "num3: " << num3 << std::endl;

    std::cout << "Enter a LongInteger number: ";
    std::cin >> num3;
    std::cout << "num3: " << num3 << std::endl;

    if (num1 == num2)
        std::cout << "num1 is equal to num2" << std::endl;
    else if (num1 > num2)
        std::cout << "num1 is greater than num2" << std::endl;
    else
        std::cout << "num1 is less than num2" << std::endl;

    LongInteger sum = num1 + num2;
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}