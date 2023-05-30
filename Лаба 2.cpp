#include <iostream>

struct Pair {
    int first;
    int second;
};

class Rational {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    void reduce() {
        int gcdValue = gcd(numerator, denominator);
        numerator /= gcdValue;
        denominator /= gcdValue;
    }

public:
    Rational() : numerator(0), denominator(1) {}

    Rational(int num, int denom) : numerator(num), denominator(denom) {
        reduce();
    }

    Rational(const Pair& p) : numerator(p.first), denominator(p.second) {
        reduce();
    }

    Rational add(const Rational& other) const {
        int resultNum = numerator * other.denominator + other.numerator * denominator;
        int resultDenom = denominator * other.denominator;
        return Rational(resultNum, resultDenom);
    }

    Rational sub(const Rational& other) const {
        int resultNum = numerator * other.denominator - other.numerator * denominator;
        int resultDenom = denominator * other.denominator;
        return Rational(resultNum, resultDenom);
    }

    Rational mul(const Rational& other) const {
        int resultNum = numerator * other.numerator;
        int resultDenom = denominator * other.denominator;
        return Rational(resultNum, resultDenom);
    }

    Rational div(const Rational& other) const {
        int resultNum = numerator * other.denominator;
        int resultDenom = denominator * other.numerator;
        return Rational(resultNum, resultDenom);
    }

    bool equal(const Rational& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool greater(const Rational& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }

    bool less(const Rational& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    void print() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }
};

int main() {
    Rational r1(3, 4);
    Rational r2(1, 2);

    Rational sum = r1.add(r2);
    sum.print();  // Output: 5/4

    Rational diff = r1.sub(r2);
    diff.print();  // Output: 1/4

    Rational product = r1.mul(r2);
    product.print();  // Output: 3/8

    Rational quotient = r1.div(r2);
    quotient.print();  // Output: 3/2

    bool isEqual = r1.equal(r2);
    std::cout << std::boolalpha << isEqual << std::endl;  // Output: false

    bool isGreater = r1.greater(r2);
    std::cout << std::boolalpha << isGreater << std::endl;  // Output: true

    bool isLess = r1.less(r2);
    std::cout << std::boolalpha << isLess << std::endl;  // Output: false

    return 0;
}