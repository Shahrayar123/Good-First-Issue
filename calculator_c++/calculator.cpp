#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

class Calculator {
public:
    void run() {
        int choice;
        do {
            displayMenu();
            choice = getChoice();
            processChoice(choice);
        } while (choice != 7);
    }

private:
    void displayMenu() const {
        std::cout << "\nC++ Calculator Menu:\n"
                  << "1. Addition\n"
                  << "2. Subtraction\n"
                  << "3. Multiplication\n"
                  << "4. Division\n"
                  << "5. Square\n"
                  << "6. Square Root\n"
                  << "7. Exit\n"
                  << "Enter your choice: ";
    }

    int getChoice() const {
        int choice;
        while (!(std::cin >> choice) || choice < 1 || choice > 7) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 7: ";
        }
        return choice;
    }

    void processChoice(int choice) {
        switch (choice) {
            case 1: add(); break;
            case 2: subtract(); break;
            case 3: multiply(); break;
            case 4: divide(); break;
            case 5: square(); break;
            case 6: squareRoot(); break;
            case 7: std::cout << "Exiting calculator. Goodbye!\n"; break;
        }
    }

    double getNumber(const std::string& prompt) const {
        double num;
        std::cout << prompt;
        while (!(std::cin >> num)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number: ";
        }
        return num;
    }

    void add() {
        int count = getNumber("How many numbers do you want to add? ");
        std::vector<double> numbers(count);
        for (int i = 0; i < count; ++i) {
            numbers[i] = getNumber("Enter number " + std::to_string(i + 1) + ": ");
        }
        double sum = 0;
        for (double num : numbers) {
            sum += num;
        }
        std::cout << "Sum: " << sum << '\n';
    }

    void subtract() {
        double num1 = getNumber("Enter the first number: ");
        double num2 = getNumber("Enter the second number: ");
        std::cout << "Difference: " << (num1 - num2) << '\n';
    }

    void multiply() {
        double num1 = getNumber("Enter the first number: ");
        double num2 = getNumber("Enter the second number: ");
        std::cout << "Product: " << (num1 * num2) << '\n';
    }

    void divide() {
        double num1 = getNumber("Enter the dividend: ");
        double num2 = getNumber("Enter the divisor: ");
        while (num2 == 0) {
            std::cout << "Error: Division by zero.\n";
            num2 = getNumber("Enter a non-zero divisor: ");
        }
        std::cout << "Quotient: " << (num1 / num2) << '\n';
    }

    void square() {
        double num = getNumber("Enter a number to square: ");
        std::cout << "Square: " << (num * num) << '\n';
    }

    void squareRoot() {
        double num = getNumber("Enter a number to find its square root: ");
        while (num < 0) {
            std::cout << "Error: Cannot calculate square root of a negative number.\n";
            num = getNumber("Enter a non-negative number: ");
        }
        std::cout << "Square root: " << std::sqrt(num) << '\n';
    }
};

int main() {
    Calculator calc;
    calc.run();
    return 0;
}