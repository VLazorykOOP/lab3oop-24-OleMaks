#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    float re, im;
    int state; // 0 - OK, 1 - NULL pointer, 2 - divide by 0
    static int count;

public:
    //Конструктори
    Complex() : re(0), im(0), state(0) {
        count++;
    }

    Complex(float val) : re(val), im(val), state(0) {
        count++;
    }

    Complex(float* ptr) {
        if (ptr == nullptr) {
            re = im = 0;
            state = 1; // Помилка: null pointer
        } else {
            re = ptr[0];
            im = ptr[1];
            state = 0;
        }
        count++;
    }

    //Деструктор
    ~Complex() {
        cout << "Destructor called. State = " << state << endl;
        count--;
    }

    // Конструктор копій
    Complex(const Complex& other) {
        re = other.re;
        im = other.im;
        state = other.state;
        count++;
    }

    //Оператор присвоєння
    Complex& operator=(const Complex& other) {
        if (this != &other) {
            re = other.re;
            im = other.im;
            state = other.state;
        }
        return *this;
    }

    //Присвоєння значення полям
    void setValues(float val = 0.0f) {
        re = val;
        im = val;
    }

    //Отримання значення реальної або уявної частини
    float getValue(bool realPart = true) const {
        return realPart ? re : im;
    }

    //Арифметичні операції
    Complex add(const Complex& other) const {
        return Complex(re + other.re, im + other.im);
    }

    Complex subtract(const Complex& other) const {
        return Complex(re - other.re, im - other.im);
    }

    Complex multiply(const Complex& other) const {
        return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
    }

    Complex divide(const Complex& other) {
        float denom = other.re * other.re + other.im * other.im;
        if (denom == 0) {
            state = 2; // помилка ділення на 0
            return *this;
        }
        float new_re = (re * other.re + im * other.im) / denom;
        float new_im = (im * other.re - re * other.im) / denom;
        return Complex(new_re, new_im);
    }

    //Ділення на ціле short
    void divideByShort(short val) {
        if (val == 0) {
            state = 2; // помилка
            return;
        }
        re /= val;
        im /= val;
    }

    //Обчислення норми
    float norm() const {
        return sqrt(re * re + im * im);
    }

    //Функції порівняння
    bool isGreaterThan(const Complex& other) const {
        return norm() > other.norm();
    }

    bool isLessThan(const Complex& other) const {
        return norm() < other.norm();
    }

    bool isEqual(const Complex& other) const {
        return re == other.re && im == other.im;
    }

    //Друк
    void print() const {
        cout << re << " + " << im << "i, state: " << state << endl;
    }

    //Додатковий конструктор для внутрішніх операцій
    Complex(float r, float i) : re(r), im(i), state(0) {
        count++;
    }

    //Глобальний лічильник
    static int getCount() {
        return count;
    }
};

//статичнa зміннa
int Complex::count = 0;

//Тестова програма
int main() {
    cout << "Testing class Complex:\n";

    Complex c1;
    Complex c2(5.5);
    float arr[] = {3.0, 4.0};
    Complex c3(arr);
    Complex c4(nullptr); // має викликати помилку

    c1.setValues(2.0);
    c1.print();

    cout << "Real part of c2: " << c2.getValue(true) << endl;

    Complex c5 = c2.add(c3);
    c5.print();

    Complex c6 = c2.subtract(c3);
    c6.print();

    Complex c7 = c2.multiply(c3);
    c7.print();

    Complex c8 = c2.divide(c3);
    c8.print();

    c1.divideByShort(0); // має викликати помилку

    cout << "Norm of c3: " << c3.norm() << endl;

    cout << "c3 > c2: " << c3.isGreaterThan(c2) << endl;
    cout << "c3 < c2: " << c3.isLessThan(c2) << endl;
    cout << "c3 = c3: " << c3.isEqual(c3) << endl;

    cout << "Total Complex objects: " << Complex::getCount() << endl;

    return 0;
}
Ы