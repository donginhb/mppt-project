#include <stdio.h>


uint16_t crcTable[256];
uint16_t remain;

void crc16_init(void);
uint16_t crc16(uint8_t[]);

void crc16_init(void) {

	uint16_t poly = 0x1021;
	uint8_t i;
	uint8_t bit;
	
	for (i=0; i<256; i++) {

		remain = (i << 8) & 0xffff;

		for (bit=8; bit>0; bit--) {

			if (remain & (1 << 15) )
				remain = (remain << 1) ^ poly;
			else
				remain = remain << 1;

			remain &= 0xffff;
		}
		crcTable[i] = remain;
	}
}

uint16_t crc16(uint8_t data[]) {

	uint8_t i;
	uint8_t byte;

	remain = 0;
 
	for (i=0; i<8; i++) {

		byte = data[i] ^ (remain >> 8);
		remain = crcTable[byte] ^ (remain << 8);
		remain &= 0xffff;
	}

	return remain;

}


