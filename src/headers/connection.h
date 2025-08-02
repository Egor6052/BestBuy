#ifndef CONNECTION_H
#define CONNECTION_H

#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include "product.h"

using json = nlohmann::json;

class Connection {
private:
    CURL* curl;
    struct curl_slist* headers;
    std::string response_string;
    std::string url;
    json request_body;
    json parsed_response;
    std::vector<Product> products; // Зберігаємо продукти

public:
    Connection();
    ~Connection();

    // Статична функція для запису відповіді від curl
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s);

    // Виконання запиту до API
    bool executeRequest();

    // Отримання JSON-відповіді
    json getResponse() const;

    // Обробка JSON-відповіді та створення продуктів
    bool processResponse();

    // Отримання всіх продуктів
    const std::vector<Product>& getProducts() const;

    // Фільтрація продуктів за назвою
    std::vector<Product> filtration(const std::string& nameProduct) const;

    void foramtJson(std::string nameTovar, int ID, int skuPerPage, int pageNumber);

};

#endif // CONNECTION_H