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

<p>The moves that we can use are the following:</p>  
-sa (swap a): Swap the first 2 elements at the top of stack a.  
-sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.
