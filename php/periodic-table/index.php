<?php

require_once("src/crawler/Crawler.php");

/*
    1 - capturar o site
    2 - extrair a informacao
    3 - montar xml
    4 - salvar xml
    5 - montar JSON 
    6 - salvar JSON
    7 - leer dados
    8 - montar e popular tabela
*/

$url = "https://www.todamateria.com.br/tabela-periodica/";
// $folderXML = "./table/periodic.tabel.json";
// $folderJSON = "./table/periodic.table.xml";

$crawler = new Crawler($url);
$crawler->run();
// $crawler->saveXML($folderXML)
// $crawler->saveJSON( $folderJSON)
