#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class Product {

private:
    std::string name;
    std::string description;
    float price;
    std::string mainImage;

public:

    Product();
    ~Product();

    void setNameProduct(const std::string& valueName);
    const std::string& getNameProduct() const ;

    void setDescriptionProduct(const std::string& valueDescription);
    const std::string& getDescriptionProduct() const ;

    void setPriceProduct(float valuePrice);
    float getPriceProduct() const ;

    void setImageProduct(const std::string& valueImage);
    const std::string& getImageProduct() const ;

};


#endif // PRODUCT_H