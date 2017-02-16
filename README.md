# cv
CV (Compile Vala) is a simple utility I made so that I can quickly compile my [Vala](https://en.wikipedia.org/wiki/Vala_(programming_language)) files,
(though it actually works with all languages that support `/**/` comments).

To use cv with a file, you insert the following in the first line of the file:
```
/* Compile: <compile command> */
```

A simple Vala  _hello world_ program would look like:
```
/* Compile: valac -o hello_world hello_world.vala */

int main(string[] args)
{
    print("Hello, world\n");
    return 0;
}
```

Compiling looks like:
```
$ cv hello_world.vala 
valac -o hello_world hello_world.vala 
$
```

Also, once already compiled, cv can be used to trigger its own compilation:
```
$ cv cv.c
```
