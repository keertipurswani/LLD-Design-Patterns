// Abstract Product: Furniture Item
class FurnitureItem {
    display() {}
}

// Concrete Products: Sofa, Chair, Table
class Sofa extends FurnitureItem {
    display() {
        console.log("Sofa");
    }
}

class Chair extends FurnitureItem {
    display() {
        console.log("Chair");
    }
}

class Table extends FurnitureItem {
    display() {
        console.log("Table");
    }
}

// Abstract Creator: Furniture Factory
class FurnitureFactory {
    createFurniture() {}
}

// Concrete Creators: Sofa Factory, Chair Factory, Table Factory
class SofaFactory extends FurnitureFactory {
    createFurniture() {
        return new Sofa();
    }
}

class ChairFactory extends FurnitureFactory {
    createFurniture() {
        return new Chair();
    }
}

class TableFactory extends FurnitureFactory {
    createFurniture() {
        return new Table();
    }
}

function main() {
    // Create factories for different types of furniture
    const sofaFactory = new SofaFactory();
    const chairFactory = new ChairFactory();
    const tableFactory = new TableFactory();

    // Create furniture objects using the factory methods
    const sofa = sofaFactory.createFurniture();
    const chair = chairFactory.createFurniture();
    const table = tableFactory.createFurniture();

    // Display the created furniture items
    sofa.display();
    chair.display();
    table.display();
}

main();
