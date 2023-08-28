# Level00

</br>
</br>

## Se connecter en tant que level00

```sh
$> ssh -l level00 [ip] -p 4242
$> password: level00
```

</br>
</br>

## Vérifier l'utilisateur

```sh
level00@SnowCrash:~$  whoami
level00@SnowCrash:~$ level00

or

level00@SnowCrash:~$  id -u -n
level00@SnowCrash:~$  level00
```

</br>
</br>

## Pour passer à l'utilisateur flag00, chercher les fichiers associés à l'utilisateur flag00

```sh
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

</br>
</br>

## Supprimer les messages d'erreur "Permission denied"

```sh
level00@SnowCrash:~$   find / -user flag00 2>/dev/null | xargs ls -al
----r--r-- 1 flag00 flag00 15 Mar  5  2016 /rofs/usr/sbin/john
----r--r-- 1 flag00 flag00 15 Mar  5  2016 /usr/sbin/john
```

</br>
</br>

## Vérifier le contenu des fichiers

```sh
level00@SnowCrash:~$  find / -user flag00 2>/dev/null  | xargs cat
cdiiddwpgswtgt
cdiiddwpgswtgt
```

</br>
</br>

## Décoder en utilisant site: https://www.dcode.fr/rot-cipher

```sh
nottoohardhere
```

</br>
</br>

## Utiliser le mot de passe pour se connecter en tant qu'utilisateur flag00

```sh
level00@SnowCrash:~$ su flag00
Password:

Don't forget to launch getflag !
flag00@SnowCrash:~$

```

</br>
</br>

## Récupérer le flag

```sh
flag00@SnowCrash:~$ getflag
Check flag.Here is your token : x24ti5gi3x0ol2eh4esiuxias
flag00@SnowCrash:~$ su level01
Password:
level01@SnowCrash:~$
```
