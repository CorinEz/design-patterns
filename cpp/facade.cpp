#include <iostream>
#include <string>
using namespace std;

class CPU {
public:
    string process() {
        return "CPU 처리 중";
    }
};

class Memory {
public:
    string load() {
        return "메모리 로딩 중";
    }
};

class SSD {
public:
    string read() {
        return "SSD 드라이브 읽는 중";
    }
};

class Computer { // 파사드 클래스
private:
    CPU cpu;
    Memory memory;
    SSD ssd;
public:
    void boot() {
        cout << ssd.read() << endl;
        cout << memory.load() << endl;
        cout << cpu.process() << endl;
    }
};

int main() {
    Computer computer;
    computer.boot();
}
