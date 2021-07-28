#include <iostream>
using namespace std;

//Task 1.1------------------------------------------------
class Figure
{
public:
    virtual double getArea()=0;
};

class Parallelogramm : public Figure
{
protected:
    double width;//ширина
    double height;//высота
public:
    Parallelogramm(double w, double h) : width(w), height(h)
    {
    }
    double getArea() override
    {
        return width * height;
    }
    void showFigureType()
    {
    cout << "Parallelogramm" << endl;
    }
};

class Circle : public Figure
{
private:
    double radius;
public:
    Circle(double r) : radius(r)
    {
    }
    double getArea() override
    {
        return radius * radius * 3.14;
    }
    void showFigureType()
    {
     cout << "Circle" << endl;
    }
};

class Rectangle : public Parallelogramm
{
public:
    Rectangle(double w, double h) : Parallelogramm(w, h)
    {
    }
    double getArea() override
    {
        return width * height;
    }
    void showFigureType()
    {
    cout << "Rectangle" << endl;
    }
};

class Square : public Parallelogramm
{
public:
    Square(double a) : Parallelogramm(a, a)
    {
    }
    double getArea() override
    {
        return width * width;
    }
    void showFigureType()
    {
    cout << "Square" << endl;
    }
};

class Rhombus : public Parallelogramm
{
public:
    Rhombus(double w, double h) : Parallelogramm(w, h)
    {
    }
    double getArea() override
    {
        return width * height;
    }
    void showFigureType()
    {
    cout << "Rhombus" << endl;
    }
};

//Task 2.1-------------------------------------------------

class Car
{
protected:
    string company = "company";
    string model = "model";
public:
    Car()
    {
    cout << "Car:" << " " << company << " " << model << ", ";
    }
};
class PassengerCar : virtual public Car
{
public:
    PassengerCar()
    {
    cout << "PassengerCar:" << " " << company << " " << model << ", ";
    }
};
class Bus : virtual public Car
{
public:
    Bus()
    {
    cout << "Bus:" << " " << company << " " << model << ", ";
    }
};
class Minivan : public PassengerCar, Bus
{
public:
    Minivan()
    {
    cout << "Minivan:" << " " << company << " " << model << ", ";
    }
};

//Task 3.1-------------------------------------------------

class Fraction {
private:
    int chislitel;
    int znamenatel;
public:
    Fraction(int a, int b) {
    chislitel = a;
    if(b != 0) {
        znamenatel = b;
        } else {
        cout << "znamenatel can not be a zero!" << endl;
        }
    }

    int getChislitel() {
        return chislitel;
    }

    int getZnamenatel() {
        return znamenatel;
    }
    friend Fraction operator+(Fraction& f1, Fraction& f2);
    friend Fraction operator-(Fraction& f1, Fraction& f2);
    friend Fraction operator*(Fraction& f1, Fraction& f2);
    friend Fraction operator/(Fraction& f1, Fraction& f2);
};

Fraction operator+(Fraction& f1, Fraction& f2) {
    return Fraction(f1.chislitel*f2.znamenatel+f2.chislitel*f1.znamenatel, f1.znamenatel*f2.znamenatel);
}

Fraction operator-(Fraction& f1, Fraction& f2) {
    return Fraction(f1.chislitel*f2.znamenatel-f2.chislitel*f1.znamenatel, f1.znamenatel*f2.znamenatel);
}
Fraction operator*(Fraction& f1, Fraction& f2) {
    return Fraction(f1.chislitel*f2.chislitel, f1.znamenatel*f2.znamenatel);
}
Fraction operator/(Fraction& f1, Fraction& f2) {
    return Fraction(f1.chislitel*f2.znamenatel, f1.znamenatel*f2.chislitel);
}

 int main() {

 //Task 1.2------------------------------------------------
    cout << "Task 1" << endl;
    Parallelogramm par(30, 50);
    Circle circle(30);
    Rectangle rec(10, 10);
    Square square(5);
    Rhombus rhombus(2, 4);

    cout << "Parallelogramm area: " << par.getArea() << endl;
    cout << "Circle area: " << circle.getArea() << endl;
    cout << "Rectangle area: " << rec.getArea() << endl;
    cout << "Square: " << square.getArea() << endl;
    cout << "Rhombus: " << rhombus.getArea() << endl;
    cout << endl;

//Task 2.2-------------------------------------------------
    cout << "Task 2" << endl;
    Bus bus;
    cout << endl;
    PassengerCar passeng;
    cout << endl;
    Minivan minivan;
    cout << endl;
    cout << endl;

//Task 3.2-------------------------------------------------
    cout << "Task 3" << endl;
    Fraction F1(1, 2);
    Fraction F2(1, 4);
    Fraction F_result = F1 + F2;
    cout << F1.getChislitel() <<"/"<< F1.getZnamenatel() << " + " << F2.getChislitel() << "/" << F2.getZnamenatel()
     << " = "<< F_result.getChislitel() << "/" << F_result.getZnamenatel() << endl;

    F_result = F1 - F2;
     cout << F1.getChislitel() <<"/"<< F1.getZnamenatel() << " - " << F2.getChislitel() << "/" << F2.getZnamenatel()
     << " = "<< F_result.getChislitel() << "/" << F_result.getZnamenatel() << endl;

    F_result = F1 * F2;
     cout << F1.getChislitel() <<"/"<< F1.getZnamenatel() << " * " << F2.getChislitel() << "/" << F2.getZnamenatel()
     << " = "<< F_result.getChislitel() << "/" << F_result.getZnamenatel() << endl;

    F_result = F1 / F2;
     cout << F1.getChislitel() <<"/"<< F1.getZnamenatel() << " / " << F2.getChislitel() << "/" << F2.getZnamenatel()
     << " = "<< F_result.getChislitel() << "/" << F_result.getZnamenatel() << endl;

    return 0;
}


