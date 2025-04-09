#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Animal {
public:
    virtual string speak() const = 0; // 순수 가상 함수
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    string speak() const override {
        return "Woof!";
    }
};

class Cat : public Animal {
public:
    string speak() const override {
        return "Meow!";
    }
};

class AnimalFactory {
public:
    static unique_ptr<Animal> createAnimal(const string& animalType) {
        if (animalType == "dog") {
            return make_unique<Dog>();
        } else if (animalType == "cat") {
            return make_unique<Cat>();
        } else {
            return nullptr;
        }
    }
};

int main() {
    auto dog = AnimalFactory::createAnimal("dog");
    if (dog) cout << dog->speak() << endl; // Woof!

    auto cat = AnimalFactory::createAnimal("cat");
    if (cat) cout << cat->speak() << endl; // Meow!
}
