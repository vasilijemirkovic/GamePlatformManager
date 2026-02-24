\# 🎮 GamePlatformManager



GamePlatformManager is a C++ console application for managing video games and their availability across different platforms.



The project allows you to:



* create games with metadata
* filter games by platform
* organize game collections (Selection)
* compare collections
* sort games
* save and load data from files



The project was developed as an object-oriented model for working with video game collections and platforms.





\## 🚀 Features



\### 🎮 Game class



Stores:



* game name
* release year
* score (0–10)
* supported platforms



Provides:



* platform support checking
* adding new platforms
* filtering games by platform
* game comparison operator
* formatted game output
* **save/load file system**





\### 📚 Selection class



Represents a collection of games for a specific platform.



Provides:



* validation that all games support the platform
* comparison of collections by number of games
* sorting games by platform and name
* formatted collection output





\### 💾 File system



Supported operations:



* saving a list of games to a file
* loading games from a file



Storage format:



*name;year;score;platform1,platform2,...*





\## ⚙️ Compilation (MinGW)



*g++ \*.cpp -o GamePlatformManager*



Run:



*./GamePlatformManager*





\## 🧪 Testing



**main.cpp** contains tests for:



* constructor validation
* platform compatibility
* adding platforms
* game comparison
* filtering
* Selection validation
* collection comparison
* collection sorting
* file save/load system





\## 🧠 Technologies



* C++
* STL (vector, algorithm, string, iostream)
* file I/O
* operator overloading
* exception handling
* object-oriented design





\## 📄 Author



Vasilije Mirkovic

