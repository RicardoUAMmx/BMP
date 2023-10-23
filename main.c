#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include "bmp.h"

int main(){
	bmp_t bmp = bmp_create( 600, 600, BITMAP_BPP_32, BI_BITFIELDS );

	print_bmp_header( &bmp.head );
	print_bmp_info( &bmp.info );

	return 0;
}
