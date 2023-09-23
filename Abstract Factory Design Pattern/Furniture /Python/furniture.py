# Abstract Product: Sofa
class Sofa:
    def sit_on(self):
        pass

# Abstract Product: Chair
class Chair:
    def sit_on(self):
        pass

# Abstract Product: Table
class Table:
    def place(self):
        pass

# Concrete Products: Modern Furniture Items
class ModernSofa(Sofa):
    def sit_on(self):
        print("Sitting on a Modern Sofa")

class ModernChair(Chair):
    def sit_on(self):
        print("Sitting on a Modern Chair")

class ModernTable(Table):
    def place(self):
        print("Placing items on a Modern Table")

# Concrete Products: Traditional Furniture Items
class TraditionalSofa(Sofa):
    def sit_on(self):
        print("Sitting on a Traditional Sofa")

class TraditionalChair(Chair):
    def sit_on(self):
        print("Sitting on a Traditional Chair")

class TraditionalTable(Table):
    def place(self):
        print("Placing items on a Traditional Table")

# Abstract Factory: Furniture Factory
class FurnitureFactory:
    def create_sofa(self):
        pass

    def create_chair(self):
        pass

    def create_table(self):
        pass

    @staticmethod
    def create_furniture_factory(type):
        if type == "modern":
            return ModernFurnitureFactory()
        elif type == "traditional":
            return TraditionalFurnitureFactory()
        else:
            return None

# Concrete Factory: Modern Furniture Factory
class ModernFurnitureFactory(FurnitureFactory):
    def create_sofa(self):
        return ModernSofa()

    def create_chair(self):
        return ModernChair()

    def create_table(self):
        return ModernTable()

# Concrete Factory: Traditional Furniture Factory
class TraditionalFurnitureFactory(FurnitureFactory):
    def create_sofa(self):
        return TraditionalSofa()

    def create_chair(self):
        return TraditionalChair()

    def create_table(self):
        return TraditionalTable()

def main():
    modern_factory = FurnitureFactory.create_furniture_factory("modern")

    # Create Modern furniture items
    modern_sofa = modern_factory.create_sofa()
    modern_chair = modern_factory.create_chair()
    modern_table = modern_factory.create_table()

    # Use Modern furniture items
    modern_sofa.sit_on()
    modern_chair.sit_on()
    modern_table.place()

    traditional_factory = FurnitureFactory.create_furniture_factory("traditional")

    # Create Traditional furniture items
    traditional_sofa = traditional_factory.create_sofa()
    traditional_chair = traditional_factory.create_chair()
    traditional_table = traditional_factory.create_table()

    # Use Traditional furniture items
    traditional_sofa.sit_on()
    traditional_chair.sit_on()
    traditional_table.place()

if __name__ == "__main__":
    main()
