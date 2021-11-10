#include <stdio.h>
#include <stdlib.h>
 
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
使用退出作用域的内存
[root@yglocal asan_test]# gcc -fsanitize=address -fno-omit-frame-pointer -o use-after-scope use-after-scope.c 
[root@yglocal asan_test]# ./use-after-scope 
=================================================================
==118523==ERROR: AddressSanitizer: stack-use-after-scope on address 0x7ffd35fafc60 at pc 0x0000004009ea bp 0x7ffd35fafc20 sp 0x7ffd35fafc10
READ of size 4 at 0x7ffd35fafc60 thread T0
    #0 0x4009e9 in main (/root/asan_test/use-after-scope+0x4009e9)
    #1 0x7f6d2c4ce872 in __libc_start_main (/lib64/libc.so.6+0x23872)
    #2 0x40082d in _start (/root/asan_test/use-after-scope+0x40082d)
 
Address 0x7ffd35fafc60 is located in stack of thread T0 at offset 32 in frame
    #0 0x4008f5 in main (/root/asan_test/use-after-scope+0x4008f5)
 
  This frame has 1 object(s):
    [32, 36) 'num' <== Memory access at offset 32 is inside this variable
HINT: this may be a false positive if your program uses some custom stack unwind mechanism or swapcontext
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-use-after-scope (/root/asan_test/use-after-scope+0x4009e9) in main
Shadow bytes around the buggy address:
  0x100026bedf30: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100026bedf40: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100026bedf50: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100026bedf60: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100026bedf70: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x100026bedf80: 00 00 00 00 00 00 00 00 f1 f1 f1 f1[f8]f2 f2 f2
  0x100026bedf90: f3 f3 f3 f3 00 00 00 00 00 00 00 00 00 00 00 00
  0x100026bedfa0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100026bedfb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100026bedfc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100026bedfd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
......
*/