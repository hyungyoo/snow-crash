# snow-crash

## 시작

1. vm에 snow-crash.iso 설치
2. vm에 네트워크생성 -> 가상 머신(VM)에서 네트워크를 만든다는 것은 VM이 호스트 시스템과 통신하거나 인터넷과 연결되어 다른 컴퓨터와 통신할 수 있는 네트워크를 설정하는 것을 의미합니다.
   이를 통해 VM은 내부 네트워크뿐만 아니라 외부 네트워크와도 통신할 수 있습니다. 내부 네트워크는 일반적으로 VM과 호스트 시스템 간의 통신이나 다른 VM과의 통신을 위해 사용됩니다. 반면에 외부 네트워크는 인터넷에 연결되어 원격 서버나 클라이언트와 통신을 할 수 있습니다.
   즉, VM에서 네트워크를 만든다는 것은 VM이 다른 기기와 통신할 수 있도록 네트워크를 설정하는 것을 의미하며, 이는 내부 네트워크뿐만 아니라 외부 네트워크를 포함합니다.

# 연결

```zsh

$> ssh 192.168.56.2 -l level00 -p 4242
           _____                      _____               _
          / ____|                    / ____|             | |
         | (___  _ __   _____      _| |     _ __ __ _ ___| |__
          \___ \| '_ \ / _ \ \ /\ / / |    | '__/ _` / __| '_ \
          ____) | | | | (_) \ V  V /| |____| | | (_| \__ \ | | |
         |_____/|_| |_|\___/ \_/\_/  \_____|_|  \__,_|___/_| |_|

  Good luck & Have fun

          192.168.56.2
level00@192.168.56.2's password:
level00@SnowCrash:~$ 

```



## [Level00](./level00/resources/README.md)
Trouvez le fichier de l'utilisateur flag00 et déchiffrez le mot de passe obtenu avec rot 11

## [Level01](./level01/resources/README.md)
Obtenez le mot de passe de flg01 dans la section mot de passe de /etc/passwd et déchiffrez-le avec john the ripper

## [Level02](./level02/resources/README.md)
le fichier pcap avec wireshark pour obtenir le mot de passe.
1. Passer au flux TCP
2. Vérifier avec le vidage hexadécimal pour vérifier .en ascii
3. Puisque . est Del, supprimer ce caractère.

## [Level03](./level03/resources/README.md)
Après avoir confirmé que le fichier level03 situé dans le répertoire home de level03 dispose de l'autorisation s avec ltrace.
Exécuter echo avec getflag dans le fichier exécutable level03.

## [Level04](./level01/resources/README.md)
Après avoir découvert localhost:4747 dans un script écrit en perl, en vérifiant l'utilisateur et en exécutant getflag avec curl

## [Level05](./level05/resources/README.md)
Dans /var/mail/level05, sh est exécuté avec l'autorité flag05, donc après avoir vérifié le fichier exécutable, écriver le fichier exécutable getflag.sh

## [Level06](./level06/resources/README.md)
php(shell_exec(getflag)) et expressions régulières

## [Level07](./level07/resources/README.md)
set env en utilisant export, `, \

## [Level08](./level08/resources/README.md)
Utiliser un lien symbolique pour éviter d'utiliser le nom de fichier "token"

## [Level09](./level09/resources/README.md)
inverser

 ## [Level10](./level10/resources/README.md)
Un problème qui peut être résolu en utilisant une technique de condition de concurrence à l'aide d'un lien symbolique

 ## [Level11](./level11/resources/README.md)
 connecter avec Netcat et envoyez la commande comme mot de passe

 ## [Level12](./level12/resources/README.md)
Il faut exécuter le CGI en tenant compte des minuscules et des majuscules."

 ## [Level13](./level13/resources/README.md)
  exécuter le niveau 13 et le vérifier avec gdb en changeant l'uid à 4242

## [Level14](./level14/resources/README.md)
Exécuter gdb pourle programme 'getflag' et changer l'UID en 'flag14'

 