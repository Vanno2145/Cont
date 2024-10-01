#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Car {
public:
    string name;
    int year;
    double engineVolume;
    double price;

    Car(const string& name, int year, double engineVolume, double price)
        : name(name), year(year), engineVolume(engineVolume), price(price) {}

    void display() const {
        cout << "��������: " << name
            << ", ��� �������: " << year
            << ", ����� ���������: " << engineVolume
            << "L, ����: $" << price << endl;
    }
};

class CarShowroom {
private:
    vector<Car> cars;

public:
    void addCar(const Car& car) {
        cars.push_back(car);
    }

    void removeCar(const string& name) {
        for (size_t i = 0; i < cars.size(); i++) {
            if (cars[i].name == name) {
                cars.erase(cars.begin() + i);
                cout << "���������� \"" << name << "\" ��� �����." << endl;
                return;
            }
        }
        cout << "���������� \"" << name << "\" �� ������." << endl;
    }

    void displayCars() const {
        if (cars.empty()) {
            cout << "��� ��������� �����������." << endl;
            return;
        }
        cout << "������ �����������:" << endl;
        for (const auto& car : cars) {
            car.display();
        }
    }

    void sortByPrice() {
        for (size_t i = 0; i < cars.size() - 1; i++) {
            for (size_t j = 0; j < cars.size() - 1 - i; j++) {
                if (cars[j].price > cars[j + 1].price) {
                    swap(cars[j], cars[j + 1]);
                }
            }
        }
        cout << "���������� ������������� �� ����." << endl;
    }

    void sortByYear() {
        for (size_t i = 0; i < cars.size() - 1; i++) {
            for (size_t j = 0; j < cars.size() - 1 - i; j++) {
                if (cars[j].year > cars[j + 1].year) {
                    swap(cars[j], cars[j + 1]);
                }
            }
        }
        cout << "���������� ������������� �� ���� �������." << endl;
    }

    void searchByName(const string& name) const {
        bool found = false;
        for (const auto& car : cars) {
            if (car.name == name) {
                car.display();
                found = true;
                break; 
            }
        }
        if (!found) {
            cout << "���������� \"" << name << "\" �� ������." << endl;
        }
    }
};

int main() {
    CarShowroom showroom;
    int choice;
    string name;
    int year;
    double engineVolume, price;

    do {
        cout << "\n1. �������� ����������\n"
            << "2. ������� ����������\n"
            << "3. ���������� ����������\n"
            << "4. ����������� �� ����\n"
            << "5. ����������� �� ���� �������\n"
            << "6. ����� ���������� �� ��������\n"
            << "0. �����\n"
            << "�������� ��������: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������� �������� ����������: ";
            cin >> name;
            cout << "������� ��� �������: ";
            cin >> year;
            cout << "������� ����� ��������� (�): ";
            cin >> engineVolume;
            cout << "������� ����: ";
            cin >> price;
            showroom.addCar(Car(name, year, engineVolume, price));
            break;

        case 2:
            cout << "������� �������� ���������� ��� ��������: ";
            cin >> name;
            showroom.removeCar(name);
            break;

        case 3:
            showroom.displayCars();
            break;

        case 4:
            showroom.sortByPrice();
            break;

        case 5:
            showroom.sortByYear();
            break;

        case 6:
            cout << "������� �������� ���������� ��� ������: ";
            cin >> name;
            showroom.searchByName(name);
            break;

        case 0:
            cout << "����� �� ���������." << endl;
            break;

        default:
            cout << "�������� �����. ����������, ���������� �����." << endl;
        }
    } while (choice != 0);
}
