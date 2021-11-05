#include "pgdbglog.h"

int glob_TypeTrace = 0;

void PgDbgLogger(unsigned long ulErrorType, int line, const char *pFile, const char *format, ...) {

    #if __APPLE__
    va_list vaArgumentPointer;
    #else 
    va_arg vaArgumentPointer;
    #endif

    static FILE *fLogFile = NULL;
    char OutputString[256] = {0};
    char *type = (ulErrorType == 1)? "Error":"Debug";

    char filename[256] = {0};
    time_t timeAndDate = 0;
    if ( fLogFile == NULL ) {
        timeAndDate = time(NULL);
        snprintf(filename, 256-1, "./debug/debug_%li", timeAndDate);
        fLogFile = fopen(filename, "w");
    }

    FILE *configFile = NULL;
    if ( configFile == NULL ){
        configFile = fopen("config.txt", "r");
    }

    if ( configFile != NULL ){
        char type = fgetc(configFile);
        glob_TypeTrace = atoi(&type);
        fclose(configFile);
    }
    
    printf("%i", glob_TypeTrace);

    va_start(vaArgumentPointer, format);
    vsnprintf(OutputString, 256 - 1, format, vaArgumentPointer);
    va_end(vaArgumentPointer);

    fprintf(fLogFile, "%04i: %s %s\n", line, type, OutputString);

    // We dont fclose file beacause the os will do it for us later.
    return;
}