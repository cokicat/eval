# eval
This is a minimal implementation of the eval function I made to learn C.  
The code is probably a mess since it's my first time finishing a project in C. The syntax is very simple: the parser only supports basic operations like `+`, `-`, `*` or `/`. Brackets and floating numbers are not supported and spaces or new lines are skipped.

## Compiling
Just run (no dependencies):
```
make
```

## Usage
```
eval [EXPRESSION]
```
If started without arguments, `eval` will run in interactive mode, else it will evaluate the first argument.  

### Example
```
eval 1+1
```
... will print `2` to stdout.

## TODO
- [ ] Add support for brackets (add better support for relative numbers)
- [ ] Add support for floating numbers
- [ ] Add dynamic tokens support
