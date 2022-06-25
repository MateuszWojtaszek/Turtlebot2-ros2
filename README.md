# README

## Spis treści
1. [Instalacja Ubuntu 22.04 na Intel NUC](#Instalacja-Ubuntu-22.04-na-Intel-NUC)
2. [Zmiana systemu przy połączeniu ssh](#zmiana-systemu-przy-połączeniu-ssh)
3. [Instalacja ROS2 Humble na Ubuntu 22.04](#instalacja-ros2-humble-na-ubuntu-2204)
4. [Instalacja sterowników Kobuki Base (ROS2 Humble)](#instalacja-sterowników-kobuki-base-ros2-humble)
## Instalacja Ubuntu 22.04 na Intel NUC
Aby zainstalować `Ubuntu 22.04` na Intel NUC:
* Pobrać obraz .iso `Ubuntu 22.04 LTS` i za pomocą dowolnego wypalić obraz systemu na pamięci USB  
* Zrestartować Intel NUC za pomocą 
```
sudo reboot
```
* Podczas restartu wpiąć pamięć USB z systemem do portu USB Intel NUC (zanim wstanie BIOS)
* Wejść do `boot menu` za pomocą klawisza `F10`.
* Wybrać opcji bootowania z USB
* Po otwarciu się ekranu wyboru `Ubuntu 22.04` wybrać opcję **"Try Ubuntu"**
* Po otwarciu, w terminalu uruchomić programu `gparted'
```
sudo gparted
```
* Wybrać partycję, na której zainstalowany jest `Ubuntu 16.04` i zmniejszyć ją o około 100GB (w zależności od potrzeb)
* **Nie tworzyć nowej partycji** Zostawić wolne miejsce nazwane `unallocated`.
* Uruchomić instalator `Ubuntu 22.04` (za pomocą ikony na pulpicie).
* Podczas instalacji systemu wybrać opcję ***Install alongside Ubuntu 16.04***
* Jeżeli wszystko przebiegło zgodnie z planem system powinien się zainstalować poprawnie, a podczas rebootu powininno pokazać się menu GRUB.  

>**Uwaga!**  
Po zainstalowaniu systemu nie będzie działało łączenie się po `ssh`. Aby to umożliwić należy wejść w terminal na Intel NUC na `Ubuntu 22.04` i zainstalować serwer `openssh`
```
sudo apt update
sudo apt install openssh-server
```    

## Zmiana systemu przy połączeniu ssh
System zmienia się za pomocą narzędzia `grub-reboot`.  
W celu zmienienia systemu należy wpisać komendę (stan na 24.06.2022 - docelowo skrypt)
```
sudo grub-reboot <N>
sudo reboot
```
gdzie `N` określa system, który zostanie włączony po reboocie.

| N 	|            System           	|
|:-:	|:---------------------------:	|
| 0 	|  Ubuntu 22.04 (ROS2 Humble) 	|
| 4 	| Ubuntu 16.04 (ROS1 Kinetic) 	|

> **Uwaga!**  
Po przełączeniu systemu pojawia się problem z kluczem `ssh`, przez co nie jest możliwe bezpieczne połączenie. Aby połączyć się z nowym systemem po reboocie, należy wykonać
```
ssh-keygen -f "/home/user/.ssh/known_hosts" -R "192.168.5.55"
```

## Instalacja ROS2 Humble na Ubuntu 22.04

## Instalacja sterowników Kobuki Base (ROS2 Humble)