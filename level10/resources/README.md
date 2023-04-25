# Level 10

## file list in home
```zsh
level10@SnowCrash:~$ ls -l
total 16
-rwsr-sr-x+ 1 flag10 level10 10817 Mar  5  2016 level10
-rw-------  1 flag10 flag10     26 Mar  5  2016 token
```

## execute file level10
```zsh
level10@SnowCrash:~$ ./level10 
./level10 file host
        sends file to host if you have access to it
```
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
Connection to 6969. we need to listen on port 6969