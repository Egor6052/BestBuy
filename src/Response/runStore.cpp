#include <iostream>
#include <curl/curl.h>
#include <algorithm>
#include <string>
#include <app.h>
#include <store.h>
#include <nlohmann/json.hpp>

std::vector<Product> App::runSilpo() {
    Store mySilpoStore;
    mySilpoStore.setStoreName("Silpo");
    JSON_Request_Silpo(mySilpoStore);
    return mySilpoStore.getProducts();
}

std::vector<Product> App::runATB() {
    // TODO: Реалізувати запит до API АТБ
    std::cout << "Товарів від АТБ поки нема!" << std::endl;
    return std::vector<Product>();
}