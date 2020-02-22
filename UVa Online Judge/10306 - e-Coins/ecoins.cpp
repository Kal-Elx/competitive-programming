#include <stdio.h>
#include <utility>
#include <map>
#include <limits>
#include <algorithm>
#include <set>

#define MAX std::numeric_limits<int>::max()

using namespace std;

// All Pythagorean Triplets under 300;
multimap<int, pair<int, int>> pythTrip = {{1, make_pair(0, 1)}, {2, make_pair(0, 2)}, {3, make_pair(0, 3)}, {4, make_pair(0, 4)}, {5, make_pair(3, 4)}, {5, make_pair(0, 5)}, {6, make_pair(0, 6)}, {7, make_pair(0, 7)}, {8, make_pair(0, 8)}, {10, make_pair(6, 
8)}, {9, make_pair(0, 9)}, {10, make_pair(0, 10)}, {11, make_pair(0, 11)}, {12, make_pair(0, 12)}, {13, make_pair(5, 12)}, {15, make_pair(9, 12)}, {13, make_pair(0, 13)}, {14, make_pair(0, 14)}, {15, make_pair(0, 15)}, {17, make_pair(8, 15)}, {16, make_pair(0, 16)}, {20, make_pair(12, 16)}, {17, make_pair(0, 17)}, {18, make_pair(0, 18)}, {19, make_pair(0, 19)}, {20, make_pair(0, 20)}, {25, make_pair(15, 20)}, {21, make_pair(0, 21)}, {29, make_pair(20, 21)}, {22, make_pair(0, 22)}, {23, make_pair(0, 23)}, {24, make_pair(0, 24)}, {25, make_pair(7, 24)}, {26, make_pair(10, 24)}, {30, make_pair(18, 24)}, {25, make_pair(0, 25)}, {26, make_pair(0, 26)}, {27, make_pair(0, 27)}, {28, make_pair(0, 28)}, {35, make_pair(21, 28)}, {29, make_pair(0, 29)}, {30, make_pair(0, 30)}, {34, make_pair(16, 30)}, {31, make_pair(0, 31)}, {32, make_pair(0, 32)}, {40, make_pair(24, 32)}, {33, make_pair(0, 33)}, {34, make_pair(0, 34)}, {35, make_pair(0, 35)}, {37, make_pair(12, 35)}, {36, make_pair(0, 36)}, {39, make_pair(15, 36)}, {45, make_pair(27, 36)}, {37, make_pair(0, 37)}, {38, make_pair(0, 38)}, {39, make_pair(0, 39)}, {40, make_pair(0, 40)}, {41, make_pair(9, 40)}, {50, make_pair(30, 40)}, {41, make_pair(0, 41)}, {42, make_pair(0, 42)}, {58, make_pair(40, 42)}, {43, make_pair(0, 43)}, {44, make_pair(0, 44)}, {55, make_pair(33, 44)}, {45, make_pair(0, 45)}, {51, make_pair(24, 45)}, {53, make_pair(28, 45)}, {46, make_pair(0, 46)}, {47, make_pair(0, 47)}, {48, make_pair(0, 48)}, {50, make_pair(14, 48)}, {52, make_pair(20, 48)}, {60, make_pair(36, 48)}, {49, make_pair(0, 49)}, {50, make_pair(0, 50)}, {51, make_pair(0, 51)}, {52, make_pair(0, 52)}, {65, make_pair(39, 52)}, {53, make_pair(0, 53)}, {54, make_pair(0, 54)}, {55, make_pair(0, 55)}, {73, make_pair(48, 55)}, {56, make_pair(0, 56)}, {65, make_pair(33, 56)}, {70, make_pair(42, 56)}, {57, make_pair(0, 57)}, {58, make_pair(0, 58)}, {59, make_pair(0, 59)}, {60, make_pair(0, 60)}, {61, make_pair(11, 60)}, {65, make_pair(25, 60)}, {68, make_pair(32, 60)}, {75, make_pair(45, 60)}, {61, make_pair(0, 61)}, {62, make_pair(0, 62)}, {63, make_pair(0, 63)}, {65, make_pair(16, 63)}, {87, make_pair(60, 63)}, {64, make_pair(0, 64)}, {80, make_pair(48, 64)}, {65, make_pair(0, 65)}, {66, make_pair(0, 66)}, {67, make_pair(0, 67)}, {68, make_pair(0, 68)}, {85, make_pair(51, 68)}, {69, make_pair(0, 69)}, {70, make_pair(0, 70)}, {74, make_pair(24, 70)}, {71, make_pair(0, 71)}, {72, make_pair(0, 72)}, {75, make_pair(21, 72)}, {78, make_pair(30, 72)}, {90, make_pair(54, 72)}, {97, make_pair(65, 72)}, {73, make_pair(0, 73)}, {74, make_pair(0, 74)}, {75, make_pair(0, 75)}, {85, make_pair(40, 75)}, {76, make_pair(0, 76)}, {95, make_pair(57, 76)}, {77, make_pair(0, 77)}, {85, make_pair(36, 77)}, {78, make_pair(0, 78)}, {79, make_pair(0, 79)}, {80, make_pair(0, 80)}, {82, make_pair(18, 80)}, {89, make_pair(39, 80)}, {100, make_pair(60, 80)}, {81, make_pair(0, 81)}, {82, make_pair(0, 82)}, {83, make_pair(0, 83)}, {84, make_pair(0, 84)}, {85, make_pair(13, 84)}, {91, make_pair(35, 84)}, {105, make_pair(63, 84)}, {116, make_pair(80, 84)}, {85, make_pair(0, 85)}, {86, make_pair(0, 86)}, {87, make_pair(0, 87)}, {88, make_pair(0, 88)}, {110, make_pair(66, 88)}, {89, make_pair(0, 
89)}, {90, make_pair(0, 90)}, {102, make_pair(48, 90)}, {106, make_pair(56, 90)}, {91, make_pair(0, 91)}, {109, make_pair(60, 91)}, {92, make_pair(0, 92)}, {115, make_pair(69, 92)}, {93, make_pair(0, 93)}, {94, make_pair(0, 94)}, {95, make_pair(0, 95)}, {96, make_pair(0, 96)}, {100, make_pair(28, 96)}, {104, make_pair(40, 96)}, {120, make_pair(72, 96)}, {97, make_pair(0, 97)}, {98, make_pair(0, 98)}, {99, make_pair(0, 99)}, {101, make_pair(20, 99)}, {100, make_pair(0, 100)}, {125, make_pair(75, 100)}, {101, make_pair(0, 101)}, {102, make_pair(0, 102)}, {103, make_pair(0, 103)}, {104, make_pair(0, 104)}, {130, make_pair(78, 104)}, {105, make_pair(0, 105)}, {111, make_pair(36, 105)}, {119, make_pair(56, 105)}, {137, make_pair(88, 105)}, {145, make_pair(100, 105)}, {106, make_pair(0, 106)}, {107, make_pair(0, 107)}, {108, make_pair(0, 108)}, {117, make_pair(45, 108)}, {135, make_pair(81, 108)}, {109, make_pair(0, 109)}, {110, make_pair(0, 110)}, {146, make_pair(96, 110)}, {111, make_pair(0, 111)}, {112, make_pair(0, 112)}, {113, make_pair(15, 112)}, {130, make_pair(66, 112)}, {140, make_pair(84, 112)}, {113, make_pair(0, 113)}, {114, make_pair(0, 114)}, {115, make_pair(0, 115)}, {116, make_pair(0, 116)}, {145, make_pair(87, 116)}, {117, make_pair(0, 117)}, {125, make_pair(44, 117)}, {118, make_pair(0, 118)}, {119, make_pair(0, 119)}, {120, make_pair(0, 120)}, {122, make_pair(22, 120)}, {123, make_pair(27, 120)}, {125, make_pair(35, 120)}, {130, make_pair(50, 120)}, {136, make_pair(64, 120)}, {150, make_pair(90, 120)}, {169, make_pair(119, 120)}, {121, make_pair(0, 121)}, {122, make_pair(0, 122)}, {123, make_pair(0, 123)}, {124, make_pair(0, 124)}, {155, make_pair(93, 124)}, {125, make_pair(0, 125)}, {126, make_pair(0, 126)}, {130, make_pair(32, 126)}, {174, make_pair(120, 126)}, {127, make_pair(0, 127)}, {128, make_pair(0, 128)}, {160, make_pair(96, 128)}, {129, make_pair(0, 129)}, {130, make_pair(0, 130)}, {131, 
make_pair(0, 131)}, {132, make_pair(0, 132)}, {143, make_pair(55, 132)}, {157, make_pair(85, 132)}, {165, make_pair(99, 132)}, {133, make_pair(0, 133)}, {134, make_pair(0, 134)}, {135, make_pair(0, 135)}, {153, make_pair(72, 135)}, {159, make_pair(84, 135)}, {136, make_pair(0, 136)}, {170, make_pair(102, 136)}, {137, make_pair(0, 137)}, {138, make_pair(0, 138)}, {139, make_pair(0, 139)}, {140, make_pair(0, 140)}, {148, make_pair(48, 140)}, {149, make_pair(51, 140)}, {175, make_pair(105, 140)}, {141, make_pair(0, 141)}, {142, make_pair(0, 142)}, {143, make_pair(0, 143)}, {145, make_pair(24, 143)}, {144, make_pair(0, 144)}, {145, make_pair(17, 144)}, {150, make_pair(42, 144)}, {156, make_pair(60, 144)}, {180, make_pair(108, 144)}, {194, make_pair(130, 144)}, {145, make_pair(0, 145)}, {146, make_pair(0, 146)}, {147, make_pair(0, 147)}, {203, make_pair(140, 147)}, {148, make_pair(0, 148)}, {185, make_pair(111, 148)}, {149, make_pair(0, 149)}, {150, make_pair(0, 150)}, {170, make_pair(80, 150)}, {151, make_pair(0, 151)}, {152, make_pair(0, 152)}, {190, make_pair(114, 152)}, {153, make_pair(0, 153)}, {185, make_pair(104, 153)}, {154, make_pair(0, 154)}, {170, make_pair(72, 154)}, {155, make_pair(0, 155)}, {156, make_pair(0, 156)}, {169, make_pair(65, 156)}, {195, make_pair(117, 156)}, {205, make_pair(133, 156)}, {157, make_pair(0, 157)}, {158, make_pair(0, 158)}, {159, make_pair(0, 159)}, {160, make_pair(0, 160)}, {164, make_pair(36, 160)}, {178, make_pair(78, 160)}, {200, make_pair(120, 160)}, {161, make_pair(0, 161)}, {162, make_pair(0, 162)}, {163, make_pair(0, 163)}, {164, make_pair(0, 164)}, {205, make_pair(123, 164)}, {165, make_pair(0, 165)}, {173, make_pair(52, 165)}, {187, make_pair(88, 165)}, {219, make_pair(144, 165)}, {166, make_pair(0, 166)}, {167, make_pair(0, 167)}, {168, make_pair(0, 168)}, {170, make_pair(26, 168)}, {175, make_pair(49, 168)}, {182, make_pair(70, 168)}, {193, make_pair(95, 168)}, {195, make_pair(99, 168)}, {210, make_pair(126, 168)}, {232, make_pair(160, 168)}, {169, make_pair(0, 169)}, {170, make_pair(0, 170)}, {171, make_pair(0, 171)}, {221, make_pair(140, 171)}, {172, make_pair(0, 172)}, {215, make_pair(129, 172)}, {173, make_pair(0, 173)}, {174, make_pair(0, 174)}, {175, make_pair(0, 175)}, {185, make_pair(60, 175)}, {176, make_pair(0, 176)}, {185, make_pair(57, 176)}, {220, make_pair(132, 176)}, {177, make_pair(0, 177)}, {178, make_pair(0, 178)}, {179, make_pair(0, 179)}, {180, make_pair(0, 180)}, {181, make_pair(19, 180)}, {183, make_pair(33, 180)}, {195, make_pair(75, 180)}, {204, make_pair(96, 180)}, {212, make_pair(112, 180)}, {225, make_pair(135, 180)}, {181, make_pair(0, 181)}, {182, make_pair(0, 182)}, {218, make_pair(120, 182)}, {183, make_pair(0, 183)}, {184, make_pair(0, 184)}, {230, make_pair(138, 184)}, {185, make_pair(0, 185)}, {186, make_pair(0, 186)}, {187, make_pair(0, 187)}, {205, make_pair(84, 187)}, {188, make_pair(0, 188)}, {235, make_pair(141, 188)}, {189, make_pair(0, 189)}, {195, make_pair(48, 189)}, {261, make_pair(180, 189)}, {190, make_pair(0, 190)}, {191, make_pair(0, 191)}, {192, make_pair(0, 192)}, {200, make_pair(56, 192)}, {208, make_pair(80, 192)}, {240, make_pair(144, 192)}, {193, make_pair(0, 193)}, {194, make_pair(0, 194)}, {195, make_pair(0, 195)}, {197, make_pair(28, 195)}, {221, make_pair(104, 195)}, {196, make_pair(0, 196)}, {245, make_pair(147, 196)}, {197, make_pair(0, 197)}, {198, make_pair(0, 198)}, {202, make_pair(40, 
198)}, {199, make_pair(0, 199)}, {200, make_pair(0, 200)}, {205, make_pair(45, 200)}, {250, make_pair(150, 200)}, {201, make_pair(0, 201)}, {202, make_pair(0, 202)}, {203, make_pair(0, 203)}, {204, make_pair(0, 204)}, {221, make_pair(85, 204)}, {255, make_pair(153, 204)}, {205, make_pair(0, 205)}, {206, make_pair(0, 206)}, {207, make_pair(0, 207)}, {208, make_pair(0, 208)}, {233, make_pair(105, 208)}, {260, make_pair(156, 208)}, {209, make_pair(0, 209)}, {241, make_pair(120, 209)}, {210, make_pair(0, 210)}, {222, make_pair(72, 210)}, {238, make_pair(112, 210)}, {274, make_pair(176, 210)}, {290, make_pair(200, 210)}, {211, make_pair(0, 211)}, {212, make_pair(0, 212)}, {265, make_pair(159, 212)}, {213, make_pair(0, 213)}, {214, make_pair(0, 214)}, {215, make_pair(0, 215)}, {216, make_pair(0, 216)}, {225, make_pair(63, 216)}, {234, make_pair(90, 216)}, {270, make_pair(162, 216)}, {291, make_pair(195, 216)}, {217, make_pair(0, 217)}, {218, make_pair(0, 218)}, {219, make_pair(0, 219)}, {220, make_pair(0, 220)}, {221, make_pair(21, 220)}, {275, make_pair(165, 220)}, {292, make_pair(192, 220)}, {221, make_pair(0, 221)}, {229, make_pair(60, 221)}, {222, make_pair(0, 222)}, {223, make_pair(0, 223)}, {224, make_pair(0, 224)}, {226, make_pair(30, 224)}, {260, make_pair(132, 224)}, {280, make_pair(168, 224)}, {225, make_pair(0, 225)}, {255, make_pair(120, 225)}, {265, make_pair(140, 225)}, {226, make_pair(0, 226)}, {227, make_pair(0, 227)}, {228, make_pair(0, 228)}, {247, make_pair(95, 228)}, {285, 
make_pair(171, 228)}, {229, make_pair(0, 229)}, {230, make_pair(0, 230)}, {231, make_pair(0, 231)}, {255, make_pair(108, 231)}, {281, make_pair(160, 231)}, {232, make_pair(0, 232)}, {290, make_pair(174, 232)}, {233, 
make_pair(0, 233)}, {234, make_pair(0, 234)}, {250, make_pair(88, 234)}, {235, make_pair(0, 235)}, {236, make_pair(0, 236)}, {295, make_pair(177, 236)}, {237, make_pair(0, 237)}, {238, make_pair(0, 238)}, {239, make_pair(0, 239)}, {240, make_pair(0, 240)}, {244, make_pair(44, 240)}, {246, make_pair(54, 240)}, {250, make_pair(70, 240)}, {260, make_pair(100, 240)}, {267, make_pair(117, 240)}, {272, make_pair(128, 240)}, {289, make_pair(161, 240)}, {300, make_pair(180, 240)}, {241, make_pair(0, 241)}, {242, make_pair(0, 242)}, {243, make_pair(0, 243)}, {244, make_pair(0, 244)}, {245, make_pair(0, 245)}, {259, make_pair(84, 245)}, {246, make_pair(0, 246)}, {247, make_pair(0, 247)}, {265, make_pair(96, 247)}, {248, make_pair(0, 248)}, {249, make_pair(0, 249)}, {250, make_pair(0, 250)}, {251, make_pair(0, 251)}, {252, make_pair(0, 252)}, {255, make_pair(39, 
252)}, {260, make_pair(64, 252)}, {273, make_pair(105, 252)}, {277, make_pair(115, 252)}, {253, make_pair(0, 253)}, {254, make_pair(0, 254)}, {255, make_pair(0, 255)}, {257, make_pair(32, 255)}, {289, make_pair(136, 
255)}, {256, make_pair(0, 256)}, {257, make_pair(0, 257)}, {258, make_pair(0, 258)}, {259, make_pair(0, 259)}, {260, make_pair(0, 260)}, {269, make_pair(69, 260)}, {261, make_pair(0, 261)}, {262, make_pair(0, 262)}, 
{263, make_pair(0, 263)}, {264, make_pair(0, 264)}, {265, make_pair(23, 264)}, {275, make_pair(77, 264)}, {286, make_pair(110, 264)}, {265, make_pair(0, 265)}, {266, make_pair(0, 266)}, {267, make_pair(0, 267)}, {268, make_pair(0, 268)}, {269, make_pair(0, 269)}, {270, make_pair(0, 270)}, {271, make_pair(0, 271)}, {272, make_pair(0, 272)}, {273, make_pair(0, 273)}, {274, make_pair(0, 274)}, {275, make_pair(0, 275)}, {276, make_pair(0, 276)}, {299, make_pair(115, 276)}, {277, make_pair(0, 277)}, {278, make_pair(0, 278)}, {279, make_pair(0, 279)}, {280, make_pair(0, 280)}, {287, make_pair(63, 280)}, {296, make_pair(96, 280)}, {298, make_pair(102, 280)}, {281, make_pair(0, 281)}, {282, make_pair(0, 282)}, {283, make_pair(0, 283)}, {284, make_pair(0, 284)}, {285, make_pair(0, 285)}, {293, make_pair(68, 285)}, {286, make_pair(0, 286)}, {290, make_pair(48, 286)}, {287, make_pair(0, 287)}, {288, make_pair(0, 288)}, {290, make_pair(34, 288)}, {300, make_pair(84, 288)}, {289, make_pair(0, 289)}, {290, make_pair(0, 290)}, {291, make_pair(0, 291)}, {292, make_pair(0, 292)}, 
{293, make_pair(0, 293)}, {294, make_pair(0, 294)}, {295, make_pair(0, 295)}, {296, make_pair(0, 296)}, {297, make_pair(0, 297)}, {298, make_pair(0, 298)}, {299, make_pair(0, 299)}, {300, make_pair(0, 300)}};

