#include <cstdio>
#include <cstring>

// ---------------------- Car 클래스 ----------------------
class Car {
protected:
    int speed;
    char name[40];

public:
    int gear;

    Car() {
        speed = 0;
        strcpy_s(name, sizeof(name), "NoName");
        gear = 1;
    }

    Car(int s, const char* n, int g) : speed(s), gear(g) {
        strcpy_s(name, sizeof(name), n);
    }

    virtual ~Car() {
        // 소멸자 (필요하면 정리할 것)
    }

    void changeGear(int g = 4) {
        gear = g;
    }

    virtual void speedUp() {
        speed += 5;
    }

    void display() {
        printf("[%s] : 기어=%d단 속도=%dkmph\n", name, gear, speed);
    }

    void whereAmI() {
        printf("객체 주소 = %p\n", this);
    }
};

// ------------------- SportsCar 클래스 -------------------
class SportsCar : public Car {
public:
    bool bTurbo;

    void setTurbo(bool bTur) {
        bTurbo = bTur;
    }

    void speedUp() override {
        if (bTurbo)
            speed += 20;
        else
            Car::speedUp();
    }
};

// ------------------------- main -------------------------
int main() {
    SportsCar sc;
    sc.setTurbo(true);
    sc.changeGear(3);
    sc.speedUp();
    sc.display();
    sc.whereAmI();

    return 0;
}
