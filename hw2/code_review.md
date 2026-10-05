## Code Review HW1
For: Mavis  
By: Rey

Files:  
`helloworld2.cpp`  
`arraymin2.cpp`   
`arraymax2.cpp`  
`arraysum2.cpp`  
`stringupper2.cpp`  
`vowelcount2.cpp`  
`piapprox2.cpp`  
`2dstencils2.cpp`  

General Comments:
Lots of my comments accross these files are repetitive. Overall, you do a lot of harcoding (of size/contents of inputs, and of number of threads), which makes your code difficult to reuse or scale. You also have many identical functions, If you find yourself copy-pasting the same code a lot of times and changing only indices/minor calcultaions, maybe think about how you can asbtract into one function. 

1. `helloworld2.cpp`

When I run the code I get the following:

```
Hello from thread 4Hello from thread !
Hello from thread 2!
Hello from thread Hello from thread 3!
Hello from thread 5!
Hello from thread 1!
Hello from thread 7!
6!
8!
Hello from thread 9!
Hello from thread 10!
```

The threads do not finish in order, and thus the result is not correctly formated this would be fixed by using a mutex. You could replace

```
 cout << "Hello from thread " << num << "!\n";
```

with

```
  mtx.lock();
  cout << "Hello from thread " << num << "!\n";
  mtx.unlock();
```
Other than that the code looks good!

2. `arraymin2.cpp`

The code correctly identifies the minimum element in the array.

The array used in this code is hardcoded with only 10 elements, I would suggest randomly generating a much larger array (maybe a few million elements).

The code also only allows for 2 threads, and splits the array in half based on an array with 10 elements. The code would be more reusable if the number of threads could be changed, and the array was divided into scetions based on how many threads there are. You actually do this in `helloworld2.cpp`, so you could reuse that code! 

I don't think you need both `checksome()` and `checkmore()` as they essentially do the same thing! Abstraction might be helpful here -> why don't you have on function to find the min that either takes indices to check as inputs, or figures out which indices to check based on the given array, thread number, and number of threads.

Overall: your code does work but it is not very scalable or reusable as it only works on a harcoded array of 10 elements with 2 threads - I would love to see this code work with any number of threads, on an array of any size!

3. `arraymax2.cpp`

Program is almost identical to `arraymin2.cpp, see above comments.

4. `arraysum2.cpp`

This is an improvement on the previous implementations of min/max! I like that your array is randomly generated and much larger and you don't hardcode indices. I still have the same comments as above on only using 2 threads and the repetitive functions.

5. `stringupper2.cpp`  

The program correctly converts the string "Happy new year!" to upper case. A fiture iteration of the might allow the user to enter a string to be converted.

You overwrite your original myString variable, which isn't bezt practice, you might consider returning a seperate variable so the original is not overwritten.

Similar comments as all the other problems - you don't need both somecaps() and morecaps(), the do the same thing! Maybe try to figure out how these can be combined into one function, especially since this approach does not really work if you have more than two threads!

6. `vowelcount2.cpp`  

Program correctly counts the number of vowels! Essentially the same as `stringupper2.cpp`, see above comments.

7. `piapprox2.cpp` 

Same comment about repetitive functions, you don't need four almost identical function, you only need 1. 

The code does not allow for multiple iterations as specified in the homework. 

Other than that good job, your math seems sound!

8. `2dstencils2.cpp`

Similar comments as all the others: repettitive functions, hardcoded indices. Try to abstract these things into variables and inputs.

Your chosen array has each cell already being twice the sum of it's vertical or horizontal neighbors so no change occurs once this program runs.

The code only alters columns 1-3, and rows 1-3 ignoring the first row and column of the given array, and any row/col past 3. If you plan to ignore the edges, maybe pad with zeroes? Also any array larger than this will not work.

Might be better to section the array into areas, or, as discussed in class, launch as many threads as there are cells and compute all the new values at once.
