#ifndef STORE_H
#define STORE_H

#include <string>

class Store {
    private:
    std::string NameStore;
    std::string API;

    public:
    Store();
    ~Store();

    void setStoreName(std::string valueNameStore);
    std::string getStoreName();

    void setAPI(std::string valueAPI);
    std::string getAPI();

};


#endif // STORE_H