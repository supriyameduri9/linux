#include <stdio.h>

int main()
{
	int total_exits;
	int time_low_32;
	int time_high_32;
	unsigned long long total_time;

	__asm__("mov $0x4fffffff, %eax\n\t"); //input
	__asm__("cpuid\n\t");
	__asm__("mov %%eax, %0;" : "=r" (total_exits));
  	__asm__("mov %%ebx, %0;" : "=r" (time_high_32));
  	__asm__("mov %%ecx, %0;" : "=r" (time_low_32));

  	total_time = (unsigned long long) time_high_32 << 32 | time_low_32;
  	printf ("CPUID(0x4FFFFFFF), exits=%d, cycles spent in exit=%llu", total_exits,total_time);
  	return 0;
}