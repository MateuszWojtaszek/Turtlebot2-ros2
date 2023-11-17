# Instalacja repozytorium
Repozytorium zawiera w sobie część modułów potrzebnych do działania, natomiast część należy pobrać dodatkowo. W celu instalacji tego repozytorium należy:
* pobrać główne repozytorium wraz z submodulami
    ```bash
    git clone --recurse-submodules https://git.kcir.pwr.edu.pl/irak/tb2_ros2_nav2.git
    ```
* pobrać moduły, które zostały zmodyfikowane i przystosowane do TurtleBota2
    ```bash
    cd tb2_ros2_nav2/ros2_ws/src
    git clone https://git.kcir.pwr.edu.pl/irak/turtlebot2.git
    git clone https://github.com/igrak34/kobuki_ros.git
    git clone --branch="foxy-devel" https://github.com/igrak34/urg_node.git
    ```
* Zainstalować konieczne dependencje
    ```bash
    cd ~/tb2_ros2_nav2/ros2_ws
    sudo rosdep install --from-path src --ignore-src --rosdistro galactic
    jesli nie zadziała użyć komendy:
    rosdep update --include-eol-distros
    ```
* Zbudować wszystkie paczki
    ```bash
    cd ~/tb2_ros2_nav2/ros2_ws
    colcon build --symlink-install
    jak nie zadziala to zainstalowac:
    sudo apt install ros-galactic-ecl-build 
    sudo apt install ros-galactic-ecl-commandline
    sudo apt install ros-galactic-ecl-config
    sudo apt install ros-galactic-ecl-core
    sudo apt install ros-galactic-ecl-console
                                      mobile robot
                                      
    or try just:
    rosdep install --from-paths src --ignore-src -y --skpis-keys "fastcdr rti-connext-dds-5.3.1urdfdom_headers"
    sudo apt install ros-galactic-joint -state-publisher-gui
    ```
# Dokumentacja
## Spis treści

### 1. [Instalacja Ubuntu 20.04 na Intel NUC](#1-instalacja-ubuntu-2004-na-intel-nuc-1)
### 2. [Zmiana systemu przy połączeniu ssh](#2-zmiana-systemu-przy-poc582c485czeniu-ssh-1)
### 3. [Instalacja ROS2 Galactic na Ubuntu 20.04](#3-instalacja-ros2-galactic-na-ubuntu-2004-1)
### 4. [Instalacja Nav2 na Ubuntu 20.04 na Intel NUC](#4-instalacja-nav2-na-ubuntu-2004-na-intel-nuc-binarki)
### 5. [Instalacja sterowników Kobuki Base (ROS2 Galactic)](#5-instalacja-sterowników-kobuki-base-ros2-galacitc)
### 6. [Obsługa skanera laserowego Hokuyo](#6-obsc582uga-skanera-laserowego-hokuyo-1)
### 7. [URDF TurtleBota 2](#7-urdf-turtlebota2)
### 8. [Paczka `turtlebot2`](#8-paczka-turtlebot2-1)
### 9. [Konfiguracja sieci na Intel NUC dla poprawnej komunikacji ROS2 w sieci lokalnej](#9-konfiguracja-sieci-na-intel-nuc-dla-poprawnej-komunikacji-ros2-w-sieci-lokalnej-1)
### 10. [Konfiguracja MOCAP4ROS2](#10-konfiguracja-mocap4ros2-1)
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
* Wybrać opcji bootowania z USB(boot_Loader!)
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
do zmiany
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
    echo "source /opt/ros/galactic/setup.bash" >> ~/.bashrc
    ```
* Zostawić ROS_DOIMAIN_ID bez zmian (stan na 27.06.2022)
* Zainstalować narzędzie `colcon` (przydatne potem)
    ```bash
    sudo apt install python3-colcon-common-extensions
    ```
* Skonfigurować `colcon_cd` oraz autouzupełnianie
    ```bash
    echo "source /usr/share/colcon_cd/function/colcon_cd.sh" >> ~/.bashrc
    echo "export _colcon_cd_root=/opt/ros/galactic/" >> ~/.bashrc
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
sudo apt install ros-galactic-turtle*
export TURTLEBOT3_MODEL=waffle
export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:/opt/ros/galactic/share/turtlebot3_gazebo/models
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
> **Adres IP lasera Hokuyo:** `192.168.0.10`
W celu konfiguracji skanera laserowego Hokuyo wpiętego do Intel NUC przez port ethernet należy:
* Ustawić poprawną konfigurację połączenia
    * wejść w `wired connections` w ustawieniach Ubuntu
    * wybrać zakładkę IPv4
    * zaznaczyć opcję `manual`
    * wpisać poniższe ustawienia:
    > Adress: 192.168.0.15  
    Netmask: 255.255.255.0  
    Gateway: (zostawić puste)
    * zrebootować system
        ```bash
        sudo reboot
        ```
