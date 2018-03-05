//***************************************************************************************
// An Vo Lec 1003 Lab 1006 Assginment 04
// 
// This C++ program will
//		1. interactively prompt for and read the name of the first input file (with key
//		   and student data) and use a filestream variable to represent the file
//		2. read the data from the input file and store the student information (ID#s, 
//		   names, test answers) into an array of structs, counting the students as the
//		   data is read
//		3. reformat the names into a more conventional form
//		4. use the key to grade the exams and store each student's score in the array
//		5. interactively prompt for and read the name of an output file
//		6. write the following to the specified output file (separate each section with
//		   a blank line to improve readability)
//			a. The author's name, section #, assignment #
//			b. A report that displays the names of the students (alphabetically by last
//			name) along with their ID#s and test scores (see formatting specifications
//			and samples below)
//			c. A report that displays the class standings with ID#s and test scores (in
//			descending order)(see formatting specifications and samples below)
//				+ the standings report should include
//					- the number of students who took the test with a label (maximum
//					class size is 35)
//					- the class average (2 digits to right of decimal)
//					- the median (middle value or average of middle values if there are 
//					an even number of students, 2 digits to right of decimal)
//		7. interactively prompt for and read the name of the second input file
//			a. write an appropriate message to indicate the start of the start of the 
//			second input file processing
//			b. write the test key to the output file (with label)
//			c. read each integer, if it matches an ID# in the student array, write the
//			student's name, test score, and test answers (you may reformat the test
//			answers if you wrish) with labels to the output file
//			d. if the ineger does not match an ID# in the array, write an error 
//			message that includes the invalid ID# to the output file
//			e. if the integer does not match an ID# in the array, write an error 
//			message that includes the invalid ID# to the output file
//
//	Input:	1st input file:
//				a. 1st line: The answer key consists of 20 lower case letters that
//				represent the correct answers to the exam. There will be no blank spaces 
//				between the letters.
//				b. 2nd line - last line: Each line will start with an ID# (int), 
//				followed by the first and last names of a student (names will be 
//				separated by at least one blank space). The names may be in a mixture
//				of upper and lower case letters. The names will be followed by at least
//				1 blank space and then that student's reponses to the test questions will
//				be provided. There will not be any blank spaces between responses, but
//				they may be in a mixture of upper and lower case letters. An upper case
//				letter should be considered correct if it matches the lower case 
//				equivalent in the key.
//
//			2nd input file contains sevel integers that are supposed to be the ID#s
//			for some of students in the class.
//	
//	Out
//***************************************************************************************

/* 
	Requirements
	1. The program MUST make use of functions (at least 5 meaningful functions in addition
	to main).
	2. The program MUST CREATE A STRUCT DATA TYPE TO STORE STUDENT DATA AND THEN DECLARE
	AN ARRAY OF STRUCTS
	3. The program MUST PASS PARAMETERS to communicate values. No global variables are
	allowed.
	4. No goto statements may be used
	5. Program must make use of filestream variables to represent the input and output
	files. Each input file may only be read one time.
	6. When prompting for file names, the required order is: 1st input file, output file,
	2nd input file.
	7. Failure to adhere to the 6 previous requirements will result in up to a 60% deduction
	of assignment's point value.
	8. Average and median (if even number of students) should be displayed with 2 digits 
	to right of decimal.
	9. For first report, right justify ID#s and test scores. Left justify names. Display
	names: last,first.
	10. For second report (class standings), right justify ID#s and scores.
	11. Program must include preprocessor directives for all header files used
	12. Program must use a static array (do not use a variable for the size
	of the array)
	13. Write your own code
*/

	// header file
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

	//constants declaration
const int CLASS_SIZE = 35;
struct studenttype
{
	int id;						//student's ID
	string firstName;			//student's first name
	string lastName;			//student's last name
	string answer;				//student's answer
	int score;					//student's score
};	
	//function prototypes
void get_student_info(studenttype [], string&, int&);
void fix_answer_key(string&);
void fix_name(string&);
void print_result(studenttype [], string, int);
void grading(string, string, int&);
void bubblesort_name(studenttype[], int);
void bubblesort_score(studenttype[], int);
void search_file_processing(ofstream&, studenttype[], string, int);
int search(studenttype[], int, int);

