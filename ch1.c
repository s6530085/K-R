//
//  ch1.c
//  hehe2
//
//  Created by GongpingjiaNanjing on 16/4/5.
//  Copyright © 2016年 sunmin.me. All rights reserved.
//

#include <stdio.h>

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
            is_word = 0;
        }
        else {
            if (is_word == 0) {
                putchar('\n');
            }
            putchar(c);
            is_word = 1;
        }
    }
}


void HistogramLengthOfWordHorizontal()
{
    // 隐藏假设输入的单词不会超过20个字母
#define MAXWORDLENGTH 20
    int length[MAXWORDLENGTH] = {0};
    int is_word = 1;
    int word_length = 0;
    int c;
    int i, j;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            // 如果之前还是文字，则要记录现在的长度
            if (is_word) {
                length[word_length]++;
            }
            is_word = 0;
            word_length = 0;
        }
        else {
            is_word = 1;
            word_length++;
        }
    }
    
    // 不可能有长度为0的单词
    for (i = 1; i < MAXWORDLENGTH; i++) {
        printf("word lenth is %2d ", i);
        for (j = 0; j < length[i]; j++) {
            printf("🁢");
        }
        printf("\n");
    }
}


void HistogramLengthOfWordVertical()
{
#define MAXWORDLENGTH 10
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
    
}





