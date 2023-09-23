# Abstract Product: Furniture Item
class FurnitureItem:
    def display(self):
        pass

# Concrete Products: Sofa, Chair, Table
class Sofa(FurnitureItem):
    def display(self):
        print("Sofa")

class Chair(FurnitureItem):
    def display(self):
        print("Chair")

class Table(FurnitureItem):
    def display(self):
        print("Table")

# Abstract Creator: Furniture Factory
class FurnitureFactory:
    def create_furniture(self):
        pass

# Concrete Creators: Sofa Factory, Chair Factory, Table Factory
class SofaFactory(FurnitureFactory):
    def create_furniture(self):
        return Sofa()

class ChairFactory(FurnitureFactory):
    def create_furniture(self):
        return Chair()

class TableFactory(FurnitureFactory):
    def create_furniture(self):
        return Table()

def main():
    # Create factories for different types of furniture
    sofa_factory = SofaFactory()
    chair_factory = ChairFactory()
    table_factory = TableFactory()

    # Create furniture objects using the factory methods
    sofa = sofa_factory.create_furniture()
    chair = chair_factory.create_furniture()
    table = table_factory.create_furniture()

    # Display the created furniture items
    sofa.display()
    chair.display()
    table.display()

if __name__ == "__main__":
    main()
