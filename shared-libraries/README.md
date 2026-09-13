# Shared libraries

Librerie scritte da me e riutilizzate in più progetti Arduino.

Ogni libreria in una sua sottocartella, seguendo la struttura standard di una libreria Arduino:

```
shared-libraries/
└── NomeLibreria/
    ├── NomeLibreria.h
    ├── NomeLibreria.cpp
    ├── library.properties
    └── examples/
```

Per usarla in uno sketch, o la copi in `~/Arduino/libraries/`, oppure (consigliato se usi PlatformIO) la referenzi come `lib_extra_dirs`.
