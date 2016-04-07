//
//  ch1.h
//  hehe2
//
//  Created by GongpingjiaNanjing on 16/4/5.
//  Copyright © 2016年 sunmin.me. All rights reserved.
//

#ifndef ch1_h
#define ch1_h
void Fahrenheit_Celsius();

void GetInput();

int CountCharacter();

int CountLine();

//Exercise 1..8. Write a program to count blanks, tabs, and newlines
int CountAllBlank();

//Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
void TrimInputBlank();

//Exercise 1-10 Write a program to copy its input to its output, replacing each tabby\t,eachbackspaceby\b,andeachbackslashby\\. Thismakestabs and backspaces visible in an unambiguous way
void ReplaceBlackWithVisualCharacter();


//Exercise 1-12. Write a program that prints its input one word per line.
void PrintOneWordPerLine();


//Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
void HistogramLengthOfWordHorizontal();


void HistogramLengthOfWordVertical();

//Exercise 1-14. Write a program to print a histogram of the frequencies of dif- ferent characters in its input.
void HistogramAlphabet();

#endif /* ch1_h */
