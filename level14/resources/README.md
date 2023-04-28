# Level 14

</br></br>

## check file
```zsh
level14@SnowCrash:~$ ls -al
total 12
dr-x------ 1 level14 level14  100 Mar  5  2016 .
d--x--x--x 1 root    users    340 Aug 30  2015 ..
-r-x------ 1 level14 level14  220 Apr  3  2012 .bash_logout
-r-x------ 1 level14 level14 3518 Aug 30  2015 .bashrc
-r-x------ 1 level14 level14  675 Apr  3  2012 .profile
```

scp -P 4242 -r ~/peda level14@192.168.56.101:/tmp

</br></br>

## check getflag with gdb
```zsh
level14@SnowCrash:~$ gdb getflag 
GNU gdb (Ubuntu/Linaro 7.4-2012.04-0ubuntu2.1) 7.4-2012.04
Copyright (C) 2012 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "i686-linux-gnu".
For bug reporting instructions, please see:
<http://bugs.launchpad.net/gdb-linaro/>...
Reading symbols from /bin/getflag...(no debugging symbols found)...done.
(gdb) disassemble main
Dump of assembler code for function main:
   0x08048946 <+0>:     push   %ebp
   0x08048947 <+1>:     mov    %esp,%ebp
   0x08048949 <+3>:     push   %ebx
   0x0804894a <+4>:     and    $0xfffffff0,%esp
   0x0804894d <+7>:     sub    $0x120,%esp
   0x08048953 <+13>:    mov    %gs:0x14,%eax
   0x08048959 <+19>:    mov    %eax,0x11c(%esp)
   0x08048960 <+26>:    xor    %eax,%eax
   0x08048962 <+28>:    movl   $0x0,0x10(%esp)
   0x0804896a <+36>:    movl   $0x0,0xc(%esp)
   0x08048972 <+44>:    movl   $0x1,0x8(%esp)
   0x0804897a <+52>:    movl   $0x0,0x4(%esp)
   0x08048982 <+60>:    movl   $0x0,(%esp)
   0x08048989 <+67>:    call   0x8048540 <ptrace@plt>
   0x0804898e <+72>:    test   %eax,%eax
   0x08048990 <+74>:    jns    0x80489a8 <main+98>
   0x08048992 <+76>:    movl   $0x8048fa8,(%esp)
   0x08048999 <+83>:    call   0x80484e0 <puts@plt>
   0x0804899e <+88>:    mov    $0x1,%eax
   0x080489a3 <+93>:    jmp    0x8048eb2 <main+1388>
   0x080489a8 <+98>:    movl   $0x8048fc4,(%esp)
   0x080489af <+105>:   call   0x80484d0 <getenv@plt>
   0x080489b4 <+110>:   test   %eax,%eax
   0x080489b6 <+112>:   je     0x80489ea <main+164>
   0x080489b8 <+114>:   mov    0x804b040,%eax
   0x080489bd <+119>:   mov    %eax,%edx
   0x080489bf <+121>:   mov    $0x8048fd0,%eax

```

Après l'exécution de la fonction ptrace, la valeur de eax est -1. Par conséquent, il faut utiliser la commande 'set eax' pour la modifier en 0 ou 1.

```zsh
   0x08048989 <+67>:    call   0x8048540 <ptrace@plt>
   0x0804898e <+72>:    test   %eax,%eax
```

break point 

0x0804898e et getuid

```zsh
(gdb) b *0x0804898e
Breakpoint 1 at 0x804898e
(gdb) b getuid
Breakpoint 2 at 0x80484b0
(gdb) run
```

changer eax apres ptrace comme 1
```zsh
Starting program: /bin/getflag 

Breakpoint 1, 0x0804898e in main ()
(gdb) print $eax
$1 = -1
(gdb) set $eax=1
(gdb) continue
Continuing.

```
</br></br>

## getuid
```zsh
Breakpoint 1, 0x0804898e in main ()
(gdb) set $eax=1
(gdb) continue
Continuing.

Breakpoint 2, 0x08048b02 in main ()
(gdb) set $eax=3014
(gdb) finish
"finish" not meaningful in the outermost frame.
(gdb) step
Single stepping until exit from function main,
which has no line number information.
Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
0xb7e454d3 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6
```



