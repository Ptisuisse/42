#!/bin/bash

# Chemin vers le dossier contenant les maps .ber
MAPS_DIR="./maps/valid"

# Boucle à travers chaque fichier .ber dans le dossier des maps
for map in "$MAPS_DIR"/*.ber; do
    echo "Test de la map: $map"
    ./so_long "$map"
    echo "Test terminé pour: $map"
    echo "--------------------------------"
done
