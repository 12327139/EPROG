#include<iostream>
#include<math.h>

class Ellipse {
private: 
    double center[2];
    double a;
    double b;
public:
    Ellipse(double center[2], double a, double b) {
        setCenter(center);
        setA(a);
        setB(b);
    }
    void setCenter(double center[2]);
    double getA();
    void setA(double a);
    double getB();
    void setB(double b);
    bool isInside(double x, double y);
    bool isCircle();
    void printFocalPoints();
    double getEccentricity();
};

void Ellipse::setCenter(double center[2]) {
    this->center[0] = center[0];
    this->center[1] = center[1];
}

double Ellipse::getA() {
    return this->a;
}

void Ellipse::setA(double a) {
    this->a = a;
}

double Ellipse::getB() {
    return this->b;
}

void Ellipse::setB(double b) {
    this->b = b;
}

bool Ellipse::isInside(double x, double y) {
    double zaehler1 = (x - this->center[0]) * (x - this->center[0]);
    double nenner1 = this->getA() * this->getA();
    double bruch1 = zaehler1 / nenner1;

    double zaehler2 = (y - this->center[1]) * (y - this->center[1]);
    double nenner2 = this->getB() * this->getB();
    double bruch2 = zaehler2 / nenner2;

    return bruch1 + bruch2 == 1;
}

bool Ellipse::isCircle() {
    return abs(a-b) < 0.0001;
}

void Ellipse::printFocalPoints() {
    
}

double Ellipse::getEccentricity() {
    double bruch = std::min(a, b) / std::max(a, b);
    return sqrt(1 - (bruch * bruch));
}

int main() {
    double a[] = {1, 2};
    Ellipse e(a, 2, 3);
}
