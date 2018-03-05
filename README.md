### Grading multiple-answer test
 This C++ program will
1. interactively prompt for and read the name of the first input file (with key and student data) and use a filestream variable to represent the file
2. read the data from the input file and store the student information (ID#s, 
names, test answers) into an array of structs, counting the students as the
data is read
3. reformat the names into a more conventional form
4. use the key to grade the exams and store each student's score in the array
5. interactively prompt for and read the name of an output file
6. write the following to the specified output file (separate each section with
a blank line to improve readability)
	+. The author's name, section #, assignment #
b. A report that displays the names of the students (alphabetically by last
name) along with their ID#s and test scores (see formatting specifications
and samples below)
c. A report that displays the class standings with ID#s and test scores (in
descending order)(see formatting specifications and samples below)
+ the standings report should include
	- the number of students who took the test with a label (maximum
	class size is 35)
	- the class average (2 digits to right of decimal)
	- the median (middle value or average of middle values if there are 
	an even number of students, 2 digits to right of decimal)
7. interactively prompt for and read the name of the second input file
	+. write an appropriate message to indicate the start of the start of the 
second input file processing
	+. write the test key to the output file (with label)
	+. read each integer, if it matches an ID# in the student array, write the
student's name, test score, and test answers (you may reformat the test
answers if you wrish) with labels to the output file
	+. if the ineger does not match an ID# in the array, write an error 
message that includes the invalid ID# to the output file
	+. if the integer does not match an ID# in the array, write an error 
message that includes the invalid ID# to the output file

```
	Input:	1st input file:
				a. 1st line: The answer key consists of 20 lower case letters that
				represent the correct answers to the exam. There will be no blank spaces 
				between the letters.
				b. 2nd line - last line: Each line will start with an ID# (int), 
				followed by the first and last names of a student (names will be 
				separated by at least one blank space). The names may be in a mixture
				of upper and lower case letters. The names will be followed by at least
				1 blank space and then that student's reponses to the test questions will
				be provided. There will not be any blank spaces between responses, but
				they may be in a mixture of upper and lower case letters. An upper case
				letter should be considered correct if it matches the lower case 
				equivalent in the key.

	Output: an output file with students' name, ID# and scores
```