#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_systeminfo()
{
        char *p_system = (char*)malloc(38*sizeof(char));
        strcpy(p_system, "Linux version 4.18.0-147.el8.x86_64");
        return p_system;
}
 
int main()
{
        printf("system info:%s", get_systeminfo());
        return 0;
}

/*
内存泄露检测
[root@yglocal asan_test]# gcc -fsanitize=address -fno-omit-frame-pointer -o memory_leak_test memory_leak_test.c
[root@yglocal asan_test]# ASAN_OPTIONS=detect_leaks=1  ./memory_leak_test 
 
=================================================================
==122316==ERROR: LeakSanitizer: detected memory leaks
 
Direct leak of 38 byte(s) in 1 object(s) allocated from:
    #0 0x7fde593f3ba8 in __interceptor_malloc (/lib64/libasan.so.5+0xefba8)
    #1 0x400827 in get_systeminfo (/root/asan_test/memory_leak_test+0x400827)
    #2 0x400855 in main (/root/asan_test/memory_leak_test+0x400855)
    #3 0x7fde58f64872 in __libc_start_main (/lib64/libc.so.6+0x23872)
 
SUMMARY: AddressSanitizer: 38 byte(s) leaked in 1 allocation(s).
*/