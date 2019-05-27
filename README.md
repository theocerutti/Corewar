## Corewar

Corewar is a game. A very special game. It consists of pitting little programs against one another in a virtual machine.
The goal of the game is to prevent the other programs from functioning correctly by using all available means.
The game will, therefore, create a virtual machine in which the programs (written by the players) will face off. Each
program’s objective is to "survive", that is to say executing a special instruction ("live") that means I’m still alive.
These programs simultaneously execute in the virtual machine and in the same memory zone, which enables them
to write on one another.
The winner of the game is the last one to have executed the "live" instruction.

The project is divided into three seperate parts:
- The virtual Machine
- The assembler
- Champions

## Assembler

USAGE: 
```cd asm ; make re```
```./asm file_name[.s]```

In order to write the champions, we will be using a simple language called "assembly code".
The Assembler converts the assembly file.s into an file.cor, an executable in the Virtual Machine. 

## Virtual Machine

USAGE: 
```cd corewar ; make re```
```./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name]```

```corewar -h``` for more information.

The machine’s role is to execute the programs that are given to it as parameters, generating processes.
It must check that each process calls the "live" instruction every CYCLE_TO_DIE cycles.
The last champion to have said "live" wins.

## Champions

Champions are written thanks to the assembly language, described in the The Assembler section.
When the game, and therefore the virtual machine, starts, each champion is going to find its personal r1 register (the
number assigned to it by the Virtual Machine).
All of the instructions are useful; all of the machine’s reactions that are described in this project description are able to
be used to give your champions more life, and to find an efficient strategy to win!

You will find many champions in the ```champions``` directory !

# Example

Here is an example of zork.s:

```
#
# zork. s for corewar
#
# Bob Bylan
#
# Sat Nov 10 03:24;30 2081
#
. name "zork"
. comment "just a basic living prog"
l2 :
sti r1,%:live,%1
and r1,%0,r1
live: live %1
zjmp %: live
```

Try to make your own champion !

## Author  

* **Théo CERUTTI** - [Github](https://github.com/theocerutti)
* **Antoine MAILLARD** - [Github](https://github.com/AntoineMaillard06)
* **Mathilde COUSTON** - [Github](https://github.com/MathildeCouston)
* **Cyril BEGARD** [Github](https://github.com/cyrilbegard/)
