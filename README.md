# pipex

Validated on 30/06/2024

125/100

Times invested: about 3 weeks

Defects of this project: 

The split in mandatory part is not well protected. The condition where dup2() returns -1 is not thought of neither... If we launch ./pipex with env -i(without environment), the program will say "command not found". If we pass absolute paths of commands, it will not work. If we quit because of invalid command, the infile discriptor is not closed "in" the child process.

All of these might not be a problem in this project, but would be a mistake in Minishell.

Take your time to understand this project, it would be really useful later.
