#include <iostream>
#include <string>
#include <store.h>


Store::Store() {
    this->NameStore = "";
    this->API = "";
}

Store::~Store() {   }


void Store::setStoreName(std::string valueNameStore) {
    if (valueNameStore.empty()) {
        std::cerr << "Error: Name Store must not be empty.\n";
    }
    if (valueNameStore.size() > 256) {
        std::cerr << "Error: Name Store is too long (max 256 characters).\n";
    }
    NameStore = valueNameStore;
}

std::string Store::getStoreName() {
    return this->NameStore;
}

void Store::setAPI(std::string valueAPI) {
    if (API.empty()) {
        std::cerr << "Error: API Store must not be empty.\n";
    }
    NameStore = API;
}

std::string Store::getAPI() {
    return API;
}


void Store::addProduct(const Product& product) {
    products_.push_back(product);
}

const std::vector<Product>& Store::getProducts() const {
    return products_;
}

void Store::clearProducts() {
    products_.clear();
}
