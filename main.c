#include <stdio.h>
#include <stdint.h>
#include "bmp.h"

int main(){
	FILE *stream = fopen("./ironman.bmp", "rb");
	bmpdib_t h;
	fread( &h, sizeof( h ), 1, stream );
	print_bmp_header( &h );
	fclose(stream);
	return 0;
}
