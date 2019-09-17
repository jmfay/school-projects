### Feedback for Lab 03

Run on September 16, 22:48:30 PM.


#### Necessary Files and Structure

+ Pass: Check that directory "googletest" exists.

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab03_class_basics" exists.

+ Pass: Change into directory "labs/lab03_class_basics".


#### Essential Files Exist

+ Pass: Check that file "Makefile" exists.

+ Pass: Check that file "Makefile.test" exists.

+ Pass: Check that file ".gitignore" exists.

+ Pass: Check that file "point2.cc" exists.

+ Pass: Check that file "point2.h" exists.

+ Pass: Check that file "point2_unittest.cc" exists.


#### .gitignore set up properly

+ Pass: Check that file/directory "cluster" does not exist.

+ Pass: Check that file/directory "point2_unittest" does not exist.

+ Pass: Check that no files with extension ".o" exist in directory "."

+ Pass: Check that no files with extension ".out" exist in directory "."


#### Test that code compiles and creates the exectuable

+ Fail: Check that make compiles.

    Make compile fails with errors:.
<pre>g++ -c -Wall main.cc -o main.o
In file included from main.cc:13:0:
point2.h:11:2: error: expected ; after class definition
 }
  ^
  ;
main.cc: In function void DisplayQuadrantCount(Point2*):
main.cc:104:29: error: no matching function for call to Point2::Quadrant()
     if (cluster[i].Quadrant() == 0)
                             ^
In file included from main.cc:13:0:
point2.h:9:9: note: candidate: int Point2::Quadrant(Point2)
     int Quadrant(Point2);
         ^~~~~~~~
point2.h:9:9: note:   candidate expects 1 argument, 0 provided
main.cc:107:36: error: no matching function for call to Point2::Quadrant()
     quad_count[cluster[i].Quadrant()-1]++;
                                    ^
In file included from main.cc:13:0:
point2.h:9:9: note: candidate: int Point2::Quadrant(Point2)
     int Quadrant(Point2);
         ^~~~~~~~
point2.h:9:9: note:   candidate expects 1 argument, 0 provided
Makefile:10: recipe for target 'main.o' failed
make: *** [main.o] Error 1
</pre>



+ Skip: Check that file "cluster" exists.

  This test was not run because of an earlier failing test.

+ Skip: Check that make compiles for Makefile:Makefile.test.

  This test was not run because of an earlier failing test.

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

