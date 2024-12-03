#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
using namespace std;

class Room {
public:
    int roomNumber;
    int capacity;
    int occupied;

    Room(int num, int cap) : roomNumber(num), capacity(cap), occupied(0) {}

    bool canOccupy() const {
        return occupied < capacity;
    }

    void occupy() {
        if (canOccupy()) {
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

    friend istream& operator>>(istream& is, Room& room) {
        is >> room.roomNumber >> room.capacity;
        room.occupied = 0;
        return is;
    }
};

class Faculty {
public:
    string instituteName;
    string facultyName;
    int studentCount;

    Faculty(string institute, string faculty, int count)
        : instituteName(institute), facultyName(faculty), studentCount(count) {}

    friend ostream& operator<<(ostream& os, const Faculty& faculty) {
        os << "Інститут: " << faculty.instituteName << ", Факультет: " << faculty.facultyName << ", Студентів: " << faculty.studentCount;
        return os;
    }

    friend istream& operator>>(istream& is, Faculty& faculty) {
        is >> faculty.instituteName >> faculty.facultyName >> faculty.studentCount;
        return is;
    }
};

class Dormitory {
private:
    string street;
    int buildingNumber;
    Faculty faculty;
    vector<Room> rooms;

public:
    Dormitory(string st, int num, Faculty fac) : street(st), buildingNumber(num), faculty(fac) {}

    Dormitory(const Dormitory& other)
        : street(other.street), buildingNumber(other.buildingNumber), faculty(other.faculty), rooms(other.rooms) {}

    Dormitory& operator=(const Dormitory& other) {
        if (this != &other) {
            street = other.street;
            buildingNumber = other.buildingNumber;
            faculty = other.faculty;
            rooms = other.rooms;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Dormitory& dorm) {
        os << "Гуртожиток: " << dorm.street << " " << dorm.buildingNumber << ", " << dorm.faculty << endl;
        os << "Кімнати:\n";
        for (const auto& room : dorm.rooms) {
            os << room << endl;
        }
        return os;
    }

    friend istream& operator>>(istream& is, Dormitory& dorm) {
        is >> dorm.street >> dorm.buildingNumber >> dorm.faculty;
        return is;
    }

    string getAddress() const {
        return street + ", буд. " + to_string(buildingNumber);
    }

    double averageOccupancy() const {
        int totalCapacity = 0;
        int totalOccupied = 0;
        for (const auto& room : rooms) {
            totalCapacity += room.capacity;
            totalOccupied += room.occupied;
        }
        return totalCapacity > 0 ? static_cast<double>(totalOccupied) / totalCapacity : 0.0;
    }

    void addRoom(const Room& room) {
        rooms.push_back(room);
    }

    void occupyRoom(int roomNumber) {
        auto it = find_if(rooms.begin(), rooms.end(), [roomNumber](const Room& room) {
            return room.roomNumber == roomNumber;
        });
        if (it != rooms.end()) {
            it->occupy();
        } else {
            throw runtime_error("Кімната не знайдена");
        }
    }

    void vacateRoom(int roomNumber) {
        auto it = find_if(rooms.begin(), rooms.end(), [roomNumber](const Room& room) {
            return room.roomNumber == roomNumber;
        });
        if (it != rooms.end()) {
            it->vacate();
        } else {
            throw runtime_error("Кімната не знайдена");
        }
    }

    int countAvailableRooms() const {
        return count_if(rooms.begin(), rooms.end(), [](const Room& room) {
            return room.canOccupy();
        });
    }

    double occupancyPercentage() const {
        int totalStudents = faculty.studentCount;
        int studentsInDorm = 0;
        for (const auto& room : rooms) {
            studentsInDorm += room.occupied;
        }
        return totalStudents > 0 ? static_cast<double>(studentsInDorm) / totalStudents * 100 : 0.0;
    }
};

int main() {
    Faculty faculty("Технічний університет", "Комп'ютерних наук", 2000);
    Dormitory dorm("Вулиця Центральна", 15, faculty);

    dorm.addRoom(Room(101, 3));
    dorm.addRoom(Room(102, 2));
    dorm.addRoom(Room(103, 4));

    dorm.occupyRoom(101);
    dorm.occupyRoom(102);

    cout << "Адреса гуртожитку: " << dorm.getAddress() << endl;
    cout << "Середня заселеність: " << dorm.averageOccupancy() * 100 << "%" << endl;

    cout << dorm;

    cout << "Відсоток студентів інституту, які живуть в гуртожитку: " << dorm.occupancyPercentage() << "%" << endl;

    return 0;
}
