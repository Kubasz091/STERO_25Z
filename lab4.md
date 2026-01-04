# Sprawozdanie z Laboratorium 4 STERO

## 1. Konfiguracja Środowiska

Zgodnie z instrukcją, przygotowano przestrzeń roboczą dla symulacji robota TIAGo. Proces obejmował:

1.  Pobranie repozytorium tiago przy użyciu komendy `vcs import --input https://raw.githubusercontent.com/RCPRGros-pkg/STERO2/refs/heads/iron/tiago_public_stero.repos
src
`
2.  Kompilację pakietów w workspace przy użyciu `colcon build`.
3.  Konfigurację zmiennych środowiskowych (`source install/setup.bash`).

## 2. Uruchomienie Symulacji

Symulacja została uruchomiona z pełnym stosem nawigacyjnym oraz planowaniem ruchu.

**Użyta komenda:**

```bash
ros2 launch tiago_gazebo tiago_gazebo.launch.py navigation:=True moveit:=True is_public_sim:=True
```

W celu weryfikacji drzewa transformacji (TF) użyto narzędzia:

```bash
ros2 run rqt_tf_tree rqt_tf_tree --force-discover
```

### Analiza Drzewa Transformacji

Na podstawie wygenerowanego grafu `tf_tree.pdf`, struktura układów współrzędnych robota TIAGo prezentuje się następująco:

1.  **Globalne Układy Odniesienia:**

    - `map`: Główny, statyczny układ współrzędnych mapy. Jest korzeniem drzewa w przypadku uruchomionej nawigacji.
    - `odom`: Układ odometrii. Transformacja `map` -> `odom` jest dynamiczna i korygowana przez system lokalizacji, niwelując błędy dryfu odometrii.

2.  **Podstawa Robota:**

    - `base_footprint`: Rzut środka robota na płaszczyznę podłoża. Transformacja `odom` -> `base_footprint` jest publikowana przez kontroler podwozia (`mobile_base_controller`) na podstawie enkoderów kół.
    - `base_link`: Główny człon fizyczny robota, sztywno połączony z `base_footprint`.

3.  **Łańcuchy Kinematyczne:**

    - **Tułów:** `torso_lift_link` (ruchomy w osi Z).
    - **Głowa:** `head_1_link`, `head_2_link` (pan/tilt).
    - **Ramię:** Seria ogniw `arm_1_link` do `arm_7_link`, zakończona punktem `wrist_ft_link` (czujnik siły/momentu).
    - **Chwytak:** Zamocowany bezpośrednio za `wrist_ft_link`. Składa się z bazy (`gripper_link`) oraz ruchomych palców (`gripper_left_finger_link`, `gripper_right_finger_link`).

4.  **Sensory:**
    - **LiDAR:** `base_laser_link` - umieszczony w podstawie.
    - **Kamera RGB-D:** `head_front_camera_link` (oraz ramki optyczne `_optical_frame`) - umieszczona na głowie, porusza się wraz z nią, dostarczając obraz i chmurę punktów w odniesieniu do aktualnej pozycji głowy.

Drzewo jest spójne (jeden korzeń), co oznacza, że wszystkie transformacje są poprawnie publikowane, umożliwiając działanie algorytmów planowania ruchu (MoveIt) oraz nawigacji.

_Pełne drzewo transformacji zostało wyeksportowane do pliku `tf_tree.pdf`._

## 3. Analiza Systemu i Sensorów

Przeprowadzono weryfikację dostępnych tematów ROS 2 oraz poprawności danych z sensorów.

| Komponent          | Temat (Topic)                                | Typ Wiadomości                | Status     |
| :----------------- | :------------------------------------------- | :---------------------------- | :--------- |
| **Sterowanie**     | `/cmd_vel`                                   | `geometry_msgs/msg/Twist`     | Oczekujący |
| **Odometria**      | `/mobile_base_controller/odom`               | `nav_msgs/msg/Odometry`       | **OK**     |
| **LiDAR**          | `/scan_raw`                                  | `sensor_msgs/msg/LaserScan`   | **OK**     |
| **Kamera RGB**     | `/head_front_camera/rgb/image_raw`           | `sensor_msgs/msg/Image`       | **OK**     |
| **Chmura Punktów** | `/head_front_camera/depth_registered/points` | `sensor_msgs/msg/PointCloud2` | **OK**     |

