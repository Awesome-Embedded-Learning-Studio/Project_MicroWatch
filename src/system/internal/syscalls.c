/**
 * @file syscalls.c
 * @author Charliechen114514 (chengh1922@mails.jlu.edu.cn)
 * @brief System Call Stubs, make no sense as STM32 Dont have these sessions yet!
 * @version 0.1
 * @date 2026-04-09
 *
 * @copyright Copyright (c) 2026
 *
 */
#include <sys/stat.h>

int _close(int fd) {
    (void)fd;
    return -1;
}

int _lseek(int fd, int ptr, int dir) {
    (void)fd;
    (void)ptr;
    (void)dir;
    return 0;
}

int _read(int fd, char* ptr, int len) {
    (void)fd;
    (void)ptr;
    (void)len;
    return 0;
}

int _write(int fd, const char* ptr, int len) {
    (void)fd;
    (void)ptr;
    return len;
}

int _fstat(int fd, struct stat* st) {
    (void)fd;
    st->st_mode = S_IFCHR;
    return 0;
}

int _isatty(int fd) {
    (void)fd;
    return 1;
}

void* _sbrk(int incr) {
    extern char _end;
    static char* heap_end;
    char* prev;

    if (!heap_end)
        heap_end = &_end;

    prev = heap_end;
    heap_end += incr;

    return (void*)prev;
}

void _kill(int pid, int sig) {
    (void)pid;
    (void)sig;
}

int _getpid(void) {
    return 1;
}
