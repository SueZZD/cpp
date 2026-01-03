#include <iostream>

class MyClass {
public:
    int* data;
    int size;

    // Default constructor
    MyClass(int s) : size(s) {
        data = new int[size];
        std::cout << "Default constructor called" << std::endl;
    }

    // Copy constructor
    MyClass(const MyClass& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        std::cout << "Copy constructor called" << std::endl;
    }

    // Destructor
    ~MyClass() {
        delete[] data;
        std::cout << "Destructor called" << std::endl;
    }
};

int main() {
    std::cout << "--- Catiro nesnesi olusturuluyor ---" << std::endl;
    MyClass Catiro(20);

    std::cout << "\n--- Catiro2 nesnesi, Catiro kullanilarak kopyalaniyor ---" << std::endl;
    MyClass Catiro2 = Catiro; // Burada Copy Constructor calisir

    // Verinin içine bir şey yazalım (ispat için)
    Catiro2.data[0] = 100; 

    // 3. İspat: Catiro2'nin içindeki veriyi kontrol edelim
    std::cout << "Catiro2.data[0] degeri: " << Catiro2.data[0] << std::endl;
    std::cout << "Catiro2'nin boyutu: " << Catiro2.size << std::endl;

    return 0;
}