/**********************************************************************
 *  readme 
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Michael Zogin

Hours to complete assignment: ~8

/**********************************************************************
 * Explain which approach you decided to use when implementing
 * (either recursive with memoization, recursive without memoization,
 * dynamic programming or Hirschberg�s algorithm). Also describe why
 * you chose this approach and what its pros and cons are.
 **********************************************************************/
I decided to choose the dynamic programming approach involving a vector 
of columns, each containing a row vector. I decided to choose this option
because it was the most straight forward and easy to follow approach for 
me, even though having one big block of memory would have been a more 
efficient solution.

/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input: 
	x: atattat
	y: tattata
Expected output:
	atattat-
	-tattata
What happened:
	The code correctly inserted a gap at the end of the x string and
the beginning of the y string for a total edit distance of 4.
The execution time was .001198 seconds.

/**********************************************************************
 * Look at your computer�s specs in the settings. 
 * How much RAM does your computer have and explain what this means? 
 **********************************************************************/
My computer has 16GB of RAM, which allows me to have access to more than 
enough memory when Im running my programs on my virtual machine.

/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
a = 4
b = 2
largest N = 

4 * N^2 would be my estimations since if M==N then it will be an N x N 
matrix, with each cell holding an int of size 4 bytes. So, if we divide
1B (1,000,000,000) by 4 we get 250,000,000 (NxN) and then take the 
square root to get approximately 15,811 as the largest N

/**********************************************************************
 * Run valgrind if you can and attach the output file to your submission. 
 * If you cannot run it, explain why, and list all errors you�re seeing. 
 * If you can run it successfully, does the memory usage nearly match that 
 * found in the question above? 
 * Explain why or why not. 
/**********************************************************************
Yes, I was able to run valgrind successfully. No, it seems that my
memory usage i greater than I had calculated.

/********************************************************************* 
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt		118		0.081533	47.92
ecoli5000.txt		160		0.244548	191.1
ecoli7000.txt		194		0.444836	374.3
ecoli10000.txt		223		0.891332	763.6
ecoli20000.txt
ecoli28284.txt

/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730



/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 
b = 
largest N = 

seconds in a day = 86,400
I am unsure as to how to come up with a polynomial function for this,
but I can see that the running times for my program seem to roughly double 
from ecoli5000 to ecoli7000 and ecoli10000.

/
**********************************************************************
 *  Did you use the lambda expression in your assignment? If yes, where 
 * (describe a method or provide a lines numbers)
 **********************************************************************/
Yes, I added a lambda expression to my main.cpp file on line 11 and used 
it as a function to return the run time at the end.

********************************************************************* 
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/
Mostly the slides provided by professor.
Also sfml-dev.org

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
Mostly just problems with my virtualbox memory


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
