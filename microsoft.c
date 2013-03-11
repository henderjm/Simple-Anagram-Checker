#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int length(char word[]);
int isAnagram(char word[], char word2[]);
int frequencyCount(char word[], char word2[]);
int isEmpty(int freq[]);

/**
 * Get length of string
 */
int length(char word[]) {
    int i = 0;
    for(i = 0; word[i] != '\0'; i++) {
    }
    return i;
}

int isAnagram(char word1[], char word2[]) {
    int i,j,matchfound = 0;
    int len = length(word1);
    if(len == length(word2)) {  // check string lengths
        for(i = 0; i < len; i++) {
            matchfound = 0;         // check for char match in string 2
            for(j = 0; j < len; j++) {
                if(word1[i] == word2[j]) {
                    word2[j] = '*'; // remove matched char
                    matchfound = 1;
                    break;
                }
            }
            if(matchfound == 0) return 0; // no match char found
        }
    } else {
        return 0; // can't be anagram -> word lengths are different
    }
    return 1;
}

// following methods used for option 2
void init(int freq[]) {
    int i;
    for(i = 0; i < 26; i++) {
        freq[i] = 0;
    }
}

int frequencyCount(char word1[], char word2[]) {
    int len1=length(word1), len2 = length(word2), i = 0;
    int frequency[26];
    init(frequency);
    if(len1 == len2) {
        while(i < len1) {
            frequency[word1[i] - 'a']++;
            frequency[word2[i] - 'a']--;
            i++;
        }
    } else {
        return 0; // can't be an anagram -> word lengths are different
    }
    int answer = isEmpty(frequency) ? 1 : 0;
    return answer;
}

int isEmpty(int freq[]) {
    int i;
    for(i = 0; i < 26; i++) {
        if(freq[i] != 0)
            return 0;
    }
    return 1;
}

int main() {
    int anagram;
    struct timeval start_time;
    struct timeval stop_time;
    long long sort_time;
    char word1[] = "thisisastring", word2[] = "gnirtsasisiht", temp[] = "gnirtsasisiht";
    gettimeofday(&start_time, NULL);
    anagram = isAnagram(word1, temp);

    gettimeofday(&stop_time, NULL);
    sort_time = (stop_time.tv_sec - start_time.tv_sec) * 1000000L +
        (stop_time.tv_usec - start_time.tv_usec);
    if(anagram)
        printf("%s is an anagram of %s\nTime for option 1= %lldms\n", word1, word2, sort_time);
    else printf("not anagram\n");
    // test 2
    gettimeofday(&start_time, NULL);
    anagram = frequencyCount(word1,word2);
    gettimeofday(&stop_time, NULL);
    sort_time = (stop_time.tv_sec - start_time.tv_sec) * 1000000L +
        (stop_time.tv_usec - start_time.tv_usec);
    if(anagram)
        printf("%s is an anagram of %s\nTime for option 2= %lldms\n", word1, word2, sort_time);

    else
        printf("Not Anagram\n");
    return 0;
}
