// Base interface representing a food item.
// Component
interface FoodItem {
    String getDescription();
    double getPrice();
}

// Concrete component
class Pizza implements FoodItem {
    public String getDescription() {
        return "Pizza";
    }

    public double getPrice() {
        return 200.0;
    }
}

// Concrete component
class Burger implements FoodItem {
    public String getDescription() {
        return "Burger";
    }

    public double getPrice() {
        return 100.0;
    }
}

// Decorator interface
abstract class Decorator implements FoodItem {
    protected FoodItem foodItem;

    public Decorator(FoodItem item) {
        this.foodItem = item;
    }
}

// Concrete decorator for adding extra cheese.
class ExtraCheeseDecorator extends Decorator {
    private double extraCheesePrice;

    public ExtraCheeseDecorator(FoodItem item, double price) {
        super(item);
        this.extraCheesePrice = price;
    }

    public String getDescription() {
        return foodItem.getDescription() + " with Extra Cheese";
    }

    public double getPrice() {
        return foodItem.getPrice() + extraCheesePrice;
    }
}

// Concrete decorator for adding extra sauce.
class ExtraSauceDecorator extends Decorator {
    private double extraSaucePrice;

    public ExtraSauceDecorator(FoodItem item, double price) {
        super(item);
        this.extraSaucePrice = price;
    }

    public String getDescription() {
        return foodItem.getDescription() + " with Extra Sauce";
    }

    public double getPrice() {
        return foodItem.getPrice() + extraSaucePrice;
    }
}

// Concrete decorator for adding extra toppings.
class ExtraToppingsDecorator extends Decorator {
    private double extraToppingsPrice;

    public ExtraToppingsDecorator(FoodItem item, double price) {
        super(item);
        this.extraToppingsPrice = price;
    }

    public String getDescription() {
        return foodItem.getDescription() + " with Extra Toppings";
    }

    public double getPrice() {
        return foodItem.getPrice() + extraToppingsPrice;
    }
}

public class Swiggy {
    public static void main(String[] args) {
        // Order a Pizza and a Burger.
        FoodItem pizzaOrder = new Pizza();
        FoodItem burgerOrder = new Burger();

        pizzaOrder = new ExtraCheeseDecorator(pizzaOrder, 10.0);
        pizzaOrder = new ExtraSauceDecorator(pizzaOrder, 5.0);

        burgerOrder = new ExtraCheeseDecorator(burgerOrder, 20.0);
        burgerOrder = new ExtraToppingsDecorator(burgerOrder, 15.0);

        System.out.println("Description of pizza order is " + pizzaOrder.getDescription());
        System.out.println("Price of pizza order is: " + pizzaOrder.getPrice());

        System.out.println("Description of burger order is " + burgerOrder.getDescription());
        System.out.println("Price of burger order is: " + burgerOrder.getPrice());
    }
}
