# Spis treści

### 1. [Instalacja Ubuntu 20.04 na Intel NUC](#1-instalacja-ubuntu-2004-na-intel-nuc-1)
### 2. [Zmiana systemu przy połączeniu ssh](#2-zmiana-systemu-przy-poc582c485czeniu-ssh-1)
### 3. [Instalacja ROS2 Galactic na Ubuntu 20.04](#3-instalacja-ros2-galactic-na-ubuntu-2004-1)
### 4. [Instalacja Nav2 na Ubuntu 20.04 na Intel NUC](#4-instalacja-nav2-na-ubuntu-2004-na-intel-nuc-binarki)
### 5. [Instalacja sterowników Kobuki Base (ROS2 Galactic)](#5-instalacja-sterowników-kobuki-base-ros2-galacitc)
---

# 1. Instalacja Ubuntu 20.04 na Intel NUC

Aby zainstalować `Ubuntu 20.04` na Intel NUC:
* Pobrać obraz .iso `Ubuntu 20.04 LTS` i za pomocą dowolnego wypalić obraz systemu na pamięci USB  
* Zrestartować Intel NUC za pomocą 
    ```bash
    sudo reboot
    ```
* Podczas restartu wpiąć pamięć USB z systemem do portu USB Intel NUC (zanim wstanie BIOS)
* Wejść do `boot menu` za pomocą klawisza `F10`.
* Wybrać opcji bootowania z USB
* Po otwarciu się ekranu wyboru `Ubuntu 20.04` wybrać opcję **"Try Ubuntu"**
* Po otwarciu, w terminalu uruchomić programu `gparted'
    ```bash
    sudo gparted
    ```
* Wybrać partycję, na której zainstalowany jest `Ubuntu 16.04` i zmniejszyć ją o około 100GB (w zależności od potrzeb)
* **Nie tworzyć nowej partycji** Zostawić wolne miejsce nazwane `unallocated`.
* Uruchomić instalator `Ubuntu 20.04` (za pomocą ikony na pulpicie).
* Podczas instalacji systemu wybrać opcję ***Install alongside Ubuntu 16.04***
* Jeżeli wszystko przebiegło zgodnie z planem system powinien się zainstalować poprawnie, a podczas rebootu powininno pokazać się menu GRUB.  

>**Uwaga!**  
Po zainstalowaniu systemu nie będzie działało łączenie się po `ssh`. Aby to umożliwić należy wejść w terminal na Intel NUC na `Ubuntu 20.04` i zainstalować serwer `openssh`
```bash
sudo apt update
sudo apt install openssh-server
```    
---

# 2. Zmiana systemu przy połączeniu ssh

System zmienia się za pomocą narzędzia `grub-reboot`.  
W celu zmienienia systemu należy wpisać komendę
```bash
sudo grub-reboot <N>
sudo reboot
```
gdzie `N` określa system, który zostanie włączony po reboocie.

| N 	|            System           	|
|:-:	|:---------------------------:	|
| 0 	|  Ubuntu 20.04 (ROS2 Galacitc) |
| 2 	|  Ubuntu 16.04 (ROS1 Kinetic) 	|

> **Uwaga!**  
Po przełączeniu systemu pojawia się problem z kluczem `ssh`, przez co nie jest możliwe bezpieczne połączenie. Aby połączyć się z nowym systemem po reboocie, należy wykonać
```bash
ssh-keygen -f "/home/${USER}/.ssh/known_hosts" -R "192.168.5.55"
```

> **Uwaga!**  
Na każdym z systemów operacyjnych został napisany skrypt umożliwiający łatwe przełączenie się z jednego systemu na drugi.

Na `Ubuntu 20.04` wystarczy wywołać:
```bash
~/switch_to_ros1
```
Na `Ubuntu 16.04` wystarczy wywołać:
```bash
~/switch_to_ros2
```
Kody źródłowe skryptów znajdują się w bieżących notatkach [./notes/11.07.2022.md](./notes/11.07.2022.md).

---

# 3. Instalacja ROS2 Galactic na `Ubuntu 20.04`

ROS'a zainstalować zgodnie z instrukcjami z https://docs.ros.org/en/galactic/Installation/Ubuntu-Install-Debians.html.   
 Po zainstalowaniu:
* Dodać odpowiedni wpis do `.bashrc`
    ```bash
    echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
    ```
* Zostawić ROS_DOIMAIN_ID bez zmian (stan na 27.06.2022)
* Zainstalować narzędzie `colcon` (przydatne potem)
    ```bash
    sudo apt install python3-colcon-common-extensions
    ```
* Skonfigurować `colcon_cd` oraz autouzupełnianie
    ```bash
    echo "source /usr/share/colcon_cd/function/colcon_cd.sh" >> ~/.bashrc
    echo "export _colcon_cd_root=/opt/ros/humble/" >> ~/.bashrc
    echo "source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash" >> ~/.bashrc
    ```
> **Uwaga!**  
W celu sprawdzenia poprawności instalacji można uruchomić przykład `talker-listener`. Wystarczy wywołać instrukcje (w osobnych instancjach terminala):  
```bash
ros2 run demo_nodes_cpp talker
```

```bash
ros2 run demo_nodes_py listener
```
---

# 4. Instalacja `Nav2` na Ubuntu 20.04 na Intel NUC (binarki)

W celu zainstalowania binarek `Nav2`:
* Zainstalować `Navigation2`
    ```bash
    sudo apt install ros-galactic-navigation2
    ```

* Zainstalować `nav2_bringup`
    ```bash
    sudo apt install ros-galactic-nav2-bringup
    ```

* Zainstalować paczki `Turtlebot3`
    ```bash
    sudo apt install ros-galactic-turtlebot3*
    ```
> **Uwaga!**  
W celu przetestowania poprawności działania `Nav2` można uruchomić przykładową symulację Turtlebot3:
```bash
sudo apt install ros-humble-turtle*
export TURTLEBOT3_MODEL=waffle
export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:/opt/ros/humble/share/turtlebot3_gazebo/models
ros2 launch nav2_bringup tb3_simulation_launch.py
```
---

# 5. Instalacja sterowników Kobuki Base (ROS2 Galacitc)

## a) Instalacja
W celu zainstalowania sterowników platformy mobilnej Kobuki Base należy:
* Stworzyć workspace wykorzystany do developmentu w ROSie
    ```bash
    cd ~/tb2_ros2_nav2/
    mkdir -p ros2_ws/src
    ```
* Pobrać paczki Kobuki
    ```bash
    cd ~/tb2_ros2_nav2/ros2_ws/src
    git clone https://github.com/kobuki-base/kobuki_core.git
    git clone https://github.com/kobuki-base/velocity_smoother.git
    git clone https://github.com/kobuki-base/cmd_vel_mux.git
    git clone https://github.com/kobuki-base/kobuki_ros_interfaces.git
    git clone https://github.com/kobuki-base/kobuki_ros.git
    ```
* Zainstalować dodatkowe wymagane komponenty
    ```bash
    cd ~/tb2_ros2_nav2/ros2_ws/
    sudo rosdep install -i --from-path src --rosdistro galactic -y
    ```

* Zbudować paczki
    ```bash
    colcon build --symlink-install
    ```

* Source'ować plik konfiguracyjny
    ```bash
    source install/setup.bash
    ```
> **Uwaga!**  
W celu przetestowania poprawności działania sterowników, wystarczy spróbować wywołać skrypt pozwalający na sterowanie za pomocą klawiatury (poniżej). Jeżeli nie występuje połączenie 
```
kobuki-simple-keyop
```


## b) Naprawa błędów związanych z komunikacją USB

Jeżeli występuje ostrzeżenie  
 `[WARNING] device does not (yet) available, is the usb connected?.`  
 to należy postępować w następujący sposób
 * Wyświetlić dostępne urządzenia USB
    ```bash
    lsusb
    ```

 Kobuki powinno zostać wyświetlone jako   
 `0403:6001 Future Technology Devices International, Ltd FT232 USB-Serial (UART) IC`

* Ponadto powinne być widoczne komunikaty o połączeniu Kobuki po wywołaniu 
    ```bash
    dmesg
    ```

* Jeżeli nie ma `/dev/kobuki` to należy
   * Dodać reguły kobuki do konfiugracji
        ```bash
        cd tb2_ros2_nav2/ros2_ws/src/kobuki_core
        sudo cp 60-kobuki.rules /etc/udev/rules.d
        sudo service udev reload
        sudo service udev restart
        ```

   * Jeżeli nadal nie ma `/dev/kobuki` 
        ```
        sudo udevadm control --reload-rules
        sudo udevadm trigger
        ```
* Teraz powinno pojawić się `/dev/kobuki`
* Sprawdzić komunikację (powinny pojawić się dziwne znaki na wyjściu terminala)
    ```bash
    cat /dev/kobuki
    ```
> Przy rozwiązywaniu problemów wykorzystano strony:  
*) https://kobuki.readthedocs.io/en/release-1.0.x/troubleshooting.html#troubleshooting-usb-section  
*) https://github.com/yujinrobot/kobuki_core/issues/24  
*) http://ftdi-usb-sio.sourceforge.net/  

---

# 6. Obsługa skanera laserowego Hokuyo 