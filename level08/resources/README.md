# Level 08

</br></br>

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

</br></br>

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

</br></br>

probleme concernant le nom de fichier!

```bash
level08@SnowCrash:~$ ln -s token /tmp/secret
level08@SnowCrash:~$ cat /tmp/secret
cat: /tmp/secret: Permission denied
level08@SnowCrash:~$ ./level08 /tmp/secret
quif5eloekouj29ke0vouxean
```
