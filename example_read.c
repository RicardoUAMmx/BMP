#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include "bmp.h"

int main(){
	bmp_t bmp_head;

	FILE *stream = fopen("./man.bmp", "rb");
	if( stream == NULL ){
		fprintf( stderr, "\nError: opening file\n" );
		return 1;
	}
	size_t br = fread( &bmp_head, sizeof( bmp_head ), 1, stream );
	fclose(stream);

	if( br != 1 ){
		fprintf( stderr, "\nError: reading header (%zu)\n", br );
		return 1;
	}

	if( swap_uint16( bmp_head.head.type ) != BITMAP_MAGIC ){
		fprintf( stderr, "\nError: type file ( %x )\n", bmp_head.head.type );
		return 1;
	}

	if( bmp_offset_check( bmp_head ) ){
		fprintf( stderr, "\nError: head size ( O: %u, H: %zu, S: %u )\n",
				 bmp_head.head.offset, sizeof( bmp_head.head ), bmp_head.info.size );
		return 1;
	}

	if( bmp_bpp_check( bmp_head.info.bpp ) ){
		fprintf( stderr, "\nError: unsoportted bpp ( %u )\n", bmp_head.info.bpp );
		return 1;
	}

	if( bmp_size_check( bmp_head.info ) ){
		fprintf( stderr, "\nError: file size ( W: %u, H: %u, B: %u, S: %u )\n",
				 bmp_head.info.width, bmp_head.info.height, bmp_head.info.bpp/8,
				 bmp_head.info.image_size );
		return 1;
	}

	if( bmp_compression_check( bmp_head.info.compression ) ){
		fprintf( stderr, "\nError: unsoportted compression ( %x )\n",
				bmp_head.info.compression );
		return 1;
	}

	return 0;
}
