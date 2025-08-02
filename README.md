
## Best Buy
---
 An app that searches multiple stores to find the lowest price for your query.

---
**_Content:_**
- [Distributed Data Collection System](#distributed-data-collection-system)
- [Features](#features)
  - [System Architecture](#system-architecture)
- [API](#api)
- [Compiling](#compiling)
- [Daemon Management](#daemon-management)
  - [Start server:](#start-server)
- [For develoders](#for-develoders)
- [Ho to push](#ho-to-push)
- [Libraries and extensions](#libraries-and-extensions)
- [Create user for System](#create-user-for-system)
- [Add users to DB](#add-users-to-db)
---

## Compiling in the directory ./build
---
Configuration:
```sh
cmake ..
```
Compile the binary:
```sh
cmake --build .
```
Start:
```sh
sudo ./start
```


## Libraries and extensions
---
**For JSON format:**
**Debian** apt
```sh
sudo apt install nlohmann-json-devel
```
**Fedora** dnf
```sh
sudo dnf install nlohmann-json-devel
```
