#pragma once
#include <cstdio>
#include <cstring>

class Car {
protected:
    int speed;
    char name[40];

public:
    int gear;

    Car();
    Car(int s, const char* n, int g);
    virtual ~Car();

    void changeGear(int g = 4);
    virtual void speedUp();
    void display();
    void whereAmI();
};

class SportsCar : public Car {
public:
    bool bTurbo;

    void setTurbo(bool bTur);
    void speedUp() override;
};
