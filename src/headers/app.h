#ifndef APP_H
#define APP_H

#include <string>
#include <store.h>


class App {
public:
    // Callback function to handle received data
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *userp) {
        size_t total_size = size * nmemb;
        userp->append((char*)contents, total_size);
        return total_size;
    }

    void setStore(App& app);

    void ParseJsonResponse(const std::string& readBuffer, Store& targetStore);

    void JSON_Request_Silpo(Store& targetStore);

    std::vector<Product> runSilpo();
    std::vector<Product> runATB();

};

#endif // APP_H