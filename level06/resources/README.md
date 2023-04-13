# Level06

## ls -l

```zsh
level06@SnowCrash:~$ ls -l
total 12
-rwsr-x---+ 1 flag06 level06 7503 Aug 30  2015 level06
-rwxr-x---  1 flag06 level06  356 Mar  5  2016 level06.php
```

두 파일전부다 실행 및 읽기가능
level06파일에서 rws는 read-write-execute + setuid를 의미합니다. 이것은 해당 파일을 실행할 때, 실행하는 사용자가 파일 소유자(flag06)의 권한을 가지게 됩니다. 따라서 level06 사용자가 level06 파일을 실행하면, 실행하는 동안 flag06 사용자의 권한을 가지게 됩니다.

## level06 실행

```zsh
level06@SnowCrash:~$ ./level06
PHP Warning:  file_get_contents(): Filename cannot be empty in /home/user/level06/level06.php on line 4
```

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
