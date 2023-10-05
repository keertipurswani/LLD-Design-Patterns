interface Image {
    void display();
}

class RealImage implements Image {
    private String filename;

    public RealImage(String filename) {
        this.filename = filename;
        loadFromDisk();
    }

    @Override
    public void display() {
        System.out.println("Displaying image: " + filename);
    }

    private void loadFromDisk() {
        System.out.println("Loading image from disk: " + filename);
    }
}

class ImageProxy implements Image {
    private RealImage realImage;
    private String filename;

    public ImageProxy(String filename) {
        this.filename = filename;
        this.realImage = null;
    }

    @Override
    public void display() {
        if (realImage == null) {
            realImage = new RealImage(filename);
        }
        realImage.display();
    }
}

public class ImageDemo {
    public static void main(String[] args) {
        // Create an ImageProxy for a high-resolution image.
        Image proxy = new ImageProxy("high_res_image.jpg");

        // Display the image (loading it on-demand).
        proxy.display();

        // The image is not loaded again if we display it multiple times.
        proxy.display();
    }
}
