#include <iostream>
using namespace std;

class FileSystemComponent {
public:
    virtual void listContents() const = 0;
    virtual int getSize() const = 0;
};

class File : public FileSystemComponent {
private:
    string name;
    int size;

public:
    File(const string& fileName, int fileSize) : name(fileName), size(fileSize) {}

    void listContents() const override {
        cout << "File: " << name << endl;
    }

    int getSize() const override {
        return size;
    }
};

#include <vector>

class Directory : public FileSystemComponent {
private:
    string name;
    vector<FileSystemComponent*> contents;

public:
    Directory(const string& dirName) : name(dirName) {}

    void addComponent(FileSystemComponent* component) {
        contents.push_back(component);
    }

    void listContents() const override {
        cout << "Directory: " << name << endl;
        for (const auto& component : contents) {
            component->listContents();
        }
    }

    int getSize() const override {
        int totalSize = 0;
        for (const auto& component : contents) {
            totalSize += component->getSize();
        }
        return totalSize;
    }
};

int main() {
    Directory* root = new Directory("Root");

    FileSystemComponent* file1 = new File("Document.txt", 100);
    FileSystemComponent* file2 = new File("Image.jpg", 200);

    Directory* subDir = new Directory("Subdirectory");
    FileSystemComponent* file3 = new File("Data.csv", 150);

    subDir->addComponent(file3);

    root->addComponent(file1);
    root->addComponent(file2);
    root->addComponent(subDir);

    // List contents and calculate total size for the directory structure
    root->listContents();
    int totalSize = root->getSize();
    cout << "Total Size: " << totalSize << " KB" << endl;

    // Clean up memory (consider using smart pointers in a real application)
    delete root;
    delete file1;
    delete file2;
    delete file3;
    delete subDir;

    return 0;
}