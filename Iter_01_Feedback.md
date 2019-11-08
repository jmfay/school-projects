### Feedback for Iteration 1

Run on November 08, 03:35:44 AM.

<hr>

This feedback is being batched and will run every few hours. Note that these feedback tests are a *work in progress* and will likely be updated to contain more tests as they are developed. Check back periodically for more feedback. Take note that these tests are _incredibly slow_ because of the time it takes to compile 4 executables.

<hr>


### Basic Tests on Devel

+ Pass: Checkout devel branch.




#### Necessary Files and Structure

+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Check that directory "project/tests" exists.

+ Pass: Check that directory "project/docs" exists.


#### Compilation Tests

+ Pass: Change into directory "project".

+ Pass: Copy file "Copying official project makefile".



+ Pass: Copy file "Copying official src makefile".



+ Pass: Copy file "Copying official tests makefile".



+ Pass: Check that make compiles.



+ Pass: Check that file "build/bin/transit_sim" exists.

+ Pass: Change into directory "tests".

+ Fail: Check that make compiles.

    Make compile fails with errors:.
<pre>cd /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external; make
make[1]: Entering directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external'
cd gtest; make
make[2]: Entering directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest'
git clone https://github.com/google/googletest.git src
Cloning into 'src'...
Checking out files:  50% (134/263)   Checking out files:  51% (135/263)   Checking out files:  52% (137/263)   Checking out files:  53% (140/263)   Checking out files:  54% (143/263)   Checking out files:  55% (145/263)   Checking out files:  56% (148/263)   Checking out files:  57% (150/263)   Checking out files:  58% (153/263)   Checking out files:  59% (156/263)   Checking out files:  60% (158/263)   Checking out files:  61% (161/263)   Checking out files:  62% (164/263)   Checking out files:  63% (166/263)   Checking out files:  64% (169/263)   Checking out files:  65% (171/263)   Checking out files:  66% (174/263)   Checking out files:  67% (177/263)   Checking out files:  68% (179/263)   Checking out files:  69% (182/263)   Checking out files:  70% (185/263)   Checking out files:  71% (187/263)   Checking out files:  72% (190/263)   Checking out files:  73% (192/263)   Checking out files:  74% (195/263)   Checking out files:  75% (198/263)   Checking out files:  76% (200/263)   Checking out files:  77% (203/263)   Checking out files:  78% (206/263)   Checking out files:  79% (208/263)   Checking out files:  80% (211/263)   Checking out files:  81% (214/263)   Checking out files:  82% (216/263)   Checking out files:  83% (219/263)   Checking out files:  84% (221/263)   Checking out files:  85% (224/263)   Checking out files:  86% (227/263)   Checking out files:  87% (229/263)   Checking out files:  88% (232/263)   Checking out files:  89% (235/263)   Checking out files:  90% (237/263)   Checking out files:  91% (240/263)   Checking out files:  92% (242/263)   Checking out files:  93% (245/263)   Checking out files:  94% (248/263)   Checking out files:  95% (250/263)   Checking out files:  96% (253/263)   Checking out files:  97% (256/263)   Checking out files:  98% (258/263)   Checking out files:  99% (261/263)   Checking out files: 100% (263/263)   Checking out files: 100% (263/263), done.
mkdir -p build
cd build; CC=/soft/gcc/7.1.0/Linux_x86_64/bin/gcc CXX=/soft/gcc/7.1.0/Linux_x86_64/bin/g++ cmake ../src -DCMAKE_INSTALL_PREFIX=/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install
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
-- Build files have been written to: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build
cd build; cmake --build . --target install
make[3]: Entering directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build'
make[4]: Entering directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build'
make[5]: Entering directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build'
Scanning dependencies of target gtest
make[5]: Leaving directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build'
make[5]: Entering directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build'
[ 12%] Building CXX object googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[ 25%] Linking CXX static library ../lib/libgtest.a
make[5]: Leaving directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build'
[ 25%] Built target gtest
make[5]: Entering directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build'
Scanning dependencies of target gmock
make[5]: Leaving directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build'
make[5]: Entering directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build'
[ 37%] Building CXX object googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 50%] Linking CXX static library ../lib/libgmock.a
make[5]: Leaving directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build'
[ 50%] Built target gmock
make[5]: Entering directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build'
Scanning dependencies of target gmock_main
make[5]: Leaving directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build'
make[5]: Entering directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build'
[ 62%] Building CXX object googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[ 75%] Linking CXX static library ../lib/libgmock_main.a
make[5]: Leaving directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build'
[ 75%] Built target gmock_main
make[5]: Entering directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build'
Scanning dependencies of target gtest_main
make[5]: Leaving directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build'
make[5]: Entering directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build'
[ 87%] Building CXX object googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[100%] Linking CXX static library ../lib/libgtest_main.a
make[5]: Leaving directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build'
[100%] Built target gtest_main
make[4]: Leaving directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build'
Install the project...
-- Install configuration: ""
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/gmock-more-matchers.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/gmock-generated-matchers.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/gmock-nice-strict.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/gmock-generated-matchers.h.pump
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/gmock-actions.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/gmock-cardinalities.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/gmock.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/internal
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/internal/gmock-pp.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/internal/gmock-internal-utils.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/internal/custom
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/internal/custom/gmock-port.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/internal/custom/gmock-generated-actions.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/internal/custom/gmock-matchers.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/internal/custom/gmock-generated-actions.h.pump
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/internal/custom/README.md
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/internal/gmock-port.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/gmock-generated-function-mockers.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/gmock-more-actions.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/gmock-matchers.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/gmock-spec-builders.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/gmock-generated-actions.h.pump
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/gmock-generated-actions.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/gmock-generated-function-mockers.h.pump
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gmock/gmock-function-mocker.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/lib/libgmock.a
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/lib/libgmock_main.a
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/lib/pkgconfig/gmock.pc
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/lib/pkgconfig/gmock_main.pc
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/lib/cmake/GTest/GTestTargets.cmake
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/lib/cmake/GTest/GTestTargets-noconfig.cmake
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/lib/cmake/GTest/GTestConfigVersion.cmake
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/lib/cmake/GTest/GTestConfig.cmake
-- Up-to-date: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/gtest_pred_impl.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/gtest-typed-test.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/gtest-printers.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/gtest_prod.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/gtest-message.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/internal
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/internal/gtest-filepath.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/internal/custom
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/internal/custom/gtest.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/internal/custom/gtest-port.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/internal/custom/gtest-printers.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/internal/custom/README.md
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/internal/gtest-death-test-internal.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/internal/gtest-string.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/internal/gtest-type-util.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/internal/gtest-port.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/internal/gtest-internal.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/internal/gtest-param-util.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/internal/gtest-port-arch.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/gtest-spi.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/gtest.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/gtest-matchers.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/gtest-param-test.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/gtest-death-test.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include/gtest/gtest-test-part.h
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/lib/libgtest.a
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/lib/libgtest_main.a
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/lib/pkgconfig/gtest.pc
-- Installing: /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/lib/pkgconfig/gtest_main.pc
make[3]: Leaving directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest/build'
make[2]: Leaving directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/gtest'
make[1]: Leaving directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external'
==== Auto-Generating Dependencies for ../src/local_simulator.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/tests/local_simulator.d -MP -MT ../build/obj/tests/local_simulator.o -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include   -std=c++11 ../src/local_simulator.cc
==== Compiling ../src/local_simulator.cc into ../build/obj/tests/local_simulator.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include   -std=c++11  -c -o  ../build/obj/tests/local_simulator.o ../src/local_simulator.cc
==== Auto-Generating Dependencies for ../src/bus.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/tests/bus.d -MP -MT ../build/obj/tests/bus.o -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include   -std=c++11 ../src/bus.cc
==== Compiling ../src/bus.cc into ../build/obj/tests/bus.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include   -std=c++11  -c -o  ../build/obj/tests/bus.o ../src/bus.cc
../src/bus.cc: In member function bool Bus::LoadPassenger(Passenger*):
../src/bus.cc:17:26: warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
   if (passengers_.size() == passenger_max_capacity_) {
       ~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~
==== Auto-Generating Dependencies for ../src/random_passenger_generator.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/tests/random_passenger_generator.d -MP -MT ../build/obj/tests/random_passenger_generator.o -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include   -std=c++11 ../src/random_passenger_generator.cc
==== Compiling ../src/random_passenger_generator.cc into ../build/obj/tests/random_passenger_generator.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include   -std=c++11  -c -o  ../build/obj/tests/random_passenger_generator.o ../src/random_passenger_generator.cc
==== Auto-Generating Dependencies for ../src/passenger.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/tests/passenger.d -MP -MT ../build/obj/tests/passenger.o -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include   -std=c++11 ../src/passenger.cc
==== Compiling ../src/passenger.cc into ../build/obj/tests/passenger.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include   -std=c++11  -c -o  ../build/obj/tests/passenger.o ../src/passenger.cc
==== Auto-Generating Dependencies for ../src/passenger_generator.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/tests/passenger_generator.d -MP -MT ../build/obj/tests/passenger_generator.o -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include   -std=c++11 ../src/passenger_generator.cc
==== Compiling ../src/passenger_generator.cc into ../build/obj/tests/passenger_generator.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include   -std=c++11  -c -o  ../build/obj/tests/passenger_generator.o ../src/passenger_generator.cc
==== Auto-Generating Dependencies for ../src/route.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/tests/route.d -MP -MT ../build/obj/tests/route.o -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include   -std=c++11 ../src/route.cc
==== Compiling ../src/route.cc into ../build/obj/tests/route.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include   -std=c++11  -c -o  ../build/obj/tests/route.o ../src/route.cc
==== Auto-Generating Dependencies for ../src/stop.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/tests/stop.d -MP -MT ../build/obj/tests/stop.o -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include   -std=c++11 ../src/stop.cc
==== Compiling ../src/stop.cc into ../build/obj/tests/stop.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include   -std=c++11  -c -o  ../build/obj/tests/stop.o ../src/stop.cc
==== Auto-Generating Dependencies for ../src/passenger_factory.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/tests/passenger_factory.d -MP -MT ../build/obj/tests/passenger_factory.o -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include   -std=c++11 ../src/passenger_factory.cc
==== Compiling ../src/passenger_factory.cc into ../build/obj/tests/passenger_factory.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include   -std=c++11  -c -o  ../build/obj/tests/passenger_factory.o ../src/passenger_factory.cc
==== Auto-Generating Dependencies for passenger_UT.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/tests/passenger_UT.d -MP -MT ../build/obj/tests/passenger_UT.o -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include   -std=c++11 passenger_UT.cc
==== Compiling passenger_UT.cc into ../build/obj/tests/passenger_UT.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include -I.. -I. -isystem/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Iter_01_Feedback/repo-fayxx092/external/install/include   -std=c++11  -c -o  ../build/obj/tests/passenger_UT.o passenger_UT.cc
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
passenger_UT.cc: In member function virtual void PassengerTests_TotalWaitTest_Test::TestBody():
passenger_UT.cc:64:2: error: passenger3 was not declared in this scope
  passenger3->Update();
  ^~~~~~~~~~
passenger_UT.cc:64:2: note: suggested alternative: passenger
  passenger3->Update();
  ^~~~~~~~~~
  passenger
Makefile:154: recipe for target '../build/obj/tests/passenger_UT.o' failed
make: *** [../build/obj/tests/passenger_UT.o] Error 1
</pre>



+ Skip: Check that file "../build/bin/unittest" exists.

  This test was not run because of an earlier failing test.

+ Pass: Change into directory "..".


#### Style Tests

+ Pass: Change into directory "src/".

+ Pass: Check that file "mainpage.h" exists.

+ Pass: Ignoring mainpage.h



+ Pass: Grading style compliancy errors (Found: 0 errors)

+ Pass: Restoring mainpage.h



+ Pass: Change into directory "..".


#### Doxygen Tests

+ Pass: Change into directory "docs/".


##### .gitignore configured properly

+ Pass: Check that file/directory "html" does not exist.

+ Pass: Check that file/directory "latex" does not exist.

+ Pass: Check that file "Doxyfile" exists.

+ Pass: Generating documentation by running doxygen

+ Pass: Check that directory "html" exists.

+ Pass: Check that file "html/classPassenger.html" exists.

+ Pass: Removing generated html and/or latex directories...



+ Pass: Change into directory "..".

+ Pass: Change into directory "..".

+ Pass: Resetting repo...




### Basic Tests on Master

+ Pass: Checkout master branch.




#### Necessary Files and Structure

+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Check that directory "project/tests" exists.

+ Pass: Check that directory "project/docs" exists.


#### Compilation Tests

+ Pass: Change into directory "project".

+ Pass: Copy file "Copying official project makefile".



+ Pass: Copy file "Copying official src makefile".



+ Pass: Copy file "Copying official tests makefile".



+ Pass: Check that make compiles.



+ Pass: Check that file "build/bin/transit_sim" exists.

+ Pass: Change into directory "tests".

+ Pass: Check that make compiles.



+ Pass: Check that file "../build/bin/unittest" exists.

+ Pass: Change into directory "..".


#### Style Tests

+ Pass: Change into directory "src/".

+ Pass: Check that file "mainpage.h" exists.

+ Pass: Ignoring mainpage.h



+ Pass: Grading style compliancy errors (Found: 0 errors)

+ Pass: Restoring mainpage.h



+ Pass: Change into directory "..".


#### Doxygen Tests

+ Pass: Change into directory "docs/".


##### .gitignore configured properly

+ Pass: Check that file/directory "html" does not exist.

+ Pass: Check that file/directory "latex" does not exist.

+ Pass: Check that file "Doxyfile" exists.

+ Pass: Generating documentation by running doxygen

+ Pass: Check that directory "html" exists.

+ Pass: Check that file "html/classPassenger.html" exists.

+ Pass: Removing generated html and/or latex directories...



+ Pass: Change into directory "..".

+ Pass: Change into directory "..".

+ Pass: Resetting repo...




### Git Usage

+ Pass: Run git ls-remote gather all branches in repo

		df692a1d0a516dd99196586205db12d5afd0a47e	refs/heads/devel

		15f185ed80cae30ab560c24221a1286282cb5e0f	refs/heads/fix/01-compilation-errors

		e34808ddc49f201ddab6db635f2951f7155d5cde	refs/heads/fix/02-passenger-enhancement

		b9fdfd3fc8f3202e1a7de251582c3463400f5a56	refs/heads/fix/03-priority1-stop-enhancement

		7058055e55cff5646478a558fce16346f2bb1348	refs/heads/fix/04-output-refactoring

		3b86f7748466731a08d030207da8b6159f8ca025	refs/heads/fix/05-bus-enhancement

		d49927415e0d7738cd775b33fca7287b3f44ae8b	refs/heads/fix/06-bus-route-enhancement

		389043e85550ea6d492bd7540b16a8e90ab1757f	refs/heads/fix/07-google-styling

		ca8b11343d395df0696f3d8f39dd1d912c0312d5	refs/heads/fix/08-doxygen-big4-documentation

		6868d1c122850509435e4889830d541489a34904	refs/heads/master



