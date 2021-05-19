/*
Sure we can process data faster than ever, but we can't get that data faster.

	Data Locality pattern:

Whenever the chip reads some memory, it gets whole cache line.
If two threads try to tweak data on the same cache line, both cores
have to do some cosly synchronization of their caches.

CacheGrind will show cashe misses and help you optimize code.
One of the hallmarks of software architecture is abstraction.

	Dirty flag pattern:
This time we defer calculation of date until it is really needed.
For example if A changes B depends on A, then when we change A we set a flag for B to true(meaning Data is not up to date).
When we need B we check the flag and if it is true we recalculate B, aterwise we use cached result for B.

Dirty flags are applied to two kinds of work: calculation and synchronization. In
both cases, the process of going from the primary data to the derived data is
time-consuming or otherwise costly.

	Object Pool:
Intent
	Improve performance and memory use by reusing objects from a fixed pool
	instead of allocating and freeing them individually.



*/