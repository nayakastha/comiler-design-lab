// Write a program for automatic design of predictive parsers.
// Consider the following sample grammar:
//     E → TE' 
//     E'→ +TE'|epsilon
//     T → FT' 
//     T'→ ∗FT'|epsilon
//     F → (E)|id
// List of errors
// 1. Operand missing for binary +.
// 2. Operand missing for binary *.
// 4. Left parenthesis missing in expression.
// 3. Right parenthesis missing in expression.
// 5. Operator missing between two identifiers.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


