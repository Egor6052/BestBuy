#include <iostream>
#include <curl/curl.h>
#include <algorithm>
#include <vector>
#include <app.h>
#include <store.h>
#include <product.h>

int main() {
    App app;

    // Отримуємо продукти з Сільпо та АТБ
    std::vector<Product> silpoProducts = app.runSilpo();
    std::vector<Product> atbProducts = app.runATB();

    // Об’єднуємо продукти в один вектор
    std::vector<Product> allProducts;
    allProducts.reserve(silpoProducts.size() + atbProducts.size());
    allProducts.insert(allProducts.end(), silpoProducts.begin(), silpoProducts.end());
    allProducts.insert(allProducts.end(), atbProducts.begin(), atbProducts.end());

    // Сортуємо продукти за зростанням ціни
    std::sort(allProducts.begin(), allProducts.end(),
        [](const Product& a, const Product& b) {
            return a.getPriceProduct() < b.getPriceProduct();
        });

    // Виводимо відсортовані продукти
    std::cout << "\n--- Усі продукти, відсортовані за ціною ---" << std::endl;
    if (allProducts.empty()) {
        std::cout << "Товари не знайдено або сталася помилка." << std::endl;
    } else {
        for (const auto& product : allProducts) {
            std::cout << "\n--- Продукт в магазині " << product.getStoreName() << " ---" << std::endl;
            std::cout << "Назва: " << product.getNameProduct() << std::endl;
            std::cout << "Опис: " << product.getDescriptionProduct() << std::endl;
            std::cout << "Ціна: " << product.getPriceProduct() << " грн" << std::endl;
            std::cout << "Зображення: " << product.getImageProduct() << std::endl;
            std::cout << "----------------------------------------" << std::endl;
        }
    }

    curl_global_cleanup();
    return 0;
}