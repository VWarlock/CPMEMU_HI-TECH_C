/* Standard Banking Library (BLSTD.H)*/

#asm
psect	text,global
psect	data,global
psect	bss,global
#endasm

typedef char int8_t;
typedef short int16_t;
typedef long int32_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;

/* bl_bank is defined at each bank (Number is set 0,1,2,3... ) */
extern int16_t bl_bank;

/* Get OVL info */
void bl_get_ovl_info(char *name, short *bank_max);

/* Get BANK info */
#define bl_get_bank_info()	bl_get_seg_info(bl_bank)
uint16_t bl_get_seg_info(short bank);

/* Set TSR mode */
void bl_tsr_on(void);
void bl_tsr_off(void);
int8_t bl_is_tsr_on(void);

#define BL_RANDOM_MAX	0x10000
#define BL_RANDOM_MASK	0xFFFF
uint16_t bl_random(void);

/* Shared heap */
void *bl_calloc(uint16_t num, uint16_t size);
void bl_free(void *ptr);
void *bl_malloc(uint16_t size);
void *bl_realloc(void *ptr, uint16_t size);
void *bl_get_memtop(void);

