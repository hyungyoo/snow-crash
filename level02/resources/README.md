# Level02

## 파일 확인

```zsh
level02@SnowCrash:~$ ls -al
total 24
dr-x------ 1 level02 level02  120 Mar  5  2016 .
d--x--x--x 1 root    users    340 Aug 30  2015 ..
-r-x------ 1 level02 level02  220 Apr  3  2012 .bash_logout
-r-x------ 1 level02 level02 3518 Aug 30  2015 .bashrc
----r--r-- 1 flag02  level02 8302 Aug 30  2015 level02.pcap
-r-x------ 1 level02 level02  675 Apr  3  2012 .profile
```

## .pcap 파일

> pcap 파일은 "Packet Capture"의 약자로, 네트워크 패킷 정보를 캡처하고 저장하기 위한 파일 형식입니다. pcap 파일은 네트워크 패킷 분석 도구에서 사용되며, Wireshark, tcpdump, WinDump 등의 프로그램에서 사용할 수 있습니다. pcap 파일에 저장된 패킷 정보는 네트워크 문제 진단, 보안 분석 등 다양한 용도로 사용될 수 있습니다.

### 1.로컬로 이동

```zsh
$>  scp -P 4242 level02@192.168.56.2:/home/user/level02/level02.pcap ./

           _____                      _____               _
          / ____|                    / ____|             | |
         | (___  _ __   _____      _| |     _ __ __ _ ___| |__
          \___ \| '_ \ / _ \ \ /\ / / |    | '__/ _` / __| '_ \
          ____) | | | | (_) \ V  V /| |____| | | (_| \__ \ | | |
         |_____/|_| |_|\___/ \_/\_/  \_____|_|  \__,_|___/_| |_|

  Good luck & Have fun

          192.168.56.2
level02@192.168.56.2's password:
```

### 2. tcpdump사용

```zsh
$> chmod +r ./level02.pcap
$> cpdump -r level02.pcap -X | grep "password" -i

reading from file level02.pcap, link-type EN10MB (Ethernet)
        0x0030:  011b b987 000d 0a50 6173 7377 6f72 643a  .......Password:
```

### 3. Wireshark로 패스워드 추출

- tcp를 tcp stream으로 변경 (순서대로 정렬)

  follow -> tcp stream

  ```zsh
  ..%..%..&..... ..#..'..$..&..... ..#..'..$.. .....#.....'........... .38400,38400....#.SodaCan:0....'..DISPLAY.SodaCan:0......xterm.........."........!........"..".....b........b....	B.
  ..............................1.......!.."......"......!..........."........"..".............	..
  .....................
  Linux 2.6.38-8-generic-pae (::ffff:10.1.1.2) (pts/10)

  ..wwwbugs login: l.le.ev.ve.el.lX.X
  ..
  Password: ft_wandr...NDRel.L0L
  .
  ..
  Login incorrect
  wwwbugs login:
  ```

- Hex dump로 변환

  ```zsh
  000000B9  66                                                 f
  000000BA  74                                                 t
  000000BB  5f                                                 _
  000000BC  77                                                 w
  000000BD  61                                                 a
  000000BE  6e                                                 n
  000000BF  64                                                 d
  000000C0  72                                                 r
  000000C1  7f                                                 .
  000000C2  7f                                                 .
  000000C3  7f                                                 .
  000000C4  4e                                                 N
  000000C5  44                                                 D
  000000C6  52                                                 R
  000000C7  65                                                 e
  000000C8  6c                                                 l
  000000C9  7f                                                 .
  000000CA  4c                                                 L
  000000CB  30                                                 0
  000000CC  4c                                                 L
  000000CD  0d                                                 .
  ```

- 0x7F

  - 0x7F는 ascii에서 Del을 뜻함
  - ft_wandr...NDRel.L0L =>
    ft_wand[DEL][del][DEL]NDRe[DEL]L0L

    입력한 문자열에서 "DEL" 문자의 역할을 이해해야 합니다. "DEL"은 Backspace와 유사한 역할을 하며, 바로 앞의 문자를 지웁니다.
    따라서 입력한 문자열에서 "DEL" 문자 뒤에 오는 문자들을 삭제하면 됩니다. 즉, "ft_w a n d r DEL DEL DEL N D R e l . L 0 L"에서 "ft_waNDReL0L"이 됩니다.

## getflag

```zsh
level02@SnowCrash:~$ su flag02
Password:
Don't forget to launch getflag !
flag02@SnowCrash:~$ getflag
Check flag.Here is your token : kooda2puivaav1idi4f57q8iq
```
