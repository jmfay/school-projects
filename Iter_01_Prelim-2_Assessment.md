### Iteration 1 - Prelim-2 Partial Assessment (Graded By: Shrivardhan Bharadwaj)

Run on November 23, 12:41:06 PM.

<hr>

This Partial Assessment indicates a TA has begun grading your unit tests. However, unit tests will be graded using a Canvas rubric and grades will only be posted on Canvas once the unit tests of every student have been graded. We ask for your patience at this time.

<hr>

+ Pass: Checkout deliverable 2 submission




#### Necessary Files and Structure

+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Check that directory "project/tests" exists.

+ Pass: Check that directory "project/docs" exists.


#### Unit Test Inspection

+ Pass: Change into directory "project/tests".

+ Pass: Manually reviewing Passenger unit tests...

    

+ Pass: Copy file "Using instructor makefile to only compile the Passenger class along with the Passenger unit tests.".



+ Pass: Check that directory "../../external" exists.

+ Fail: Check that make compiles.

    Make compile fails with errors:.
<pre>cd /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external; make
make[1]: Entering directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external'
cd gtest; make
make[2]: Entering directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest'
git clone https://github.com/google/googletest.git src
Cloning into 'src'...
Checking out files:  90% (239/263)   Checking out files:  91% (240/263)   Checking out files:  92% (242/263)   Checking out files:  93% (245/263)   Checking out files:  94% (248/263)   Checking out files:  95% (250/263)   Checking out files:  96% (253/263)   Checking out files:  97% (256/263)   Checking out files:  98% (258/263)   Checking out files:  99% (261/263)   Checking out files: 100% (263/263)   Checking out files: 100% (263/263), done.
mkdir -p build
cd build; CC=/soft/gcc/7.1.0/Linux_x86_64/bin/gcc CXX=/soft/gcc/7.1.0/Linux_x86_64/bin/g++ cmake ../src -DCMAKE_INSTALL_PREFIX=/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install
-- The C compiler identification is GNU 7.1.0
-- The CXX compiler identification is GNU 7.1.0
-- Check for working C compiler: /soft/gcc/7.1.0/Linux_x86_64/bin/gcc
-- Check for working C compiler: /soft/gcc/7.1.0/Linux_x86_64/bin/gcc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /soft/gcc/7.1.0/Linux_x86_64/bin/g++
-- Check for working CXX compiler: /soft/gcc/7.1.0/Linux_x86_64/bin/g++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found PythonInterp: /usr/bin/python (found version "2.7.15") 
-- Looking for pthread.h
-- Looking for pthread.h - found
-- Looking for pthread_create
-- Looking for pthread_create - not found
-- Looking for pthread_create in pthreads
-- Looking for pthread_create in pthreads - not found
-- Looking for pthread_create in pthread
-- Looking for pthread_create in pthread - found
-- Found Threads: TRUE  
-- Configuring done
-- Generating done
-- Build files have been written to: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build
cd build; cmake --build . --target install
make[3]: Entering directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build'
make[4]: Entering directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build'
make[5]: Entering directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build'
Scanning dependencies of target gtest
make[5]: Leaving directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build'
make[5]: Entering directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build'
[ 12%] Building CXX object googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[ 25%] Linking CXX static library ../lib/libgtest.a
make[5]: Leaving directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build'
[ 25%] Built target gtest
make[5]: Entering directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build'
Scanning dependencies of target gmock
make[5]: Leaving directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build'
make[5]: Entering directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build'
[ 37%] Building CXX object googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 50%] Linking CXX static library ../lib/libgmock.a
make[5]: Leaving directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build'
[ 50%] Built target gmock
make[5]: Entering directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build'
Scanning dependencies of target gmock_main
make[5]: Leaving directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build'
make[5]: Entering directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build'
[ 62%] Building CXX object googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[ 75%] Linking CXX static library ../lib/libgmock_main.a
make[5]: Leaving directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build'
[ 75%] Built target gmock_main
make[5]: Entering directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build'
Scanning dependencies of target gtest_main
make[5]: Leaving directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build'
make[5]: Entering directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build'
[ 87%] Building CXX object googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[100%] Linking CXX static library ../lib/libgtest_main.a
make[5]: Leaving directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build'
[100%] Built target gtest_main
make[4]: Leaving directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build'
Install the project...
-- Install configuration: ""
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/gmock-generated-actions.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/gmock-more-actions.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/gmock-actions.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/gmock-cardinalities.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/gmock-generated-function-mockers.h.pump
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/gmock-nice-strict.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/gmock.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/gmock-more-matchers.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/gmock-generated-matchers.h.pump
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/gmock-generated-actions.h.pump
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/internal
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/internal/gmock-port.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/internal/gmock-internal-utils.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/internal/custom
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/internal/custom/gmock-generated-actions.h.pump
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/internal/custom/gmock-matchers.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/internal/custom/gmock-generated-actions.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/internal/custom/README.md
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/internal/custom/gmock-port.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/internal/gmock-pp.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/gmock-matchers.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/gmock-spec-builders.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/gmock-function-mocker.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/gmock-generated-function-mockers.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gmock/gmock-generated-matchers.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/lib/libgmock.a
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/lib/libgmock_main.a
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/lib/pkgconfig/gmock.pc
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/lib/pkgconfig/gmock_main.pc
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/lib/cmake/GTest/GTestTargets.cmake
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/lib/cmake/GTest/GTestTargets-noconfig.cmake
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/lib/cmake/GTest/GTestConfigVersion.cmake
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/lib/cmake/GTest/GTestConfig.cmake
-- Up-to-date: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/gtest-typed-test.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/gtest-test-part.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/gtest.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/internal
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/internal/gtest-param-util.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/internal/gtest-port-arch.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/internal/gtest-port.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/internal/custom
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/internal/custom/gtest-printers.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/internal/custom/gtest-port.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/internal/custom/README.md
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/internal/custom/gtest.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/internal/gtest-filepath.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/internal/gtest-internal.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/internal/gtest-type-util.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/internal/gtest-string.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/internal/gtest-death-test-internal.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/gtest-printers.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/gtest-param-test.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/gtest-death-test.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/gtest_prod.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/gtest-message.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/gtest-matchers.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/gtest_pred_impl.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/gtest-spi.h
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/lib/libgtest.a
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/lib/libgtest_main.a
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/lib/pkgconfig/gtest.pc
-- Installing: /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/lib/pkgconfig/gtest_main.pc
make[3]: Leaving directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest/build'
make[2]: Leaving directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/gtest'
make[1]: Leaving directory '/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external'
==== Auto-Generating Dependencies for ../src/passenger.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/tests/passenger.d -MP -MT ../build/obj/tests/passenger.o -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include   -std=c++11 ../src/passenger.cc
==== Compiling ../src/passenger.cc into ../build/obj/tests/passenger.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include   -std=c++11  -c -o  ../build/obj/tests/passenger.o ../src/passenger.cc
==== Auto-Generating Dependencies for passenger_UT.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/tests/passenger_UT.d -MP -MT ../build/obj/tests/passenger_UT.o -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include   -std=c++11 passenger_UT.cc
==== Compiling passenger_UT.cc into ../build/obj/tests/passenger_UT.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include   -std=c++11  -c -o  ../build/obj/tests/passenger_UT.o passenger_UT.cc
passenger_UT.cc: In member function virtual void PassengerTests::SetUp():
passenger_UT.cc:29:3: error: passenger3 was not declared in this scope
   passenger3 = new Passenger();
   ^~~~~~~~~~
