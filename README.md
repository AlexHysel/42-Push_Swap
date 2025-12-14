*This project has been created as part of the 42 curriculum by afomin.*

---

## Description

**push_swap** is an algorithmic project whose goal is to sort a stack of integers using a limited set of operations and the smallest possible number of moves.

The program receives a list of integers as arguments, stores them in **stack A**, and must sort them in ascending order using **stack B** as auxiliary storage. Only a predefined set of operations (swap, push, rotate, reverse rotate) is allowed.
The challenge lies in designing an efficient sorting strategy that minimizes the total number of operations, especially for large input sizes.

---

## Instructions

### Compilation

Compile the project using `make`:

```bash
make
```

This will generate the executable:

```bash
./push_swap
```

### Usage

Run the program with a list of integers as arguments:

```bash
./push_swap 3 2 1
```

### Test
if you want to get the number of steps with exact namber of elements in stack, you need to use test

*Code in test.c DOESNT fit norminette rules, so it's commented in repository.*

```bash
make test
```

This will compile the executable, just run it with one arg (number of random elements in stask a, 100 by default) and `ls -l` to count lines

```bash
./push_swap_test 500 | ls -l
```

The program outputs a sequence of instructions (one per line) that, when applied, will sort the stack.

## Allowed Operations

* `pa`, `pb` — push the top element from one stack to the other
* `ra`, `rb`, `rr` — rotate a stack upward
* `rra`, `rrb`, `rrr` — rotate a stack downward

I also use hardcoded `sa` in sort3 funtion, but only once, so this code doesnt include s-functions at all.

---

## Resources

### Classic References

Turk Sort algorythm:
https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0

### Use of AI

AI was used to write basic README and find some errors in my code.
