# Level 09

## ls -l
```zsh
level09@SnowCrash:~$ ls -l
total 12
-rwsr-sr-x 1 flag09 level09 7640 Mar  5  2016 level09
----r--r-- 1 flag09 level09   26 Mar  5  2016 token
```

## check files
```zsh
level09@SnowCrash:~$ ltrace ./level09 
__libc_start_main(0x80487ce, 1, 0xbffff7f4, 0x8048aa0, 0x8048b10 <unfinished ...>
ptrace(0, 0, 1, 0, 0xb7e2fe38)                 = -1
puts("You should not reverse this"You should not reverse this
)            = 28
+++ exited (status 1) +++
level09@SnowCrash:~$ ./level09 
You need to provied only one arg.
level09@SnowCrash:~$ ./level09 token 
tpmhr
level09@SnowCrash:~$ ltrace ./level09 token 
__libc_start_main(0x80487ce, 2, 0xbffff7d4, 0x8048aa0, 0x8048b10 <unfinished ...>
ptrace(0, 0, 1, 0, 0xb7e2fe38)                 = -1
puts("You should not reverse this"You should not reverse this
)            = 28
+++ exited (status 1) +++
level09@SnowCrash:~$ cat token 
f4kmm6p|=�p�n��DB�Du{��
level09@SnowCrash:~$ 

```

"You should not reverse this" => on doit le reverser


## create application en C
```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    char buff[100];
    int i = 0;
    int fd = open("/home/user/level09/token", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    int read_size = read(fd, buff, 100); 
    if (read_size == -1) {
        perror("read");
        return 1;
    }
    buff[read_size] = '\0';
    while (buff[i]) {
        buff[i] -= i;
        i++;
    }
    printf("%s\n", buff);
    close(fd);
    return 0;
}

```
## make application and apply to oken
```zsh
level09@SnowCrash:~$ mkdir /tmp/level09
level09@SnowCrash:~$ cd /tmp/level09
level09@SnowCrash:/tmp/level09$ vim reverse.c
level09@SnowCrash:/tmp/level09$ gcc reverse.c 
level09@SnowCrash:/tmp/level09$ ./a.out 
f3iji1ju5yuevaus41q1afiuq�
level09@SnowCrash:/tmp/level09$ su flag09
Password: 
Don't forget to launch getflag !
flag09@SnowCrash:~$ getflag
Check flag.Here is your token : s5cAJpM8ev6XHw998pRWG728z
flag09@SnowCrash:~$ su level10
Password: 
level10@SnowCrash:~$ 
```