// Design an LR(0) parser by hand that will check the validity of proposition logic expressions and 
// generate its truth table and report whether the expression is a tautology/fallacy/satisfiabilty.

// Valid Tokens
// 1. A-Z (excluding T and F), a-z (excluding t and f)  are tokens of length 1 represent Boolean variables
//    whole values are either T/t for true or F/f for false.
// 2. T/t and F/f are constants representing true and false respectively.
// 3. Operator /\ stands for 'AND'.
// 4. Operator \/ stands for 'OR'.
// 5. Operator ~ stands for 'NOT'.
// 6. Operator -> stands for 'implication'.
// 7. Operator <-> stands for 'if and only if'.
// 8. Operator ( stands for 'opening parenthesis'.
// 9. Operator ) stands for 'closing parenthesis'.

// Operator Precedence  Associativity

// maximum ()              Left
//         ~               Right
//         <->             Left
//         ->              Left  
//         /\              Left
// minimum \/              Left

// Errors Handled by this system

// 1. Lexical Error occurs when invalid tokens are found. The error and its position in the imput string should 
// be displayed.
// 2. Syntax or Parse Error:
// (i) Incomplete expression.
// (ii) Operator missing when two operands are consecutive.
// (iii) Expression missing when open parenthesis and close parenthesis are consecutive elements in the input 
// string and vice versa.
// (iv) Operand missing for a binary operator.
// (v) Operand missing for an unary operator.
// (vi) Consecutive Binary Operators -> operand missing.
// (vii) Missing of ( for a ).

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    cin >> input;
    bool is_valid = true;
    // Check for lexical error
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] == 'T' || input[i] == 't' || input[i] == 'F' || input[i] == 'f')
        {
            if(i != input.length() - 1)
            {
                cout << "Lexical Error at position " << i << ": " << input[i] << endl;
                is_valid = false;
            }
        }
        else if(input[i] == '(' || input[i] == ')' || input[i] == '~' || input[i] == '<' || input[i] == '>' || input[i] == '&' || input[i] == '|')
        {
            if(i != input.length() - 1)
            {
                cout << "Lexical Error at position " << i << ": " << input[i] << endl;
                is_valid = false;
            }
        }
        else if(input[i] == ' ')
        {
            continue;
        }
        else
        {
            cout << "Lexical Error at position " << i << ": " << input[i] << endl;
            is_valid = false;
        }
    }
    if(!is_valid)
        return 0;
    // Check for syntax error
        int count_open_parenthesis = 0;
        int count_close_parenthesis = 0;


        for(int i = 0; i < input.length(); i++)
        {
            if(input[i] == '(')
            {
                count_open_parenthesis++;
            }
            else if(input[i] == ')')
            {
                count_close_parenthesis++;
            }
        }

        if(count_open_parenthesis != count_close_parenthesis)
        {
            cout << "Syntax Error: Missing of ( for a )" << endl;
            return 0;
        }

                if(count_open_parenthesis == count_close_parenthesis)
        {
            if(count_open_parenthesis == 0)
            {
                if(count_close_parenthesis == 0)
                {
                    cout << "Syntax Error: Incomplete expression" << endl;
                    return 0;
                }
                else
                {
                    cout << "Syntax Error: Missing expression" << endl;
                    return 0;
                }
            }
            else
            {
                if(count_close_parenthesis == 0)
                {
                    cout << "Syntax Error: Missing expression" << endl;
                    return 0;
                }
            }
        }
        else
        {
            cout << "Syntax Error: Missing of ( for a )" << endl;
            return 0;
        }


        for(int i = 0; i < input.length(); i++)
        {
            if(input[i] == '(')
            {
                if(i != 0)
                {
                    if(input[i - 1] == '~' || input[i - 1] == '<' || input[i - 1] == '>' || input[i - 1] == '&' || input[i - 1] == '|')
                    {
                        cout << "Syntax Error: Operator missing when two operands are consecutive" << endl;
                        return 0;
                    }
                }
            }
            else if(input[i] == ')')
            {
                if(i != input.length() - 1)
                {
                    if(input[i + 1] == '(')
                    {
                        cout << "Syntax Error: Expression missing when open parenthesis and close parenthesis are consecutive elements in the input string and vice versa" << endl;
                        return 0;
                    }
                }
            }
            else if(input[i] == '~' || input[i] == '<' || input[i] == '>' || input[i] == '&' || input[i] == '|')
            {
                if(i != input.length() - 1)
                {
                    if(input[i + 1] == '(')
                    {
                        cout << "Syntax Error: Expression missing when open parenthesis and close parenthesis are consecutive elements in the input string and vice versa" << endl;
                        return 0;
                    }
                }
            }
            else if(input[i] == ' ')
            {
                continue;
            }
            else
            {
                cout << "Syntax Error: Invalid token" << endl;
                return 0;
            }
        }

        // Check for operand missing for a binary operator
         
}

