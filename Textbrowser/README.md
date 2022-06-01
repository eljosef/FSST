# Programmieraufgabe Textbrowser

Basierend auf dem vorliegenden Qt-Programmgerüst soll ein grafischer Webclient mit Ausgabe des Website-Quelltextes programmiert werden. 
(lauffähiges Beispielprogramm im Unterverzeichnis `bin`)

## Lösungsschritte
1. Logge dich auf deinem Account auf github über den Webbrowser ein
2. Navigiere mit dem Browser zu diesem Repository: 
 https://github.com/eneukirchner/Textbrowser 
3. Erstelle einen Fork davon auf deinem github-Account (fork-Button rechts oben auf der github-Website).
4. Kopiere den Fork auf deinen Raspberry: `git clone git@github.com:<dein Accountname>/Textbrowser.git` 
   In dem dadurch erzeugten Ordner befindet sich das Projekt. 
5. Das resultierende grafische Programm soll in der Funktionalität der Vorlage entsprechen. Erstelle den  C++ - Quellcode, sodass nach Eingabe des Hostnamens und Drücken des "go!"- Buttons die Antwort des Servers im Textformat erscheint. Falls keine Verbindung mit dem Server zustande kommt, soll nach einem Timeout von einigen Sekunden die Meldung "connect failed!" im textBrowser-Fenster erscheinen.  
6. Die HTTP-Netzwerkfunktionalität soll in der Klasse `HttpClient` umgesetzt werden.  
*Tipp: Die Funktion `write` von `QTcpSocket` verlangt für den Hostnamen einen String vom Typ `QByteArray`. Die Umwandlung
von `QString` kann mit der Funktion `toUtf8()` bewerkstelligt werden*
7. Abgabe: **10 min** vor Schluss (wird angesagt). **Achtung: frühere Abgaben werden nicht gewertet! Abgaben nach
   Abgabeschluss ebenso nicht.** 
```
git add .
git commit -m "Abgabe"
git push origin main
```

