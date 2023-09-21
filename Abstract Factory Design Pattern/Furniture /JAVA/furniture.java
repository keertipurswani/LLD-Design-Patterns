interface Sofa {
    void sitOn();
}

// Abstract Product: Chair
interface Chair {
    void sitOn();
}

// Abstract Product: Table
interface Table {
    void place();
}

// Concrete Products: Modern Furniture Items
class ModernSofa implements Sofa {
    public void sitOn() {
        System.out.println("Sitting on a Modern Sofa");
    }
}

class ModernChair implements Chair {
    public void sitOn() {
        System.out.println("Sitting on a Modern Chair");
    }
}

class ModernTable implements Table {
    public void place() {
        System.out.println("Placing items on a Modern Table");
    }
}

// Concrete Products: Traditional Furniture Items
class TraditionalSofa implements Sofa {
    public void sitOn() {
        System.out.println("Sitting on a Traditional Sofa");
    }
}

class TraditionalChair implements Chair {
    public void sitOn() {
        System.out.println("Sitting on a Traditional Chair");
    }
}

class TraditionalTable implements Table {
    public void place() {
        System.out.println("Placing items on a Traditional Table");
    }
}

// Abstract Factory: Furniture Factory
interface FurnitureFactory {
    Sofa createSofa();
    Chair createChair();
    Table createTable();

    public static FurnitureFactory createFurnitureFactory(String type) {
        if (type.equals("modern")) {
            return new ModernFurnitureFactory();
        } else if (type.equals("traditional")) {
            return new TraditionalFurnitureFactory();
        } else {
            return null;
        }
    }
}

// Concrete Factory: Modern Furniture Factory
class ModernFurnitureFactory implements FurnitureFactory {
    public Sofa createSofa() {
        return new ModernSofa();
    }

    public Chair createChair() {
        return new ModernChair();
    }

    public Table createTable() {
        return new ModernTable();
    }
}

// Concrete Factory: Traditional Furniture Factory
class TraditionalFurnitureFactory implements FurnitureFactory {
    public Sofa createSofa() {
        return new TraditionalSofa();
    }

    public Chair createChair() {
        return new TraditionalChair();
    }

    public Table createTable() {
        return new TraditionalTable();
    }
}

public class furniture {
    public static void main(String[] args) {
        FurnitureFactory modernFactory = FurnitureFactory.createFurnitureFactory("modern");
        // use the abstract factory to create factories

        // Create Modern furniture items
        Sofa modernSofa = modernFactory.createSofa();
        Chair modernChair = modernFactory.createChair();
        Table modernTable = modernFactory.createTable();

        // Use Modern furniture items
        modernSofa.sitOn();
        modernChair.sitOn();
        modernTable.place();

        // Create a Traditional Furniture Factory
        FurnitureFactory traditionalFactory = FurnitureFactory.createFurnitureFactory("traditional");

        // Create Traditional furniture items
        Sofa traditionalSofa = traditionalFactory.createSofa();
        Chair traditionalChair = traditionalFactory.createChair();
        Table traditionalTable = traditionalFactory.createTable();

        // Use Traditional furniture items
        traditionalSofa.sitOn();
        traditionalChair.sitOn();
        traditionalTable.place();
    }
}