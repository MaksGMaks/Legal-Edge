### Installation
1. Clone the repo

   ```
   git clone https://github.com/MaksGMaks/Legal-Edge.git
   ```

2. Install prerequisites
   ```
   conan install . --output-folder=build --build=missing
   ```
 
3. Go to build folder and run cmake with presets

   ```
   cd build
   cmake .. --preset conan-debug -DBUILD_CLIENT=ON -DBUILD_SERVER=ON
   ```

4. Build the project

   ```
   cmake --build .
   ```
