#include "Libraries.h"

struct Car {
    double length;
    double clearance;
    double engineVolume;
    double enginePower;
    double wheelDiameter;
    string color;
    string transmissionType;
};

// ������� ��� ������� �������� ����������
void setCar(Car& car, double length, double clearance, double engineVolume, double enginePower, double wheelDiameter, const string& color, const string& transmissionType) {
    car.length = length;
    car.clearance = clearance;
    car.engineVolume = engineVolume;
    car.enginePower = enginePower;
    car.wheelDiameter = wheelDiameter;
    car.color = color;
    car.transmissionType = transmissionType;
}

// ������� ��� ����������� �������� ����������
void display(const Car& car) {
    cout << "�����: " << car.length << " �" << endl;
    cout << "�������: " << car.clearance << " �" << endl;
    cout << "����� ���������: " << car.engineVolume << " �" << endl;
    cout << "�������� ���������: " << car.enginePower << " �.�." << endl;
    cout << "������� �����: " << car.wheelDiameter << " ������" << endl;
    cout << "����: " << car.color << endl;
    cout << "��� ������� �������: " << car.transmissionType << endl << endl;
}

// ������� ��� ������ �������� �� ������������ ���������
void findCar(const Car cars[], int numCars, double minEnginePower, double minEngineVolume) {
    cout << "����������, ��������������� ��������� ������:" << endl;
    for (int i = 0; i < numCars; ++i) {
        if (cars[i].enginePower >= minEnginePower && cars[i].engineVolume >= minEngineVolume) {
            cout << "���������� " << i + 1 << ":" << endl;
            display(cars[i]);
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    const int numCars = 3;
    Car cars[numCars];

    setCar(cars[0], 4.5, 0.2, 2.5, 250, 18, "�����", "�������");
    setCar(cars[1], 4.2, 0.15, 1.8, 160, 17, "�������", "��������");
    setCar(cars[2], 4.0, 0.2, 2.0, 180, 19, "������", "�������");

    cout << "���������� � ���� �����������:" << endl;
    for (int i = 0; i < numCars; ++i) {
        cout << "���������� " << i + 1 << ":" << endl;
        display(cars[i]);
    }

    double minPower = 200;
    double minVolume = 2.0;
    findCar(cars, numCars, minPower, minVolume);

    return 0;
}
