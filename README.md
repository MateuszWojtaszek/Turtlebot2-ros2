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

> **Uwaga!**  
Na każdym z systemów operacyjnych został napisany skrypt umożliwiający łatwe przełączenie się z jednego systemu na drugi.

Na `Ubuntu 22.04` wystarczy wywołać:
```
~/switch_to_ros1.sh
```
Na `Ubuntu 16.04` wystarczy wywołać:
```
~/switch_to_ros2.sh
```
Kody źródłowe skryptów znajdują się w bieżących notatkach [./notes/27.06.2022.md](./notes/27.06.2022.md).
## Instalacja ROS2 Humble na `Ubuntu 22.04`
W celu zainstalowania ROS'a 2 (zgodnie z instrukcjami z https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html):
* Aktualizować apt i zainstalować ROS'a 2 za pomocą paczek
```
sudo apt update
sudo apt upgrade
sudo apt install ros-humble-desktop
```
* Dodać odpowiedni wpis do `.bashrc`
```
echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
```
* Zostawić ROS_DOIMAIN_ID bez zmian (stan na 27.06.2022)
* Zainstalować narzędzie `colcon` (przydatne potem)
```
sudo apt install python3-colcon-common-extensions
```
* Skonfigurować `colcon_cd` oraz autouzupełnianie
```
echo "source /usr/share/colcon_cd/function/colcon_cd.sh" >> ~/.bashrc
echo "export _colcon_cd_root=/opt/ros/humble/" >> ~/.bashrc
echo "source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash" >> ~/.bashrc
```
> **Uwaga!**  
W celu sprawdzenia poprawności instalacji można uruchomić przykład `talker-listener`. Wystarczy wywołać instrukcje (w osobnych instancjach terminala):  
```
ros2 run demo_nodes_cpp talker
```

```
ros2 run demo_nodes_py listener
```
## Instalacja `Nav2` na Ubuntu 22.04 na Intel NUC
Nav2 zbudowano ze źródeł korzystając z tymczasowego patch'a naprawiającego błąd DDS'a (link: https://github.com/gezp/navigation2/tree/fix_obstacle_layer). W celu przeprowadzenia takiej instalacji:
* Stworzyć workspace na `Nav2`
```
mkdir -p ~/nav2_ws/src
```
* Pobrać kod źródłowy
```
cd ~
git clone https://github.com/gezp/navigation2.git
```
* Przekopiować poszczególne paczki do workspace'a
```
cp -r ~/navigation2/* ~/nav2_ws/src/
```
*  Zainstalować dependencje za pomocą `rosdep`
```
cd ~/nav2_ws/
rosdep install -y -r -q --from-paths src --ignore-src --rosdistro humble
```
* Zbudować paczki
```
colcon build --symlink-install
```
> **Uwaga!**  
Aby uniknąć bardzo długiego czasu kompilacji (na Intel NUC to ponad 30 minut) można usunąć z `nav2_ws` folder  `nav2_system_tests` przed rozpoczęciem kompilacji.

> **Uwaga!**  
W celu przetestowania poprawności działania `Nav2` można uruchomić przykładową symulację Turtlebot3:
```
sudo apt install ros-humble-turtle*
export TURTLEBOT3_MODEL=waffle
export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:/opt/ros/humble/share/turtlebot3_gazebo/models
ros2 launch nav2_bringup tb3_simulation_launch.py
```

## Instalacja sterowników Kobuki Base (ROS2 Humble)