#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_STR_LEN 1000

char mychar(char chares, int shft)
{
    if (!isalpha(chares))
        return chares;

    int max_chares = 0;
    int min_chares = 0;

    if (isupper(chares)) {
        max_chares = 90;
        min_chares = 65;
    }
    else if (islower(chares)) {
        max_chares = 122;
        min_chares = 97;
    }
    shft = shft % 25;
    int ext_chares = (int)chares + shft;
    if (ext_chares > max_chares) {
        ext_chares = (ext_chares % max_chares) + min_chares - 1;
    }
    else if (ext_chares < min_chares) {
        ext_chares = max_chares - (min_chares - ext_chares - 1);
    }

    return (char)ext_chares;
}

int len_strings(char* strings)
{
    int len = 0;

    for (int i = 0; strings[i] != '\0'; i++)
        len++;

    return len;
}

char* cesar_encryption(char* messages, int key, bool decipher_flag)
{
    int message_len = len_strings(messages);
    char* rlt = (char*)malloc((len_strings(messages) + 1) * sizeof(char));
    if (message_len == 0) {
        rlt[0] = '\0';
        return rlt;
    }

    if (decipher_flag)
        key = -key;

    int i = 0;
    for (; messages[i] != '\0'; i++)
        rlt[i] = mychar(messages[i], key);
    rlt[i] = '\0';

    return rlt;
}

int main()
{
    const int encryption = 3;
    char* messages[] = { "ViNi,ViDi,ViCi", "Canis vivus ",
            "#@%%", "XYxy", NULL };
    for (int i = 0; messages[i] != NULL; i++) {
        char* initmess = cesar_encryption(messages[i], encryption, false);
        char* decmess = cesar_encryption(initmess, encryption, true);
        printf("Input message:     %s\n", messages[i]);
        printf("Encrypted message: %s\n", initmess);
        printf("Decrypted message: %s\n\n", decmess);
        free(decmess);
        free(decmess);
    }

    return 0;
}