// main.cpp
#include <iostream>
#include <curl/curl.h> // Потрібно для curl_global_cleanup()
#include "app.h"
#include "store.h"
#include "product.h" // Може знадобитися, якщо ви виводите деталі Product

int main() {
    App app;
    Store mySilpoStore;

    app.JSON_Request_Silpo(mySilpoStore);

    std::cout << "\n--- Продукти в магазині " << mySilpoStore.getStoreName() << " ---" << std::endl;
    if (mySilpoStore.getProducts().empty()) {
        std::cout << "Товари не знайдено або сталася помилка." << std::endl;
    } else {
        for (const auto& product : mySilpoStore.getProducts()) {
            std::cout << "Назва: " << product.getNameProduct() << std::endl;
            std::cout << "Опис: " << product.getDescriptionProduct() << std::endl;
            std::cout << "Ціна: " << product.getPriceProduct() << " грн" << std::endl;
            std::cout << "Зображення: " << product.getImageProduct() << std::endl;
            std::cout << "----------------------------------------" << std::endl;
        }
    }

    return 0;
}