#pragma once
#include <cstdio>
#include <cstring>

class Car {
protected:
	int speed; // �ӵ� (private)
	char name[40]; // �̸� (private)
public:
	int gear; // ��� (public)
    Car() : speed(0), gear(0) { name[0] = '\0'; } // �⺻ ������
	~Car() { } // �Ҹ���
	Car(int s, char* n, int g): speed(s), gear(g) {
		strcpy_s(name, sizeof(name), n); // ������ �Լ� ��ü (name ��� �ʱ�ȭ)
	}
	void changeGear(int g = 4) { // ��� �ܼ��� �����ϴ� ��� �Լ�
		gear = g;
	}
	void speedUp() { // �ӵ��� 5�� ���� ��� �Լ�
		speed += 5;
	}
	void display() {		// �ڵ����� ������ ȭ�鿡 �����.
		printf("[%s] : ���=%d�� �ӵ�=%dkmph\n", name, gear, speed);
	}
	void whereAmI() { printf("��ü �ּ� = %p\n", this); }
};