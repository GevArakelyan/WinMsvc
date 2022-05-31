## https://github.com/catchorg/Catch2


Run specific test
thisTest
"This Test"
Run Group of tests
Customer* | all tests starting with Customer


Run all tests except
Exclude:otherTest
~otherTest
~*other*
a* ~ab* abc

List all test names.
tests.exe --list-tests
//---
t.exe "[a]"
t.exe ~[a]
t.exe "[a][b]"
t.exe "[a],[b]" | means run all tests with tag a or b

t.exe -# [#Sample2] | will run only tests from sample2 file.

t.exe --list-tags | to see all tags