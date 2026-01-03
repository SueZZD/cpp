#include <iostream>
#include <algorithm> // std::copy için

class LidarScan {
public:
    float* distances; // Metre cinsinden mesafe verileri
    int point_count;

    LidarScan(int count) : point_count(count) {
        distances = new float[point_count];
        std::cout << "Sensorden " << point_count << " nokta alindi." << std::endl;
    }

    // Copy Constructor: Veri işleme birimi (Object Detection) 
    // orijinal veriyi bozmasın diye derin kopyalama yapılır.
    LidarScan(const LidarScan& other) : point_count(other.point_count) {
        distances = new float[point_count];
        std::copy(other.distances, other.distances + point_count, distances);
        std::cout << "Veri isleme birimi icin shallow copy olusturuldu." << std::endl;
    }

    ~LidarScan() {
        delete[] distances;
        std::cout << "Lidar verisi bellekten temizlendi." << std::endl;
    }
};

int main() 
{
    LidarScan original_scan(5);
    
    original_scan.distances[0] = 1.2f;
    original_scan.distances[1] = 2.5f;
    original_scan.distances[2] = 0.8f;
    original_scan.distances[3] = 4.3f;
    original_scan.distances[4] = 1.9f;

    std::cout << "\n--- Veri Isleme Birimi Calisiyor ---" << std::endl;
    
    // 2. Orijinal veriyi bozmamak için kopyasını oluşturuyoruz
    LidarScan processed_scan = original_scan; 

    // 3. Kopya üzerinde değişiklik yapalım (Filtreleme simülasyonu)
    processed_scan.distances[0] = 0.0f; 

    // 4. İspat: Orijinal veri hala duruyor mu?
    std::cout << "\nOrijinal ilk mesafe: " << original_scan.distances[0] << "m" << std::endl;
    std::cout << "Kopya ilk mesafe: " << processed_scan.distances[0] << "m" << std::endl;

    std::cout << "\n--- Program Sonu ---" << std::endl;
    return 0;
}