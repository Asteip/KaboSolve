# KaboSolve
Solver of constraint satisfaction problems with "branch-and-prune" strategy. The "branch-and-prune" strategy uses in this project is "Forward checking".
The following problems are available :
* N-queens
* Send More Money
* Magic square
* sudoku (without diagonals)
* x-sudoku (with diagonals)

# Compile and Installation

Clone the repository :
```bash
git clone https://github.com/Asteip/KaboSolve
```

Compile the project :
```bash
# run the following command at the root of the project directory
make
```

Run the KaboSolve :
```bash
# problem : choose among the following problem : n-queens, more-money, magic-square, sudoku, x-sudoku
# number of solutions : "one" (finds the first solution) or "all" (finds all solution)
# options : additional options
./KaboSolve <problem> <number of solutions> [<options>]
```