int main()
{
	studenttype student[CLASS_SIZE];				//list of student
	int n;											//number of student
	string correctAnswer;							//variable to store the correct answer keys
	get_student_info(student, correctAnswer, n);	
	print_result(student, correctAnswer, n);

	return 0;
}

//******************************************************************************************
void fix_answer_key(string& word)//convert letters to lowercase
// Given string word, fix_answer_key will convert all of letters of the
// string word to lowercase letters
{
	for (int i=0; i < word.length(); i++)
		word[i] = tolower(word[i]);
}

void fix_name(string& word)//fix name
// Given string word, fix name will convert the first letter of
// the input files into a capitalized letter, then convert the rest of the
// input to lowercase letters
{
	word[0] = toupper(word[0]);
	for (int i=1; i < word.length(); i++)
		word[i] = tolower(word[i]);
}

//********************************************************************************************
void get_student_info(studenttype data[], string& correctAnswer, int& n)
// Given studenttype data[] and integer n, get_student_info will
//		1. interactively prompt for and read the name of the first input file (with key
//		   and student data) and use a filestream variable to represent the file
{	
	ifstream infile;														//input file stream variable
	string filename;														//variable to hold the input file name
	cout << "Please enter name of the first input file:" << endl;
	cin >> filename;

	infile.open(filename.c_str());
	n = 0;
	infile >> correctAnswer;
	fix_answer_key(correctAnswer);

//		2. read the data from the input file and store the student information (ID#s, 
//		   names, test answers) into an array of structs, counting the students as the
//		   data is read

	infile >> data[n].id;
	while (infile)
	{
		infile >> data[n].firstName >> data[n].lastName;

//		3. reformat the names into a more conventional form
		fix_name(data[n].lastName);
		fix_name(data[n].firstName);
		infile >> data[n].answer;
		fix_answer_key(data[n].answer);
		data[n].score = 0;

//		4. use the key to grade the exams and store each student's score in the array
		grading(correctAnswer, data[n].answer, data[n].score);
		n++;
		infile >> data[n].id;
	}

	infile.close();
}

void grading (string ansKey, string answer, int& score)
// Given the string anskey, which stores the answer keys, grading will
// compare a student's answers to compute the score that the student
// earns
{
	for (int i =0; i < ansKey.length(); i++)
	{
		if (answer[i] == ansKey[i])
		{
			score = score + 5;
		}
	}
}	

//************************************************************************************************************

void print_result(studenttype data[], string correctAnswer, int n)
// Given the struct studenttype data, string correctAnswer and integer n,
// print_result will prompt for and read the name of an output file,
// and write a specific structure for the output file
{
	ofstream outfile;											//output file stream variables
	string filename;											//variable to hold the output file name
	int totalScore = 0;
//		5. interactively prompt for and read the name of an output file
	cout << "Please enter the name of the output file:" << endl;
	cin >> filename;

	outfile.open(filename.c_str());
//		6. write the following to the specified output file (separate each section with
//		   a blank line to improve readability)
//			a. The author's name, section #, assignment #
	outfile << "An T. Vo\tLecture section 1003\tAssignment #5"
			<< endl
			<< endl;

	outfile << left
			<< setw(30)
			<< "NAME"
			<< setw(6)
			<< "ID#"
			<< "SCORE"
			<< endl;

//			b. A report that displays the names of the students (alphabetically by last
//			name) along with their ID#s and test scores (see formatting specifications
//			and samples below)
	bubblesort_name(data, n);
	for (int i = 0; i < n ; i++)
	{
		outfile << left 
				<< setw(30)
				<< data[i].lastName + "," + data[i].firstName
				<< right
				<< setw(3)
				<< data[i].id
				<< setw(8)
				<< data[i].score
				<< endl;
	}
	outfile << endl;

//			c. A report that displays the class standings with ID#s and test scores (in
//			descending order)(see formatting specifications and samples below)
//				+ the standings report should include
//					- the number of students who took the test with a label (maximum
//					class size is 35)
//					- the class average (2 digits to right of decimal)
//					- the median (middle value or average of middle values if there are 
//					an even number of students, 2 digits to right of decimal)

	bubblesort_score(data, n);
	outfile << "CLASS STANDINGS" << endl;
	outfile << "ID#"
			<< setw(8)
			<< "SCORE"
			<< endl;
	for (int j = 0; j < n; j++)
	{
		outfile << setw(3)
				<< data[j].id
				<< setw(8)
				<< data[j].score
				<< endl;
		totalScore = totalScore + data[j].score;
	}
	outfile << endl;

	outfile << "# of Students: " << n << endl;
	outfile << fixed << showpoint << setprecision(2);
	outfile << "Class Average: " << static_cast<double>(totalScore) / n
			<< endl;
	if (n % 2 != 0)
	{
		outfile << "Median score: " << static_cast<double>(data[n/2+1].score) << endl << endl;
	}
	else
	{
		outfile << "Median score: "
				<< (static_cast<double>(data[n/2-1].score) + data[n/2].score) / 2
				<< endl
				<< endl;
	}

	search_file_processing(outfile, data, correctAnswer, n);

	outfile.close();
}

