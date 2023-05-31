# push_swap
My implementation of Push Swap.
It initialises a linked list with the contents of argv and sorts the stack in as fewer operations as possible. 
It does this by performing operations between two stacks A and B. 

Note that many conventional sorting algorithms cant be applied as we have to obey hard rules, similar to how 
the childhood toy works.

AVAILABLE OPERATIONS:
PA (Put A): puts the first/top element of stack_B onto the top of stack_A
PB (Put B): puts the first/top element of stack_A onto the top of stack_B
RA (Rotate A): puts the first node of the stack onto the bottom/end of the stack. Adjusts all node indices accordingly.
RB (Rotate B): puts the first node of the stack onto the bottom/end of the stack. Adjusts all node indices accordingly.
RR (Rotate A and B): Calls RA and RB. 
RRA (Reverse Rotate A): puts the last node of the stack onto the top/start of the stack. Adjusts all node indices accordingly.
RRB (Reverse Rotate B): puts the last node of the stack onto the top/start of the stack. Adjusts all node indices accordingly.
RRR (Reverse Rotate A and B): Calls RRA and RRB. 
SA (Swap A): Swaps the first two elements of stack A.
SB (Swap B): Swaps the first two elements of stack B.
SS (Swap A and B): Swaps the first two elements of stack A and stack B.

OVERALL IMPLEMENTATION GUIDE:
1.Starts by checking validity and populating inputs from argv and inserting them into our linked list stack_A.
2.pushes all nodes of Stack_A into Stack_B but 3.
3.Perform a short sort on our 3 elements left within stack_A.
4.Calculate the current target index within stack_A for each element of stack_B. 
5.Calculate the cost to get a given element within stack_B into its target index in stack_A.
6.Retrieve the node with the cheapest cost, and perform the cheapest move.
7.Repeate steps 4-6 until stack_B is empty.
8.If stack_A is rotated out of order, rotate it into the correct order.
