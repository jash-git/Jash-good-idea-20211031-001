#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *ptr;
void get_pointer()
{
        int local[10];
        ptr = &local[0];
        return;
}


int main()
{
        get_pointer();

        printf("%d\n", *ptr);

        return 0;
}

/*
使用栈上返回的变量
[root@yglocal asan_test]# gcc -fsanitize=address -fno-omit-frame-pointer -o use_after_return use-after-return.c
[root@yglocal asan_test]# ASAN_OPTIONS=detect_stack_use_after_return=1 ./use_after_return 
=================================================================
==108419==ERROR: AddressSanitizer: stack-use-after-return on address 0x7fa2de200020 at pc 0x0000004009a2 bp 0x7ffccaef23c0 sp 0x7ffccaef23b0
READ of size 4 at 0x7fa2de200020 thread T0
    #0 0x4009a1 in main (/root/asan_test/use_after_return+0x4009a1)
    #1 0x7fa2e264d872 in __libc_start_main (/lib64/libc.so.6+0x23872)
    #2 0x4007cd in _start (/root/asan_test/use_after_return+0x4007cd)

Address 0x7fa2de200020 is located in stack of thread T0 at offset 32 in frame
    #0 0x400895 in get_pointer (/root/asan_test/use_after_return+0x400895)

  This frame has 1 object(s):
    [32, 72) 'local' <== Memory access at offset 32 is inside this variable
HINT: this may be a false positive if your program uses some custom stack unwind mechanism or swapcontext
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-use-after-return (/root/asan_test/use_after_return+0x4009a1) in main
Shadow bytes around the buggy address:
  0x0ff4dbc37fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0ff4dbc37fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0ff4dbc37fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0ff4dbc37fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0ff4dbc37ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0ff4dbc38000: f5 f5 f5 f5[f5]f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
  0x0ff4dbc38010: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0ff4dbc38020: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0ff4dbc38030: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0ff4dbc38040: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0ff4dbc38050: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
......
*/