> **Uwaga!**  
Jeżeli konfiguracja przebiegła pomyślnie to możliwe będzie zpingowanie lasera
```bash
ping 192.168.0.10
```

Aby uruchomić ROSowy node lasera należy wywołać
```bash
ros2 launch urg_node urg_node_launch.py sensor_interface:=ethernet
```
> **Uwaga!**  
W celu sprawdzenia poprawności działania skanera należy w osobnych terminalach uruchomić static publishera, zapewniającego sztuczną transformacje między mapą a laserem, oraz `rviz2`:
```bash
ros2 run tf2_ros static_transform_publisher 0 0 0 0 0 0 "map" "laser"
```
```bash
rviz2
```
---


# 7. URDF TurtleBota2
Korzystając z repozytorium `Turtlebot` (https://github.com/turtlebot/turtlebot) przygotowanego na ROS1 udało się poprawnie przygotować URDF Turtlebota2, aby zgadzał się ze stanem faktycznym. Więc zamiast kamery 3D przygotowano uproszczony model skanera laserowego i umieszczono go w miejscu, w którym znajduje się w rzeczywistości. Dzięki temu możliwa jest poprawna transformacja położenia lasera.

W celu wyświetlenia modelu robota wystarczy wywołać
```bash
ros2 launch turtlebot2_description display.launch.py
```

Poza tym istnieje możliwość wyświetlania zarówno skanu laserowego i robota, wystarczy w drugim terminalu wywołać:
```bash
ros2 launch urg_node urg_node_launch.py sensor_interface:=ethernet
```
i w rviz'ie zasubskrybować odpowiedni topic.

***URDF znajduje się w paczce `turtlebot2` (opisano poniżej)***

---

# 8. Paczka `turtlebot2`

W celu łatwej inicjalizacji stworzono paczkę turtlebot2, która docelowo zawierać będzie konfigurację i skrypty uruchamiające do funkcjonalności takich jak SLAM czy nawigacja.  

***(STAN NA 24.07.2022)***  
Do tej pory udało się stworzyć paczki:
* `turtlebot2_description` - URDF robota do wizualizacji, transformacji i symulacji(do pobrania nowa wersja z repo github igrak34 urg_node foxy_devel)
* `turtlebot2_bringup` - skrypty inicjalizujące najważniejsze moduły - pozwala na sterowanie po topic'u `cmd_vel`, na odczytywanie skanu laserowego i odczytywanie informacji z Kobuki
* `turtlebot2_slam` - skrypty inicjalizujące mapowanie otoczenia za pomocą skanera laserowego (na 24.07.2022 tylko `slam_toolbox` - w planie `cartographer`)
* `turtlebot2_nav` - skrypty i konfiguracje inicjalizujące stos nawigacyjny `Nav2` i lokalizujący robota (AMCL)

* `TESTY:`
* `Uruchamianie robota (drive i laser):` - ros2 launch turtlebot2_bringup turtlebot2_bringup.launch.py
* `Uruchamianie Nav2 całego:` - ros2 launch turtlebot2_nav nav2.launch.py namespace:=tb2_1          (to najpierw)
* `Uruchamianie widoku Nav2:` - ros2 launch turtlebot2_nav rviz_nav2.launch.py namespace:=tb2_1         (to drugie)
* `remapowanie cmd_vel na turtlebota:` - --ros-args --remap cmd_vel:=/tb6/cmd_vel 

namespacy są ważne!(rozróżnianie robotów w sieci)

*`gdyby wystąpił błąd w launch file trzeba zmienic node_executable na executable!!!!`
 cd /opt/ros/galactic/share/urg_node/launch
 vim urg_node_launch.py
---

# 9. Konfiguracja sieci na Intel NUC dla poprawnej komunikacji ROS2 w sieci lokalnej

Podczas pracy ze skanerem laserowym, którego interfejsem podłączenia do Intel NUC był `ethernet` powstał problem, w którym ROS2 próbował udostępniać dane w sieci skanera laserowego zamiast w sieci laboratorium (WiFi). Aby to rozwiązać należy:
* W "Wired Connection" w ustawieniach Ubuntu należy ustawić 
    ```
    Adress: 192.168.0.15
    Mask: 255.255.255.0
    Gateway: (zostawić puste)
    ```
* Stworzyć plik konfiguracyjny `cyclonedds.xml` (na przykład w folderze `home`)
    ```xml
    <?xml version="1.0" encoding="UTF-8"?>  
    <CycloneDDS xmlns="https://cdds.io/config"
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xsi:schemaLocation="https://cdds.io/config
    https://raw.githubusercontent.com/eclipse-cyclonedds/cyclonedds/master/etc/cyclonedds.xsd">
        <Domain id="any">
            <General>
                <NetworkInterfaceAddress>wlp58s0</NetworkInterfaceAddress>
            </General>
        </Domain>  
    </CycloneDDS>
    ```
* Wpisać następującą linię do pliku `~/.bashrc` **(ustawić odpowiednią ścieżkę)**
    ```
    export CYCLONEDDS_URI=file://$PWD/cyclonedds.xml
    ```

# 10. Konfiguracja MOCAP4ROS2
## Instalacja
```bash
mkdir -p mocap_ws/src
cd mocap_ws/src
git clone https://github.com/MOCAP4ROS2-Project/mocap4ros2_optitrack.git
git clone https://github.com/MOCAP4ROS2-Project/mocap_msgs.git
git clone https://github.com/MOCAP4ROS2-Project/mocap.git
cd ..
colcon build
```
> **Uwaga!**  
Jeżeli nie uda się skompilować, należy poprawić plik nagłówkowy w pliku `mocap_ws/src/mocap/mocap_robot_gt/mocap_robot_gt/src/mocap_robot_gt/gt_component.cpp` z ```#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>``` na ```#include <tf2_geometry_msgs/tf2_geometry_msgs.h>```

Następnie zainstalować NatNetSDK
```bash
cd mocap_ws/src/mocap4ros2_optitrack/mocap_optitrack_driver/
python3 install_sdk.py
```

## Konfiguracja w 07 na komputerze `192.168.0.100`
```yaml
mocap_optitrack_driver_node:
  ros__parameters:
    connection_type: "Multicast" # Unicast / Multicast
    server_address: "192.168.0.40"
    local_address: "192.168.0.100"
    multicast_address: "239.255.42.99"
    server_command_port: 1510
    server_data_port: 1511
    rigid_body_name: "ground"
    lastFrameNumber: 0
    frameCount: 0
    droppedFrameCount: 0
    n_markers: 0
    n_unlabeled_markers: 0
    qos_history_policy: "keep_all"         # keep_all / keep_last
    qos_reliability_policy: "best_effort"  # best_effort / reliable
    qos_depth: 10                         # 10 / 100 / 1000
```

## Konfiguracja `motive`
Settings/Streaming:
* **Local Interface:** 192.168.0.40
* **Transmission Type:** Multicast 
* **Rigid Bodies:** ON 
* **Up Axix:** Z-Axis 
* **Commmand Port:** 1510
* **Data Port:** 1511 
* **Multicast Interface:** 239.255.42.99 

## Uruchamianie launchfile sterownika `mocap`
W pliku `mocap_ws/src/mocap4ros2_optitrack/mocap_optitrack_driver/launch/optitrack2.launch.py` odkomentować kod:
```py
driver_activate_trans_event = EmitEvent(
    event = ChangeState(
        lifecycle_node_matcher = launch.events.matchers.matches_action(driver_node),
        transition_id = lifecycle_msgs.msg.Transition.TRANSITION_ACTIVATE,
    )
)
```
i
```py
ld.add_action(driver_activate_trans_event)
```
Następnie wywołać w `mocap_ws`:
```bash
colcon build
source install/setup.bash
ros2 launch mocap_optitrack_driver optitrack2.launch.py
```


