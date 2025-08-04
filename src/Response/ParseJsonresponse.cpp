#include <iostream>
#include <nlohmann/json.hpp>
#include <app.h>
#include <product.h>

using json = nlohmann::json;

void App::ParseJsonResponse(const std::string& readBuffer, Store& store) {
    try {
        auto json_response = json::parse(readBuffer);
        if (json_response.contains("items") && json_response["items"].is_array()) {
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

                // Встановлюємо назву магазину
                product.setStoreName(store.getStoreName());

                // Додаємо продукт до магазину
                store.addProduct(product);
            }
        } else {
            std::cout << "Товари не знайдено в відповіді." << std::endl;
        }
    } catch (const json::exception& e) {
        std::cerr << "Помилка парсингу JSON: " << e.what() << std::endl;
    }
}