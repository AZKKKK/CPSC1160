#include <iostream>
#include <iomanip>

#ifndef PRODUCT_H
#define PRODUCT_H

// Product Class
class Product {
public:
    std::string name;
    double price;
    int quantity;
};

//String Case insensitive equality comparison
bool isEqual(const std::string left, const std::string right);

//operator overloading function for product
std::istream& operator>>(std::istream& in, Product& p) {
    std::cout << "Enter Product Name: ";
    in >> p.name;
    while(p.name == "") {
        std::cout << "Enter Product Name: ";
        in >> p.name;
    }

    std::cout << "Enter Product Price: ";
    in >> p.price;
    while(p.price < 0) {
        std::cout << "Enter Product Price: ";
        in >> p.price;
    }


    std::cout << "Enter Product Quantity: ";
    in >> p.quantity;
    while(p.quantity < 0) {
        std::cout << "Enter Product Quantity: ";
        in >> p.quantity;
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const Product p) {
    out << "Name: " << p.name << ", Price: " <<  
    std::setprecision(2) << std::fixed << p.price
    <<", Quantity: " << p.quantity << std::endl;

    return out;
}


bool operator==(const Product& left, const Product& right) {
    return isEqual(left.name,right.name) && 
    left.price == right.price;
}

bool isEqual(const std::string left, const std::string right) {
    if(left.length() != right.length()) 
        return false;
        
    for(unsigned char i = 0; i < left.length(); i ++) {
        if(tolower(left[i]) != tolower(right[i]))
            return false;
    }

    return true;
}

#endif //PRODUCT_H