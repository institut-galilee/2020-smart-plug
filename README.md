# Smart-Plug
les prises connectées sont des dispositifs de smart home très simples d'utilisation. Une connexion à internet et un smartphone suffisent pour diriger les appareils et accessoires électriques dans la maison, sans avoir à dépenser des milliers d'euros dans une installation domotique complexe.


# Rapport

<h1>Introduction</h1>

<p>De nos jours les objets connectés prennent une place incontestable dans le quotidien d’un bon nombre de personnes par leurs utilité et leurs facilité d’utilisation.</p>
<p>Les objets connectés produisent de grandes quantités de données dont le stockage et le traitement entrent dans le cadre de ce que l'on appelle les big data. En logistique, il peut s'agir de capteurs qui servent à la traçabilité des biens pour la gestion des stocks et les acheminements. Dans le domaine de l'environnement, il est question de capteurs surveillant la qualité de l'air, la température, le niveau sonore, l'état d'un bâtiment, etc.</p>
<p>Nous avons donc intégré cette option qui est l’internet des objets, qui définit les bases de conception et de réalisation d’un objet connecté, et nous avons opté pour un projet qui est en vogue ces dernières années et qui est une partie importante du dispositif d’une maison intelligente, à savoir une prise connecté.</p>


<h1>Description du projet</h1>

<p>L’idée nous ai venue à la suite du désagrément que tout un chacun a chez lui lorsqu’il aimerait par « magie » gérer sa prise sans devoir se déplacer, tout consiste a réalisé une prise connecté qu’on pourra gérer à partir de son téléphone ou de son ordinateur, il existe aujourd’hui pas mal de production industriel dans le domaine avec des géant comme Belkin ou TP Link et pleins d’autres.
Notre but a travers ce projet est de réalisé un prototype minimaliste de ce qui existe déjà sur le marché, en utilisant des matériaux simple et un microcontrôleur.</p>
<h2>Scenario d’utilisation</h2>
<p>L’utilisateur connecte sa prise au courant pour l’alimenter, cette dernière démarrera et activera sa connexion wifi, l’utilisateur se connectera à la prise et aura donc une interface web pour la gérer il pourra :</p>
<ol>
<li>Allumer ou éteindre la prise : en se connectant a l’interface web de la prise l’utilisateur trouvera deux bouton on/off qui lui permettront d’allumer en appuyant sur on et d’éteindre en appuyant off</li>
<li>Chronométré le temps d’utilisation : lors du lancement en mode on de notre prise, un chronomètre se lancera et affichera le temps d’utilisation exacte de la prise.</li>
<li>Mesure de consommation électrique</li>
</ol>



<h1>Etat de l’art</h1> 
<h2>Solutions Existante</h2>
<p>Il existe aujourd’hui un bon nombre de grand groupe qui travail sur les maison en connecté et en particulier sur les prises connectées, plusieurs solutions sont offertes avec pour chacune des fonctionnalité en plus ou en moins, on va donc essayer de faire un petit top 3 des produit les mieux vendu en France dans le domaine</p>
<ol>
<li><strong>Belkin WeMo Insight :</strong> </br><img src = "https://github.com/institut-galilee/2020-smart-plug/blob/master/doc/belkin.png" title = "belkin" alt = "belkin"></li>

<ol type="a">
<li><strong>Description</strong></li>
<p>Belkin est une marque américaine spécialisée dans la fabrication de matériel informatique. D'abord spécialisée dans la connectique informatique, l'entreprise, basée à Los Angeles, s'est diversifiée et propose aujourd'hui des accessoires téléphoniques et réseaux. Elle ne manque pas à l'appel en matière de prises connectées, accessoires de plus en plus en vogue.</p>
<li><strong>Fonctionnalité</strong></li>
<p>Elle est appréciée du grand publique pour sa complétude, elle offre plusieurs fonctionnalité, elle propose donc une application de gestion d’une simplicité qui fait son succès, elle se connecte en wifi, l’application permet donc une gestion à distance de la prise et un enregistrement des temps d’activité mais aussi les temps de veilles, elle est aussi capable de se couplet avec des applications IFTT (des applications « IF THEN ELSE ») </p>
<li><strong>Ordre de prix </strong></li>
<p>45 euros</p>

</ol>



<li><strong>Tp-link HS100 :</strong></br><img src = "https://github.com/institut-galilee/2020-smart-plug/blob/master/doc/tplink.jpg" title = "tplink" alt = "tplink"></li>
<ol type="a">
<li><strong>Description :</strong></li>
 
<p>TP-Link a fait des outils technologiques sa spécialité. Comme bon nombre de ses concurrents, l'entreprise chinoise s'est lancée dans le secteur des prises connectées en concevant son modèle : la prise connectée TP-Link HS100.</p>

<li><strong>Fonctionnalité :</strong></li>

<p>Pour l'installation, il faut télécharger l'application Kasa, qui permettra de contrôler à distance la prise et de la lier au réseau Wi-Fi domestique en connexion directe
Le gros point fort de cette prise est la possibilité de la gérer vocalement avec Alexa ou Google Home, mais elle propose aussi l’allumage a distance ou programmé, mais aussi la création de scène par exemple crée une scène « coucher » qui éteindra tout a une heure précise </p>
<li><strong>Ordre de prix :</strong></li>
<p> 37.98 euros </p> 
</ol>

