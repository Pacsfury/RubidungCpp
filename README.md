# RUBIDUNG
## A memory dungeon CLI game, now in C++
---


# Features
**Rubidung** is a dungeon game, memory-based.


When the game starts, the map is shown. Different tiles mean different things:


| **Symbol** | **Meaning**                |
|------------|----------------------------|
|**#**       |A wall, recovered of spikes!|
|**.**       |Free space to walk          |
|**$**       |The treasure you want!      |
|**@**       |You!                        |
|**O**       |A wall, without spikes!     |


When the first command is entered, the map hides, and your only help is your memory.


Currently available commands are:


- **W**: Move up
- **A**: Move left
- **S**: Move down
- **D**: Move right


If the correct sequence is entered, the game halts and you win, but if you do more turns than maximum, you lose!


## Updates Log

16/05/2026

- **Add**: C++ version

26/06/2026

- **Upgrade**: README deleting typos and spelling mistakes, add checkboxes to `known bugs`.

## Known Bugs

- [ ] Level 1 repeats
- [ ] Maps should be `static`
- [ ] Escape ANSI code for clearing screen



