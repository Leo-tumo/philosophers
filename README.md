# philosophers 42
I’ve never thought philosophy would be so deadly.
## ΟΙ ΓΕΥΜΑΤΙΖΟΝΤΕΣ ΦΙΛΟΣΟΦΟΙ
![](https://github.com/hanshazairi/42-minitalk/workflows/norminette/badge.svg)

[![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/alesanto/Philosophers)](https://github.com/JaeSeoKim/badge42)
#### `source` - [wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)

![image](https://user-images.githubusercontent.com/73405731/153401286-ef7133b2-918c-4b5a-9d44-1df5e321f542.png)
### Goal
One or more philosophers are sitting at a round table either eating, either thinking, either sleeping. While they are eating, they do not think or sleep; while thinking they don’t eat or sleep; and, of course, while sleeping, they do not eat or think.
  - The philosophers sit at a circular table with a large bowl of spaghetti in the center.
  - There are some forks on the table. Serving and eating spaghetti with a single fork
is very inconvenient, so the philosophers will eat with two forks, one for each hand.
  - Each time a philosopher finishes eating, they will drop their forks and start sleeping. Once they have finished sleeping, they will start thinking. The simulation stops when a philosopher dies.
  - Every philosopher needs to eat and they should never starve.
  - Philosophers don’t speak with each other.
  - Philosophers don’t know when another philosopher is about to die.
  - No need to say that philosophers should avoid dying!

### Arguments

The program should take the following arguments: number_of_philosophers time_to_die
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
  - number_of_philosophers: is the number of philosophers and also the number of forks.
  - time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’ milliseconds after starting their last meal or the beginning of the simulation,
it dies.
  - time_to_eat: is in milliseconds and is the time it takes for a philosopher to eat. During that time they will need to keep the two forks.
  - time_to_sleep: is in milliseconds and is the time the philosopher will spend sleeping.
  - number_of_times_each_philosopher_must_eat: argument is optional, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.
  - 
### Rules

| Rule         |                 Description                             |
|:------------:|:-------------------------------------------------------:|
| `make`       | Compile the program.                                    |
| `make clean` | Remove every objects of compilation                     |
| `make fclean`| Do `clean` rule and remove the executable program       |
| `make re`    | Do `fclean` rule and compile the program                |

### Useful links

[youtube](https://youtu.be/d9s_d28yJq0)

[youtube](https://youtu.be/uA8X5zNOGw8)
