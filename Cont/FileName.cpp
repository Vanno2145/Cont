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
        cout << "Название: " << name
            << ", Год выпуска: " << year
            << ", Объем двигателя: " << engineVolume
            << "L, Цена: $" << price << endl;
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
                cout << "Автомобиль \"" << name << "\" был удалён." << endl;
                return;
            }
        }
        cout << "Автомобиль \"" << name << "\" не найден." << endl;
    }

    void displayCars() const {
        if (cars.empty()) {
            cout << "Нет доступных автомобилей." << endl;
            return;
        }
        cout << "Список автомобилей:" << endl;
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
        cout << "Автомобили отсортированы по цене." << endl;
    }

    void sortByYear() {
        for (size_t i = 0; i < cars.size() - 1; i++) {
            for (size_t j = 0; j < cars.size() - 1 - i; j++) {
                if (cars[j].year > cars[j + 1].year) {
                    swap(cars[j], cars[j + 1]);
                }
            }
        }
        cout << "Автомобили отсортированы по году выпуска." << endl;
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
            cout << "Автомобиль \"" << name << "\" не найден." << endl;
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
        cout << "\n1. Добавить автомобиль\n"
            << "2. Удалить автомобиль\n"
            << "3. Отобразить автомобили\n"
            << "4. Сортировать по цене\n"
            << "5. Сортировать по году выпуска\n"
            << "6. Найти автомобиль по названию\n"
            << "0. Выйти\n"
            << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите название автомобиля: ";
            cin >> name;
            cout << "Введите год выпуска: ";
            cin >> year;
            cout << "Введите объем двигателя (л): ";
            cin >> engineVolume;
            cout << "Введите цену: ";
            cin >> price;
            showroom.addCar(Car(name, year, engineVolume, price));
            break;

        case 2:
            cout << "Введите название автомобиля для удаления: ";
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
            cout << "Введите название автомобиля для поиска: ";
            cin >> name;
            showroom.searchByName(name);
            break;

        case 0:
            cout << "Выход из программы." << endl;
            break;

        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
        }
    } while (choice != 0);
}
