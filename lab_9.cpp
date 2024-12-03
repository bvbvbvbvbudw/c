#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class DynamicArray {
public:
    virtual void input() = 0;
    virtual void output() = 0;
    virtual ~DynamicArray() {}

protected:
    vector<T> array;
};

class Room {
public:
    int roomNumber;
    int capacity;
    int occupied;

    Room(int num = 0, int cap = 0) : roomNumber(num), capacity(cap), occupied(0) {}

    void occupy() {
        if (occupied < capacity) {
            occupied++;
        } else {
            throw runtime_error("Кімната вже повністю заселена");
        }
    }

    void vacate() {
        if (occupied > 0) {
            occupied--;
        } else {
            throw runtime_error("Кімната вже пуста");
        }
    }

    friend ostream& operator<<(ostream& os, const Room& room) {
        os << "Кімната: " << room.roomNumber << ", Місткість: " << room.capacity << ", Зайнято: " << room.occupied;
        return os;
    }
};

class Faculty {
public:
    string instituteName;
    string facultyName;
    int studentCount;

    Faculty(string institute = "", string faculty = "", int count = 0)
        : instituteName(institute), facultyName(faculty), studentCount(count) {}

    friend ostream& operator<<(ostream& os, const Faculty& faculty) {
        os << "Інститут: " << faculty.instituteName << ", Факультет: " << faculty.facultyName << ", Студентів: " << faculty.studentCount;
        return os;
    }
};

class Dormitory : public DynamicArray<Room> {
private:
    string street;
    int buildingNumber;
    Faculty faculty;

public:
    Dormitory(string st = "", int num = 0, Faculty fac = Faculty())
        : street(st), buildingNumber(num), faculty(fac) {}

    string getAddress() const {
        return street + ", буд. " + to_string(buildingNumber);
    }

    void addRoom(const Room& room) {
        array.push_back(room);
    }

    void occupyRoom(int roomNumber) {
        for (auto& room : array) {
            if (room.roomNumber == roomNumber) {
                room.occupy();
                return;
            }
        }
        throw runtime_error("Кімната не знайдена");
    }

    void vacateRoom(int roomNumber) {
        for (auto& room : array) {
            if (room.roomNumber == roomNumber) {
                room.vacate();
                return;
            }
        }
        throw runtime_error("Кімната не знайдена");
    }

    double averageOccupancy() const {
        int totalCapacity = 0;
        int totalOccupied = 0;
        for (const auto& room : array) {
            totalCapacity += room.capacity;
            totalOccupied += room.occupied;
        }
        return totalCapacity > 0 ? static_cast<double>(totalOccupied) / totalCapacity : 0.0;
    }

    void output() override {
        cout << "Гуртожиток: " << street << ", буд. " << buildingNumber << ", " << faculty << endl;
        cout << "Кімнати:\n";
        for (const auto& room : array) {
            cout << room << endl;
        }
    }

    void input() override {
        cout << "Введіть адресу гуртожитку: ";
        cin >> street >> buildingNumber;
        cout << "Введіть факультет: ";
        cin >> faculty.instituteName >> faculty.facultyName >> faculty.studentCount;
    }

    bool operator<(const Dormitory& other) const {
        return this->averageOccupancy() < other.averageOccupancy();
    }

    bool operator==(const Dormitory& other) const {
        return this->array.size() == other.array.size();
    }
};

int main() {
    Faculty faculty("Технічний університет", "Комп'ютерних наук", 500);
    Dormitory dorm1("Вулиця Центральна", 10, faculty);
    dorm1.addRoom(Room(101, 3));
    dorm1.addRoom(Room(102, 2));

    dorm1.occupyRoom(101);

    dorm1.output();

    cout << "Адреса гуртожитку: " << dorm1.getAddress() << endl;

    Dormitory dorm2("Вулиця Приморська", 15, Faculty("Економічний університет", "Фінансів", 2000));
    dorm2.addRoom(Room(201, 4));
    dorm2.addRoom(Room(202, 2));

    dorm2.occupyRoom(201);

    cout << "Середня заселеність гуртожитку 1: " << dorm1.averageOccupancy() * 100 << "%" << endl;
    cout << "Середня заселеність гуртожитку 2: " << dorm2.averageOccupancy() * 100 << "%" << endl;

    if (dorm1 < dorm2) {
        cout << "Гуртожиток 1 менш заселений, ніж гуртожиток 2." << endl;
    }

    return 0;
}