int S;
set<pair<int, int>> coins;
int cost[301][301];

void search(int cv, int iv) {
    for (int j = 0; j < S+1; ++j)
            fill(cost[j], cost[j] + S+1, MAX);
    cost[0][0] = 0;

    for (int c = 0; c <= cv; ++c) {
        for (int i = 0; i <= iv; ++i) {
            for (pair<int, int> coin : coins) {
                int ccv = coin.first;
                int civ = coin.second;
                if (c-ccv >= 0 && i-civ >= 0 && cost[c-ccv][i-civ] != MAX)
                    cost[c][i] = min(cost[c][i], 1 + cost[c-ccv][i-civ]);
            }
        }
    }
}

int main() {
    int n, m, cv, iv;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int res = MAX;
        coins.clear();

        scanf("%d %d", &m, &S);
        for (int j = 0; j < m; ++j) {
            scanf("%d %d", &cv, &iv);
            if (cv == 0 && iv == 0)
                continue;
            coins.insert(make_pair(cv, iv));
        }

        pair<multimap<int, pair<int, int>>::iterator, multimap<int, pair<int, int>>::iterator> ret = pythTrip.equal_range(S);

        int mv = 0;
        for (multimap<int, pair<int, int>>::iterator it = ret.first; it != ret.second; ++it) {
            pair<int, int> v = it->second;
            mv = max(mv, v.second);
        }
        search(mv, mv);

        for (multimap<int, pair<int, int>>::iterator it = ret.first; it != ret.second; ++it) {
            pair<int, int> v = it->second;
            res = min(cost[v.first][v.second], res);
            res = min(cost[v.second][v.first], res);
        }

        if (res != MAX)
            printf("%d\n", res);
        else
            printf("not possible\n");
    }

    return 0;
}