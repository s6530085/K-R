//
//  ch1.h
//  hehe2
//
//  Created by GongpingjiaNanjing on 16/4/5.
//  Copyright © 2016年 sunmin.me. All rights reserved.
//

#ifndef ch1_h
#define ch1_h

#define ALPAHBETCOUNT 26

// 隐藏假设输入的单词不会超过20个字母,否则图标也难看
#define MAXWORDLENGTH 20

#define MAXLINELENGTH 1000

void Fahrenheit_Celsius();

void GetInput();

int CountCharacter();

int CountLine();

//Exercise 1..8. Write a program to count blanks, tabs, and newlines
int CountAllBlank();

//Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
void TrimInputBlank();

//Exercise 1-10 Write a program to copy its input to its output, replacing each tab by \t,each backspace by \b, and each backslash by \\. Thismakestabs and backspaces visible in an unambiguous way
void ReplaceBlackWithVisualCharacter();


//Exercise 1-12. Write a program that prints its input one word per line.
void PrintOneWordPerLine();


//Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
void HistogramLengthOfWordHorizontal();


void HistogramLengthOfWordVertical();

//Exercise 1-14. Write a program to print a histogram of the frequencies of dif- ferent characters in its input.
void HistogramAlphabet();

// Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as possible of the text.
void PrintLongestLine(int maxline);

// Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.
void PrintAllLinesLargeThanLimit(int limit, int maxline);


//Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.
void PrintAllTrimedLine(int maxline);


//Exercise 1-19. Write a function reverse (s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.

void Reverse(char to[], char from[]);

#endif /* ch1_h */
