#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include "bmp.h"

int main(){
	bmpheader_t bmp_h;
	bmpinfo_t bmp_i;
	bmpcolor_t bmp_c;
	bmpprofile_t bmp_p;
	FILE *stream = fopen("./ironman.bmp", "rb");
	fread( &bmp_h, sizeof( bmp_h ), 1, stream );
	fread( &bmp_i, sizeof( bmp_i ), 1, stream );
	fread( &bmp_c, sizeof( bmp_c ), 1, stream );
	fread( &bmp_p, sizeof( bmp_p ), 1, stream );
	print_bmp_header( &bmp_h );
	print_bmp_info( &bmp_i );
	print_bmp_color( &bmp_c );
	print_bmp_profile( &bmp_p );
	fclose(stream);
	printf( "\n\n" );
	printf( "Header: %lu\n", sizeof( bmp_h ) );
	printf( "Info: %lu\n", sizeof( bmp_i ) );
	printf( "Color: %lu\n", sizeof( bmp_c ) );
	printf( "Profile: %lu\n", sizeof( bmp_p ) );
	printf( "\n\n" );
	return 0;
}
