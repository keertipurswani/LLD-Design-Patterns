#include <iostream>
using namespace std;

// The Subject interface represents the Image.
class Image {
public:
    virtual void display() = 0;
};

// The RealImage is the actual implementation of the Image.
class RealImage : public Image {
private:
    string filename;

public:
    RealImage(const string& filename) : filename(filename) {
        loadFromDisk();
    }

    void display() {
        cout << "Displaying image: " << filename << endl;
    }

    void loadFromDisk() {
        cout << "Loading image from disk: " << filename << endl;
    }
};

// The ImageProxy is the proxy class that loads and displays high-resolution images on-demand.
class ImageProxy : public Image {
private:
    RealImage* realImage;
    string filename;

public:
    ImageProxy(const string& filename) : filename(filename), realImage(nullptr) {}

    void display() {
        if (!realImage) {
            realImage = new RealImage(filename);
        }
        realImage->display();
    }

    ~ImageProxy() {
        if (realImage) {
            delete realImage;
        }
    }
};

int main() {
    // Create an ImageProxy for a high-resolution image.
    ImageProxy proxy("high_res_image.jpg");

    // Display the image (loading it on-demand).
    proxy.display();

    // The image is not loaded again if we display it multiple times.
    proxy.display();

    return 0;
}
