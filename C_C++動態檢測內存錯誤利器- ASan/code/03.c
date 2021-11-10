#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
        char *p = (char*)malloc(32*sizeof(char));
        free(p);

        int a = p[1];

        return 0;
}

/*
使用悬空指针
[root@yglocal asan_test]# gcc -fsanitize=address -fno-omit-frame-pointer -o dangling_pointer_test dangling_pointer_test.c 
[root@yglocal asan_test]# ./dangling_pointer_test 
=================================================================
==83532==ERROR: AddressSanitizer: heap-use-after-free on address 0x603000000011 at pc 0x0000004007c4 bp 0x7ffd7f562760 sp 0x7ffd7f562750
READ of size 1 at 0x603000000011 thread T0
    #0 0x4007c3 in main (/root/asan_test/dangling_pointer_test+0x4007c3)
    #1 0x7f56196cd872 in __libc_start_main (/lib64/libc.so.6+0x23872)
    #2 0x4006ad in _start (/root/asan_test/dangling_pointer_test+0x4006ad)

0x603000000011 is located 1 bytes inside of 32-byte region [0x603000000010,0x603000000030)
freed by thread T0 here:
    #0 0x7f5619b5c7e0 in __interceptor_free (/lib64/libasan.so.5+0xef7e0)
    #1 0x400787 in main (/root/asan_test/dangling_pointer_test+0x400787)
    #2 0x7f56196cd872 in __libc_start_main (/lib64/libc.so.6+0x23872)

previously allocated by thread T0 here:
    #0 0x7f5619b5cba8 in __interceptor_malloc (/lib64/libasan.so.5+0xefba8)
    #1 0x400777 in main (/root/asan_test/dangling_pointer_test+0x400777)
    #2 0x7f56196cd872 in __libc_start_main (/lib64/libc.so.6+0x23872)

SUMMARY: AddressSanitizer: heap-use-after-free (/root/asan_test/dangling_pointer_test+0x4007c3) in main
Shadow bytes around the buggy address:
  0x0c067fff7fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0c067fff8000: fa fa[fd]fd fd fd fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8010: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
......
*/