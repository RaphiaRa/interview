### Requirements
- CMake at least Version 3.2
- make
- A C++14 capable compiler
- git

### Clone & Build Tests
``` bash
git clone https://github.com/RaphiaRa/interview.git
mkdir interview/build; cd interview/build
git submodule update --init
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
