#include <iostream>

using namespace std;

// Product class representing individual products
class Product {
    private:
        string name;
        double price;

    public:
        Product(const string& name, const double& price) : name(name), price(price) {}

        const string& getName() const {
            return name;
        }

        double getPrice() const {
            return price;
        }
};

// Iterator interface
class Iterator {
    public:
        virtual ~Iterator() {}
        virtual Product* first() = 0;
        virtual Product* next() = 0;
        virtual bool hasNext() = 0;
};

// Concrete iterator for the product collection
class ProductIterator : public Iterator {
    private:

        vector<Product*>& products;
        size_t current;

    public:

        ProductIterator(vector<Product*>& products) : products(products), current(0) {}

        Product* first() {
            if (products.empty()) {
                return nullptr;
            }
            current = 0;
            return products[current];
        }

        Product* next() {
            if (hasNext()) {
                return products[++current];
            }
            return nullptr;
        }

        bool hasNext() {
            return current < products.size();
        }
};

// Aggregate class that stores products and provides an iterator
class Inventory {
    private:
        vector<Product*> products;
    public:
        void addProduct(Product* product) {
            products.push_back(product);
        }

        Iterator* createIterator() {
            return new ProductIterator(products);
        }
};


int main() {

    // Create some products
    Product product1("Laptop", 99999.99);
    Product product2("Smartphone", 49999.99);
    Product product3("Headphones", 7999.99);

    // Create an inventory and add products
    Inventory inventory;
    inventory.addProduct(&product1);
    inventory.addProduct(&product2);
    inventory.addProduct(&product3);

    // Create an iterator and iterate over the products
    Iterator* iterator = inventory.createIterator();
    Product* currentProduct = iterator->first();

    while (currentProduct) {
        cout << "Product: " << currentProduct->getName() << 
                        ", Price: $" << currentProduct->getPrice() << std::endl;
        currentProduct = iterator->next();
    }

    delete iterator;

    return 0;
}