#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
        int *p;
        {
                int num = 10;
                p = &num;
        }
        printf("%d/n", *p);
 
        return 0;
}

/*
使用退出作用域的变量
[root@yglocal asan_test]# ./use-after-scope 
=================================================================
==45490==ERROR: AddressSanitizer: stack-use-after-scope on address 0x7fffda668b50 at pc 0x0000004009ea bp 0x7fffda668b10 sp 0x7fffda668b00
READ of size 4 at 0x7fffda668b50 thread T0
    #0 0x4009e9 in main (/root/asan_test/use-after-scope+0x4009e9)
    #1 0x7fc2194ca872 in __libc_start_main (/lib64/libc.so.6+0x23872)
    #2 0x40082d in _start (/root/asan_test/use-after-scope+0x40082d)
 
Address 0x7fffda668b50 is located in stack of thread T0 at offset 32 in frame
    #0 0x4008f5 in main (/root/asan_test/use-after-scope+0x4008f5)
 
  This frame has 1 object(s):
    [32, 36) 'num' <== Memory access at offset 32 is inside this variable
HINT: this may be a false positive if your program uses some custom stack unwind mechanism or swapcontext
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-use-after-scope (/root/asan_test/use-after-scope+0x4009e9) in main
Shadow bytes around the buggy address:
  0x10007b4c5110: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10007b4c5120: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10007b4c5130: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10007b4c5140: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10007b4c5150: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x10007b4c5160: 00 00 00 00 00 00 f1 f1 f1 f1[f8]f2 f2 f2 f3 f3
  0x10007b4c5170: f3 f3 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10007b4c5180: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10007b4c5190: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10007b4c51a0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10007b4c51b0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
......
[root@yglocal asan_test]#
*/