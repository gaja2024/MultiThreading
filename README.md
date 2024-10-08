This project contains Matrix Multiplication & Merge Sort.
Matrix Multiplication : Here there is an input file called MatrixSize.txt Example is shown below
13
3 4 5
8 8 8
12 9 12
16 16 16
24 24 24
30 30 30
48 48 48
80 80 80
100 100 100
240 240 240
400 400 400
800 800 800
1600 1600 1600

First row is size is number of testcases (above example  it is 13)
Each row (in next 13 rows)contains matrix size M,N,P (means 1st matrix MxN & 2nd Matrix NxP)
Program will generate matrix elements of size MxN & NxP and then multiplies those matrices. 
Program also prints the input matrix, and result matrix in both SingleThreaded & Multithreaded.
Time comparison is stored in PerformanceData class.
PerformanceAnalyser class prints the comparison data in table format.

Similarly there is DataSize.txt in MergeSort , first row of which is number of test cases  and subsequent rows in array size to be sorted.
Time comparison is stored in PerformanceData class.
PerformanceAnalyser class (there is not much analysis here it only prints the data) prints the comparison data in table format.
