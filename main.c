#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include "bmp.h"

int main(){
	bmp_t bmp_head;
	FILE *stream = fopen("./ironman.bmp", "rb");
	fread( &bmp_head, sizeof( bmp_head ), 1, stream );
	fclose(stream);
	print_bmp( bmp_head );
	return 0;
}
