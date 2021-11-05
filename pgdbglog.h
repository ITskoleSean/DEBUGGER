#ifndef PGDBGLOG_H
#define PGDBGLOG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <stdarg.h>

extern int glob_TypeTrace;
#define pgdebug(...) if ( glob_TypeTrace == 1 ) {PgDbgLogger(0, __LINE__, __FILE__, __VA_ARGS__);}
#define pgerror(...) PgDbgLogger(1, __LINE__, __FILE__, __VA_ARGS__);

void PgDbgLogger(unsigned long ulErrorType, int line, const char *pFile, const char *format, ...); 

#endif