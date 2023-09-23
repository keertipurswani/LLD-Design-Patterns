// Abstract Product: Sofa
class Sofa {
    sitOn() {}
}

// Abstract Product: Chair
class Chair {
    sitOn() {}
}

// Abstract Product: Table
class Table {
    place() {}
}

// Concrete Products: Modern Furniture Items
class ModernSofa extends Sofa {
    sitOn() {
        console.log("Sitting on a Modern Sofa");
    }
}

class ModernChair extends Chair {
    sitOn() {
        console.log("Sitting on a Modern Chair");
    }
}

class ModernTable extends Table {
    place() {
        console.log("Placing items on a Modern Table");
    }
}

// Concrete Products: Traditional Furniture Items
class TraditionalSofa extends Sofa {
    sitOn() {
        console.log("Sitting on a Traditional Sofa");
    }
}

class TraditionalChair extends Chair {
    sitOn() {
        console.log("Sitting on a Traditional Chair");
    }
}

class TraditionalTable extends Table {
    place() {
        console.log("Placing items on a Traditional Table");
    }
}

// Abstract Factory: Furniture Factory
class FurnitureFactory {
    createSofa() {}
    createChair() {}
    createTable() {}

    static createFurnitureFactory(type) {
        if (type === "modern") {
            return new ModernFurnitureFactory();
        } else if (type === "traditional") {
            return new TraditionalFurnitureFactory();
        } else {
            return null;
        }
    }
}

// Concrete Factory: Modern Furniture Factory
class ModernFurnitureFactory extends FurnitureFactory {
    createSofa() {
        return new ModernSofa();
    }

    createChair() {
        return new ModernChair();
    }

    createTable() {
        return new ModernTable();
    }
}

// Concrete Factory: Traditional Furniture Factory
class TraditionalFurnitureFactory extends FurnitureFactory {
    createSofa() {
        return new TraditionalSofa();
    }

    createChair() {
        return new TraditionalChair();
    }

    createTable() {
        return new TraditionalTable();
    }
}

function main() {
    const modernFactory = FurnitureFactory.createFurnitureFactory("modern");

    // Create Modern furniture items
    const modernSofa = modernFactory.createSofa();
    const modernChair = modernFactory.createChair();
    const modernTable = modernFactory.createTable();

    // Use Modern furniture items
    modernSofa.sitOn();
    modernChair.sitOn();
    modernTable.place();

    // Create a Traditional Furniture Factory
    const traditionalFactory = FurnitureFactory.createFurnitureFactory("traditional");

    // Create Traditional furniture items
    const traditionalSofa = traditionalFactory.createSofa();
    const traditionalChair = traditionalFactory.createChair();
    const traditionalTable = traditionalFactory.createTable();

    // Use Traditional furniture items
    traditionalSofa.sitOn();
    traditionalChair.sitOn();
    traditionalTable.place();
}

main();
