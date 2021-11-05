#include "../inc/libmx.h"




void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    unsigned char *bigTemp = NULL;
	unsigned char *littleTemp = NULL;

	if (big_len >= little_len && big_len > 0 && little_len > 0) {
		bigTemp = (unsigned char *)big;
		littleTemp = (unsigned char *)little;
		while (*bigTemp) {
			if (mx_memcmp(bigTemp, littleTemp, little_len - 1) == 0) {
				return bigTemp;
            }
			bigTemp++;
		}
	}
	return NULL;
}


