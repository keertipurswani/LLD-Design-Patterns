// Abstract Product: Furniture Item
interface FurnitureItem {
    void display();
}

// Concrete Products: Sofa, Chair, Table
class Sofa implements FurnitureItem {
    @Override
    public void display() {
        System.out.println("Sofa");
    }
}

class Chair implements FurnitureItem {
    @Override
    public void display() {
        System.out.println("Chair");
    }
}

class Table implements FurnitureItem {
    @Override
    public void display() {
        System.out.println("Table");
    }
}

// Abstract Creator: Furniture Factory
interface FurnitureFactory {
    FurnitureItem createFurniture();
}

// Concrete Creators: Sofa Factory, Chair Factory, Table Factory
class SofaFactory implements FurnitureFactory {
    @Override
    public FurnitureItem createFurniture() {
        return new Sofa();
    }
}

class ChairFactory implements FurnitureFactory {
    @Override
    public FurnitureItem createFurniture() {
        return new Chair();
    }
}

class TableFactory implements FurnitureFactory {
    @Override
    public FurnitureItem createFurniture() {
        return new Table();
    }
}

public class furniture {
    public static void main(String[] args) {
        // Create factories for different types of furniture
        FurnitureFactory sofaFactory = new SofaFactory();
        FurnitureFactory chairFactory = new ChairFactory();
        FurnitureFactory tableFactory = new TableFactory();

        // Create furniture objects using the factory methods
        FurnitureItem sofa = sofaFactory.createFurniture();
        FurnitureItem chair = chairFactory.createFurniture();
        FurnitureItem table = tableFactory.createFurniture();

        // Display the created furniture items
        sofa.display();
        chair.display();
        table.display();
    }
}