//-----------------------------------------------------------------------------------------------
// Mpeg12LibTab.h
// Copyright (C) 2013 Dumonteil David
//
// MFNode is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// MFNode is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// This program use lipmp2dec and mpeg123 source code :
// https://sourceforge.net/projects/libmp2codec/
// http://www.mpg123.de/
//----------------------------------------------------------------------------------------------
#ifndef MPEG12LIBTAB_H
#define MPEG12LIBTAB_H

const unsigned short mpa_bitrate_tab[2][3][15] = {
    { {0, 32, 64, 96, 128, 160, 192, 224, 256, 288, 320, 352, 384, 416, 448 },
      {0, 32, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320, 384 },
      {0, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320 } },
    { {0, 32, 48, 56, 64, 80, 96, 112, 128, 144, 160, 176, 192, 224, 256},
      {0, 8, 16, 24, 32, 40, 48, 56, 64, 80, 96, 112, 128, 144, 160},
      {0, 8, 16, 24, 32, 40, 48, 56, 64, 80, 96, 112, 128, 144, 160}
    }
};

const unsigned short mpa_freq_tab[3] = { 44100, 48000, 32000 };

// half mpeg encoding window (full precision)
const int mpa_enwindow[257] = {
     0,    -1,    -1,    -1,    -1,    -1,    -1,    -2,
    -2,    -2,    -2,    -3,    -3,    -4,    -4,    -5,
    -5,    -6,    -7,    -7,    -8,    -9,   -10,   -11,
   -13,   -14,   -16,   -17,   -19,   -21,   -24,   -26,
   -29,   -31,   -35,   -38,   -41,   -45,   -49,   -53,
   -58,   -63,   -68,   -73,   -79,   -85,   -91,   -97,
  -104,  -111,  -117,  -125,  -132,  -139,  -147,  -154,
  -161,  -169,  -176,  -183,  -190,  -196,  -202,  -208,
   213,   218,   222,   225,   227,   228,   228,   227,
   224,   221,   215,   208,   200,   189,   177,   163,
   146,   127,   106,    83,    57,    29,    -2,   -36,
   -72,  -111,  -153,  -197,  -244,  -294,  -347,  -401,
  -459,  -519,  -581,  -645,  -711,  -779,  -848,  -919,
  -991, -1064, -1137, -1210, -1283, -1356, -1428, -1498,
 -1567, -1634, -1698, -1759, -1817, -1870, -1919, -1962,
 -2001, -2032, -2057, -2075, -2085, -2087, -2080, -2063,
  2037,  2000,  1952,  1893,  1822,  1739,  1644,  1535,
  1414,  1280,  1131,   970,   794,   605,   402,   185,
   -45,  -288,  -545,  -814, -1095, -1388, -1692, -2006,
 -2330, -2663, -3004, -3351, -3705, -4063, -4425, -4788,
 -5153, -5517, -5879, -6237, -6589, -6935, -7271, -7597,
 -7910, -8209, -8491, -8755, -8998, -9219, -9416, -9585,
 -9727, -9838, -9916, -9959, -9966, -9935, -9863, -9750,
 -9592, -9389, -9139, -8840, -8492, -8092, -7640, -7134,
  6574,  5959,  5288,  4561,  3776,  2935,  2037,  1082,
    70,  -998, -2122, -3300, -4533, -5818, -7154, -8540,
 -9975,-11455,-12980,-14548,-16155,-17799,-19478,-21189,
-22929,-24694,-26482,-28289,-30112,-31947,-33791,-35640,
-37489,-39336,-41176,-43006,-44821,-46617,-48390,-50137,
-51853,-53534,-55178,-56778,-58333,-59838,-61289,-62684,
-64019,-65290,-66494,-67629,-68692,-69679,-70590,-71420,
-72169,-72835,-73415,-73908,-74313,-74630,-74856,-74992,
 75038,
};

// layer 2 tables
const int sblimit_table[5] = { 27 , 30 , 8, 12 , 30 };

const int quant_steps[17] = {
    3,     5,    7,    9,    15,
    31,    63,  127,  255,   511,
    1023,  2047, 4095, 8191, 16383,
    32767, 65535
};

// we use a negative value if grouped
const int quant_bits[17] = {
    -5,  -7,  3, -10, 4, 
     5,  6,  7,  8,  9,
    10, 11, 12, 13, 14,
    15, 16 
};

// encoding tables which give the quantization index. Note how it is possible to store them efficiently !
static const unsigned char alloc_table_0[] = {
 4,  0,  2,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 
 4,  0,  2,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 
 4,  0,  2,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 
 4,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 16, 
 4,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 16, 
 4,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 16, 
 4,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 16, 
 4,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 16, 
 4,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 16, 
 4,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 16, 
 4,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 2,  0,  1, 16, 
 2,  0,  1, 16, 
 2,  0,  1, 16, 
 2,  0,  1, 16, 
};

static const unsigned char alloc_table_1[] = {
 4,  0,  2,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 
 4,  0,  2,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 
 4,  0,  2,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 
 4,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 16, 
 4,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 16, 
 4,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 16, 
 4,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 16, 
 4,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 16, 
 4,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 16, 
 4,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 16, 
 4,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 3,  0,  1,  2,  3,  4,  5, 16, 
 2,  0,  1, 16, 
 2,  0,  1, 16, 
 2,  0,  1, 16, 
 2,  0,  1, 16, 
 2,  0,  1, 16, 
 2,  0,  1, 16, 
 2,  0,  1, 16, 
};

static const unsigned char alloc_table_2[] = {
 4,  0,  1,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 
 4,  0,  1,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 3,  0,  1,  3,  4,  5,  6,  7, 
};

static const unsigned char alloc_table_3[] = {
 4,  0,  1,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 
 4,  0,  1,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 3,  0,  1,  3,  4,  5,  6,  7, 
};

static const unsigned char alloc_table_4[] = {
 4,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
 4,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 
 4,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 
 4,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 3,  0,  1,  3,  4,  5,  6,  7, 
 2,  0,  1,  3, 
 2,  0,  1,  3, 
 2,  0,  1,  3, 
 2,  0,  1,  3, 
 2,  0,  1,  3, 
 2,  0,  1,  3, 
 2,  0,  1,  3, 
 2,  0,  1,  3, 
 2,  0,  1,  3, 
 2,  0,  1,  3, 
 2,  0,  1,  3, 
 2,  0,  1,  3, 
 2,  0,  1,  3, 
 2,  0,  1,  3, 
 2,  0,  1,  3, 
 2,  0,  1,  3, 
 2,  0,  1,  3, 
 2,  0,  1,  3, 
 2,  0,  1,  3, 
};

const unsigned char *alloc_tables[5] = { alloc_table_0, alloc_table_1, alloc_table_2, alloc_table_3, alloc_table_4, };

#endif