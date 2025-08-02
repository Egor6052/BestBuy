#include <iostream>
#include <curl/curl.h>
#include <string>
#include <app.h>

int main() {
    App app;

    app.JSON_Request_Silpo();

    curl_global_cleanup();
    return 0;
}