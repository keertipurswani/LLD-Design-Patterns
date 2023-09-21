//The Factory Method pattern is a creational design pattern that defines an interface for creating objects but lets subclasses alter the type of objects that will be created.

#include <iostream>
#include <string>

// Abstract Product: Furniture Item
class FurnitureItem {
public:
    virtual void display() = 0;
};

// Concrete Products: Sofa, Chair, Table
class Sofa : public FurnitureItem {
public:
    void display() override {
        std::cout << "Sofa" << std::endl;
    }
};

class Chair : public FurnitureItem {
public:
    void display() override {
        std::cout << "Chair" << std::endl;
    }
};

class Table : public FurnitureItem {
public:
    void display() override {
        std::cout << "Table" << std::endl;
    }
};

// Abstract Creator: Furniture Factory
class FurnitureFactory {
public:
    virtual FurnitureItem* createFurniture() = 0;
};

// Concrete Creators: Sofa Factory, Chair Factory, Table Factory
class SofaFactory : public FurnitureFactory {
public:
    FurnitureItem* createFurniture() override {
        return new Sofa();
    }
};

class ChairFactory : public FurnitureFactory {
public:
    FurnitureItem* createFurniture() override {
        return new Chair();
    }
};

class TableFactory : public FurnitureFactory {
public:
    FurnitureItem* createFurniture() override {
        return new Table();
    }
};

int main() {
    // Create factories for different types of furniture
    FurnitureFactory* sofaFactory = new SofaFactory();
    FurnitureFactory* chairFactory = new ChairFactory();
    FurnitureFactory* tableFactory = new TableFactory();

    // Create furniture objects using the factory methods
    FurnitureItem* sofa = sofaFactory->createFurniture();
    FurnitureItem* chair = chairFactory->createFurniture();
    FurnitureItem* table = tableFactory->createFurniture();

    // Display the created furniture items
    sofa->display();
    chair->display();
    table->display();

    // Clean up objects
    delete sofaFactory;
    delete chairFactory;
    delete tableFactory;
    delete sofa;
    delete chair;
    delete table;

    return 0;
}