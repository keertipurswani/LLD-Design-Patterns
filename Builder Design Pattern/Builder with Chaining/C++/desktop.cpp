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
    virtual DesktopBuilder &buildMotherboard() = 0;
    virtual DesktopBuilder &buildProcessor() = 0;
    virtual DesktopBuilder &buildMemory() = 0;
    virtual DesktopBuilder &buildStorage() = 0;
    virtual DesktopBuilder &buildGraphicsCard() = 0;

    Desktop build()
    {
        return desktop;
    }
};

class DellDesktopBuilder : public DesktopBuilder
{
public:
    DesktopBuilder &buildMotherboard()
    {
        desktop.motherboard = "Dell Motherboard";
        return *this;
    }

    DesktopBuilder &buildProcessor()
    {
        desktop.processor = "Dell Processor";
        return *this;
    }

    DesktopBuilder &buildMemory()
    {
        desktop.memory = "32GB DDR4 RAM";
        return *this;
    }

    DesktopBuilder &buildStorage()
    {
        desktop.storage = "1TB SSD + 2TB HDD";
        return *this;
    }

    DesktopBuilder &buildGraphicsCard()
    {
        desktop.graphicsCard = "NVIDIA RTX 3080";
        return *this;
    }
};

class HpDesktopBuilder : public DesktopBuilder
{
public:
    DesktopBuilder &buildMotherboard()
    {
        desktop.motherboard = "Hp Motherboard";
        return *this;
    }

    DesktopBuilder &buildProcessor()
    {
        desktop.processor = "Intel Core i5";
        return *this;
    }

    DesktopBuilder &buildMemory()
    {
        desktop.memory = "16GB DDR4 RAM";
        return *this;
    }

    DesktopBuilder &buildStorage()
    {
        desktop.storage = "512GB SSD";
        return *this;
    }

    DesktopBuilder &buildGraphicsCard()
    {
        desktop.graphicsCard = "Integrated Graphics";
        return *this;
    }
};

class DesktopDirector
{
public:
    Desktop buildComputer(DesktopBuilder &builder)
    {
        return builder.buildMotherboard().buildProcessor().buildMemory().buildStorage().buildGraphicsCard().build();
    }
};

int main()
{
    DesktopDirector director;

    DellDesktopBuilder dellDesktopBuilder;
    Desktop highEndComputer = director.buildComputer(dellDesktopBuilder);

    HpDesktopBuilder officeBuilder;
    Desktop officeComputer = director.buildComputer(officeBuilder);

    highEndComputer.display();
    officeComputer.display();

    return 0;
}