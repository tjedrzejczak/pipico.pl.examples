# pipico.pl.examples

Repozytorium zawiera kod źródłowy przykładów omówionych na stronie [pipico.pl](https://pipico.pl).
Kompilacji poszczególnych przykładów należy dokonywać z ich folderów.

W folderze picolib znajduje się biblioteka [PicoLib](https://github.com/tjedrzejczak/PicoLib) załączona jako submoduł git.

Przed pierwszą kompilacją należy w folderze, w którym znajduje się `main.c` lub `main.cpp`, wykonać:

```console
mkdir build && cd build
cmake ..
make -j$(nproc)
```

Następne kompilacje wymagają ponownego wykonania w folderze `build` polecenia:

```console
make -j$(nproc)
```

Po szczegóły odsyłam do artykułu [Hello, World! w języku C](https://pipico.pl/2022/04/hello).

Kontakt ze [mną](https://authors/tjedrzejczak) możliwy jest przez [GitHub Discussions](https://github.com/tjedrzejczak/PicoLib/discussions/1).

#### Przykłady

Przykłady użycia biblioteki znajdują się na stronie [pipico.pl](https://pipico.pl/picolib).
