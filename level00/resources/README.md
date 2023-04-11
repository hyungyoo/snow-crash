# Level00

## login as level00

```zsh
$> ssh -l level00 [ip] -p 4242
$> password: level00
```

## 현재 유저 확인

```zsh
level00@SnowCrash:~$  whoami
level00@SnowCrash:~$ level00

or

level00@SnowCrash:~$  id -u -n
level00@SnowCrash:~$  level00
```

## flag00으로 su를 하기위해서, flag00유저로된 파일찾기

```zsh
level00@SnowCrash:~$  find / -user flag00
find: `/rofs/etc/ssl/private': Permission denied
find: `/rofs/home': Permission denied
find: `/rofs/root': Permission denied
/rofs/usr/sbin/john
find: `/rofs/var/cache/ldconfig': Permission denied
find: `/rofs/var/lib/php5': Permission denied
find: `/rofs/var/lib/sudo': Permission denied
find: `/rofs/var/spool/cron/atjobs': Permission denied
find: `/rofs/var/spool/cron/atspool': Permission denied
find: `/rofs/var/spool/cron/crontabs': Permission denied
find: `/rofs/var/tmp': Permission denied
find: `/rofs/var/www/level04': Permission denied
find: `/rofs/var/www/level12': Permission denied
...
...
```

## Permission denied 제거

```zsh
level00@SnowCrash:~$   find / -user flag00 2>/dev/null | xargs ls -al
----r--r-- 1 flag00 flag00 15 Mar  5  2016 /rofs/usr/sbin/john
----r--r-- 1 flag00 flag00 15 Mar  5  2016 /usr/sbin/john
```

## 파일 확인

```zsh
level00@SnowCrash:~$  find / -user flag00 2>/dev/null  | xargs cat
cdiiddwpgswtgt
cdiiddwpgswtgt
```

## rot 11로 디코드

```zsh
level00@SnowCrash:~$  echo "cdiiddwpgswtgt" | tr 'a-zA-Z' 'L-ZA-Kl-za-k'
nottoohardhere
```

## 암호를 이용해서 flag00으로 로그인

```zsh
level00@SnowCrash:~$ su flag00
Password:

Don't forget to launch getflag !
flag00@SnowCrash:~$

```

## get flag

```zsh
flag00@SnowCrash:~$ getflag
Check flag.Here is your token : x24ti5gi3x0ol2eh4esiuxias
flag00@SnowCrash:~$
```

## level01

```zsh
flag00@SnowCrash:~$ su level01
Password:
level01@SnowCrash:~$
```
