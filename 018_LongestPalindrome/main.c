#include <stdio.h>
#include <string.h>

int longestPalindrome(char* s) {
    int charCount[80];
    memset(charCount, 0, sizeof(charCount));
    int len = strlen(s);
    int i, result = 0;
    int odd = 0;

    for (i=0; i<len; i++) {
        charCount[s[i]-'A'] += 1;
    }

    for (i=0; i<80; i++) {
        if (charCount[i] % 2 == 0) {
            result += charCount[i];
        }
        else {
            //we don't need to find the longest odd length, odd length can be -1 to get even length
            // ccc -> cc
            result += (charCount[i] - 1);
            odd = 1;
        }
    }   
    return result + odd;
}

int main(void) {
    char s[] = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    printf("Result with input %d: %d\n", strlen(s), longestPalindrome(s));
    return 0;
}