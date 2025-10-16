# zad 1
wywołanie tego polecenia
```
vcs import --input https://raw.githubusercontent.com/RCPRG-
ros-pkg/STERO2/refs/heads/iron/tiago_public_stero.repos
src
```

miało efekt pobrania potrzebnych pluginów do src

---
# zad 2
te polecenia
```
source /opt/ros/iron/setup.bash
colcon build --symlink-install
```
załadowały środowisko ROS 2 Iron, 
spowodowały zbudowanie wszystkich potrzebnych paczek w katalogu tiago

Co zmienia --symlink-install:
- zamiast kopiować pliki do install/ tworzy dowiązania symboliczne do zbudowanych/źródłowych plików (zwł. dla pakietów Python i zasobów),
- przyspiesza przebudowy i zmniejsza zużycie miejsca; zmiany w plikach Pythona widoczne od razu bez reinstalacji,
- nie zmienia kompilacji; binaria/biblioteki pochodzą z build/.

---

# zad 3

