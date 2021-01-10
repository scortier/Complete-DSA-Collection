/*
Highest: Exponentiation (^)
Next highest: Multiplication (*) and division (/)
Lowest: Addition (+) and Subtraction (-)

For example –

Infix notation: (A-B)*[C/(D+E)+F]
Post-fix notation: AB- CDE +/F +*


Here, we first perform the arithmetic inside the parentheses (A-B) and (D+E). The division of C/(D+E) must done prior to the addition with F. After that multiply the two terms inside the parentheses and bracket.

Now we need to calculate the value of these arithmetic operations by using stack.

The procedure for getting the result is:

Convert the expression in Reverse Polish notation( post-fix notation).
Push the operands into the stack in the order they are appear.
When any operator encounter then pop two topmost operands for executing the operation.
After execution push the result obtained into the stack.
After the complete execution of expression the final result remains on the top of the stack


For example –

Infix notation: (2+4) * (4+6)
Post-fix notation: 2 4 + 4 6 + *
Result: 60

https://www.geeksforgeeks.org/arithmetic-expression-evalution/
*/