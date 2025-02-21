# ML P2 - Perceptron learning rule 
Deze repository bevat de uitwerking voor ML: P2 - Perceptron learning rule in C++. Er wordt gebruik gemaakt van [Catch2](https://github.com/catchorg/Catch2) om de opdrachten te testen. Sommige van deze tests falen, zoals de XOR, omdat dit natuurlijk niet kan met 1 perceptron.

Student: Dylan McGivern<br>
Studentnummer: 1866428

## CMake
Dit project maakt gebruik van CMake om te compilen. Volg de volgende commando's om dit project te compilen (mits je op een UNIX systeem zit):
```bash
mkdir temp/
cd temp/
cmake ..
make
./test
```

## Doxygen
Op het pad `docs/html/index.html` bevindt zich de documentatie voor deze opdracht. Dit bestand bevat documentatie voor alle klassen die zijn gemaakt. Mocht je de documentatie opnieuw willen genereren, gebruik dan de volgende commando (zorg wel dat je doxygen hebt geïnstalleerd op jouw systeem):
```bash
doxygen Doxyfile
```

## Data genereren (optioneel)
De data die nodig is om in te lezen bestaat al in de `data/` directory. Mocht je het zelf willen genereren maak dan eerst een Python virtual environment met de benodigde libraries:
```bash
python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt
```
Hierna kan het `get_data.py` bestand gerunt worden:
```bash
python3 get_data.py
```
Dit genereert `no_virginica.csv` en `no_setosa.csv` in de `data/` directory.
