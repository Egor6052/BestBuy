#include <iostream>
#include <app.h>
#include <store.h>


void App::setStore() {
    // arrey of store, 
    Store store;
    // name in array
    store.setStoreName("Silpo");
    std::cout << store.getStoreName() << std::endl;

}
