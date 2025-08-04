#include <iostream>
#include <app.h>
#include <store.h>
#include <app.h>


void App::setStore(App& app) {
    Store mySilpoStore;

    mySilpoStore.setStoreName("Silpo");
    std::cout << mySilpoStore.getStoreName() << std::endl;

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


}