passenger_UT.cc:29:3: note: suggested alternative: passenger
   passenger3 = new Passenger();
   ^~~~~~~~~~
   passenger
passenger_UT.cc: In member function virtual void PassengerTests::TearDown():
passenger_UT.cc:35:10: error: passenger3 was not declared in this scope
   delete passenger3;
          ^~~~~~~~~~
passenger_UT.cc:35:10: note: suggested alternative: passenger
   delete passenger3;
          ^~~~~~~~~~
          passenger
passenger_UT.cc: In member function virtual void PassengerTests_updateTest_Test::TestBody():
passenger_UT.cc:56:19: error: request for member Update in ((PassengerTests_updateTest_Test*)this)->PassengerTests_updateTest_Test::<anonymous>.PassengerTests::waitPassenger, which is of pointer type Passenger* (maybe you meant to use -> ?)
     waitPassenger.Update();
                   ^~~~~~
passenger_UT.cc:57:19: error: request for member Update in ((PassengerTests_updateTest_Test*)this)->PassengerTests_updateTest_Test::<anonymous>.PassengerTests::waitPassenger, which is of pointer type Passenger* (maybe you meant to use -> ?)
     waitPassenger.Update();
                   ^~~~~~
passenger_UT.cc:58:19: error: request for member GetOnBus in ((PassengerTests_updateTest_Test*)this)->PassengerTests_updateTest_Test::<anonymous>.PassengerTests::waitPassenger, which is of pointer type Passenger* (maybe you meant to use -> ?)
     waitPassenger.GetOnBus();
                   ^~~~~~~~
passenger_UT.cc:59:19: error: request for member Update in ((PassengerTests_updateTest_Test*)this)->PassengerTests_updateTest_Test::<anonymous>.PassengerTests::waitPassenger, which is of pointer type Passenger* (maybe you meant to use -> ?)
     waitPassenger.Update();
                   ^~~~~~
In file included from /project/grades/Fall-2019/csci3081/bhara054/grading-environment/grading-scripts/grading/Iter_01_Prelim-2_Assessment/repo-fayxx092/external/install/include/gtest/gtest.h:375:0,
                 from passenger_UT.cc:15:
passenger_UT.cc:60:29: error: request for member GetTotalWait in ((PassengerTests_updateTest_Test*)this)->PassengerTests_updateTest_Test::<anonymous>.PassengerTests::waitPassenger, which is of pointer type Passenger* (maybe you meant to use -> ?)
     EXPECT_EQ(waitPassenger.GetTotalWait(), 3);
                             ^
passenger_UT.cc: In member function virtual void PassengerTests_TotalWaitTest_Test::TestBody():
passenger_UT.cc:64:2: error: passenger3 was not declared in this scope
  passenger3.Update();
  ^~~~~~~~~~
passenger_UT.cc:64:2: note: suggested alternative: passenger
  passenger3.Update();
  ^~~~~~~~~~
  passenger
Makefile:155: recipe for target '../build/obj/tests/passenger_UT.o' failed
make: *** [../build/obj/tests/passenger_UT.o] Error 1
</pre>



+ Skip: Check that file "../build/bin/unittest" exists.

  This test was not run because of an earlier failing test.

+ Skip: Get all google tests.

  This test was not run because of an earlier failing test.


#### Unit Test Results

<hr>

Note that your unit tests were *not* expected to pass. This test simply makes sure that your unit tests can and do run.

<hr>

+  _0_ / _5_ : Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

+  _0_ / _5_ : Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

+  _0_ / _5_ : Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

+  _0_ / _5_ : Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

