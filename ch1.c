//
//  ch1.c
//  hehe2
//
//  Created by GongpingjiaNanjing on 16/4/5.
//  Copyright © 2016年 sunmin.me. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "ch1.h"

void Fahrenheit_Celsius()
{
    float fhar;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    
    printf("%2.5f\n", 2.5);
    for (fhar = lower; fhar <= upper; fhar += step) {
        printf("%3.0f %10.1f\n", fhar, (fhar-32.0)*5.0/9.0);
    }
}


void GetInput()
{
    int c;
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    printf("Receive end of file, exit\n");
}


int CountCharacter()
{
    int nc = 0;
    int c;
    
    while ((c = getchar()) != EOF) {
        nc++;
    }
    return nc;
}


int CountLine()
{
    int line = 0;
    int c;
    
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            line++;
        }
    }
    return line;
}



int CountAllBlank()
{
    int count = 0;
    int c;
    
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            count++;
        }
        else if (c == ' ') {
            count++;
        }
        else if (c == '\t') {
            count++;
        }
    }
    return count;
}


void TrimInputBlank()
{
    int c;
    int last_is_blank = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            // 如果之前是空格,则无视
            if (!last_is_blank) {
                putchar(c);
            }
            last_is_blank = 1;
        }
        else {
            putchar(c);
            last_is_blank = 0;
        }
    }
}


void ReplaceBlackWithVisualCharacter()
{
    int c;
    
    while ((c = getchar()) != EOF) {
        // 根本收不到的好嘛
        if (c == '\b') {
            putchar('\\');
            putchar('b');
        }
        else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        }
        else if (c == '\t') {
            putchar('\\');
            putchar('t');
        }
        else {
            putchar(c);
        }
    }
}


void PrintOneWordPerLine()
{
    int c;
    int is_word = 1;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            // 如果之前还是文字，就换个行
            if (is_word) {
                putchar('\n');
            }
            is_word = 0;
        }
        else {
            putchar(c);
            is_word = 1;
        }
    }
}


// 第一个参数是标题，形式是{"第一列", "第二列"},第二个参数是里面标题字符串最大长度，第三个是多少个标题，第四个参数是打印字符，目前犯懒只能写一个，第五个是每个标题对应多少个打印字符的数组，数组长度和多少个标题一致
static void PrintHorizontal(char **titles, int titleLength, int count, char *printChar, int* printLength)
{
    int i, j;
    char format[20];
    for (i = 0; i < count; i++) {
        sprintf(format, "%%%ds: ", titleLength);
        printf(format, titles[i]);
        for (j = 0; j < printLength[i]; j++) {
            printf(" %s", printChar);
        }
        printf("\n");
    }
}


void HistogramLengthOfWordHorizontal()
{
    int length[MAXWORDLENGTH] = {0};
    int is_word = 1;
    int word_length = 0;
    int c;
    int i;
    char *cp[MAXWORDLENGTH];
    char *cc;
    
    for (i = 0; i < MAXWORDLENGTH; i++) {
        cc = (char *)malloc(4);
        sprintf(cc, "%3d", i+1);
        cp[i] = cc;
    }
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            // 如果之前还是文字，则要记录现在的长度
            if (is_word && (word_length > 0)) {
                // 因为不可能有0长度的字符串，所以就直接-1了
                length[word_length-1]++;
            }
            is_word = 0;
            word_length = 0;
        }
        else {
            is_word = 1;
            word_length++;
        }
    }
    
    PrintHorizontal(cp, 2, MAXWORDLENGTH, "🁢", length);
    for (i = 0; i < MAXWORDLENGTH; i++) {
        free(cp[i]);
    }
}


void HistogramLengthOfWordVertical()
{
    int length[MAXWORDLENGTH] = {0};
    int is_word = 1;
    int word_length = 0;
    int c;
    int i, j, m;
    
    while (1) {
        c = getchar();
        if (c == ' ' || c == '\n' || c == '\t' || c == EOF) {
            // 如果之前还是文字，则要记录现在的长度
            if (is_word) {
                length[word_length]++;
            }
            is_word = 0;
            word_length = 0;
            if (c == EOF) {
                break;
            }
        }
        else {
            is_word = 1;
            word_length++;
        }
    }
    
    // 先找出最大值吧
    m = length[1];
    for (i = 2; i < MAXWORDLENGTH; i++) {
        if (length[i] > m) {
            m = length[i];
        }
    }
    
    // 打印水平柱状图
    printf("\n");
    for (i = 0; i < m; i++) {
        for (j = 1; j < MAXWORDLENGTH; j++) {
            if (length[j] >= m - i) {
                printf(" *");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    // 打印最下面的数字
    for (i = 1; i < MAXWORDLENGTH; i++) {
        printf("%2d", i);
    }
}


void HistogramAlphabet()
{
    int length[ALPAHBETCOUNT] = {0};
    int c;
    int i;
    char *cp[ALPAHBETCOUNT];
    char *cc;
    
    for (i = 0; i < ALPAHBETCOUNT; i++) {
        cc = (char *)malloc(2);
        sprintf(cc, "%c", 'a' + i);
        cp[i] = cc;
    }
    
    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {
            length[c-'a']++;
        }
        else if (c >= 'A' && c <= 'Z') {
            length[c-'A']++;
        }
    }
    
    PrintHorizontal(cp, 2, ALPAHBETCOUNT, " *", length);
    
    for (i = 0; i < ALPAHBETCOUNT; i++) {
        free(cp[i]);
    }
}


// 跟书上的例子保持一致吧，返回的长度不包括最后的'\0'，所以如果长度为0意味着其实遇到EOF了
static int GetLine(char line[], int linelimit)
{
    int c;
    int length = 0;
    
    // 不能再简单的    while ((c = getchar()) != EOF) 了，不然会遇到空行直接结束的情况
    while ((c = getchar()) != EOF) {
        // 如果是换行，则就getline了
        if (c != '\n' && length < linelimit -1) {
            line[length++] = c;
        }
        else {
            if (c == '\n') {
                line[length++] = '\n';
            }
            break;
        }
    }
    line[length] = '\0';

    return length;
}


static void Copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}


void PrintLongestLine(int maxline)
{
    // c99就已经支持不定长数组声明了哦
    char line[maxline];
    char longestline[maxline];
    int  longest = 0;
    int  length;
    
    while ((length = GetLine(line, maxline)) > 0) {
        if (length > longest) {
            longest = length;
            Copy(longestline, line);
        }
    }
    if (longest > 0) {
        printf("find longest line, length is %d, content is %s\n", longest, longestline);
    }
    else {
        printf("empty content\n");
    }
}


void PrintAllLinesLargeThanLimit(int limit, int maxline)
{
    char line[maxline];
    int  length;

    while ((length = GetLine(line, maxline)) > limit) {
        printf("%s", line);
    }
}


// 传过来的时候已经抱
static void TrimBlankFromBack(char line[], char trimedline[], int length)
{
    int i, j;
    
    
}


void PrintAllTrimedLine(int maxline)
{
    char line[maxline];
    char trimedline[maxline];
    int  length;
    
    while ((length = GetLine(line, maxline)) ) {
        // 这个length是包含空白的哦
        if (length > 0) {
            TrimBlankFromBack(line, trimedline, length);
            printf("%s", trimedline);
        }
    }
}


void Reverse(char to[], char from[])
{
    int c;
    int i,length;
    length = 0;
    
    while ((c = from[length++]) != '\0') {
    
    }
    
    for (i = 0; i < length - 1; i++) {
        to[i] = from[length-i-2];
    }
    to[length-1] = '\0';
}
