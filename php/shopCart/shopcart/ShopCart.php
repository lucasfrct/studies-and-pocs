<?php

class ShopCart {
    
    public float $cupom = (32.63);
    public int $numPortion = 1;
    private float $total = 0;
    private float $subTotalProducts = 0;
    
    private Product $product;
    private $products = [];
    private Address $address;
    private Freight $freight;

    public function addProduct(Product $product) {
        //$this->product = $product;
        array_push($this->products, $product);
    }

    public function addAddress(Address $address) {
        $this->address = $address;
    }

    public function addFreight(Freight $freight) {
        $this->freight = $freight;
    }

    public function subTotal() {

    }

    public function resume() {

        foreach($this->products as $product) {
            $this->subTotalProducts += $product->resume();
        }

        return $this->total = $this->subTotalProducts + $this->freight->value - $this->cupom;
    }

};