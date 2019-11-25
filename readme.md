# PID Controller using Test Driven Development
[![Build Status](https://travis-ci.org/Arjung27/PID-Controller.svg?branch=master)](https://travis-ci.org/Arjung27/PID-Controller)
[![Coverage Status](https://coveralls.io/repos/github/Arjung27/PID-Controller/badge.svg?branch=master)](https://coveralls.io/github/Arjung27/PID-Controller?branch=master)
---

## Authors
Part 1

- Driver    : [Arjung27](https://github.com/Arjung27)
- Navigator : [kartikmadhira1](https://github.com/kartikmadhira1)

Part 2(Implementation)

- Driver     : [kartikmadhira1](https://github.com/kartikmadhira1)
- Navigator  : [Arjung27](https://github.com/Arjung27)

## Standard install via command-line
```
git clone --recursive https://github.com/Arjung27/PID-Controller.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Run cpplint for Google c++ styleguide errors
```
cd <path to repository>
cpplint app/*.cpp include/*.hpp test/*.cpp

```
## Run cppcheck
```
cd <path to repository>
cppcheck --enable=all --std=c++11 -I include/ --suppress=missingIncludeSystem $( find . -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/" )

```
