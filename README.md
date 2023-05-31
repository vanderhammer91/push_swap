<p><strong>Push_Swap</strong><br>
 <em>My implementation of Push Swap:<br>
initialises a linked list with the contents of argv and sorts the stack in as fewer operations as possible. <br>
  It does this by performing operations between two stacks A and B.</em><br></p>

<p><strong>Note:</strong> that many conventional sorting algorithms cant be applied as we have to obey hard rules, similar to how <br>
the childhood toy works.</p>

<p><strong>AVAILABLE OPERATIONS:</strong><br>
 <strong>PA (Put A): </strong>puts the first/top element of stack_B onto the top of stack_A <br>
 <strong>PB (Put B): </strong>puts the first/top element of stack_A onto the top of stack_B <br><br>
 <strong>RA (Rotate A): </strong>puts the first node of the stack onto the bottom/end of the stack. Adjusts all node indices accordingly. <br>
 <strong>RB (Rotate B): </strong>puts the first node of the stack onto the bottom/end of the stack. Adjusts all node indices accordingly. <br>
<strong>RR (Rotate A and B): </strong>Calls RA and RB. <br><br>
 <strong>RRA (Reverse Rotate A): </strong>puts the last node of the stack onto the top/start of the stack. Adjusts all node indices accordingly. <br>
<strong>RRB (Reverse Rotate B): </strong>puts the last node of the stack onto the top/start of the stack. Adjusts all node indices accordingly. <br>
 <strong>RRR (Reverse Rotate A and B):</strong> Calls RRA and RRB. <br><br>
 <strong>SA (Swap A):</strong> Swaps the first two elements of stack A. <br>
 <strong>SB (Swap B):</strong> Swaps the first two elements of stack B. <br>
<strong>SS (Swap A and B): Swaps the first two elements of stack A and stack B.<br>
</p>

<p><strong>OVERALL IMPLEMENTATION GUIDE:</strong><br>
1.Starts by checking validity and populating inputs from argv and inserting them into our linked list stack_A. <br>
2.pushes all nodes of Stack_A into Stack_B but 3. <br>
3.Perform a short sort on our 3 elements left within stack_A. <br>
4.Calculate the current target index within stack_A for each element of stack_B. <br>
5.Calculate the cost to get a given element within stack_B into its target index in stack_A. <br>
6.Retrieve the node with the cheapest cost, and perform the cheapest move. <br>
7.Repeate steps 4-6 until stack_B is empty. <br>
8.If stack_A is rotated out of order, rotate it into the correct order. <br></p>
