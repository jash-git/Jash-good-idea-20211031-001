#include <stdio.h>
#include <string.h>

int main()
{
        char stack_buf[4] = {0};
        strcpy(stack_buf, "1234");

        return 0;
}

/*
栈缓冲区溢出
[root@yglocal asan_test]# ./stack_ovf_test 
=================================================================
==38634==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7ffcf3d8b8d4 at pc 0x7f8714bbaa1d bp 0x7ffcf3d8b8a0 sp 0x7ffcf3d8b048
WRITE of size 5 at 0x7ffcf3d8b8d4 thread T0
    #0 0x7f8714bbaa1c  (/lib64/libasan.so.5+0x40a1c)
    #1 0x400949 in main (/root/asan_test/stack_ovf_test+0x400949)
    #2 0x7f87147da872 in __libc_start_main (/lib64/libc.so.6+0x23872)
    #3 0x4007cd in _start (/root/asan_test/stack_ovf_test+0x4007cd)

Address 0x7ffcf3d8b8d4 is located in stack of thread T0 at offset 36 in frame
    #0 0x400895 in main (/root/asan_test/stack_ovf_test+0x400895)

  This frame has 1 object(s):
    [32, 36) 'stack_buf' <== Memory access at offset 36 overflows this variable
HINT: this may be a false positive if your program uses some custom stack unwind mechanism or swapcontext
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-buffer-overflow (/lib64/libasan.so.5+0x40a1c) 
Shadow bytes around the buggy address:
  0x10001e7a96c0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10001e7a96d0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10001e7a96e0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10001e7a96f0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10001e7a9700: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x10001e7a9710: 00 00 00 00 00 00 f1 f1 f1 f1[04]f2 f2 f2 f3 f3
  0x10001e7a9720: f3 f3 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10001e7a9730: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10001e7a9740: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10001e7a9750: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10001e7a9760: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
......
*/