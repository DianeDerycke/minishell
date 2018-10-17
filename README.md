# Minishell

Minishell is the second project of the Unix branch at 42 school. It is a simplistic shell to make us (students) understand the process creation and synchronization.

## Requirements

- GCC 4.2.1
- GNU Make 3.81

## Getting Started

If you want to try the program, please make sure to run the following commands:

- Clone the repository : `git clone https://github.com/DianeDerycke/minishell.git`

- Go to the repository : `cd ./minishell`

- Compile the project : `make`

- Run the program : `./minishell`

## Informations

### Instructions
Follow this [link](https://github.com/DianeDerycke/minishell/blob/master/minishell.en.pdf) to read the instructions about the project.

### Makefile
The Makefile contains the regular rules such as :
- `make clean`
- `make fclean`
- `make re`

### About this minishell
It has implemented these builtins : `cd` `echo` `setenv` `unsetenv` `env` `exit`.
For more informations about the builtins, you can run in the minishell `help`.
It handles expansions such as `~` and `$`

### Bonus
- PATH's right management
- Builtin `help`
- `env -i` option

# Key takeaways
This project allowed me to understand how basic commands work, the environment and its goals, the process and its creation, the expansions and I could improved the readability of my code.
