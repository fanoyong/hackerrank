#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int h, m;
    const char hour[12][10] = {"one\0", "two\0", "three\0", "four\0"
                            ,"five\0", "six\0", "seven\0", "eight\0"
                            ,"nine\0", "ten\0", "eleven\0", "twelve\0"
    };
    const char minute[60][30] = {"one minute past\0", "two minutes past\0", "three minutes past\0", "four minutes past\0", "five minutes past\0",
        "six minutes past\0", "seven minutes past\0", "eight minutes past\0", "nine minutes past\0", "ten minutes past\0",
        "eleven minutes past\0", "twelve minutes past\0", "thirteen minutes past\0", "fourteen minutes past\0", "quarter past\0",
        "sixteen minutes past\0", "seventeen minutes past\0", "eighteen minutes past\0", "nineteen minutes past\0", "twenty minutes past\0",
        "twenty one minutes past\0", "twenty two minutes past\0", "twenty three minutes past\0", "twenty four minutes past\0", "twenty five minutes past\0",
        "twenty six minutes past\0", "twenty seven minutes past\0", "twenty eight minutes past\0", "twenty nine minutes past\0", "half past\0",
        "twenty nine minutes to\0", "twenty eight minutes to\0", "twenty seven minutes to\0", "twenty six minutes to\0", "twenty five minutes to\0",
        "twenty four minutes to\0", "twenty three minutes to\0", "twenty two minutes to\0", "twenty one minutes to\0", "twenty minutes to\0",
        "nineteen minutes to\0", "eighteen minutes to\0", "seventeen minutes to\0", "sixteen minutes to\0", "quarter to\0",
        "fourteen minutes to\0", "thirteen minutes to\0", "twelve minutes to\0", "eleven minutes to\0", "ten minutes to\0",
        "nine minutes to\0", "eight minutes to\0", "seven minutes to\0", "six minutes to\0", "five minutes to\0",
        "four minutes to\0", "three minutes to\0", "two minutes to\0", "one minute to\0", "\0",
    };

    scanf("%d %d", &h, &m);
    if (m == 0) {
        printf("%s o' clock\n", hour[h-1]);
    } else if((60-m) >= 30) {
        printf("%s %s\n", minute[m-1], hour[h-1]);
    } else {
        printf("%s %s\n", minute[m-1], hour[h%12]);
    }
    return 0;
}
