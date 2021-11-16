### Requirements
- CMake at least Version 3.2
- make
- A C++14 capable compiler
- git

### Build Tests
``` bash
git submodule init
mkdir build; cd build
cmake ..
make
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
