// From Data-oriented design software engineering for 
// limited resources and short schedules (Richard Fabian)
// 6.1 Bypassing the Cache https://lwn.net/Articles/255364/



#include <emmintrin.h>


void setbytes(char* p, int c)
{
	__m128i i = _mm_set_epi8(c, c, c, c,
		c, c, c, c,
		c, c, c, c,
		c, c, c, c);
	_mm_stream_si128((__m128i*) & p[0], i);
	_mm_stream_si128((__m128i*) & p[16], i);
	_mm_stream_si128((__m128i*) & p[32], i);
	_mm_stream_si128((__m128i*) & p[48], i);
}
/*
Optimization tips.
1. Reducing order dependencies.
2. Reducing memory dependency.
3. Write buffer awareness.
*/

/*
	4. Aliasing | aliasing is when it's possible for pointers to reference the same
	memory, and therefore require reloading between reads if the other pointer
	has been written to.

*/

void fun() {
	char buffer[100];
	buffer[0] = 'X';
	//memcpy(buffer + 1, buffer, 98);
	buffer[99] = '\0 ';
}

// After looking deeper on this topic,
// Microsoft offers keywords __declspec(restrict) and __restrict. __declspec(restrict)
// applies to a function declaration or definition that returns a pointer type and tells 
// the compiler that the function returns an object that will not be aliased with any 
// other pointers. And __restrict offers similar semantics on variables.
void fun2(int n, int* __restrict a, int* __restrict b,
	int* __restrict c) {
	int i;
	for (i = 0; i < n; i++) {
		a[i] = b[i] + c[i];
	}
}


void gun2(int n, int* a, int* b, int* c) {
	int i;
	for (i = 0; i < n; i++) {
		a[i] = b[i] + c[i];
	}
}

//todo: add info from https://docs.microsoft.com/en-us/cpp/cpp/restrict?redirectedfrom=MSDN&view=msvc-170

// 5. Alignment
#include <memory>

void fun1(int* p) {
	int* p1 = std::assume_aligned<16>(p);
	//  Use p1, not p, to ensure benefit from the alignment assumption.
	// However, the program has undefined behavior if p is not aligned
	// regardless of whether p1 is used.
}

/*

	6. Return Value optimization
	9.6 Cach line utilization
	9.7  False sharing

*/
/*
	9.10 Don’t get evicted
 To reduce the chance or frequency
 of your code and data being evicted, keep both code and data
 small and process in bursts when you can.

 To that end, try to find ways to guarantee to the compiler
that you are working with aligned data, in arrays that are
multiples of 4 or 8, or 16, so the compiler doesn’t need to
add preambles and postamble code to handle unaligned, or
irregularly sized arrays. It can be better to have 3 more dead
elements in an array and handle it as an array of length N  4.
*/
void Amplify(float* a, float mult, int count)
{
	for (int i = 0; i < count; ++i) {
		a[i] *= mult;
	}
}
//typedef float f16 __attribute__((aligned(16))); //for gcc, clang
typedef __declspec(align(16)) float f16;
void Amplify2(f16* a, float mult, int count)
{
	count &= -4;
	for (int i = 0; i < count; ++i) {
		a[i] *= mult;
	}
}

void Gcc_Clang_Amplify2(float* a, float mult, int count)
{
	float* ax = (float*)__builtin_assume_aligned(a, 64);
	count &= -4;
	for (int i = 0; i < count; ++i) {
		a[i] *= mult;
	}
}

void New_Standard_Amplify2(float* a, float mult, int count)
{
	float* ax = std::assume_aligned<64>(a);
	count &= -4;
	for (int i = 0; i < count; ++i) {
		a[i] *= mult;
	}
}

// Here it seems that gcc is doing great and msvc,clang can't optimize same way yet.

// The Rule: Breaking out, breaks vectorisation
//typedef float f16 __attribute__((aligned(16)));
void Amplify_with_break(f16* a, float mult, int count)
{
	count &= -4;
	for (int i = 0; i < count; ++i) {
		if (a[i] < 0)
			break;
		a[i] *= mult;
	}
}
/*
Note that branching in and of itself does not cause a breakdown in vectorisation,
but the fact the loop is exited based on data.
*/

//typedef float f16 __attribute__((aligned(16)));
void Amplify_with_if(f16* a, float mult, int count)
{
	count &= -4;
	for (int i = 0; i < count; ++i) {
		f16 val = a[i] * mult;
		if (val > 0)
			a[i] = val;
		else
			a[i] = 0;
	}
}

// Other example: below function can't be auto-verctorized because of near data dependency.
void CombineNext(float* a, int count)
{
	for (int i = 0; i < count - 1; ++i) {
		a[i] += a[i + 1];
	}
}
// but this one can, because it depends on far away data.
void CombineFours(float* a, int count)
{
	for (int i = 0; i < count - 4; ++i) {
		a[i] += a[i + 4];
	}
}

// Carlos Bueno’s book Mature Optimization Handbook

// Claim: Encapsulation makes ccode more reusable. It's easier to
// modify the implementation without affecting the usage. Main-
// tenance and refactoring become easy, quick and safe.

uint32_t CountBitsClever(uint32_t v) {
	v = v - ((v >> 1) & 0x55555555); // reuse input as temporary
	v = (v & 0x33333333) + ((v >> 2) & 0x33333333); // temp
	auto c = ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; // count
	return c;
}
uint32_t CountBitsDumb(uint32_t in) {
	uint32_t numBits = 0;
	while (in) {
		numBits += 1;
		in &= in - 1;
	}
	return numBits;
}
// always look if there is known solution to the problem.
uint32_t CountBitsBetter(uint32_t in){
    return std::popcount(in);
}
