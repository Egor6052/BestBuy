#include "product.h"
#include <iostream>
#include <algorithm>
#include <cctype>

Product::Product()
    : name()
    , description()
    , price(0.0f)
    , mainImage() {
}

Product::~Product() = default;

void Product::setNameProduct(const std::string& valueName) {
    if (valueName.empty()) {
        std::cerr << "Error: Name must not be empty.\n";
    }
    // При потребі: обмеження довжини
    if (valueName.size() > 256) {
        std::cerr << "Error: Name is too long (max 256 characters).\n";
    }
    name = valueName;
}

const std::string& Product::getNameProduct() const {
    return name;
}

void Product::setDescriptionProduct(const std::string& valueDescription) {
    if (valueDescription.empty()) {
        std::cerr << "Error: Description must not be empty.\n";
    }
    description = valueDescription;
}

const std::string& Product::getDescriptionProduct() const {
    return description;
}

void Product::setPriceProduct(float valuePrice) {
    if (valuePrice < 0.0f) {
        std::cerr << "Error: Price must be non-negative.\n";
    }
    price = valuePrice;
}

float Product::getPriceProduct() const {
    return price;
}

void Product::setImageProduct(const std::string& valueImage) {
    if (valueImage.empty()) {
        std::cerr << "Error: Image path/URL must not be empty.\n";
    }
    mainImage = valueImage;
}

const std::string& Product::getImageProduct() const {
    return mainImage;
}