## 4. Implementacja Algorytmu Sterowania (Hexagon)

W celu realizacji zadania poruszania się po zadanej trajektorii (sześciokąt), zaimplementowano dedykowany węzeł ROS 2 w języku C++: `hexagon_mover.cpp`.

**Kluczowe cechy implementacji:**

- **Typ węzła:** `rclcpp::Node` o nazwie `hexagon_mover`.
- **Komunikacja:**
  - Publikacja sterowania prędkością na temat `/cmd_vel` (`geometry_msgs/msg/Twist`).
  - Subskrypcja odometrii z `/mobile_base_controller/odom` (do logowania pozycji).
- **Algorytm:** Prosta maszyna stanów oparta na czasie.
  - Stan 0: Jazda prosto przez wyliczony czas `move_time_`.
  - Stan 1: Obrót o 60 stopni (PI/3) przez czas `turn_time_`.
- **Parametry:** Prędkość liniowa `0.4 m/s`, prędkość kątowa `0.4 rad/s`.

Kod źródłowy węzła znajduje się w pliku `src/lab1_pkg/src/hexagon_mover.cpp`.

## 5. Weryfikacja Wizualna

Poniżej przedstawiono zrzuty ekranu dokumentujące wykonanie zadań w środowisku symulacyjnym.

### Zadanie: Hexagon

![Wizualizacja: Hexagon - Wynik](photos/zad_hex/path_result.png)
![Wizualizacja: Hexagon - Odometria](photos/zad_hex/path_odometry.png)

## 6. Plan Testów i Weryfikacja Wymagań (SysML)

Struktura wymagań oraz planowane przypadki testowe zostały zamodelowane w notacji SysML.

```mermaid
classDiagram
    %% --- Definicje Stylów ---
    classDef requirement fill:#FFF9C4,stroke:#FBC02D,stroke-width:2px,color:black;
    classDef testcase fill:#E1F5FE,stroke:#0288D1,stroke-width:1px,color:black;
    classDef hardware fill:#E0E0E0,stroke:#616161,stroke-width:1px,stroke-dasharray: 5 5;

    %% --- Pakiet Wymagań (Co robot ma robić?) ---
    namespace Wymagania_Systemowe {
        class Percepcja {
            <<Requirement>>
            Wykrywanie przeszkód (ścian)
            Source: LiDAR / Proximity
        }
        class Autonomia {
            <<Requirement>>
            Bezpieczny przejazd A -> B
            Constraint: Zero kolizji
        }
        class Sterowanie {
            <<Requirement>>
            Manualna kontrola prędkości
            Interface: cmd_vel
        }
    }

    %% --- Pakiet Testów (Twoje scenariusze) ---
    namespace Kampania_Testowa_Symulacja {
        class Weryfikacja_Dzialania_Sensorow {
            <<TestCase>>
            Tools: Gazebo (World) + RViz
            Input: Postawienie ściany przed robotem
            Check: Wizualizacja chmury punktów/LaserScan
        }
        class Nawigacja_z_Omijaniem_Przeszkod {
            <<TestCase>>
            Tools: Navigation Stack
            Input: Goal Pose (za przeszkodą)
            Check: Robot planuje trasę dookoła
        }
        class Teleoperacja_z_Klawiatury {
            <<TestCase>>
            Tools: teleop_twist_keyboard
            Input: Klawisze i, j, k, l, u, o
            Check: Robot porusza się zgodnie z komendą
        }
    }

    %% --- Relacje Weryfikacji (Traceability) ---
    Weryfikacja_Dzialania_Sensorow ..|> Percepcja : verify
    Nawigacja_z_Omijaniem_Przeszkod ..|> Autonomia : verify
    Nawigacja_z_Omijaniem_Przeszkod ..|> Percepcja : uses
    Teleoperacja_z_Klawiatury ..|> Sterowanie : verify
```

## 7. Kampania Testowa

Film prezentujący przebieg wszystkich zaplanowanych testów w symulatorze.

**https://drive.google.com/file/d/1WWmyXD8RajXPDPjqZDHNNPUAdfkwYrC2/view?usp=sharing**
