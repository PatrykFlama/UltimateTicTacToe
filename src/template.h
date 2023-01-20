#ifndef TEMPLATE
#define TEMPLATE

// #region
/* --- LIBRARIES --- */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// --NCurses--
#ifndef _WIN32
#include <ncurses.h>
#define ncurses true
#endif

#ifdef _WIN32
#define ncurses false
#define initscr()                               //? ncruses
#define printw(...) printf(__VA_ARGS__)         //? ncruses            
#define scanw(...) scanf(__VA_ARGS__)           //? ncurses 
#define getch() getchar()                       //? ncruses       
#define refresh()                               //? ncruses
#define clear() printf("\e[1;1H\e[2J");         //? ncruses                    
#define endwin()                                //? ncruses
#define start_color()
#define init_pair(index, foreground, background)
#define init_color(color, R, G, B)
#define attron(...)
#define attroff(...)
#endif

/* --- SUPERFOR --- */
#define GET_MACRO_FOR(_1, _2, _3, _4, NAME, ...) NAME
#define _FOR3(i, a, n, inc) for (int i = (a); (inc) > 0 ? i < (n) : i >= (n); i += (inc))
#define _FOR2(i, a, n) _FOR3(i, a, n, 1)
#define _FOR1(i, n) _FOR2(i, 0, n)
#define _FOR0(n) _FOR1(i, n)
#define FOR(...) GET_MACRO_FOR(__VA_ARGS__, _FOR3, _FOR2, _FOR1, _FOR0)(__VA_ARGS__)    //? (/name/, //from//, to, ///inc///)

/* --- VARS --- */
#define ll long long int
#define ld long double

/* --- C BASIC CARE PACKAGE --- */
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

/* --- MISC --- */
#define nl putchar('\n')
// #endregion

#endif
