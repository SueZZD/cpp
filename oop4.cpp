#include <iostream>
#include <algorithm> // std::copy için

// 1. Kendi Namespace'imizi oluşturalım
namespace AutonomousSystem {

    // 2. Base Class (Kalıtım için temel sınıf)
    class Sensor {
    public:
        virtual void processData() = 0; // Pure virtual function (Interface)
        virtual ~Sensor() {} // Virtual destructor (Bellek sızıntısını önlemek için şart)
    };

    // 3. Derived Class (Kalıtım alıyor)
    class LidarSensor : public Sensor {
    private:
        float* raw_data; // Pointer ile bellek yönetimi
        int resolution;

    public:
        // Constructor
        LidarSensor(int res) : resolution(res) {
            raw_data = new float[resolution];
            for(int i = 0; i < resolution; ++i) raw_data[i] = 0.0f; // Initialize
            std::cout << "[Lidar] " << resolution << " nokta icin bellek ayrildi." << std::endl;
        }

        // Copy Constructor (Deep Copy)
        LidarSensor(const LidarSensor& other) : resolution(other.resolution) {
            raw_data = new float[resolution]; // Pointer için yeni bellek alanı
            std::copy(other.raw_data, other.raw_data + resolution, raw_data); // Veriyi kopyala
            std::cout << "[Lidar] Veri baska bir birime kopyalandi (Deep Copy)." << std::endl;
        }

        // Polymorphism için override
        void processData() override {
            std::cout << "[Lidar] " << resolution << " nokta isleniyor..." << std::endl;
        }

        // Destructor
        ~LidarSensor() {
            delete[] raw_data; // Pointer ile ayrılan yeri boşalt
            std::cout << "[Lidar] Bellek temizlendi." << std::endl;
        }
    };
}

// 4. Using namespace kullanımı
using namespace std;
using namespace AutonomousSystem;

int main() {
    LidarSensor front_lidar(1024); // Nesne oluşturuldu
    
    // '&' ekleyerek REFERANS yaptık:
    LidarSensor& object_detection_unit = front_lidar; 

    front_lidar.processData();
    object_detection_unit.processData();

    return 0;
}