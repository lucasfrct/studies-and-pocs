<?php

class StateMachine
{
    private array $observers = []; // [ function, function ]
    private string $currentStep = '';
    private array $listSteps = [];

    public function subscribe(Closure $fn)
    {
        array_push($this->observers, $fn);
    }

    public function notify()
    {        
        if(!empty($this->currentStep)) {
            foreach($this->listSteps[$this->currentStep] as $step){
                $step($this->currentStep);
            }
            print("<br>notfy => $this->currentStep <br>");
        }
    }

    public function newStep(string $stepName, Closure $fecho)
    {
        $this->listSteps[$stepName] = array_merge(($this->listSteps[$stepName] ?? []), [$fecho]);           
    }

    public function run()
    {
        $this->notify();
    }

    public function next()
    {

        $keys = array_keys($this->listSteps);

        $lengh = count($keys);

        foreach ($keys as $key => $step) {

            if ($this->currentStep == $step && $key < ($lengh - 1)) {
                $pos = $key + 1;
                $this->currentStep = $keys[$pos];
                break;
            }
        }

        if (empty($this->currentStep) && !empty($keys)) {
            $this->currentStep = $keys[0];
        }
    }

    public function prev()
    {

        $keys = array_keys($this->listSteps);

        foreach ($keys as $key => $step) {
            if ($this->currentStep == $step && $key > 0) {
                $pos = $key - 1;
                $this->currentStep = $keys[$pos];
                break;
            }
        }

        if (empty($this->currentStep)) {
            $this->currentStep = $keys[0];
        }
    }
}

