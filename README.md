# KaboSolve
Solver of constraint satisfaction problems with "branch-and-prune" strategy. The "branch-and-prune" strategy uses in this project is "Forward checking".

# Compile and Installation
===========================

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
# probleme : choose among the following problem : N-reines, more-money magic-square
# choix-solver : "one" (finds the first solution) or "all" (finds all solution)
# options : some problem asks for option like N-reines
./KaboSolve <probleme> <choix-solver> [<options>]
```
