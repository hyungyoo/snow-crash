# snow-crash

## 시작

1. vm에 snow-crash.iso 설치
2. vm에 네트워크생성 -> 가상 머신(VM)에서 네트워크를 만든다는 것은 VM이 호스트 시스템과 통신하거나 인터넷과 연결되어 다른 컴퓨터와 통신할 수 있는 네트워크를 설정하는 것을 의미합니다.
   이를 통해 VM은 내부 네트워크뿐만 아니라 외부 네트워크와도 통신할 수 있습니다. 내부 네트워크는 일반적으로 VM과 호스트 시스템 간의 통신이나 다른 VM과의 통신을 위해 사용됩니다. 반면에 외부 네트워크는 인터넷에 연결되어 원격 서버나 클라이언트와 통신을 할 수 있습니다.
   즉, VM에서 네트워크를 만든다는 것은 VM이 다른 기기와 통신할 수 있도록 네트워크를 설정하는 것을 의미하며, 이는 내부 네트워크뿐만 아니라 외부 네트워크를 포함합니다.

# 연결

```zsh

$> ssh 192.168.56.2 -l level00 -p 4242
           _____                      _____               _
          / ____|                    / ____|             | |
         | (___  _ __   _____      _| |     _ __ __ _ ___| |__
          \___ \| '_ \ / _ \ \ /\ / / |    | '__/ _` / __| '_ \
          ____) | | | | (_) \ V  V /| |____| | | (_| \__ \ | | |
         |_____/|_| |_|\___/ \_/\_/  \_____|_|  \__,_|___/_| |_|

  Good luck & Have fun

          192.168.56.2
level00@192.168.56.2's password:
level00@SnowCrash:~$ 

```



## [Level00](./level00/resources/README.md)
유저가 flag00인 파일을 찾아 얻은 비밀번호를 rot 11로 복호화

## [Level01](./level01/resources/README.md)
/etc/passwd에 비밀번호 섹션에 있는 flg01의 비밀번호를 얻어, john the rippser로 복호화

## [Level02](./level02/resources/README.md)
pcap 파일을 wireshark로 확인하여 비밀번호를 획득한다. 
1. tcp stream으로 변경
2. ascii에서 .을 확인하기위해 hex dump로 확인
3. .이 Del이므로, 해당 문자를 제거한다.

## [Level03](./level03/resources/README.md)
level03의 홈에위치한 level03파일이 s권한이 있는걸확인후, ltrace로 확인.
getflag가 들어간 echo를 임의로 level03실행파일에서 실행시키면된다.

## [Level04](./level01/resources/README.md)
perl로 작성된 스크립트에서 localhost:4747을 알아낸후, curl로 유저확인 및 getflag실행

## [Level05](./level05/resources/README.md)
/var/mail/level05에서, flag05권한으로 sh실행을하므로, 실행파일 확인후, getflag.sh 실행파일작성

## [Level06](./level06/resources/README.md)
php(shell_exec(getflag)) and regex

## [Level07](./level07/resources/README.md)
set env with export, `, \

## [Level08](./level08/resources/README.md)
Use a symbolic link to avoid using the file name 'token'

## [Level09](./level09/resources/README.md)
 encrypting algorithm with level09 and reverse it!

 ## [Level10](./level10/resources/README.md)
symbolic link를 이용한 Race Condition 기법을 활용하여 해결할 수 있는 문제
