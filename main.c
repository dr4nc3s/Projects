#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
	uint32_t startMS = 0xFFFFFAFF;
	uint32_t newMS = 6656;

	uint32_t diffMS = newMS - startMS;

	uint32_t manualMS = newMS + (0xFFFFFFFF - startMS);

	printf("diffMS = %u manualMS = %u\n", diffMS, manualMS);

	return 0;
}