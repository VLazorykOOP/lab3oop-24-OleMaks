#include <iostream>
#include <cmath>
#include <string>

class Circle {
private:
    double radius;
    std::string color;

public:
    // Конструктор за замовчуванням
    Circle() {
        radius = 1.0;
        color = "red";
    }

    // Конструктор з параметрами
    Circle(double r, std::string c) {
        setRadius(r);
        setColor(c);
    }

    // Сеттери для радіуса
    void setRadius(double r) {
        if (r > 0) {
            radius = r;
        } else {
            std::cerr << "Error: radius must be positive. Radius by default applied (1.0)." << std::endl;
            radius = 1.0;
        }
    }

    // Сеттери  для кольору
    void setColor(std::string c) {
        if (!c.empty()) {
            color = c;
        } else {
            std::cerr << "Error color cant be empty. Entered default color red." << std::endl;
            color = "red";
        }
    }

    // Геттер для радіуса
    double getRadius() const {
        return radius;
    }

    // Геттер для кольору
    std::string getColor() const {
        return color;
    }

    // Обчислення площі круга
    double area() const {
        return M_PI * radius * radius;
    }

    // Обчислення довжини кола
    double circumference() const {
        return 2 * M_PI * radius;
    }

    // Функція друку
    void print() const {
        std::cout << "Circle with radius: " << radius
                  << ", color: " << color
                  << ", area: " << area()
                  << ", length of circle: " << circumference()
                  << std::endl;
    }
};

// Тестова функція main
int main() {
    // Тест конструктора за замовчуванням
    Circle c1;
    c1.print();

    // Параметри
    Circle c2(5.5, "blue");
    c2.print();

    // Тест некоректного радіуса
    Circle c3(-3, "green");
    c3.print();

    // Тест встановлення нового радіуса та кольору
    c1.setRadius(10);
    c1.setColor("yellow");
    c1.print();

    // Геттери
    std::cout << "Radius c2: " << c2.getRadius() << std::endl;
    std::cout << "Color c2: " << c2.getColor() << std::endl;

    return 0;
}
