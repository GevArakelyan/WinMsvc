
https://docs.microsoft.com/en-us/windows-hardware/drivers/debugger/bp--bu--bm--set-breakpoint-
	bp vs bu
Breakpoints that you set with bp are not saved in WinDbg workspaces.
Breakpoints that are set with bu are saved in workspaces.
---------------------------------
			bm usage

example.
	0:000> bm myprogram!mem* 
	4: 0040d070 MyProgram!memcpy
	5: 0040c560 MyProgram!memmove
	6: 00408960 MyProgram!memset

----------------------------------------------
If you specify Thread, breakpoints are set on the specified threads.
For example, the ~*bp command sets breakpoints on all threads,
~#bp sets a breakpoint on the thread that causes the current exception,
and ~123bp sets a breakpoint on thread 123.
The ~bp and ~.bp commands both set a breakpoint on the current thread.
----------------------------------------------

## [Time Travel Debugging - James McNellis - Meeting C++ 2018](https://www.youtube.com/watch?v=MyVQnP-U_ho)
```
dx @$calls = @$cursession.TTD.Calls("kernekbase!GetLastError", "user32!MessageBox")
will get both calls

dx -g @$calls | print in grid

dx -g @$calls
.OrderBy(x => x.TimeStart)
.Where( x => x.ReturnValue != 0 || x.Function.Contains("MessageBox"))
.Where( x => x.ThreadId == 0x1634) | this is ui thread
.Count() | will get count

dx -g -c 2300 @$calls | will skip first 2300

ba w 8 address
g- | go back

To see all locations where we write to some 8 byte memory
dx -g @$cursession.TTD.Memory(Address1,Address1+8, "w")

```