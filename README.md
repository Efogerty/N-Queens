# N-Queens
Calculates how many unique solutions there are to the n queens problem.

N queens is a problem in which given a certain amount of chess queens, how many instances of the board could there be
in which none of the queens are targeting each other?

We solve this through a checkRow function that searches from positions on the board and ensures queens are not targering them, 
then pruning future searches to not include ones that have been already checked in order to solve this problem efficiently.
