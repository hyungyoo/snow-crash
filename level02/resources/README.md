# Level02

## vérifier le fichier

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

## 
fichier .pcap

> 
Un fichier pcap signifie "Packet Capture" et est un format de fichier permettant de capturer et de stocker des informations sur les paquets réseau. Les fichiers pcap sont utilisés par les outils d'analyse de paquets réseau et peuvent être utilisés par des programmes tels que Wireshark, tcpdump et WinDump. Les informations sur les paquets stockées dans les fichiers pcap peuvent être utilisées à diverses fins, notamment pour diagnostiquer des problèmes de réseau et analyser la sécurité.

### 1.aller local

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

### 2. Utiliser tcpdump

```zsh
$> chmod +r ./level02.pcap
$> cpdump -r level02.pcap -X | grep "password" -i

reading from file level02.pcap, link-type EN10MB (Ethernet)
        0x0030:  011b b987 000d 0a50 6173 7377 6f72 643a  .......Password:
```

### 3. Extraire le mot de passe avec Wireshark

-  Changer tcp en flux tcp (trié dans l'ordre)

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

- 
Convertir en vidage hexadécimal

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

  -  0x7F signifie Suppr en ascii
  - ft_wandr...NDRel.L0L =>
    ft_wand[DEL][del][DEL]NDRe[DEL]L0L

    Vous devez comprendre le rôle du caractère "DEL" dans la chaîne saisie. "DEL" agit de la même manière que Backspace, supprimant le caractère immédiatement avant.
    Par conséquent, vous pouvez supprimer les caractères suivant le caractère "DEL" dans la chaîne d'entrée. C'est-à-dire que "ft_w a n d r DEL DEL DEL N D R e l . L 0 L" devient " ft_waNDReL0L ".

## getflag

```zsh
level02@SnowCrash:~$ su flag02
Password:
Don't forget to launch getflag !
flag02@SnowCrash:~$ getflag
Check flag.Here is your token : kooda2puivaav1idi4f57q8iq
```
