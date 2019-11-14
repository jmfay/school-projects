### Feedback for Iter 02

Run on November 13, 21:06:50 PM.


### Basic Tests on Devel

+ Pass: Checkout devel branch



<hr>

This feedback is being batched and will run every few hours. Note that these feedback tests are a *work in progress* and will possibly be updated to contain more tests as they are developed. Check back periodically for more feedback as well as for your updated results.

<hr>


#### Necessary Files and Structure

+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Check that directory "project/tests" exists.

+ Pass: Check that directory "project/docs" exists.

+ Pass: Change into directory "project/src".

+ Fail: Compiling capture_transit_sim target of the src/ makefile...

<pre>make: *** No rule to make target 'capture_transit_sim'.  Stop.
</pre>



+ Skip: Check that file "../build/bin/capture_transit_sim" exists.

  This test was not run because of an earlier failing test.


#### Style Checking All src/ Files

+ Pass: Check that file "mainpage.h" exists.

+ Pass: Ignoring mainpage.h



+ Pass: Grading style compliancy errors Found: 0 errors, Expected 0.

+ Pass: Restoring mainpage.h




### Git Usage

+ Pass: Run git ls-remote gather all branches in repo

		5d34adecc975db2484563acddd0dbeebbb4aeb3c	refs/heads/devel

		15f185ed80cae30ab560c24221a1286282cb5e0f	refs/heads/fix/01-compilation-errors

		e34808ddc49f201ddab6db635f2951f7155d5cde	refs/heads/fix/02-passenger-enhancement

		b9fdfd3fc8f3202e1a7de251582c3463400f5a56	refs/heads/fix/03-priority1-stop-enhancement

		7058055e55cff5646478a558fce16346f2bb1348	refs/heads/fix/04-output-refactoring

		3b86f7748466731a08d030207da8b6159f8ca025	refs/heads/fix/05-bus-enhancement

		d49927415e0d7738cd775b33fca7287b3f44ae8b	refs/heads/fix/06-bus-route-enhancement

		389043e85550ea6d492bd7540b16a8e90ab1757f	refs/heads/fix/07-google-styling

		ca8b11343d395df0696f3d8f39dd1d912c0312d5	refs/heads/fix/08-doxygen-big4-documentation

		047caddf3fce0914e61ce7aa6379160392bc6d05	refs/heads/master



<hr>

Gathered all branches in this repo. Note that passing this test does *not* mean that a sufficient amount of branches were found.

<hr>

