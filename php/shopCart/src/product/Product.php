<?php
require_once("./IProduct.php");

class Product implements IProduct, IControlQuantity { 
    public string $pid = "";

    public string $name = "";
    public string $brand = "";
    public string $type = "";
    public int $quantity = 1;
    public float $price = 9.5;
    public int $limit = 5;
    public float $subTotal = 0;
    public string $color = "transparet";

    public function changePId(string $pid = "") {
        $this->pid = $pid;
    }

    public function add() {
        $this->quantity++;
        $this->quantity = $this->limiter($this->quantity);
    }

    public function sub() {
        $this->quantity--;
        $this->quantity = $this->limiter($this->quantity);
    }

    private function limiter(int $quantity): int {
        
        if($quantity < 1) {
            $quantity = 1;
        }

        if($quantity >= $this->limit) {
            $quantity = $this->limit;
        }

        return $quantity;
    }

    public function resume(): float {
        return $this->subTotal = $this->price * $this->quantity;
    }
}