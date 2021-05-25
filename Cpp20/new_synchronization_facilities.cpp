#include <latch>
#include <vector>
#include <thread>
#include <barrier>
#include <functional>
namespace
{
	/*			Latch
		std::latch is a single-use counter that allows threads to wait
		for the count to reach zero.

		1. Create the latch with a non-zero count
		2. One or more threads decrease the count
		3. Other threads may wait for the latch to be signalled.
		4. When the count reaches zero it is permanently signalled
		and all waiting threads are woken.

	*/
	struct my_data
	{
		unsigned i;
	};

	unsigned const thread_count = 2;

	void foo()
	{
		std::latch done(thread_count);
		my_data data[thread_count]{};
		std::vector<std::jthread> threads;
		for (unsigned i = 0; i < thread_count; ++i)
		{
			threads.push_back(std::jthread([&, i]
			{
				data[i] = my_data{i};
				done.count_down();
			}));
			//do more stuff
		}
		done.wait();
		//process data
	}

	/*
		Synchronizing Tests with Latches
		Using a latch is great for multithreaded tests:

		1. Set up the test data
		2. Create a latch
		3. Create the test threads
		==> The first thing each thread does is
		test_latch.arrive_and_wait()
		4. When all threads have reached the latch they are
			unblocked to run their code
	*/
}

namespace
{
	/* Barriers.
		std::barrier<> is a reusable barrier.
		Synchronization is done in phases:

		1. Construct a barrier, with a non-zero count and a completion
		function
		2. One or more threads arrive at the barrier
		3. These or other threads wait for the barrier to be signalled
		4. When the count reaches zero, the barrier is signalled, the
		completion function is called and the count is reset


	*/
	unsigned const num_threads = 3;
	void finish_task() noexcept // removing noexcept does not compile
	{
	}
	std::barrier b(num_threads, finish_task);
	void worker_thread(std::stop_token st, unsigned i)
	{
		while (!st.stop_requested())
		{
			//do stuff i
			b.arrive_and_wait();
		}
	}
}

#include <semaphore>
namespace
{
	/*
				Semaphores
		A semaphore represents a number of available 'slots'.
		If you acquire a slot on the semaphore then the count is decreased until you release the slot

		Attempting to acquire a slot when the count is zero will either block or fail.

		A thread may release a slot without  acquiring one and vice versa.
	*/
	unsigned const max_count = 3;
	std::counting_semaphore<max_count> slots(max_count);
	std::binary_semaphore is_alias_of(1); //std::counting_semaphore<1>

	void example()
	{
		slots.acquire();// blocks slots.try_acquire();  doesn't block 	
		// do stuff                    Here only 3 threads can do work at the same time.
		slots.release();
	}

}

namespace
{
	/*		Updates to Atomics

		Low-level waiting for atomics
		Atomic Smart Pointers
		std::atomic_ref

	*/

	std::atomic<int> var;

	void ex_atomic()
	{
		var.wait(1);
		var.notify_all();
		var.notify_one();
	}

	std::atomic<std::shared_ptr<int>> atomic_sptr;
	std::atomic<std::weak_ptr<int>> atomic_wptr;



}