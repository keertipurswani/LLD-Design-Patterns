#include <iostream>
using namespace std;

class Desktop
{
public:
    string motherboard;
    string processor;
    string memory;
    string storage;
    string graphicsCard;

    void display()
    {
        cout << "Desktop Specs:" << endl;
        cout << "Motherboard: " << motherboard << endl;
        cout << "Processor: " << processor << endl;
        cout << "Memory: " << memory << endl;
        cout << "Storage: " << storage << endl;
        cout << "Graphics Card: " << graphicsCard << endl;
    }
};

class DesktopBuilder
{
protected:
    Desktop desktop;

public:
    virtual void buildMotherboard() = 0;
    virtual void buildProcessor() = 0;
    virtual void buildMemory() = 0;
    virtual void buildStorage() = 0;
    virtual void buildGraphicsCard() = 0;

    Desktop getDesktop()
    {
        return desktop;
    }
};

class DellDesktopBuilder : public DesktopBuilder
{
public:
    void buildMotherboard()
    {
        desktop.motherboard = "Dell Motherboard";
    }

    void buildProcessor()
    {
        desktop.processor = "Dell Processor";
    }

    void buildMemory()
    {
        desktop.memory = "32GB DDR4 RAM";
    }

    void buildStorage()
    {
        desktop.storage = "1TB SSD + 2TB HDD";
    }

    void buildGraphicsCard()
    {
        desktop.graphicsCard = "NVIDIA RTX 3080";
    }
};

class HpDesktopBuilder : public DesktopBuilder
{
public:
    void buildMotherboard()
    {
        desktop.motherboard = "HP Motherboard";
    }

    void buildProcessor()
    {
        desktop.processor = "Intel Core i5";
    }

    void buildMemory()
    {
        desktop.memory = "16GB DDR4 RAM";
    }

    void buildStorage()
    {
        desktop.storage = "512GB SSD";
    }

    void buildGraphicsCard()
    {
        desktop.graphicsCard = "Integrated Graphics";
    }
};

class DesktopDirector
{
public:
    Desktop buildDesktop(DesktopBuilder &builder)
    {
        builder.buildMotherboard();
        builder.buildProcessor();
        builder.buildMemory();
        builder.buildStorage();
        builder.buildGraphicsCard();
        return builder.getDesktop();
    }
};

int main()
{
    DesktopDirector director;

    DellDesktopBuilder dellDesktopBuilder;
    Desktop dellDesktop = director.buildDesktop(dellDesktopBuilder);

    HpDesktopBuilder hpDesktopBuilder;
    Desktop hpDesktop = director.buildDesktop(hpDesktopBuilder);

    dellDesktop.display();
    hpDesktop.display();

    return 0;
}
