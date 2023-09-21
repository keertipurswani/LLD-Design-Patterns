#include <iostream>

// Abstract Product: Sofa
class Sofa {
public:
    virtual void sitOn() = 0;
};

// Abstract Product: Chair
class Chair {
public:
    virtual void sitOn() = 0;
};

// Abstract Product: Table
class Table {
public:
    virtual void place() = 0;
};

// Concrete Products: Modern Furniture Items
class ModernSofa : public Sofa {
public:
    void sitOn() override {
        std::cout << "Sitting on a Modern Sofa" << std::endl;
    }
};

class ModernChair : public Chair {
public:
    void sitOn() override {
        std::cout << "Sitting on a Modern Chair" << std::endl;
    }
};

class ModernTable : public Table {
public:
    void place() override {
        std::cout << "Placing items on a Modern Table" << std::endl;
    }
};

// Concrete Products: Traditional Furniture Items
class TraditionalSofa : public Sofa {
public:
    void sitOn() override {
        std::cout << "Sitting on a Traditional Sofa" << std::endl;
    }
};

class TraditionalChair : public Chair {
public:
    void sitOn() override {
        std::cout << "Sitting on a Traditional Chair" << std::endl;
    }
};

class TraditionalTable : public Table {
public:
    void place() override {
        std::cout << "Placing items on a Traditional Table" << std::endl;
    }
};

// Abstract Factory: Furniture Factory
class FurnitureFactory {
public:
    virtual Sofa* createSofa() = 0;
    virtual Chair* createChair() = 0;
    virtual Table* createTable() = 0;

    static FurnitureFactory* CreateFurnitureFactory(std::string type) {
        if (type == "modern") {
            return new ModernFurnitureFactory();
        }
        else if (type == "traditional") {
            return new TraditionalFurnitureFactory();
        }
        else return nullptr;
    }
};

// Concrete Factory: Modern Furniture Factory
class ModernFurnitureFactory : public FurnitureFactory {
public:
    Sofa* createSofa() override {
        return new ModernSofa();
    }

    Chair* createChair() override {
        return new ModernChair();
    }

    Table* createTable() override {
        return new ModernTable();
    }
};

// Concrete Factory: Traditional Furniture Factory
class TraditionalFurnitureFactory : public FurnitureFactory {
public:
    Sofa* createSofa() override {
        return new TraditionalSofa();
    }

    Chair* createChair() override {
        return new TraditionalChair();
    }

    Table* createTable() override {
        return new TraditionalTable();
    }
};

int main() {
    FurnitureFactory* modernFactory = FurnitureFactory::CreateFurnitureFactory("modern");
    //use the abstract factory to create factories

    // Create Modern furniture items
    Sofa* modernSofa = modernFactory->createSofa();
    Chair* modernChair = modernFactory->createChair();
    Table* modernTable = modernFactory->createTable();

    // Use Modern furniture items
    modernSofa->sitOn();
    modernChair->sitOn();
    modernTable->place();

    // Clean up Modern Factory objects
    delete modernFactory;
    delete modernSofa;
    delete modernChair;
    delete modernTable;

    // Create a Traditional Furniture Factory
    FurnitureFactory* traditionalFactory = FurnitureFactory::CreateFurnitureFactory("traditional");

   // FurnitureFactory* traditionalFactory = new TraditionalFurnitureFactory();

    // Create Traditional furniture items
    Sofa* traditionalSofa = traditionalFactory->createSofa();
    Chair* traditionalChair = traditionalFactory->createChair();
    Table* traditionalTable = traditionalFactory->createTable();

    // Use Traditional furniture items
    traditionalSofa->sitOn();
    traditionalChair->sitOn();
    traditionalTable->place();

    // Clean up Traditional Factory objects
    delete traditionalFactory;
    delete traditionalSofa;
    delete traditionalChair;
    delete traditionalTable;

    return 0;
}