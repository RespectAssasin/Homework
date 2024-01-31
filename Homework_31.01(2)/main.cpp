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

// Функция для задания значений автомобиля
void setCar(Car& car, double length, double clearance, double engineVolume, double enginePower, double wheelDiameter, const string& color, const string& transmissionType) {
    car.length = length;
    car.clearance = clearance;
    car.engineVolume = engineVolume;
    car.enginePower = enginePower;
    car.wheelDiameter = wheelDiameter;
    car.color = color;
    car.transmissionType = transmissionType;
}

// Функция для отображения значений автомобиля
void display(const Car& car) {
    cout << "Длина: " << car.length << " м" << endl;
    cout << "Клиренс: " << car.clearance << " м" << endl;
    cout << "Объем двигателя: " << car.engineVolume << " л" << endl;
    cout << "Мощность двигателя: " << car.enginePower << " л.с." << endl;
    cout << "Диаметр колес: " << car.wheelDiameter << " дюймов" << endl;
    cout << "Цвет: " << car.color << endl;
    cout << "Тип коробки передач: " << car.transmissionType << endl << endl;
}

// Функция для поиска значений по определенным критериям
void findCar(const Car cars[], int numCars, double minEnginePower, double minEngineVolume) {
    cout << "Автомобили, соответствующие критериям поиска:" << endl;
    for (int i = 0; i < numCars; ++i) {
        if (cars[i].enginePower >= minEnginePower && cars[i].engineVolume >= minEngineVolume) {
            cout << "Автомобиль " << i + 1 << ":" << endl;
            display(cars[i]);
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    const int numCars = 3;
    Car cars[numCars];

    setCar(cars[0], 4.5, 0.2, 2.5, 250, 18, "Синий", "Автомат");
    setCar(cars[1], 4.2, 0.15, 1.8, 160, 17, "Красный", "Механика");
    setCar(cars[2], 4.0, 0.2, 2.0, 180, 19, "Черный", "Автомат");

    cout << "Информация о всех автомобилях:" << endl;
    for (int i = 0; i < numCars; ++i) {
        cout << "Автомобиль " << i + 1 << ":" << endl;
        display(cars[i]);
    }

    double minPower = 200;
    double minVolume = 2.0;
    findCar(cars, numCars, minPower, minVolume);

    return 0;
}
