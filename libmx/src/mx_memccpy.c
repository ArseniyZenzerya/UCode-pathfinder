#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n){

    char *p_dst = (char *)dst;
	char *p_src = (char *)src;

size_t count = 0;

	for (size_t i = 0; i < n; i++) {
		count ++;
		p_dst[i] = p_src[i];
		if (p_src[i] == c)
			break;
	}

	if (count == n)
		return NULL;
	count++;
	return p_dst + count;

    return dst;
}



