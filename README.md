# blox-lang 
Blox programming language reference

## 1 Introduction
Blox is a fractal language, that is, everything is a block, composed by
children blocks. Types, functions, classes, modules, etc., are
blocks.

## 2 Syntax

### 2.1 Reserved Words
List of reserved words:
(see [/src/blox.lex](/src/blox.lex))

### 2.2 Blocks
A block is a basic unit that may have input (parameters), output
(return), a behavior (statements) and other blocks defined inside it.

### 2.3 Types
The blox compiler performs duck typing.
The built-in types are int, string, bool and float.

### 2.4 Subprograms
Subprograms are blocks as well, with input parameters and return values.
By default, parameters are passed by value, however the caller block may
say explicitly it wants a callee to update the value of a parameter by
using &paramname.
This will pass the address to the original variable.
ointers are hidden to the user.

### 2.5 Classes
Classes can be implemented as blocks where the fields and methods are
blocks defined inside the class. The main code of the class block is the
constructor and must return 'this' (the current block instance).

### 2.6 Imports
A block can import another block by using the reserved word 'import'. An
imported block may receive parameters, which must be provided at that
moment. Imports must be in the definitions section of a block.
Import syntax:

`import block_identification [(params)] [as name]`

Ex.:

```
import root(2) as sqrt
import operations.power as pow
import "mymodule.blox" (param1,param2) as m
```

## 3 Examples
(see [examples](/examples) directory)
