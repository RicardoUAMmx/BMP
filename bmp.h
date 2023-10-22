
#define BITMAP_MAGIC 0x424D
#define BITMAP_LCS 0x4D424544
#define BITMAP_BPP_1 0x0001
#define BITMAP_BPP_2 0x0002
#define BITMAP_BPP_4 0x0004
#define BITMAP_BPP_8 0x0008
#define BITMAP_BPP_16 0x0010
#define BITMAP_BPP_32 0x0020

struct bmpheader {
    uint16_t type;              // "BM" (0x42, 0x4D)
    uint32_t size;              // file size
    uint16_t reserved1;         // not used (0)
    uint16_t reserved2;         // not used (0)
    uint32_t offset;            // offset to image data (54B)
} __attribute__((__packed__));
typedef struct bmpheader bmpheader_t;

struct bmpinfo {
    uint32_t size;          // DIB header size (40B)
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
typedef struct bmpinfo bmpinfo_t;

struct rgba_mask {
	uint32_t red;
	uint32_t green;
	uint32_t blue;
	uint32_t alpha;
} __attribute__((__packed__));
typedef struct rgba_mask rgba_mask_t;

typedef uint32_t ciexyz1616_t;

struct ciexyz {
	ciexyz1616_t ciexyz_x;
	ciexyz1616_t ciexyz_y;
	ciexyz1616_t ciexyz_z;
} __attribute__((__packed__));
typedef struct ciexyz ciexyz_t;

struct ciexyztriple {
	ciexyz_t ciexyz_red;
	ciexyz_t ciexyz_green;
	ciexyz_t ciexyz_blue;
} __attribute__((__packed__));
typedef struct ciexyztriple ciexyztriple_t;

struct gamma {
	uint32_t red;
	uint32_t green;
	uint32_t blue;
} __attribute__((__packed__));
typedef struct gamma gamma_t;

struct bmpcolor {
	rgba_mask_t rgbam;
	uint32_t lcs;
	ciexyztriple_t xyz;
	gamma_t g;
} __attribute__((__packed__));
typedef struct bmpcolor bmpcolor_t;

struct bmpprofile {
	uint32_t intent;
	uint32_t data;
	uint32_t size;
	uint32_t reserved;
} __attribute__((__packed__));
typedef struct bmpprofile bmpprofile_t;

struct bmp {
	bmpheader_t head;
	bmpinfo_t info;
	bmpcolor_t color;
	bmpprofile_t profile;
} __attribute__((__packed__));
typedef struct bmp bmp_t;

void print_bmp_header( const bmpheader_t* header );
void print_bmp_info( const bmpinfo_t* info );
void print_bmp_color( const bmpcolor_t* color );
void print_bmp_profile( const bmpprofile_t* profile );
void print_bmp( const bmp_t bmp );

uint16_t swap_uint16( uint16_t val );
uint32_t swap_uint32( uint32_t val );

uint8_t bmp_offset_check( bmp_t bmp );
uint16_t bmp_bpp_check( uint16_t bpp );
uint8_t bmp_size_check( bmpinfo_t info );
