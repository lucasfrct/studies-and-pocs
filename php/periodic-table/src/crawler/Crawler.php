<?php

class Crawler {
    private string $url = "";
    private DOMDocument $dom;
    private array $atomsPool = array();

    public function __construct(string $url) {
        $this->url = $url;
    }

    public function run() {
        $this->dom = new DOMDocument('1.0');
        @$this->dom->loadHTMLFile($this->url);

        $this->sweep();
        $this->show($this->atomsPool);
    }
    
    /* 
    * Varre o HTML, procura o element ID e captura os atributos
    * @param string $element 
    * @return array $atom
    */
    public function fillAtom(string $element): array {

        try {
            $atom = $this->dom->getElementById($element);

            if ($atom == new stdClass()) { throw new Exception("elemento Inválido"); }
            
            $atomAssembler = [];
            $atomAssembler["name"]      = $atom->getAttribute("data-name");
            $atomAssembler["symbol"]    = $atom->getAttribute("data-symbol");
            $atomAssembler["number"]    = $atom->getAttribute("data-atomicnumber");
            $atomAssembler["mass"]      = $atom->getAttribute("data-atomicmass");
            $atomAssembler["ec"]        = $atom->getAttribute("data-ec");
            $atomAssembler["family"]    = $this->selectFamily($atom->getAttribute("class"));

        } catch(Exception $error) {
            print("ERROR: "+$error->getMessage());
        }

        return  $atomAssembler;
        
    }

     /*
     * seleciona a familia dos atomos com base na class fo element
     * @param string $classRef
     * @return string (family category) 
     */
    public function selectFamily(string $classRef) {
        $classRef = trim(str_replace("element", "", $classRef));

        switch($classRef) {
            case "e_7":
                return "não metais";
                break;
            default:
                return "";
                break;
        };
    }

    private function show($value) {
        echo "<pre>";
        var_dump($value);
        echo "</pre>";
    } 

    /*
    * varre a dom HTML e retorma todos os elemetos da tabela
    */
    private function sweep() {
        $limit = 118;
        for($i = 1; $i <= $limit; $i++) {
            $this->atomsPool[] = $this->fillAtom("element_".(string)$i);
        }
    }
}
