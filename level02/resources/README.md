# Level02

## vérifier le fichier

```sh
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

> Le fichier PCAP est l'abréviation de "Packet Capture", c'est un format de fichier utilisé pour enregistrer le trafic réseau. Le fichier PCAP enregistre diverses informations telles que l'heure, les adresses IP de l'émetteur et du destinataire, les numéros de port, etc., des paquets réseau. Ces informations sont utilisées à diverses fins telles que l'analyse réseau, les enquêtes de sécurité, la résolution de problèmes réseau, etc.

### 1.aller local

```sh
level02@SnowCrash:~$ pwd
/home/user/level02

```

```sh
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

### 2. Extraire le mot de passe avec Wireshark

![Screenshot 2023-08-28 at 10 06 25 PM](https://github.com/hyungyoo/snow-crash/assets/71254925/f97e26df-8570-42d1-8c57-98404a412316)

![Screenshot 2023-08-28 at 10 06 34 PM](https://github.com/hyungyoo/snow-crash/assets/71254925/45dc55f4-0eea-4d58-a3bd-3e5fd35f230a)

- Changer tcp en flux tcp (trié dans l'ordre)
  analyse -> follow -> tcp stream

![Screenshot 2023-08-28 at 10 07 15 PM](https://github.com/hyungyoo/snow-crash/assets/71254925/c6290112-2fda-4cc4-9ed9-1b73ebf1a3d5)

- Convertir en vidage hexadécimal

![Screenshot 2023-08-28 at 10 10 08 PM](https://github.com/hyungyoo/snow-crash/assets/71254925/505569f8-c52c-478e-b378-bbdb01ca5cf4)

- 0x7F

  - 0x7F signifie Suppr en ascii
  - ft_wandr...NDRel.L0L =>
    ft_wand[DEL][DEL][DEL]NDRe[DEL]L0L[END]

    Vous devez comprendre le rôle du caractère "DEL" dans la chaîne saisie. "DEL" agit de la même manière que Backspace, supprimant le caractère immédiatement avant.
    Par conséquent, vous pouvez supprimer les caractères suivant le caractère "DEL" dans la chaîne d'entrée. C'est-à-dire que "ft_w a n d r DEL DEL DEL N D R e l . L 0 L" devient " ft_waNDReL0L ".

## getflag

```sh
level02@SnowCrash:~$ su flag02
Password:
Don't forget to launch getflag !
flag02@SnowCrash:~$ getflag
Check flag.Here is your token : kooda2puivaav1idi4f57q8iq
```
