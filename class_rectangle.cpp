#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double length;

public:
    // Setter for width
    void setWidth(double W) {
        if (W > 0) {
            width = W;
        } else {
            cout << "Width must be positive.\n";
        }
    }
    // Setter for length
    void setLength(double L) {
        if (L > 0) {
            length = L;
        } else {
            cout << "Length must be positive.\n";
        }
    }
    // Getter for width
    double getWidth() const {
        return width;
    }
    // Getter for length
    double getLength() const {
        return length;
    }
    // Function to calculate area
    double calculateArea() const {
        return width * length;
    }
    // Function to calculate perimeter
    double calculatePerimeter() const {
        return 2 * (width + length);
    }
};
int main() {
    // Creating a Rectangle object using setters
    Rectangle rect1;
    rect1.setWidth(5.0);
    rect1.setLength(10.0);
    cout << "--- Rectangle 1 ---\n";
    cout << "Width: " << rect1.getWidth() << "\n";
    cout << "Length: " << rect1.getLength() << "\n";
    cout << "Area: " << rect1.calculateArea() << "\n";
    cout << "Perimeter: " << rect1.calculatePerimeter() << "\n\n";

    // Creating another Rectangle object with different dimensions
    Rectangle rect2;
    rect2.setWidth(3.0);
    rect2.setLength(7.0);
    cout << "--- Rectangle 2 ---\n";
    cout << "Width: " << rect2.getWidth() << "\n";
    cout << "Length: " << rect2.getLength() << "\n";
    cout << "Area: " << rect2.calculateArea() << "\n";
    cout << "Perimeter: " << rect2.calculatePerimeter() << "\n";

    return 0;
}