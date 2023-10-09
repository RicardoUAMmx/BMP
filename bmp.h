
struct pixel {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} __attribute__((__packed__));

typedef struct pixel pixel_t;

/* Source: https://en.wikipedia.org/wiki/BMP_file_format */
struct bmpdib_h {
	/* BMP HEader */
    uint16_t type;              // "BM" (0x42, 0x4D)
    uint32_t size;              // file size
    uint16_t reserved1;         // not used (0)
    uint16_t reserved2;         // not used (0)
    uint32_t offset;            // offset to image data (54B)
	/* DIB HEader */
    uint32_t dib_size;          // DIB header size (40B)
    uint32_t width;             // width in pixels
    uint32_t height;            // height in pixels
    uint16_t planes;            // 1
    uint16_t bpp;               // bits per pixel (24)
    uint32_t compression;       // compression type (0/1/2) 0
    uint32_t image_size;        // size of picture in bytes, 0
    uint32_t x_ppm;             // X Pixels per meter (0)
    uint32_t y_ppm;             // X Pixels per meter (0)
    uint32_t num_colors;        // number of colors (0)
    uint32_t important_colors;  // important colors (0)
} __attribute__((__packed__));

typedef struct bmpdib_h bmpdib_t;

// pixel_t read_data(FILE* stream, const bmpdib_t* header);
void print_bmp_header( const bmpdib_t* header );

