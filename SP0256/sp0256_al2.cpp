#include "sp0256_al2.h"

namespace sp0256_al2
{

	const char * labels[] = {
		"PA1",	"PA2",	"PA3",	"PA4",	"PA5",	"OY",	"AY",	"EH",
		"KK3",	"PP",	"JH",	"NN1",	"IH",	"TT2",	"RR1",	"AX",
		"MM",	"TT1",	"DH1",	"IY",	"EY",	"DD1",	"UW1",	"AO",
		"AA",	"YY2",	"AE",	"HH1",	"BB1",	"TH",	"UH",	"UW2",
		"AW",	"DD2",	"GG3",	"VV",	"GG1",	"SH",	"ZH",	"RR2",
		"FF",	"KK2",	"KK1",	"ZZ",	"NG",	"LL",	"WW",	"XR",
		"WH",	"YY1",	"CH",	"ER1",	"ER2",	"OW",	"DH2",	"SS",
		"NN2",	"HH2",	"OR",	"AR",	"YR",	"GG2",	"EL",	"BB2"
	};

	unsigned nlabels = sizeof( labels ) / sizeof( char * );

	/* ======================================================================== */
	/*  MASK table                                                              */
	/* ======================================================================== */
	static const uint8_t mask[4097] =
	{
		0xE0,0x7B,0xE0,0x07,0xE0,0x47,0xE0,0x27,0xE0,0x67,0xE0,0x97,0xE8,0x28,0xE8,0xFC,
		0xE8,0x32,0xE8,0xFA,0xE8,0x4E,0xE8,0x89,0xE8,0xB5,0xE8,0x5D,0xE8,0x4B,0xE8,0xF7,
		0xE8,0x3F,0xE4,0x08,0xE4,0xC4,0xE4,0xDC,0xE4,0xEE,0xE4,0x59,0xE4,0xD5,0xE4,0xFD,
		0xE4,0x33,0xE4,0xFB,0xEC,0xA8,0xEC,0x44,0xEC,0xDC,0xEC,0xCA,0xEC,0xBA,0xEC,0x56,
		0xEC,0x91,0xEC,0xC5,0xEC,0x9D,0xEC,0xF3,0xEC,0x8F,0xE2,0xE0,0xE2,0xE4,0xE2,0xDC,
		0xE2,0x5A,0xE2,0x26,0xE2,0xAE,0xE2,0xF1,0xE2,0x75,0xE2,0x63,0xE2,0x5B,0xE2,0x3F,
		0xEA,0x8C,0xEA,0x1A,0xEA,0x3E,0xEA,0xF1,0xEA,0x7B,0xE6,0xAC,0xE6,0x0A,0xE6,0x16,
		0xE6,0x4E,0xE6,0x15,0xE6,0xBD,0xE6,0xA7,0xEE,0xDC,0xEE,0x06,0xEE,0x6E,0xEE,0x19,
		0xE1,0x00,0xE1,0x40,0xE1,0x20,0xE1,0x60,0xE1,0x10,0xE1,0x50,0xE1,0x30,0xE1,0x70,
		0xE1,0x08,0xE1,0x48,0xE1,0x28,0xE1,0x68,0xE1,0x18,0xE1,0x58,0xE1,0x38,0xE1,0x78,
		0xE1,0x04,0xE1,0x44,0xE1,0x24,0xE1,0x64,0xE1,0x14,0xE1,0x54,0xE1,0x34,0xE1,0x74,
		0xE1,0x0C,0xE1,0x4C,0xE1,0x2C,0xE1,0x6C,0xE1,0x1C,0xE1,0x5C,0xE1,0x3C,0xE1,0x7C,
		0x08,0x00,0x04,0x00,0x0C,0x00,0x02,0x00,0x0A,0x00,0x06,0x00,0x0E,0x00,0x01,0x00,
		0x09,0x00,0x05,0x00,0x0D,0x00,0x03,0x00,0x0B,0x00,0x07,0x00,0x0F,0x00,0xF1,0x00,
		0xF4,0x00,0xF7,0x00,0xFF,0x00,0x1D,0xFF,0x00,0x10,0x33,0xE5,0x96,0xA9,0xAF,0x3F,
		0x43,0xB0,0x64,0xCA,0xA3,0xF6,0x47,0x55,0xB4,0xFE,0x29,0x8E,0xDA,0x1F,0x77,0x6D,
		0x51,0x75,0xF4,0x7E,0xA9,0xB3,0xE2,0x4F,0xD5,0x56,0xFD,0xA5,0xDA,0xCA,0x7F,0x16,
		0x49,0xFB,0x07,0x00,0x10,0x31,0xEE,0xD6,0xED,0xB3,0xBF,0x1A,0xA2,0x27,0xAA,0xCD,
		0xF6,0xCB,0xB9,0x5B,0x52,0xAD,0xCD,0x5F,0x8A,0xCD,0xFF,0x4A,0xB5,0x56,0xFF,0xA9,
		0xD7,0x7E,0x1E,0xE5,0x56,0xFE,0xA7,0x5A,0xDA,0x81,0x14,0x49,0x3D,0x00,0x00,0x18,
		0x36,0xFB,0x56,0x41,0x4B,0x91,0xF8,0x2C,0x9D,0x4C,0x15,0x00,0xF4,0x18,0x23,0x0D,
		0x00,0x3A,0x82,0x1F,0x6D,0xB9,0x84,0x01,0x18,0x04,0x84,0x88,0x15,0x03,0x00,0xFD,
		0x18,0x24,0x05,0x00,0x2A,0x96,0x7E,0xE7,0xD7,0x84,0x01,0x50,0x45,0xE4,0xEB,0x3C,
		0x03,0x00,0x18,0x24,0x15,0x00,0x29,0x21,0x03,0x46,0x9F,0xE6,0xDC,0xF2,0xA8,0xD1,
		0x11,0x00,0x06,0xE0,0x98,0xD3,0x94,0x5B,0x1D,0x2C,0x43,0xFD,0xA7,0x74,0x8B,0x6E,
		0x00,0x18,0x37,0xCF,0xD6,0x80,0x06,0x0F,0xFF,0x15,0x9C,0x2A,0x74,0xD2,0x00,0x92,
		0xB4,0x81,0x14,0x1E,0x32,0x03,0x00,0x01,0x00,0x20,0x5F,0x19,0x00,0x18,0x35,0xFB,
		0x56,0x81,0x44,0x0D,0xEB,0x8F,0xC6,0x0D,0x14,0x00,0xF5,0x18,0x23,0x1D,0x40,0x35,
		0xA7,0x23,0x84,0x9E,0xA4,0x02,0x20,0x46,0x74,0x4C,0xA9,0xCF,0x2E,0x78,0x07,0x9C,
		0x0E,0x00,0x18,0x35,0xC7,0x96,0xA7,0x71,0x39,0x0E,0x1E,0x64,0x45,0x66,0xAA,0x9A,
		0xB8,0xC7,0x79,0x5B,0x52,0x2D,0xC5,0x3E,0xEA,0xA4,0xD7,0xCB,0xB1,0x5B,0x00,0x18,
		0x36,0xFB,0x56,0xBD,0x86,0x0B,0xD3,0x0C,0x25,0x0C,0x15,0x00,0x10,0x36,0xDD,0x56,
		0xFD,0xB0,0xB8,0x00,0x22,0xA4,0xCE,0xDB,0xAA,0xFA,0x3C,0xCF,0x74,0xE5,0x16,0x00,
		0xF6,0x18,0x21,0x14,0x40,0x42,0x20,0xE2,0xE7,0xBB,0xA4,0x01,0x98,0x04,0xA4,0xFC,
		0xA0,0x03,0x00,0x18,0x3C,0xDD,0xD6,0xC2,0x06,0x8F,0xED,0x97,0x1A,0x64,0x79,0xA6,
		0xDD,0x32,0xE8,0xE8,0x89,0xFE,0x75,0x73,0x85,0x02,0x00,0x18,0x33,0xFB,0x16,0x02,
		0x0B,0x0F,0x07,0x33,0x5E,0x2B,0x74,0x66,0xDF,0x62,0xE1,0x41,0xD0,0x20,0xD6,0x5F,
		0x91,0xCA,0xEC,0x5B,0x09,0x2D,0x3C,0x19,0xC8,0x7A,0x31,0xCD,0xC9,0x05,0x01,0x00,
		0x18,0x3C,0x08,0xA7,0x74,0x10,0x00,0x41,0x3D,0x00,0x71,0x9A,0x72,0x8B,0x81,0x85,
		0x87,0x7D,0x43,0x1F,0x07,0x09,0x00,0x10,0x33,0xEE,0xD6,0xA9,0xBB,0x80,0x05,0x29,
		0x25,0xCA,0xA5,0x1E,0xCC,0xB5,0x5B,0x51,0xE7,0xFC,0xBF,0xEA,0x9C,0x1F,0xC4,0x9D,
		0x5B,0x56,0x9D,0xFC,0x40,0xEA,0x92,0xFF,0x03,0x00,0x18,0x33,0xED,0xD6,0xE5,0xB9,
		0x81,0x10,0xAB,0x23,0x49,0x47,0x8A,0x9D,0x1C,0x00,0x00,0x18,0x33,0xF5,0x96,0xA7,
		0xBD,0xF7,0x1E,0xA7,0x84,0x25,0x47,0xAA,0xD6,0x9E,0x4A,0xD1,0x3E,0x53,0x00,0x18,
		0x38,0xF4,0x56,0x89,0xC6,0x10,0xFB,0x30,0x58,0x4B,0x16,0x00,0x18,0x33,0xF5,0x96,
		0xB3,0xAF,0x7F,0x15,0x9B,0x23,0x88,0x48,0xAE,0xDE,0x92,0xAA,0x6F,0xFE,0x00,0x18,
		0x33,0xE7,0x56,0x05,0xCB,0x8C,0x09,0x32,0x1E,0xCE,0x51,0xF2,0x01,0x10,0x20,0xFF,
		0x0E,0xE3,0x29,0x0F,0xF8,0xC7,0xBF,0x78,0xD0,0x24,0xF2,0x00,0x92,0x2B,0xF7,0xFF,
		0x5C,0x66,0xEE,0x2D,0x12,0x96,0x8C,0x04,0x60,0x7C,0x1A,0x66,0x24,0x81,0x1F,0x40,
		0x00,0x0F,0x9F,0x00,0x00,0x18,0x39,0xEE,0x16,0x7F,0x49,0x0D,0xF1,0xA6,0xDB,0xCC,
		0x15,0x00,0x18,0x26,0x07,0x40,0x25,0x27,0x81,0x61,0xDD,0x84,0x02,0xB8,0xE6,0x33,
		0x68,0xC4,0x8B,0x14,0x00,0x86,0xE4,0xF5,0x9F,0x01,0x00,0x18,0x33,0xC1,0xD6,0x3E,
		0xC7,0x10,0xE5,0x02,0xC3,0x0E,0x31,0xC6,0xDD,0x2A,0xC9,0xA0,0x79,0x5F,0x87,0xB3,
		0x61,0x02,0x00,0x19,0x24,0x0D,0x80,0x31,0x12,0x62,0xA7,0x1C,0x00,0x18,0x38,0xED,
		0xD6,0x7F,0x49,0x4B,0xC3,0x03,0xC3,0x8B,0x14,0x00,0x18,0x38,0xED,0x96,0xBD,0x07,
		0x09,0xDB,0x06,0x24,0xAC,0x93,0xC6,0xDD,0xEA,0x28,0xD9,0x61,0x7E,0x46,0x4F,0x99,
		0x5E,0x3A,0x08,0x90,0x04,0xE0,0xEE,0x2E,0x00,0x10,0x38,0xE7,0x96,0xAF,0x75,0x3F,
		0x0D,0x22,0xA4,0x8A,0xB4,0xF9,0x53,0x75,0x16,0x7F,0x2A,0xAE,0x62,0x70,0xD5,0xD0,
		0x0B,0x00,0x00,0xF4,0x18,0x23,0x0F,0x00,0x29,0x99,0x62,0xE4,0x7C,0xC6,0xDE,0xEA,
		0x28,0x19,0x62,0x3F,0x97,0x77,0x75,0x02,0x00,0xF8,0x18,0x25,0x0F,0x40,0x32,0xA1,
		0x5E,0x45,0x7D,0xA6,0xDC,0x1A,0xA9,0xC9,0x68,0x9F,0xA5,0xA3,0x71,0x02,0x00,0x18,
		0x36,0xCC,0xD6,0x42,0x0B,0x55,0xF2,0x34,0xF9,0x08,0xD5,0xE6,0xDB,0xA2,0x60,0xA9,
		0x42,0xBE,0x41,0xEB,0x78,0xCB,0x94,0x5B,0xF6,0x1C,0x24,0x4D,0x33,0x96,0x92,0x63,
		0x00,0xF4,0x18,0x23,0x0C,0x80,0x15,0xF8,0x3F,0x68,0x7F,0xE6,0xDD,0xA2,0x30,0xD9,
		0x31,0xFF,0xD5,0x73,0x85,0x02,0x00,0x18,0x26,0x04,0x80,0x1E,0x87,0x81,0x6B,0x7F,
		0xC4,0x02,0x98,0x24,0x64,0x58,0xE9,0x67,0xC8,0x16,0xC0,0x13,0x14,0x41,0x52,0x01,
		0x4C,0x72,0x21,0x98,0xF0,0x01,0x00,0x10,0x37,0xE5,0xD6,0x30,0xB9,0xFF,0x16,0xA4,
		0x04,0x63,0x85,0x03,0x00,0x20,0x84,0xFC,0xF8,0x03,0x00,0x18,0x32,0xCF,0x16,0xC3,
		0xC8,0x4E,0xDE,0xAC,0x97,0x8A,0x74,0xC6,0xDA,0xB2,0xBE,0x18,0xE1,0x97,0x70,0x74,
		0x85,0x52,0x1E,0x38,0x0E,0x1D,0x30,0xF1,0x05,0x00,0x19,0x21,0x0F,0xC0,0x29,0x94,
		0xE0,0x64,0x1C,0x00,0x1D,0xF2,0x18,0x21,0x0F,0x80,0x35,0x89,0xC0,0xCA,0x5B,0xB6,
		0xC0,0xDD,0x78,0x7A,0x00,0xF7,0x18,0x21,0x1D,0xC0,0x31,0xB1,0xE1,0x46,0x3C,0xE4,
		0x00,0xA0,0x65,0x43,0x10,0xE5,0xA7,0x54,0x00,0xB5,0x88,0x86,0x8D,0x73,0x00,0x18,
		0x36,0xF4,0x56,0x89,0x51,0xD7,0x02,0xAA,0xBB,0xE9,0x34,0xC5,0x02,0xD8,0x08,0xB0,
		0xC3,0x84,0xD0,0xD4,0x5B,0x25,0x45,0x4C,0x08,0xC0,0xEE,0x9B,0x5C,0x00,0x18,0x35,
		0xEF,0x16,0x37,0x2F,0xFF,0x06,0x9E,0x45,0xAB,0x6A,0x8A,0xF5,0x76,0x5B,0x9D,0xD6,
		0x6F,0xAC,0xD2,0x5B,0x0D,0x00,0x18,0x33,0xDE,0x96,0xA7,0x33,0x83,0x19,0x22,0xA5,
		0xC4,0x65,0xAA,0xA5,0x39,0x4C,0xB1,0x14,0x03,0x00,0x18,0x35,0xCD,0x96,0x3E,0xC7,
		0xCA,0xC1,0x7C,0x42,0x0B,0xB4,0xE6,0xD9,0x5A,0x30,0xE1,0x89,0x1F,0xC5,0x7E,0x79,
		0xDA,0x54,0x5B,0x05,0x1E,0x25,0xAE,0x06,0x0A,0xB9,0x49,0x00,0x18,0x33,0xED,0x96,
		0xA9,0xBB,0xBF,0x00,0xA9,0x23,0x4B,0x48,0xAE,0xDD,0x92,0x3A,0x69,0xF7,0x52,0x2D,
		0xE5,0x5E,0xCA,0xAD,0xDC,0x4B,0xB5,0x75,0xF7,0x39,0x76,0x2B,0xEE,0xDC,0x9A,0xFA,
		0xAA,0xE6,0x51,0x1C,0xD5,0x5C,0xCA,0xAB,0xBA,0xC7,0x5D,0x5B,0x53,0x55,0xDD,0x1D,
		0x00,0x18,0x26,0x03,0x00,0x21,0x8E,0x1F,0x45,0x7A,0x65,0x00,0xB8,0x84,0x11,0x54,
		0xD1,0xCA,0x78,0x5B,0xFC,0x37,0x22,0x17,0xFB,0x89,0xAE,0x51,0x99,0x72,0xCB,0xBF,
		0xA5,0xA5,0xD9,0xC1,0x81,0x35,0x0A,0x00,0x18,0x33,0xE7,0x56,0x05,0xCB,0x8C,0x09,
		0x32,0x1E,0xCE,0x51,0xF2,0x01,0x10,0x20,0xFF,0x0E,0xE3,0x29,0x0F,0xF8,0xC7,0xBF,
		0x78,0xD0,0x24,0xF2,0x00,0x92,0x2B,0xF7,0xFF,0x5C,0x00,0x00,0xF5,0x18,0x25,0x05,
		0x00,0x2A,0x27,0x21,0x83,0xBC,0xA5,0x02,0xD0,0x66,0x46,0x24,0xD9,0x03,0x00,0x18,
		0x31,0xED,0x16,0x07,0x89,0x0C,0xE7,0xB4,0xF9,0xAB,0x54,0x12,0x00,0x00,0xFC,0x07,
		0x0E,0x00,0x62,0xDA,0x2D,0x73,0x0E,0x12,0xA6,0x13,0xC9,0x16,0x6A,0xE4,0x03,0x20,
		0x40,0x00,0xFC,0x68,0x47,0x2E,0x00,0x02,0x20,0x00,0xE0,0x85,0x64,0x01,0xE0,0x00,
		0x0E,0x14,0xA8,0x47,0x26,0x00,0x02,0x20,0xC1,0x5E,0xBC,0xCC,0xB7,0xE5,0x21,0x12,
		0xC2,0x38,0xAD,0x76,0x03,0x8D,0x2C,0x00,0xE0,0x11,0x22,0xA0,0x0E,0x00,0x18,0x32,
		0xED,0x16,0x07,0x89,0x0C,0xE7,0xB4,0xF9,0xAB,0x54,0x12,0x00,0x00,0xFC,0x07,0x0E,
		0x00,0x64,0xD8,0x2D,0x73,0x0E,0x16,0xA6,0x11,0x49,0x56,0xAA,0x24,0x00,0x00,0xC0,
		0x01,0x01,0xE2,0x4B,0x2E,0x00,0x02,0x04,0xC0,0x8F,0xB6,0x24,0x00,0x20,0x00,0x02,
		0x00,0x5E,0x48,0x02,0x00,0x0E,0xE0,0x40,0x81,0xFA,0xA4,0x03,0x20,0x00,0x12,0xEC,
		0xC5,0xCF,0x78,0x5B,0x1E,0x22,0x21,0x8C,0xD3,0x6A,0x37,0xD0,0xC9,0x00,0x00,0x1E,
		0x21,0x02,0xEA,0x00,0x00,0x10,0x33,0xED,0x96,0xAB,0xB1,0x3F,0x43,0xB0,0x64,0x8A,
		0xAD,0x18,0xC4,0x9D,0x5B,0x55,0x1E,0xBD,0x20,0xCE,0xDB,0xB2,0xBB,0xB6,0x00,0x00,
		0x19,0x31,0xDD,0xD6,0xC2,0x06,0x8F,0xED,0x97,0x1A,0x64,0x79,0xA6,0xDD,0x32,0xE8,
		0xE8,0x89,0xFE,0x75,0x73,0x85,0x02,0x00,0x18,0x2A,0x17,0x00,0x4A,0x1C,0x24,0x65,
		0x1C,0x00,0x18,0x34,0xDD,0xD6,0x80,0x06,0x0F,0xFF,0x15,0x9C,0x2A,0x54,0x32,0x00,
		0x92,0xB4,0x81,0x14,0x1E,0x24,0x0B,0x00,0x01,0x00,0x20,0x5F,0x79,0x66,0xDF,0xA2,
		0xE0,0x98,0x69,0x3F,0x76,0x43,0xA1,0x46,0x02,0x30,0x80,0x00,0x60,0x5E,0xC8,0x24,
		0x80,0xA9,0x00,0x02,0xFE,0x03,0x00,0x00,0x18,0x2E,0x03,0x80,0x21,0x0F,0x00,0x29,
		0x98,0xC6,0xDB,0x22,0x30,0xE9,0x19,0xBD,0x80,0x27,0x09,0x03,0x00,0x18,0x32,0xD6,
		0x96,0xA9,0xAB,0x3F,0x11,0x30,0xE4,0xEA,0x26,0x8A,0xA2,0xD5,0xCF,0x55,0x5B,0x53,
		0x1F,0xB5,0xBE,0xAA,0xA4,0xB8,0x53,0x9D,0x35,0x73,0xAA,0xB3,0x6A,0x1E,0xF5,0x51,
		0xCD,0xE7,0xAC,0x2D,0x00,0x18,0x32,0xE4,0x96,0x07,0x0B,0x44,0xF2,0xB2,0x37,0x8B,
		0x55,0x32,0x00,0x8E,0x27,0x80,0x87,0x3E,0x24,0x03,0x1C,0x07,0x82,0xF7,0x00,0x41,
		0xA6,0xDC,0xAA,0xB7,0x28,0x61,0x38,0x40,0x44,0xD9,0x4A,0x02,0xC8,0x11,0x04,0xF1,
		0x9D,0xC5,0x4C,0xB9,0xE5,0x01,0x31,0xB2,0x7A,0x4C,0xA6,0xAA,0x9D,0xF9,0xB6,0x00,
		0x3C,0x6A,0x38,0x67,0xCD,0x56,0xB5,0x93,0x0F,0x00,0xE0,0x07,0x48,0x8C,0x3E,0xC3,
		0x6D,0xB9,0x5B,0x88,0xF0,0xEC,0x0F,0xAA,0x64,0x01,0x00,0x18,0x33,0xEF,0xD6,0x65,
		0xFD,0xC0,0x04,0x27,0x25,0x28,0x47,0x8A,0x96,0x1F,0xCC,0xD5,0x5B,0x52,0xAD,0xF4,
		0x60,0xAA,0x9D,0xFD,0x53,0x99,0x94,0xFB,0x2A,0x93,0x6E,0x5F,0x57,0x6E,0x01,0x00,
		0xF4,0x18,0x24,0x07,0xC0,0x21,0x20,0x9C,0xC3,0x5C,0xC6,0xDC,0xE2,0xF7,0xE8,0x19,
		0xDF,0x65,0xC3,0x85,0x02,0x00,0x18,0x35,0xEE,0x16,0x47,0x8B,0x48,0xFF,0xB0,0x98,
		0x6C,0x74,0xC6,0xDC,0x8A,0x70,0xE1,0xE1,0x3F,0x06,0x83,0x8D,0xDE,0x90,0x5B,0x2E,
		0x19,0x33,0x0C,0xC0,0x60,0x34,0x50,0x00,0xF4,0x18,0x21,0x06,0x80,0x21,0x92,0x7F,
		0xC8,0x5B,0xA6,0xDE,0x2A,0xA1,0xC9,0x68,0xFF,0x86,0xB3,0x65,0x02,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	};

}
