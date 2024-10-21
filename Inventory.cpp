//Programmer: Sadad Yusuf.
//Project: Create an InventoryItem Structure.
//Date: Oct-21-2024
/**
 *Pseudocode
 * Start
 STRUCTURE InventoryItem
        string name
        string sku
        string description
        string category
        double price
        integer quantity
    END STRUCTURE

FUNCTION print_single_item(item)
END FUNCTION

print_inventory(inventory_array, size)
    FOR each item in inventory_array
        CALL print_single_item(i)
END FUNCTION

MAIN PROGRAM
    SET array_size = 5
    CREATE inventory_array of size array_size

    // Add predefined items (first 3)
    SET item[0] to hammer details
    SET item[1] to nail details
    SET item[2] to awl details

    // Get user input for remaining items
    FOR i = 3 to array_size - 1
        INPUT item details from user
        STORE in inventory_array[i]
    END FOR
   // Print everything
    CALL print_inventory(inventory_array, array_size)

End Program

 ***/
#include <iomanip>
#include <iostream>
//Create a structure for inventory item
struct Inventory_Item {
    std::string name;
    std::string sku;
    std::string description;
    std::string category;
    double price{};
    int quantity{};
};
//Create a function that prints a single InventoryItem.
void print_single_inventory(const Inventory_Item &item);
// Create a function that prints all the inventory items in the array of struct
void print_inventory(Inventory_Item inventory[], int size);
int main() {
    // Create a program that creates an array of 5 Inventory items.
    const int size = 5;
    Inventory_Item my_inventory_item[size];
    // Store the first item in the array
    my_inventory_item[0].name = "Hammer";
    my_inventory_item[0].sku = "ABZ127";
    my_inventory_item[0].category = "Hardware";
    my_inventory_item[0].price = 7.98;
    my_inventory_item[0].quantity = 200;
    // store the second item in the array
    my_inventory_item[1].name = "Nail";
    my_inventory_item[1].sku = "CDX349";
    my_inventory_item[1].category = "Fastener";
    my_inventory_item[1].price = 1.27;
    my_inventory_item[1].quantity = 3000;
    // store the third item in the array
    my_inventory_item[2].name = "Awl";
    my_inventory_item[2].sku = "ABZ376";
    my_inventory_item[2].category = "Hardware";
    my_inventory_item[2].price = 3.62;
    my_inventory_item[2].quantity = 38;
// Ask a user to input two more items in the array of size 5
    for (int i = 3; i < size; i++) {
        std::cout <<"please provide inventory item details such as: name,sku,category,price,and quantity "<< std::endl;
        std::cout<<"Name: ";
        std::cin>>my_inventory_item[i].name;
        std::cout<<" sku: ";
        std::cin>>my_inventory_item[i].sku;
        std::cout<<" category: ";
        std::cin>>my_inventory_item[i].category;
        std::cout<<" price: ";
        std::cin>>my_inventory_item[i].price;
        std::cout<<" quantity: ";
        std::cin>>my_inventory_item[i].quantity;
    }
    // Print all the inventory Items to the Console.
    print_inventory(my_inventory_item, size);

    return 0;
}
void print_single_inventory(const Inventory_Item &item) {
    std::cout<<"\n-----------------------------------------\n";
    std::cout<<" Name: "<<item.name<<std::endl;
    std::cout<<" sku: "<<item.sku<<std::endl;
    std::cout<<" Category: "<<item.category<<std::endl;
    std::cout<<" Price: "<<item.price<<std:: fixed<<std::setprecision(2)<<std::endl;;
    std::cout<<" Quantity: "<<item.quantity<<std::endl;
    std::cout<<"---------------------------------------------\n";

    }
void print_inventory(Inventory_Item inventory[], int size) {
    std::cout<<"\n=========== Inventory Items ===============\n"<<std::endl;
    for (int i = 0; i < size; i++) {
        print_single_inventory(inventory[i]);
    }
}
