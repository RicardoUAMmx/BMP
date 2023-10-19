#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "bmp.h"

void print_bmp_header( const bmpheader_t* header ){
	printf( "\n" );
	printf( "%-12s", "Def" );
	printf( "%-12s\n", "Value" );
	printf( "%s", "--------- " );
	printf( "%s\n", "--------- " );
	printf( "%-12s", "Kind:" );
	printf( "%s\n", ( char * )&header->type );
	printf( "%-12s", "Size:" );
	printf( "%u\n", header->size );
	printf( "%-12s", "Offset:" );
	printf( "%u\n", header->offset );
	printf( "\n" );
}

void print_bmp_info( const bmpinfo_t* info ){
	printf( "\n" );
	printf( "%-12s", "Def" );
	printf( "%-12s\n", "Value" );
	printf( "%s", "--------- " );
	printf( "%s\n", "--------- " );
	printf( "%-12s", "DIB Head:" );
	printf( "%u\n", info->size );
	printf( "%-12s", "Width:" );
	printf( "%u\n", info->width );
	printf( "%-12s", "Height:" );
	printf( "%u\n", info->height );
	printf( "%-12s", "Planes:" );
	printf( "%hu\n", info->planes );
	printf( "%-12s", "BPP:" );
	printf( "%hu\n", info->bpp );
	printf( "%-12s", "Compress:" );
	printf( "%u\n", info->compression );
	printf( "%-12s", "Img Size:" );
	printf( "%u\n", info->image_size );
	printf( "%-12s", "XPPM:" );
	printf( "%u\n", info->x_ppm );
	printf( "%-12s", "YPPM:" );
	printf( "%u\n", info->y_ppm );
	printf( "%-12s", "N Colors:" );
	printf( "%u\n", info->num_colors );
	printf( "%-12s", "I Colors:" );
	printf( "%u\n", info->important_colors );
	printf( "\n" );
}

void print_bmp_color( const bmpcolor_t* color ){
	printf( "\n" );
	printf( "%-12s", "Def" );
	printf( "%-12s\n", "Value" );
	printf( "%s", "----------- " );
	printf( "%s\n", "----------- " );
	printf( "%-12s", "RedMask:" );
	printf( "%x\n", color->rgbam.red );
	printf( "%-12s", "GreenMask:" );
	printf( "%x\n", color->rgbam.green );
	printf( "%-12s", "BlueMask:" );
	printf( "%x\n", color->rgbam.blue );
	printf( "%-12s", "AlphaMask:" );
	printf( "%x\n", color->rgbam.alpha );
	printf( "%-12s", "LCS:" );
	printf( "%s\n", ( char * )&color->lcs );
	printf( "%-12s", "RX:" );
	printf( "%u\n", color->xyz.ciexyz_red.ciexyz_x );
	printf( "%-12s", "RY:" );
	printf( "%u\n", color->xyz.ciexyz_red.ciexyz_y );
	printf( "%-12s", "RZ:" );
	printf( "%u\n", color->xyz.ciexyz_red.ciexyz_z );
	printf( "%-12s", "GX:" );
	printf( "%u\n", color->xyz.ciexyz_green.ciexyz_x );
	printf( "%-12s", "GY:" );
	printf( "%u\n", color->xyz.ciexyz_green.ciexyz_y );
	printf( "%-12s", "GZ:" );
	printf( "%u\n", color->xyz.ciexyz_green.ciexyz_z );
	printf( "%-12s", "BX:" );
	printf( "%u\n", color->xyz.ciexyz_blue.ciexyz_x );
	printf( "%-12s", "BY:" );
	printf( "%u\n", color->xyz.ciexyz_blue.ciexyz_y );
	printf( "%-12s", "BZ:" );
	printf( "%u\n", color->xyz.ciexyz_blue.ciexyz_z );
	printf( "%-12s", "Gamma R:" );
	printf( "%x\n", color->g.red );
	printf( "%-12s", "Gamma G:" );
	printf( "%x\n", color->g.green );
	printf( "%-12s", "Gamma B:" );
	printf( "%x\n", color->g.blue );
	printf( "\n" );
}

void print_bmp_profile( const bmpprofile_t* profile ){
	printf( "\n" );
	printf( "%-12s", "Def" );
	printf( "%-12s\n", "Value" );
	printf( "%s", "----------- " );
	printf( "%s\n", "----------- " );
	printf( "%-12s", "Intent:" );
	printf( "%s\n", ( char * )&profile->intent );
	printf( "%-12s", "DataOff:" );
	printf( "%u\n", profile->data );
	printf( "%-12s", "Size:" );
	printf( "%u\n", profile->size );
	printf( "%-12s", "Reserved:" );
	printf( "%u\n", profile->reserved );
	printf( "\n" );
}


