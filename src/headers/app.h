#ifndef APP_H
#define APP_H

#include <string>

class App {
public:
    // Callback function to handle received data
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *userp) {
        size_t total_size = size * nmemb;
        userp->append((char*)contents, total_size);
        return total_size;
    }

    void ParseJsonResponse(const std::string& readBuffer);

    void JSON_Request_Silpo();

    void Store();
};

#endif // APP_H