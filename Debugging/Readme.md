## Here you can find quick links to information needed during debugging.


### [Force loading debug symbols](https://www.youtube.com/watch?v=HYEOAzyJBhU)
If you have a source code for which you trying to debug crash dump, then you just need to 
create new exe with pdb and from inside windbg execute
**.simopt+ 0x40** then **.reload** this will force load symbols.

### [Windbg scripts](https://www.youtube.com/watch?v=8t1aTbnZ2CE)
Below examples will print whenever we open/create files. 
1. bp kernelbase!CreateFileW ".printf \"Opening file %mu\", dwo(@esp+4);.echo ---;k 3;gc"
2. bp kernelbase!CreateFileA ".printf \"Opening file %ma\", dwo(@esp+4);.echo ---;k 3;gc"
3. bp kernelbase!CreateFileW "gu; .if (@eax == 0) {
   .printf \"Failed to open file=%mu\", dwo(@esp+4); .echo ---;k3
   } .else { gc }
Details from above commands. eax is return register for x86 for 64 bit it's rax
@esp + 4 is first argument address.

