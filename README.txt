name: Boxuan Guan
UNI: bg2469


Description

answer for part1
part1
(a)
3.9 when interrupt occur, system save context, context info is stored in PCB of the processs. Mainly context switch consists of state save and state restore. So the kernel will save the context of the old process and load the saved context of the new process scheduled to run.

3.11 
when there is a zombie process to clean up, what you should do is to kill its parents, and init process will adopt it, at the same time init process will clean it automatically by clean its entry on the process table.


(b)
1. What is typeof? Is it C language keyword, function, or macro? What does it do?
Typeof is a keyword
t takes one argument and returns its type
2. What is offsetof? Is it keyword, function, or macro? What does it do?
It’s a macro, return a byte offset of a member called Member  to the beginning of the structure Type

3.	What does the container_of() macro do?
It subtracts the offset of the structure’s member from its address yielding the address of the container structure. That’s it!

4. Yes I can identify it, the macro is defined and undefined) by using keyword “#define” at the beginning and “#undefined”. 


5.	The macros has two lines. Is the 1st line (the declaration of __mptr) really necessary? Is it possible to rewrite the macro without it? What is the purpose of that 1st line?

It is necessary and it is impossible to rewrite the macro without it since you have to get a copy of ptr, which is __mptr, otherwise you would affect ptr while you are doing the subtraction in the second line;


for part2 to part4 I'v made some comments in the code so you could understand what I'm coding.
