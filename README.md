# IOT : Projet de réservation de salles

Ce répertoire Git contient un projet Arduino permettant de simuler la réservation d'une salle au sein d'un établissement scolaire.

Pour cela, un projet Arduino est connecté à une API connectée à une base de données NoSQL enregistrant les réservations.

L'API est disponible à l'adresse suivante : [IOT-API-ReservationDeSalles](https://gitlab.com/CortoVILAINEPSI/iot-api-reservationdesalles)

Le but de l'application est de permettre à des étudiants de réserver une salle facilement lorsqu'ils sont devant grâce à un écran et quelques boutons. Ils ont alors la possibilité de savoir si la salle est disponible à tel ou tel horaire et dans le cas où elle n'est pas réservée, la réserver.

Une vidéo de présentation et de démonstration est disponible à l'adresse suivante : [Vidéo de démonstration](https://1drv.ms/v/s!AkptWhpP6pvZgdkwfxf7DBEm8aROSA?e=a1v2yz)

Le système de l'Arduino est simple, il contient les éléments suivants :

- 2 leds
- 5 boutons
- 1 écran LCD

L'écran permet l'affichage des différents horaires disponibles ainsi que des différentes classes.
Les leds permettent de savoir si une salle est disponible ou non à un horaire défini.
Les boutons permettent de naviguer dans l'application.


# Langages de programmation

Le projet Arduino est développé en C++.

L'API est développée en Javascript (node.js) via le framework express.js.
