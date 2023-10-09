#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "bmp.h"

// pixel_t read_data(FILE* stream, const bmpdib_t* header){
// 	if(stream == NULL || header == NULL){
// 		return 0;
// 	}
// 	// w == 1 && p == 1;   w == 2 && p == 2;   w == 3 && p == 3;   w == 4 && p == 0  
// 	int padding = header->(4-((3*width)%4))%4;
// 	int num_of_pixels = header->width * header->height;
// 	pixel_t* Pixel[num_of_pixels];
// 
// 	fseek(stream, 54, SEEK_SET); //move 54B (header size)
// 	int index_p = 0;
// 	for(int i = 0; i < header->height; i++){
// 		for(int j = 0; j < header->width; j++){
// 			Pixel[index_p] = malloc(sizeof(pixel_t));
// 			fread(&(Pixel[index_p]->blue), 1, 1, stream); 
// 			fread(&(Pixel[index_p]->green), 1, 1, stream); 
// 			fread(&(Pixel[index_p]->red), 1, 1, stream); 
// 			index_p++;
// 		}
// 		fseek(stream, padding, SEEK_CUR);  //padding at the end of row
// 	}
// 	return *Pixel;
// }

void print_bmp_header( const bmpdib_t* header ){
	printf( "\n" );
	printf( "%-10s", "Def" );
	printf( "%-10s\n", "Value" );
	printf( "%s", "--------- " );
	printf( "%s\n", "--------- " );
	printf( "%-10s", "Kind:" );
	printf( "%s\n", ( char * )&header->type );
	printf( "%-10s", "Size:" );
	printf( "%u\n", header->size );
	printf( "%-10s", "Offset:" );
	printf( "%u\n", header->offset );
	printf( "%-10s", "DIB Head:" );
	printf( "%u\n", header->dib_size );
	printf( "%-10s", "Width:" );
	printf( "%u\n", header->width );
	printf( "%-10s", "Height:" );
	printf( "%u\n", header->height );
	printf( "%-10s", "Planes:" );
	printf( "%hu\n", header->planes );
	printf( "%-10s", "BPP:" );
	printf( "%hu\n", header->bpp );
	printf( "%-10s", "Compress:" );
	printf( "%u\n", header->compression );
	printf( "%-10s", "Img Size:" );
	printf( "%u\n", header->image_size );
	printf( "%-10s", "XPPM:" );
	printf( "%u\n", header->x_ppm );
	printf( "%-10s", "YPPM:" );
	printf( "%u\n", header->y_ppm );
	printf( "%-10s", "N Colors:" );
	printf( "%u\n", header->num_colors );
	printf( "%-10s", "I Colors:" );
	printf( "%u\n", header->important_colors );
}
