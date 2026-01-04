#include <iostream>
#include <cstring> // std::memcpy için

class CameraFrame {
private:
    uint8_t* rawData;   // Görüntü piksellerini tutan pointer
    size_t frameSize;   // Bellek boyutu
    int frameId;

public:
    // Constructor: Bellek Tahsisi (Allocation)
    CameraFrame(size_t size, int id) : frameSize(size), frameId(id) {
        // Heap üzerinden güvenli bellek ayırma
        rawData = new (std::nothrow) uint8_t[frameSize]; 
        
        if (!rawData) {
            std::cerr << "[KRITIK] Bellek yetersiz! Frame " << frameId << " olusturulamadi." << std::endl;
        } else {
            // Belleği temizle 
            std::memset(rawData, 0, frameSize);
            std::cout << "[Bellek] Frame " << frameId << " icin " << frameSize << " byte ayrildi." << std::endl;
        }
    }
    
    CameraFrame(const CameraFrame& other) : frameSize(other.frameSize), frameId(other.frameId + 1000) {
        rawData = new uint8_t[frameSize];
        // Belleği fiziksel olarak kopyalıyoruz
        std::memcpy(rawData, other.rawData, frameSize);
        std::cout << "[Bellek] Frame " << other.frameId << " derin kopyalandi -> Yeni ID: " << frameId << std::endl;
    }

    // Destructor: Bellek İadesi (Deallocation)
    ~CameraFrame() {
        if (rawData != nullptr) {
            delete[] rawData; 
            rawData = nullptr; // Dangling Pointer (asılı kalan pointer) oluşumunu engeller
            std::cout << "[Bellek] Frame " << frameId << " temizlendi." << std::endl;
        }
    }

    void displayStatus() const {
        if (rawData) std::cout << "Frame ID: " << frameId << " hazir." << std::endl;
    }
};

int main() {
    {
        //Scope Yönetimi
        CameraFrame frontCam(1920 * 1080 * 3, 101); // 1080p RGB Frame
        frontCam.displayStatus();

        // Nesne kopyalama
        CameraFrame detectionFrame = frontCam; 
        detectionFrame.displayStatus();
    } // Burada Scope biter, Destructor'lar otomatik çağrılır.

    std::cout << "Program sonu. Tum bellek iade edildi." << std::endl;
    return 0;
}