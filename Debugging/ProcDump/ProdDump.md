https://docs.microsoft.com/en-us/sysinternals/downloads/procdump


			ProcDump

procdump -e 1 -f "" -w MyApp

will show you exceptions that got thrown.
1 is for thrown exceptions.
-e 1 means first chance exceptions. -e only will show only unhandled (means last chance).

-f "" | f is for filter. when empty means all.
-f 171 | for exception with code 171
-w | for waiting.
you can specify dump location with -x c:\dumps args.




procdump -i | will register it for creating crash dump when processes will crash.
procdump -ma -i | to generate mini active dump.
To remove it as default AeDebug tool:
procdump -u

------------------
After opening dump file, to see more info.
.lastevent  | Displays pid/tid and exception code of the crash
.exr -1 | Displays the Exception's parameters, and a description if it is a well known code


.ecxr
then
k
will show the throw moment not when it already has been catched.


![Common ProcDump Options](Assets/ProcDump_options01.png)

![Common ProcDump Options](Assets/ProcDump_options02.png)


procdump -c 20 cpustres c:\dumps || will create dmp file if cpu usage will exeed 20% for some time (10s I guess)
procdump -c 20 -u cpustres c:\dumps | same as above except will treat cpu usage relative to a single core


Defrag-Tools-180-Active-Memory-Dump : https://channel9.msdn.com/Shows/Defrag-Tools/Defrag-Tools-180-Active-Memory-Dump?term=dump%20file%20debugging&lang-en=true

