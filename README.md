# <p align = "center"> LSystem </p>

 ---

<p align = "center"> Simple c++ L-System generator </p>

-   [What are L-Systems?](#description)
    * [Definition](#definition)
    * [Development](#development)
-   [How it works?](#how-it-works)
    * [LSystem class](#lsystem-class)
    * [Turtle class](#turtle-class)
-   [Documentation](#documentation)
    * [Initialization](#initialization)
    * [Setting rules](#setting-rules)
    * [Getting results](#getting-results)
-   [Examples](#examples)
    * [Plant](#plant)
    * [Heighway dragon](#heighway-dragon)
    * [Pleasant error](#pleasant-error)
    * [Sierpinski triangle](#sierpinski-triangle)

---
## What are L-Systems?
### Definition
An L-system or Lindenmayer system is a parallel rewriting system and a type of formal grammar.

L-systems are now commonly known as parametric L systems, defined as a tuple:

>  G = (V, ω, P),

where
- V (the alphabet) is a set of symbols containing both elements that can be replaced (variables) and those which cannot be replaced ("constants" or "terminals")
- ω (start, axiom or initiator) is a string of symbols from V defining the initial state of the system
- P is a set of production rules or productions defining the way variables can be replaced with combinations of constants and other variables. A production consists of two strings, the predecessor and the successor. For any symbol A which is a member of the set V which does not appear on the left hand side of a production in P, the identity production A → A is assumed; these symbols are called constants or terminals.

### Development
Once the L-system is defined, it begins to evolve according to its rules. The initial state of the L-system is its axiom. With further development, this line describing the state will change. The development of L-systems is cyclic. In each development cycle, a line is viewed from beginning to end, character by character. For each symbol, the rule for which the symbol serves as a precursor is searched. If no such rule is found, the symbol is left unchanged. In other words, for those x characters for which there is no explicit rule, the implicit rule applies: X→X. If the corresponding rule is found, the predecessor character is replaced by the following string from this rule.

## How it works?
The program has two classes: LSystem and Turtle. The first class produces the development of L-system. The second class processes commands of turtle graphics.

### LSystem class
The LSystem class has only two methods, except for the constructor.
```c++
LSystem(string axiom, vector<string> &rul);
```
Constructor. Creates and returns a new object of the LSystem class. Takes the string axiom as the l-system axiom and the vector rul as The l-system rule set.
```c++
void iterate(const int &iterations);
```
Carries out &iterations stages of development of the L-system.
```c++
void interpret(const float &step, const float &angle);
```
Interprets the current state of the L-system (calls interpretation procedures for each character for which such procedure is defined in the interpretation table).

### Turtle class
The Turtle class has two kinds of methods. Some of them are responsible for the movement of the turtle in the coordinate system. Others are responsible for drawing.
####  Methods of movement
```c++
void move(float distance);
```
Moves the turtle a certain distance
```c++
void turnRight(float angle);
void turnLeft(float angle);
```
Turns the turtle's head at a certain angle
```c++
void save();
void restore();
```
Save/restore the current coordinates of the turtle

####  Drawing methods
```c++
void drawLine(float x1, float y1);
```
Draws the path of the turtle if the pen is omitted
```c++
void setColor(double red, double green, double blue);
void setColor(int red, int green, int blue);
```
Change the color of the turtle feather
```c++
void setPictureSize();
```
Finds the largest and smallest coordinates and sets the size of the image

## Documentation
### Initialization

```c++
LSystem lsystem(options);
```

`options` may contain:
- `axiom` A String to set the initial axiom
- `rules` A Vector of the strings with variables and rules

### Setting rules
As seen in the first section you can simply set your rules when you init your L-System:

```c++
vector<string> rules = {"A => A-B--B+A++AA+B-"};
LSystem lsystem(rules);
```

But the rule string should look like this
```
A => A-B--B+A++AA+B-
```
The first character is the variable name. Then '=>' with spaces. After that, there is a variable replacement rule.

Also you could start with an empty L-System object, addRule() to edit the L-System later:
```c++
LSystem lsystem();
lsystem.addRule("B","+A-BB--B-A++A+B");
```

### Getting results
Now that we have set up our L-System set, we  can develop our L-System with iterate():

- Iterate once
```c++
lsystem.iterate();
```

- Iterate n-times
```c++
int n = 5;
lsystem.iterate(n);
```

Then you can interpret result with interpret():

```c++
float step = 3;
float angle = 120;
lsystem.interpret(step, angle);
```

Also you can just get result with getCondition():
```c++
LSystem lsystem("ABA");
lsystem.addRule("B","+A-B-B-A+");
lsystem.iterate();
lsystem.getCondition();
// 'A+A-B-B-A+A'
```

## Examples
### Plant

![Plant](examples/fractal_plant.png "Fractal Plant")

Iterations - 7<br>
Angle - 25 degrees

|     Axiom     |     Rules     |
| ------------- | ------------- |
| X  | X → F-[[X]+X]+F[+FX]-X<br> F → FF |

### Heighway dragon

![Heighway dragon](examples/heighway_dragon.png "Heighway dragon")

Iterations - 13<br>
Angle - 90 degrees

|     Axiom     |     Rules     |
| ------------- | ------------- |
| FX  | X → X+YF+<br> Y → -FX-Y |

### Pleasant Error

![Pleasant Error](examples/pleasant_error.png "Pleasant Error")

Iterations - 4<br>
Angle - 72 degrees

|     Axiom     |     Rules     |
| ------------- | ------------- |
| F-F-F-F-F  | F → F-F++F+F-F-F |

### Sierpinski triangle
Run sierpinski-example.cpp to get this example

### Gosper curve
Run gosper-example.cpp to get this example
