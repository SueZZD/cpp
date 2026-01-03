#include <iostream>
#include <string>

class AutonomousTask {
public:
    std::string task_name;
    int priority;

    AutonomousTask(std::string name, int p) : task_name(name), priority(p) {}

    AutonomousTask(const AutonomousTask& other) = delete; // Kopyalamayı yasakladık!

    // Move Constructor: Görevi bir kuyruktan diğerine "transfer" eder
    AutonomousTask(AutonomousTask&& other) noexcept : task_name(std::move(other.task_name)), priority(other.priority) {
        std::cout << task_name << " gorevi yeni birime devredildi." << std::endl;
    }
};

int main() 
{
    AutonomousTask t1("Engel Algilama", 1);

    std::cout << "Gorev t1 biriminde: " << t1.task_name << std::endl;

    AutonomousTask t2 = std::move(t1); 

    std::cout << "Transferden sonra t2'deki gorev: " << t2.task_name << std::endl;
    
    std::cout << "Transferden sonra t1'in durumu : [" << t1.task_name << "]" << std::endl;

    return 0;
}