<li><strong>Bosch Smart Plug :</strong><img src = "https://github.com/institut-galilee/2020-smart-plug/blob/master/doc/bosch.png" title = "bosch" alt = "bosch"></li>
<ol type "a">	
<li><strong>Description</strong></li>
<p>On ne présente plus la marque Bosch. L'enseigne tentaculaire allemande s'est imposée dans tous les secteurs de l'équipement intérieur, et les prises connectées ne font pas exception. En juillet 2017, Bosch sort sa prise « Bosch Smart Plug », avec la même ambition que nos voisins outre-Rhin : fournir tous les éléments domotiques permettant d'autonomiser une maison connectée.</p>
<li><strong>Fonctionnalité</strong></li> 
<p>Du côté des fonctionnalités, l'application Bosch reste très traditionnelle. Il est donc possible d'allumer et d'éteindre la prise et un clic, de lire les données de consommation en temps réel, et de programmer une mise en route/un arrêt à une heure précise. Une fonctionnalité pratique pour mettre en route sa machine à café le matin à telle heure et la faire s'arrêter 15 minutes après, par exemple
Elle propose le minimum mais Bosch mais le point sur la protection des données de leurs utilisateurs </p>
<li><strong>Ordre de Prix :</strong></li> 
<p>85.20 euros</p>



</li>

</ol>
<p>On aussi plein d’autre produit qui font la concurrence avec différentes marque comme : Elgato Eve Energy, Konyks Priska Mini, AwoxSmartPlug, Koogeek, Horsky Prise Connecté, Osram Smart +, BeeWi SmartPlug.</p>
<h1>Etude Fonctionnelle</h1>
<h2>Diagramme de cas d’utilisation</h2> 
<img src = "https://github.com/institut-galilee/2020-smart-plug/blob/master/doc/diag.png" title = "diag" alt = "diag">
<h2>Prototypage Fritzing</h2>
<img src = "https://github.com/institut-galilee/2020-smart-plug/blob/master/doc/firtz.png" title = "fritz" alt = "fritz">

<h1>Fonctionnalité</h1> 

<h2>Matériels utilisés</h2> 
<ol type"1">
<li><strong>Un microcontrôleur :</strong></li>
<img src = "https://github.com/institut-galilee/2020-smart-plug/blob/master/doc/micro.png" title = "google logo" alt = "Google logo">
<p>ESP32 qui nous a été remis par l’université au début du semestre</p>
<li><strong>Relay :</strong></li>
<img src = "https://github.com/institut-galilee/2020-smart-plug/blob/master/doc/relay.png" title = "google logo" alt = "Google logo">
<p>Afin de relier le microcontrôleur a la prise et il a couté 3 euros</p>
<li><strong>Capteur de courant :</strong></li> 
<img src = "https://github.com/institut-galilee/2020-smart-plug/blob/master/doc/capt.png" title = "google logo" alt = "Google logo">
<p>Pour pouvoir mesurer la consommation électrique, il a couté 3euros</p>
<li><strong>Cable pour connecter le tout :</strong></li> 
<p>fourni par l’université</p>
<li><strong>Barrette pour disposer le contrôleur et les composant :</strong></li>
<p>fourni par l’université</p> 
</ol>

<h2>Photo du Produit</h2>

<img src = "https://github.com/institut-galilee/2020-smart-plug/blob/master/doc/image1.jpg" title = "google logo" alt = "Google logo">
<img src = "https://github.com/institut-galilee/2020-smart-plug/blob/master/doc/image2.jpg" title = "google logo" alt = "Google logo">
<img src = "https://github.com/institut-galilee/2020-smart-plug/blob/master/doc/image3.jpg" title = "google logo" alt = "Google logo">

<h2>interface web</h2>

<img src = "https://github.com/institut-galilee/2020-smart-plug/blob/master/doc/image4.jpg" title = "google logo" alt = "Google logo">
<img src = "https://github.com/institut-galilee/2020-smart-plug/blob/master/doc/image5.jpg" title = "google logo" alt = "Google logo">

<h1>Conclusion</h1>
<p>Pour conclure, on commence tout d’abord par remercier Mr Osmani et Mr Hamidi de nous avoir permis de travailler sur de tels sujets mais aussi pour leur implications et les cours dispensé.
Par ailleurs, a travers ce cour et ce projets nous avons eu l’occasion de découvrir un univers qu’on ne connaissait que de nom, on a abordé une thématique du quotidien, et l’avons résolu avec les moyens du bord.</p>
<p>Ce projet nous a ouvert les porte vers un peu d’électronique puisque on a pu faire quelque recherche sur les capteur et comment brancher le system, nous avons aussi appris à réaliser un état de l’art avec les solutions existante sur le marché.</p>
<p>Nous espérons pouvoir apporter plein d’autre amélioration a notre produit par la suite en y ajoutant quelque fonctionnalité en vogue ces dernière année comme la commande vocal.</p>
