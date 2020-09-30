### Feedback for Lab 10

Run on October 19, 07:39:15 AM.


### Necessary Files and Structure

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab10_advanced_git" exists.


### Git Usage

+ Pass: Run git ls-remote to check for existence of specific branch- Branch devel found

+ Pass: Checkout devel branch.



+ Pass: Run git ls-remote gather all branches in repo

		233fd54b18f9bc5fe7f4d9690fc4df9523ef110f	refs/heads/devel

		15f185ed80cae30ab560c24221a1286282cb5e0f	refs/heads/fix/01-compilation-errors

		e34808ddc49f201ddab6db635f2951f7155d5cde	refs/heads/fix/02-passenger-enhancement

		f8f66b5f861372830441cf6d458a01b1af419846	refs/heads/master



+ Pass: Checking for the correct number of branches

Sufficient branches found (found=2, required=2):

fix/01-compilation-errors

fix/02-passenger-enhancement


#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history

		[Joey Fay] 2019-10-18 (HEAD -> devel, origin/devel) Merge branch 'fix/02-passenger-enhancement' into devel 

		[Joey Fay] 2019-10-18 (origin/fix/02-passenger-enhancement, fix/02-passenger-enhancement) fix(passenger.cc): fix #2 <replaced with passenger.cc from lab09> - Took fleshed out passenger.cc from lab09 and placed in src folder
- added functionality to Update(), GetOnBus(), GetTotalWait(), and IsOnBus()
- project now not only compiles, but has functionality of passenger.cc


		[Joey Fay] 2019-10-18 fix(local_simulator.cc): fix #1 <fixed file bugs to allow make compilation> - make file for project reporting errors in local_simulator.cc
- changed pass_.Update and pass_.Report() to use pointer operator (->)


		[Joey Fay] 2019-10-18 (origin/fix/01-compilation-errors, fix/01-compilation-errors) Merge branch 'master' of https://github.umn.edu/umn-csci-3081-f19/repo-fayxx092 

		[Joey Fay] 2019-10-18 lab 09: Adding deliverables 





		[Joey Fay] 2019-10-18 Fixed merge conflict in lab8 



































+ Pass: Check git commit history
Sufficient commits (found=11,required=4)


### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 2)

[OPEN issue #2] :  Passenger Class Enhancement [enhancement] @fayxx092

[OPEN issue #1] :  Iteration 1 Simulator Compilation Bug [bug]





+ Pass: Run ghi for total number of closed issues in Github repo (Found: 0)

+ Pass: Run ghi for total number of issues in Github repo (Found: 2, Expected: 2) 

 [OPEN issue #2] :  Passenger Class Enhancement [enhancement] @fayxx092

[OPEN issue #1] :  Iteration 1 Simulator Compilation Bug [bug]

[CLOSED issue #] : 

 




### Test that code on  devel compiles

+ Pass: Checkout devel branch.



+ Pass: Check that directory "project" exists.

+ Pass: Change into directory "project".

+ Pass: Check that file "makefile" exists.

+ Pass: Check that make compiles.



