#include <stdio.h>

int main()
{
	int total_exits;
	unsigned long long time_low_32;
	unsigned long long time_high_32;
	unsigned long long total_time;

	_asm_("mov $0x4fffffff, %eax\n\t"); //input
	_asm_("cpuid\n\t");
	_asm_("mov %%eax, %0\n\t" : "=r"(total_exits));
  _asm_("mov %%ebx, %0\n\t":"=r" (time_high_32);
  _asm_("mov %%ecx, %0\n\t":"=r" (time_low_32);

  total_time = (unsigned long long) time_high_32 << 32 | time_low_32;
  printf ("CPUID(0x4FFFFFFF), exits=%d, cycles spent in exit=%llu", total_exits,total_time);
  return 0;
}