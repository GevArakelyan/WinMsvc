## **rax** is almost always holds the return value of the function.
```
On windbg

r rax | print rax register
or
rrax 

rax | will display bottom 16bits of rax
```
## **rcx** is used as first parameter of member functions (it holds this pointer)
```
.load C:\dumps\mex.dll
.chain | too see loaded extensions.
!t | will show the stack (we could use k command, but this one adds some extra info)
```
error code may reside inside rax.
```
r | too see registers
x too see local variables
!gle | get last error
open google and type "win32 error codes" | you'll find all error codes on microsoft docs.
```
## For walking the stack and looking around.
```
t or t-
p or p-
g or g-
gu | getting out of current function

u | to see where we are.

uf module!function | will show function stack.

!strings address | too see what string in this address

!teb | will show short version of thread env block
dt nt!_TEB address | (address can be found in first line of !teb command result)
here we can see LastError value and it's offset.
ba w4 (tebAddress)+LastErroroffset  
g-

bc* to clear breakpoints.

bp module!function 

bd* | to disable all breakpoints
be 1 | to enable 1 breakpoint.

ub | unassemble backwards

```

## When someone calls function then parameters stored in: rcx rdx r8 and r9.
```
!strings valueof_rcx | will show parameter if it is string.
```










