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
landscape:x:104:110::/var/lib/landscape:/bin/false
sshd:x:105:65534::/var/run/sshd:/usr/sbin/nologin
level00:x:2000:2000::/home/user/level00:/bin/bash
level01:x:2001:2001::/home/user/level01:/bin/bash
level02:x:2002:2002::/home/user/level02:/bin/bash
level03:x:2003:2003::/home/user/level03:/bin/bash
level04:x:2004:2004::/home/user/level04:/bin/bash
level05:x:2005:2005::/home/user/level05:/bin/bash
level06:x:2006:2006::/home/user/level06:/bin/bash
level07:x:2007:2007::/home/user/level07:/bin/bash
level08:x:2008:2008::/home/user/level08:/bin/bash
level09:x:2009:2009::/home/user/level09:/bin/bash
level10:x:2010:2010::/home/user/level10:/bin/bash
level11:x:2011:2011::/home/user/level11:/bin/bash
level12:x:2012:2012::/home/user/level12:/bin/bash
level13:x:2013:2013::/home/user/level13:/bin/bash
level14:x:2014:2014::/home/user/level14:/bin/bash
flag00:x:3000:3000::/home/flag/flag00:/bin/bash
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
flag02:x:3002:3002::/home/flag/flag02:/bin/bash
flag03:x:3003:3003::/home/flag/flag03:/bin/bash
flag04:x:3004:3004::/home/flag/flag04:/bin/bash
flag05:x:3005:3005::/home/flag/flag05:/bin/bash
flag06:x:3006:3006::/home/flag/flag06:/bin/bash
flag07:x:3007:3007::/home/flag/flag07:/bin/bash
flag08:x:3008:3008::/home/flag/flag08:/bin/bash
flag09:x:3009:3009::/home/flag/flag09:/bin/bash
flag10:x:3010:3010::/home/flag/flag10:/bin/bash
flag11:x:3011:3011::/home/flag/flag11:/bin/bash
flag12:x:3012:3012::/home/flag/flag12:/bin/bash
flag13:x:3013:3013::/home/flag/flag13:/bin/bash
flag14:x:3014:3014::/home/flag/flag14:/bin/bash

```
Le fichier /etc/passwd est un fichier qui stocke les informations de base des comptes d'utilisateurs sur les systèmes Unix et Linux. Chaque ligne représente un compte d'utilisateur et contient plusieurs champs séparés par des virgules. La signification de chaque champ est la suivante :

- Nom d'utilisateur (Username)
- Mot de passe crypté (Encrypted Password) ou "x" (les mots de passe sont stockés séparément dans le fichier /etc/shadow)
- ID de l'utilisateur (User ID)
- ID du groupe (Group ID)
- Informations utilisateur ou commentaire (User Info or Comment)
- Chemin du répertoire personnel de l'utilisateur (User Home Directory Path)
- Shell de connexion (Login Shell)

on peut avoir "42hDRfypTqqnw" comme Mot de passe crypté 

et

Pour casser un mot de passe haché, on utilise généralement l'outil de craquage de mot de passe bien connu, John the Ripper.

</br>
</br>


## Décrypter "42hDRfypTqqnw" avec john the ripper

</br>

### 1. Enregistrer le mot de passe SCP dans un fichier et le déplacer localement

</br>

```zsh
➜  sgoinfre echo "42hDRfypTqqnw" > passwd
➜  sgoinfre ls
assembly  john-1.9.0  john-1.9.0.tar.gz  passwd  snow-crash  uber
➜  sgoinfre cat passwd 
42hDRfypTqqnw
➜  sgoinfre ./john-1.9.0/run/john ./passwd 
Loaded 1 password hash (descrypt, traditional crypt(3) [DES 128/128 SSE2])
Press 'q' or Ctrl-C to abort, almost any other key for status
abcdefg          (?)
1g 0:00:00:00 100% 2/3 100.0g/s 76800p/s 76800c/s 76800C/s raquel..bigman
Use the "--show" option to display all of the cracked passwords reliably
Session completed
➜  sgoinfre ./john-1.9.0/run/john ./passwd --show
?:abcdefg

1 password hash cracked, 0 left

```
password: abcdefg


```zsh
level01@SnowCrash:~$ su flag01
Password: 
Don't forget to launch getflag !
flag01@SnowCrash:~$ getflag
Check flag.Here is your token : f2av5il02puano7naaf6adaaf

flag01@SnowCrash:~$ su level02
Password:
level02@SnowCrash:~$
```
