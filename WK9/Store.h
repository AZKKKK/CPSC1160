#include <iostream>
#include "Product.h"

#ifndef STORE_H
#define STORE_H

//clss Store
class Store {
private:
    int n;
    Product* products;
public:

    //default constructor
    Store() {
        n = 0;
        products = nullptr;
    }

    //defined constructors
    Store(const int p){
        if (p <= 0) {
            n=0;
            products = nullptr;

        } else {
            n = p;
            products = new Product[p];
            for (int i = 0; i < p; i++) {
                std::cin >> products[i];
            }

        }
    }

    //deep copy constructor
    Store(const Store& copyFrom){
        this->n = copyFrom.n;
        this->products = new Product[this->n];
        for (int i = 0; i < this->n; i++) {
            *(this->products + i) = *(copyFrom.products + i);
        }
    }

    //destructor
    ~Store() {
        if (products) {
            //Deallocate Memory
            delete[] products;
            products = nullptr;
        }   
    }
    
    //getters
    Product* GetProducts() const { 
        return products; 
    }

    int GetN() const {
        return this->n;
    }

    Product GetProductAt(const int index) const {
        if( index >= this->n ) {
            std::cout << "invalid index ";
            return Product();
        }

        return this->products[index];
    }

    //setters
    void SetN(const int n) {
        this->n = n;
    }

    void SetProducts(Product* products) {
        if (this->products) {
            delete[] this->products;
        }
        this->products = products;
    }

    //overloading Operators
    Store operator=(const Store& copyFrom) {
        this->n = copyFrom.n;
        if(this->products)
            delete[] this->products;
        
        this->products = new Product[this->n];
        for (int i = 0; i < this->n; i++)
            *(this->products + i) = *(copyFrom.products + i);
        

        return *this;
    }

    // '+' operator overloading for Store
    Store operator+(const Store& right) {
        int newSize = right.n + this->n;
        Product* p = new Product[newSize];
        int k = 0;

        for(int i = 0; i < newSize; i ++) {
            if(i < this->n)
                p[i] = this->products[i];
            else    
                p[i] = right.products[k++];
        }

        delete[] this->products;
        this->products = p;
        this->n = newSize;

        merge();

        return *this;
    }


    // '+' operator overloading for int
    Store operator+(const int t) {
        if(t == 0) 
            return *this;
        
        Product* tempProducts = new Product[this->n + t];
        for(int i = 0; i < this->n; i++) {
            tempProducts[i] = this->products[i];
        }


        for(int i = n; i < this->n + t; i++) {
            std::cin >> tempProducts[i];
        }

        this->n = this->n + t;

        delete[] this->products;

        this->products = tempProducts;

        return *this;
    }
    //'-' operator overloading for Store
    Store operator-(const Store& right){
        for(int i = 0; i < this->n; i ++){
            for(int j = 0; j < right.n; j ++){
                if(this->products[i] == right.products[j]){
                    removeProduct(i);
                    i = -1;
                    break;
                }
            }
        }

        return *this;
    }

    //'-' overloading for int
    Store operator-(const int t){
        if(t == 0) 
            return *this;

        else if(t >= this->n) {
            if(this->products) {
                delete[] this->products;
                this->products = nullptr;
            }
            this->n = 0;

            return *this;
        }

        std::string name;
        for(int i = 0; i < t; i++) {
            std::cout << "Enter the name of the product will be removed: ";
            std::cin >> name;
            removeProduct(name);
        }

        return *this;
    }

    //input and output overloading
    //output: print details of every single product in the store
    friend std::ostream& operator<<(std::ostream& out, const Store& s);
    //ask user to input information of products in the store
    friend std::istream& operator>>(std::istream& in,Store& s); 

private: // Helper methods
    void removeProduct(const std::string name) {

        for(int i = 0; i < this->n; i ++) {
            if(name == this->products[i].name) {
                if(this->n == 1) {
                    delete[] this->products;
                    this->products = nullptr;
                    this->n = 0;
                    break;
                }

                const int newSize = this->n - 1;
                Product* p = new Product[newSize];
                int k = 0;
                for(int j = 0; j < this->n; j ++, k ++) {
                    if (j != i)
                        p[k] = this->products[j];
                    else   
                        k --;
                }

                delete[] this->products;
                this->products = p;
                this->n -= 1;
                i = -1;
            }

        }
    }

    void removeProduct(const int index) {
        if(this->n <= 0) return;

        if(this->n == 1){
            delete[] this->products;
            this->products = nullptr;
            this->n = 0;

            return;
        }

        Product* p = new Product[this->n - 1];
        int j = 0;


        for(int i = 0; i < this->n; i ++, j++) {
            if (i != index)
                p[j] = this->products[i];
            else
                j --;
        }

        delete[] this->products;
        this->products = p;
        this->n -= 1;
    }


    void merge(){
        if(this->n == 1 || this->n == 0){
            return;
        };

        for(int i = 0; i < this->n; i ++) {
            for(int j = i + 1; j < this->n; j ++){
                if(this->products[i] == this->products[j]) {
                    this->products[i].quantity += 
                    this->products[j].quantity;
                    removeProduct(j);
                    i = -1;
                    break;
                }
            } 

        }
    }
    
    

};

//implementation of input and output overloading
std::ostream& operator<<(std::ostream& out, const Store& s) {
    if(s.GetN() == 0 && !s.products) {
        out << "Empty Store";
    }

    for(int i = 0; i < s.n; i ++) {
        out << s.products[i];
    }

    return out;
}

std::istream& operator>>(std::istream& in,Store& s) {
    std::cout << "Enter amount of products needed to add: ";
    int k;
    in >> k;
    while(k <= 0){
        in >> k;
    }

    Product* tempPro = new Product[s.n+k];
    for(int i = 0; i < s.n + k; i ++) {
        if (i < s.n)
            tempPro[i] = s.products[i];
        else
            in >> tempPro[i];
    }

    s.SetN(s.n+k);
    s.SetProducts(tempPro);

    return in;
}


#endif // STORE_H