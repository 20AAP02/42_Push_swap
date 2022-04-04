<h1 align="center"> Push_swap | 42 School Project </h1>
<h4>This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves.</h4>
<p>To make this happen, I had to manipulate various sorting algorithms and choose the most appropriate solution for optimized data sorting</p>
<p>This project was a highly straightforward algorithm project: data must be sorted.<br>
I had at my disposal a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks. The goal was to write a program in C called 
push_swap which calculates and displays on the standard output the smallest program, made of Push swap language instructions, that sorts the integers 
received as arguments.</p>

-----

<h4>What I learned with this project?</h4>
<p>- Diferent sorting algorithms</p>
<p>- Algorithm implementation</p>

-----

<h4>Subject</h4>
https://github.com/20AAP02/push_swap/blob/main/en.subject.pdf

-----

<h4>Grade : 100%</h4>
<h6>Mandatory : 100/100</h6>
<h6>Bonus : 0/25</h6>

<h4>Guide</h4>

<p>We are given two stacks called Stack A and Stack B. Stack A is given a random list of unorganized numbers. We must take the random list of 
numbers in Stack A and sort them so that Stack A is organized from smallest to largest. There are only a few moves we’re allowed to used to 
manipulate the stacks. The main goal of this project is to organize Stack A in as few moves as possible.</p>

<b>The moves that we can use are the following:</b>  
- sa (swap a): Swap the first 2 elements at the top of stack a.<br> 
- sb (swap b): Swap the first 2 elements at the top of stack b.<br> 
- ss : sa and sb at the same time.<br> 
- pa (push a): Take the first element at the top of b and put it at the top of a.<br> 
- pb (push b): Take the first element at the top of a and put it at the top of b.<br> 
- ra (rotate a): Shift up all elements of stack a by 1.<br> 
- rb (rotate b): Shift up all elements of stack b by 1.<br> 
- rr : ra and rb at the same time.<br> 
- rra (reverse rotate a): Shift down all elements of stack a by 1.<br> 
- rrb (reverse rotate b): Shift down all elements of stack b by 1.<br> 
- rrr : rra and rrb at the same time.<br><br>

<b>Algorithm Implementation</b>
<p>So now that we have the moves we are allowed to use, how should we use them? The algorithms I used depends on how many random numbers are getting applied to Stack A. There are 4 main test cases that I want to cover. The cases are 3, 5, 100, and 500. Each case requires me to handle them differently, so I’ll break down how I optimized each case one at a time.</p>
<p>This ocurres because the evaluation is made acording to those the followinf checkpoints.<br>To have the highest score, my algorithm must make<br>
&#9;less then 3 moves when the stack has 3 integers;<br>
&#9;less then 8 moves, when the stack has 5 integers;<br>
&#9;less then 700 moves when the stack has 100 integers;<br>
&#9;less then 5500 moves when the stack has 500 integers;</p><br>
<i>- Stack of 3 integers</i>
<p>For a this stack size i just harcoded the most optimized moves. So depending on the position of the biggest, smallest and medium number; I will
proceed to make certain moves (in this case the max number of moves is 2)</p>
<i>- Stack of 5 integers</i>
<p>When stack A starts with 4 integers, or as long as the size is less than 60 I will apply the same algorithm. Which goes like this</p>

