#include <stdio.h>

char translate(int num, int key) {
    int temp = (num - key + 28) % 27;
    char result;
    switch(temp) {
        case 0:
            result = ' ';
            break;
        case 1:
            result = 'a';
            break;
        case 2:
            result = 'b';
            break;
        case 3:
            result = 'c';
            break;
        case 4:
            result = 'd';
            break;
        case 5:
            result = 'e';
            break;
        case 6:
            result = 'f';
            break;
        case 7:
            result = 'g';
            break;
        case 8:
            result = 'h';
            break;
        case 9:
            result = 'i';
            break;
        case 10:
            result = 'j';
            break;
        case 11:
            result = 'k';
            break;
        case 12:
            result = 'l';
            break;
        case 13:
            result = 'm';
            break;
        case 14:
            result = 'n';
            break;
        case 15:
            result = 'o';
            break;
        case 16:
            result = 'p';
            break;
        case 17:
            result = 'q';
            break;
        case 18:
            result = 'r';
            break;
        case 19:
            result = 's';
            break;
        case 20:
            result = 't';
            break;
        case 21:
            result = 'u';
            break;
        case 22:
            result = 'v';
            break;
        case 23:
            result = 'w';
            break;
        case 24:
            result = 'x';
            break;
        case 25:
            result = 'y';
            break;
        case 26:
            result = 'z';
            break;
    }
    return result;
}

int main() {
    int N, key;
    scanf("%d %d", &N, &key);
    int surat[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &surat[i]);
    }
    printf("Terjemahan surat :\n");
    for(int i = 0; i < N; i++) {
        printf("%c", translate(surat[i], key));
    }
    printf("\n");
    return 0;
}
