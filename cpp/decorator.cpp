#include <iostream>
using namespace std;

class Coffee {
public:
    virtual int cost() const {
        return 5;
    }
    virtual ~Coffee() = default;
};

class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;
public:
    CoffeeDecorator(Coffee* coffee) : coffee(coffee) {}
    virtual int cost() const override {
        return coffee->cost();
    }
};

class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}
    int cost() const override {
        return coffee->cost() + 2;
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}
    int cost() const override {
        return coffee->cost() + 1;
    }
};

int main() {
    Coffee* coffee = new Coffee();
    cout << coffee->cost() << endl; // 5

    Coffee* coffeeWithMilk = new MilkDecorator(coffee);
    cout << coffeeWithMilk->cost() << endl; // 7

    Coffee* coffeeWithSugar = new SugarDecorator(coffee);
    cout << coffeeWithSugar->cost() << endl; // 6

    Coffee* coffeeWithMilkAndSugar = new SugarDecorator(coffeeWithMilk);
    cout << coffeeWithMilkAndSugar->cost() << endl; // 8

    // 메모리 해제
    delete coffeeWithMilkAndSugar;
    delete coffeeWithSugar;
    delete coffeeWithMilk;
    delete coffee;
}
