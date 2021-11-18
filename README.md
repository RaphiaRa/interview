### Minimum Requirements
- CMake, at least Version 3.2
- A C++14 capable compiler
- git

### Clone & Build Tests 
#### On Linux & MacOs with make
``` bash
git clone https://github.com/RaphiaRa/interview.git
mkdir interview/build; cd interview/build
git submodule update --init
cmake ..
make
```
#### On Windows
- Visual Studio 2017+ has built-in support for CMake Projects.
- For older Visual Studio Versions, cmake should create appropriate Visual Studio project files.
``` bash
git clone https://github.com/RaphiaRa/interview.git
mkdir interview/build; cd interview/build
git submodule update --init
cmake ..
```

### Run Tests
``` bash
./Interview-tests
```

##### Run specific tests cases
``` bash
./Interview-tests test_task_xx
```
##### For example, to run the test cases for task_02, run
``` bash
./Interview-tests test_task_02
```
