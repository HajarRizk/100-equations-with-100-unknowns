# 100-equations-with-100-unknowns
The programs reads first an integer n which is the number of equations.
Then the program reads n lines containing the equations.
Any operation convert every equation to the proper form.
After reading the equations the program reads one or more commands from user and program print the results of each operations
and read another operation till the program read the operation quit which ends the program. Any result printed based on the proper form of
equations

operations:
num_vars: Print the number of
variables in the equations.
equation i: Print equation number i (i is integer) in proper form to variable is repeated any varibles on the right hand and only one constant on left hand
column x2: Print the column of coefficients of variable (x2).Print the vector of coefficients of the given variable name. (x2 can be replaced by any variable
name)
add 1 3: Print the result equation from adding equation 1 and equation 3. (1 and 3 can be any integer numbers from 1 to n).
subtract 1 3: Print the result equation from subtracting equation 1 and equation 3. (1 and 3 can be any integer numbers from 1 to n).
substitute x2 1 3:Remove the variable x2 from equation 1 by substituting it with equation 3 and print the result equation

Examples:
1)
3
2x1+3x2+4x3=16
1x1+2x2+1x3=8
3x1+1x2+2x3+x4=13
num_vars

4

2)
3
2x1+3x2+4x3=16
1x1+2x2+1x3=8
3x1+1x2+2x3+x4=13
equation 2

1x1+2x2+1x3=8

3)
3
2x1+3x2+4x3=16
1x1+2x2+1x3=8
3x1+1x2+2x3+x4=13
add 1 3

4x1+4x2+6x3+x4=29

4)
3
2x1+3x2+4x3=16
1x1+2x2+1x3=8
3x1+1x2+2x3+x4=13
substitute x2 1 3

-7x1-2x3-3x4=-23 or 7x1+2x3+3x4=23


