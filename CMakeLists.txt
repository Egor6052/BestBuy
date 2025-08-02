cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# Назва проекту
project(start LANGUAGES CXX)

# Встановлення стандарту C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Опція для використання статичних бібліотек
option(USE_STATIC "Use static library" ON)

# Вивід повідомлення про систему
message(STATUS "OS: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Compile with static library? ${USE_STATIC}")

# Знаходження бібліотеки CURL
find_package(CURL REQUIRED)
if(NOT CURL_FOUND)
    message(WARNING "CURL not found via find_package, trying manual paths")
    find_library(CURL_LIBRARY NAMES curl libcurl PATHS /usr/lib /usr/lib/x86_64-linux-gnu)
    find_path(CURL_INCLUDE_DIR NAMES curl/curl.h PATHS /usr/include /usr/include/x86_64-linux-gnu)
    if(CURL_LIBRARY AND CURL_INCLUDE_DIR)
        message(STATUS "Manually found CURL: ${CURL_LIBRARY}, ${CURL_INCLUDE_DIR}")
    else()
        message(FATAL_ERROR "Could not find CURL manually")
    endif()
endif()

# Шлях до вихідних файлів
set(SOURCE_FILES
    src/main.cpp

    # Connection
    # src/Connection/Connection.cpp

    # Product
    # src/Product/Product.cpp
    
)

# Додавання виконуваного файлу
add_executable(start
    ${SOURCE_FILES}
)

# Компіляторні опції
target_compile_options(start
    PRIVATE
        -Wall -fPIC
)

# Підключення include-шляхів
target_include_directories(start
    PRIVATE
        include  # Змінено з src/headers на include, де лежить nlohmann/json.hpp
        src/headers
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CURL_INCLUDE_DIR}
)

# Лінкування бібліотек
target_link_libraries(start
    PRIVATE
        ${CURL_LIBRARY}
)

# Для статичного лінкування (якщо USE_STATIC увімкнено)
if(USE_STATIC)
    if(UNIX AND NOT APPLE)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")
    endif()
endif()