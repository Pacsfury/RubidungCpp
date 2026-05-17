# RUBIDUNG
## A memory dungeon CLI game, now in C++
---


# Features
**Rubidung** is a dungeon memory game, memory-based.


When the game starts, the map is shown. Diferent tiles mean different things:


| **Symbol** | **Meaning**                |
|------------|----------------------------|
|**#**       |A wall, recovered of spikes!|
|**.**       |Free space to walk          |
|**$**       |The treasure you want!      |
|**@**       |You!                        |
|**O**       |A wall, without spikes!     |


When the first command is inputted, the map hides, and your only help is your memory.


Actual commands are:


- **W**: Move up
- **A**: Move left
- **S**: Move down
- **D**: Move right


If the correct sequence is inputted, the game halts and you win, but if you do more turns than maximum, you lose!


## Updates Log

16/05/2026

- **Add**: C++ version

## Known Bugs

- Level 1 repeats
- Maps should be `static`
- Escape ANSI code for clearing screen



