Top debugger commands that will help you to gain more info about running app.

---------------------------------------------------------------------------
Windows Debugging and Troubleshooting https://www.youtube.com/watch?v=2rGS5fYGtJ4
windbg notepad
qd   | to detach then quit(this means app will not be closed.)
lm | list modules
lm v m malware | show verbose for module named malware.
-----------------------To look how much time task took it's easy to use below in cmd------------------------------------------------------
Computer\HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Command Processor
New Strings Value | name it Autorun and for value use { prompt $T $B $P$G}
-------------------Programm monitoring fixing crashes finding perf problems--------------------------------------------------------
	https://channel9.msdn.com/events/ignite/2015/brk3316
	Process Monitor { shows many usefull information like registries, process and threads, I/O}
ctrl+r will revert filters.
ctrl+t will open process Tree
-----------------------ProcDump-------------------
procdump -i | will register it for creating crash dump when processes will crash.

procdump -c 20 cpustres c:\dumps || will create dmp file if cpu usage will exeed 20% for some time (10s I guess)



---------------------------------------------------------------------------
!peb  | shows laoded modules, environment variables, command line args, and more...

.hh k | will show hellp for k command. ( k is showing call stack.)

!runaway | shows quanta of each thread. run when have high cpu issue.

| will show commandline.

~ will show pid and tid. ~Ns switches the active thread to thread N.

~*k to see all stacks.
---------Performance tools-------------------------------------------
Find when wmplayer is consuming 10% of some cpu for 5 seconds.

	procdump -c 10 -s 5 -u wmplayer.

-----------------------------------------
 .Net related.

	!syncblk find outstanding syncblocks on which other threads are waiting.

	Another common commands for hangs.
	!finalizequeue from psscorX lists objects registered for finalization.

	!threads is one way to find handgs.
-----------------------------------------