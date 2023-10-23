#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "bmp.h"

void print_bmp_header( bmpheader_t header ){
	printf( "\n" );
	printf( "%-12s", "Def" );
	printf( "%-12s\n", "Value" );
	printf( "%s", "--------- " );
	printf( "%s\n", "--------- " );
	printf( "%-12s", "Kind:" );
	printf( "0x%x\n", header.type );
	printf( "%-12s", "Size:" );
	printf( "%u\n", header.size );
	printf( "%-12s", "Offset:" );
	printf( "%u\n", header.offset );
	printf( "\n" );
}

void print_bmp_info( bmpinfo_t info ){
	printf( "\n" );
	printf( "%-12s", "Def" );
	printf( "%-12s\n", "Value" );
	printf( "%s", "--------- " );
	printf( "%s\n", "--------- " );
	printf( "%-12s", "DIB Head:" );
	printf( "%u\n", info.size );
	printf( "%-12s", "Width:" );
	printf( "%u ( %x )\n", info.width, info.width );
	printf( "%-12s", "Height:" );
	printf( "%u ( %x )\n", info.height, info.height );
	printf( "%-12s", "Planes:" );
	printf( "%hu\n", info.planes );
	printf( "%-12s", "BPP:" );
	printf( "%hu\n", info.bpp );
	printf( "%-12s", "Compress:" );
	printf( "%u\n", info.compression );
	printf( "%-12s", "Img Size:" );
	printf( "%u\n", info.image_size );
	printf( "%-12s", "XPPM:" );
	printf( "%u\n", info.x_ppm );
	printf( "%-12s", "YPPM:" );
	printf( "%u\n", info.y_ppm );
	printf( "%-12s", "N Colors:" );
	printf( "%u\n", info.num_colors );
	printf( "%-12s", "I Colors:" );
	printf( "%u\n", info.important_colors );
	printf( "\n" );
}

void print_bmp_color( bmpcolor_t color ){
	printf( "\n" );
	printf( "%-12s", "Def" );
	printf( "%-12s\n", "Value" );
	printf( "%s", "----------- " );
	printf( "%s\n", "----------- " );
	printf( "%-12s", "RedMask:" );
	printf( "%x\n", color.rgbam.red );
	printf( "%-12s", "GreenMask:" );
	printf( "%x\n", color.rgbam.green );
	printf( "%-12s", "BlueMask:" );
	printf( "%x\n", color.rgbam.blue );
	printf( "%-12s", "AlphaMask:" );
	printf( "%x\n", color.rgbam.alpha );
	printf( "%-12s", "LCS:" );
	printf( "%x\n", color.lcs );
	printf( "%-12s", "RX:" );
	printf( "%u\n", color.xyz.ciexyz_red.ciexyz_x );
	printf( "%-12s", "RY:" );
	printf( "%u\n", color.xyz.ciexyz_red.ciexyz_y );
	printf( "%-12s", "RZ:" );
	printf( "%u\n", color.xyz.ciexyz_red.ciexyz_z );
	printf( "%-12s", "GX:" );
	printf( "%u\n", color.xyz.ciexyz_green.ciexyz_x );
	printf( "%-12s", "GY:" );
	printf( "%u\n", color.xyz.ciexyz_green.ciexyz_y );
	printf( "%-12s", "GZ:" );
	printf( "%u\n", color.xyz.ciexyz_green.ciexyz_z );
	printf( "%-12s", "BX:" );
	printf( "%u\n", color.xyz.ciexyz_blue.ciexyz_x );
	printf( "%-12s", "BY:" );
	printf( "%u\n", color.xyz.ciexyz_blue.ciexyz_y );
	printf( "%-12s", "BZ:" );
	printf( "%u\n", color.xyz.ciexyz_blue.ciexyz_z );
	printf( "%-12s", "Gamma R:" );
	printf( "%x\n", color.g.red );
	printf( "%-12s", "Gamma G:" );
	printf( "%x\n", color.g.green );
	printf( "%-12s", "Gamma B:" );
	printf( "%x\n", color.g.blue );
	printf( "\n" );
}

void print_bmp_profile( bmpprofile_t profile ){
	printf( "\n" );
	printf( "%-12s", "Def" );
	printf( "%-12s\n", "Value" );
	printf( "%s", "----------- " );
	printf( "%s\n", "----------- " );
	printf( "%-12s", "Intent:" );
	printf( "%x\n", profile.intent );
	printf( "%-12s", "DataOff:" );
	printf( "%u\n", profile.data );
	printf( "%-12s", "Size:" );
	printf( "%u\n", profile.size );
	printf( "%-12s", "Reserved:" );
	printf( "%u\n", profile.reserved );
	printf( "\n" );
}

