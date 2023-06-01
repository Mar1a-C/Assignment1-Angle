#include <iostream>
#include <cmath>
using namespace std;

class Angle {
private:
    int deg, min, sec;

public:
    Angle() {
        deg = 0;
        min = 0;
        sec = 0;
    }

    Angle(int degrees, int minutes, int seconds) {
        deg = degrees;
        min = minutes;
        sec = seconds;
        rectify(*this);
    }

    void info() const {
        cout<<deg<<"° "<<min<<"' "<<sec<<"\" ";
    }

    double rad() const {
        const double PI = 3.14159;
        return ((deg * PI) / 180) + ((min * PI) / (180 * 60)) + ((sec * PI) / (180 * 3600));
    }

    friend Angle operator+(const Angle& a, const Angle& b);
    friend Angle operator-(const Angle& a, const Angle& b);
    friend void rectify(Angle& angle);
};

Angle operator+(const Angle& a, const Angle& b) {
    Angle c;
    c.deg = a.deg + b.deg;
    c.min = a.min + b.min;
    c.sec = a.sec + b.sec;
    rectify(c);
    return c;
}

Angle operator-(const Angle& a, const Angle& b) {
    Angle c;
    c.deg = a.deg - b.deg;
    c.min = a.min - b.min;
    c.sec = a.sec - b.sec;
    rectify(c);
    return c;
}

void rectify(Angle& angle) {
    while (angle.sec >= 60) {
        angle.sec -= 60;
        angle.min += 1;
    }

    while (angle.min >= 60) {
        angle.min -= 60;
        angle.deg += 1;
    }

    while (angle.deg >= 360) {
        angle.deg -= 360;
    }

    while (angle.sec < 0) {
        angle.sec += 60;
        angle.min -= 1;
    }

    while (angle.min < 0) {
        angle.min += 60;
        angle.deg -= 1;
    }

    while (angle.deg < 0) {
        angle.deg += 360;
    }
}

int main() {
    int deg_a, min_a, sec_a;
    int deg_b, min_b, sec_b;

    cout<<"Enter the integer degrees, minutes, and seconds of angle a: ";
    cin >> deg_a >> min_a >> sec_a;

    cout<<"Enter the integer degrees, minutes, and seconds of angle b: ";
    cin >> deg_b >> min_b >> sec_b;

    Angle a(deg_a, min_a, sec_a);
    Angle b(deg_b, min_b, sec_b);

    cout<<"The following angles have been input:"<<endl;
    cout<<"a = ";
    a.info();
    cout<<"= "<<a.rad()<<" radians"<<endl;

    cout<<"b = ";
    b.info();
    cout<<"= "<<b.rad()<<" radians"<<endl;

    cout<<"a + b = ";
    Angle sum = a + b;
    sum.info();
    cout<<"= "<<sum.rad()<<" radians"<<endl;

    cout<<"a - b = ";
    Angle diff = a - b;
    diff.info();
    cout<<"= "<<diff.rad()<<" radians"<<endl;

    return 0;
}
