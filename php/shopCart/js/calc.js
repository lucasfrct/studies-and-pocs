
/*
    CALC 
        -> DISPLAY
        -> TECLADO
        -> CONTROL BAR
        --> SUM
        --> SUBTRACT
        --> MULTIPLY
        --> DIVISION
        >> SUPORT EXPRESSOIN
*/

class Calculator {
    
    layout = {
        root: '',
        minimize: '',
        maximize: "",
        close: ""
    }

    processor = {
        registrator: 0,
        accumulator: {
            l1: [],
            l2: [],
            l3: [],
            l4: []
        },
        alu: {
            "sum": (arr = [])=> {
                return arr.reduce((a, b)=> { return Number(a) + Number(b) })
            },
            "mul": (arr = [])=> {
                return arr.reduce((a, b)=> { return Number(a) * Number(b) })
            },
            "div": (arr = [])=> {
                return (arr.length >= 2 && arr[1] != 0) ? (arr[0] / arr[1]) : 0
            },

            "rst": (arr = [])=> {
                this.processor.opcode = []
                this.processor.accumulator.l1 = []
                this.processor.accumulator.l2 = []
                this.processor.accumulator.l3 = []
                this.processor.accumulator.l4 = []
                this.registrator = ""
            }
        },
        opcode: [],
        lifecycle: (value)=> {

            let instruction = this.processor.instructionFilter(value)
            let num = this.numberFilter(value)
            
            
            if(instruction != "") {
    
                this.processor.opcode.push(instruction)
                let numConcret = this.processor.accumulator.l1.join("")

                this.processor.accumulator.l4.forEach((val)=> {
                    if(val == "-") {
                        numConcret = -numConcret
                    }
                })
                this.processor.accumulator.l3.push(numConcret)
                this.processor.accumulator.l1 = []
            }
            
            if(num) {
                this.processor.accumulator.l1.push(Number(num))
            }

            if(value.trim() != '=')  {
                this.processor.accumulator.l2.push(value)
                this.processor.registrator = this.processor.accumulator.l2.join('')
            }

            if(value.trim() == "-") {
                this.processor.accumulator.l4.push(value)
            }

            if(this.processor.opcode.length > 0) {
                let instructions = []
                this.processor.opcode.forEach((instruction)=> {
                    
                    if(instruction == "eql") {
                        instructions.forEach((inst)=> {
                            this.processor.registrator = this.processor.alu[inst](this.processor.accumulator.l3) 
                        })
                        
                    } else {
                        instructions.push(instruction)
                    }

                    if(instruction == "rst") {
                        this.processor.registrator = "0"
                        this.processor.alu[instruction]([])
                    }
                })
            }
        },

        instructionFilter: (value)=> {

            switch(value) {
                case "+":
                    return "sum"
                    break
                case "-":
                    return "sum"
                    break
                case "x":
                    return "mul"
                    break
                case "/":
                    return "div"
                    break
                case "=":
                    return "eql"
                    break
                case "C":
                    return "rst"
                    break
                default:
                    return ""
                    break
            }

        }

    }
    
    display = ""

    keyboard = ['x^2', 'x^y', 'sin', 'cos', 'tan', 'sqrt', '10^x', 'log', 'Exp', 'Mod', '->', 'CE', 'C', '<-', '/', 'PI', '7', '8', '9', 'x', 'n!', '4', '5', '6','-', '+-', '1', '2', '3', '+', '(', ')', '0', ',', '=']

    constructor(element) {
        this.mount(element)
    }
    
    mount(element) {

        var that = this 

        this.layout.root = document.querySelector(element)
        this.layout.root.classList.add("calculator")

        var barWindow = document.createElement("div")
        barWindow.classList.add('bar', 'context')

        var title = document.createElement("span")
        title.innerHTML = "Calculadora"

        this.layout.minimize = document.createElement("a")
        this.layout.minimize.innerHTML = '_'
        this.layout.minimize.addEventListener('click', ()=> {
            this.minimize()
        })

        this.layout.maximize = document.createElement("a")
        this.layout.maximize.innerHTML = "|_|"
        this.layout.maximize.addEventListener('click', ()=> {
            this.maximize()
        })

        this.layout.close = document.createElement("a")
        this.layout.close.innerHTML = "x"
        this.layout.close.addEventListener('click', ()=> {
            this.close()
        })

        barWindow.append(title)
        barWindow.append(this.layout.minimize)
        barWindow.append(this.layout.maximize)
        barWindow.append(this.layout.close)

        var screen = document.createElement('div')
        screen.classList.add('screen')

        var barScreen = document.createElement('div')
        barScreen.classList.add('bar')

        var menu = document.createElement('a')
        menu.innerHTML = "="
        menu.classList.add('menu')

        var span = document.createElement('span')
        span.innerHTML = "Cientifica"

        var history = document.createElement('a')
        history.classList.add("history")
        history.innerHTML = "<->"

        barScreen.append(menu)
        barScreen.append(span)
        barScreen.append(history)

        var display = document.createElement('div')
        display.classList.add('display')
        display.innerHTML = "0"

        screen.append(barScreen)
        screen.append(display)

        var keyboard = document.createElement('div')
        keyboard.classList.add('keyboard')

        var controlKeyboard = document.createElement('div')
        controlKeyboard.classList.add('control-keyboard')

        var keys = document.createElement('div')
        keys.classList.add('keys')

        this.keyboard.forEach((key)=> {
            let bt = document.createElement('button')
            bt.innerHTML = key
            
            bt.addEventListener('click', (event)=> {
                event.preventDefault()
                that.processor.lifecycle(key)

                console.log("Click: ", )
                console.log("key","processor", this.processor)

                let dpl = document.querySelector(".display")
                dpl.innerHTML = this.processor.registrator

            })
            
            keys.append(bt)
        })

        keyboard.append(controlKeyboard)
        keyboard.append(keys)
        console.log("Keyborad: ", keyboard)


        this.layout.root.append(barWindow)
        this.layout.root.append(screen) // (append) aplique ao final
        this.layout.root.append(keyboard
            )

        console.log("LAYOUT", this.layout)


    }

    minimize( ) {
        this.layout.root.classList.add("minimize")
        console.log(this.layout.root)
    }

    maximize() {
        this.layout.root.classList.remove("minimize")
    }

    close() {
        this.layout.root.classList.add("close")
    }

    numberFilter(value) {
        if(value.length == 1) {
            return (value.match(/\d+/g)?.length > 0 && value.match(/\d+/g)[0]) ? value.match(/\d+/g)[0] : ""
        }
        return ""
    }

    signalFilter(value) {
        return value
    }
}

calc = new Calculator('#applyCalc')