void print_bmp( const bmp_v5_t bmp ){
	print_bmp_header( bmp.head );
	print_bmp_info( bmp.info );
	print_bmp_color( bmp.color );
	print_bmp_profile( bmp.profile );
}

uint16_t swap_uint16( uint16_t val ){
	return ( val << 8 ) | ( val >> 8 );
}

uint32_t swap_uint32( uint32_t val ){
    val = ( ( val << 8 ) & 0xFF00FF00 ) | ( ( val >> 8 ) & 0xFF00FF ); 
    return ( val << 16 ) | ( val >> 16 );
}

uint8_t bmp_offset_check( bmp_t bmp ){
	if( bmp.head.offset != ( sizeof( bmp.head ) + bmp.info.size ) ){
		return 1;
	}
	return 0;
}

uint8_t bmp_bpp_check( uint16_t bpp ){
	if( bpp == BITMAP_BPP_8  ||
		bpp == BITMAP_BPP_16 ||
		bpp == BITMAP_BPP_32 )
	{
		return 0;
	}

	return 1;
}

uint8_t bmp_size_check( bmpinfo_t info ){
	if( info.image_size != ( info.width * info.height ) * ( info.bpp/8 ) ){
		return 1;
	}
	return 0;
}

uint8_t bmp_compression_check( uint32_t compression ){
	if( compression == BI_RGB  ||
		compression == BI_RLE8 ||
		compression == BI_RLE4 ||
		compression == BI_BITFIELDS ||
		compression == BI_JPEG ||
		compression == BI_PNG  ||
		compression == BI_CMYK ||
		compression == BI_CMYKRLE8 ||
		compression == BI_CMYKRLE4 )
	{
		return 0;
	}

	return 1;
}


bmpheader_t bmp_header_null( void ){
	bmpheader_t head = {
		.type = 0,
		.size = 0,
		.reserved1 = 0,
		.reserved2 = 0,
		.offset = 0,
	};
	return head;
}

bmpinfo_t bmp_info_null( void ){
	bmpinfo_t info = {
		.size = 0,
		.width = 0,
		.height = 0,
		.planes = 0,
		.bpp = 0,
		.compression = 0,
		.image_size = 0,
		.x_ppm = 0,
		.y_ppm = 0,
		.num_colors = 0,
		.important_colors = 0,
	};
	return info;
}

bmpcolor_t bmp_color_null( void ){
	bmpcolor_t color = {
		.rgbam.red = 0,
		.rgbam.green = 0,
		.rgbam.blue = 0,
		.rgbam.alpha = 0,
		.lcs = 0,
		.xyz.ciexyz_red.ciexyz_x = 0,
		.xyz.ciexyz_red.ciexyz_y = 0,
		.xyz.ciexyz_red.ciexyz_z = 0,
		.xyz.ciexyz_green.ciexyz_x = 0,
		.xyz.ciexyz_green.ciexyz_y = 0,
		.xyz.ciexyz_green.ciexyz_z = 0,
		.xyz.ciexyz_blue.ciexyz_x = 0,
		.xyz.ciexyz_blue.ciexyz_y = 0,
		.xyz.ciexyz_blue.ciexyz_z = 0,
		.g.red = 0,
		.g.green = 0,
		.g.blue = 0,
	};
	return color;
}

bmp_t bmp_create_null( void ){
	bmp_t bmp;
	bmp.head = bmp_header_null(  );
	bmp.info = bmp_info_null (  );
	return bmp;
}

bmp_t bmp_create( uint32_t width, uint32_t height, uint16_t bpp, uint32_t compression ){

	bmp_t bmp;

	if( bmp_bpp_check( bpp ) ){
		fprintf( stderr, "\nError: unsoportted bpp ( %u )\n",
				 bpp );
		return bmp = bmp_create_null(  );
	}

	if( bmp_compression_check( compression ) ){
		fprintf( stderr, "\nError: unsoportted compression ( %x )\n",
				 compression );
		return bmp = bmp_create_null(  );
	}

	bmp.head.type = BITMAP_MAGIC;
	bmp.head.size = sizeof( bmpheader_t ) + sizeof( bmpinfo_t ) +
					( width * height * ( bpp >> 3 ) );
	bmp.head.reserved1 = 0;
	bmp.head.reserved2 = 0;
	bmp.head.offset = sizeof( bmpheader_t ) + sizeof( bmpinfo_t );
	bmp.info.size = sizeof( bmpinfo_t );
	bmp.info.width = width;
	bmp.info.height = height;
	bmp.info.planes = 1;
	bmp.info.bpp = bpp;
	bmp.info.compression = compression;
	bmp.info.image_size = width * height * ( bpp >> 3 );
	bmp.info.x_ppm = 0;
	bmp.info.y_ppm = 0;
	bmp.info.num_colors = 0;
	bmp.info.important_colors = 0;

	return bmp;
}

