// app.cpp
#include <iostream>
#include <nlohmann/json.hpp>
#include "app.h"
#include "store.h" // <--- Додаємо, щоб App знав про Store
#include "product.h" // Вже може бути підключено через store.h або app.h

using json = nlohmann::json;

// Змінюємо сигнатуру ParseJsonResponse, щоб вона приймала об'єкт Store за посиланням
void App::ParseJsonResponse(const std::string& readBuffer, Store& targetStore) {
    try {
        auto json_response = json::parse(readBuffer);
        if (json_response.contains("items") && json_response["items"].is_array()) {
            // Store targetStore;
            
            targetStore.clearProducts();

            for (const auto& item : json_response["items"]) {
                Product product;
                
                product.setNameProduct(item.value("name", "Немає назви"));
                std::string description = "Опис відсутній";
                if (item.contains("parameters") && item["parameters"].is_array()) {
                    for (const auto& param : item["parameters"]) {
                        if (param.value("key", "") == "description for silpo.ua/MA") {
                            description = param.value("value", "Опис відсутній");
                            break;
                        }
                    }
                }
                product.setDescriptionProduct(description);

                float price = 0.0f;
                if (item.contains("prices") && item["prices"].is_array()) {
                    for (const auto& p : item["prices"]) {
                        if (p.value("Type", "") == "price") {
                            price = p.value("Value", 0.0f);
                            break;
                        }
                    }
                }
                product.setPriceProduct(price);
                product.setImageProduct(item.value("mainImage", "Зображення відсутнє"));

                targetStore.addProduct(product);

                // std::cout << "Назва: " << product.getNameProduct() << std::endl;
                // std::cout << "Опис: " << product.getDescriptionProduct() << std::endl;
                // std::cout << "Ціна: " << product.getPriceProduct() << " грн" << std::endl;
                // std::cout << "Зображення: " << product.getImageProduct() << std::endl;
                // std::cout << "----------------------------------------" << std::endl;
            }
        } else {
            std::cout << "Товари не знайдено в відповіді." << std::endl;
        }
    } catch (const json::exception& e) {
        std::cerr << "Помилка парсингу JSON: " << e.what() << std::endl;
    }
}