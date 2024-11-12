#include <cmath>
#include <iomanip>
#include <iostream>

namespace {
const int kTaskOne = 1;
const int kTaskTwo = 2;
const int kTaskThree = 3;
const int kTaskFour = 4;

const int kPrecision = 6;
const int kPrecisionX = 1;
const int kPrecisionTaskFour = 10;
}  // namespace

void task1() {
    const int kStep = 5;

    int n = 0;
    int m = 0;

    std::cout << "Введите значение n: ";
    std::cin >> n;
    std::cout << "Введите значение m (m < n): ";
    std::cin >> m;

    if (m >= n) {
        std::cout << "Ошибка: m должно быть меньше n!" << std::endl;
        return;
    }

    if (m == 0) {
        std::cout << "Ошибка: n не может быть равен 0!" << std::endl;
        return;
    }

    int sum = 0;
    for (int i = kStep; i <= n; i += kStep) {
        if (i % m != 0) {
            sum += i;
        }
    }

    std::cout << "Сумма натуральных чисел: " << sum << std::endl;
}

void task2() {
    const int kPositiveAMultiplicationLowerBoundary = 2;
    const int kPositiveAMultiplicationUpperBoundary = 8;
    const int kPositiveAStep = 2;

    const int kNegativeAMultiplicationLowerBoundary = 3;
    const int kNegativeAMultiplicationUpperBoundary = 9;
    const int kNegativeAStep = 3;

    double a = 0.0;
    std::cout << "Введите значение a: ";
    std::cin >> a;

    double product = 1.0;

    if (a >= 0.0) {
        for (int i = kPositiveAMultiplicationLowerBoundary; i <= kPositiveAMultiplicationUpperBoundary; i += kPositiveAStep) {
            product *= i * i;
        }
        product -= a;
    } else {
        for (int i = kNegativeAMultiplicationLowerBoundary; i <= kNegativeAMultiplicationUpperBoundary; i += kNegativeAStep) {
            product *= (i - 2);
        }
    }

    std::cout << std::fixed << std::setprecision(kPrecision) << "Значение S: " << product << std::endl;
}

void task3() {
    double x = 0.0;
    const double h = 0.2;
    const double kEpsilon = 1e-6;
    const int kSetOutputLengthBetweenNumber = 11;
    const int kSetOutputFirstLeeterOffsetWidth = 2;
    const int kSetOutputLengthBetweenLetters = 11;
    const int kSetOutputLastLeeterOffsetWidth = 12;

    std::cout << std::setw(kSetOutputFirstLeeterOffsetWidth) << "x" << std::setw(kSetOutputLengthBetweenLetters) << "Y(x)"
              << std::setw(kSetOutputLengthBetweenLetters) << "S(x)" << std::setw(kSetOutputLastLeeterOffsetWidth) << "N" << std::endl;

    while (x <= 1.0) {
        double Y = std::cos(2 * x);
        double S = 1.0;
        double k = 1.0;
        int n = 0;

        while (k > kEpsilon) {
            ++n;
            k *= 2 * x * x / (n * (2 * n - 1));
            S += n % 2 == 0 ? k : -k;
        }

        std::cout << std::fixed << std::setprecision(kPrecisionX) << x << std::setprecision(kPrecision) << std::setw(kSetOutputLengthBetweenNumber)
                  << Y << std::setw(kSetOutputLengthBetweenNumber) << S << std::setw(kSetOutputLengthBetweenNumber) << n << std::endl;
        x += h;
    }
}

void task4() {
    int n = 0;
    double x = 0;
    const int kIntermediateValue1 = 3;
    const int kIntermediateValue2 = 5;
    const int kIntermediateValue3 = 10;
    const int kStartingValueI = 1;

    std::cout << "Введите натуральное значение n: ";
    std::cin >> n;
    std::cout << "Введите значение x: ";
    std::cin >> x;

    if (n < 1) {
        std::cout << "Ошибка: n должно быть натуральным!" << std::endl;
        return;
    }

    double y = 1.0;
    double k = 1.0;

    std::cout << "Промежуточные суммы:" << std::endl;

    for (int i = kStartingValueI; i < n; ++i) {
        k *= (x * x) / (2 * i * (2 * i - 1));
        y += k;

        if (i == kIntermediateValue1 || i == kIntermediateValue2 || i == kIntermediateValue3) {
            std::cout << "Сумма при n = " << std::setprecision(kPrecisionTaskFour) << i << ": " << std::setprecision(kPrecisionTaskFour) << y
                      << std::endl;
        }
    }
    std::cout << "Полученный результат: " << std::setprecision(kPrecisionTaskFour) << y << std::endl;
}

int main() {
    char continueExecution = 'y';
    while (continueExecution == 'y') {
        std::cout << "Введите номер задачи, который хотите решить. ";
        int task = 0;

        std::cin >> task;

        switch (task) {
            case kTaskOne:
                task1();
                break;
            case kTaskTwo:
                task2();
                break;
            case kTaskThree:
                task3();
                break;
            case kTaskFour:
                task4();
                break;
            default:
                std::cout << "Вы ввели неверный номер задачи. Попробуйте снова, или завершите выполнение" << std::endl;
                break;
        }

        std::cout << "Хотите повторить выполнение программы? [y/n]" << std::endl;
        std::cin >> continueExecution;
    }

    return 0;
}
