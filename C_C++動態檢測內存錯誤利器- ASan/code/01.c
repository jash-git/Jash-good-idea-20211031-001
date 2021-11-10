#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
        char *heap_buf = (char*)malloc(32*sizeof(char));
        memcpy(heap_buf+30, "overflow", 8);    //在heap_buf的第30个字节开始，拷贝8个字符
        free(heap_buf);
        return 0;
}

/*
堆缓冲区溢出

[root@yglocal asan_test]# gcc -fsanitize=address -fno-omit-frame-pointer -o heap_ovf_test heap_ovf_test.c 
[root@yglocal asan_test]# ./heap_ovf_test 
=================================================================
==40602==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x603000000030 at pc 0x7f3de8f91a1d bp 0x7ffd4b4ebb60 sp 0x7ffd4b4eb308
WRITE of size 8 at 0x603000000030 thread T0
    #0 0x7f3de8f91a1c  (/lib64/libasan.so.5+0x40a1c)
    #1 0x400845 in main (/root/asan_test/heap_ovf_test+0x400845)
    #2 0x7f3de8bb1872 in __libc_start_main (/lib64/libc.so.6+0x23872)
    #3 0x40075d in _start (/root/asan_test/heap_ovf_test+0x40075d)

0x603000000030 is located 0 bytes to the right of 32-byte region [0x603000000010,0x603000000030)
allocated by thread T0 here:
    #0 0x7f3de9040ba8 in __interceptor_malloc (/lib64/libasan.so.5+0xefba8)
    #1 0x400827 in main (/root/asan_test/heap_ovf_test+0x400827)
    #2 0x7f3de8bb1872 in __libc_start_main (/lib64/libc.so.6+0x23872)

SUMMARY: AddressSanitizer: heap-buffer-overflow (/lib64/libasan.so.5+0x40a1c) 
Shadow bytes around the buggy address:
  0x0c067fff7fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0c067fff8000: fa fa 00 00 00 00[fa]fa fa fa fa fa fa fa fa fa
  0x0c067fff8010: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==40602==ABORTING
[root@yglocal asan_test]#
*/