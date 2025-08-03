// store.h

#ifndef STORE_H
#define STORE_H

#include <string>
#include <vector>
#include "product.h"

class Store {
private:
    std::string NameStore;
    std::string API;
    std::vector<Product> products_;

public:
    Store();
    ~Store();

    void setStoreName(std::string valueNameStore);
    std::string getStoreName();

    void setAPI(std::string valueAPI);
    std::string getAPI();

    void addProduct(const Product& product);

    // Метод для отримання всіх продуктів магазину
    const std::vector<Product>& getProducts() const;

    // Метод для очищення списку продуктів магазину
    void clearProducts();
};

#endif // STORE_H