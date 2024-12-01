#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;
    string species;
    string continent;
    double weight;

public:
    Animal() {}
    Animal(string nm, string sp, string cont, double kg)
        : name(nm), species(sp), continent(cont), weight(kg) {}

    virtual void Print() const {
        cout << name << "\t" << species << "\t" << continent << "\t" << weight << " kg" << endl;
    }

    virtual void Eat() const = 0; 
    virtual void Sound() const = 0; 

    virtual ~Animal() {}
};

class Cat : public Animal {
public:
    Cat(string nm, string sp, string cont, double kg)
        : Animal(nm, sp, cont, kg) {}

    void Eat() const override {
        cout << "Ест мышей" << endl;
    }

    void Sound() const override {
        cout << "Мяу" << endl;
    }
};

class Fox : public Animal {
public:
    Fox(string nm, string sp, string cont, double kg)
        : Animal(nm, sp, cont, kg) {}

    void Eat() const override {
        cout << "Ест мясо животных." << endl;
    }

    void Sound() const override {
        cout << "Фыр фыр" << endl;
    }
};

class Demon : public Animal {
public:
    Demon(string nm, string sp, string cont, double kg)
        : Animal(nm, sp, cont, kg) {}

    void Eat() const override {
        cout << "Ест детей" << endl;
    }

    void Sound() const override {
        cout << "Звук из ада." << endl;
    }
};

int main() {
    setlocale(0, "ru");

    Animal* animals[] = {
        new Cat("Черная кошка", "Кошка", "Мир", 4.2),
        new Fox("Рыжая лиса", "Лиса", "Европа", 6.5),
        new Demon("Адский демон", "Демон", "Ад", 52)
    };

    for (Animal* animal : animals) {
        animal->Print();
        animal->Eat();
        animal->Sound();
        cout << endl;
    }

    for (Animal* animal : animals) {
        delete animal;
    }

    return 0;
}
