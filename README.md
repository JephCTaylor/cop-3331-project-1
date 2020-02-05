# cop-3331-project-1

REQUIREMENTS

Write a program to simulate a uniform (meaning every number is equally likely to appear as the next) integer random number.  Your program will be a console application which will simulate a 6-faced die. You will “throw” your simulated die N times. The number N should be obtained by prompting the user on “How many rolls?”

Also, since you will be using rand() provide a prompt requesting that the user provide a seed number. The prompt can be as simple as "Please enter a seed:"

Then use the seed provided by the user to seed the random number generator. This will also help you test your program.

We will use 6000 times as an example.

Show the frequency distribution of your numbers when 6,000 tosses are made and the random number is instantiated to generate numbers between 1 and 6 (inclusive).  In other words, show how many times the numbers 1,2,3,….and 6 have appeared.

The output displayed on the screen should look something like this:

 

1  ----- 900

2  ----- 950

    Up to

6  ---- 1011

Meaning that the number one appeared 900 times (your mileage may vary), and so on.

 

The output should also have a section displaying a histogram.

The histogram should look something like this:

1 xxxxxxxxxxxxxx

2 xxxxxxxxxxxxxx

.

.

.

6 xxxxxxxxxxxxxx

 

Where the ‘x’ represent some number of occurrence of a particular face. Since you are likely to get 100’s of occurrences of a face you will not be able to use one x for one occurrence. Therefore you will have to scale your display so that ‘x’ represents some number of occurrences.

You might want to find the number with the maximum occurrence and represent that maximum occurrence with 60 “x”’s.

Make sure that your x’s line up and start on the same column.

 

Then display the histogram obtained when you roll 2 dice and add up the numbers that come up (2 – 12). As in the first part, you will roll the dice N times.

Create 2 outputs as above. 1 output to display the counts for each sum and one output to display the x’s for each sum

 

 

Guidelines.

Use plenty of comments to help others understand your code. Program without comments will incur a 10% penalty.

 

You must use the vector<> type to hold the histogram counts. If you do not use the vector<> you will incur a 20% penalty

 

Do not use a switch or if statement to update the counts in the histogram!

Using a switch or if statement in the updating method of your histogram will result in a 20% penalty.

 

Your code must compile. If your code doesn’t compile you will automatically receive a grade of 0.

 

Your executable must run. If not you will automatically receive a grade of 0.

 

If your code doesn’t display the histogram and counts appropriately you will suffer a penalty of at least 50% depending on the cause of the error.

 

You will submit your project through canvas. You will “Clean” the project and then zip your project and then submit the zipped file.

The project is presented before we covered all aspects of it. If  there is something you do not quite understand, please make sure you ask for clarifications in class.
