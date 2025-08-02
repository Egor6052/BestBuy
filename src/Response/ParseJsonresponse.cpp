#include <iostream>
#include <curl/curl.h>
#include <string>
#include <app.h>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

void App::ParseJsonResponse(std::string readBuffer) {

    try {
        // Parse JSON response
        auto json_response = json::parse(readBuffer);

        // Check if "items" exists
        if (json_response.contains("items") && json_response["items"].is_array()) {
            for (const auto& item : json_response["items"]) {
                // Extract name
                std::string name = item.value("name", "Немає назви");
                std::cout << "Назва: " << name << std::endl;

                // Extract description from parameters
                std::string description = "Опис відсутній";
                if (item.contains("parameters") && item["parameters"].is_array()) {
                    for (const auto& param : item["parameters"]) {
                        if (param.value("key", "") == "description for silpo.ua/MA") {
                            description = param.value("value", "Опис відсутній");
                            break;
                        }
                    }
                }
                std::cout << "Опис: " << description << std::endl;

                // Extract price
                std::string price = "Ціна відсутня";
                if (item.contains("prices") && item["prices"].is_array()) {
                    for (const auto& p : item["prices"]) {
                        if (p.value("Type", "") == "price") {
                            price = std::to_string(p.value("Value", 0.0));
                            break;
                        }
                    }
                }
                std::cout << "Ціна: " << price << " грн" << std::endl;

                // Extract main image
                std::string mainImage = item.value("mainImage", "Зображення відсутнє");
                std::cout << "Зображення: " << mainImage << std::endl;

                std::cout << "----------------------------------------" << std::endl;
            }
        } else {
            std::cout << "Товари не знайдено в відповіді." << std::endl;
        }
    } catch (const json::exception& e) {
        std::cerr << "Помилка парсингу JSON: " << e.what() << std::endl;
    }
}