#include "APRS.h"
#include <avr/pgmspace.h>

// This table goes up to 641.09 knots. This keeps it inside short ints.
const unsigned short speedTable[85] PROGMEM = {
	0, // 0
	8, // 1
	17, // 2
	26, // 3
	36, // 4
	47, // 5
	59, // 6
	71, // 7
	85, // 8
	100, // 9
	116, // 10
	133, // 11
	152, // 12
	172, // 13
	194, // 14
	217, // 15
	243, // 16
	270, // 17
	300, // 18
	332, // 19
	366, // 20
	403, // 21
	444, // 22
	487, // 23
	534, // 24
	585, // 25
	640, // 26
	699, // 27
	763, // 28
	832, // 29
	906, // 30
	987, // 31
	1074, // 32
	1168, // 33
	1269, // 34
	1379, // 35
	1497, // 36
	1625, // 37
	1763, // 38
	1912, // 39
	2072, // 40
	2246, // 41
	2434, // 42
	2637, // 43
	2856, // 44
	3092, // 45
	3347, // 46
	3623, // 47
	3921, // 48
	4243, // 49
	4590, // 50
	4965, // 51
	5371, // 52
	5808, // 53
	6281, // 54
	6791, // 55
	7343, // 56
	7938, // 57
	8581, // 58
	9276, // 59
	10026, // 60
	10836, // 61
	11711, // 62
	12655, // 63
	13676, // 64
	14778, // 65
	15968, // 66
	17254, // 67
	18642, // 68
	20141, // 69
	21761, // 70
	23509, // 71
	25398, // 72
	27438, // 73
	29641, // 74
	32020, // 75
	34590, // 76
	37365, // 77
	40363, // 78
	43600, // 79
	47095, // 80
	50871, // 81
	54949, // 82
	59353, // 83
	64109  // 84
};

static char buf[4];
const char *Base91::encode(unsigned long data) {
  buf[3] = 33 + data%91;
  data /= 91;
  buf[2] = 33 + data%91;
  data /= 91;
  buf[1] = 33 + data%91;
  data /= 91;
  buf[0] = 33 + data;
  return buf;
}  
