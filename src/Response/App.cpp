#include <iostream>
#include <curl/curl.h>
#include <string>
#include <app.h>
#include <store.h>

void App::JSON_Request_Silpo(Store& targetStore) {
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    // Initialize libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        // Set URL
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.catalog.ecom.silpo.ua/api/2.0/exec/EcomCatalogGlobal");

        // Set headers
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.163 Safari/537.36");
        headers = curl_slist_append(headers, "Content-Type: application/json;charset=UTF-8");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // Get product name from user
        std::string nameProduct;
        std::cout << "Введіть назву товару: " << std::endl;
        std::getline(std::cin, nameProduct);

        if (nameProduct.size() > 256) {
            std::cerr << "Помилка: Назва занадто довга (максимум 256 символів)." << std::endl;
            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            return;
        }

        // Escape quotes in the product name for JSON
        std::string escapedProduct = nameProduct;
        size_t pos = 0;
        while ((pos = escapedProduct.find('"', pos)) != std::string::npos) {
            escapedProduct.replace(pos, 1, "\\\"");
            pos += 2;
        }

        // Construct JSON POST data dynamically
        std::string post_data = "{\"method\": \"GetSimpleCatalogItems\", \"data\": {\"customFilter\": \"" + escapedProduct + "\", \"filialId\": \"2405\", \"skuPerPage\": 5, \"pageNumber\": 1}}";
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data.c_str());

        // Set callback function to handle response
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, App::WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Perform the request
        res = curl_easy_perform(curl);

        // Check for errors
        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            ParseJsonResponse(readBuffer, targetStore);
        }

        // Cleanup
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
}


