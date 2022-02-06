<?php

require_once("./src/statemachine/State.Machine.php");

$machine = new StateMachine();

$machine->newStep("pendente", fn () => print("01 - step pendente - popula bando de dados<br>"));
$machine->newStep("pendente", fn () => print("02 - step pendente  - envia email <br>"));
$machine->newStep("pendente", fn () => print("03 - step pendente  - envia email <br>"));

$machine->newStep("emTransito", fn () => print("step emTransito<br>"));
$machine->newStep("entregue", fn () => print("step entregue<br>"));

$machine->next();
$machine->notify();

$machine->next();
$machine->notify();

$machine->next();
$machine->notify();

$machine->next();
$machine->notify();

$machine->prev();
$machine->notify();

$machine->prev();
$machine->notify();