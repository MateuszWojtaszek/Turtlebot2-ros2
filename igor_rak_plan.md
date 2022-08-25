
# Sugerowany plan inżynierki

- [Sugerowany plan inżynierki](#sugerowany-plan-inżynierki)
  - [Początkowy opis z propozycji tematu](#początkowy-opis-z-propozycji-tematu)
  - [Plan rozdziałów pracy inżynierskiej](#plan-rozdziałów-pracy-inżynierskiej)
    - [Wprowadzenie](#wprowadzenie)
      - [1.1 Cel i zakres pracy](#11-cel-i-zakres-pracy)
      - [1.2 Realizacja i narzędzia](#12-realizacja-i-narzędzia)
    - [Architektura Robot Operating System 2 (ROS2)](#architektura-robot-operating-system-2-ros2)
      - [Podejście komponentowe do projektów w robotyce](#podejście-komponentowe-do-projektów-w-robotyce)
      - [Podstawowe koncepty komunikacji](#podstawowe-koncepty-komunikacji)
      - [Uruchamianie złożonych systemów robotycznych](#uruchamianie-złożonych-systemów-robotycznych)
    - [Stos nawigacyjny Nav2](#stos-nawigacyjny-nav2)
    - [Robot TurtleBot2](#robot-turtlebot2)
      - [Fizyczny robot w laboratorium](#fizyczny-robot-w-laboratorium)
      - [Model URDF przeznaczony do symulacji](#model-urdf-przeznaczony-do-symulacji)
      - [Oprogramowanie](#oprogramowanie)
    - [Napotkane i rozwiązane problemy](#napotkane-i-rozwiązane-problemy)
      - [Sprzętowe](#sprzętowe)
        - [Sterowniki `kobuki_base`](#sterowniki-kobuki_base)
        - [LiDAR z złączem Ethernet](#lidar-z-złączem-ethernet)
      - [Programowe](#programowe)
    - [Przygotowanie zestawu paczek `turtlebot2`](#przygotowanie-zestawu-paczek-turtlebot2)
    - [Podsumowanie](#podsumowanie)

## Początkowy opis z propozycji tematu

Temat 1:
"Sterowanie robotem mobilnym typu Turtlebot2 z użyciem ROS2 i Nav2"

Zadania w ramach takiego projektu inżynierskiego:

- modernizacja oprogramowania sterowników ROBOTIS Turtlebota 2 z ROS1 Kinetic do ROS2 Galactic/Humble

- zapoznanie z paczkami Nav2 do sterowania robotem mobilnym

- implementacja własnych pluginów w Nav2 (trudniejsze) / scenariuszy na bazie Behavior Tree (łatwiejsze) do zastosowania w Nav2

- dodatkowe (dla najlepszych) udostępnienie open-source pluginów w repozytorium OpenRobotics od ROS-a 2

Student pod nadzorem przygotowuje wg znanych instrukcji przeniesienie sterowników hardware'owych TB2 (ROS1 Kinetic, 2016, już bez wsparcia) na wersję z ROS2 Galactic/Humble (2021/2022, wspierane do 2027). Następnie zapoznaje się z stosem nawigacyjnym Nav2 do sterowania robotem mobilnym i przygotowuje scenariusz jego użycia (np. AMR w magazynie). Jeśli wystarczy czasu, to student może wybrać plugin (fragment oprogramowania) do dodania do pracy i potem jako Pull Request do repozytorium OpenRobotics (ros-planning/Nav2).

## Plan rozdziałów pracy inżynierskiej

Przechodzę w opisie od ogółu do szczegółów, pamiętaj, że to tylko i wyłącznie sugestie, jak ja bym to zrobił na Twoim miejscu. Zwykle w pracy dyplomowej miejsce w swoich rozdziałach mają:

- wprowadzenie/wstęp z uzasadnieniem wyboru takiego, a nie innego tematu, jego znaczenie w dziedzinie robotyki, to tutaj przeważnie wspomina się najwięcej źródeł poza rozdziałami z teorią - umiejscawiasz swoją pracę w konkretnej gałęzi robotyki, wprowadzasz ogólnikowo cel pracy i wyjaśniasz znaczenie swoich rozwiązań i osiągnięć w ramach projektu inżynierskiego/badawczego, zarysowujesz wykorzystane narządzia i układ rozdziałów z ich zawartością

- teoria - wprowadzasz tutaj definicje i określenia używane dalej do komunikowania informacji czytelnikowi w kolejnych częściach pracy, wyjaśniasz ogólną postać projektu/systemu, podstawy użytych technologii, osobno ich znaczenie w Twojej pracy (najlepiej z przykładami); tutaj może trafić już w pełni konkretny opis celu pracy

- praktyka/implementacja, wykonana praca w ramach oprogramowania i sprzętu, tutaj opierasz się na definicjach wprowadzonych w rozdziale o teorii, zakładając, że czytelnik już +- wie, o co chodzi; opisane tutaj mogą być także napotkane problemy i ślepe uliczki w przeprowadzonej pracy i badaniach, których podkreślenie wyjaśni część decyzji projektowych dalej lub zaznaczy interesujące problemy badawcze.

### Wprowadzenie

Tutaj powinien być ogólny zarys i argumenty za chęcią uzyskania modułowości dla systemów robotycznych o większej złożoności (manipulatory, roboty mobilne, systemy wizyjne, systemy lokalizacji itd.), zachęty do pisania i udostępniania paczek oprogramowania, które są możliwe do ponownego użycia przez innych, do tego są przeważnie open-source, można skontatkować się z ich autorami w miarę możliwości, powstrzymują zjawisko "wynajdywania koła na nowo", pozwalają na łatwiejszą integrację między różnymi projektami i grupami badawczymi na uczelniach i w przemyśle (hasła: ROS Industrial, kilka większych projektów związanych z przemysłem adaptującym ROS też się nada, są 2 główne publikacje o ROS1 i ROS2, gdzie są charakteryzowane całkiem dobrze). Potem możesz wspomnieć, że to bardzo aktywnie rozwijająca się dziedzina i utrzymanie robotycznego sprzętu w działaniu wymaga często bieżącej pracy nad sprzętem i oprogramowaniem, aby korzystać z jej najnowszych zdobyczy.

#### Cel i zakres pracy

Po uzasadnieniu, dlaczego open-source jest ważny, przedstawiasz w liściue obecny stan laboratorium, sprzętowy i programowy (ROS1 Kinetic, Ubuntu 16.04, flota robotów mobilnych Turtlebot 2 + ich czujniki) i przedstawiasz plan swojej pracy w tym projekcie (na bazie tego, co już mamy na razie byłoby ok, potem się to poprawi i doda wszystko). To ostatnie zadanie z pluginem dodasz, jak się uda, wiadomo :) Ale już samo przygotowanie scenariusza w symulacji plus nagranie filmiku z laboratorium a la digital twin byłoby w sam raz na inżynierkę dobrą.

#### Realizacja i narzędzia

Tutaj lecisz __zwięzłą__ listą wypunktowaną, co udało się zrobić i w którym rozdziale/sekcji których rozdziałów jest tego opis, sposoby użycia + schematy z dokumentacji itd. Wrzuciłem Ci moją magisterkę, abyś zobaczył, jak ona wyglądała, możesz sobie podejrzeć, co było uznane przez Profesor za dobry układ pracy (chociaż akurat tylko z symulacjami, bez sprzętu).
W opisie narzędzi wymieniasz wszystkie wersje: oprogramowania, ROS-a, model robota i sprzęt na nim.

### Architektura Robot Operating System 2 (ROS2)

To ten rozdział, gdzie opisujesz ROS-a 2 - tutaj są najważniejsze podrozdziały teoretyczne (więcej o każdym podrozdziale będzie w kolejnych sekcjach niżej,) moim zdaniem to w kolejności:

* opis ogółem podejścia komponentowego do projektów w robotyce, jego zalet i tego, że ROS takie coś spełnia,
* .

Przed pierwszym podrozdziałem jak zawsze dalej daj 1-2 zdania o tym, co jest w tym rozdziale (np. "W tym rozdziale opisana jest architektura Robotic Operation System, jej podstawowe komponenty i mechanizmy działania. Opisano tutaj także najważniejsze różnice między odchodzącym do lamusa ROS 1 a nastawionym na przyszłość i przemysł ROS 2")

#### Podejście komponentowe do projektów w robotyce

Ten kurs ROS2 z Udemy, co Ci kiedyś wysłałem, dobrze to na początku pokazał, na typowym przykładzie z życia - można by taką luźną historią też tutaj zacząć, jak wygląda bez podejścia komponentowego życie projektów robotycznych - na początku jest prosto i taki program-monolit z kilkoma klasami, potem jednak dodaje się coraz więcej sterowników do silników, implementowanych w różnych językach, masa różnych czujników, kamery, ogółem, pojawia się wynajdywanie koła na nowo, ostatecznie program robi się spaghetti bug-lognese, ciężko wymienić cokolwiek, czujnik zepsuty, inną kamerę, samo utrzymanie kodu tworzy problemy; a kiedy nadchodzi ten czas każdego projektu, jego koniec, to człowiek zostaje z kodem trudnym do użycia gdziekolwiek ponownie.
I właśnie wtedy wchodzi on, cały na biało, ROS (zarówno 1, jak i 2 tu pasują, o tym więcej za moment. Opisujesz tutaj potem tego zalety, możliwość wykorzystania bogatej biblioteki paczek open-source, doświadczenia innych użytkowników-robotyków, modułowość projektu i jego dłuższe życie. Przy tym dłuższym życiu możesz też wspomnieć, że stare roboty też są jeszcze jare, jak się o nie odpowiednio zadba - chodzi oczywiście od Turtleboty 2 tutaj, wiadomo.

Potem wchodzi opis pojęć z grafikami z tej publikacji o ROS 2...

#### Podstawowe koncepty komunikacji

I tutaj lecisz tak, jak już na Overleafie praktycznie już masz - zaczynasz od node'a, potem definicje wiadomości (ang. messages), następnie topic i service, potem action. Twój spis pojęć jest całkiem ok pomysłem. Dodałbym tam także akronimy, jakich będziesz ewentualnie dalej używać (np. DDS przy wyjaśnianiu decentralizacji ROS2 jako ważnej różnicy względem ROS1, launcher/launch file).
Mam trochę uwag do tego, jak napisałeś te fragmenty tam, ale to na jakimś Zoomie sobie przejrzymy to we dwóch, z nagrywaniem kamery, abyś potem mógł to sobie odsłuchiwać i mieć notki.

#### Uruchamianie złożonych systemów robotycznych

Dziesiątki node'ów w systemie? Proste! Tutaj daj opis launcherów w Pythonie i możliwość używania tych samych skryptów do symulacji w Gazebo i na rzeczywistym robotcie, to całkiem ważne dalej do efektów Twojej pracy.

### Stos nawigacyjny Nav2

W tym rozdziale skupiłbym się na podstawowych składnikach potrzebnych do uruchomienia Nav2 na TB2 - to właśnie te trzeba by sensownie opisać, głównie na bazie dokumentacji (tekst + grafiki) oraz cytując tę publikację "The Marathon 2: A Navigation System" (S. Macenski __et al.__) wspomnianą [tutaj pod filmikiem](https://navigation.ros.org/). Dłuższy podrozdział o BT mógłby być przydatny, jeśli zdążysz przygotować scenariusz z jakimiś nieco bardziej złożonym, customowym Behavior Tree, jeśli nie, to wystarczy wtedy opis BT ogółem plus opis użycia `navigate_through_poses_w_replanning_and_recovery.xml` jako BT w [NavigateToPose](https://navigation.ros.org/configuration/packages/bt-plugins/actions/NavigateToPose.html?highlight=navigatetopose).

### Robot TurtleBot2

#### Fizyczny robot w laboratorium

#### Model URDF przeznaczony do symulacji

#### Oprogramowanie

### Napotkane i rozwiązane problemy

#### Sprzętowe

##### Sterowniki `kobuki_base`

##### LiDAR z złączem Ethernet

#### Programowe

### Przygotowanie zestawu paczek `turtlebot2`

### Podsumowanie
