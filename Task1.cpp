#include <iostream>
#include <conio.h>
#include <string>
#define pi 3.14159265358

class Figure
{
public:
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual std::string  show() { return show(); }
};

class Square: public Figure
{
public:
    Square(double a = 1): _a(a) { }

	virtual double area() const { return _a * _a; }
	virtual double perimeter() const { return _a * 4; }
	virtual std::string  show() { return "Square\n"; }

private:
    double _a;
};

class Circle: public Figure
{
public:
    Circle(double r = 1): _r(r) { }

	virtual double area() const { return pi * _r * _r; }
	virtual double perimeter() const { return 2 * pi * _r; }
	virtual std::string  show() { return "Circle\n"; }

private:
    double _r;
};

class Rectangle: public Figure
{
public:
	Rectangle(double b = 1, double c = 1): _b(b), _c(c) { }

	virtual double area() const { return _b * _c; }
	virtual double perimeter() const { return 2 * (_b + _c); }
	virtual std::string  show() { return "Rectangle\n"; }

private:
	double _b, _c;
};

int main()
{
	Figure *figures[3];

	figures[0] = new Square (3);
	figures[1] = new Circle (2);
	figures[2] = new Rectangle (2,4);

	for (int i = 0; i < 3; ++i)
		std::cout << figures[i]->show() << "Area: " << figures[i]->area() << " Perimeter: " << figures[i]->perimeter() << std::endl;

	for (int i = 0; i < 3; ++i)
		delete figures[i];

	getch();
	return 0;
}
