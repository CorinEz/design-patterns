#include <iostream>
#include <string>
using namespace std;

class InternalClass {
public:
    virtual string fetch() {   // <-- virtual 추가
        return "get user info";
    }
    virtual ~InternalClass() = default; // 소멸자도 virtual이면 좋음
};

class ExternalClass {
public:
    string search() {
        return "get user info";
    }
};

class Adapter : public InternalClass {
private:
    ExternalClass* external;
public:
    Adapter(ExternalClass* external) : external(external) {}

    string fetch() override {   // 이제 제대로 오버라이드 됨
        return external->search();
    }
};

int main() {
    InternalClass internal;
    cout << internal.fetch() << endl; // get user info

    ExternalClass external;
    Adapter adapter(&external);
    cout << adapter.fetch() << endl; // get user info
}