void bubblesort_name(studenttype data[ ],int count)
// Sort an array of integers into ascending order.
// Parameters: data[]
// data: array of floategers to be sorted
// count: (int) number of values in the array
// Value passed back: sorted data
{
	 studenttype temp; //place holder when values are interchanged
	 for (int i=0; i < count-1; i++)
		 for (int j=0; j < count-(i+1); j++)
			 if (data[j].lastName > data[j+1].lastName)
			 {
				 temp = data[j];
				 data[j] = data[j+1];
				 data[j+1] = temp;
			 }
}

void bubblesort_score(studenttype data[ ],int count)
// Sort an array of integers into ascending order.
// Parameters: data[]
// data: array of floategers to be sorted
// count: (int) number of values in the array
// Value passed back: sorted data
{
	 studenttype temp; //place holder when values are interchanged
	 for (int i=0; i < count-1; i++)
		 for (int j=0; j < count-(i+1); j++)
			 if (data[j].score < data[j+1].score)
			 {
				 temp = data[j];
				 data[j] = data[j+1];
				 data[j+1] = temp;
			 }
}


//***********************************************************************************************

//		7. interactively prompt for and read the name of the second input file
void search_file_processing(ofstream& output, studenttype data[], string correctAnswer, int n)
// Given the the output filestream, struct studenttype data[], string correctAnswer and integer n,
// search_file_processing will write the output file after it finishes the searching process
{
	ifstream infile;										//input file stream variable
	string filename;
	int location, target;

//			a. write an appropriate message to indicate the start of the 
//			second input file processing
	cout << "Please enter the name of the second input file:"
		 << endl;
	cin >> filename;

	infile.open(filename.c_str());

	output << "BEGIN STUDENT SEARCH FILE PROCESSING" 
		   << endl
		   << endl;

//			b. write the test key to the output file (with label)
	output << "Test key: " << correctAnswer
		   << endl;

//			c. read each integer, if it matches an ID# in the student array, write the
//			student's name, test score, and test answers (you may reformat the test
//			answers if you wrish) with labels to the output file
	infile >> target;
	while(infile)
	{
		location = search(data, n, target);

		if (location >= 0)
		{
			output  << endl
					<< "ID#:"
					<< setw(7)
					<< data[location].id
					<< endl;
			output  << "Name: "
					<< data[location].firstName + " " + data[location].lastName
					<< endl;
			output  << "Test score: "
					<< data[location].score
					<< endl;
			output  << "Test responses: "
					<< data[location].answer
					<< endl;
		}
//			d. if the ineger does not match an ID# in the array, write an error 
//			message that includes the invalid ID# to the output file
		else
		{
			output << endl
				   << target << " is not a valid student ID#"
				   << endl;
		}
		infile >> target;
	}

	infile.close();
}

int search(studenttype data[], int n, int target)
// Given the struct studenttype data[] with its integer n, and integer target,
// the function search will return the result if a student's id matches with the target 
// id. If it does not match, the function search will return -1
{
	for (int i = 0; i < n; i++)
		if(data[i].id == target)
			return i;
	return -1;
}
