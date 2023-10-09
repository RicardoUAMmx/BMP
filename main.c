#include <stdio.h>
#include <stdint.h>
#include "bmp.h"

int main(){
	FILE *stream = fopen("./ironman.bmp", "rb");
	bmpdib_t h;
	fread( &h, sizeof( h ), 1, stream );

	print_bmp_header( &h );
	//printf( "%-10s", "Kind:" );
	//priprintf( "%s\n", ( char * )&h.type );
	//priprintf( "%-10s", "Size:" );
	//priprintf( "%u\n", h.size );
	//priprintf( "%-10s", "Offset:" );
	//priprintf( "%u\n", h.offset );

	fclose(stream);
	return 0;
}
