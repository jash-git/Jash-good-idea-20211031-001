#include <stdio.h>
#include <stdlib.h>
 
int main()
{
        char *p = (char*)malloc(32*sizeof(char));
        free(p);
        free(p);
 
        return 0;
}

/*
重复释放
[root@yglocal asan_test]# gcc -fsanitize=address -fno-omit-frame-pointer -o invalid_free_test invalid_free_test.c 
[root@yglocal asan_test]# ./invalid_free_test 
=================================================================
==116778==ERROR: AddressSanitizer: attempting double-free on 0x603000000010 in thread T0:
    #0 0x7fab036ca7e0 in __interceptor_free (/lib64/libasan.so.5+0xef7e0)
    #1 0x400743 in main (/root/asan_test/invalid_free_test+0x400743)
    #2 0x7fab0323b872 in __libc_start_main (/lib64/libc.so.6+0x23872)
    #3 0x40065d in _start (/root/asan_test/invalid_free_test+0x40065d)
 
0x603000000010 is located 0 bytes inside of 32-byte region [0x603000000010,0x603000000030)
freed by thread T0 here:
    #0 0x7fab036ca7e0 in __interceptor_free (/lib64/libasan.so.5+0xef7e0)
    #1 0x400737 in main (/root/asan_test/invalid_free_test+0x400737)
    #2 0x7fab0323b872 in __libc_start_main (/lib64/libc.so.6+0x23872)
 
previously allocated by thread T0 here:
    #0 0x7fab036caba8 in __interceptor_malloc (/lib64/libasan.so.5+0xefba8)
    #1 0x400727 in main (/root/asan_test/invalid_free_test+0x400727)
    #2 0x7fab0323b872 in __libc_start_main (/lib64/libc.so.6+0x23872)
 
SUMMARY: AddressSanitizer: double-free (/lib64/libasan.so.5+0xef7e0) in __interceptor_free
==116778==ABORTING
*/